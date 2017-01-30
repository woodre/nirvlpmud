inherit "obj/weapon.c";

#include "/players/jaraxle/ansi.h"

#define BOLTS present("arrows", environment())

#define USER environment()

reset(arg){

  ::reset(arg);

  if (arg) return;

set_name("longbow");

set_short("LongBow");

set_long(

"  This is a finely crafted wooden bow. It is made of a polished\n"+

"smooth flexible wood.  A string is connected from the top to the\n"+

"bottom. It is a deadly weapon in the proper hands.\n");

set_type("bow"); 

set_class(1);

set_weight(1);

set_value(1500);

set_hit_func(this_object());

set_message_hit(({

  HIR+"Destroyed"," with an expert shot",

  RED+"Blasted"," with a flying bow shot",

  "crippled"," with a well placed shot",

  "struck"," with deadly force",

  "struck"," with a bow shot",

  "hit","",

  "knicked"," with a bow shot"

  }));



}







weapon_hit(attacker){

 int dam;



 if(check_attackers()){

  tell_object(USER,

  "You swing the bow like a club as you fight your opponent hand-to-hand.\n");

  return random(4) + 2;

  }

 if(!BOLTS){

  tell_object(environment(), 

  "Your bow is out of arrows. You start bashing your opponent with it\n"+

  "like a club!\n");

  return random(4) + 2;

  }

 if(!BOLTS->query_ammo()){

  tell_object(environment(), 

  "Your bow is out of arrows. You start bashing your opponent with it\n"+

  "like a club!\n");

  return random(4) + 2;

  }

 dam = BOLTS->use_ammo(1);

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

