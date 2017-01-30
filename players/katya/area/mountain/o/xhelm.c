/*
 *     xhelm.c             
 *     Katya@Nirvana
 *     Copyright (c) 2007 Katya
 *     All Rights Reserved.
 *    
 */


#include <ansi.h>
inherit "obj/armor";

reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_name("Xiulicoatl's Helm");
    set_alias("helm");
    set_short("Xiulicoatl's Helm");
    set_long("The blue dragons helmet is made out of Xiulicoatl's head.\n");
    set_type("helmet");
    set_weight(1);
    set_ac(2);
    set_value(1500);

}

