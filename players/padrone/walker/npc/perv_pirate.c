/*
 * perv_pirate.c
 * perverted pirate in kitchen
 */

inherit "obj/monster";

void
reset(status arg)
{
  ::reset(arg);
  if (arg)
    return;
  set_name("perverted pirate");
  set_alias("pirate");
  set_gender("male");
  set_level(3);
  set_hp(45);
  set_wc(7);
  set_ac(4);
  set_al(-120);
  set_short("A perverted pirate");
  set_long("This pirate really is perverted!\n"+
           "It is disgusting to see what he is doing.\n"+
           "You didn't know that it was anatomically possible to do that,\n"+
           "at least not with cabbage...\n"+
           "You are shocked.\n");
  set_aggressive(1);
}
