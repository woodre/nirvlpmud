/*
 *  Created:      Forbin@Nirvana
 *  Copyright:    Copyright (c) 2004 Forbin
 *                  All Rights Reserved.
 *  Realm:        The Ruins (/players/forbin/realms/ruins)
 *  Function:     object that prevents printing message_hit
 *  Create Date:  2004.07.12
 *  Last Edit:    2004.07.12 -Forbin
 *  Notable Changes:
 */ 

#include "/players/forbin/define.h"
inherit "obj/treasure";

id(str) { return (::id(str) || str == "no_msg_hit"); }

reset(arg) {
  if(arg) return;
}

get() { return 1; }

drop() { return 1; }

can_put_and_get() { return 0; }
