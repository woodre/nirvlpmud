

inherit "/obj/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("pot pie");
  add_alias("pie");
  set_short("A Pot Pie");
  set_long("A delicious looking pot pie.\n");
  set_type("bite");
  set_msg("You take a big bite out of the pie.\n");
  set_msg2(" takes a bite off the pot pie.\n");
  add_cmd("eat");
  set_heal(20,20); 
  set_charges(1);
  set_stuff(8);
  set_value(150); 
}
