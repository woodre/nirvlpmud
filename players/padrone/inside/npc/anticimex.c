/*
 * anticimex.c
 * Exterminator for food_cellar.c
 */

inherit "obj/monster";

object bottle;

void
reset(status arg)
{
  monster::reset(arg);
  if (arg)
    return;
  set_name("vermin exterminator");
  set_alias("exterminator");
  set_level(2);
#if 0 /* Adjusting for Nirvana monster.guide -- Rumplemintz */
  set_male();
  set_wc(5);
#else
  set_hp(30);
  set_wc(6);
  set_ac(3);
#endif
  set_al(-12);
  set_short("A vermin exterminator from Anticimex");
  set_long("This is an old man in blue coveralls marked 'Anticimex'.\n"+
           "He is here to kill the rats that have infested the cellar.\n");

  /* rat poison */
  bottle = clone_object("obj/drink");
  bottle->set_value("black bottle#A largish black bottle with some kind of liquid inside#Yuk! Rat poison! You feel horrible#-5#50#1");
  move_object(bottle, this_object());
}
