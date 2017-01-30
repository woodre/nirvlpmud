/* Based on Feld's arena */
#include "/players/pestilence/define.h"
inherit "/players/pestilence/closed/std/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc=""+HIR+"Entry Way"+NORM+"";
  long_desc=
"     This is a small entrance room to the arena.  People can come here\n\
to fight other players, without loss of equipment or experience.  All one\n\
must do is to set their kill_players spar.  Above here there is a large\n\
section of bleachers, where the combat can be viewed.\n";
  dest_dir=({
    "/players/pestilence/arena/room/spar","west",
    "/players/pestilence/hall.c","east",
    "/players/pestilence/arena/room/stands","up"
  });
}
init() {
  ::init();
  add_action("west","west");
  add_action("east","east");
  add_action("quit","quit");
}
west() {
/*
  if(present("crotchrot",this_player()) ||
     present("toxin",this_player()) ||
     present("oath",this_player()) ||
     present("nitro",this_player()) ||
     present("poison",this_player())) {
      write("The arena officials refuse to let you enter the arena.\n");
      return 1;
    }
*/
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
