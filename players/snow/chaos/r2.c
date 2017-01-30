/* Shadow room */

inherit "players/snow/chaos/arch.c";
#include "/players/snow/chaos/defs.h"
#include "/players/snow/closed/cyber/color.h"

reset(arg) {
  ::reset();

  if(!arg) {
  short_desc=YELLOW+"C"+OFF+
             MAGENTA+"h"+OFF+
             GREEN+"A"+OFF+
             CYAN+"o"+OFF+
             BLUE+"S"+OFF;
  long_desc=
"  Shadows flutter and spin around this strange area.\n\
There is a huge hole in the ground that leads to utter\n\
darkness. You seem to hear screams echoing through your\n\
mind but your ears hear nothing but silence.\n";
  items=({
    "shadows","These appear to be harmless tricks of the ChAoS realm",
    "hole","This is a hole. What little you can see of the sides and edges\n"+
           "show no hand or footholds. If you wanted to you could 'jump'\n"+
           "into it",
    "darkness","You cannot see into this.",
      });
  }
}

init() {
  ::init();
  add_action("jump_hole","jump");
}

jump_hole(str) {
  if(!str) { write("Jump into what?\n"); RE; }
  if(str == "into hole" || str == "hole") {
    write("You bravely jump into the unknown blackness!\n\n\n\n"+
          "       You black out...\n\n\n\n"+
          "            You wake up in a dark realm.\n");
    say(TPN+" jumps bravely into the dark hole!\n");
    TR("/players/snow/ROOMS/dark.c",TPN+" falls into the room.\n");
    MO(TP,"/players/snow/ROOMS/dark.c");
    command("look",TP);
  RE;
  }
}
