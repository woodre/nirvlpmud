/*
 * ant_razor.c
 * Antonio's razor
 */

inherit "obj/weapon";

void
reset(status arg)
{
  weapon::reset(arg);
  if (arg)
    return;
  set_name("razor");
  set_class(5);
  set_value(10);
  set_weight(1);
  set_short("A razor");
}
