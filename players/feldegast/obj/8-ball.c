#include "/players/feldegast/defines.h"

inherit "obj/treasure";

reset(arg) {
  if(arg) return;
  set_id("orb");
  set_alias("magic orb");
  set_short("A "+BOLD+"mystic "+BLK+"orb"+NORM);
  set_long(
"This is a magical orb of great power.  It is almost completely\n"+
"opaque, yet seems to shine like obsidian.  A prominent rune upon the\n"+
"top of the orb is etched in black, and surrounded by a white circle.\n"+
"On the opposite side, part of the orb is transparent.  To call upon\n"+
"the power of this mystic device, you must <"+HIM+"shake"+NORM+"> it.\n"+
"It is said that the orb contains the answers to all questions.\n");
  set_weight(1);
  set_value(1000+random(500));
}
init() {
  add_action("cmd_shake","shake");
}
cmd_shake(str) {
  notify_fail("Shake what?\n");
  if(!str) return 0;
  if(str!="orb") return 0;
  write("You give the orb a good shake and then peer into its shadowy\n"+
        "center.  A few words appear:\n"+BOLD);
  write( ({
    "It is certain",
    "My reply is No",
    "Without a doubt",
    "Cannot predict now",
    "Yes",
    "You may rely on it",
    "Concentrate and ask again",
    "Reply hazy, try again",
    "Outlook good",
    "Very doubtful",
    "It is decidedly so",
    "Signs point to yes",
    "Don't count on it",
    "Yes, definitely",
    "Outlook not so good",
    "Better not tell you now",
    "As I see it yes",
    "My sources say no",
    "Ask again later",
    "Most likely",
  })[random(19)]);
  write(".\n\n"+NORM);
     

  return 1;
}
