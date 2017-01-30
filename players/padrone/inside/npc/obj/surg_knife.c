/*
 * surg_knife.c
 * Surgeon's main knife
 */

inherit "obj/weapon";

void
reset(status arg)
{
  weapon::reset(arg);
  if (arg)
    return;
  set_name("knife");
  set_alias("big knife");
  set_alt_name("big swordlike razor-sharp knife");
  set_short("A big, swordlike, razor-sharp knife");
  set_class(14);
  set_value(600);
  set_weight(2);
}
