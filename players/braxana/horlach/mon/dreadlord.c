inherit "players/braxana/horlach/mon";

#include "/players/mythos/closed/guild/name.h"
string rlong;

reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("DreadLord");
  set_short("DreadLord");
  set_alias("dreadlord");
  set_race("dread");
  set_long("You see before you the embodiment of ANTI-LIFE.\n"+
           "A thing of blackness, a thing of null.\n"+
           "You can barely make out a shape with arms and horns....\n");
  set_level(30);
  set_hp(20000);
  set_al(-1000);
  set_wc(80);
  set_ac(30);
  set_aggressive(0);
  set_perception(200);
  set_chance(90,0);
  set_spell_tell("The DreadLord glares at you!",0);
  set_spell_mess("The Dymon glares at its foe!",0);
  set_spell_dam(60,0);
  set_chance(75,1);
  set_spell_tell("You feel your life drain away as the DreadLord feeds on you!",1);
  set_spell_mess("The DreadLord's foe drops to one knee...",1);
  set_spell_dam(150,1);
  set_chance(50,2);
  set_spell_tell("Razor-like TEETH tear into you!",2);
  set_spell_mess("The Dread's foe screams in pain!",2);
  set_spell_dam(200,2);
  set_chance(20,3);
  set_spell_tell("ALL IS PAIN!",3);
  set_spell_mess("The Dread's foe screams in pain!",3);
  set_spell_dam(600,3);
}

