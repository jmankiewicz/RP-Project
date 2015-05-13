#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP
#include <boost/exception/all.hpp>

namespace rpProject
{

enum severity { Neglectable, Informative, ShouldNot, MustNot, Fatal, Catastrophic };

typedef boost::error_info<struct errorNameStruct,std::string> errorName;
typedef boost::error_info<struct errorTitleStruct,std::string> errorTitle;
typedef boost::error_info<struct errorDrescriptionStruct,std::string> errorDescription;
typedef boost::error_info<struct errorSeverityStruct,severity> errorSeverity;

struct exception: virtual boost::exception, virtual std::exception { };


std::string severityToString(severity s);

std::string makeErrorReport(exception& e);

#define THROW_EXCEPTION(x) BOOST_THROW_EXCEPTION(x)

} //namespace rpProject
#endif // EXCEPTION_HPP
