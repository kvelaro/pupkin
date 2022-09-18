#include <syslog.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../about/info.h"

void logit(int logLevel, const char *message, bool fatal) {
    openlog(APPLICATION_NAME,  LOG_PERROR | LOG_PID, LOG_DAEMON);
    syslog(logLevel, "%s", message);
    closelog();
    if(fatal) {
        exit(-1);
    }
}
