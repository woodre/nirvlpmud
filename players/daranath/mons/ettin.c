#define tp this_player()->query_name()
inherit "players/mythos/amon/forest/monster1";
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("Ettin");
  set_alias("ettin");
  set_race("giant");
  set_short("An Ettin towers above you");
   set_long("Standing over twice your size and casting a large shadow\n"+
            "about the area, the Ettin wields a pair of spiked clubs, one\n"+
            "with each hand.\n");
  set_hp(950);
  set_level(20);
  set_al(-1000);
  set_wc(35);
  set_ac(22);
  set_heal(6,13);
  set_aggressive(0);
  
  set_dead_ob(this_object());

  set_chat_chance(20);
  set_a_chat_chance(35);

  set_chance(35);
  set_spell_dam(75);
  set_spell_mess1("The Ettin rears up and slams its foe!\n");
  set_spell_mess2("The Ettin stands up and crushes you with massive blow!\n");

  set_mult(2);
  set_mult_chance(40);
  set_mult_dam1(20);
  set_mult_dam2(13);

}
