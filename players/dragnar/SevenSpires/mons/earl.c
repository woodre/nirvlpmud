inherit "/obj/monster";
#include <ansi.h>
/******************************************************************************
 * Program: earl.c
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
  SetMultipleIds( ({ "earl the wagon master","wagon master","master" }) );
  set_name("earl");
  set_race("human");
  set_short("Earl the Wagon Master");
  set_long( "Earl is the leader of the wagon train. His people look to him in\n\
times of need for help. If he spends all of his hard work at the\n\
casino instead of taking care of his family, that doesn't make\n\
him a bad guy does it?\n");

  set_gender("male");
  set_level(20);
  set_al(-300);
  set_dead_ob(this_object());
  
  set_chat_chance(9);
  load_chat( "Earl says: 'Wanna make a wager?'\n");
  load_chat( "Earl says: 'If the weather holds, I'll be playing cards tomorrow!'\n");
  load_chat( "Earl pulls out a casino chip from his pocket, rubs it,\n\
and quickly puts it back into his pocket with a smile.\n");

}

monster_died() {
  object chips;

  if( !environment() )
    return;

  chips = clone_object("/players/boltar/casino/floor/chips.c");
  chips->add_chip_value( 3000 + random(3000) );
  move_object( chips, environment() );
  tell_room( environment(), "As "+query_name()+" dies his casino chips spill on the ground!\n");
}
