/*
 * squirrel that loads up in path2.c
 */

inherit "obj/monster";

void
reset(status arg)
{
  ::reset(arg);
  if (arg)
    return;
  set_name("squirrel");
  set_short("A squirrel");
  set_long("This is a small, furry squirrel.\n" +
           "It looks very nice and friendly.\n");
  set_level(1);
  set_al(50);
#if 0   /* Original values in here, Nirvana values after */
  set_ep(60);
  set_hp(10);
  set_ac(2);
  set_wc(4);
#else
  set_wc(5);
  set_ac(3);
  set_hp(15);
#endif  /* Nirvana changes, we don't set_ep, inherit handles for us */
}
