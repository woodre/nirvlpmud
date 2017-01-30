inherit "/obj/monster";
#include <ansi.h>
/******************************************************************************
 * Program: wagoner.c
 * Path: /players/dragnar/SevenSpires/mons
 * Type: Mob
 * Created: July 3rd, 2015 by Dragnar
 *
 * Purpose: A mid level monster in the Seven Spires area.
 * History:
 *          07/03/2015 - Gnar
 *            Created
 ******************************************************************************/
 
reset(arg) {

  ::reset(arg);
  if(arg) return;
  set_name("wagoner");
  set_race("human");
  set_short("A wagoner");
set_long(
"A member of the wagon train who helps with the day to day needs\n\
of the animals and chores that need to be done. A sad creature,\n\
taken advantage of by the wagon master who pays a pittance all\n\
in worthless casino chips.\n");

  if( !random(2) ) {
    set_gender("male");
    set_al(-50);
    set_level(16);
  }
  else {
    set_gender("female");
    set_al(0);
    set_level(13);
  }
  set_dead_ob(this_object());
  

}

monster_died() {
  object chips;

  if( !environment() )
    return;

  chips = clone_object("/players/boltar/casino/floor/chips.c");
  chips->add_chip_value( 500 + random(1000) );
  move_object( chips, environment() );
  tell_room( environment(), "As the "+query_name()+" dies their casino chips spill on the ground!\n");
}
