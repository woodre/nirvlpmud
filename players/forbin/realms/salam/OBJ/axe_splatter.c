/*  Forbin | Create date:  jun2002.24 | Last mod:  jun2002.27  */

/*
 *  Created:      Forbin@Nirvana
 *  Copyright:    Copyright (c) 2004 Forbin
 *                  All Rights Reserved.
 *  Realm:        Caves of the Salamite
 *  Function:     Atmosphere
 *  Create Date:  2002.06.24
 *  Last Edit:    2004.06.05 -Forbin
 *  Notes:        Cloned to players when they use:
 *                /playesr/forbin/realms/salam/OBJ/neruumsh.c
 *  Notable Changes:
 */

#include "/players/forbin/realms/salam/salamdefine.h"

id(string str) { return str == "neruumsh_axe_splatter"; }

extra_look() {
  if (this_player() == environment())
    return "You are covered in "+RED+"blood"+NORM+" and "+RED+"gore"+NORM+"";
  else
    return ""+environment()->query_name()+" is covered in "+RED+"blood"+NORM+" and "+RED+"gore"+NORM+"";
}

status get()  { return 1;}

status drop() { return 1;}

init() {
  call_out("destroy_me", 300);
}

destroy_me() {
  destruct(this_object());
    return 1;
}