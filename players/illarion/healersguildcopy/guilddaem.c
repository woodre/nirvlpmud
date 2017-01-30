#include "def.h"
#include "cost.h"
string cast_bless;
string min_bless;                               
                               
  /* power includes */

#include "power/need.h"
#include "power/holy_blessing.h"
#include "power/help.h"
#include "power/titler.h"
#include "power/check.h"
#include "power/history.h"
#include "power/heal.h"
#include "power/peace.h"
#include "power/fortify.h" 
#include "power/mystic_transfer.h" 
#include "power/cure.h"
#include "power/defend.h"
#include "power/shield.h"
#include "power/reduce.h"
#include "power/resurrect.h" 
#include "power/mass_heal.h"
#include "power/simulcrum.h" 
#include "power/potion.h"
#include "power/reinstate.h" 
#include "power/regenerate.h"
#include "power/cove.h"
#include "power/full_heal.h" 
#include "power/haven.h" 
#include "power/salve.h" 
#include "power/grant.h" 
#include "power/healing_spring.h"
#include "power/bless.h"
#include "power/robe_of_healing.h"


reset(arg) {
if(ep) { destruct(TO); return 1; }
  min_bless = ({"GUILDDAEM"});
  if(arg) return;
  LLL = LVL = LVV = 0;
  cast_bless = ({"GUILDDAEM"});
  reset_m();
}



