#include "../std.h"
main(str)
{
   object o;
   if(!str) return;
   if(str == "home")
      {
      write("You vortex home.\n");
      MO(TP,"/players/vertebraker/workroom");
      return 1;
   }
   o = find_player(str);
   if(!o) return;
   MO(TP,ENV(o));
   write("You vortex to "+o->QN+".\n");
   command("look",TP);
   return 1;
}
