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
    
  set_alt_name("blade");
  set_alias("blade of honor");
  set_name("The "+HIR+"Bloodfist"+HIK+" Blade of Honor"+NORM);
  set_long(
    "An ornate grey blade with a blood red gold inlaid hilt.  Fastkills\n"+
    "Honor blade can clearly be seen engraved on the blades hilt.  The  \n"+
    "edge of the blade looks as if it would cut a god if god was in the way.\n");
  set_read("Honor First\n");
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
  a = random(5);
  b = random(5);
  c = random(5);
  d = random(5);

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

  if(a==2){
    if(!attacker) return 1;
    write(WEP+"Blood"+NORM+" races along the blade of your "+BOLD+"sword"+NORM+WEP+"\n"+NORM);
    say(WEP+"Blood"+NORM+" races along the blade of "+environment()->query_name()+"'s "+BOLD+"sword"+NORM+"!\n"+NORM);
  attacker->hit_player((2), "other|physical");
  }  

  if(a==1){
    if(!attacker) return 1;
    write(WEP+"Blood"+NORM+" quenches "+BOLD+"The "+HIR+"Bloodfist"+HIK+" Blade of Honor"+NORM+WEP+"\n"+NORM);
    say(WEP+"Blood"+NORM+" flows down "+environment()->query_name()+"'s "+BOLD+"sword"+NORM+"!\n"+NORM);
  attacker->hit_player((2), "other|physical;");
  }

  if(a==0){
    if(!attacker) return 1;
    write(BOLD+"Blood"+NORM+" splashes over "+BOLD+"sword"+NORM+WEP+"!\n"+NORM);
    say(BOLD+WEP+"Blood"+NORM+" splashes off or "+environment()->query_possessive()+"  "+BOLD+"sword"+NORM+"!\n"+NORM);
  attacker->hit_player((0), "other|Jareel");
  }
  return 1;
}
