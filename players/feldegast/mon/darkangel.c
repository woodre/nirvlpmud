/*
File: darkangel.c
Author: Feldegast
Date: 04/09/02
Description:
  A dark angel who guards an altar at the abandoned cathedral in Calador.
*/
#include "defs.h"

inherit "/obj/monster2.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("mezynix");
  set_alt_name("angel");
  set_alias("dark angel");
  set_short(HIM+"Mezynix"+NORM+", the "+BOLD+BLK+"Dark Angel"+NORM);
  set_long(
    "Mezynix is a dark angel, a powerful captain in the ranks of demonkind.\n"+
    "Although his face appears earily handsome, his mouth is covered in the\n"+
    "dried blood of his mortal victims.  His body is wrapped in dark armor\n"+
    "and his gauntlets end in shiny steel claws.  A pair of black, leathery\n"+
    "wings extend from his back.\n"
  );
  set_gender("male");
  set_race("demon");
  set_level(23);
  set_wc(40);
  set_ac(21);
  set_hp(2000);
  set_al(-1000);
  add_special("hb_aggro", ({ 50, 2 }));
  load_spell(25,50,"other|fire",
    HIR+"\nThe dark angel throws a wave of flame at you!\n\n"+NORM,
    HIR+"\nThe dark angel throws a wave of flame at %NAME%!\n\n"+NORM);
  load_spell(25,55,"other|evil",
    BOLD+BLK+"\n\nThe dark angel's eyes blaze with darkfire!\n\n"+NORM,
    BOLD+BLK+"\nThe dark angel's eyes blaze with darkfire at %NAME%!\n\n"+NORM);
  add_special("area_attack",
    ({
      10,45,
      RED+"The dark flames lash you!\n"+NORM,
      BOLD+BLK+"\nThe "+BOLD+BLK+"Dark Angel"+NORM+" summons a "+BOLD+"rain of darkfire!\n"+NORM,
      "other|evil", 0
    }));

}

void heart_beat()
{
  ::heart_beat();
  if(!random(40))
  {
    say(short()+" waves his hand.\n");
    environment()->set_field(1);
  }
}
