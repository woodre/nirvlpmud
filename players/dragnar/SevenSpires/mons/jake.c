inherit "/obj/monster";
#include <ansi.h>
/******************************************************************************
 * Program: jake.c
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
  SetMultipleIds( ({ "jake the trail hand" }) );
  set_name("jake");
  set_race("human");
  set_short("Jake the Trail Hand");
set_long(
"Jake is a man past his prime who has a lived a rough life in the\n\
great outdoors. He looks like your typical coyboy with the attire\n\
to match. He looks a little hard on his luck though, his cowboy\n\
gear is in bad shape and you can't see anything of value on him.\n");

  set_gender("male");
  set_level(17);
  set_al(-100);
  set_dead_ob(this_object());
  
  set_chat_chance(9);
  load_chat( "Jake says: 'Damn casino, I lost everything I own.'\n");
  load_chat( "Jake grumbles under his breath about being down to his last few chips.\n");
  load_chat( "Jake asks you: 'Can I borrow a few coins?\n\
He quickly adds: 'I can pay it back right quick!'\n");
  load_chat( "Jake pulls out a casino chip from his pocket, rubs it,\n\
and quickly puts it back into his pocket with a smile.\n");

}

monster_died() {
  object chips;

  if( !environment() )
    return;

  chips = clone_object("/players/boltar/casino/floor/chips.c");
  chips->add_chip_value( 500 + random(3000) );
  move_object( chips, environment() );
  tell_room( environment(), "As "+query_name()+" dies his casino chips spill on the ground!\n");
}
