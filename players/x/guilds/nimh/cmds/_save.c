#include "../x.h"

int y;

int cmd_save()
{
 if(y) return 0;
 command("nsave", TP);
 write(HIK+"Saving mudwide statistics...\n"+NORM);
 y = 1;
 command("save", TP);
 y = 0;
 write(HIK+"Logging mudwide statistics...\n"+NORM);
 command("logme", TP);
 return 1;
}
