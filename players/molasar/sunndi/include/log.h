
/*
 * log routines
 *
 */

#define LOGDIR "/players/molasar/sunndi/logs/"
#define LOG_DEBUG "debug.log"

#define SUNNDI_DEBUG 1

void log_data(string logfile, string message);
void log_debug(string message);

void log_data(string logfile, string message) {
   write_file(LOGDIR + logfile, ctime(time()) +": " + message + "\n");
}

void log_debug(string message) {
   write_file(LOGDIR + LOG_DEBUG, ctime(time()) +": [" + file_name(caller()) + "] " + message + "\n");
}

