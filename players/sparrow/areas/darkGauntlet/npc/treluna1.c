/*****************************************************************************
 *      File:                   treluna1.c
 *      Function:               Treluna first form
 *      Author(s):              Sparrow@Nirvana
 *      Copyright:              Copyright (c) 2010 Sparrow
 *                              All Rights Reserved.
 *      Source:                 12/20/10 (happy birthday me!)
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
    sm = HIY+" ~ "+NORM;
    set_name("treluna");
    set_alias("mistress");
    set_short("Treluna "+HIY+"["+NORM+"Mistress of Insanity"+HIY+"] ["+NORM+"maiden"+HIY+"]"+NORM);
    set_race( "demon");
    set_long("Treluna, the Mistress of Insanity as she is known in some circles, was the first of the\n"+
    		 "demons imprisoned by the Black Willow three centuries ago.  Appearing in her first form,\n"+
    		 "the beautiful maiden, her beauty is enough to melt even the hardest of souls.  She has\n"+
    		 "used this form to infiltrate houses of the holy, impersonating a healer of great skill.\n"+
    		 "Even as she healed their physical wounds a portion of the soul was taken in its place.\n"+
    		 "Patrons of the maiden seemed to age at an alarming rate and later it was discovered she\n"+
    		 "fed from the souls to maintain her power and her beauty.\n");
    set_level(30);
    set_ac(30+random(10));
    set_wc(60+random(20));
set_hp(2500 + random(300));
    set_al(-100);
    set_aggressive(0);
    set_chat_chance(0);
    set_a_chat_chance(0);
    set_dead_ob(this_object());
    add_spell("demonBurst",
      sm+"Treluna screams for P  E  A  C  E  !!!\n"+sm+"You feel disoriented and too sick to fight.\n\n",
      sm+"Treluna screams for P  E  A  C  E  !!!\n"+sm+"#CTN# gives up #TP# attack.\n\n",
      20,100,"other|holy",1,"trelunaPeace");
    add_spell("drain",
      sm+"Treluna rushes in close and kisses you deeply!\n"+sm+"You feel your energy being drained away!\n\n",
      sm+"Treluna rushes in close to #CTN# and kisses #TS# deeply!\n"+sm+"Treluna seems to be energized!\n\n",
      40,({"25d3","15d4"}),({"other|holy","other|dark"}),0,"trelunaDrain");
    set_multi_cast(1);
    set_weapon_params("other|holy",30,0);
  }

}

monster_died() {
  object x;
  object y;
  tell_room(environment(this_object()),
    "Treluna's beauty drains from her body - shriveling into the form of an old hag!\n");
  x = present("corpse",environment(this_object()));
  destruct(x);
  y = clone_object("/players/sparrow/areas/darkGauntlet/npc/treluna2.c");
  move_object(y,environment(this_object()));
  if(attacker_ob && y){
    y->attacked_by(attacker_ob);
  }
  return 0;
}

void trelunaPeace(object att) {
    this_object()->stop_fight();
    this_object()->stop_fight();
    this_object()->stop_hunter();
    att->stop_fight();
    att->stop_fight();
    att->stop_hunter();
  }

  void trelunaDrain(object att) {
  	this_object()->heal_self((random(10)+1)*10);
  }
