inherit "obj/monster";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
set_name("shark");
set_short();
set_alias("shark");
set_long("A small Sand Shark.  It is about 4 feet in length,\n"+
"and has a brown smooth, slimy skin.  It is trying to nibble your toes.\n");
set_level(5);
set_wc(9);
set_ac(5);
set_hp(75);
set_chat_chance(1);
load_chat("A sand shark swims in circles around your feet.\n");
}
