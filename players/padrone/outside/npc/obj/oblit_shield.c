/*
 * oblit_shield.c
 * Sir Obliterator's shield
 */

inherit "obj/armor";

void
reset(status arg)
{
  ::reset(arg);
  if (arg)
    return;
  set_name("shield");
  set_alias("big black shield");
  set_type("shield");
  set_ac(1);
  set_value(100);
  set_weight(5);
  set_short("A big black shield with a picture painted on it");
  set_long("The shield is big, black but not very beautiful.\n" +
           "There is a picture painted on it, a picture of a dead\n" +
           "young prince being eaten by a black dragon.\n");
}
