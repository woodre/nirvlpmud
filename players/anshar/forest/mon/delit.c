
#include "/players/anshar/closed/mydef.h"
inherit "obj/monster";
int X;
int Y;
string SIZE;
object ob;
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  Y = (random(6));
  X = (Y+7);
  if(X == 7) SIZE = " baby ";
  if(X == 8) SIZE = " tiny ";
  if(X == 9) SIZE = " small ";
  if(X == 10) SIZE = " medium ";
  if(X == 11) SIZE = " large ";
  if(X == 12) SIZE = " huge ";
  if(X == 13) SIZE = " giant ";
  set_name("delit");
  set_short("A"+SIZE+"delit");
  set_alias("delit");
  set_race("delit");
  set_long("     With the appearance of a large albino hairless rat\n"+
           "that somehow has become bipedal, the delit glares at you\n"+
           "with squinty eyes. The long tail seems to move prehensily.\n"+
           "Fingers end in sharp nails, and its mouth is filled with\n"+
           "row after row of sharp teeth, perfect for rending flesh.\n");
  set_hp(X*20);
  set_level(X);
  set_al(-200);
  set_wc(X+7);
  set_ac(X+1);
  set_aggressive(0);

  set_dead_ob(TO);

  set_chat_chance(3);
  set_a_chat_chance(15);
  load_chat("The delit peers at you cautiously.\n");
  load_chat("The delit suddenly quivers, and then is still.\n");
  load_a_chat("Whoops and hollers can be heard from the woods all about.\n");

}
monster_died() {
if(attacker_ob) tell_object(attacker_ob, "You slice off the delit's valuable tail.\n");
ob=clone_object(FITEM+"tail");
ob->set_amount(Y);
move_object(ob,environment(TO));
return 0;
}
