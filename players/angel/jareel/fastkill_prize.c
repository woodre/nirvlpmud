/* Fastkill Prize for showing the crazy coin bug mobs do */

#include "/players/jareel/ansi.h"
inherit "/obj/weapon";
#define ATT USER->query_attack()
#define USER environment(this_object())
#define WEP HIR+"=="+HIB+"*"+HIR+"=="+NORM
#define EN environment()->query_name() 

reset(arg){
  if(arg) return;
    ::reset(arg);
    
  set_alt_name("sword");
  set_alias("lightning sword");
  set_name("The "+HIR+"Bloodfist"+HIK+" Blade of Honor "+NORM+BOLD+"["+HIC+"Chaos Honed"+NORM+BOLD+"]"+NORM);
  set_long(
    "Shock is a simple blade arching with electricity.  Its power is not in\n"+
    "its physical dominance but in the power it unleashes on its enemy.  The\n"+
    "energy that flows over the blade was found on the hero plane.\n");
  set_read("Lightning Sword\n");
  set_class(21);
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
  a = random(4);
  b = random(4);
  c = random(4);
  d = random(4);
  e = random(4);
  f = random(4);
  g = random(4);
  h = random(4);
  i = random(4);
  j = random(4);
  k = random(4);
  l = random(4);

  if(a==0){
    if(!attacker) return 1;
    write(BOLD+"\nYou blur with deadly speed!\nYou blur with deadly speed!\nYou blur with deadly speed!\n"+NORM);
    say(BOLD+EN+" blurs with deadly speed!\n"+NORM);
  attacker->hit_player(1);
  }
 
  if(b==0){
    if(!attacker) return 1;
    write(BOLD+"\nYou...\n      S L A S H\n           "+ATT->query_name()+" through the throat!\n\n"+NORM);
    say(BOLD+EN+"\n S L A S H E S "+ATT->query_name()+" through "+ATT->query_possessive()+" throat!\n\n"+NORM);
  attacker->hit_player(1);
  }
 
  if(c==0){
    if(!attacker) return 1;
    write(HIR+"Fire erupts off your blade searing flesh.\n      "+ATT->query_name()+" writhes in pain!!!!\n"+NORM);
    say(HIR+"\nFire leaps off of "+EN+"\n\n"+NORM);
  attacker->hit_player(1+random(2), "other|fire");
  }

  if(d==0){
    if(!attacker) return 1;
    write(BOLD+"\nYou descend upon "+ATT->query_name()+" with deadly grace!\n"+
    "          "+ATT->query_name()+" is gutted like a fish.\n\n"+NORM);
    say(WEP+environment()->query_name()+" descends upon "+ATT->query_name()+" with deadly grace!\n"+
    "          "+ATT->query_name()+" recoils with fear and horror."+WEP+"\n"+NORM);
  attacker->hit_player(1);
  }

  if(e==0){
    if(!attacker) return 1;
    write(BOLD+"\nYou hold your "+BOLD+"The Bloodfist Blade of Honor"+NORM+" poised above your head.\n\n"+NORM);
    say(environment()->query_name()+" holds "+environment()->query_possessive()+BOLD+" sword"+NORM+" poised above     "+ATT->query_name()+"'s head."+WEP+"\n"+NORM);
  attacker->hit_player(random(2));
  }

  if(f==0){
    if(!attacker) return 1;
    write("\nYou jump high in the air!\n\n"+NORM);
    say(environment()->query_name()+" jumps high in the air!\n"+NORM);
  attacker->hit_player(2);
  }   

  if(g==0){
    if(!attacker) return 1;
    write(BOLD+"\nYou gracefully whirl in close to "+ATT->query_name()+"\n\n"+NORM);
    say(BOLD+environment()->query_name()+" gracefully whirl in closes to     "+ATT->query_name()+".\n"+NORM);
  attacker->hit_player(2);
  }

  if(h==0){
    if(!attacker) return 1;
    write(BOLD+"\nYou lift your "+BOLD+"sword"+NORM+" high in the air, blurring toward "+ATT->query_name()+"'s face!\n\n"+NORM);
    say(BOLD+environment()->query_name()+" lifts the "+BOLD+"sword"+NORM+" high in the air, blurring toward "+ATT->query_name()+"'s face!\n"+NORM);
  attacker->hit_player(2);
  }

  if(i==0){
    if(!attacker) return 1;
    write("\nYou descend upon "+ATT->query_name()+" with deadly grace!\n\n"+
    ""+BOLD+ATT->query_name()+" recoils with fear and horror.\n"+NORM);
    say(environment()->query_name()+" descends upon "+ATT->query_name()+" with deadly grace!\n"+
  ""+BOLD+ATT->query_name()+" recoils with fear and horror.\n"+NORM);
  attacker->hit_player(2);
  }

  if(j==0){
    if(!attacker) return 1;
    write("\nElectricity sparks everywhere!\n\n"+
    ""+BOLD+ATT->query_name()+" freezes in helpless pain\n"+NORM);
    say("Electricity sparks everywhere!\n"+
    ""+BOLD+ATT->query_name()+" freezes in helpless pain.\n"+NORM);
  attacker->hit_player(1+random(2));
  }

  if(k==0){
    if(!attacker) return 1;
    write("\nA "+BOLD+BLINK+"LIGHTNING BOLT"+NORM+" of energy leaps off the sword!\n"+
    "          You cackle in ecstasy!\n"+ATT->query_name()+" is chared, screaming, from the ground!\n\n"+NORM);
    say(" of energy leaps off "+environment()->query_name()+"'s sword!\n"+
    environment()->query_name()+" cackles in ecstasy!\n"+ATT->query_name()+" is chared, screaming, from the ground!\n"+NORM);
  attacker->hit_player(3);
  }

  if(l==0){
    if(!attacker) return 1;
    write("\nThe "+BOLD+"lightning"+NORM+" releases all of its energy into "+ATT->query_name()+"!\n"+
    "          "+ATT->query_name()+" groans pitifully and falls into a smoking heap on the floor.\n\n"+NORM);
    say("The "+BOLD+"lightning"+NORM+" releases all of its energy into "+ATT->query_name()+"!\n"+
    ""+ATT->query_name()+" groans pitifully and falls into a smoking heap on the floor.\n"+NORM);
  attacker->hit_player(1);
  }

  if(a==2){
    if(!attacker) return 1;
    write(WEP+BOLD+BLINK+"L I G H T N I N G"+NORM+" races along the blade of your "+BOLD+"sword"+NORM+WEP+"\n"+NORM);
    say(WEP+BOLD+BLINK+"L I G H T N I N G"+NORM+" races along the blade of "+environment()->query_name()+"'s "+BOLD+"sword"+NORM+"!\n"+NORM);
  attacker->hit_player((3), "other|electricity");
  }  



  if(a==1){
    if(!attacker) return 1;
    write(WEP+BOLD+BLINK+"L I G H T N I N G"+NORM+" races along the blade of your "+BOLD+"sword"+NORM+WEP+"\n"+NORM);
    say(WEP+BOLD+BLINK+"L I G H T N I N G"+NORM+" races along the blade of "+environment()->query_name()+"'s "+BOLD+"sword"+NORM+"!\n"+NORM);
  attacker->hit_player((3), "other|electricity");
  }

  if(a==0){
    if(!attacker) return 1;
    write(BOLD+BLINK+"L I G H T N I N G"+NORM+" blasts off the searing outline of your "+BOLD+"sword"+NORM+WEP+"!\n"+NORM);
    say(BOLD+BLINK+WEP+"L I G H T N I N G"+NORM+" blasts off the searing outline of "+environment()->query_possessive()+"  "+BOLD+"sword"+NORM+"!\n"+NORM);
  attacker->hit_player((2), "other|electricity");
  }
  return 1;
}
