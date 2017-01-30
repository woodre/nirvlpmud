/* sion_boots.c

    found on ~/kotor/mon/sion.c
    provide good ac and other|laser resistance
    also provide physical resistance
    
*/

#include "/players/illarion/dfns.h"
inherit "obj/armor";

void reset(status arg) {
  ::reset(arg);
  if(arg) return;
  
  set_name(boots);
  set_short(HIK+"Darth "+HIR+"Sion"+NORM+"'s banded boots");
  set_class(2);
  set_res(10);
  set_params("other|laser",0,15,0);
  set_weight(3);
  set_value(10000);
}

query_kotor_barter() { return 1; }