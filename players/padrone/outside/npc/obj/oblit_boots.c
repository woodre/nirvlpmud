/*
 * oblit_boots.c
 * Sir Obliterator's boots
 */

inherit "obj/armor";

void
reset(status arg)
{
  ::reset(arg);
  if (arg)
    return;
  set_name("combat boots");
  set_alias("boots");
  set_type("boot");
  set_ac(1);
  set_weight(1);
  set_value(75);
  set_short("A pair of combat boots");
}
