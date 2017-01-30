#include "/players/mythos/closed/ansi.h"
inherit "obj/monster";
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_alias("messenger");
  set_name("sniper");
  set_gender("male");
  set_short();
  set_race("human");
  set_long("\n");
  set_hp(10000);
  set_level(30);
  set_dead_ob(this_object());
  set_al(-1000);
  set_ep(0);
  set_wc(0);
  set_ac(1000);
  set_aggressive(0);
  call_out("cmd",10);
}

cmd() {
object ob;
int n;
  if(!environment(this_object())) return 1;
  ob = users();
  for(n=0;n<sizeof(ob);n++) {
   if(ob[n]) if(ob[n]->query_level() > 2) if(environment(ob[n]))
    if(present("snipe",ob[n]) && (random(10) == 0)) {
    tell_room(environment(ob[n]),"\n\t\tBANG!\n\n");
      tell_object(ob[n],
      HIR+"\nYou feel a sharp pain! You look down and you are bleeding!\n\n"+NORM);
      ob[n]->heal_self(-10-random(10));
      command("drop all",ob[n]); }
		}
	call_out("cmd",100 + random(1000)); 
	return 1;}
	
monster_died() {
object ob;
int n;
  ob = users();
    for(n=0;n<sizeof(ob);n++) {
    if(present("snipe",ob[n])) { destruct(present("snipe",ob[n])); } }
return 0;}
