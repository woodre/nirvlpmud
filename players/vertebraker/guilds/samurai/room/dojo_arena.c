#include "../def.h"

inherit "/room/room";

reset(arg)
{
  if(arg) return;
  set_light(1);
  set_short("Dojo - Arena");
  set_long("\
The Dojo - Arena.\n\
To the south is the entrance to the combat arena.\n\
To the east are a row of stands.\n");
  items = ({
  });
  dest_dir = ({
    ROOMDIR+"dojo_sc","north",
    ROOMDIR+"dojo_stands","east",
    ROOMDIR+"dojo_arena2","south",
  });
}

init() {
  ::init();
  add_action("north","north");
  add_action("south","south");
  add_action("quit","quit");
}

south() {
  if(this_player()->query_pl_k() < 2) {
    write("You must set your sparring flag by typing "+BOLD+"kill_players spar"+NORM+".\n");
    say(TP->QN+" tries to go and fails.\n");
    return 1;
  }
  return 0;
}
north(str) {
  if(this_player()->query_pl_k() > 1) {
    write("Sparring flag removed.\n");
    this_player()->rm_spar();
  }
  return 0;
}
realm() {
  return "NT";
}
query_no_fight() {
  return 1;
}

query_spar_area() { return 1; }

quit() {
  write("You may not quit from this location.\n");
  return 1;
}
