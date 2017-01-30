/*
 * oblit_mail.c
 * Sir Obliterator's chain mail
 */

inherit "obj/armor.c";

void
reset(status arg)
{
  ::reset(arg);
  if (arg)
    return;
  set_name("chainmail");
  set_alias("armor");
  set_type("armor");
  set_ac(3);
  set_value(500);
  set_weight(5);
  set_short("A suit of chainmail");
}
