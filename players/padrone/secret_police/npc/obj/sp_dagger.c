/*
 * sp_dagger.c
 * Secret Police dagger
 */

inherit "obj/weapon";

void
reset(status arg)
{
  ::reset(arg);
  if (arg)
    return;
  set_name("dagger");
  set_short("A dagger");
  set_class(6);
  set_value(10);
  set_weight(1);
}
