#include "/players/mythos/closed/ansi.h"
#define tp this_player()->query_name()
inherit "players/mythos/amon/forest/monster1";

int a,b;
object att;

reset(arg)  {
  object ob;
  ::reset(arg);
  if(arg) return;
  set_name("jinro");
  set_race("beast");
  set_short("Jinro- half man, half beast");
  set_long("The one horned beast is of incredible beauty.  Its black hide radiates\n"+
    "an aura of tranquility.  Its black mane ruffles in the wind\n"+
    "and its horn gleams with an inner light.\n");
  set_hp(500);
  set_level(20);
  set_al(-500);
  set_wc(35);
  set_ac(17);
  set_aggressive(0);
  set_chat_chance(1);
  set_a_chat_chance(10);
  load_chat("Jinro watches you.\n");
  load_a_chat("Fire rains down on you!\n");
  call_out("scary1",3);
}

scary1() {
att=(this_object()->query_attack());
   if(att) {
     a=att->query_hp();
   call_out("scary2",3); return 1;}
call_out("scary1",3);
return 1;}

scary2() {
att=(this_object()->query_attack());
  b=att->query_hp();
  if(b>a) {
  att->add_hit_point(-(b-a)-5);
  tell_room(environment(this_object()),RED+"\t\tJinro screams and FIRE rains down on you!\n"+NORM);
  call_out("scary1",3);
  return 1;}
  call_out("scary",3);
  return 1;} 
