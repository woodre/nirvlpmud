#include "/players/llew/closed/ansi.h"
inherit "room/room";

reset(arg) {
   if(arg) return;
   short_desc="Sacred Circle";
   long_desc="\tSurrounded in sylvan beauty, this clearing is a\n"+
      "haven of peace and tranquility.  The grass is soft, the air\n"+
      "is cool and comfortable.  Protecting the clearing is a circle\n"+
      "of great oaks, beckoning prosperity.  The leaves whisper\n"+
      "gently letting in the overhead moonlight.   Paths trail through\n"+
      "the obscuring trees in several directions.\n";
   dest_dir=({"players/llew/closed/personal/solace/pool","east",
              "players/llew/closed/personal/solace/cairne","west",
              "players/llew/closed/personal/solace/waterfall","north",
              "players/llew/closed/personal/solace/glade","south"});
   items=({
      "clearing","The clearing is about fifteen feet in diameter",
      "grass","The soft green was invites you to lie down and rest",
      "oaks","The oaks are tall and ancient.  There is a sense of\nbenevolence and wisdom to them",
      "leaves","The leaves are high overhead; hard to see",
      "moonlight","Although you can't see it above, it can only be\nfull with as much light that penetrates the clearing",
      "paths","The paths are slight but distinguishible in the pale moonlight"
   });
   set_light(1);
}

realm() { return "NT"; }
query_no_fight() { return 1; }
