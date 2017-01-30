/*  TRINKET.C - Carried by GIRL.C in EASTHALL.C of Delnoch Keep
*/
#include "/players/traff/closed/ansi.h"
inherit "obj/treasure";
string extra_look;

reset(arg)  {
  if(arg) return;
  set_id("trinket");
  set_short("A small trinket");
  set_long("A pretty little trinket.  You think you might be able to sell it.\n");
  set_weight(2);
  set_value(random(100)+25);
}
extra_look()  {
  object ex_look;
  ex_look = environment(this_object())->query_name();
  write(ex_look+" has a touch of "+BLU+"CLASS"+NORM+"!\n");
        }
