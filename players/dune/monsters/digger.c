inherit "obj/monster";


reset(arg)
{
  int a, v, x;
  ::reset(arg);
  if(arg) return;
  a = random(3) + 1;
  set_name("digger");
  set_race("digger");
  set_alias("digger");

  if (a == 1)
  {
    set_short("A chigger digger");
    set_long("The chigger digger looks like a large mole with claws.\n"+
             "It seems to have no eyes, yet it does not bump into any walls.\n");
    set_level(9);
    set_hp(random(10)+135);
    set_wc(9);
    set_ac(11);
  }
  if (a == 2)
  {
    set_short("An mole digger");
    set_long("The mole digger is a furry, tough-skinned beast.\n"+
             "It digs in and out of the ground like a seal\n"+
             "playing in water. Looks like its claws could hurt.\n");
    set_level(11);
    set_hp(random(15)+165);
    set_wc(11);
    set_ac(13);
  }
  if (a == 3)
  {
    set_short("A bore digger");
    set_long("The bore digger is the bulkiest of its kind.\n"+
             "Its claws are well-sharpened and its teeth\n"+
             "are those of a meat-eater.\n");
    set_level(13);
    set_hp(random(20)+195);
    set_wc(13);
    set_ac(14);
  }

  set_al(0);
  set_move_at_reset();
  x = random(2);
  for (v = 1; v <= x; v++)
  {
    move_object(clone_object("/players/dune/objects/gem.c"),
      this_object());
  }
}
