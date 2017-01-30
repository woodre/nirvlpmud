#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */
#include "/players/anshar/closed/mydef.h"
inherit "room/room";
int X;

reset(arg) {
  if (arg) return 0;
  set_light(0);
  short_desc=(HIR+"The Zodiac Temple"+NORM);
  long_desc="     This is the shrine of Sagittarius, as is evidenced by the large\n"+
            "statue of an archer standing here. There is also an altar before the\n"+
            "statue. A deep silence pervades this room, some reminder of the holy,\n"+
            "though unknown nature of the room.\n";
  items=({
    "shrine",  "Dedicated to the idea of Sagittarius",
    "statue",  "A large statue of an archer, so real, it appears almost alive",
    "altar",  "One never knows what might happen when one 'kneels' at an altar",
  });
  dest_dir=({
    ZROOM+"zigg_1_7", "south",
    ZROOM+"zigg_1_3", "east",
  });

}
init() {
   ::init();
     add_action ("kneel_altar", "kneel");
     add_action ("challenge_sag", "challenge");
   }

kneel_altar(str) {
  if(!str || !str == "altar") {
    write("What?\n");
    return 1;
    }
  if(X == 0) {
    write("A voice booms out: Greetings, mortal! it has been long since\n"+
          "one has ventured to kneel at my altar. Are you one who seeks\n"+
          "to test your mettle? If you desire to know your worthiness in\n"+
          "in battle, you have only to challenge me. Beware, though, for\n"+
          "this is no game. You could very easily die. Think well, and if\n"+
          "you are certain, let the challenge begin!\n");
    X++;
    return 1;
    }
  write("Silence greets you.\n");
  return 1;
  }
challenge_sag(str) {
  if(!str || !str == "sagittarius") {
    write("What?\n");
    return 1;
    }
  if(X == 1) {
    write("A voice booms out: Very well, mortal! Let us do battle!\n");
    move_object(clone_object(ZMON+"sagittarius"),this_object());
    X ++;
    return 1;
    }
  write("Silence greets your challenge.\n");
  return 1;
  }


realm() {return "NT"; }
