/* Siegfried */

#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */

inherit "/obj/monster.c";

reset(arg)
{
  ::reset(arg);
  if (!arg)
  {
    /* Siegfried's whip disappears as an illusion when dropped at his death. */
    move_object(clone_object("/players/aingeal/casino/weapons/whip.c"),
                this_object());
  }
  set_name("siegfried");
  set_alias("siegfried");
  set_alt_name("entertainer");
  set_short("Siegfried");
  set_race("human");
  set_long("Siegfried's sharp gaze scans the audience, his dark-\n\
blonde hair and ruddy skin tinged with sweat from the\n\
hot stage lights.  Dressed in tight-fitting black pants\n\
and a white tuxedo shirt open at the chest, he moves \n\
across the stage with the grace usually attributed to\n\
one of the giant felines that made him famous.\n");
  set_level(13);
  set_ac(9 + random(2));
  set_wc(15 + random(3));
  set_hp(195);
  set_al(-100);
  set_aggressive(0);
  add_money(random(50) + 550);
  set_chat_chance(20);
  set_a_chat_chance(30);
  set_chance(15);
  set_spell_mess1("\n\tSiegfried shouts,"+YEL+"'SARMOTI!"+NORM+
                  "\n\tHis attacker disappears!\n");
  set_spell_mess2("\n\tSiegfried shouts, "+YEL+"'SARMOTI!"+NORM+
                  "\n\tYou disappear!\n");
  set_spell_dam(10);
  /* Regular chats */
  load_chat("Siegfried muses, 'In magic.....anything is possible.'\n");
  load_chat("Siegfried says,'Don't call us just magicians or conjurers...\n\
Storytellers would be just right.'\n");
  load_chat("Siegfried pauses to cuddle an enormous Royal White Tiger\n\
before it pads silently out of view backstage.\n");
  load_chat("Siegfried spears the audience with the intensity of his gaze\n\
as he intones, 'To rise above what seems impossible,\n\
one must first believe.'\n");
  load_chat("Siegfried pauses dramatically before his next astounding feat...\n");
  /* Combat chats */
  load_a_chat("Siegfried thrashes his whip with a startling "+YEL+
              "CRACK!"+NORM+"\n");
  load_a_chat("Siegfried shouts something hostile-sounding in German!\n");
  load_a_chat("Siegfried brandishes a flaming hoop at you!\n");
  load_a_chat("Siegfried shouts to Roy, 'Get back! I'll take care of this!'\n");
  set_dead_ob(this_object());
}

/* Siegfried's corpse will disappear as illusion upon his death.*/
monster_died()
{
	object corpse;
	corpse=present("corpse",environment());
	say("\n\t"+BLU+"Siegfried laughs maliciously as he\n"+
      "\t\tsuddenly DISAPPEARS from view!'"+NORM+"\n\n");
  destruct(corpse);
  return 1;
}
