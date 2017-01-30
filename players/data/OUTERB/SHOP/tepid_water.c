
inherit "/obj/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("water");
  add_alias("jug");
  add_alias("tepid water");
  add_alias("jug of tepid water");
  set_short("A jug of tepid water");
  set_long("A jug filled with old water collected when it rains. Just 'sip' it.\n");
  set_type("sips");
  set_msg("You take a sip of some tepid water, and manage to hold it down.\n");
  set_msg2(" drinks some tepid water.\n");
  add_cmd("swig");
  add_cmd("drink");
  add_cmd("sip");
  set_heal(30,30);
  set_charges(3);
  set_soak(12);
  set_value(200);
}
