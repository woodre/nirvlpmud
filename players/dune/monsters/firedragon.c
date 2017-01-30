inherit "obj/monster";


reset(arg)
{
  int a, x, v;
  object gold;
  ::reset(arg);
  if(arg) return;
  a = random(4) + 1;
  set_name("Dragon");
  set_race("dragon");
  set_alias("dragon");

  if (a == 1)
  {
    set_short("A big orange fire dragon");
    set_long("The big orange dragon towers above you.\n"+
         "Large spikes and tough dragonscales cover its\n"+
         "body from head to claw.\n");
    set_level(17);
    set_hp(random(100)+400);
    set_wc(27);
    set_ac(15);
    set_chance(15);
    set_spell_dam(40);
  }
  if (a == 2)
  {
    set_short("A large red fire dragon");
    set_long("This large red dragon looms over you. It looks\n"+
         "utterly dangerous and mean. The dragon grows\n"+
         "short wings, with talons on the ends.\n");
    set_level(17);
    set_hp(random(100)+450);
    set_wc(29);
    set_ac(16);
    set_chance(15);
    set_spell_dam(45);
  }
  if (a == 3)
  {
    set_short("A huge red fire dragon");
    set_long("This dragon is quite mighty. It is lord among\n"+
         "lesser dragon-kind. And, with the impressive\n"+
         "display of natural weapons upon its body, you\n"+
         "hope that it will not pound you into the earth.\n");
    set_level(18);
    set_hp(random(100)+500);
    set_wc(31);
    set_ac(17);
    set_chance(20);
    set_spell_dam(50);
  }
  if (a == 4)
  {
    set_short("A huge ancient red fire dragon");
    set_long("The huge ancient dragon is master of all dragon-kind.\n"+
         "It draws respect from all dragons and does not answer\n"+
         "to anyone or anything but itself.\n");
    set_level(18);
    set_hp(random(100)+550);
    set_wc(33);
    set_ac(18);
    set_chance(20);
    set_spell_dam(55);
  }

  set_al(0);
  set_aggressive(1);
  set_move_at_reset();
  set_spell_mess1("The fire dragon breathes on you!");
  set_spell_mess2("The fire dragon tears you to shreds!");

  gold=clone_object("obj/money");
  if (a == 1) gold->set_money(random(1000)+500);
  if (a == 2) gold->set_money(random(2500)+500);
  if (a == 3) gold->set_money(random(4500)+500);
  if (a == 4) gold->set_money(random(6500)+1000);
  move_object(gold,this_object());

  x = random(2);
  for (v = 1; v <= x; v++)
  {
    move_object(clone_object("/players/dune/objects/dragonmeat.c"),
      this_object());
  }
}
