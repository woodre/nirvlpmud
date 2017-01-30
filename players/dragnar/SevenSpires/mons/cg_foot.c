inherit "/obj/monster";
#include <ansi.h>
/******************************************************************************
 * Program: cg_foot.c
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
  set_name("footman");
  set_race("human");
  set_short("Footman "+HIK+"["+GRN+"Citadel Guard"+HIK+"]"+NORM);
  set_long( 
"Footmen form the bulk of the Citadel Guard. Almost every new member\n\
of the Guard starts as a Footman to learn the basics of military\n\
life. Although some lack experience, the Guard will only accept\n\
men that have some level of training and a strong arm.\n");

  set_gender("male");
  set_level(21);
  set_al(-100);
  clone_gold = random(4);
  
  if( clone_gold ) {
    add_money(random(8000)+2000);
  }
  else
    set_dead_ob(this_object());
  
  set_chat_chance(4);
  load_chat( "Pikeman says: '.'\n");
  load_chat( "Footman says: '.'\n");
  load_chat( "The footman grumbles under his breath about his sergeant.\n");
  load_chat( "The footman grumbles under his breath about the weather.\n");

}

monster_died() {
  object chips;

  if( !environment() )
    return;

  if( !clone_gold ) {
    chips = clone_object("/players/boltar/casino/floor/chips.c");
    chips->add_chip_value( random(12000) );
    move_object( chips, environment() );
    tell_room( environment(), "As "+query_name()+" dies his casino chips spill on the ground!\n");
}
}
