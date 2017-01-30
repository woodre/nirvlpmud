inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
int t;
reset (arg){
  if(!present("lad")){
    for(t=0;t<2;t++){
    move_object(clone_object("players/persephone/monster/lad2"), TOB);
  }
}
 if (!arg) {
  set_light(1);
  short_desc="Main Wharf";
  long_desc="This appears to be the major wharf of the Harbour or Port of Persephoneia.\n" +
            "To the Southwest you see the harbour center while the wharf continues\n" +
            "to the Northeast. You start to feel uneasy and you sense an evil presence\n" +
            "further down the wharf.\n";
  dest_dir=({"players/persephone/rooms/pier2b","northeast",
             "players/persephone/rooms/harbb","southwest"
  });
 }
}
realm() { return "NT"; }
