
inherit "/obj/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("Spirits Be Fouled");
  add_alias("wine");
  add_alias("spirits be fouled");
  add_alias("spirits");
  add_alias("bottle");
  set_short("A bottle of Spirits Be Fouled");
  set_long("This is a bottle of Spirits be Fouled, you wonder who would\n"+
           "want to 'drink' this putrid stuff.\n");
  set_type("sips");
  set_msg("You take a drink of the Spirit and immediately start to gag.\n");
  set_msg2(" drinks some spirits.\n");
  add_cmd("drink");
  add_cmd("swig");
  add_cmd("sip");
  set_heal(25,25);
  set_charges(3);
  set_intox(12);
  set_value(200); /* Per charge! */
}
