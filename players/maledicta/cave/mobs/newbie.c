#include "/players/maledicta/ansi.h"
inherit "obj/monster.c";

object gold;
int coins;
int get_coins;
reset(arg)  {

  ::reset(arg);
  if(arg) return;

set_alt_name("cave_mob");
set_dead_ob(this_object());
switch(random(11)){
  case 10:
   mob3();
   coins = 200 + random(50);
   break;
  case 9:
   mob4();
   coins = 200;
   break;
  case 8:
   mob5();
   coins = 100 + random(80);
   break; 
  case 7:
   mob6();
   coins = 320 + random(60);
   break;
  case 4..6:
   mob1();
   coins = 300 + random(50);
   break;
  case 2..3:
   mob2();
   coins = 250 + random(25);
   break;
  case 1:
   mob7();
   coins = 420 + random(80);
   break;
  case 0:
   mob8();
   coins = 450;
   break;
  default:
   mob1();
   coins = 100;
   break;
  }
if(get_coins){  
gold = clone_object("obj/money");
gold->set_money(coins);
move_object(gold,this_object());
 }
}	


                             
mob1(){
set_short(HIW+"skeleton"+NORM+"");
set_long(
"  This undead creature is about 6 feet tall, its white bones clanking\n"+
"noisily off of each other as it moves. Its claws are razor sharp and\n"+
"easily capable of rending flesh. Its eyes seem to glow with a bluish\n"+
"inner light.\n");
set_name("skeleton");
set_alias("undead");
set_gender("creature");
set_race("undead");
set_level(7);
set_hp(100);
set_ac(5);
set_wc(13);
set_al(0);
}

mob2(){
set_short(YEL+"goblin guard"+NORM+"");
set_long(
"  This short green skinned creature looks at you with yellow\n"+
"crazed eyes. Its body is covered with tight wirey muscles, and\n"+
"it holds a wooden club in its hand. It seems ready to fight.\n");
set_name("goblin");
set_race("goblin");
set_gender("creature");
set_alias("guard");
set_level(6);
set_hp(75);
set_ac(6);
set_wc(12);
set_al(-400);
}	

mob3(){
set_short(YEL+"orc guard"+NORM+"");	
set_long(
" This is a massive pig-faced warrior. His body is fat, yet muscled\n"+
"to the point of being very dangerous. He wields a huge axe in his\n"+
"right hand. His body is covered in matted fur from dead animals.\n");
set_name("orc");
set_alias("guard");
set_gender("male");
set_race("orc");
set_level(8);
set_hp(140);
set_ac(6);
set_wc(13);
set_al(-450);
}

mob4(){
set_short(GRN+"kobold guard"+NORM+"");
set_long(
"  This very short creature holds a short sword in its clawed right hand\n"+
"and carries a small wooden shield in it left. Its body is covered in a\n"+
"thick green scaly hide, and its face ends in a muzzle full of small sharp\n"+
"teeth.\n");
set_name("kobold");
set_alias("guard");
set_race("kobold");
set_gender("male");
set_level(5);
set_hp(65);
set_ac(6);
set_wc(10);
set_al(-400);
}

mob5(){
set_short(HIW+"giant rat"+NORM+"");	
set_long(
"  This huge rodent is covered with a grungy white fur. Its four legs\n"+
"end in long claws, and its long feral muzzle is tipped with huge white\n"+
"incisors capable of rending flesh easily.\n"); 
set_name("rat");
set_alias("rat");
set_race("rat");
set_gender("creature");
set_level(4);
set_hp(50);
set_ac(4);
set_wc(10);
set_al(0);
}

mob6(){
set_short(HIR+"giant"+BOLD+BLK+" spider"+NORM+"");	
set_long(
"  This is a huge mutated arachnid. Its eight legs are covered in\n"+
"fur, and its red glistening eyes stare at you menacingly. It has\n"+
"twin pincers that can easily crunch steel within their grasp.\n"); 
set_name("spider");
set_alias("arachnid");
set_race("arachnid");
set_gender("creature");
set_level(8);
set_hp(130);
set_ac(6);
set_wc(13);
set_al(0);
}

mob7(){
set_short(HIG+"lizardman"+NORM+"");	
set_long(
"  This tall warrior is slouched at the waist presenting a feel that\n"+
"he is actually shorter. His entire form is covered in green wet scales\n"+
"that appear ready to absorb any decent attack. A large spear is carried\n"+
"in his right hand, and fur skins are strapped onto its chest and upper\n"+
"legs. Its eyes are a deep yellow that stare at you with hatred.\n"); 
set_name("man");
set_alias("lizardman");
set_gender("male");
set_race("lizardman");
set_level(10);
set_hp(150);
set_ac(9);
set_wc(15);
set_al(-500);
}

mob8(){
set_short(HIW+"suit of armor ["+NORM+"animated"+HIW+"]"+NORM+"");	
set_long(
"  This large heavy suit of armor has been enchanted to protect this\n"+
"area. It carries a large sword and moves with grace.\n"); 
set_name("armor");
set_alias("suit");
set_race("creation");
set_gender("creature");
set_level(10);
set_hp(150);
set_ac(10);
set_wc(11);
set_al(0);
}
	
monster_died() {
	
  tell_room(environment(this_object()),
  "As the "+query_name()+" dies you see a large pile of coins lying on the\n"+
  "ground near it. Obviously that is what it was protecting.\n");	
gold = clone_object("obj/money");
gold->set_money(coins);
move_object(gold,environment(this_object()));
return 1; }
