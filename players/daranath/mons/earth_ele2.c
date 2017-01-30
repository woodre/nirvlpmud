#define tp this_player()->query_name()
inherit "players/mythos/amon/forest/monster1";
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("Earth Elemental");
  set_alias("earth");
  set_race("elemental");
  set_short("A Powerful Earth Elemental");
  set_long("The earth elemental is a very large humanoid shaped pile of\n"+
           "east, stone, precious metals and gems straight from the ground.\n"+
           "Two brillant multifaceted gems make up its eyes, and it stares\n"+
           "directly at you, angry at your presence. This appears to be a\n"+
           "powerful creature, be wary of its strength!!!\n");
  set_hp(1200);
  set_level(22);
  set_al(-900);
  set_wc(38);
  set_ac(22);
  set_heal(8,15);
  set_aggressive(0);
  
  set_dead_ob(this_object());

  set_a_chat_chance(35);
  load_a_chat("The elemental slams you with a powerful fist.\n");

  set_chance(35);
  set_spell_dam(75);
  set_spell_mess1("The Earth Elemental crushes its foe!\n");
  set_spell_mess2("The elemental rises up and buries you!\n");

  set_mult(2);
  set_mult_chance(40);
  set_mult_dam1(20);
  set_mult_dam2(13);

}

monster_died() {
object ob;
ob=clone_object("/players/daranath/items/earth_eye.c");
  move_object(ob,this_object());
return 0;
}
