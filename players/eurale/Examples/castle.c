/*  There are a number of changes that need to be made before any
    castle can be put into play.  First, copy the ansi file from
    /open/ansi.h into your home directory so you can use it at your
    convenience.  Then do the following:

    line 15 - change DEST to your castle location
    line 17 - change to your castle ID, remember all your areas will
              eventually be accessed from here
    line 22 - change to your castle long()
    line 26 - change 'name' to your entry verb
    line 30 - change the path to your entry room
*/

#include "/open/ansi.h"
#define DEST "your/castle location"

id(str) { return str == "castle name"; }

short() { return "Castle Name"; }

long() { write(
  "Your castle description goes here.\n");
}

init() {
  add_action("LOC","name");
}

LOC() {
  this_player()->move_player("dir#players/wizard/RMS/room.c");
    return 1;
}

reset(arg) {
object qob;

/*  YOUR QUESTS ARE ADDED HERE....
if(!present("quest_name",find_object("room/quest_room.c"))) {
  qob = clone_object("obj/quest_obj");
  qob->set_name("quest_name");
  qob->set_hint("Give the player quest hint\n");
  move_object(qob,"room/quest_room");
}
*/

  if(arg) return;
    move_object(this_object(), DEST);

/*  CLONE AUTOLOAD OBJECTS HERE....
clone_object("players/wizard/area/OBJ/item.c");
}
*/

is_castle(){return 1;}
