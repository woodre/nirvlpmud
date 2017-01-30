#include "def.h"

inherit ROOM;

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="Sparring Arena Entry";
  long_desc=
"     This is a small, simple room where combatants may prepare to enter\n\
the sparring arena.  If you die in the sparring arena, you will not lose\n\
any experience and you will be automatically resurrected in the recovery\n\
room with all of your equipment and coins.\n";
  dest_dir=({
    PATH+"spar_arena","west",
    PATH+"foyer","east",
    PATH+"stands2","up"
  });
}
init() {
  ::init();
  add_action("west","west");
  add_action("east","east");
  add_action("quit","quit");
}
west() {
  if(present("crotchrot",this_player()) ||
     present("toxin",this_player()) ||
     present("oath",this_player()) ||
     present("nitro",this_player()) ||
     present("poison",this_player())) {
      write("The arena officials refuse to let you enter the arena.\n");
      return 1;
    }
  if(this_player()->query_pl_k() < 2) {
    write("You must set your sparring flag by typing "+BOLD+"kill_players spar"+NORM+".\n");
    say(TPN+" tries to go and fails.\n");
    return 1;
  }
  return ::cmd_move();
}
east(str) {
  if(this_player()->query_pl_k() > 1) {
    write("Sparring flag removed.\n");
    this_player()->rm_spar();
  }
  return ::cmd_move();
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
