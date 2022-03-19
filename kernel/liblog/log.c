#include <liblog/log.h>
#include <klibc/io.h>

void LogOut(enum LogType lt, const char* file, const char* msg)
{
    
    gfxSetVertexColor(150,150,150);
    char* logtype;
    printstr("<");
    printstr(file);
    printstr("> ");
    if (lt == LOG_ERROR) { gfxSetVertexColor(255,0,0);
        logtype= "[ERROR]";
    }
    else if (lt == LOG_INFO){ gfxSetVertexColor(88,255,255);
        logtype= "[INFO]";
    }
    else if (lt == LOG_OK){ gfxSetVertexColor(88,255,88);
        logtype= "[OK]";
    }
    else {
        gfxSetVertexColor(255,255,255);
        logtype= "[?]";
    }
    
    
    printstr(logtype);
    printstr(": ");
    gfxSetVertexColor(200,200,200);
    uint32_t length = 0;
    while (msg[length] != '\0')
    {
        if ((length == 70))
            println("");
        else 
            printch(msg[length]);
        length+=1;
    }
    
    
    println("");
    gfxSetVertexColor(255,255,255);
    
}