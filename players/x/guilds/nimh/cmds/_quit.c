#include "../x.h"

int cmd_quit(string str)
{
 object gsh;
 command("save", TP);
 MASTER->broadcast((string)PO->query_logout_msg(), 1);
 if(gsh = (object)TP->query_nimh_genshadow())
  gsh->end_shadow();
 return 0;
}
