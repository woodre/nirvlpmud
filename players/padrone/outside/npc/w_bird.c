/*
 * w_bird.c
 * bird for w.c room
 */

inherit "obj/monster";

void
reset(status arg)
{
  ::reset(arg);
  if (arg)
    return;
  set_name("bird");
  set_alias("small bird");
  set_level(1);
#if 0  /* Adjusted for Nirvana monster.guide -- Rumplemintz */
  set_ep(60);
  set_hp(10);
  set_ac(2);
  set_wc(4);
#else
  set_hp(15);
  set_ac(3);
  set_wc(5);
#endif
  set_al(50);
  set_short("A small bird");
  set_long("This is a small bird. Who knows what it can be called?\n"+
           "It looks very nice and friendly.\n");
}
