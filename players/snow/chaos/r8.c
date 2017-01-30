/* Jungle room */

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
"  Welcome to the jungle...\n\
Raucous noises crash against your ears!\n\
You are in a tropical rain forest. The lush vegetation\n\
causes a sense of claustrophobia as light can barely\n\
trickle through the verdant leaves above. Vines hang\n\
around and the decaying undergrowth lies thick beneath\n\
your feet. Beware: the jungle holds many surprises for\n\
the unwary...\n";
  items=({
    "vegetation","Lots of green stuff all around you",
    "leaves","Broad leaves hang above and around you. Some have\n"+
             "bugs on them",
    "bugs","Little bugs crawling and flying around... maybe you can\n"+
           "catch one!",
    "vines","Cool! Vines you can swing on and climb just like Tarzan!",
    "undergrowth","Dead and dying parts of plants. It is pretty deep\n"+
                  "so you should be able to dig around in it",
      });
  call_out("jungle_sounds",random(20)+10);
  }
}

jungle_sounds() {
  int ran;
  string sound;
  ran = random(8);
  if(!environment()) return 1;
  if(ran == 1) sound = "A huge crashing sound passes near you and fades..\n";
  if(ran == 2) sound = "You hear a monkey screaming in the distance!\n";
  if(ran == 3) sound = "You notice a slithering sound close to your feet!\n";
  if(ran == 4) sound = "A lion roars in triumph.. somewhere..\n";
  if(ran == 5) sound = "You hear the grunting of wild pigs.\n";
  if(ran == 6) sound = "The jungle becomes suddenly quiet...\n";
  if(ran == 7) sound = "Some birds caw noisily overhead.\n";
  if(!sound) { call_out("jungle_sounds",random(100)+50); return 1; }
  TR(TO,sound);
  call_out("jungle_sounds",random(80)+50);
  RE;
}

init() {
  ::init();
  add_action("swing_vine","swing");
  add_action("climb_vine","climb");
  add_action("dig_growth","dig");
  add_action("catch_bug","catch");
}

swing_vine(str) {
  if(!str) { write("Swing on what?\n"); RE; }
  if(str == "vine" || str == "on vine" || str == "on vines") {
    if(random(30) > TP->query_attrib("int")) {
      write("You start to swing on a vine...\n\n"+
            "    Unfortunately it is a dead vine...\n\n"+
            "         You crash painfully to the ground!\n\n");
      say(TPN+" starts to swing on a vine...\n\n"+
          "    Unfortunately it is a dead vine...\n\n"+
          "        "+TPN+" crashes painfully to the ground!\n\n");
      TP->add_hit_point(-random(30));
      RE;
    }
    write("You swing joyfully above the ground!\n\n"+
          "        SWING!        SWING!\n\n");
    say(TPN+" swings joyfully above the ground!\n\n"+
        "        SWING!        SWING!\n\n");
    if(TP->query_attrib("str") < random(24)) {
      write("You lose your grip and fall painfully to the ground!\n");
      say(TPN+" loses "+GEN+" grip and falls painfully to the ground!\n");
      TP->add_hit_point(-random(30));
      RE;
    }
    write("You swing gracefully back down to the ground!\n\n");
    say(TPN+" swings gracefully back down to the ground!\n\n");
    RE;
  }
}

climb_vine(str) {
  object ws;
  if(!str) { write("Climb what?\n"); RE; }
  if(str == "vine" || str == "a vine" || str == "vines") {
    write("You start climbing up a vine...\n\n");
    say(TPN+" starts climbing up a vine...\n\n");
    if(TP->query_attrib("int") < random(24)) {
      write("You were climbing on a dead vine...\n"+
            "    Now you are falling...\n\n");
      say(TPN+" was climbing on a dead vine...\n"+
          "    Now "+TPN+" is falling...\n\n");
      write("You land with a painful THUD.\n");
      say(TPN+" lands with a painful THUD.\n");
      TP->add_hit_point(-random(30));
      RE;
    }
    if(TP->query_attrib("str") < random(24)) {
      write("You lose you grip and fall!\n\n\n"+
            "    You land with a painful THUD.\n\n");
       say(TPN+" loses "+GEN+" grip and falls!\n\n\n"+
           "    "+TPN+" lands with a painful THUD.\n\n");
       TP->add_hit_point(-random(40));
       RE;
    }
    ws = present("wyrmslayer",TP);
    if(ws && ws->query_orb() == 1) {
      write("You are sucked up into the sky!\n");
      say(TPN+" disappears above the leaf canopy...\n");
      MO(TP,"/players/snow/closed/q/sky.c");
      call_other("/players/snow/closed/q/sky.c","delay_appear");
      call_other("/players/snow/closed/q/sky.c","set_block",1);
      call_other("/players/snow/closed/q/sky.c","set_blockname",TPRN);
      return 1;
    }
    write("You emerge from the leaf canopy and are attacked by stirges!\n"+
          "    You fall...\n\n\n\n"+
          "        You land with a very painful THUD!\n\n");
    say(TPN+" climbs out of sight above the leaf canopy...\n\n"+
        "    You hear a scream!\n\n"+
        "        "+TPN+" falls through the trees and lands with a THUD!\n");
    TP->add_hit_point(-(random(50)+10));
    MO(clone_object(STIRGEM),TO);
    MO(clone_object(STIRGEM),TO);
    MO(clone_object(STIRGEM),TO);
    MO(clone_object(STIRGEM),TO);
    MO(clone_object(STIRGEM),TO);
    MO(clone_object(STIRGEM),TO);
    RE;
  }
}

dig_growth() {
   write("You dig around in the undergrowth... kinda dirty but kinda fun!\n");
   say(TPN+" grubs around in the leaves and dirt... looks kinda fun!\n");
 RE;
}

catch_bug(str) {
  if(!str) { write("Catch what?\n"); RE; }
  if(str == "bug" || str == "bugs") {
    if(TP->query_attrib("ste") < random(30)) {
      write("You reach out and try to snag a bug...\n\n"+
            "   It just barely gets away!  You weren't quite fast enough.\n");
      say(TPN+" tries to grab a bug but just misses.\n");
      RE;
    }
    write("You reach out and grab a bug!\n"+
          "    Ewwww... you squished it...\n");
    say(TPN+" reaches out and grabs a bug!\n"+
       "    Ewww... "+TPN+" has bug guts on "+GEN+" hands...\n");
    RE;
  }
}
