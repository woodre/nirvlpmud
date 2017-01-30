#include "/players/jaraxle/ansi.h"

inherit "obj/monster.c";



object gold;

int coins;

int get_coins;

reset(arg)  {



  ::reset(arg);

  if(arg) return;



set_alt_name("cave_mob");

set_dead_ob(this_object());

switch(random(15)){

  case 13..14:

   mob3();   /* Human Guard */

   coins = 350 + random(50);

   break;

  case 11..12:

   mob4();   /*  Halfling Guard */

   coins = 200;

   break;

  case 10:

   mob5();   /* Giant Rat */

   coins = 100 + random(80);

   break; 

  case 9:

   mob6();  /* Giant Spider */

   coins = 320 + random(60);

   break;

  case 8:

   mob1();   /* Skeleton */

   coins = 300 + random(50);

   break;

  case 6..7:

   mob2();   /* gnome guard */

   coins = 250 + random(25);

   break;

  case 4..5:

   mob7();  /* Lizardman */

   coins = 420 + random(80);

   break;

  case 3:

   mob8();  /* Suit of armor */

   coins = 450;

   break;

  case 0..2:

   mob4();   /*  Halfling Guard */

   coins = 200;

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

set_short(YEL+"gnome guard"+NORM+"");

set_long(

"  This short gnome is covered in leather armor and he wields\n"+

"a large pickaxe.  He seems ready to protect this area and\n"+

"watches you carefully.\n");

set_name("guard");

set_race("gnome");

set_gender("creature");

set_alias("gnome");

set_level(6);

set_hp(75);

set_ac(6);

set_wc(12);

set_al(500);

}	



mob3(){

set_short("human guard");	

set_long(

"  This is a human wearing lightweight armor.  He seems\n"+

"ready to protect this area.  He wields a sword and peers\n"+

"at you from behind a light helm.\n");

set_name("guard");

set_alias("human");

set_gender("male");

set_race("human");

set_level(8);

set_hp(140);

set_ac(6);

set_wc(13);

set_al(450);

}



mob4(){

set_short(HIW+"halfling guard"+NORM);

set_long(

"  Before you stands a short halfing.  He is only 3.5 feet in\n"+

"height and wears leather armor.  He seems ready to fight if\n"+

"necessary.\n");

set_name("guard");

set_alias("halfling");

set_race("halfling");

set_gender("male");

set_level(5);

set_hp(65);

set_ac(6);

set_wc(10);

set_al(600);

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

"legs. Its eyes are a deep yellow and watch you carefully.\n"); 

set_name("man");

set_alias("lizardman");

set_gender("male");

set_race("lizardman");

set_level(10);

set_hp(150);

set_ac(9);

set_wc(15);

set_al(500);

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

