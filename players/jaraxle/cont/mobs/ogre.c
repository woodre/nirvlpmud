#define WAR "/players/jaraxle/cont/daemon"

#include "/players/jaraxle/ansi.h"

inherit "obj/monster.c";



int bdelay;



reset(arg)  {



  ::reset(arg);

  if(arg) return;

bdelay = 0;

set_name("ogre");

set_race("ogre");

set_short("an Ogre");

set_long(

"  This Ogre stands about 8 1/2 feet tall and is rippling\n"+

"with muscles.  His head is shaven, with huge yellowed teeth\n"+

"filling his mouth.  The hands of this creature are large\n"+

"and carry a huge wooden club. His body is covered in dirty\n"+

"animal skins that offer very little protection. A bulky\n"+

"sack is carried on his back, held by a long rope that winds\n"+

"around his chest. He seems ready to kill anything.\n"); 

set_level(20);

set_hp(700);

set_al(-1000);

set_wc(35);

set_ac(11);

set_heart_beat(1);

set_aggressive(1);

set_chance(35);

set_spell_dam(random(20) + 15);

set_spell_mess1(

"The Ogre "+HIR+"SLAMS"+NORM+" his opponent with the club!\n");

set_spell_mess2(

"You fall back in pain as the Ogre slams you with his club!\n");

}

