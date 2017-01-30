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
set_short(BOLD+BLK+"guardian spirit"+NORM+"");
set_long(
"  This floating being seems to be made of some sort of bright\n"+
"mist.  It watches you carefully with two beads of white light.\n");
set_name("spirit");
set_alias("guardian spirit");
set_level(16);
set_race("spirit");
set_gender("creature");
set_hp(250);
set_ac(10);
set_wc(19);
set_al(1000);
set_chat_chance(5);
  load_chat("The spirit glides about the room.\n");
  load_chat("The spirit's white eyes watch you.\n");

set_chance(10);
set_spell_dam(random(15));

set_spell_mess1(
"The spirit lashes out at its opponent with flaming hands!\n");
set_spell_mess2(
"You feel the spirit grasp you and begin to burn the life from you!\n");
}

mob2(){
set_short(YEL+"dwarven "+HIW+"guard"+NORM+"");
set_long(
"This short dwarf stands about 4 feet in height, but is\n"+
"the same in width.  He has a long beard below two black\n"+
"intelligent eyes.  He is built like brick wall but hits\n"+
"like a falling tree with his mighty warhammer.\n");
set_name("guard");
set_alias("dwarf");
set_race("dwarf");
set_gender("male");
set_level(13);
set_hp(190);
set_ac(7);
set_wc(17);
set_al(500);
set_chat_chance(5);
  load_chat("The dwarven guard watches you carefully.\n");
set_chance(10);
set_spell_dam(10);
set_spell_mess1(
"The Dwarven Guard "+HIR+"SLAMS"+NORM+" his opponent to the ground!\n");
set_spell_mess2(
"The Dwarven Guard "+HIR+"SLAMS"+NORM+" you in the face with his Hammer!\n");

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
set_short(HIY+"Golden "+HIW+"Dragon"+NORM+BOLD+"kin"+NORM);	
set_long(
" Before you stands a tall half-dragon, half-man.  Known as\n"+
"a dragonkin, this creature has golden scales and bright\n"+
"blue eyes.  It seems ready for a fight.\n"); 
set_name("dragonkin");
set_heal(4, 3);
set_alias("kin");
set_gender("creature");
set_race("dragon");
set_level(17);
set_hp(220);
set_ac(11);
set_wc(20);
set_al(500);
}

mob6(){
set_short("centaur");	
set_long(
"  Before you is a half-man half-horse creature.  From the\n"+
"waist up, his human torso is of a muscular build, and he\n"+
"carries a large axe.  His hooves seem ready to trample the\n"+
"unwary.\n"); 
set_name("centaur");
set_race("centaur");
set_gender("male");
set_level(16);
set_hp(240);
set_ac(10);
set_wc(19);
set_al(800);
set_chat_chance(5);
  load_chat("The centaur stomps around on his heavy hooves.\n");
  load_chat("The centaur watches you warily.\n");

set_chance(10);
set_spell_dam(5 + random(20));
set_spell_mess1(
"The Centaur charges his opponent!\n");
set_spell_mess2(
"You feel a horrible pain as the Centaur charges over you with its mighty hooves!\n");
}

mob7(){
set_short(YEL+"half-ogre"+NORM+"");	
set_long(
"  Standing at nearly eight feet tall, this huge muscled creature\n"+
"stands ready to protect his domain from anything. A huge\n"+
"club rests easily in its right hand, its entire length spiked\n"+
"with steel. Huge bear furs are wrapped about its form, and it\n"+
"wears a decent helmet to protect its head.\n");
set_name("ogre");
set_alias("half-ogre");
set_race("half-ogre");
set_gender("male");
set_level(16);
set_hp(215);
set_ac(10);
set_wc(21);
set_al(600);
set_chat_chance(5);
  load_chat("The huge ogre watches you.\n");
  load_chat("The Half-Ogre is unsure about you.\n");
}


mob8(){
set_short(HIW+"lesser Archangel of "+HIY+"Light"+NORM+"");	
set_long(
"  Before you is a beautiful humanoid creature from the higher\n"+
"planes of existence.  It is wrapped in light and carries a\n"+
"powerful sword.  You can barely make out armor beneath the\n"+
"glaring light.\n"); 
set_name("angel");
set_alias("archangel");
set_race("archangel");
set_gender("creature");
set_level(14);
set_hp(190);
set_ac(5);
set_wc(18);
set_al(1000);
set_chance(15);
set_spell_dam(random(25));
set_spell_mess1(
"The Archangel slices at his opponent with his sword!\n");
set_spell_mess2(
"You feel a "+HIY+"SEARING"+NORM+" pain as the Archangel slices into you!\n");
}
	
monster_died() {
	
  tell_room(environment(this_object()),
  "As the "+query_name()+" dies you see a large pile of coins lying on the\n"+
  "ground near it. Obviously that is what it was protecting.\n");	
gold = clone_object("obj/money");
gold->set_money(coins);
move_object(gold,environment(this_object()));
return 1; }
