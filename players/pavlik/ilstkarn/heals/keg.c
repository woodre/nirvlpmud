
inherit "/obj/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("keg of beer");
  add_alias("keg");
  add_alias("beer");
  set_short("A keg of beer");
  set_long("A large wooden beer keg. The smooth polished keg is quite a hefty\n\
load but you can't wait to get your lips on it and drink.\n");
  set_type("drink");
  set_msg("You lift the heavy keg and take a swig from its tap.\n"+
      "*glug* *glug* *glug* ..... AAaaaahhhh!\n");
  set_msg2(" takes a swig from a keg of beer.\n");
  add_cmd("drink");
  add_cmd("swig");
  set_heal(20+random(40), 20+random(40));
  set_charges(6);
  set_intox(7);
  set_value(100); /* Per charge! */
}
