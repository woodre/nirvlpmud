/* Continent Mobs - Forest type 1 */

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
   coins = 900 + random(100);
   break;
  case 4:
   mob1();
   break;
  case 3:
   mob2();
   break;
  case 2:
   mob7();
   coins = 300 + random(100);
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
set_short(HIW+"Cave Bear"+NORM);
set_long(
"  This is a huge gray cave bear. Its snout is lined with\n"+
"large sharp teeth, and its paws are black with long claws.\n"+
"The bears fur is thick and seems to blend well with the\n"+
"surrounding rocks.\n");
set_name("bear");
set_alias("cave bear");
if(!random(2)){
set_gender("male");
}
else{
set_gender("female");
}
set_race("bear");
set_level(16);
set_hp(420);
set_ac(9);
set_wc(25);
set_al(0);
set_chance(15);
set_spell_dam(15);
set_spell_mess1(
"The bear slaps its opponent with a huge paw!\n");
set_spell_mess2(
"The bear slams you with a huge paw!\n");
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
set_short(HIY+"Griffin"+NORM);	
set_long(
"  This is a large griffin. Its head and front paws are that\n"+
"of an eagle, while its hind quarters are that of a lion. It's\n"+
"back has wings attached behind the shoulder blades. It seems\n"+
"to be a quick and ferocious fighter and probably not something\n"+
"you would want to mess with.\n"); 
set_name("griffin");
set_level(13);
set_race("griffin");
set_gender("creature");
set_hp(195);
set_ac(9);
set_wc(18);
set_al(0);
set_chat_chance(5);
  load_chat("The griffin flexes its wings.\n");
  load_chat("The griffin cocks its head to the side and considers you.\n");
set_chance(5);
set_spell_dam(15);
set_spell_mess1(
"The griffin tears into its opponent visciously!\n");
set_spell_mess2(
"You feel a horrible pain as the griffin tears into you!\n");
}


mob4(){
set_short("a large hunting cat");
set_long(
"  This is a very large hunting cat. It is native to these hills and\n"+
"seems quite at home.  It is covered in a short brownish yellow fur\n"+
"that seems to ruffle as it senses possible prey. It has beautiful\n"+
"yellow eyes and a short snout.\n");
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
set_short(HIW+"Hill Giant"+NORM);	
set_long(
"  This is a huge man that stands over 12 feet tall. His\n"+
"body is covered in bear fur and he holds a large club in\n"+
"his hand. He doesn't seem very intelligent, but he looks\n"+
"extremely dangerous.\n"); 
set_name("giant");
set_alias("hill giant");
set_level(17);
set_hp(425);
set_gender("male");
set_race("giant");
set_ac(7);
set_wc(29);
set_al(0);
set_chat_chance(5);
  load_chat("The giant looks at you and then at its club.\n");
  
set_chance(25);
set_spell_dam(5 + random(20));
set_spell_mess1(
"The giant slams its club down on it victim!\n");
set_spell_mess2(
"The giant slams you with it club!\n");
}

mob7(){
set_short("a hill dwarf");	
set_long(
"   This is a wandering hill dwarf. His short form is only\n"+
"4 1/2 feet tall, yet he is almost as wide as he is tall.\n"+
"He has a long white beard that almost touches his knees,\n"+
"and big bushy eyebrows. He wears leather armor mixed with\n"+
"steel plates. A large Battle axe is held easily in his\n"+
"hand.\n");
set_name("dwarf");
set_alias("hill dwarf");
set_race("dwarf");
set_gender("male");
set_level(8);
set_hp(120);
set_ac(7);
set_wc(18);
set_al(200);
set_chat_chance(5);
  load_chat("The dwarf squints and looks at you carefully.\n");
  load_chat("Dwarf says, 'Aye, who ya be?'\n");
set_chance(25);
set_spell_dam(20);
set_spell_mess1(
"The dwarf swings his mighty axe!\n");
set_spell_mess2(
"You feel a terrible pain as the Dwarves axe bites deep into your flesh!\n");                     
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
