/*Monster created to show damage done.
  CREATED by snow and implemente by mythos
  altered for current implementation by Anshar*/

#include "/players/anshar/closed/ansi.h"
inherit "/obj/monster";
 
int thp;
 
reset(arg) {
   ::reset(arg);
   if (!arg) {
 
     set_name("automaton");
     set_short("A battle automaton");
     set_race("android");
     set_alias("form");
     set_long("     This slick automaton is here for you to test your\n"+
              "proficiency in battle. Matte black exoskeleton overlays\n"+
              "the best in nanotech repair technology. Not a single ding\n"+
              "marks its pristine surface. To stop combat with it, simply\n"+
              "'halt'\n");
     set_level(1);
     set_ac(0);
     set_wc(0);
     set_hp(2000);
     set_al(0);
     set_aggressive(0);
     set_no_exp_value(1);
thp = 2000;
   }
}
 
init() {
  ::init();
  add_action("halt","halt");
    }
 
halt() {
  if(this_player()->query_attack()){
  object obj;
  write("You halt the fight.\n");
  obj = this_player()->query_attack();
  this_player()->stop_fight();  this_player()->stop_fight();
  obj->stop_fight();  obj->stop_fight();
  this_player()->stop_hunter();  obj->stop_hunter();
  test_show();
  return 1; }
  write("You are not engaged in battle currently.\n");
  return 1;
}
 
test_show() {
  int chp,diff;
chp = this_object()->query_hp();
diff = ( thp - chp );
  if(diff<0)diff=0;
  tell_room(environment(this_object()),BOLD+"DAMAGE:"+NORM);
  while(diff>0)
{
  tell_room(environment(this_object()),GRN+">"+NORM);
  diff-=5;
}
  tell_room(environment(this_object()),"\n");
return 1;
}

heart_beat() {
  ::heart_beat();
  if(this_player()->query_attack()) test_show();
  heal_self(1000);
  return 1;
}
rebeat() { call_out("rebeat",20); set_heart_beat(1); heart_beat(); return 1; }
