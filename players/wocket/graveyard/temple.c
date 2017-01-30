#define PATH "/players/wocket/graveyard/"
#include "/players/wocket/closed/ansi.h"
inherit "/players/wocket/graveyard/groom.c";
int openalready;

reset(arg){
openalready = 0;
  if(arg) return;

  short_desc = BLU+"The Temple of Marthki"+NORM;

  long_desc = ""+
"   The lighting is dim but enough to see.  Small candles illuminate\n"+
"the walls while a burning altar rests in the middle.  Above that, on\n"+
"a raised platform, a sarcophagus lays.  There are many tapestries that\n"+
"hang from the walls.  The floor seems stained with blood.\n";

dest_dir = ({
    PATH+"gr17.c","out",
});
  items = ({
    "candles","Made of beeswax, they drip slowly as they flicker in the darkness",
    "altar","It burns bright to light the room.  Many items have been charred away by\nthe flames",
    "platform","It rises from the ground",
    "floor","It seems stained with blood",
    "ground","It seems stained with blood",
  "sarcophagus","It is delecately decorated.  Perhaps you could 'open' it",
  "tapestries","They hang from the walls, depicting brutal war",
  "walls","They are made of stone and are covered with many tapestries",
});

  smells = ({
    "default","Decay fills the air",
});

  listens = ({
    "default","You hear the wail of silence",
});

  set_light(1);

}

init(){
  ::init();
    add_action("open_action","open");
 remove_call_out("getweather");
}

open_action(string str){
object ob;
  if(str != "sarcophagus"){
    notify_fail("What would you like to open?\n");
    return 0;
  }
if(openalready == 1){
    notify_fail("It has already been opened.\n");
    return 0;
}
write("You open the sarcophagus.\n");
write("A mummy attacks you from inside.\n");
ob = clone_object(PATH+"marthki.c");
move_object(ob,this_object());
ob->attack_object(this_player());
openalready = 1;
return 1;
}
