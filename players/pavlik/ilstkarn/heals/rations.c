inherit "/obj/generic_heal";


void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("iron rations");
  add_alias("rations");
  add_alias("iron");
  add_alias("ration");
  add_alias("iron rations");
  set_short("Iron Rations");
  set_long("A pack of dried meat and fruit. Iron Rations are not the most\n\
tasty food, but they are known to be a healthy meal.\n");
  set_type("rations");
  set_msg("You scarf down a quick meal of Iron rations.\n");
  set_msg2(" scarfs some Iron Rations.\n");
  add_cmd("eat");
  add_cmd("scarf");
  set_heal(20+random(40),20+random(40));
  set_charges(3+random(3));
  set_stuff(7);
  set_value(100);
}
