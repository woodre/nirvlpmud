/* Ice room */

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
"  This area is a vast plain of clean, bluish-white ice.\n\
A brisk wind chills your face though the sun is shining\n\
brightly overhead. All is silent except the whistling wind.\n";
  items=({
    "sun","The sun is shining brightly on the ice",
    "ice","Smooth, clean ice. You could slide on it if you wished",
      });
  call_out("ice_crack",random(100)+20);
  }
}

ice_crack() {
  TR(TO,"You hear an ominous CRACK!\n");
  call_out("ice_crack",random(100)+20);
  RE;
}

init() {
  ::init();
  add_action("ice_slide","slide");
}

ice_slide(str) {
  if(!str) { write("Slide on what?\n"); RE; }
  if(str == "ice" || str == "on ice") {
    write("You slide happily on the ice...\n\n"+
          "    WHEEeeee!!!\n\n");
    say(TPN+" slides happily on the ice...\n\n"+
        "    WHEEeeee!!!\n\n");
    if(random(100) < 8) {
      write("A crack opens beneath you!\n"+
            "    You cannot stop sliding...\n\n"+
            "        You fall...\n\n         You black out.\n\n"+
            "You wake shivering.\n");
      say("A crack opens up beneath "+TPN+"!\n"+
          "    "+TPN+" cannot stop sliding...\n\n"+
          "        "+TPN+" falls...\n\n");
      TR("/players/snow/ROOMS/tundra/tundra2.c",
         TPN+" slides down a cliff and lands at your feet.\n");
      MO(TP,"/players/snow/ROOMS/tundra/tundra2.c");
      TP->add_hit_point(-(random(50)+20));
      command("look",TP);
      RE;
    }
    write("You slowly slide to a stop... WOW! That was fun!\n");
    say(TPN+" slowly slides to a stop... WOW! That looked like fun!\n");
    RE;
  }
}
