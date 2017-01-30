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
   write(HIK+"Demons"+NORM+" come from the ground and grab "+corpse->short()+", holding\n"+
         "it motionless, as you place your hand on the "+corpse->short()+" and\n"+
         "drain it of it's "+HIW+"S O U L"+NORM+".  The "+HIW+"S O U L"+NORM+" fills a spot in your\n"+
		 "personal darkness, leaving you somewhat healed.\n");
   say(HIK+"Demons"+NORM+" come from the ground and grab "+corpse->short()+" holding it motionless, as\n"+
       this_player()->query_name() + " places their hand on the  "+ corpse->short()+" and drains it of it's "+HIW+"S O U L"+NORM+"\n");
   say(this_player()->query_name() + " grins evilly after "+HIK+"devouring another "+HIW+"S O U L"+NORM+".\n");
/*
   if (sscanf(file_name(corpse),"obj/corpse%s",i)!=1) return 1;
*/
   this_player()->heal_self(corpse->heal_value());
   destruct(corpse);
   return 1;
   }
