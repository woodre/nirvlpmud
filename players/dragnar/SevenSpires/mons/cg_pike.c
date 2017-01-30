inherit "/obj/monster";
#include <ansi.h>
/******************************************************************************
 * Program: pikeman.c
 * Path: /players/dragnar/SevenSpires/mons
 * Type: Mob
 * Created: July 3rd, 2015 by Dragnar
 *
 * Purpose: A mid level monster in the Seven Spires area.
 * History:
 *          10/02/2015 - Gnar
 *            Created
 ******************************************************************************/
 int clone_gold;
 
reset(arg) {

  ::reset(arg);
  if(arg) return;
  SetMultipleIds( ({ "guard","citadel guard" }) );
  set_name("pikeman");
  set_race("human");
  set_short("Pikeman "+HIK+"["+GRN+"Citadel Guard"+HIK+"]"+NORM);
  set_long( 
"Pikemen are the stength of the Citadel Guard. They are the core to\n\
keeping peace and order within the boarders of the Seven Spires. Only\n\
the strongest men with experience as a footman are chosen to join the\n\
ranks of the Pikemen.\n");

  set_gender("male");
  set_level(22);
  set_al(-100);
  clone_gold = random(6);
  
  if( clone_gold ) {
    add_money(random(10000)+1000);
  }
  else
    set_dead_ob(this_object());
  
  set_chat_chance(4);
  load_chat( "Pikeman says: 'Move along.'\n");
  load_chat( "Pikeman says: 'There is unrest in the city, no weapons allowed.'\n");
  load_chat( "The pikeman scans the crowd looking for danger.\n");

}

monster_died() {
  object chips;

  if( !environment() )
    return;

  if( !clone_gold ) {
    chips = clone_object("/players/boltar/casino/floor/chips.c");
    chips->add_chip_value( random(13000) );
    move_object( chips, environment() );
    tell_room( environment(), "As "+query_name()+" dies his casino chips spill on the ground!\n");
}
}
