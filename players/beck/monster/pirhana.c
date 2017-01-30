inherit "obj/monster";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
set_name("pirhana");
set_alias("fish");
set_short();
set_long("A small pirhana fish with razor sharp teeth.\n");
set_aggressive(1);
set_level(2);
set_wc(6);
set_ac(3);
set_hp(30);
}
