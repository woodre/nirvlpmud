inherit "obj/monster";
 
reset(arg)
{
  object gold, armor, weapon;

  ::reset (arg);
  if (arg) return;
  set_name("beggar");
  set_race("human");
  set_alias("old beggar");
  set_short("An old beggar");
  set_long("\n"+
"He is a beggar, he has very little cash, and only meager posessions.\n");
  set_level(12);
  set_hp(60 + random (100));
  set_al (-25);
  set_wc(12 + random (10));
  set_ac(8);
  set_chance(20);
  set_spell_dam(3 + random (5));
  set_spell_mess1("Beggar tears at you with his overgrown finger nails!");
  set_spell_mess2("Beggar swipes at you with his viscious toe nails!");
  set_chat_chance(2);
  load_chat("The beggar says: Some change for an old beggar.\n");

  gold = clone_object("obj/money");
  gold->set_money(60 + random(100));

  move_object (gold, this_object());
  set_move_at_reset (1); /* make wandering */

  if (random (2) == 1)
  {
    set_aggressive (1);  /* make agressive 50% of time */
    set_whimpy (1);  /* make wimpy */
  }
}
