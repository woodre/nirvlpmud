inherit "obj/monster";
#include "/players/illarion/dfns.h"

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("Dirty Rats");
  set_race("rodent");
  set_gender("male");
  set_short("A pack of dirty, hungy-looking rats");
  set_long(
"Beady red eyes and shiny, sharp teeth glint dangerously.  The rats seeth\n"+
"over one another, looking for food, and from their behaviror, you are\n"+
"a definate option.\n");
  set_level(12);
  set_hp(180);
  set_wc(16);
  set_ac(9);
  set_chat_chance(7);
  load_chat("The rats scrabble around the room.\n");
  load_chat("The squeeking is starting to get to you....\n");
  set_a_chat_chance(7);
  load_a_chat("The rat pack surrounds you.\n");
  load_a_chat("You remember something about rats, and hope you won't\n"+
              "contract something.\n");
}
id(str) { return ::id(str) || str == "pack" || str == "rats"; }
