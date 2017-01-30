#include "/players/illarion/ansi.h"
inherit "obj/monster";
int dmg,rounds;
int max;

reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_name("blob");
   set_level(15);
   set_race("blob");
   set_short("Blob");
   set_long("A nasty, squishy, red, pulsating, glob of...  Who the hell knows.\n");
   set_hp(1000);
   set_wc(1);
   set_ac(0);
   set_al(0);
   dmg=0;
   rounds=0;
   }
init() {
   ::init();
   add_action("damage","damage");
   add_action("glob","glob");
   add_action("beat","beat");
  add_action("change_wc","set_wc");
  add_action("change_ac","set_ac");
}
heart_beat() {
   if(attacker_ob) {
      dmg += 1000-hit_point;
      rounds++;
      say("Damage was "+HIR+(1000-hit_point)+NORM+".  Average is "+HIR+(dmg/rounds)+"."+ pad(((dmg-((dmg/rounds)*rounds))*1000)/rounds,-3,'0')+NORM+"\n");
      if((1000-hit_point) > max) max=1000-hit_point;
      heal_self(1000);
   }
  ::heart_beat();
}

damage() {
   int tmprnd;
   tmprnd = rounds;
   if(tmprnd==0) {
      tmprnd = 1;
   }
   write("Damage: "+dmg+"\n");
   write("Rounds: "+rounds+"\n");
   write ("Average: " + (dmg/tmprnd) + "." + pad(((dmg - ((dmg / tmprnd) * tmprnd)) * 1000) / tmprnd, -3, '0') + NORM + "\n");
   write("Max: "+max+"\n");
   write("\"glob\" to reset\n");
   return 1;
}
glob() {
   write("Ok.\n");
   dmg=0;
   rounds=0;
   max = 0;
   return 1;
}
beat(str) {
   if(attacker_ob) {
      write("Blob is already attacking something.\n");
     return 1;
   }
   if(!str) {
      write("Blob burps:  Attack what?\n");
      return 1;
   }
   if(present(str) && living(present(str))) {
      attack_object(present(str));
      attack();
   return 1;
   }
}

change_wc(string str) {
  int x;
  if(!str) return 0;
  if(!sscanf(str,"%d",x)) return 0;
  set_wc(x);
  return 1;
}
change_ac(string str) {
  int x;
  if(!str) return 0;
  if(!sscanf(str,"%d",x)) return 0;
  set_ac(x);
  return 1;
}

dump_to_room(blah) {
  int s;
  s=sizeof(blah);
  while(s--)
    tell_room(environment(),blah[s]+",");
  tell_room(environment(),"\n");
}

show_damage(damage,type) {
  int x,s;
  s=sizeof(damage);
  tell_room(environment(),"  ");
  for(x=0;x<s;x++)
    tell_room(environment(),pad(type[x],15));
  tell_room(environment(),"\n    ");
  for(x=0;x<s;x++)
    tell_room(environment(),pad(damage[x],15));
  tell_room(environment(),"\n");
}
do_damage(int *damage, string *type) {
  mixed dam;
  show_damage(damage,type);
  dam= ::do_damage(damage,type);
  tell_room(environment(),"Damage taken in hit: "+dam+"\n");
  return dam;
}
