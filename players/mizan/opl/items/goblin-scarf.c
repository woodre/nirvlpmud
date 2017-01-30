/*****************************************************************************
 *      File:                   goblin-scarf.c
 *      Function:               An expensive item which keeps goblins from
 *                              going aggro on sight
 *      Author(s):              Mizan@Nirvana
 *      Copyright:              Copyright (c) 2011 Mizan@Nirvana
 *                              All Rights Reserved.
 *      Source:                 2/2011
 *      Notes:
 *      Change History:
 ****************************************************************************/

inherit "obj/armor";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_short("A green scarf of Suffering");
    set_long("This is a worn-out, smelly scarf which smells like goblin body odor and poop.\n"+
    "There is a logo of two interlocking 'G's, and the words 'Gangsta Life' drawn crudely\n"+
    "with a magic marker across the bottom half of the scarf.\n");
    set_ac(1);
    set_weight(1);
    set_value(600);
    set_name("scarf");
    set_alias("goblin-scarf");
    set_type("neck");
}

query_save_flag() { return 1; }
