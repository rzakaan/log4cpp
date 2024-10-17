#include "log.cpp"
//#include <iostream>

int main(int argc, char** argv) {
    // Comment
    /*
     * Multiline comment
     * */
    Logg
    Logger LOG("logfile.txt");
    /*LOG.log(TRACE, "Trace");
    LOG.log(INFO, "PROGRAM STARTED");
    LOG.log(DEBUG, "Debuggin");
    LOG.log(WARNING, "Warning");
    LOG.log(ALERT, "Alert");
    LOG.log(ERROR, "ERROR");
    LOG.log(FATAL, "Critical");
    LOG.log(FATAL, "SDASDERROR");*/
        LOG << "message";

    // LOG.log();
    return 1;
}
