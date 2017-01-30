#include "../defs.h"

inherit ROOM;

int offset;

void reset(int arg)
{
  if(arg) return;
  set_light(1);
  short_desc=CYN+"The Misty Tower"+OFF;
  long_desc=
"  A full circle of the staircase becomes visible in this high\n\
vaulted circular hall.  To the north, where the steps bisect the\n\
floor, is a doorway between flights.  Directly opposite it, beneath\n\
the curve of the staircase an archway leads into a large chamber.\n\
Scattered about the hall are a few mahogany chairs and coffee tables.\n\
In a rare display of martial aesthetics, whoever decorated this room\n\
placed a suit of ceremonial armor on a pedestal near the west wall.\n\
Directly opposite that is a grandfather clock.\n";
  items=({
    "circle","The staircase ascends from 12 o'clock, upward in a counterclock-\n"+
             "wise fashion until it goes up through the ceiling directly above\n"+
             "that",
    "staircase","The staircase is constructed of timeworn blue streaked with\n"+
                "green marble and ascends in a counterclockwise fashion",
    "doorway","You hear low murmuring and the crackling of a fire through the doorway."+
              "You silently congratulate yourself for having such keen hearing",
    "flights","To the left of the door the stairs lead down and to the right of it\n"+
              "they lead up and around",
    "archway","The archway is constructed of sandstone blocks transported here with\n"+
              "great effort from the Jal-Hab desert",
    "chamber","You can't see all of it from here",
    "chairs","They are obviously the work of a skilled craftsman, and yet they look\n"+
             "terribly uncomfortable",
    "tables","You get the impression that these're the kind of tables that you need\n"+
             "to use coasters for",
    "armor","The suit of armor is strictly ceremonial and probably too heavy to\n"+
            "actually wear.  It's left arm is stretched out in an odd parody of\n"+
            "a salute",
    "clock","special: see long() function",
  });
  dest_dir=({
    ROOMDIR+"tower4.c","up",
    ROOMDIR+"tower2.c","down",
    ROOMDIR+"portalroom.c","south",
    ROOMDIR+"lounge.c","north",
  });
}
void init() {
  ::init();
  add_action("cmd_pull","pull");
  add_action("cmd_twist","twist");
  add_action("cmd_push","push");
  add_action("cmd_enter","enter");
}

int cmd_pull(string str) {
  if(!str || str!="arm") {
    notify_fail("Pull what?\n");
    return 0;
  }
  write("It doesn't budge.\n");
  return 1;
}

int cmd_push(string str) {
  if(!str || str!="arm") {
    notify_fail("Push what?\n");
    return 0;
  }
  write("There is some give, but you don't quite have the motion right.\n");
  return 1;
}

int cmd_twist(string str) {
  if(!str || str!="arm") {
    notify_fail("Twist what?\n");
    return 0;
  }
  write("You twist the arm of the ceremonial piece of armor and hear a loud\n"+
        "click echo through the hall.\n");
  say("You hear a loud click.\n");
  offset++;
  return 1;
}

int cmd_enter(string str) {
  int t;
  t=time()+(offset*3600);
  if(!str || (str!="passage" && str!="clock") ||
     (t < 10800 && t > 14400)) /* Between 3 and 4 am */
    return 0;
  write("\nYou enter the passageway behind the clock.  Behind it you find a\n"+
        "narrow staircase that descends deep beneath the tower.\n\n");
  move_object(this_player(),ROOMDIR+"crypt.c");
  command("look",this_player());
  return 1;
}

long(str) {
  int t;
  if(!str || str!="clock")
    ::long(str);
  else {
    t=time()+(offset*3600);
    write("The old grandfather clock says: "+ctime(t)[11..15]+"\n");
    t=t % 86400;
    if(t > 28800 && t < 32400)
      write("You notice that the grandfather clock has cracked open, revealing\n"+
            "a secret passage.\n");
  }
}
