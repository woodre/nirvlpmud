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
    set_name("billy club");
    set_short("A Billy Club");
    set_long("This is a standard issue billy club, black in color\n"+
             "with a circle of rope, called a sabre knot, at the\n"+
             "end to wrap around your wrist.\n");
    set_type("club");
    set_class(14);
    set_weight(2);
    set_value(700);

}
