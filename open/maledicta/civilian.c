#include "/players/maledicta/ansi.h"
inherit "obj/monster.c";

int coins;
int blade_num;
int wander,wander_time;
object gold,blades;
reset(arg)  {

  ::reset(arg);
  if(arg) return;


set_alt_name("civilian");
set_aggressive(0);
set_wander(0, 20);
set_heart_beat(2);
blade_num = 0;
switch(random(20)+1){
  case 20:
    civilian1();
    coins = random(100) + 200;
   break;
  case 18..19:
    civilian2();
    coins = random(150) + 200;
   break;
  case 16..17:
    civilian3();
    coins = random(150) + 200;
   break;
  case 13..15:
    civilian4();
    coins = random(150) + 200;
   break;
  case 12:
    civilian5();
    coins = random(500) + 1000;
   break;
  case 11:
    civilian6();
    coins = random(400) + 600;
   break;
  case 10:
    civilian7();
    coins = random(500) + 750;
    blade_num = 1;
   break;
  case 8..9:
    civilian8();
    coins = 0;
   break;
  case 7:
    civilian9();
    coins = 0;
   break;
  case 6:
    civilian10();
    coins = random(200) + 300;
   break;
  case 5:
    civilian11();
    coins = 0;
   break;
  case 3..4:
    civilian12();
    coins = 0;
   break;
  case 1..2:
    civilian13();
    coins = 0;
   break;
  default:
    civilian1();
    coins = random(150) + 200;
   break;        
  }
if(coins){  
gold = clone_object("obj/money");
gold->set_money(coins);
move_object(gold,this_object());
  }
if(blade_num){
blades = clone_object("players/maledicta/town/weapons/wblade.c");
move_object(blades, this_object());
   }
}	


civilian1(){
set_short("a short plynumth ["+HIB+"civilian"+NORM+"]");
set_long(
" Looking at this small creature, you see it stands only 4 feet\n"+
"tall and is covered with short black hair. Its eyes are deep\n"+
"blue and show signs of great intelligence. It is wearing a clothe\n"+
"jacket and a small pouch on its left side. The Plynumth seems\n"+
"to wobble a little as it walks.\n");
set_race("plynumth");
set_level(5);
set_name("plynumth");
set_hp(80);
set_ac(6);
set_wc(14);
set_al(150);
set_chat_chance(5);
  load_chat("The plynumth looks about, studying its surroundings\n");
  load_chat("Plynumth civilian says: Dor cais tyui for?\n");
set_a_chat_chance(15);
  load_a_chat("Plynumth snarls and claws at his opponent!\n");
  load_a_chat("Plynumth civilian looks around for escape.\n");
}

civilian2(){
set_short("a young human male ["+HIB+"civilian"+NORM+"]");
set_long(
"  The first to inhabit Derellia IV, this human seems to be\n"+
"well to do and quite happy. He is dressed in fine clothes\n"+
"and seems to walk with purpose.\n");
set_level(5);
set_race("human");
set_alias("male");
set_name("human");
set_hp(75);
set_ac(5);
set_wc(9);
set_al(200);
set_chat_chance(5);
  load_chat("The human nods to a passing civilian.\n");
  load_chat("Human says: Very nice day, just lovely.\n");
set_a_chat_chance(15);
  load_a_chat("The human male yells: GUARDS!!!\n");
  load_a_chat("The human civilian attempts to dodge his opponents attack!\n");  
}

civilian3(){
set_short("a young human female ["+HIB+"civilian"+NORM+"]");
set_long(
"  One of the original human inhabitants of Derellia IV. Her\n"+
"clothes are of fine make and show that she is somewhat wealthy\n"+
"although not over-doing it as so many cultures in the galaxy\n"+
"often do. She seems happy and vibrant.\n");
set_level(5);
set_race("human");
set_alias("female");
set_name("human");
set_hp(70);
set_ac(5);
set_wc(9);
set_al(200);
set_chat_chance(5);
   load_chat("The human female smiles at a passing civilian.\n");
   load_chat("The human girl waves to her neighbor.\n");
set_a_chat_chance(15);
   load_a_chat("The girl yells: GUARDS!!! HELP ME!!!\n");
   load_a_chat("The girl attempts to dodge her opponents attack!\n");
}

civilian4(){
set_short("An older human ["+HIB+"civilian"+NORM+"]");      
set_long(
"  This older human is of middle-age and dressed in nice clothing\n"+
"suiting that of someone who is well-to-do. They look as if they\n"+
"are very happy and content.\n");
set_level(5);
set_race("human");
set_name("human");
set_hp(85);
set_ac(8);
set_wc(12);
set_al(200);
set_chat_chance(5);
   load_chat("The older human walks through the crowd, a smile on their face.\n");
   load_chat("Human bows their head to a passer-by and says hello.\n");
set_a_chat_chance(15);
   load_a_chat("The older human yells: GUARDS!!!\n");
}      

civilian5(){
set_short("a b'yeklik tradesman ["+HIB+"civilian"+NORM+"]");
set_long(
"  This four-armed trader is covered with small shining scales, which\n"+
"resemble small gold coins. Its eyes are greenish, and shot through\n"+
"with yellow streaks. Its height is around 7ft, and most of its length\n"+
"is made up of its extremely long legs. It has a short stubby tail\n"+
"which nearly touches the ground.\n");
set_name("tradesman");
set_level(13);
set_race("b'yeklik");
set_hp(180);
set_ac(10);
set_wc(16);
set_al(0);
set_chat_chance(5);
   load_chat("The tradesman says: I canna getta chew anyting.\n");
   load_chat("The tradesman shines some coins with a couple of its arms.\n");
   load_chat("The B'yeklik looks around with interest.\n");
set_a_chat_chance(15);
   load_a_chat("The tradesman dodges to the left!\n");
   load_a_chat("B'yeklik snarls in defiance.\n");
set_chance(15);
set_spell_dam(random(15)+10);
set_spell_mess1(
  "The tradesman's arms swing about with lightning speed attacking his opponent!\n");
set_spell_mess2(
  "The tradesman's arms swing at you with lightning speed!\n");
  }
civilian6(){
set_short("a blue-skinned devron ["+HIB+"civilian"+NORM+"]");
set_long(
" This medium height alien is nearly human in appearance except\n"+
"for its blue-tinted skin. It is wearing nice clothing and seems\n"+
"to be happy as it makes its way through the crowd. Its hair is\n"+
"extremely long and braided with some type of metal discs.\n");
set_level(12);
set_race("devron");
set_name("devron");
set_hp(150);
set_ac(9);
set_wc(16);
set_al(100);
set_chat_chance(5);
  load_chat("The devron says: A beautiful town this is, very nice.\n");
  load_chat("The devron civilian smiles to a couple walking by.\n");
set_a_chat_chance(15);
  load_a_chat("Devron dodges its opponents attack!\n");
  load_a_chat("The devron lunges at its opponent!\n");
set_chance(15);
set_spell_dam(random(10)+5);
set_spell_mess1(
"The devron twirls its long braided hair about, sharp plates whipping at its opponent!\n");
set_spell_mess2(
"The devron's sharp braided hair spins at you, sharp plates cutting into you!\n");
}

civilian7(){

set_short("an ivory tusked doona trader ["+HIB+"civilian"+NORM+"]");
set_long(
" This tall alien stands nearly 8 1/2 feet tall, its long robes concealing\n"+
"most of its body. From its narrow long face extends several long thin ivory\n"+
"tusks, each polished and well taken care of. A large pouch can be seen on\n"+
"its left hip. It walks with a long stride.\n");
set_level(15);
set_race("doona");
set_alias("trader");
set_name("doona");
set_hp(250);
set_wc(20);
set_ac(10);
set_al(0);
set_chat_chance(5);
   load_chat("The doona trader looks with a careful eye on the crowd.\n");
   load_chat("The long robes of the trader swish about as it moves.\n");
set_chance(20);
set_spell_dam(random(20)+15);
set_spell_mess1(
"The Doona trader lashes out quickly with long wrist blades!\n");
set_spell_mess2(
"The Doona trader lashes out at you with its long wrist blades!\n");

}
civilian8(){
string droid_type;
switch(random(10)+1){
case 10:
droid_type = "C1P4";
set_name("c1p4");  
break;
case 9:
droid_type = "T4C2";
set_name("t4c2");  
break;
case 8:
droid_type = "C6P1";
set_name("c6p1");  
break;
case 7:
droid_type = "T1P5";
set_name("t1p5");  
break;
case 6:
droid_type = "C9D3";
set_name("c9d3");  
break;
case 5:
droid_type = "E7C5";
set_name("e7c5");  
break;
case 4:
droid_type = "B8D2";
set_name("b8d2");  
break;
case 3:
droid_type = "C3T1";
set_name("c3t1");  
break;
case 2:
droid_type = "S2M5";
set_name("s2m5");  
break;
case 1:
droid_type = "T3S9";
set_name("t3s9");  
break;
default:
droid_type = "C1P4";
set_name("c1p4");  
break;
}
set_short("a protocol droid ["+HIY+""+droid_type+""+NORM+"]");
set_long(
"  A silvery protocol droid. Its polished casing shines in the\n"+
"light of the town, reflecting brightly. It stands nearly 6 feet\n"+
"tall, and walks with a halting step. It seems to be out to\n"+
"perform duties for its master.\n");
set_level(3);
set_race("droid");
set_alias("droid");
set_dead_ob(this_object());
set_hp(50);
set_wc(7);
set_ac(4);
set_al(0);
set_chat_chance(5);
   load_chat("The protocol droid says: I am "+droid_type+", human-cyborg relations.\n");
   load_chat("Droid walks through the crowd with some caution.\n");
   load_chat("The protocol droid tries to get someone's attention and fails.\n");
   load_chat("The protocol droid walks by you and bows slightly.\n");
set_a_chat_chance(15);
   load_a_chat("C1P4 says: OH...OH MY!\n");
   load_a_chat("The protocol droid says: PLEEEEEEEEASE DON'T DEACTIVATE ME!\n");
}           

civilian9(){
set_short("a short power droid ["+BOLD+""+BLK+"P5A1"+NORM+"]");
set_long(
"  This is a short two-limbed power droid. Its black casing is dull\n"+
"and unremarkable, and fully covers its blocky shape. A pair of\n"+
"sensor eyes glow red from its front, and a short antenna extends\n"+
"from its side and points into the air. It walks clumsily on its\n"+
"wide legs. Its primary purpose is to carry energy cells and to\n"+
"serve as a walking power base.\n");
set_level(3);
set_race("droid");
set_dead_ob(this_object());
set_name("droid");
set_alias("p5a1");
set_hp(40);
set_ac(3);
set_wc(6);
set_al(0);
set_chat_chance(5);
   load_chat("The power droid hums and beeps as it walks along.\n");
   load_chat("The power droid goes: Unhk Uhnk, Mmmmmm\n");
}

civilian10(){
set_short("a flying grenken ["+HIB+"civilian"+NORM+"]");
set_long(
"  This small creature is covered with a shining exoskeleton, its\n"+
"buglike appearance and long nearly transparent wings showing its\n"+
"clearly insect origin. The alien has a small shoulder pack strapped\n"+
"around its torso, which dangles below it as it glides along on\n"+
"its humming wings. It seems to be intent on its surroundings.\n");
set_name("grenken");
set_level(8);
set_race("grenken");
set_hp(120);
set_ac(5);
set_wc(10);
set_al(100);
set_chat_chance(5);
   load_chat("The flying grenken buzzes over the crowd.\n");
   load_chat("The grenken says: Excuuuuse.....Excuuuuse.\n");
set_a_chat_chance(15);
   load_a_chat("The grenken buzzes away attempting to dodge its opponents attack!\n");
   load_a_chat("The flying grenken swings wildly with its long spindly arms!\n");
}

civilian11(){
set_short("an armored pack wern ["+HIC+"animal"+NORM+"]");
set_long(
"  This is a four-legged pack animal common to these parts. Its\n"+
"armored hide gives it considerable protection against attacks,\n"+
"and its large rounded teeth provide decent attack capability.\n"+
"It seems to be a well muscled and capable animal for its duties.\n");
set_name("wern");
set_race("wern");
set_alias("animal");
set_level(16);
set_hp(400);
set_wc(15);
set_ac(22);
set_al(0);
set_chat_chance(5);
   load_chat("The Wern sniffs the air.\n");
   load_chat("The Wern chews on a nearby tree limb.\n");
   load_chat("The Wern goes: MERRRRR.....\n");
set_a_chat_chance(15);
   load_a_chat("The Wern charges at its opponent!\n");
}

civilian12(){
set_short("a motorized air purifier ["+HIY+"droid"+NORM+"]");
set_long(
"  This is a short four-wheeled motor driven purifier. Its job\n"+
"is to take the polution from the air of the city and provide\n"+
"the population with a pleasant non-stagnated breath. It is\n"+
"driving along very slowly and makes a light humming sound.\n");
set_name("purifier");
set_race("droid");
set_alias("droid");
set_dead_ob(this_object());
set_level(2);
set_hp(35);
set_wc(5);
set_ac(2);
set_al(0);
set_chat_chance(5);
   load_chat("The purifier buzzes along as it does its task.\n");
}

civilian13(){
set_short("a mechanized street cleaner ["+HIY+"droid"+NORM+"]");
set_long(
"  This is a tall multi-limbed droid used for keeping the streets\n"+
"of Derellia IV clean.  Its numerous limbs are tipped with scrubbing\n"+
"brushes and water jet hoses. It seems very capable in its assigned\n"+
"task.\n");
set_name("droid");
set_race("droid");
set_alias("cleaner");
set_random_pick(100);
set_dead_ob(this_object());
set_level(2);
set_hp(45);
set_wc(7);
set_ac(4);
set_al(0);
set_chat_chance(5);
   load_chat("The cleaner droid whirls about cleaning everything in sight.\n");
   load_chat("The street cleaner picks up a stray piece of trash.\n");
}

void set_wander(int chance, int time) {  
   wander = time;  
   set_heart_beat(1); 
}  

heart_beat(){
   ::heart_beat();
   if(wander && !query_attack()) {  
      if(wander_time++ > wander && !random(4)) {
        random_move();  
      } 
    }
}    	
	
monster_died() {
  object corpse;
  corpse = present("corpse", environment()); 
  tell_room(environment(this_object()),
  "As the droid is torn apart, it falls to the ground into useless scrap.\n");	
  if(corpse)
    destruct(corpse);
return 1; }

	   	      	     	   	