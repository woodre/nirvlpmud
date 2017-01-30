/*
File: talismanf.c
By: Feldegast @ Nirvana
Updated: 03-21-02
Description:
  Talisman of Fire.  An amulet with fire resistance, found
on the orcish shaman in Caladon.
*/
#include "/players/feldegast/defines.h"

inherit "obj/armor";

reset(arg) {
  ::reset(arg);

  if(arg) return; 

  set_name("talisman of fire");
  set_alias("talisman");
  set_short(BOLD+"Talisman"+NORM+" of "+HIR+"Fire"+NORM);
  set_long(
    "This is a metal talisman with a tear-drop shaped fire symbol etched\n"+
    "on it.  It offers powerful protection against fire based attacks.\n"
  );
  set_weight(1);
  set_value(1300);

  set_ac(1);

  /* 1% resistance to physical damage. */
  set_res(1);

  set_type("amulet");  /* armor,helmet,boots,ring,amulet,shield,misc  */

  /*
    This line sets up an ac to fire of 3, a resistance to fire of 3%,
    and a special function called fire_special. 
  */

  set_params("other|fire",3,3,"fire_special");
  set_params("other|laser",3,3,"do_special");
}


do_special(owner) {
  if(!random(12)) {
    tell_object(owner, "Your Talisman glows protectively.\n");
    if(this_player() && this_player()!=owner)
      write(owner->query_name()+"'s Talisman glows protectively.\n");
    return 2;
  }
}

/*
This function is called when the owner receives damage from a fire
based attack.  The return amount is added to the player's ac.
*/
fire_special(owner) {
  if(!random(5)) {
    tell_object(owner, "Your crystal amulet glows intensely!\n");
    return 4;
  }
  if(!random(20)) {
    tell_object(owner, HIW+"Your Talisman glows as it protects you from the heat.\n"+NORM);
    return 1000; /* This is 10% resistance.  Not 1000 ac! */
  }
  if(!random(20)) {
    tell_object(owner, HIR+"Your Talisman glows as it protects you from the heat.\n"+NORM);
    return 1001; /* This is 10% resistance and a bonus ac of 1. */
  }

}

