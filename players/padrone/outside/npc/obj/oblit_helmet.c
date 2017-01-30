/*
 * oblit_helmet.c
 * Sir Obliterator's helmet
 */

inherit "obj/armor";

void
reset(status arg)
{
  ::reset(arg);
  if (arg)
    return;
  set_name("metal helmet");
  set_alias("helemt");
  set_type("helmet");
  set_ac(1);
  set_weight(2);
  set_value(75);
  set_short("A metal helmet");
  set_long("A metal helmet.\n");
}
