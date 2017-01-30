#include "../x.h"

int cmd_stest()
{
 if(TP->query_nimh_genshadow())
  write(HIG+"SHADOW ON\n"+NORM);
 else
  write(HIR+"SHADOW OFF\n"+NORM);
 return 1;
}
