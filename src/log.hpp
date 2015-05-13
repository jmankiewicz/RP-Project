#ifndef LOG_HPP
#define LOG_HPP

#define BOOST_LOG_DYN_LINK 1

#include <boost/current_function.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/log/attributes.hpp>
#include <boost/log/sinks.hpp>
#include <boost/log/sources/record_ostream.hpp>
#include <boost/log/sources/severity_channel_logger.hpp>
#include <boost/log/sources/severity_feature.hpp>
#include <boost/log/attributes/scoped_attribute.hpp>
#include <boost/log/utility/setup/console.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>

namespace rpProject
{
  namespace log
  {
    enum SeverityLevel
    {
        debug,
        informative,
        notification,
        warning,
        error,
        critical,
        catastrophic
    };
  }


  class LoggingService
  {
  public:

    boost::shared_ptr< boost::log::sinks::synchronous_sink< boost::log::sinks::text_file_backend > > fileSink;
    boost::shared_ptr< boost::log::sinks::synchronous_sink< boost::log::sinks::text_ostream_backend > > consoleSink;

    boost::shared_ptr<boost::log::sources::severity_channel_logger_mt<log::SeverityLevel> > logger;

    LoggingService()
    {
       std::cout.sync_with_stdio(true);
       this->logger.reset(new boost::log::sources::severity_channel_logger_mt<log::SeverityLevel>());
       fileSink = boost::log::add_file_log
       (
        boost::log::keywords::file_name = "rpProject_%N.log",
        boost::log::keywords::rotation_size = 10 * 1024 * 1024,
        boost::log::keywords::time_based_rotation = boost::log::sinks::file::rotation_at_time_point(0, 0, 0),
        boost::log::keywords::format = "[%LineID%:%TimeStamp%][%ThreadID%@%Scope%]: <%Severity%>  %Message%"
       );
       consoleSink = boost::log::add_console_log
       (
         std::cout,
         boost::log::keywords::format = "[%LineID%:%TimeStamp%][%ThreadID%@%Scope%]: <%Severity%>  %Message%"
       );
//        consoleSink->set_filter(boost::log::attributes::expr::attr< int >("Severity") >= 3);
       consoleSink->locked_backend()->auto_flush(true);

       boost::shared_ptr< boost::log::core > core = boost::log::core::get();
       core->add_global_attribute("LineID", boost::log::attributes::counter< unsigned int >(1));
       core->add_global_attribute("ThreadID", boost::log::attributes::current_thread_id());
       core->add_global_attribute("Scope", boost::log::attributes::named_scope());
       core->add_global_attribute("TimeStamp", boost::log::attributes::local_clock());
//        core->add_global_attribute("Severity", boost::log::trivial::severity());
    }

    boost::log::sources::severity_channel_logger_mt<log::SeverityLevel>& operator()()
    {
      return *this->logger;
    }

  };

  extern LoggingService systemLog;

  #define LOG(x) BOOST_LOG_SEV(rpProject::systemLog(),x)
  #define LOG_FUNCTION() BOOST_LOG_FUNCTION()
} //namespace rpProject

#endif // LOG_HPP
