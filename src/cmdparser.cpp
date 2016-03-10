#include "cmdparser.h"
#include "pipeline.h"

void cmdParse(unsigned char cmd, unsigned char data) {
    sendUi(cmd, data);
}