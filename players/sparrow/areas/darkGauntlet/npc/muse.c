/*****************************************************************************
 *      File:                   muse.c
 *      Function:               Muse the Dark Bard
 *      Author(s):              Sparrow@Nirvana
 *      Copyright:              Copyright (c) 2010 Sparrow
 *                              All Rights Reserved.
 *      Source:                 12/24/10-12/25/10 Merry Christmas 
 *      Notes:
 *      Change History:
 ****************************************************************************/
#include "/sys/ansi.h"
inherit "/obj/monster";
string sm;

reset(arg) {
  ::reset(arg);
  if (!arg) {    
    if(!present("congela", this_object())) {
      move_object(clone_object("/players/sparrow/areas/darkGauntlet/obj/wep/congela.c"),this_object());
    }
    if(!present("distrugere", this_object())) {
      move_object(clone_object("/players/sparrow/areas/darkGauntlet/obj/wep/distrugere.c"),this_object());
    }
    if(!present("boots", this_object())) {
      move_object(clone_object("/players/sparrow/areas/darkGauntlet/obj/arm/darksongBoots.c"),this_object());
    }
    if(!present("armor", this_object())) {
      move_object(clone_object("/players/sparrow/areas/darkGauntlet/obj/arm/darksongLeather.c"),this_object());
    }
    if(!present("circlet", this_object())) {
      move_object(clone_object("/players/sparrow/areas/darkGauntlet/obj/arm/darksongCirclet.c"),this_object());
    }
    if(!present("cloak", this_object())) {
      move_object(clone_object("/players/sparrow/areas/darkGauntlet/obj/arm/darksongCloak.c"),this_object());
    }  
    /* sm - spell marker. Make it easier for players to see when important
       battle messages come through.
    */
    sm = HIM+" ~ "+NORM;
    set_name("muse");
    set_alias("bard");
    set_short(HIM+"Muse "+MAG+"["+HIW+"The "+HIK+"D"+HIW+"ark "+HIK+"B"+HIW+"ard"+NORM+MAG+"]"+NORM);
    set_race( "demon");
    set_long("\n");
    set_gender("female");
    set_level(40);
    set_ac(40+random(10));
    set_wc(110+random(20));
    set_hp(2500 + random(500));
    set_al(-1000);
    set_aggressive(0);
    set_chat_chance(0);
    set_a_chat_chance(0);
    set_dead_ob(this_object());
    add_spell("dSong1",
      sm+"#CMN# sings a dark and foreboding tune making your skin crawl.\n\n\n",
      sm+"#CMN# sings a dark and foreboding tune, you see #CTN# shiver in pain!\n\n\n",
      25,"30d4","other|sonic",1,"debuff");
    add_spell("dSong2",
      sm+"#CMN# hums an amusing tune, she seems to get stronger with each bar!\n\n\n",
      sm+"#CMN# hums an amusing tune, she seems to get stronger with each bar!\n\n\n",
      25,0,0,0,"buff");
    add_spell("dart",
      sm+"#CMN#'s form  "+HIK+HBMAG+" B  L  U  R  S "+NORM+"  as she darts around behind you!\n"+
      sm+"       #CMN# laughs maniacally as she plunges both kukris into your back!\n",
      sm+"#CMN#'s form  "+HIK+HBMAG+" B  L  U  R  S "+NORM+"  as she darts around behind #CTN#!\n"+
      sm+"       #CMN# laughs maniacally as she plunges both kukris into #TP# back!\n",
      30,({"10d4","20d2","20d2"}),({0,"other|cold","other|dark"}),0); 
    set_multi_cast(0);
    set_weapon_params("other|dark",60,0);
    set_weapon_params("other|cold",60,0);
  }
}

monster_died() {
  object x;
  object y;
  tell_room(environment(this_object()),
    "BOO!\n");
  x = present("corpse",environment(this_object()));
  destruct(x);
  return 0;
}

void unBuff() {
  this_object()->set_wc(110);
  this_object()->set_ac(45);
  return;
}

void buff(object att) {
  int huh;
  this_object()->heal_self(200);
  huh = (int)this_object()->query_wc(); 
  if(huh > 135) {
    this_object()->set_wc(140);
    this_object()->set_ac(80);
    call_out("unBuff", 20);
  }
  return 0;    
}

void debuff(object att) {
  object a;
  if(att) {
    a = present("dischord", att);
    if(a) {
      a->add_duration(10+random(6));
    }
    else {
      a = clone_object("/players/sparrow/areas/darkGauntlet/obj/deBuff.c");
      a->set_duration(10+random(6));
      move_object(a, att);
    }
  }
  return;
}
