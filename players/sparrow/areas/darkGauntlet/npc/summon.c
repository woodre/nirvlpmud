/*****************************************************************************
 *      File:                   summon.c
 *      Function:               creatures that herensugue knife creates
 *      Author(s):              Sparrow@Nirvana
 *      Copyright:              Copyright (c) 2010 Sparrow
 *                              All Rights Reserved.
 *      Source:                 12/23/10 
 *      Notes:
 *      Change History:
 ****************************************************************************/
#include "/sys/ansi.h"
inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if (!arg) {
    int level, wepClass, armClass, hPoints, sDam, sTar, sChan;
    string mName, mShort, mLong, sMess1, sMess2,dType,sm;
    /* generation of random monster */
    switch(random(10)) {
      case 0..4:
        level = 15;
        wepClass = 50+random(10);
        armClass = 17+random(10);
        hPoints = 400;
        sDam = 15+random(10);
        mName = "armanite";
        mShort = HIR+"Armanite "+HIK+"["+HIW+"Summoned"+HIK+"]"+NORM;
        mLong = "Armanites compose the heavy cavalry of the army of the The Abyss. They resemble\n"+
		"fiendish centaurs covered by a full plate armor. They are fierce enemies in battle\n"+
		"and their charges are deeply feared. On the layers of the Abyss they usually wander\n"+
		"in groups of dozens. Because of their unusual discipline, they are often employed\n"+
		"by powerful abyssal lords as mercenaries.\n";
        sMess1 = "The armanite "+HIM+"charges"+NORM+" fearlessly into you, knocking you back!!!\n";
	sMess2 = "The armanite "+HIM+"charges"+NORM+" fearlessly into #CTN#, knocking #TS# back!!!\n";
	sTar = 0;
	sChan = 50;
	dType = "physical";        
      break;
      case 5..7:
        level = 17;
	wepClass = 60+random(10);
	armClass = 20+random(10);
	hPoints = 500+random(200);
	sDam = 20+random(20);
      	mName = "bulezau";
	mShort = HIC+"Bulezau "+HIK+"["+HIW+"Summoned"+HIK+"]"+NORM;
	mLong = "Bulezaus are the core of the heavy infantry of the armies of The Abyss. Bulezaus\n"+
		"have the shape of a big man with the head of a ram. Despite their appearance they\n"+
		"are excellent warriors, particulary in melee combat. They aggregate in groups only\n"+
		"if they have a powerful leader able to control them; whenever this leader passes\n"+
		"away, it is almost certain that bulezaus will start fighting each other until death.\n";
	sMess1 = "The bulezaus howls with an ear-piercing scream.\nYour head is filled with   "+HIR+"P  A  I  N"+NORM+"  !!!\n";
	sMess2 = "The bulezaus howls with an ear-piercing scream.\n#CTN#'s head is filled with   "+HIR+"P  A  I  N"+NORM+"  !!!\n";
	sTar = 1;
	sChan = 50;
	dType = "other|sonic";
      break;
      case 8..9:
      	level = 20;
	wepClass = 70+random(10);
	armClass = 25+random(10);
	hPoints = 700+random(300);
	sDam = 25+random(25);
	mName = "chasme";
	mShort = HIG+"Chasme "+HIK+"["+HIW+"Summoned"+HIK+"]"+NORM; 
	mLong = "Chasmes are merciless demons resembling great flies. They enjoy torturing and tormenting\n"+
		"other beings, also demons, especially if they are sure of their impunity. Because of\n"+
		"their curelty, chasmes are often charged with torturing enemies and deserters. Sometimes\n"+
		"chasmes can be found in groups acting as patrols; they fly in the skies of The Abyss\n"+
		"looking for intruders to torment.\n";
	sMess1 = "The chasme sprays you with a torrent of "+HIG+"acidic vomit"+NORM+"!!!\n";
	sMess2 = "The chasme sprays #CTN# with a torrent of "+HIG+"acidic vomit"+NORM+"!!!\n";
	sTar = 0;
	sChan = 50;
	dType = "other|poison";
      break;
    }    

    sm = HIB+" ~ "+NORM;
    set_name(mName);
    set_alias("demon");
    set_short(mShort);
    set_race( "demon");
    set_long(mLong);
    set_level(level);
    set_ac(armClass);
    set_wc(wepClass);
    set_hp(hPoints);
    set_al(-1000);
    set_aggressive(1);
    set_chat_chance(0);
    set_a_chat_chance(0);
    set_dead_ob(this_object());
    add_spell("mSpell",
      sm+sMess1,
      sm+sMess2,
      sChan,sDam,dType,sTar);
    set_multi_cast(0);
  }
}

void init() {
  call_out("destroy_me",30);
}

void destroy_me() {
  tell_room(environment(this_object()),
    "The demon disappears in a puff of smoke!\n");
  destruct(this_object());
}

monster_died() {
  object x;
  object y;
  tell_room(environment(this_object()),
    "The demon disappears in a puff of smoke!\n");
  x = present("corpse",environment(this_object()));
  destruct(x);
  return 0;
}
