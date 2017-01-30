/* Space room */

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
"\n\n  You find yourself floating in space...\n\n\
Stars are all around you. It is very pretty.\n\n";
  items=({
    "stars","Beautiful bright stars. They seem far, far away...\n",
    "space","Space, the final frontier",
      });
  call_out("sky_visions",random(30));
  }
}

sky_visions() {
  int ran;
  string vis;
  ran = random(10);
  if(!environment()) return 1;
  if(ran == 1) vis = "An asteroid streaks by you!\n";
  if(ran == 2) vis = "A comet circles lazily around a distant solar system.\n";
  if(ran == 3) vis = "A faraway star explodes in a violent burst of light!\n";
  if(ran == 4) vis = "You feel insignificant among the universe.\n";
  if(ran == 5) vis = "An ephemeral chill creeps down your spine...\n";
  if(ran == 6) vis = "Spacedust momentarily blinds you!\n";
  if(ran == 7) vis = "Planets circle around a nearby sun.\n";
  if(ran == 8) vis = "You float perilously near an asteroid belt...\n";
  if(ran == 9) vis = "You float lazily in the deceptive calm of space.\n";
  if(!ran) call_out("sky_visions",random(100)+50);
  TR(TO,vis);
  call_out("sky_visions",random(30)+10);
  RE;
}
