#include "/players/jaraxle/ansi.h"

inherit "obj/monster.c";



int bdelay;

int shield_on;

reset(arg)  {



  ::reset(arg);

  if(arg) return;

bdelay = 0;

set_name("dragon");

set_alias("queen");

set_alt_name("cont_dragon");

set_race("dragon");

set_short(BOLD+"Queen Delarintoris, "+HIG+"Emerald "+NORM+GRN+"Dragon"+NORM);

set_long(

" This is the Queen of the Emerald Dragons. She is well over 100 feet\n"+

"in length, her entire body covered in a thick translucent-green\n"+

"scale. Her eyes blaze with a deep blue energy, a sign of her strong\n"+

"magical abilities. Her wings are outstretched, catching the light off\n"+

"of their shining surface and reflecting it across the room.  The\n"+

"Queen's claws and teeth are incredibly sharp and long, capable of\n"+

"tearing apart nearly any creature in existence. She is perhaps the\n"+

"most intimidating sight you have ever seen.\n");

set_level(20);

set_hp(900);

set_al(1000);

set_aggressive(0);

set_wc(40);

set_ac(27);

set_heart_beat(1);

set_chat_chance(10);

load_chat("The Queen stares at you with a questioning look.\n");

load_chat("The Queen hisses,'Why have you come?'\n");

load_chat("The light reflects from green scale and bounces around the room.\n");

}



hit_player(i){

if(shield_on && attacker_ob){

tell_object(attacker_ob,

"You feel a terrible "+HIY+"CHARGE"+NORM+" flow into your body as you hit the Queen!\n");

attacker_ob->hit_player(i);

}

::hit_player(i);

}





heart_beat(){

int rnum;

object ob2;

object next;

::heart_beat();

rnum = random(100);

if(random(100) > 90 && query_hp() < query_mhp()){

tell_room(environment(),

"The Emerald Dragons eyes burn brightly with magical energy!\n"+

"Its wounds heal!\n");

heal_self(80);

}

if(random(100) > 95 && !shield_on){

tell_room(environment(),

"The "+BOLD+"Queen"+NORM+" chants softly...\n"+

"        "+HIB+"BLUE ENERGY"+NORM+"\n"+

"         surrounds her scaled body!\n");

shield_on = random(21) + 10;

}

if(shield_on == 1){

tell_room(environment(),

HIB+"The Blue Glow dies from around the Queen's body..."+NORM+"\n");

shield_on = 0;

}



if(shield_on) shield_on -= 1;



if(!bdelay && random(100) < 50 && attacker_ob){

tell_room(environment(),

"A large cloud of "+YEL+"Yellowish Gas"+NORM+" flows from the Dragons\n"+

"open mouth!\n\n"+

"          "+HIY+"Choking Fumes Envelope The Room!"+NORM+"\n\n\n");

ob2 = first_inventory(environment(this_object()));

  while(ob2) {

      next = next_inventory(ob2);

	  if(ob2->is_living() && !ob2->query_emerald_dragon()){

		  tell_room(environment(),

		  ob2->query_name()+" chokes on the Gas!\n");

              ob2->hit_player(random(40) + 20);

		  }

  ob2 = next;      

  }

 bdelay = 3;

 }

else if(attacker_ob){

bdelay -= 1;

if(bdelay < 0) bdelay = 0;

}



if(bdelay && attacker_ob){

if(rnum > 70){

if(random(100) < 70 && attacker_ob){

tell_room(environment(),

"The "+HIG+"Queen"+NORM+" reaches out and rakes with her gleaming claws!\n",

({ attacker_ob }));

tell_object(attacker_ob,

"You feel a terrible pain as the Queen rakes you with its claws!\n");

attacker_ob->hit_player(random(26));

}

else if(attacker_ob){

tell_object(attacker_ob,

"You barely dodge the gleaming claws of the Queen!\n");

  }

 }

}

else if(rnum < 20){

if(alt_attacker_ob && random(100) < 30){

tell_object(alt_attacker_ob,

"You are "+HIR+"SLAMMED"+NORM+" by the long tail of the Queen!\n");

alt_attacker_ob->hit_player(random(21));

tell_room(environment(),

"The Queen's tail lashes out and strikes "+alt_attacker_ob->query_name()+"!\n");

  }

 }

}



query_emerald_dragon(){ return 1; }