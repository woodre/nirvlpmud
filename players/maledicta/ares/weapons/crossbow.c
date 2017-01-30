/* This weapon is part of a concept to improve parties and
   give them a bit more power while doing so. Here it is:
   You have this wep and it's wc is random(4) + 2 if directly
   fighting someone alone, cause your bashing with it! Well,
   if you put someone in front to take the hits, then its wc
   raises to 17 + random(8). MUST BE IN THE BACKLINE! Also, 
   this weapon takes ammo which can take up weight and space
   as well as cost some cash. I hope you can agree that a 
   wep like this is both interesting and beneficial to giving
   ppl a reason to party. If you don't, well, you're an idiot. 
   */

inherit "obj/weapon.c";
#include "/players/maledicta/ansi.h"
#define BOLTS present("bolts", environment())
#define BQUIVER present("bolt_quiver", environment())
#define USER environment()
reset(arg){
  ::reset(arg);
  if (arg) return;
set_name("crossbow");
set_short("Crossbow");
set_long(
"  This is a large wooden crossbow. Its main body is\n"+
"made of a polished oak with a flexible bow extending\n"+
"outward from both sides. It requires bolts in order to\n"+
"fire.\n");
set_type("gun"); 
set_class(1);
set_weight(2);
set_value(1000);
set_hit_func(this_object());
set_message_hit(({
  HIR+"Destroyed"," with an expert shot",
  RED+"Blasted"," with a flying crossbow shot",
  "crippled"," with a well placed shot",
  "struck"," with deadly force",
  "struck"," with a crossbow shot",
  "hit","",
  "knicked"," with a crossbow shot"
  }));

}



weapon_hit(attacker){
 int dam;
 if(check_attackers()){
  tell_object(USER,
  "You swing the crossbow like a club as you fight your opponent hand-to-hand.\n");
  return random(4) + 2;
  }
 if(!BOLTS){
  tell_object(environment(), 
  "Your crossbow is out of bolts. You start bashing your opponent with it\n"+
  "like a club!\n");
  return random(4) + 2;
  }
 if(!BOLTS->query_ammo()){
  tell_object(environment(), 
  "Your crossbow is out of bolts. You start bashing your opponent with it\n"+
  "like a club!\n");
  return random(4) + 2;
  }
 dam = BOLTS->use_ammo(1);
 if(random(100) < 5){
  tell_object(USER,
  HIR+"["+NORM+BOLD+"C R I T I C A L"+NORM+HIR+"]"+NORM);
  dam += random(10);
  }
 return dam;
 }

check_attackers(){
object ob;
 ob = first_inventory(environment(USER));
  while(ob) {
    if(ob->query_attack() == USER){ return 1; }
     ob = next_inventory(ob);
    }
 return 0;
 }