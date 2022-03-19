#include "pic.h"


void picRemap(void)
{
    
    LOG(LOG_INFO, "Remapping PICs");
    outb(MASTER_PIC_COMMAND , 0x20); 
    outb(SLAVE_PIC_COMMAND, 0x20);
    
    LOG(LOG_OK, "Finished remapping PIC.");
}