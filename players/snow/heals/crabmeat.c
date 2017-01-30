inherit "/obj/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("crabmeat");
  add_alias("slab");
  add_alias("slab of giant crabmeat");
  add_alias("giant crabmeat");
  set_short("A slab of giant crabmeat");
  set_long("This is a slab of crabmeat taken from the corpse of a giant crab.\n");
  set_type("bites");
  set_msg("You devour the delicious crabmeat!\n");
  set_msg2(" devours the delicious crabmeat!\n");
  add_cmd("eat");
  set_heal(35,35);
  set_charges(4);
  set_stuff(30);
  set_value(0);  /* for a reason */
  set_msg_stuffed("You are too full to eat that much!\n");
  set_type_single("bite"); /* verte */
}


