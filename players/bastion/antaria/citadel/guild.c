
#include "std.h"
#define NAME this_player()->query_name()
#define HIS this_player()->query_possessive()

int gate_open;

#undef EXTRA_INIT
#define EXTRA_INIT extra_init();

extra_init() {
     add_action("open_gate", "open");
     add_action("north", "north");
}

#undef EXTRA_LONG
#define EXTRA_LONG \
     if(str=="gate"||str=="walls") { \
          write("The walls of glistening adamantite and sturdy gates look"+\
             "\nwell able to thwart any would-be invaders.\n"); \
          return; } \
     if(str=="towers") { \
          write("You notice the colorful banners or several wizards\n"+ \
                "flying from them.\n"); \
          return; } \
      if(str=="crest") { \
          write("You recognize it as the Seal of the Guild of Sorcerers.\n");\
          return; } \
     if(str=="plaque") { \
          write("It reads: MEMBERS ONLY!\n"); \
          return; }

TWO_EXIT("players/bastion/guild/courtyard", "north",
     "players/bastion/antaria/citadel/road3", "south",
     "Sorcerers' Gate",
     "Before you lies a city-within-a-city. Towers of ivory rise beyond\n" +
     "adamantine gates. Passers-by regard the structure with widened eyes\n" +
     "as they go about their business. A crest adorns the ponderous portal.\n"+
     "A plaque is fixed to the wall beside it.\n",
     1)

id(str) { 
  return str=="towers" || str=="walls" || str=="gate" || str=="plaque" ||
         str=="crest";
}

north() {
  if(!gate_open) {
    write("The gates are closed.\n");
    return 1;
  }
  write("You enter the Guild of Sorcerers.\n");
  say(NAME + " passes through the gates.\n");
}

open_gate(str) {
  if(str=="gate" || str=="gates") str=str;
  else return 0;
  if(gate_open) {
    write("The gates already stand open.\n");
    return 1;
  }
  if(!this_player()->query_sorcerer()) {
    write("You see no means of doing that.\n");
    return 1;
  }
  tell_room(this_object(), format(NAME + " waves " + HIS + " arms and the " +
   "gates open.\n"));
  tell_room("players/bastion/guild/courtyard", "The gates swing open.\n");
  gate_open=1;
  ("players/bastion/guild/courtyard")->set_gate_open(1);
  call_out("close_gate", 6);
  return 1;
}

close_gate() {
  tell_room(this_object(), "The gates swing closed.\n");
  tell_room("players/bastion/guild/courtyard", "The gates swing closed.\n");
  gate_open=0;
  ("players/bastion/guild/courtyard")->set_gate_open(0);
}

set_gate_open(i) { gate_open=i; }
