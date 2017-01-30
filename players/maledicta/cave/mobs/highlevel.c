#include "/players/maledicta/ansi.h"
inherit "obj/monster.c";

object gold;
int ground;
int coins;
int get_coins;
reset(arg)  {

  ::reset(arg);
  if(arg) return;

set_alt_name("cave_mob");
set_dead_ob(this_object());
switch(random(13)){
  case 12:
   mob10();
   coins = 2000 + random(1100);
   break;
  case 11:
   mob9();
   coins = 4500 + random(1200);
   break;
  case 10:
   mob3();
   coins = 3000 + random(2000);
   break;
  case 8..9:
   mob4();
   coins = 4500 + random(1200);
   break;
  case 7:
   mob5();
   coins = 3000 + random(2000);
   break; 
  case 5..6:
   mob6();
   coins = 4500 + random(1100);
   break;
  case 4:
   mob1();
   coins = 3000 + random(2000);
   break;
  case 2..3:
   mob2();
   coins = 4000 + random(1850);
   break;
  case 1:
   mob7();
   coins = 4250 + random(2000);
   break;
  case 0:
   mob8();
   coins = 4200 + random(1800);
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
set_short(RED+"ettin"+NORM+"");
set_long(
"  This huge creature stands at nearly ten feet tall. It is covered in\n"+
"disgusting looking animal furs and has a huge leather pouch strapped\n"+
"to its side. Atop its shoulders are two heads, both extremely ugly,\n"+
"and covered with grime. It carries a huge club in each of its large\n"+
"hands.\n");
set_name("ettin");
set_alias("ettin");
set_gender("male");
set_race("giant");
set_level(19);
set_hp(485);
set_ac(10+ random(5));
set_wc(34+ random(5));
set_al(-800);
set_chat_chance(5);
  load_chat("The huge Ettin swings its clubs in anticipation.\n");
  load_chat("Both of the heads of the Ettin sneer at you.\n");
set_chance(25);
set_spell_dam(20 + random(20));

set_spell_mess1(
"The Ettin slams its opponent with its twin clubs!\n");
set_spell_mess2(
"You look up in time to see both of the Ettins clubs drop down on you...\n\n"+
"                  "+HIR+"SLAM!"+NORM+"\n"+
"                    "+HIR+"SLAM!"+NORM+"\n"+
"                   You fall back dazed and bleeding!\n");
}

mob2(){
set_short(HIW+"golem"+NORM+"");
set_long(
"  This huge magical creation is made from the most resistant and\n"+
"impenetrable stone ever found in the material realm. Its body is\n"+
"sculpted into a towering form, its head neckless and formed \n"+
"straight into its huge chest. Its arms are long and end in twin\n"+
"spiked balls, easily able to crush the life from any mortal. A\n"+
"single large gem can be seen where its eyes would be, its crystal\n"+
"surface glimmering with magical power.\n");
set_name("golem");
set_alias("golem");
set_race("automaton");
set_gender("creature");
set_level(20);
set_hp(530 + random(100));
set_ac(19 + random(8));
set_wc(35 + random(8));
set_al(0);
set_chat_chance(5);
  load_chat("The golem stands perfectly still.\n");
set_a_chat_chance(15);
  load_a_chat("Your weapon rings out against the stone skin of the golem!\n");
  load_a_chat("Golem hits you very hard.\n");
set_chance(25);
set_spell_dam(15 + random(30));
set_spell_mess1(
"The golem spins about "+HIM+"SLAMMING"+NORM+" its opponent!\n");
set_spell_mess2(
"You feel dazed as the golem "+HIM+"SLAMS"+NORM+" you with its arms!\n");
}	

mob3(){
set_short(HIR+"fire elemental"+NORM+"");	
set_long(
"  This man-sized flaming creature is a magical creation that burns\n"+
"extremely bright. A wave of heat eminates from its body, causing\n"+
"everything around it to burn or melt.\n"); 
set_name("elemental");
set_alias("elemental");
set_level(19);
set_race("elemental");
set_gender("creature");
set_hp(500 + random(50));
set_ac(13 + random(5));
set_wc(28 + random(10));
set_al(0);
set_chat_chance(5);
  load_chat("The fire elemental seems to watch you with a sightless gaze.\n");
  load_chat("The fire elemental dances about the room with a hypnotic grace.\n");
set_a_chat_chance(15);
  load_a_chat("You feel a horrible heat wash over you!\n");
  load_a_chat("The fire element resists your attacks.\n");
set_chance(10 + random(16));
set_spell_dam(20 + random(30));
set_spell_mess1(
"A stream of "+HIR+"FLAME"+NORM+" jets out at the elementals enemy!\n");
set_spell_mess2(
"You are engulfed in a stream of "+HIR+"FLAME"+NORM+"!\n");
}

mob4(){
set_short(HIW+"skeletal "+BOLD+BLK+"knight"+NORM+"");
set_long(
"  Standing before you is an undead warrior dressed in the armor\n"+
"of a knight, which hangs loosely from its body. Its body is of\n"+
"white bone which is completely clean of flesh. Its eyes are small\n"+
"red dots which stare outward like small points of flame. It carries\n"+
"a huge two-handed sword.\n");
set_name("knight");
set_alias("undead");
set_gender("creature");
set_level(20);
set_race("undead");
set_hp(500);
set_ac(18 + random(6));
set_wc(30 + random(10));
set_al(0);
set_chance(20);
set_spell_dam(20 + random(20));
set_spell_mess1(
"The undead knight swings its sword in a wide arc...\n"+
"           "+HIW+"SLICE"+NORM+"\n"+
"       It tears into its opponent!\n");
set_spell_mess2(
"You feel a horrible pain as the undead knights sword bites into your flesh!\n");
}

mob5(){
set_short(GRN+"shambling mound"+NORM+"");	
set_long(
"  A huge pile of trash and rotting vegetation, this creature\n"+
"stands about twelve feet tall. It is hard to make out features\n"+
"on this thing, but you do see arms and legs, which are huge\n"+
"and probably powerful. It leaves a slimy trail as it moves\n"+
"around the room.\n"); 
set_name("mound");
set_heal(3, 8);
set_alias("mound");
set_gender("creature");
set_level(19);
set_hp(475 + random(100));
set_race("shambler");
set_ac(16);
set_wc(28 + random(5));
set_al(0);
set_chat_chance(5);
  load_chat("A foul smell wafts about the room.\n");
  load_chat("Something falls off of the mound and splats on the ground.\n");
set_a_chat_chance(15);
  load_a_chat("Your attack lands with a splat against the mound!\n");
  load_a_chat("You find your weapon hard to pull from the mound.\n");
set_chance(20);
set_spell_dam(10 + random(25));
set_spell_mess1(
"The shambling mound swats at its opponent with a rotting arm!\n");
set_spell_mess2(
"You are slammed to the ground by a huge rotting arm!\n");

}

mob6(){
set_short(RED+"wyvern"+NORM+"");	
set_long(
"  This huge reptilian beast is covered in redish brown scales. Its\n"+
"back has huge wings which sprout outward. Its head is huge and\n"+
"covered with short horns, a large terrible maw is filled with sharp\n"+
"teeth which can rend flesh easily. It has large muscled arms which\n"+
"end in white razor sharp claws.  It looks very hungry.\n"); 
set_name("wyvern");
set_alias("wyvern");
set_level(20);
set_hp(525 + random(100));
set_gender("creature");
set_race("wyvern");
set_ac(18 + random(4));
set_wc(26 + random(4));
set_al(0);
set_chat_chance(5);
  load_chat("The wyvern hisses loudly.\n");
  load_chat("The large wyvern's tail lashes about.\n");

set_chance(20);
set_spell_dam(15 + random(20));
set_spell_mess1(
"The tail of the wyvern flips around impaling its opponent!\n");
set_spell_mess2(
"A burning pain courses through your body as you are impaled on the wyverns tail!\n");
}

mob7(){
set_short(YEL+"beholder"+NORM+"");	
set_long(
"  A large greenish sphere made of rock hard scales. It has\n"+
"ten eyestalks and a huge bluish central eye that stares at\n"+
"you with hatred. A large fanged mouth is directly below the\n"+
"main eye. It hovers at about waist level over the ground.\n");
set_name("beholder");
set_alias("beholder");
set_race("beholder");
set_gender("creature");
set_level(20);
set_hp(600 + random(150));
set_ac(8 + random(5));
set_wc(33 + random(15));
set_al(-1000);
set_chat_chance(5);
  load_chat("The beholder hovers over the ground watching you.\n");
  load_chat("An eyestalk waivers back and forth watching you.\n");
set_a_chat_chance(15);
  load_a_chat("A beam of magic fires from an eyestalk.\n");
set_chance(10 + random(20));
set_spell_dam(25 + random(30));
set_spell_mess1(
"A myriad of magics erupts from the Beholders numerous eyestalks!\n"+
"Its opponent falls back in a terrible pain!\n");
set_spell_mess2(
"You feel a terrible pain as the Beholders eyestalks fire magic energy at you!\n"+
"               "+BLU+"COLD"+NORM+" sweeps over you....\n"+
"                 "+HIG+"MAGIC"+NORM+" encompasses you....\n"+
"                   "+HIW+"FEAR"+NORM+" destroys your courage...\n"+  
"                     "+HIR+"FIRE"+NORM+" envelops you.....\n"+
"                       "+HIB+"LIGHTNING"+NORM+" strikes you....\n"+
"                         "+HIM+"TEETH"+NORM+" tear into your flesh...\n"+
"             You crumble under the onslaught!\n");                     
}

mob8(){
set_short(HIW+"demon guard"+NORM+"");	
set_long(
"  Standing before you, this huge black-skinned demon is covered with short\n"+
"horns and in some places, thick exoskeleton plates. Its head is huge, two\n"+
"long horns protruding from either side of its head, and deep blue eyes\n"+
"staring out from under thickskinned brows. Its large knuckles are tipped\n"+
"with wicked spikes, allowing for huge damage to anyone foolish enough\n"+
"to fight this beast.\n");
set_name("demon");
set_alias("guard");
set_gender("creature");
set_race("demon");
set_level(20);
set_hp(515);
set_ac(11 + random(12));
set_wc(30 + random(14));
set_al(-1000);
set_chance(10 + random(12));
set_spell_dam(random(40) + 20);

set_spell_mess1(
"The demon guard breathes a stream of "+HIR+"FLAME"+NORM+" at its opponent!\n");
set_spell_mess2(
"You are engulfed in a raging stream of "+HIR+"FLAME"+NORM+" from the demon guard!\n");
}	

mob9(){
set_short(HIW+"Lich"+HIB+" Mage"+NORM+"");	
set_long(
"  Before you stands a tall skeletal figure in rotting robes and\n"+
"rusting bits of iron jewelry.  It's eyes shine with a bright blue\n"+
"light that seems to pierce you to the soul.  A coldness radiates\n"+
"from its body in waves.\n");
set_name("lich");
set_alias("mage");
set_gender("creature");
set_race("undead");
set_level(20);
set_hp(515 + random(100));
set_ac(20 + random(12));
set_wc(35 + random(14));
set_al(-1000);
set_chance(30 + random(12));
set_spell_dam(random(40) + 20);

set_spell_mess1(
"The lich stares at it's opponent...\n\n"+
"                 "+BOLD+" [  "+HIB+"I C E"+NORM+BOLD+"  ] "+NORM+"\n"+
"   A wave of freezing cold fills the room!\n");
set_spell_mess2(
"You scream in agony as a wave of "+BOLD+"[ "+HIB+"I C E"+NORM+BOLD+" ]"+NORM+" slams into you!\n");
}	

mob10(){
set_short(HIM+"Guardian "+NORM+BOLD+"Naga"+NORM+"");	
set_long(
" This long serpent-like beast has the fanged head of an\n"+
"elf which extends down into a scaley torso. Its body is\n"+
"nearly 30 feet in length and filled with corded muscle that\n"+
"can crush a human in seconds.  It watches you carefully,\n"+
"waiting for any move.\n");
set_name("naga");
set_alias("guardian");
set_gender("creature");
set_race("naga");
set_level(20);
set_hp(500 + random(150));
set_ac(20 + random(12));
set_wc(28 + random(14));
set_al(-1000);
set_chance(20 + random(12));
set_spell_dam(random(80) + 40);

set_spell_mess1(
"The naga surrounds it's opponent...\n"+
"       -~-~  "+HIR+"C R U S H"+NORM+"  ~-~-\n"+
"     The naga's victim screams as it is slowly crushed!\n");
set_spell_mess2(
"The naga slides its long body around your torso and stomach...\n"+
"You are slowly "+HIR+"CRUSHED"+NORM+" as it constricts!\n");
}	

monster_died() {
if(!get_coins){	
  tell_room(environment(this_object()),
  "As the "+query_name()+" dies you see a large pile of coins lying on the\n"+
  "ground near it. Obviously that is what it was protecting.\n");	
gold = clone_object("obj/money");
gold->set_money(coins);
move_object(gold,environment(this_object()));
return 1; }

return 1; }
