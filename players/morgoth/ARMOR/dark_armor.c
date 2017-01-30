inherit "obj/armor";

reset(arg)
{
  if (arg) return;
  ::reset(arg);
  set_name("dark armor");
  set_alias("armor");
  set_short("Dark Armor");
  set_long("A suit of armor made from some unknown alloy.  It is so dark that it\n"+
           "seems to absorb all light.\n");
  set_weight(4);
  set_ac(4);
  set_value(200);
  set_type("armor");
}
