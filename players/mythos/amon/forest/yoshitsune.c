inherit "obj/monster";
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("warrior");
  set_short();
  set_race("hero");
  set_gender("male");
  set_alias("yoshitsune");
  set_long("Yoshitsune- the hero of the Minamoto clan.  He stands tall and imposing.\n"+
    "His face behind the shroud- is a face of boyish beauty.  He is a master in \n"+
    "fighting- for he was once taught by the mythical Tengu.\n");
  set_hp(525);
  set_level(21);
  set_al(100);
  set_wc(30);
  set_ac(18);
  set_aggressive(0);
  set_a_chat_chance(15);
  load_a_chat("Yoshitsue laughs and declares that he has no need to draw his sword against a puny foe as you.\n");
  load_a_chat("Yoshitsune moves gracefully as he beats you down with his flute.\n");
  move_object(clone_object("/players/mythos/awep/forest/flute.c"),this_object());
  set_chance(40);
  set_spell_dam(random(35));
  set_spell_mess1("Using the flute, Yoshitsune deals a great blow to"+ this_player()->query_name()+"'s cheek!\n");
  set_spell_mess2("Using the flute, Yoshitsune deals you a great blow to the cheek!\n");
}
