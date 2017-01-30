#include "/players/jareel/ansi.h"
inherit "/obj/weapon";
#define USER environment()
#define WEP RED+"<<<<"+CYN+"***"+RED+">>>>"+NORM

reset(arg){
  if(arg) return;
    ::reset(arg);
    
  set_alt_name("shock");
  set_alias("lightning sword");
  set_name(HIY+"Shock, "+HIB+"lightning sword"+NORM+" of Orlanth Thunderous");
  set_long(
    "Shock is a simple blade arching with other|electric.  Its power is not in\n"+
    "its physical dominance but in the power it unleashes on its enemy.  The\n"+
    "energy that flows over the blade was found on the hero plane.\n");
  set_read("Lightning Sword\n");
  set_class(5);
  set_type("sword");
  set_weight(1);
  set_value(10000);
  set_hit_func(this_object());
}

query_wear() {
   return 1;
}

weapon_breaks() {
   return 1;
}

weapon_hit(attacker){
     
  int a;
  int b;
  int c;
  int d;
  int e;
  int f;
  int g;
  int h;
  int i;
  int j;
  int k;
  int l;
  a = random(3);
  b = random(2);
  c = random(3);
  d = random(3);
  e = random(3);
  f = random(3);
  g = random(3);
  h = random(3);
  i = random(3);
  j = random(3);
  k = random(3);
  l = random(3);

  if(a==0){
    if(!attacker) return 1;
    write(WEP+"Electricity sparks everywhere!"+WEP+"\n"+NORM);
    say(WEP+"Electricity sparks everywhere!"+WEP+"\n"+NORM);
  attacker->hit_player(1+random(2), "other|electric");
  }
 
  if(b==0){
    if(!attacker) return 1;
    write(WEP+"You impale "+attacker->query_name()+" through the throat!"+WEP+"\n"+NORM);
    say(WEP+environment()->query_name()+" impales "+attacker->query_name()+" through "+attacker->query_possessive()+" throat!"+WEP+"\n"+NORM);
  attacker->hit_player(1+random(2));
  }
 
  if(c==0){
    if(!attacker) return 1;
    write(WEP+"Electricity arcs over "+attacker->query_name()+WEP+"\n"+NORM);
    say(WEP+"Electricity arcs over "+attacker->query_name()+WEP+"\n"+NORM);
  attacker->hit_player(2+random(2), "other|electric");
  }

  if(d==0){
    if(!attacker) return 1;
    write(WEP+"You descend upon "+attacker->query_name()+" with deadly grace!\n"+
    ""+attacker->query_name()+" recoils with fear and horror."+WEP+"\n"+NORM);
    say(WEP+environment()->query_name()+" descends upon "+attacker->query_name()+" with deadly grace!\n"+
    ""+attacker->query_name()+" recoils with fear and horror."+WEP+"\n"+NORM);
  attacker->hit_player(2+random(2), "other|electric");
  }

  if(e==0){
    if(!attacker) return 1;
    write(WEP+"You hold your "+BOLD+"sword"+NORM+" poised above your head."+WEP+"\n"+NORM);
    say(WEP+environment()->query_name()+" holds "+environment()->query_possessive()+BOLD+" sword"+NORM+" poised above     "+attacker->query_name()+"'s head."+WEP+"\n"+NORM);
  attacker->hit_player(random(2), "other|electric");
  }

  if(f==0){
    if(!attacker) return 1;
    write(WEP+"You jump high in the air!"+WEP+"\n"+NORM);
    say(WEP+environment()->query_name()+" jumps high in the air!"+WEP+"\n"+NORM);
  attacker->hit_player(2+random(3), "other|electric|wind");
  }   

  if(g==0){
    if(!attacker) return 1;
    write(WEP+"You gracefully whirl in close to "+attacker->query_name()+WEP+"\n"+NORM);
    say(WEP+environment()->query_name()+" gracefully whirl in closes to     "+attacker->query_name()+"."+WEP+"\n"+NORM);
  attacker->hit_player(random(2));
  }

  if(h==0){
    if(!attacker) return 1;
    write(WEP+"You lift your "+BOLD+"sword"+NORM+" high in the air, blurring toward "+attacker->query_name()+"'s face!"+WEP+"\n"+NORM);
    say(WEP+environment()->query_name()+" lifts the "+BOLD+"sword"+NORM+" high in the air, blurring toward "+attacker->query_name()+"'s face!"+WEP+"\n"+NORM);
  attacker->hit_player(1+random(2));
  }

  if(i==0){
    if(!attacker) return 1;
    write(WEP+"You descend upon "+attacker->query_name()+" with deadly grace!\n"+
    ""+attacker->query_name()+" recoils with fear and horror."+WEP+"\n"+NORM);
    say(WEP+environment()->query_name()+" descends upon "+attacker->query_name()+" with deadly grace!\n"+
  ""+attacker->query_name()+" recoils with fear and horror."+WEP+"\n"+NORM);
  attacker->hit_player(2+random(2), "other|electric");
  }

  if(j==0){
    if(!attacker) return 1;
    write(WEP+"Electricity sparks everywhere!\n"+
    ""+attacker->query_name()+" freezes in helpless pain"+WEP+"\n"+NORM);
    say(WEP+"Electricity sparks everywhere!\n"+
    ""+attacker->query_name()+" freezes in helpless pain."+WEP+"\n"+NORM);
  attacker->hit_player(1+random(2));
  }

  if(k==0){
    if(!attacker) return 1;
    write(WEP+"A "+BOLD+BLINK+"LIGHTNING BOLT"+NORM+" of energy leaps off the sword!\n"+
    "You cackle in ecstasy!\n"+attacker->query_name()+" is charred, screaming, from the ground!"+WEP+"\n"+NORM);
    say(WEP+" of energy leaps off "+environment()->query_name()+"'s sword!"+WEP+"\n"+
    environment()->query_name()+" cackles in ecstasy!\n"+attacker->query_name()+" is charred, screaming, from the ground!"+WEP+"\n"+NORM);
  attacker->hit_player(2+random(3), "other|electric");
  }

  if(l==0){
    if(!attacker) return 1;
    write(WEP+"The "+BOLD+"lightning"+NORM+" releases all of its energy into "+attacker->query_name()+"!"+WEP+"\n"+
    ""+attacker->query_name()+" groans pitifully and falls into a smoking heap on the floor."+WEP+"\n"+NORM);
    say(WEP+"The "+BOLD+"lightning"+NORM+" releases all of its energy into "+attacker->query_name()+"!\n"+
    ""+attacker->query_name()+" groans pitifully and falls into a smoking heap on the floor."+WEP+"\n"+NORM);
  attacker->hit_player(4+random(2), "other|electric");
  }
  

  if(a==2){
    if(!attacker) return 1;
    write(BOLD+"Lightning"+NORM+" blasts off the searing outline of your "+BOLD+"sword"+NORM+"!"+WEP+"\n"+NORM);
    say(BOLD+"Lightning"+NORM+" blasts off the searing outline of "+environment()->query_possessive()+" "+BOLD+"sword"+NORM+"!"+WEP+"\n"+NORM);
  attacker->hit_player(3+random(2), "other|electric");
  }

  if(a==1){
    if(!attacker) return 1;
    write("Lightning"+NORM+" races along the blade of your "+BOLD+"sword"+NORM+WEP+"\n"+NORM);
    say("Lightning"+NORM+" races along the blade of "+environment()->query_name()+"'s "+BOLD+"sword"+NORM+WEP+"!\n"+NORM);
  attacker->hit_player(3+random(3), "other|electric");
  }

  if(a==0){
    if(!attacker) return 1;
    write(WEP+BOLD+"Lightning"+NORM+" blasts off the searing outline of your "+BOLD+"sword"+NORM+WEP+"!\n"+NORM);
    say(WEP+BOLD+"Lightning"+NORM+" blasts off the searing outline of "+environment()->query_possessive()+"     "+BOLD+"sword"+NORM+WEP+"!\n"+NORM);
  attacker->hit_player(3+random(2), "other|electric");
  }
  return 1;
}
