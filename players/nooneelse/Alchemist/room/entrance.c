/*
  alchemist_entrance.c
*/

#include "/players/nooneelse/Alchemist/lib/defs.h"

inherit "room/room";
inherit "/players/nooneelse/Alchemist/room/rooms.c";

object who;

string str, what;

int non_member_present;

init() {
  ::init();

  add_action("push", "push");
}

push(str) {
  if (!str) return;
  sscanf(str,"%s wall", what);
  if (str != "north" && what != "north") return;
  say(this_player()->query_name()+
      " reaches out and pushes the north wall.\n");
  say("A blue aura surrounds "+this_player()->query_possessive()+
      " "+" and "+this_player()->query_pronoun()+" disappears.\n");
  write("As you reach out and push the north wall a "+
        "blue aura surrounds you,\n");
  write("then fades away.  You see that your surroundings have changed.\n\n");
  call_other(ALCHEMIST_LOBBY, "???", 0);
  move_object(this_player(), ALCHEMIST_LOBBY);
  command("look", this_player());
  return 1;
}

reset(arg) {
  if (arg) return;
    
  set_light(1);
  short_desc=("blue room");
  no_castle_flag=1;
  long_desc=
     "This is a blue room with unadorned walls.  Why is it here?\n";
  items =
    ({
      "wall", "All you see is a blue wall with some smudges on it.",
      "walls", "All you see are featureless blue walls.\n"+
               "The north one seems to have some smudges on it.",
      "smudge", "It seems to be handprints.",
      "smudges", "They seem to be handprints.",
    });
  dest_dir=
    ({
      "players/nooneelse/dim", "south",
    });
  return;
}
