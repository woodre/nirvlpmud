/*****************************************************************************
 *      File:                   zombieDM.c
 *      Function:               Common functionality for zombies
 *      Author(s):              Mizan@Nirvana
 *      Copyright:              Copyright (c) 2011 Mizan@Nirvana
 *                              All Rights Reserved.
 *      Source:                 2/2011
 *      Notes:                 
 *      Change History:         
 ****************************************************************************/
#include "../definitions.h"
string *my_zombie_types;

get() {
    return 0;
}
short() {
    return "A server named (zombie)";
}
id(str) {
    return str == "zombie" || str == "server";
}


string get_zombie_type() {
    return my_zombie_types[random(sizeof(my_zombie_types))];
}

void reset(int arg)
{
    /* move ourselves home. */
    move_object(this_object(), DAEMON_HOME);

    if (!arg)
    {
        my_zombie_types = ( {
	"horse",
	"wombat",
	"office worker",
	"plumber",
	"nuclear power technician",
	"line chef",
	"police officer",
	"pornstar",
	"garbageman",
	"meat packer",
	"senator",
	"baker",
	"street vendor",
	"nosepicker",
	"photographer",
	"plastic surgeon",
	"dentist",
	"homeless guy",
	"alcoholic",
	"meth dealer",
	"used car salesman",
	"fishmonger",
	"auto mechanic",
        });
    }
}

