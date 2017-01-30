inherit "obj/armor";
/******************************************************************************
 * Program: fboots.c
 * Path: /players/dragnar/SevenSpires/armor
 * Type: Object
 * Created: August 28th, 2015 by Dragnar
 *
 * Purpose: Boots that enhance wc but have no ac or special.
 *
 * History:
 *          08/28/2015 - Dragnar
 *            Created
 ******************************************************************************/
#include <ansi.h>

reset(arg){
  ::reset(arg);
  set_short(RED+"Boots of Fortitude"+NORM);
  set_long(
"A pair of simple combat boots stained with the blood of battle.\n\
They have been blessed by magic to aid in the strength of your\n\
physical attacks by an unknown Mage of great power.\n");
  set_ac(0);
  set_weight(1);
  set_value(1500);
  set_name("boots");
  SetMultipleIds( ({ "generic_wc_bonus","boots of fortitude","spireobj" }) );
  set_type("boots");
}

gen_wc_bonus() {
  int ret;
  if( !environment() || !environment()->is_player() || environment()->query_level() < 15 || !query_worn() )
    return 0;

  ret = 1;
  if( !random(25) ) {
    tell_object( environment(), RED+"\tYour boots aid in the strength of your attack!\n"+NORM);
    ret++;
  }
  return environment()->query_prestige_level() > random(10) ? 2+ret : ret;
}
