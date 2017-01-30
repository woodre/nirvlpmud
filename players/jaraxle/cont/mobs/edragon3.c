#include "/players/jaraxle/ansi.h"

inherit "obj/monster.c";



int bdelay;

int shield_on;

reset(arg)  {

  ::reset(arg);

  if(arg) return;

bdelay = 0;

set_name("dragon");

set_alias("magus");

set_alt_name("cont_dragon");

set_race("dragon");

set_short(HIG+"Emerald "+NORM+GRN+"Dragon"+NORM+" (Magus)");

set_long(

" This is one of the Queen's personal assistants, and a\n"+

"very powerful wielder of magic. It is almost 100 feet\n"+

"in length, and covered in a thick crystalline green\n"+

"scale. Its head is covered in short clear spikes of\n"+

"crystal, with its glowing blue eyes looking out from\n"+

"under thick scaly brows. Its claws are long, and made\n"+

"from the same clear and greenish crystal, easily capable\n"+

"of rending any armor. Its wings are wide when spread\n"+

"easily carrying its massive body into the air. A fine\n"+

"yellowish mist flows from its nostrils and between its\n"+

"large teeth.\n");

set_level(20);

set_hp(600);

set_al(1000);

set_aggressive(0);

set_wc(35);

set_ac(24);

set_heart_beat(1);

set_chat_chance(10);

load_chat("The Emerald Dragon watches you with deep blue eyes.\n");

load_chat("The Magus Dragon's claws spread out with wide arcs of lightning dancing between them.\n");

load_chat("The Emerald Dragon lightly fans its wings, stirring up a dust cloud.\n");

}

hit_player(i){

if(shield_on && attacker_ob){

tell_object(attacker_ob,

"You feel a terrible "+HIY+"CHARGE"+NORM+" flow into your body as you hit the Dragon!\n");

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

heal_self(50);

}

if(random(100) > 95 && !shield_on){

tell_room(environment(),

"The Emerald Magus chants softly...\n"+

"        "+HIB+"BLUE ENERGY"+NORM+"\n"+

"surrounds the Dragons scaled body!\n");

shield_on = random(11) + 10;

}

if(shield_on == 1){

tell_room(environment(),

HIB+"The Blue Glow dies from around the dragons body..."+NORM+"\n");

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

            ob2->hit_player(random(30) + 20, "other|poison");

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

"The "+HIG+"Emerald "+NORM+GRN+"Dragon"+NORM+" reaches out and rakes with its gleaming claws!\n",

({ attacker_ob }));

tell_object(attacker_ob,

"You feel a terrible pain as the Dragon rakes you with its claws!\n");

attacker_ob->hit_player(random(20)+ 4, "other|poison");

}

else if(attacker_ob){

tell_object(attacker_ob,

"You barely dodge the gleaming claws of the Dragon!\n");

}

}

}

else if(rnum < 20){

if(alt_attacker_ob && random(100) < 30){

tell_object(alt_attacker_ob,

"You are "+HIR+"SLAMMED"+NORM+" by the long tail of the Dragon!\n");

alt_attacker_ob->hit_player(random(15)+ 3, "other|poison");

tell_room(environment(),

"The dragon's tail lashes out and strikes "+alt_attacker_ob->query_name()+"!\n");

  }

 } 

}



query_emerald_dragon(){ return 1; }
