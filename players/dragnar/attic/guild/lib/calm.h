#include "/players/dragnar/guild/defs/def.h"
calm() {
      object ob;
      ob=first_inventory(environment(this_player()));
      while (ob) {
         if (living(ob)) {
            if (ob->query_attack()) {
                ob->query_attack()->stop_fight();
               ob->stop_fight();
             }
             }
         ob = next_inventory(ob);
        ob;
                }
	     write("You command fighting to stop.\n");
      return 1;
   }
