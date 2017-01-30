/*
 * surg_scalpel.c
 * Surgeon's scalpel
 */

inherit "obj/weapon";

void
reset(status arg)
{
  weapon::reset(arg);
  if (arg)
    return;
  set_name("scalpel");
  set_short("A scalpel");
  set_long("A surgeon's scalpel.\n");
  set_class(6);
  set_value(80);
  set_weight(1);
}
