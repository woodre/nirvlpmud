#include "/players/jaraxle/ansi.h"

inherit "obj/monster.c";



object gold;

int ground;

int coins;

int get_coins;

int hound;



reset(arg)  {



  ::reset(arg);

  if(arg) return;



set_alt_name("cave_mob");

set_dead_ob(this_object()); 



switch(random(20) + 1){

  case 18..20:

   mob1();  /* archangel of light */

   coins = 3000 + random(2200);

   break;

  case 15..17:

   mob4();  /* Silver Knight */

   coins = 4500 + random(1200);

   break;

  case 12..14:

   mob7();  /* Ki-Rin */

   coins = 4250 + random(2000);

   break;

  case 9..11:

   mob8();  /* Hound Archon */

   coins = 4200 + random(2000);

   break;

  case 7..8:

   mob9();  /* Mystic Elf */

   coins = 4500 + random(1200);

   break; 

  case 5..6:

   mob10(); /* Guardian Naga */

   coins = 4500 + random(1100);

   break;

  case 4:

   mob3();  /* Fire Element */

   coins = 3000 + random(2000);

   break;

  case 3:

   mob2();  /* Golem */

   coins = 4000 + random(1850);

   break;

  case 2:

   mob5();  /* Shambling Mound */

   coins = 3000 + random(2000);

   break;

  case 1:

   mob6(); /*  Wyvern */

   coins = 4500 + random(1100);

   break;

  default:

   mob1();

   coins = 100;

   break;

  }





set_heart_beat(1);



if(get_coins){  

gold = clone_object("obj/money");

gold->set_money(coins);

move_object(gold,this_object());

 }

}	



heart_beat(){

  ::heart_beat();

  if(hound){

  if(random(100) < 60){

    if(attacker_ob && !attacker_ob->query_ghost()){

      already_fight=0;

      attack();

      }

   }

 }

}

                             

mob1(){

set_short(HIW+"Archangel of "+HIY+"Light"+NORM+"");

set_long(

"  This beautiful creature standing before you emits\n"+

"a holy light that covers the area and warms you. It\n"+

"wears a breast plate of pure mithril, and carries\n"+

"a sword of light.  Its eternal eyes stare through\n"+

"you.\n");

set_name("archangel");

set_alias("archangel of light");

set_gender("male");

set_race("angel");

set_level(19);

set_hp(485);

set_ac(10+ random(5));

set_wc(34+ random(5));

set_al(1000);

set_chance(25);

set_spell_dam(20 + random(20));



set_spell_mess1(

"The Archangel sweeps forward and strikes with its sword of light!\n");

set_spell_mess2(

"You are driven back by the seering hot Sword of the Archangel!\n"+

HIW+"         -  - --- "+HIY+"S L A S H"+HIW+" --- - -"+NORM+"\n"+

"You cry out in pain!\n");

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

set_short(HIW+"Silver Knight"+NORM+"");

set_long(

"  Before you stands a proud knight of the realm.  He is\n"+

"covered in thick plates of armor, and carries a two-handed\n"+

"sword.  The symbols of law and good cover his shield.\n");

set_name("knight");

set_alias("silver knight");

set_gender("male");

set_level(20);

set_race("human");

set_hp(500);

set_ac(18 + random(6));

set_wc(30 + random(10));

set_al(0);

set_chance(20);

set_spell_dam(20 + random(20));

set_spell_mess1(

"The Knight swings his sword in a wide arc...\n"+

"           "+HIW+"SLICE"+NORM+"\n"+

"       It tears into its opponent!\n");

set_spell_mess2(

"You feel a horrible pain as the Knights sword bites into your flesh!\n");

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

set_short(HIY+"Ki"+HIW+"-"+HIY+"Rin"+NORM);	

set_long(

"  Here stands the most beautiful creature in all the realms. It\n"+

"has the shape of a large horse, but with silver skin and mane.\n"+

"An intelligence is apparent in its eyes as it stares at you from\n"+

"under a single horn that juts from atop its head.\n");

set_name("ki");

set_alias("kirin");

set_race("ki-rin");

set_gender("creature");

set_level(20);

set_hp(600 + random(150));

set_ac(8 + random(5));

set_wc(33 + random(15));

set_al(1000);

set_chat_chance(5);

  load_chat("The Ki-Rin watches you with interest.\n");

  load_chat("The Ki-Rin taps a large hoof on the ground.\n");

set_chance(10 + random(20));

set_spell_dam(25 + random(30));

set_spell_mess1(

"Magic erupts from the "+HIY+"Ki"+HIW+"-"+HIY+"Rin's "+HIW+"Silver Horn"+NORM+"!\n"+

"Its opponent falls back in a terrible pain!\n");

set_spell_mess2(

"You feel a terrible pain as the Ki-Rin's horn fires magical energy at you!\n"+

"      "+HIB+"COLD"+NORM+" sweeps over you....\n"+

"   "+HIG+"MAGIC"+NORM+" encompasses you....\n"+

"       "+HIW+"FEAR"+NORM+" destroys your courage...\n"+  

"               "+HIR+"FIRE"+NORM+" envelops you.....\n"+

"             "+HIB+"LIGHTNING"+NORM+" strikes you....\n"+

"             You crumble under the onslaught!\n");                     

}



mob8(){

set_short(HIW+"Hound "+HIM+"Archon"+NORM);	

set_long(

"  The Hound Archon is a celestial being from another plane of\n"+

"existence.  It is humanoid in appearance, but has the head of\n"+

"a dog.  Its body is covered with light plates of armor, and it\n"+

"carries a magical longsword.  The Hound is a powerful being.\n");

set_name("archon");

set_alias("hound");

set_gender("creature");

set_race("archon");

set_heal(3, 8);

set_level(20);

set_hp(515);

set_ac(11 + random(12));

set_wc(30 + random(14));

set_wc_bonus(30 + random(14));

set_al(1000);

hound = 1;

}	



mob9(){

set_short(HIG+"Mystic Elf"+NORM);	

set_long(

"  This is a powerful elf wizard.  He stands before you in\n"+

"green robes covered in runes, with a staff of oak in his\n"+

"right hand.  He appears to be old, even for an elf.\n");

set_name("elf");

set_alias("mage");

set_gender("male");

set_race("undead");

set_level(20);

set_hp(515 + random(100));

set_ac(20 + random(12));

set_wc(35 + random(14));

set_al(1000);

set_chance(30 + random(12));

set_spell_dam(random(40) + 20);



set_spell_mess1(

HIW+"The Elf Mage holds up his staff...\n\n"+

"          [ "+HIG+"M Y S T I C A L   E N E R G Y"+HIW+" ]\n"+

"      A wave of power fills the room!\n"+NORM);

set_spell_mess2(

HIW+"You scream in agony as a wave of "+HIG+"Mystical Energy"+HIW+" slams into you!\n"+NORM);

}	



mob10(){

set_short(HIY+"Guardian "+HIW+"Naga"+NORM);	

set_long(

" This long serpent-like beast has the head of an elf\n"+

"which extends down into a scaley torso. Its body is\n"+

"nearly 30 feet in length and filled with corded muscle\n"+

"that can crush a human in seconds.  It watches you\n"+

"carefully, waiting for any move.\n");

set_name("naga");

set_alias("guardian");

set_gender("creature");

set_race("naga");

set_level(20);

set_hp(500 + random(150));

set_ac(20 + random(12));

set_wc(28 + random(14));

set_al(1000);

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

