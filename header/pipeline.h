#ifndef PIPELINE_H
#define PIPELINE_H

#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

void readLogger();
void sendUi(unsigned char cmd, unsigned char data);

#endif // PIPELINE_H