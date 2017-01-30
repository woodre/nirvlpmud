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

   set_name("tail of the cacodemon");
   set_alias("tail");
   set_type("exotic");
   get_short();
   set_class(20);
   set_weight(1);
   set_value(8000);
   set_long(
      HIK+"The long black barbed rope like weapon feels powerfull in your hand. \n"+
      "Dark energy flows over your hand as you hold this weapon.  You feel\n"+
      "like pouring some energy into the tail, adding a "+NORM+BOLD+"charge"+HIK+" to it."+NORM+"\n");
   set_hit_func(this_object());
}

weapon_hit(attacker){
  int i;

  if(energize != 1) {
    return 0;   
  }

  i = random(12);
  if(i==7){
    if(!attacker) return 1;
write(HIK+"The tail cracks, snapping into "+ATT->query_name()+"!\n"+NORM);
say(HIK+environment()->query_name()+"'s whip cracks with energy!\n"+NORM);
attacker->hit_player(1+random(5), "other|physical");
  
  }

  if(i==6){
    if(!attacker) return 1;
write(HIK+"Dark energy flows from the weapon...\n   Darkenss lashess out at "+ATT->query_name()+"...\n"+NORM);
say(HIK+"Darkness flows from "+environment()->query_name()+"'s weapon into "+ATT->query_name()+".\n"+NORM);
attacker->hit_player(1+random(6), "other|dark");
  
  }

  if(i==5){
    if(!attacker) return 1;
write(HIK+"With deadly grace you twirl the whip around you snaping "+ATT->query_name()+"...\n"+NORM);
say(HIK+"With deadly grace "+environment()->query_name()+" twirls the whip snaping "+ATT->query_name()+"...\n"+NORM);
attacker->hit_player(1+random(6), "other|physical");
  
  }

  if(i==4){
    if(!attacker) return 1;
write(HIK+"CCCCCCCRRRRRR\n      RRRRRAAAAAAAAAAA\n             ACCKKKKKKKKKKKKK!!!!!\n"+NORM);
say(HIK+"CCCCCCCCRRRR\n       RRRRRRRAAAAAAAAAAA\n             ACCCCCCCCCCCKKKKKKKKKKK!!!!!!!!\n"+NORM);
attacker->hit_player(10+random(40), "other|physical");
  
  }

  if(i==3){
    if(!attacker) return 1;
write(HIK+"Darkness unfolds as your weapon strikes "+ATT->query_name()+".\n"+NORM);
say(HIK+"Darkness unfolds as "+environment()->query_name()+"'s weapon strikes "+ATT->query_name()+".\n"+NORM);
attacker->hit_player(1+random(4), "other|dark");
  
  }

  if(i==2){
    if(!attacker) return 1;
write(RED+"Blood flys as the whip cracks "+ATT->query_name()+".\n"+NORM);
say(RED+"Blood flys as the whip cracks "+ATT->query_name()+".\n"+NORM);
attacker->hit_player(5+random(3), "other|physical");
  
  }

  if(i==1){
    if(!attacker) return 1;
write(HIG+"Bile drips from the barb at the end of your whip snaps off of "+ATT->query_name()+NORM+"\n");
say(HIG+"A green mucus drips for the barb on "+environment()->query_name()+"'s whip snaps off of "+ATT->query_name()+NORM+".\n");
attacker->hit_player(11+random(9), "other|poison");
  }
}

status wield(string str) {
   int x,s;

   if(!id(str)) return 0;
   if(environment()!=TP) return 0;
   if(TP->query_extra_level() < 25){ write("You can't wield this yet, gain a few levels.\n"); return 1; }
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
   add_action("darkcharge","charge");
}
   
check_wielded(){

   if(this_player()->query_weapon() == this_object()){
     return 1; 
   }
   
   else {
     notify_fail(BOLD+"You must be wielding the tail.\n"+NORM);
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

darkcharge(){
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
   time = ((500+random(500))*MAGIC)/30;
   call_out("remove_energy",time);
   write(HIG+"\nAn energy surge flows into the tail.....\n\n"+
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
   str = ""+HIK+"Tail of the Cacodemon"+NORM+"";

   if(energize == 1){
     str += ""+RED+"  ["+NORM+BOLD+"Dark Matrix"+NORM+RED+"]"+NORM+"";
   }

   set_short(str);
}


