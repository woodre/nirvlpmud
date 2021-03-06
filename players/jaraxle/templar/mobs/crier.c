#include "/players/jaraxle/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
   ::reset(arg);
   if(arg) return;

  set_name("polwen");
set_alt_name("crier");
  set_race("human");
set_gender("male");
  set_short("Polwen, the Templar Crier");
  set_long("  The Templar Crier stands tall and has a vigorous presence. His face\n"+
    "is clean shaven and he has thinning black hair. He wears a snug pair\n"+
    "of breeches and a leather tunic.\n");
  set_level(5);
  set_hp(75);
  set_al(1000);
  set_wc(8);
  set_ac(3);
  set_aggressive(0);
  set_heart_beat(1);
  set_chat_chance(5);
  load_chat("The Templar Crier says: Attention! Notices from the Command!\n");
  load_chat("The Templar Crier says: "+GRN+"Ask"+NORM+" me about the latest "+GRN+"news"+NORM+"!\n");
}

init() {
  add_action("ask","ask");
}

ask(str) {
string what;
  if(!present("KnightTemplar", this_player())) {notify_fail("You are not a Knight.\n");
return 0;
}
  if(!str) { notify_fail("Ask whom about what?\n"); return 0; }
  if(sscanf(str,"polwen about %s",what)!=1) { notify_fail("Ask whom about what?\n"); return 0; }
  switch(what) {
      case "news":
      write(
    "The Templar Crier smiles brightly at you, a twinkle in his eyes. He\n"+
    "opens his scroll and begins reading the parchment, glancing at you\n"+
    "while he speaks:\n"+
    " \n"+
    "  'There is also a new room that will house a Knight that will be able\n"+
    "the reminder for specific Command "+GRN+"contacts"+NORM+", the "+GRN+"changes"+NORM+" to the castle,\n"+
    "or the brief message of "+GRN+"duty"+NORM+" for all Knights.\n"+
    "  \n"+
    "  The village crier wraps up his scroll with care and smiles at you.\n");
  return 1;
      case "contacts":
      write(
    "  Please continue also to contact Larisa for any general guild questions\n"+
    "you may have, and contact Slacker regarding the Alliance. Do NOT\n"+
    "contact the guild wizards directly with any sort of complaints, it is\n"+
    "no longer their job to mediate guild issues. It is the responsibility\n"+
    "of the Command, and the appropriate GC should be contacted whenever\n"+
    "possible.\n");
  return 1;
      case "changes":
      write(
    "  Take some time to remap the castle, as there are numerous changes\n"+
    "in the directions of many popular rooms. We have added private rooms\n"+
    "once again, and you will be able to store 3 items in them for now.\n"+
    "  There is also a new room that will house a Knight that will be able\n"+
    "to assist Knights with different quests as they become available.\n");
  return 1;
      case "duty":
      write(
    "  Please take a few moments to read the Tablet once more. It\n"+
    "is important that you understand and follow every law set forth. As a\n"+
    "Knight Templar, it is your responsibility to behave in a good manner\n"+
    "at all times. The Tablet itself is quite clear and leaves little room\n"+
    "for interpretation.\n"+
    "  Sadly, there will likely be a handful of our guildmates that will\n"+
    "choose to be disgruntled over these changes, and the fact that they\n"+
    "can no longer deviate from the laws of the guild without consequence.\n"+
    "But as Knights, we must all follow the laws. We were aware of them as\n"+
    "we joined, and for those of us that have been here much longer, we\n"+
    "were active when the laws took effect. There will be no tolerance for\n"+
    "people that repeatedly disrespect others within this guild. It is\n"+
    "meant to be enjoyable for all.\n");
  return 1;
  default:
    write(
    "I do not have any news available on that topic. Please try again.\n");
    return 1;
  }
}
