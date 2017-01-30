/* Penn Jillette */

#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */

inherit "/obj/monster.c";

reset(arg)
{
  ::reset(arg);
  if (!arg)
  {
    move_object(clone_object("/players/aingeal/casino/weapons/card.c"),
                this_object());
  }
  set_name("penn");
  set_alias("jillette");
  set_alt_name("entertainer");
  set_short("Penn Jillette");
  set_race("human");
  set_long("Penn grins at the audience, the nature of his smile\n\
somewhere between sweet and sinister.  Dressed in a\n\
snappy, gray three piece suit, his impressive six-foot\n\
six-inch height, bushy ponytail, and booming voice are\n\
both attention-grabbing and intimidating all at once.\n\
The stage lights glint off his round-rimmed glasses and\n\
dangling silver earring as he moves.  With a theatrical\n\
gesture, he displays a single playing card, the three\n\
of clubs.  His one blood red fingernail on his left ring\n\
finger glows against the white background of the card.\n");
  set_level(11);
  set_ac(8 + random(2));
  set_wc(14 + random(2));
  set_hp(165);
  set_al(-500);
  set_aggressive(0);
  set_chat_chance(15);
  set_a_chat_chance(30);
  set_chance(15);
  set_spell_mess1("\n\tPenn twists his expression into a grimace of hatred\n\
\n\tas he spits out a"+GRN+"BLASPHEMOUS OATH!"+NORM+"\n\
\n\tHis attacker collapses to the floor in "+GRN+"PAIN!"+NORM+"\n");
  set_spell_mess2("\n\tPenn twists his expression into a grimace of hatred\n\
\n\tas he spits out a"+GRN+"BLASPHEMOUS OATH!"+NORM+"\n\
\n\tYou collapse to the floor in "+GRN+"PAIN!"+NORM+"\n");
  set_spell_dam(15);
  /* Regular chats */
  load_chat("Penn announces, 'Good evening.  We are Penn and Teller....\n\
and you've probably heard by now that we do magic....'\n");
  load_chat("Penn grasps one end of a red rope.  The other end is\n\
holding up Teller, who's cinched tight in a straightjacket,\n\
and hanging upside down from the celing, dangling over a bed\n\
of 18-inch, sharp, wooden spikes.\n");
  load_chat("Penn quips, 'Las Vegas is a town built on bad math.'\n");
  load_chat("Penn deftly juggles six broken bottles, \n\
drawing an astonished gasp from the audience.\n");
  load_chat("Penn grins, displaying the .357 Magnum\n\
bullet he caught in his mouth!\n");
  /* Combat chats */
  load_a_chat("Penn "+RED+"SLICES"+NORM+" you with the \n\
razor-sharp edge of his playing card!\n");
  load_a_chat("Penn rushes at you with a deafening roar!\n");
  load_a_chat("Penn pulls one razor-edged steel playing card \n\
from his sleeve, and wields it like a weapon!\n");
}
