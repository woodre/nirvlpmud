#include "/players/jaraxle/ansi.h"



#define USER environment(this_object())

inherit "obj/weapon.c";



reset(arg){

  ::reset(arg);

  if (arg) return;

set_name("daggers");

set_alt_name("stiletto daggers");

set_alias("dagger");

set_long(

"  This is a pair of finely crafted daggers. The right\n"+

"dagger has a thin blade that is nearly 1.5' in length\n"+

"and is very lightweight. It's handle is wrapped with a\n"+

"black leather and the pommel is tipped with a small\n"+

"skull with green emeralds for eyes.  The left dagger\n"+

"is nearly the same as the right except the balancing\n"+

"weight is a withered hand grasping a crystal. Simply\n"+

"wield daggers to wield them both.\n");

set_type("knife"); 

set_class(18);

set_weight(2);

set_value(5000);

set_hit_func(this_object());

set_wield_func(this_object());

set_save_flag(1);

}



short(){

	if(this_object()->query_wielded()){

	return "Stiletto Dagger of "+GRN+"Poison"+NORM+" [right]  (wielded)\n"+

             "Stiletto Dagger of "+BOLD+"the Wraith"+NORM+" [left] (wielded)"; }

        else { return "Stiletto Dagger of "+GRN+"Poison"+NORM+" [right]\n"+

             "Stiletto Dagger of "+BOLD+"the Wraith"+NORM+" [left]"; }

             }



two_handed(){ return 1; } 



id(str) {

  if(previous_object()) {

  if(!test_my_wear(previous_object())) {

    return str == "dagger" || str == "daggers" ||

    str == "notarmor";

     }

   }

  return str == "dagger" || str == "daggers"; 

}



test_my_wear(ob) {

  string atype;

  if(!this_object()->query_wielded()) return 1;

  if(!USER) return;

  atype = ob->query_type();

  if(!atype) return;

  

    if(atype == "shield") return 0;

    

  else return 1; }



no_wield(){

 object shield;

 object ob;	

 ob = first_inventory(USER);

 shield = present("shield", environment());

 if(environment() && living(environment())) { 

  while(ob){

     string arm;

     int worn;

     arm = call_other(ob, "query_type");

     worn = call_other(ob, "query_worn");

 if(arm == "shield" && worn){

 	tell_object(USER,

 	"You cannot wield the daggers while using a shield.\n"); 

        return 1; 

        }

        ob = next_inventory(ob);

        }

  return 0;}

}









mixed

 wield(mixed str) {

if(no_wield()) return 1; 

if(objectp(str)){

  return 1;

   }

 return ::wield(str);

}

 	 	





weapon_hit(attacker){

int tot_dam;

int badbad;

object poison;



  if(random(100) < 25){

    tell_room(environment(USER),

    USER->query_name()+" leaps forward and drives the right dagger into"+

    " "+attacker->query_name()+"!\n", ({ USER }));

    tell_object(USER, 

    "You drive your right dagger into the chest of "+attacker->query_name()+"!\n"+

    "                    "+GRN+"* P O I S O N *"+NORM+"\n"+

    "   "+attacker->query_name()+" is injected with a terrible poison!\n");

    tell_object(attacker,

    "As "+USER->query_name()+" drives the tip of his right dagger into your body\n"+

    "you feel a burning sensation burn into your veins...\n");


/*  if(!present("poison2", attacker)){

    poison = clone_object("/players/feldegast/obj/poison2.c");

    poison->set_duration(random(3) + 1);

    poison->set_damage(8);    

    move_object(poison, attacker);

    }

*/
  
  tot_dam += random(3);

    }

  if(random(100) < 25){

    badbad = random(5) + 2;

    tell_room(environment(USER), 

    USER->query_name()+" drives "+USER->query_possessive()+" dagger into"+

    " "+attacker->query_name()+"!\n", ({ USER }));

    tell_object(USER, 

    "Your leap forward and slice with your left dagger...\n\n"+

    "          "+BOLD+"~ W R A I T H   S T R I K E ~"+NORM+"\n\n"+

    "   You grow in strength as your opponent weakens!\n");

    tell_object(attacker,

    "You fall back in a cold fear as you feel your life force being yanked from\n"+

    "your body!\n");

    USER->add_hit_point(badbad);

    attacker->heal_self(-(badbad));

    attacker->add_spell_point(badbad);

    tot_dam += random(5);    

    }

  return tot_dam;

  }

  

set_short(sh) { short_desc = sh; }



