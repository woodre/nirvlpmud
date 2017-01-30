/*
 * phelm.c
 * Standard pirate helmet
 */

inherit "obj/armor";

void
reset(status arg)
{
  armor::reset(arg);
  if (arg)
    return;
  set_name("metal helmet");
  set_alias("helmet");
  set_type("helmet");
  set_ac(1);
  set_weight(3);
  set_value(75);
  set_short("A metal helmet");
}
