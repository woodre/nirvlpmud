inherit "players/illarion/poke/mon/pokemon";
#include "/players/illarion/dfns.h"

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

  set_name("abra");
  set_race("pokemon");
  set_alias("rat");
  set_short("An odd rat-looking creature called Abra");
  set_long(
"Although this creature most closely resembles a rat, with a long, hairless\n"+
"tail, and long-toed feet, its round, thich body and short arms and legs\n"+
"look more like they belong on a teddy bear.  It looks up at you out of\n"+
"long, slanted eyes, and you feel its presence brush against your mind.\n");
  create(19);
  set_al(50+random(101));
  set_chat_chance(12);
  load_chat("The Abra looks at you, and though it makes no sound, you hear\n"+
            "it say \"Abra\" quite clearly in your mind.\n");
  load_chat("The Abra scampers around nimbly, looking for food.\n");
  load_chat("The Abra raises its head as if listening for something, but its\n"+
            "ears don't twitch at all.\n");
  set_spchance(15);
  add_spell("confusion",level+5,
"The Abra looks at you, squinting its eyes together.  Suddenly, you feel "+
"yourself rise into the air, and fly back and forth a few times, before "+
"being dropped into the ground.\n",
"The Abra squints at #TN#, who suddenly flies into the air, is "+
"thrown back and forth a few times, then crashes to the ground.\n",
"physical");
}
