inherit "players/braxana/horlach/mon";

reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("death");
  set_short("Minor Death");
  set_alias("minor");
  set_race("death");
  set_long("Before you looms a minor yet powerful aspect of death.\n"+
           "Shrouded in a cloak of black it silently looks at you.\n"+
           "Skeletal hands grip the handle of a scythe\n"+
           "And it hungers....\n");
  set_level(19);
  set_hp(500);
  set_al(-1000);
  move_object(clone_object("/players/mythos/closed/guild/forest/wep/scythe.c"),
             this_object());
  command("wield scythe");
  set_wc(40);
  set_ac(18);
  set_aggressive(0);
  set_perception(200);
  set_chance(60,0);
  set_spell_tell("Death slices into you!",0);
  set_spell_mess("Death slices and dices!",0);
  set_spell_dam(35,0);
  set_chance(10,1);
  set_spell_tell("Pain fills you!",1);
  set_spell_mess("Death cuts into its foe!",1);
  set_spell_dam(200,1);
  set_chance(25,2);
  set_spell_tell("Something cold touches your soul!",2);
  set_spell_mess("Death grins.",2);
  set_spell_dam(60,2);
  set_chat_chance(0);
  set_chat_att_chance(0);
}

