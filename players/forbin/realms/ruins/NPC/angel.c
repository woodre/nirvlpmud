/*
//  Created:      Forbin@Nirvana
//  Copyright:    Copyright (c) 2004 Forbin
//                  All Rights Reserved.
//  Realm:        The Ruins (/players/forbin/realms/ruins/)
//  Function:     NPC
//  Create Date:  unknown
//  Last Edit:    2004.07.22 -Forbin
//  Notes:        Adapted heavily from original mob
//                  Original Copyright (c) Maledicta@Nirvana
//  Approval:     Fred 2004.07.24
//  Notable Changes:  
//    2004.07.12 -new spell attacks added, [Forbin]
//    2004.07.22 -added #defines for wc/ac bonuses [Forbin]
//    2004.07.28 -daemonized mob to make more memory effecient 
*/ 

#include "/players/forbin/realms/ruins/ruinsdefine.h"
#include "/players/forbin/logging.h"
#pragma combine_strings
inherit "/players/vertebraker/closed/std/monster.c";

int Changed;
string DeathChat;
mixed *Settings;

id(str) { 
  if(Settings) {
    if(Settings[2] == "ice") 
      return (::id(str) || str == "archangel" || str == "demon" ||
                           str == "archangel of ice" || str == "ice");
    if(Settings[2] == "fire") 
      return (::id(str) || str == "archangel" || str == "demon" ||
                           str == "archangel of fire" || str == "fire");
    else  
      return (::id(str) || str == "archangel" || str == "demon");                           
  }
  else  
    return (::id(str) || str == "archangel" || str == "demon");
}

reset(arg)  {
  ::reset(arg);
  if(arg) return;
  Settings = ({ });
}

set_up(int wc, int ac, string type, string wp, string wn) {
  Settings = ({ wc, ac, type, wp, wn });
  "/players/forbin/realms/ruins/NPC/angelbase.c"->initialize(Settings);  
}
  
set_changed(int n) { Changed = n; }
query_changed() { return Changed; }

set_death_chat(string dc) {
  DeathChat = dc;
}

heart_beat() {
/*
  object attacked;
*/
  ::heart_beat();
 /* redundant, caused errors */
/* -verte
  attacked = (this_object()->query_attack());
 */
  /* changed attacked to attacker_ob */
  if(attacker_ob && query_changed() == 0) {
    "/players/forbin/realms/ruins/NPC/angelbase.c"->change(Settings);  
  }
} 

monster_died() {
  object corpse;
  corpse = present("corpse", environment());   
#ifdef KILLLOG
  mon_log(KILLLOG);
#endif
  if(DeathChat) tell_room(environment(this_object()), DeathChat);    
  if(corpse) destruct(corpse);
  return 1; 
}
