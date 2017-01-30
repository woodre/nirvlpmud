/*
 *  A bubble (light source?) for Bards.
 *  Bard v3.0
 */

#include "/players/saber/closed/esc2.h"
#define HIB ESC+"[1;34m"
#define NORM ESC+"[2;37;0m"
inherit "obj/treasure";

reset(arg)  {
  if (arg) return;
    set_id("bubble");
    set_short("A luminous "+HIB+"blue"+NORM+" bubble");
    set_long("A small, luminous "+HIB+"blue"+NORM+" bubble.\n"+
      "It is "+HIB+"glowing"+NORM+" with the intensity of a torch.\n");
    set_weight(0);
    set_light(1);
        }
