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
   coins = 400 + random(125);
   break;
  case 9:
   mob4();
   coins = 750 + random(200);
   break;
  case 8:
   mob5();
   coins = 800 + random(200);
   break; 
  case 7:
   mob6();
   coins = 740 + random(150);
   break;
  case 4..6:
   mob1();
   coins = 850 + random(400);
   break;
  case 2..3:
   mob2();
   coins = 500 + random(350);
   break;
  case 1:
   mob7();
   coins = 800 + random(150);
   break;
  case 0:
   mob8();
   coins = 650 + random(250);
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
set_short(BOLD+BLK+"wraith"+NORM+"");
set_long(
"  This floating ghostly creature is as dark as night. Its form is in the\n"+
"shape of an armored knight, although it holds no true substance. Its red\n"+
"eyes blaze in fury at its misfortune of being kept from peace.\n");
set_name("wraith");
set_alias("undead");
set_level(16);
set_race("spirit");
set_gender("creature");
set_hp(250);
set_ac(10);
set_wc(19);
set_al(-1000);
set_chat_chance(5);
  load_chat("The wraith glides about the room.\n");
  load_chat("The wraiths red eyes bore into you.\n");
set_a_chat_chance(15);
  load_a_chat("Wraith dodges your attack!\n");
  load_a_chat("The wraith reaches out for your soul!\n");
  load_a_chat("Wraith's eyes flare in fury!\n");

set_chance(10);
set_spell_dam(random(15));

set_spell_mess1(
"The wraith lashes out at its opponent with hands that carry the chill of death!\n");
set_spell_mess2(
"You feel the wraith grasp you and begin to take your life force!\n");
}

mob2(){
set_short(YEL+"gnoll "+HIW+"guard"+NORM+"");
set_long(
"  This large creature stands around 7 feet tall, its head is that\n"+
"of a jackal, and its body a human. It is covered in a short yellow\n"+
"fur that is spotted with dark circles. The gnoll is wearing a dark\n"+
"leather armor which covers the vital parts of its body. A huge\n"+
"spiked club sits readily in its right hand.\n");
set_name("gnoll");
set_alias("guard");
set_race("gnoll");
set_gender("male");
set_level(13);
set_hp(190);
set_ac(7);
set_wc(17);
set_al(-400);
set_chat_chance(5);
  load_chat("The gnoll guard watches you carefully.\n");
  load_chat("The gnoll cackles with a high growling sound.\n");
set_a_chat_chance(15);
  load_a_chat("Gnoll bashes you with his club!\n");
  load_a_chat("The gnoll guard jumps out of your reach!\n");
set_chance(10);
set_spell_dam(10);
set_spell_mess1(
"The Gnoll Guard "+HIR+"SLAMS"+NORM+" his opponent to the ground!\n");
set_spell_mess2(
"The Gnoll Guard "+HIR+"SLAMS"+NORM+" you in the face with his club!\n");

}	

mob3(){
set_short(HIY+"griffin"+NORM+"");	
set_long(
"  This massive beast has the body of a lion and the head and wings of\n"+
"an eagle. Its muscled form is covered with a golden fur and brown\n"+
"feathers. Its huge wingspan easily encompasses the room, and its large\n"+
"beak looks ready to tear away flesh at any time.\n"); 
set_name("griffin");
set_alias("griffin");
set_level(15);
set_gender("creature");
set_race("griffin");
set_hp(220);
set_ac(8);
set_wc(22);
set_al(0);
set_chat_chance(5);
  load_chat("The griffin hisses loudly at you.\n");
  load_chat("Griffin beats its wings, raising dust into the room.\n");
set_a_chat_chance(15);
  load_a_chat("Griffin hits you with its mighty wing!\n");
  load_a_chat("Griffin hits you hard.\n");
  load_a_chat("The griffin raises up on its hind quarters and lashes out at you!\n");
}

mob4(){
set_short(GRN+"flying "+RED+"serpent"+NORM+"");
set_long(
"  This huge snake is around 25 feet long, its wide form covered in\n"+
"tough scales capable of resisting damage. Its head is feathered,\n"+
"each one a dark redish brown in color. Huge wings sprout from the\n"+
"beasts side, keeping it aloft and hovering easily over the ground.\n");
set_name("serpent");
set_alias("serpent");
set_level(14);
set_race("serpent");
set_hp(185);
set_ac(9);
set_wc(19);
set_al(0);
}

mob5(){
set_short(GRN+"troll"+NORM+"");	
set_long(
"  This huge gangly creature is covered in a warty tough green\n"+
"skin. Huge black hair covers it in patches, as well as from its\n"+
"head in long tangled streams. Its face is covered in warts as\n"+
"well, its long nose angled oddly downward over its mouth which\n"+
"is filled with jagged yellowed teeth.\n"); 
set_name("troll");
set_heal(4, 3);
set_alias("troll");
set_gender("creature");
set_race("troll");
set_level(17);
set_hp(220);
set_ac(7);
set_wc(23);
set_al(-500);
}

mob6(){
set_short(RED+"minotaur"+NORM+"");	
set_long(
"  Standing at seven feet tall, this creature has the head of a\n"+
"bull and the body of a man. A thick red fur flows down its back\n"+
"from its head, and also down its chest. Its huge muscled body\n"+
"easily carries a large battle axe.\n"); 
set_name("minotaur");
set_alias("minotaur");
set_race("minotaur");
set_gender("male");
set_level(16);
set_hp(240);
set_ac(10);
set_wc(19);
set_al(-500);
set_chat_chance(5);
  load_chat("The minotaur huffs loudly.\n");
  load_chat("Minotaurs eyes stare at you angrily.\n");

set_chance(10);
set_spell_dam(5 + random(20));
set_spell_mess1(
"The Minotaur charges his opponent!\n");
set_spell_mess2(
"You feel a horrible pain as the Minotaur "+HIW+"SLAMS"+NORM+" into you with its mighty horns!\n");
}

mob7(){
set_short(YEL+"ogre"+NORM+"");	
set_long(
"  Standing at nearly nine feet tall, this huge muscled creature\n"+
"stands ready to bash any pitiful victim into oblivion. A huge\n"+
"club rests easily in its right hand, its entire length spiked\n"+
"with steel. Huge bear furs are wrapped about its form, their\n"+
"stinking hair matted with blood and old food.\n");
set_name("ogre");
set_alias("ogre");
set_race("ogre");
set_gender("male");
set_level(16);
set_hp(215);
set_ac(10);
set_wc(21);
set_al(-600);
set_chat_chance(5);
  load_chat("The huge ogre sneers at you.\n");
  load_chat("Ogre licks his lips in anticipation of lunch.\n");
set_a_chat_chance(15);
  load_a_chat("Ogre slams you with his huge fist!\n");
  load_a_chat("Ogre kicks at you!\n");
}

mob8(){
set_short(HIW+"demonmane"+NORM+"");	
set_long(
"  A short blackskinned demonling. This creature has long muscled\n"+
"arms which end in dangerous claws. Its red eyes stare at you with\n"+
"a cold fury.\n"); 
set_name("demonmane");
set_alias("demon");
set_race("demon");
set_gender("creature");
set_level(14);
set_hp(190);
set_ac(5);
set_wc(18);
set_al(-1000);
set_chat_chance(5);
  load_chat("The small demon flies about the room in a back and forth pattern.\n");
  load_chat("The demons red eyes watch you carefully.\n");
set_chance(15);
set_spell_dam(random(25));

set_spell_mess1(
"The demonmanes hands glow white hot as he slaps his opponent!\n");
set_spell_mess2(
"You feel a "+HIY+"SEARING"+NORM+" pain as the demonmane reaches out and grasps you!\n");

}
	
monster_died() {
	
  tell_room(environment(this_object()),
  "As the "+query_name()+" dies you see a large pile of coins lying on the\n"+
  "ground near it. Obviously that is what it was protecting.\n");	
gold = clone_object("obj/money");
gold->set_money(coins);
move_object(gold,environment(this_object()));
return 1; }
