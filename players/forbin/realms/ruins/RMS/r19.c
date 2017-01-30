#include "/players/forbin/realms/ruins/ruinsdefine.h"
inherit "/players/forbin/closed/std/room.c";

reset(arg) {
  object angel;
  if(!present("archangel")) {
    angel = clone_object(NPC+"angel.c");
    angel->set_up(26, 15, "ice", "ice_hammer.c", "hammer");
    move_object(angel, this_object()); 
  }
  if(arg) return;
set_light(1);

short_desc = RUINS;
long_desc =
"  Here the hallway turns and leads to the south and back to the west. The\n"+
"surrounding stone is finely crafted and shows no damage. Wall sconces\n"+
"provide adequate lighting as you make your way forward.\n";

items = ({
  "stone",
  "Whoever built this hallway and the surrounding rooms was a master craftsman\n"+
  "with endless skill",
  "sconces",
  "Trimmed in gold and beautiful in design, they provide light for your passage",
});

dest_dir = ({
  RMS+"r18.c","west",
  RMS+"r21.c","south"
});

}

query_ruinsroom() { return 1; }

short() { 
  int i;
  string sh;
  if(set_light(0) > 0) { 
    if(this_player()) {
      if(!environment(this_player())->query_ruinsroom() && this_player()->query_level() < 40) return HIW+RUINS+NORM; 
      else { 
        sh = HIW+short_desc+" ["+NORM;
        if(!dest_dir || no_exits) sh += "no exits";
        else {
          for(i=1; i<sizeof(dest_dir); i+=2) {
            sh += translate_exit(dest_dir[i]);
            if (i < sizeof(dest_dir)-2) sh += ",";
          }
        }
        sh += HIW+"]";
        return sh+NORM; 
      }
    }
    else return HIW+RUINS+NORM;   
  }
  else return "Dark room";     
}
