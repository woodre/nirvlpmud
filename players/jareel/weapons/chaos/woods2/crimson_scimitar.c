

/* Wep Average with Charge activated
   Hits  Average  Max
   583    11.57   56

   Wep Average without charge activated
   Hits  Average  Max
   570     4.19   26                    */

#include "/players/jareel/define.h"
inherit "obj/weapon.c";
#define ATT USER->query_attack()
#define USER environment(this_object())
int bladesharp;
int energize;
int MAGIC;

reset(arg) {
   ::reset(arg);
   if (arg) return;

   set_name("scimitar of the crimson bat");
   set_alias("scimitar");
   set_type("sword");
   get_short();
   set_class(21);
   set_weight(1);
   set_value(8000);
   set_long(
      HIR+"\n"+
      "\n"+
      "\n");
   set_hit_func(this_object());
}

weapon_hit(attacker){
  int i;

  if(energize != 1) {
    return 0;   
  }

  i = random(8);
  if(i==7){
write(HIK+"Sword hit 7\n"+NORM);
say(HIK+environment()->query_name()+"'s sword hit 7\n"+NORM);
attacker->hit_player(1+random(5), "other|physical");
  
  }

  if(i==6){
write(HIK+"sword hit6...\n"+NORM);
say(HIK+"sword hit 6\n"+NORM);
attacker->hit_player(1+random(6), "other|dark");
  
  }

  if(i==5){
write(HIK+"sword hit5...\n"+NORM);
say(HIK+"deptf hit5...\n"+NORM);
attacker->hit_player(1+random(6), "other|physical");
  
  }

  if(i==4){
write(HIK+"sword hit4\n"+NORM);
say(HIK+"sword hit4\n"+NORM);
attacker->hit_player(10+random(40), "other|physical");
  
  }

  if(i==3){
write(HIK+"swordhit3.\n"+NORM);
say(HIK+"sword hit3.\n"+NORM);
attacker->hit_player(1+random(4), "other|dark");
  
  }

  if(i==2){
write(RED+"sword hit2.\n"+NORM);
say(RED+"sword hit2.\n"+NORM);
attacker->hit_player(5+random(3), "other|physical");
  
  }

  if(i==1){
write(HIG+"sword hit1\n");
say(HIG+"sword hit1.\n");
attacker->hit_player(11+random(9), "other|poison");
  }
}

status wield(string str) {
   int x,s;

   if(!id(str)) return 0;

   if(environment()!=TP) return 0;

   if ((status)this_player()->query_pl_k() != 1) { write("Set your pk flag bitchboy.\nTil then use some other crappy ass weapon.\n");
     return 1; }


   if(present("notweapon",this_player())) {
      write("For some reason you are unable to wield this weapon.\n");
      return 1;
   }
   
   if (wielded) {
      write("You already wield it!\n");
      return 1;
   }
   
   wielded_by = this_player();
   call_other(this_player(), "wield", this_object(), silentwield);
   wielded = 1;
   
   return 1; 
}
   
init(){
   ::init();
   add_action("crimsoncharge","vortex");
}
   
check_wielded(){

   if(this_player()->query_weapon() == this_object()){
     return 1; 
   }
   
   else {
     notify_fail(BOLD+"You must be wielding the scimitar.\n"+NORM);
     return 0;  
   }
}
   
check_magic(){
   int i;

   i = this_player()->query_attrib("int");
   if(i > 30) i = 30;
   if(i < 0) i = 0;
   return i; 
}

crimsoncharge(){
   int time;

   MAGIC = check_magic();
   if(check_wielded() == 0) return 0;

   if(this_player()->query_spell_point() < 50){
     notify_fail(BOLD+"You lack the energy to charge the tail.\n"+NORM);
     return 0;  
   }

   this_player()->add_spell_point(-50);
   energize = 1;
   get_short();
   time = ((500+random(500))*MAGIC)/3;
   call_out("remove_energy",time);
   write(HIG+"\nAn energy surge flows into the blade.....\n\n"+
   "        "+NORM+"\n");
   return 1;  
}
   
remove_energy(){
   write(HIG+"The energy fades from the tail....\n"+NORM);
   say(HIG+"The energy from the tail fades....\n"+NORM);
   energize = 0;
   get_short();
   return 1;  
}
   
get_short(){
   string str;
   str = ""+HIR+"Scimitar of the Crimson Bat"+NORM+"";

   if(energize == 1){
     str += ""+RED+"  ["+NORM+BOLD+"Vortex Charged"+NORM+RED+"]"+NORM+"";
   }

   set_short(str);
}

query_wear(){ return 1; }

