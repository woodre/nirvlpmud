/*
//  Created:      Tristian@Nirvana
//  Copyright:    Copyright (c) 2005 Tristian
//                  All Rights Reserved.
//  Function:     Weapon
//  Create Date:  2006.10.08
*/

#include "/players/tristian/lib/ClubFeddefine.h"
inherit "/obj/weapon.c";

void reset(int arg) { 

    ::reset(arg);
     if(arg) return;
    set_name("shiv");
    set_short("A Prison Shiv");
    set_long("This is a crude homemade stabbing weapon.  It is a piece\n"+
             "of the bed spring, sharpened and wrapped with strands of\n"+
             "hair and tape to form a handle.\n");
    set_type("dagger");
    set_class(14);
    set_weight(2);
    set_value(700);

}
