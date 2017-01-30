#include "/players/fred/mages/defs.h"

cmd_drakyr()
{
 object obj;
 if(USER->query_ghost()) { write("You can't summon a drakyr now.\n"); return 1; }
 if(RANK < 5) { write("You don't have the required rank.\n"); return 1; }
 if(INT < 20) {
  write("You don't have the intelligence needed to cast this spell.\n");
   return 1;
 }
 if(present("dark_circle", USER)->query_drakyr())
 {
  write("You already have summoned a drakyr.\n");
  return 1;
 }
 if(USER->query_sp() < 150) {
    write("You don't have enough energy.\n"); return 1; }
 write("You clasp your hands together tightly.\n"+
       "Slowly, you release them.\n"+
       "A "+BOLD+BLK+"dark shadow"+NORM+" rises through your very palms.\n"+
       "\nAn enchanted "+CYN+"winged"+NORM+" "+BOLD+BLK+"drakyr"+NORM+" takes form!\n");
 say((string)this_player()->query_name()+" clasps "+possessive(this_player())+" hands together tightly.\n"+
     "Slowly, "+subjective(this_player())+" releases them.\n"+
      "A "+BOLD+BLK+"dark shadow"+NORM+" rises through "+possessive(this_player())+" palms.\n"+
      "A strange creature emerges.\n");
 obj = clone_object("/players/fred/mages/mon/drakyr");
 move_object(obj, environment(this_player()));
 present("dark_circle", TP)->set_drakyr(obj);
 TP->add_sp(-150);
 obj->summoner(this_player());
 return 1;
}
