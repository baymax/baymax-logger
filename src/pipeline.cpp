#include "pipeline.h"
#include "cmdparser.h"

char * uiPipePath = "/tmp/baymax-ui";
char * loggerPipePath = "/tmp/baymax-logger";

void readLogger() {
    int fd;
    char buf[3] = "0";
    fd = open(loggerPipePath, O_RDONLY);
    unsigned char cmd;
    unsigned char data;
    while(1) {
        read(fd, buf, 3);
        if (buf[0] != '0') {
            //int32_t cmd = atoi(buf);
            //parseCmd(cmd);
            cmd = buf[0];
            data = buf[1];
            cmdParse(cmd, data);
            printf("Received: %c\n", buf[0]);

            snprintf(buf, 35, "%s", "0");
            
        } 
    }
}

void sendUi(unsigned char cmd, unsigned char data) {
    mkfifo(uiPipePath, 0666);
    int fd = open(uiPipePath, O_WRONLY);
    char buff[3];
    snprintf(buff, 35, "%c%c", cmd, data);
    write(fd, buff, sizeof(buff));
}