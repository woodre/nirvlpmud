#include "/players/reflex/lib/lib.h"
#include "/players/reflex/lib/include/ansi.h"
#define tp this_player()->query_name()
inherit "room/room";
int t;
reset(int arg){
 if(!arg){
  set_light(1);
 short_desc="Cloak Room";
long_desc=
 "You have entered the anteroom of Orin's Inn.  There are various pegs on\n"+
 "the wall where customers may hang their cloaks.  You may wish to hang\n"+
 "your cloak as well, for while the wind outside might have chilled your\n"+
 "bones, the interior of Orin's Inn is always comfortably warm.  Through\n"+
 "the door to the east you see the common room of the inn.\n";

items=({
 "door","A mahogany door leading to the inn's common room",
 "floor","The floor is made from a beautiful mahogany wood",
 });

  dest_dir=({
 "/players/saber/ryllian/ryllian2.c","west",
 "/players/reflex/guilds/bards/orin/orin2.c","in",
           });
  }   }
init(){
 ::init();
if(present("shardak_mark",this_player()))  {
  write("A large man steps in front of you.\n"+
        "Matthew says: I'm sorry, but your kind are not welcome here.\n");
  say(tp+" is escorted to the street.\n");
  move_object(this_player(),"/players/saber/ryllian/ryllian2.c");
  tell_room(environment(this_player()), tp+" is escorted from Orin's Inn.\n");
  return 1;
        }

  add_action("search","search");
  add_action("down","down");
}

search() {
 write("You find a staircase leading down to the wine cellar\n");
say (tp +" searches the area\n");
 return 1;  }

down() {
write("You walk down the staircase.\n");
call_other(this_player(),"move_player","walking down the staircase#/players/reflex/guilds/bards/orin/orin5.c");
  return 1;
  }
