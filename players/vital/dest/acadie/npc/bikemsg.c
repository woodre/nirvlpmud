/******************************************************************************
 *  
 *  File:           bikemsg.c
 *  
 *  Author(s):      Vital@Nirvana
 *  
 *  Copyright:      Copyright (c) 2001 Vital@Nirvana
 *                  All Rights Reserved.
 *  
 *  Source:			Started 8/29/01.
 *  
 *  Notes:			
 *  
 *  Change History: 
 *  
 *  
 *****************************************************************************/

#include <ansi.h>
#include "/players/vital/closed/headers/vital.h"
#include "/players/vital/dest/include/dest.h"

inherit "/players/vital/closed/std/monster.c";
string grace;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("messenger");
  set_alt_name("bike messenger");
  set_alias("bike");
  set_short("Bike Messenger");
  set_long("\
  The bicycle messenger is out and about delivering messages to all \n\
manner of individuals and businesses.\n");
  set_gender("female");
  set_race(get_race());
  set_level(15+random(2));
  set_ac(2);
  set_al(275);
  set_wander(2,1,({}));
  set_attrib("wil",20);
  set_attrib("sta",25);
  set_spell_mess1("The bicycle messenger is livid with "+RED+"rage"+NORM+".\n");
  get_spell_mess2();
}

id(str) { return str == "Messenger" || str == "Bicycle Messenger" || str == "Biker" || str == name || str == alias || str == race || str == alt_name; }

get_spell_mess2() {
    switch(random(4)) {
        case 0: return "The bicycle messenger reaches out and punches "+CTPN+" in the face.\n";
        case 1: return "Bike Messenger screams at "+CTPN+".\n";
        case 2: return "The bicycle messenger places his bike between "+CTPN+" and himself.\n";
        case 3: return "The bicycle messenger runs over "+CTPN+"\'s toes.\n";
    }
}

get_race() {
    switch(random(5)) {
        case 0: grace = "human"; break;
        case 1: grace = "simbari"; break;
        case 2: grace = "krondaku"; break;
        case 3: grace = "poltroyan"; break;
        case 4: grace = "gi"; break;
    }
    return grace;
}
