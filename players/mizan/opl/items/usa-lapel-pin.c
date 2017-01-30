/*****************************************************************************
 *      File:                   usa-lapel-pin.c
 *      Function:               An expensive item which prevents the soldiers
 *                              from going aggro
 *      Author(s):              Mizan@Nirvana
 *      Copyright:              Copyright (c) 2011 Mizan@Nirvana
 *                              All Rights Reserved.
 *      Source:                 2/2011
 *      Notes:
 *      Change History:
 ****************************************************************************/

inherit "obj/armor";
#include "/obj/ansi.h"
reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_short("An " + HIR + "American" + NORM + " " + HIB + "Flag" + NORM + " " + HIW + "lapel pin" + NORM);
    set_long("This is a small lapel pin depicting an American flag.\nOn the back it says 'Made in China'.\n");
    set_ac(1);
    set_weight(1);
    set_value(500);
    set_name("pin");
    set_alias("usa-lapel-pin");
    set_type("neck");
}

query_save_flag() { return 1; }
