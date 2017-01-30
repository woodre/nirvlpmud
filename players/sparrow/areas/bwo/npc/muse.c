/*****************************************************************************
 *      File:                   muse.c
 *      Function:               Muse
 *      Author(s):              Sparrow@Nirvana
 *      Copyright:              Copyright (c) 2006 Sparrow 
 *                              All Rights Reserved.
 *      Source:                 9/21/06
 *      Notes:                 
 *      Change History:         
 ****************************************************************************/
#include "/sys/ansi.h"
inherit "/players/sparrow/areas/bwo/include/mob_funcs.c";
inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("muse");
    set_alias("taker");
    set_short("Muse - the Taker");
    set_race( "machine");
    set_long("\n");
    set_level(22);
    set_ac(18+random(5));
    set_wc(36+random(5));
    set_hp(700+random(200));
    set_al(0);
    set_aggressive(0);
    set_chat_chance(7);
    set_a_chat_chance(10);
    load_chat("The Taker takes something!\n");
    load_a_chat("Muse grins at you!\n");
    set_weapon_params("other|electric",20,"gut_punch");
  }
}
