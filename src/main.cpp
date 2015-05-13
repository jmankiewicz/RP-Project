#include <iostream>
#include "log.hpp"
#include "exception.hpp"
#include <boost/program_options.hpp>
#include <string>
#include <sstream>

#include <Qt/qapplication.h>
#include "mainwindow.hpp"

using namespace rpProject;

/* Function used to check that 'opt1' and 'opt2' are not specified
 * at the same time. */
void conflicting_options(const boost::program_options::variables_map& vm,
                         const char* opt1, const char* opt2)
{
    if (vm.count(opt1) && !vm[opt1].defaulted()
        && vm.count(opt2) && !vm[opt2].defaulted())
        //Follwong is a preprocessor-macro which adds the linenumber, filename and functionname to our eexception and then throws it
        THROW_EXCEPTION( exception() << errorName("conflicting_commandline_options") << errorTitle("Conflicting options given") << errorDescription(std::string("Option ") + opt1 + std::string(" and ") + opt2 + std::string(" may not be specified together!" )));
}

int main(int argc, char **argv)
{
    // Process command-line-option

    boost::program_options::options_description desc("Allowed options");
    /* Don't be afraid. Syntax of the following declaration seems weird.
     * The function add_options() returns an object which supports multiple
     * usage of the operator() to add many options. That's why it looks this
     * way.  */
    desc.add_options()
        ("help", "produce help message")
        ("nohelp", "hide help message");

    //Now we load the command-line and map it's parts to variables
    boost::program_options::variables_map vm;
    boost::program_options::store(boost::program_options::parse_command_line(argc, argv, desc), vm);
    //If any variables are coupled to command-line-options, set their values now
    boost::program_options::notify(vm);
    /* Now we'll check for conflicting options. Function conflicting_options will throw an
     * exception in case of a conflict. Program-exceptions thrown inside the try block are
     * processed in _one_ a matching catch-block and then the program continues from after
     * the last catch-block. catch(...) matches any exception but has no access to the
     * exception object. So it's a measure of last resort. Be careful when using this,
     * because you loose all information on the error which occurred and might break
     * everything because your program is in an unknown and maybe unsafe state!
     *
     * It might look tempting for convenience to just use catch(...) everywhere but please
     * believe me: You'll fuck up everything and spend twice the time cleaning up. */
    try
    {
        conflicting_options(vm, "help", "nohelp");
    }
    catch(exception& e)
    {
        std::cerr << makeErrorReport(e) << "\n";
        return 1; //Return jumps back to the place from which the function was called
                  //For main() this means program-exit like exit() does anywhere.
    }
    catch(...)
    {
      std::cerr << "Unknown exception while checking option. Quitting.";
      exit(1); //exit(int error_num) exits to OS from anywhere in the code!
    }

    if (vm.count("help"))
    {
        std::cout << desc << std::endl;
        return 1;
    }

    //Startup

    LOG(log::informative) << "Program startup. rpProject Version 0.0.0";

    QApplication a(argc,argv);

    MainWindow m;

    m.show();

    a.exec();

    LOG(log::informative) << "Program exit. Bye!";
    return 0;
}
