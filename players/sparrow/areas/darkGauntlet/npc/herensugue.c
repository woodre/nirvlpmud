/*****************************************************************************
 *      File:                   herensugue.c
 *      Function:               herensugue the maker
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
    /* sm - spell marker. Make it easier for players to see when important
       battle messages come through.
    */
    string sm;
    sm = HIC+" ~ "+NORM;
    set_name("herensugue");
    set_alias("maker");
    set_short(HIK+"Herensugue "+HIG+"["+HIW+"Maker of Evil Things"+HIG+"]"+NORM);
    set_race( "demon");
    set_long("Herensugue is the ancient creator of all things evil. Three hundred years ago\n"+
	     "he had run amok, so much evil was created that the balance was destroyed\n");
    set_gender("male");
    set_level(40);
    set_ac(40+random(10));
    set_wc(70+random(10));
    set_hp(3500 + random(500));
    set_al(-1000);
    set_aggressive(0);
    set_chat_chance(0);
    set_a_chat_chance(0);
    set_dead_ob(this_object());
    add_spell("summoning",
      sm+"\n#CMN# pulls out a knife and slices his wrist!\n"+
      sm+HIR+"          Blood"+NORM+" pours from the wound, taking physical form!\n\n\n",
      sm+"\n#CMN# pulls out a knife and slices his wrist!\n"+
      sm+HIR+"          Blood"+NORM+" pours from the wound, taking physical form!\n\n\n",
      50,0,0,5,"summon");
    add_spell("glare",
      sm+"\n#CMN# stares at you stonily, you feel your mind being shredded!\n\n\n",
      sm+"\n#CMN# stares at #CTN# stonily, #CTN# grabs #TP# head in agony!\n\n\n",
      20,"30d4","other|mental",0);
    add_spell("crush",
      sm+"\n#CMN# points at you and screams: "+HIY+"'Eu esmaga-lo ate a morte!'\n"+NORM+
      sm+"          #CMN# cackles with a thousand voices while clenching his fist...\n"+
      sm+"                   Your body is crushed by an invisible force, you can't breathe!\n",
      sm+"\n#CMN# points at #CTN# and screams: "+HIY+"'Eu esmaga-lo ate a morte!'\n"+NORM+
      sm+"          #CMN# cackles with a thousand voices while clenching his fist...\n"+
      sm+"                   #CTN#'s body is crushed by an invisible force, #TS# can't breathe!\n",
      10,"50d4",0,0); 
    set_multi_cast(0);
    set_weapon_params("other|evil",60,0);
  }
}

monster_died() {
  object x;
  object y;
  tell_room(environment(this_object()),
    "Herensugue screams in terror as his essence is drawn into his knife.\n");
  x = present("corpse",environment(this_object()));
  destruct(x);
  return 0;
}

void summon(object att) {
  object mon;  
  tell_room(environment(this_object()),
    "The demon finally forms and leaps to attack!\n");
  mon = clone_object("/players/sparrow/areas/darkGauntlet/npc/summon.c");
  move_object(mon, environment(this_object()));
  if(att && mon) {
    mon->attacked_by(att);
    mon->attacked_by(att);
    mon->attacked_by(att);
  }
  return 0;  
}
