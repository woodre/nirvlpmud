#define tp this_player()->query_name()
inherit "players/mythos/amon/forest/monster1";
reset(arg)  {
  ::reset(arg);
  if(arg) return;
move_object(clone_object("/players/daranath/weps/kobold_maul.c"),this_object());
move_object(clone_object("/players/daranath/arms/kobold_cape.c"),this_object());
move_object(clone_object("/players/daranath/arms/kobold_crown.c"),this_object());
  set_name("Kobold King");
  set_alias("kobold");
  set_alt_name("king");
  set_race("humanoid");
  set_short("Gor'Thazul, The Kobold King");
  set_long("The Kobold King stands a full foot taller then the rest of\n"+
           "the kobold tribe. His red skin is darker then most of them,\n"+
           "almost dark brown in color. He wears no tattoos, but has a\n"+
           "a large scar running across one eye, sealing it shut. He is\n"+
           "not too be taken lightly.\n");
  set_level(15);

  init_command("wear crown");
  init_command("wear cape");
  init_command("wield weapon");

  set_hp(250);
  set_al(-1000);
  set_wc(21);
  set_ac(10);
  set_aggressive(0);

  set_mult(2);
  set_mult_chance(15);
  set_mult_dam1(10);
  set_mult_dam2(10);

}
