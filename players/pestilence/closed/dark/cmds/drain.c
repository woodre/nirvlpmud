#include "/players/pestilence/ansi.h"

main() {
  object blah;
   object corpse;
   string i;
   corpse = present("corpse", environment(this_player()));
   if (!corpse) {

      write("No corpse present.\n");
      return 1;
      }
   write("You rip into the "+corpse->short()+" tearing it into small pieces.\n"+
         "You gather the pieces into your hand and put them in a shot glass of\n"+
         "whiskey and drink them down, giving you a somewhat healed feeling.\n");
   say(this_player()->query_name() + " rips into the "+ corpse->short()+" tearing it into small pieces.\n"+
       this_player()->query_name() + " puts the pieces into a shot glass and downs it.\n");
/*
	   if (sscanf(file_name(corpse),"obj/corpse%s",i)!=1) return 1;
*/
	   this_player()->heal_self(corpse->heal_value());
   destruct(corpse);
   return 1;
   }
