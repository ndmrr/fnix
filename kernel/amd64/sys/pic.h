

#ifndef PIC_H
#define PIC_H
#include <klibc/io.h>
#include <liblog/log.h>

#define MASTER_PIC_COMMAND 0x0020
#define MASTER_PIC_DATA    0x0021
#define SLAVE_PIC_COMMAND  0x00A0
#define SLAVE_PIC_DATA     0x00A1

void picRemap(void);



#endif 
