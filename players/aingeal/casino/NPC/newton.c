/* Wayne Newton */

#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */

inherit "/obj/monster";

reset(arg)
{
  object gold, ob;
  ::reset(arg);
  if (arg) return;
  gold = clone_object("obj/money");
  gold->set_money(random(500) + 2500);
  move_object(gold,this_object());
  ob = clone_object("/players/aingeal/casino/armor/boutonniere.c");
  move_object(ob,this_object());
  set_name("wayne");
  set_alias("newton");
  set_alt_name("entertainer");
  set_short("Wayne Newton");
  set_race("human");
  set_long("Wayne smiles down at his adoring fans, his rakish good looks\n\
still evident after all these years.  He is sharply dressed in a\n\
black tuxedo, his red boutonniere a bright stain of color upon his\n\
chest. With poise and confidence borne of long years in the spotlight,\n\
it's clear why Wayne Newton is still known as 'Mr. Las Vegas'.\n");
  set_level(18);
  set_ac(13 + random(2));
  set_wc(22 + random(4));
  set_hp(350 + random(50));
  set_al(500);
  set_aggressive(0);
  set_chat_chance(10);
  set_a_chat_chance(25);
  set_chance(10);
  set_spell_mess1("\n\tWayne "+YEL+"PUMMELS"+NORM+" his opponent with his fists!\n");
  set_spell_mess2("\n\tWayne "+YEL+"PUMMELS"+NORM+" you with his fists!\n");
  set_spell_dam(30);
  load_chat("Wayne leans down to shake hands with an adoring fan.\n");
  load_chat("Wayne closes his eyes as he croons, \n\
'The love between the two of us was dying.....\n\
And it got so bad I knew I had to leave.....\n");
  load_chat("Wayne flashes the audience a youthful grin as he sings,\n\
'Danke schoen....oh, darlin', danke schoen....'\n");
  load_chat("Wayne plucks the red rose boutonniere from his jacket pocket\n\
and sniffs it with a boyish grin as he sings,\n\
'I want some red roses for a blue lady.....'\n");
  load_a_chat("Wayne scowls at you as he dodges out of your way!\n");
  load_a_chat("Wayne shouts, 'How dare you interrupt my show!'\n");
  load_a_chat("Wayne drops into a fighter's crouch and shouts, 'Bring it!'\n");
  load_a_chat("Wayne blasts you with a devastating punch!\n");
}

