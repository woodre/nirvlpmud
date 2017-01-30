inherit "/obj/monster";
#include <ansi.h>
/******************************************************************************
 * Program: ffish.c
 * Path: /players/dragnar/SevenSpires/mons
 * Type: Mob
 * Created: October 22nd, 2014 by Dragnar
 *
 * Purpose: A mid level monster in the Seven Spires area. 
 * History:
 *          10/05/2015 - Dragnar
 *            Created
 ******************************************************************************/
 int school_members;
 
reset(arg) {
  ::reset(arg);
  if(arg) return;
  SetMultipleIds( ({ "school","flasher fish","school of flasher fish", }) );
  set_name("fish");
  set_race("fish");
  set_short("A "+HIW+"School of Flasher Fish"+NORM);
  set_level(20);
  school_members = 10 + random(10);
  set_wc_bonus( weapon_class * school_members );
  set_long(
"A vicious school of flasher fish.\n\
This school has around "+school_members+" members in it.\n");
    set_gender("creature");
  set_wander_realm("/players/dragnar/SevenSpires/rooms/forest");
}

init() {
  
  ::init();
  if( !this_player() || !environment() )
    return;
  
  attacker_ob = this_player();
  tell_room( environment(), HIW+"The Flasher Fish attack with vicious speed!\n");
  
}

heart_beat() {
  int i;
  ::heart_beat();
  for( i=0; i < school_members; i++) {
    already_fight=0;
    attack();
  }
}
