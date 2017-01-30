/* Continent Mobs - Plain type 1 */

#include "/players/maledicta/ansi.h"
inherit "obj/monster.c";

object gold;
int ground;
int coins;
int get_coins;
reset(arg)  {

  ::reset(arg);
  if(arg) return;

set_alt_name("cont_mob");
switch(random(9)){
  case 8:
   mob3();
   break;
  case 7:
   mob4();
   break;
  case 6:
   mob5();
   break; 
  case 5:
   mob6();
   coins = 800 + random(200);
   break;
  case 4:
   mob1(); 
   break;
  case 3:
   mob2();
   break;
  case 2:
   mob7();
   coins = 750 + random(250);
   break;
  case 1:
   mob8();
   break;
  default:
   mob1();
   break;
  }
if(coins){  
gold = clone_object("obj/money");
gold->set_money(coins);
move_object(gold,this_object());
 }
}	

mob1(){
set_short(GRN+"Plains "+YEL+"Centaur"+NORM);
set_long(
"  This is one of the many Centaurs that roam the plains\n"+
"of Kelrisan.  His lower torso is in the shape of a medium\n"+
"sized horse, with the upper body of a man. He carries a\n"+
"large war hammer at the ready.\n");
set_name("centaur");
set_alias("plains centaur");
set_gender("male");
set_race("centaur");
set_level(15);
set_hp(200);
set_ac(14);
set_wc(20);
set_al(150);
set_chance(15);
set_spell_dam(10);
set_spell_mess1(
"The Centaur stomps his opponent into the ground!\n");
set_spell_mess2(
"The Centaur stomps you into the ground!\n");
}

mob2(){
set_short("wild dog");
set_long(
"   This is a large wild dog. Its fur is rough and multi\n"+
"colored. It seems hungry and you feel it might be best\n"+
"to just keep your distance.\n");
set_name("dog");
set_alias("wild dog");
set_race("dog");
set_gender("creature");
set_level(2);
set_hp(30);
set_ac(3);
set_wc(8);
set_al(0);
if(!random(3)){
set_aggressive(1);
}
set_chat_chance(5);
  load_chat("The dog eyes you with suspicion.\n");
set_a_chat_chance(15);
  load_a_chat("The dog snarls!\n");
  load_a_chat("The wild dog snaps its jaws and howls.\n");
set_chance(5);
set_spell_dam(5);
set_spell_mess1(
"The dog bites its opponent visciously!\n");
set_spell_mess2(
"You feel a sharp pain as the dog bites into you!\n");
}	

mob3(){
set_short("a "+RED+"giant"+NORM+" beetle");	
set_long(
"   This is a large hard shelled beetle.  It is colored a dark\n"+
"brown and has many long black legs.  A pair of sharp pointed\n"+
"mandibles extend out from beneath its shell.\n"); 
set_name("beetle");
set_alias("giant beetle");
set_level(7);
set_race("beetle");
set_gender("creature");
set_hp(105);
set_ac(8);
set_wc(9);
set_al(0);
set_chat_chance(5);
  load_chat("The beetle searches about for food.\n");
  load_chat("The beetle chops through the surrounding weeds with its mandibles.\n");
}

mob4(){
set_short("a large hunting cat");
set_long(
"  This is a very large hunting cat. It is native to the plains of\n"+
"Kelrisan and seems quite at home.  It is covered in a short brownish\n"+
"yellow fur that seems to ruffle as it senses possible prey. It has\n"+
"beautiful yellow eyes and a short snout.\n");
set_name("cat");
set_alias("hunting cat");
set_gender("creature");
set_level(7);
set_race("cat");
set_hp(95);
set_ac(6);
set_wc(14);
set_al(0);
set_chat_chance(5);
  load_chat("The hunting cat glances at you.\n");
  load_chat("The large cat licks a paw and lazily stretches.\n");

set_chance(25);
set_spell_dam(6);
set_spell_mess1(
"The huge cat leaps at its prey!\n");
set_spell_mess2(
"You feel a horrible pain as the hunting cat bites into your flesh!\n");
}

mob5(){
set_short("A giant eagle");	
set_long(
"  This is a huge eagle.  Its feathers are brown around the\n"+
"back and neck, with glistening white down on the chest and\n"+
"near its clawed feet. Its yellow eyes study you closely.\n"); 
set_name("eagle");
set_alias("giant eagle");
set_gender("creature");
set_level(6);
set_hp(75);
set_race("eagle");
set_ac(8);
set_wc(8);
set_al(0);
set_chat_chance(5);
  load_chat("The giant eagle spreads its wings and steps carefully.\n");
  load_chat("A giant eagle blinks as it studies you.\n");
set_chance(20);
set_spell_dam(10);
set_spell_mess1(
"The giant eagle descends at its prey, claws extended!\n");
set_spell_mess2(
"You feel a terrible pain as the eagle claws at you!\n");

}

mob6(){
set_short("an "+YEL+"Ogre"+NORM);	
set_long(
"   This is a very large brutish man. He stands about\n"+
"8 feet tall and carries a large hammer. His body is\n"+
"covered in animal skins and he has a large pouch around\n"+
"his shoulder.\n"); 
set_name("ogre");
set_alias("ogre");
set_level(15);
set_hp(250);
set_gender("male");
set_race("giant");
set_ac(7);
set_wc(22);
set_al(-500);

set_chance(25);
set_spell_dam(5 + random(15));
set_spell_mess1(
"The ogre swings his huge hammer at his opponent!\n");
set_spell_mess2(
"The ogre slams you in the chest with his huge hammer!\n");
}

mob7(){
set_short("a large snake");	
set_long(
"  This is a large burrowing snake. Its body is covered\n"+
"in shiny scales that blend well with the brown grass\n"+
"and dirt. It has a huge jaws with wickedly curved teeth.\n");
set_name("snake");
set_alias("snake");
set_race("snake");
set_gender("creature");
set_level(5);
set_hp(75);
set_ac(5);
set_wc(9);
set_al(0);
set_chance(12);
set_spell_dam(10);
set_spell_mess1(
"The snake clamps down on its opponent with its huge teeth!\n");
set_spell_mess2(
"The snake clamps down on you with its sharp teeth!\n");                     
}

mob8(){
set_short("a wild boar");	
set_long(
"  Standing before you is a wild boar. It seems very\n"+
"skittish, and yet you aren't sure which way it might\n"+
"charge if provoked.  It has large tusks that extend\n"+
"from a short pig snout. Its body is covered in a short\n"+
"wirey fur.\n");
set_name("boar");
set_alias("wild boar");
set_gender("creature");
set_race("boar");
set_level(4);
set_hp(60);
set_ac(3);
set_wc(10);
set_al(0);
if(!random(4)){
set_aggressive(1);
}
set_chat_chance(5);
  load_chat("The boar snorts as it paces back and forth.\n");
  load_chat("Wild boar squeels unhappily as you stare at it.\n");

}	
