#include "../std.h"

main(str)
{
   object f;
   if(!str) return 0;
   f = clone_object("/players/vertebraker/closed/filer");
   MO(f,TP);
   command("file "+str,TP);
   destruct(f);
   return 1;
}
