inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("apprentice");
set_race("durkor");
set_short("An apprentice");
set_long(
  "  The durkor before you is training to learn the ways of the\n"+
  "Werjor durkors.  Walking around in her gray robe with her \n"+
  "mind on how to pass his next tasks.  From behind the blackness\n"+
  "of the hood two glowing eyes can be seen\n");
 
set_level(16);
set_hp(300);
set_al(-200);
set_dead_ob(this_object());
set_aggressive(0);
add_money(750+random(500));
set_wc(20 + random(7));
set_ac(13);

}
  