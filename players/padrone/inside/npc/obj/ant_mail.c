/*
 * ant_mail.c
 * Antonio's chainmail
 */

inherit "obj/armor";

void
reset(status arg)
{
  armor::reset(arg);
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
