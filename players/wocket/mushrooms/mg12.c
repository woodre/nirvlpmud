/*  10/09/06 - Rumplemintz
      Moved inherit to top of file, removed trailing ; from #include
*/

inherit "room/room";
#include "/players/wocket/closed/ansi.h"
#define PATH "/players/wocket/mushrooms/"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()

reset(arg) {
  if(!present("guard",this_object()))
    move_object(clone_object("/players/wocket/mushrooms/guard.c"),this_object());
  if(!present("guard 2",this_object()))
    move_object(clone_object("/players/wocket/mushrooms/guard.c"),this_object());
  if(arg) return;
  set_light(1);

  short_desc = HIR+"The Mushroom Grove"+NORM;
  long_desc =
    "   \
The large mushrooms surround a small cave that was formed by\n\
the constantly flowing stream that continues to cut through it.  There\n\
seems to be no other way to continue as the mushrooms grow very\n\
close together in this part of the grove.  Back to the southwest\n\
the worn pathway again takes shape.\n";

  items = ({
    "mushrooms","They are oversized and very colorful",
    "pathway","It is well worn from use",
    "cave","A small cave.  Perhaps you should try to 'enter' it",
    "stream","A small stream that formed the cave",
  });

  dest_dir = ({
    PATH+"mg11.c","southwest",
  });

}

init(){
  ::init();
  add_action("opencave","enter");
}

int opencave(string str){
  if (!str || str != "cave"){
    notify_fail("What would you like to enter?\n");
    return 0;
  }
  if(present("guard")){
    write("The guard blocks you.\n");
    say("the guard blocks "+this_player()->query_name()+" from entering the cave.\n");
    return 1;
  }
  write("You open and enter the cave.\n");
  say(this_player()->query_name()+" opens the cave.\n");
  say(this_player()->query_name()+" enters the cave.\n");
  move_object(this_player(),"/players/wocket/mushrooms/mgcave.c");
  command("look",this_player());
  say(this_player()->query_name()+" enters.\n");
  return 1;
}
