/* Water room */

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
"  WhoA! You appear to be up to your waist in "+BLUE+"water"+OFF+"!\n\
How very strange...\n\
Anyway, there does not seem to be much to do here except\n\
splash around and maybe dive under the "+BLUE+"water"+OFF+".\n\
This could get boring rather quickly...\n";
  items=({
    "portal","A glowing portal to another dimension...\n"+
             "  Do you dare to enter it?",
    "water","You are in "+BLUE+"water"+OFF+". You can splash or dive...",
      });
  }
}

init() {
  ::init();
  add_action("splash_water","splash");
  add_action("dive_water","dive");
  add_action("enter_portal","enter");
}

splash_water(str) {
  object ob;
  if(!str) {
    write("You splash around in the water! You feel like a little kid!\n");
    say(TPN+" splashes around inthe water like a little kid!\n");
  RE;
  }
  ob = present(str,ENV(TP));
  if(!ob) { write(CAP(str)+" is not here to splash!\n"); RE; }
    write("You splash "+CAP(str)+" with water!\n");
    say(TPN+" splashes "+CAP(str)+" with water!\n");
    TE(ob,"  You get even wetter!\n");
  RE;
}

dive_water() {
  write("You dive under the water...\n");
  say(TPN+" dives under the water...\n");
  if(random(30) < TP->query_attrib("int")) {
    write("You see a sort of portal under the water.\n"); }
  write("You come up for breath and explode out of the water!\n");
  say(TPN+" explodes back out of the water!\n");
  RE;
}

enter_portal(str) {
  if(!str) { write("Enter what?\n"); RE; }
  if(str == "portal") {
    write("You dive down and through the portal!\n");
    say(TPN+" dives under the water...\n");
    TR("/players/snow/water/alcove",TPN+" emerges from the portal.\n");
    MO(TP,"/players/snow/water/alcove");
    write("You emerge in a strange green room.\n");
    command("look",TP);
    RE;
  }
}
