/*
 ~  Sigil guild daemon
 */

#include "/players/cosmo/closed/ansi.h"
#include "daemon.h"

/* Combat Abilities */

#include "power/set_power.h"
#include "power/invoke.h"
#include "power/cone.h"


/* Misc Abilities */

#include "power/ghelp.h"
#include "power/gwho.h"
#include "power/channel.h"
#include "power/new_sc.h"


/* Utility Functions */

query_pmess() {
/* Used in the gob long() to display the powerlevel */
int plvl;
  plvl = TPGO->query_plevel();
  if(level < 10){
    if(plvl < 4) return "low";
    else if(plvl < 7) return "medium";
    else if(plvl < 11) return "high";
    else return "error";
  }
  else if(level < 15){
    if(plvl < 6) return "low";
    else if(plvl < 11) return "medium";
    else if(plvl < 16) return "high";
    else return "error";
  }
  else if(extralevel < 5){
    if(plvl < 8) return "low";
    else if(plvl < 15) return "medium";
    else if(plvl < 21) return "high";
    else return "error";
  }
  else if(extralevel > 4){
    if(plvl < 9) return "low";
    else if(plvl < 18) return "medium";
    else if(plvl < 21) return "high";
    else if(plvl > 20) return "overload";
    else return "error";
  }
  else return "error";
}

query_dam1_msg(int num) {
/* Used in invoke.h and cone.h to get appropriate damage msgs */
mapping map;
  map = TPGO->query_major_info();
  switch(num){
    case 45..1000: return map["dam1"];
    case 40..44: return map["dam2"];
    case 33..39: return map["dam3"];
    case 27..32: return map["dam4"];
    case 17..26: return map["dam5"];
    case 10..16: return map["dam6"];
    case 5..9: return map["dam7"];
    case 1..4: return map["dam8"];
    default: return "missed";
  }
}

query_dam2_msg(string str) {
/* Used in invoke.h and cone.h to get appropriate damage msgs */
mapping map;
  map = TPGO->query_major_info();
  switch(random(100)+1){
    case 75..1000: return map[str+"msg1"];
    case 50..74: return map[str+"msg2"];
    case 25..49: return map[str+"msg3"];
    case 1..24: return map[str+"msg4"];
    default: return map[str+"msg4"];
  }
}

int filter_invis(object who){
     if(!environment(who)){ return 0; }
     if(TP->query_level() < who->query_invis()) return 0;
     return 1;
}
int filter_sigil(object who){
     if(!present("SIGIL_OB", who)) return 0;
     return 1;
}
