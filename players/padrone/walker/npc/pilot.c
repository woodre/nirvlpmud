/*
 * pilot.c
 * walking castle pilot
 */

inherit "obj/monster";

void
reset(status arg)
{
  ::reset(arg);
  if (arg)
    return;
  set_name("pilot");
  set_alias("castle pilot");
  set_gender("male");
  set_level(3);
#if 0 /* Adjusting for Nirvana monster.guide -- Rumplemintz */
  set_wc(5);
  set_ep(140);
#else
  set_hp(45);
  set_wc(7);
  set_ac(4);
#endif
  set_al(-100);
  set_short("The pilot who is controlling the walking castle");
  set_long("This is a pilot. Using the controls on the bridge,\n"+
           "he can move the walking castle.\n");
}
