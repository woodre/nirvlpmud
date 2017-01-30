#include "/players/francesco/univ/ansi.h"
#define USER environment(this_object())

inherit "obj/weapon";

reset(arg){
  ::reset(arg);
  if (arg) return;
  set_name("testweapon");
  set_alias("polearm");
  set_alt_name("weapon");
  set_long("Test weapon with higher wc which makes the player to be unable to\n"+
           "wear any 'armor' type piece of armor.\n");
  set_type("polearm");
  set_class(18);  
  set_weight(1);
  set_value(5500);
  set_hit_func(this_object());
}

short(){
        if(this_object()->query_wielded()){
        return "Testweapon wielded in right hand.\n"+
               "Testweapon wielded in left hand"; }
        else { return "Testweapon"; }        
}  

two_handed(){ return 1; } 

id(str)    { return str=="testweapon"; }

init() {
  ::init();
   add_action("wield_weapon","wield");
}

weapon_hit(attacker){ 
if(!random(4)){
    if(this_player()->query_guild()=="cyberninja") return 7;
    else return 9;}
return 1;}

no_wield(){
 object shield;
 object ob;     
 if(!USER) return;
 ob = first_inventory(USER);
 shield = present("armor", environment());
 if(environment() && living(environment())) { 
  while(ob){
     string arm;
     int worn;
     arm = call_other(ob, "query_type");
     worn = call_other(ob, "query_worn");
 if(arm == "armor" && worn){
        tell_object(USER,
        "You cannot wield the testweapon while using a shield.\n"); 
        return 1; 
        }
        ob = next_inventory(ob);
        }
  return 0;}
}

wield_weapon(mixed str) {
  if(no_wield() || !USER) return 1;
  if(objectp(str)){
  return 1;
   }
 return ::wield(str);
}

test_my_wear(ob) {
  string atype;
  if(!this_object()->query_wielded()) return 1;
  if(!USER) return;
  atype = ob->query_type();
  if(!atype) return;
  
    if(atype == "armor") return 0;
    
  else return 1; }
