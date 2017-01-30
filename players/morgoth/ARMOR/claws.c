inherit "obj/armor";

reset(arg)
{
  if (arg) return;
  ::reset(arg);
  set_name("leather armor");
  set_alias("armor");
  set_short("Leather Armor");
  set_long("A suit of leather armor.  It is worn by the guards\n"+
           "in Morgoth's castle.  It has Morgoth's insignia on\n"+
           "the breastplate.\n");
  set_weight(3);
  set_ac(2);
  set_value(110);
  set_type("armor");
}
