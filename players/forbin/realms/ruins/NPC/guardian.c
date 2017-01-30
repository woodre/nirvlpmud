#include "/players/forbin/realms/ruins/ruinsdefine.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("guardian");
  set_alias("twilight");
  set_race("darkling");
  set_short(HIK+"Guardian "+NORM+BLU+"of Twili"+HIB+"ght"+NORM);
  set_long(
    " This four-legged monstrosity stands blocking further passage into the\n"+
    "ruins.  Its head is covered with thick plates of scaly armor, as well as\n"+
    "its chest and forelegs.  The remaining parts of this beast have long\n"+
    "thick black hair growing from them, the strands clinging together from\n"+ 
    "dried blood and gore that has collected on it.  Its eyes are of deep\n"+
    "blue, seemingly out of place for such a creature; you look into them and\n"+
    "feel peace even while at the same time your heart races in fear.  It is\n"+
    "shackled to the floor by thick rusted chains.\n");
  set_level(20);
  set_hp(650);
  set_al(-1000);
  set_wc(32);
  set_ac(10);
  set_aggressive(0);
  set_chat_chance(15);
    load_chat("The Guardian looks at you closely.\n");
    load_chat("The Guardian pulls at its shackles.\n");
    load_chat("Faint mist hangs in the air as the Guardian snorts at your presence.\n");
  set_a_chat_chance(15);
    load_a_chat("As it slams you to the ground, the Guardian unleashes a roar!\n");
    load_a_chat("The Guardian ROARS!\n");
  add_spell("smash",
    "\n\n\tThe $HK$Guardian$N$ leaps across the ground at you...\n\n"+
    "It smashes you squarely in the stomach, instantly sickening you!\n",
    "The $HK$Guardian$N$ leaps across the ground toward #CTN#,\n"+
    "striking #TO# hard in #TP# stomach.\n",
    20,"20-45","physical",0);    
  add_spell("claw",
    "The $HK$Guardian$N$ rises up on its hind legs and brings its\n"+
    "front limbs crashing down on you.\n\n"+
    "     As its claws dig deep, $R$blood$N$ gushes out of your wounds!\n",
    "The $HK$Guardian$N$ rises up on its hind legs and brings its\n"+
    "front limbs crashing down on #CTN#.\n"+
    "$R$Blood$N$ gushes out of #CTN#'s wounds!\n",
    10,"40-80","physical",0); 
  set_dead_ob(this_object());
}

init() {
  ::init();
  add_action("no_move", "east");
}

no_move() {
  write(
    "The "+HIK+"Guardian "+NORM+BLU+"of Twili"+HIB+"ght"+NORM+" moves to block you!\n");
  return 1;
}

monster_died() {
  object corpse;
  corpse = present("corpse", environment(this_object()));
#ifdef KILLLOG
  mon_log(KILLLOG);
#endif 
  tell_room(environment(this_object()),
    "As the beast slumps to the ground, you catch a flicker of something\n"+
    "gold hidden in the thick fur around its neck.\n");
  move_object(clone_object(OBJ+"anhk.c"), corpse);    
  return 1; 
} 
