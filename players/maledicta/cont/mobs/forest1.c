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
   coins = 900 + random(201);
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
set_short(YEL+"Brown Bear"+NORM);
set_long(
"  This is a very large brown bear. It seems at ease here\n"+
"in the forest as it searches for a small meal. It has long\n"+
"claws and a black snout with many sharp white teeth.\n");
set_name("bear");
set_alias("brown bear");
if(!random(2)){
set_gender("male");
}
else{
set_gender("female");
}
set_race("bear");
set_level(13);
set_hp(200);
set_ac(8);
set_wc(19);
set_al(0);
set_chat_chance(5);
  load_chat("A large brown bear ignores you as it searches for food.\n");
  load_chat("The bear yawns lazily.\n");
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
set_short(HIW+"Forest "+NORM+GRN+"Lizard"+NORM);	
set_long(
"  This is a huge scaled forest lizard.  It is nearly 8 feet in\n"+
"length, with its tail extending outward another three. It is\n"+
"covered in thick scales that protect it from predators. A long\n"+
"pink tongue flickers out from between rows of sharp teeth.\n"); 
set_name("lizard");
set_alias("forest lizard");
set_level(5);
set_race("lizard");
set_gender("creature");
set_hp(80);
set_ac(5);
set_wc(8);
set_al(0);
set_chat_chance(5);
  load_chat("The lizard lumbers along slowly.\n");
  load_chat("A forked pink tongue flickers out of the lizards mouth.\n");
}

mob4(){
set_short("a large hunting cat");
set_long(
"  This is a very large hunting cat. It is native to these woods and\n"+
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
set_short("Giant Eagle");	
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
set_short(GRN+"Forest "+HIW+"Giant"+NORM);	
set_long(
"  This is a huge man that stands over 12 feet tall. His\n"+
"body is covered in bear fur and he holds a large club in\n"+
"his hand. He doesn't seem very intelligent, but he looks\n"+
"extremely dangerous.\n"); 
set_name("giant");
set_alias("forest giant");
set_level(17);
set_hp(475);
set_gender("male");
set_race("giant");
set_ac(10);
set_wc(25);
set_al(0);
set_chat_chance(5);
  load_chat("The giant looks at you and then at its club.\n");
  load_chat("Giant says, 'Uh...why you in my forest?'\n");

set_chance(25);
set_spell_dam(5 + random(20));
set_spell_mess1(
"The giant slams its club down on it victim!\n");
set_spell_mess2(
"The giant slams you with it club!\n");
}

mob7(){
set_short("a wandering Elf");	
set_long(
"  This is a tall elf wanderer. He wears greenish brown\n"+
"clothing which seems to help him blend in with the\n"+
"forest surrounding. He has a wooden bow strapped to\n"+
"his back and carries a thin sword at his hip. His\n"+
"pointed ears are partially covered by a green head\n"+
"wrap which prominently displays an eagle in black.\n");
set_name("elf");
set_alias("wandering elf");
set_race("elf");
set_gender("male");
set_level(8);
set_hp(100);
set_ac(7);
set_wc(16);
set_al(600);
set_chat_chance(5);
  load_chat("The elf checks his surroundings carefully.\n");
  load_chat("Elf says, 'Greetings explorers.'\n");
set_chance(25);
set_spell_dam(20);
set_spell_mess1(
"The elf quickly fires an arrow at his opponent!\n");
set_spell_mess2(
"You feel a terrible pain as an arrow pierces your skin!\n");                     
}

mob8(){
set_short(YEL+"a wild boar"+NORM);	
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
