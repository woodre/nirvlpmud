/*****************************************************************************
 *      File:                   wookie=-translator.c
 *      Function:               An expensive item which makes it possible to
 *                              understand the wookies in the fungal forest
 *      Author(s):              Mizan@Nirvana
 *      Copyright:              Copyright (c) 2011 Mizan@Nirvana
 *                              All Rights Reserved.
 *      Source:                 2/2011
 *      Notes:
 *      Change History:
 ****************************************************************************/
inherit "/players/mizan/core/object.c";
#include "/obj/ansi.h"

reset(arg)
{
    ::reset(arg);
    if(arg) return;

    set_get(1);
    set_value(10);
    set_weight(1);
    
    set_name("stick");
    set_alias("wookiee-translator");

    set_short("A small wooden stick");
    set_long("This is a small wooden stick that has been hollowed out.\n"+
            "It smells rather funny, and there is a brass label nailed into it.\n");

    set_read("A label on the stick reads: Wookiee Translator, Mk. II\n");
    set_smell("The stick smells like something you stepped on yesterday.\n");
    set_taste("Don't do that. You look silly.\n");
}

query_save_flag() { return 1; }
