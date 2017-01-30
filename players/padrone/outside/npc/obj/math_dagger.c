/*
 * math_dagger.c
 * dagger for Mathilda
 */

inherit "obj/weapon";

void
reset(status arg)
{
  ::reset(arg);
  if (arg)
    return;
  set_name("dagger");
  set_class(7);
  set_value(10);
  set_weight(1);
  set_short("A dagger");
  set_long("This is an ordinary dagger, like the ones thieves often carry.\n");
}
