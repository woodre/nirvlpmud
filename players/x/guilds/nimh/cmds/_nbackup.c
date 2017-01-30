#include "../x.h"

int cmd_nbackup(string str)
{
 if(str) return 0;

 write(HIK+"Backing up guild statistics...\n"+NORM);
 if(file_size("/"+N_BACKUP+(string)TP->RN+".o") > -1)
  write(HIK+"Overwriting old backup...\n"+NORM);
 PO->backup_me();
 write("Ok.\n");
 return 1;
}
