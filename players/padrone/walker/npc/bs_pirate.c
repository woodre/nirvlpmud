/*
 * bs_pirate.c
 * Big Smelly pirate
 */

inherit "obj/monster";

void
reset(status arg)
{
  object wep, jack, helm, cash;
  ::reset(arg);
  if (arg)
    return;
  set_name("big smelly pirate");
  set_alias("pirate");
  set_gender("male");
  set_short("A big smelly pirate");
  set_long("This is a big pirate. He does not smell good.\n");
  set_level(7);
  set_hp(105);
  set_wc(11);
  set_ac(6);
  set_al(-150);
  set_aggressive(1);

  wep = clone_object("obj/weapon");
  wep->set_name("cutlass");
  wep->set_class(10);
  wep->set_value(50);
  wep->set_weight(3);
  wep->set_short("A cutlass");
  wep->set_long("This is a cutlass. It has probably belonged to a pirate.\n");
  move_object(wep, this_object());
  init_command("wield cutlass");

  jack = clone_object("obj/armor");
  jack->set_name("leather jacket");
  jack->set_alias("jacket");
  jack->set_short("A leather jacket");
  jack->set_long("A worn but sturdy leather jacket.\n"+
                 "On the back is a lot of rivets making the pattern of a star.\n");
  jack->set_value(50);
  jack->set_weight(2);
  jack->set_ac(2);
  jack->set_type("armor");
  move_object(jack, this_object());
  init_command("wear jacket");

  helm = clone_object("/players/padrone/walker/npc/obj/phelm");
  move_object(helm, this_object());
  init_command("wear helmet");

  cash = clone_object("obj/money");
  cash->set_money(1 + random(50));
  move_object(cash, this_object());
}
