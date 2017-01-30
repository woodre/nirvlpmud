/******************************************************************************
 *  File:           memorial.c
 *  Author(s):      Vital@Nirvana
 *  Copyright:      Copyright (c) 2003 Vital@Nirvana
 *                  All Rights Reserved.
 *  Source:			Started 9/24/03.
 *  Notes:			
 *  Change History: 
 *****************************************************************************/


#include "/players/vital/closed/headers/ansi.h"

inherit "/players/vital/closed/std/obj.c";

reset(arg) {
   if(arg) return;
   set_id(({"memorial", "Memorial", "The Memorial", "the memorial", "dreamspeakr"}));
   set_name("the memorial");
   set_alias("dreamspeakr\'s memorial");
   set_short("A " + HIW + "Memorial" + NORM + " to " + HIM + "Dreamspeakr" + NORM);
   set_long("This is a small " + HIW + "memorial" + NORM + " to the player and wizard that many \nof us knew and loved. If you didn't know her, we invite you to \ntake a moment to " + BLU + "visit" + NORM + " her " + BLU + "memorial" + NORM + " and read the thoughts \nof those whose lives she touched. Also, you are invited to \n" + YEL + "visit" + NORM + " her " + YEL + "realm" + NORM + " and carefully read her descriptions. \nThere is a part of her in everything she touched.\n");
   set_weight(1000);
   set_value(0);
   set_info("This Memorial is dedicated to the life of Dreamspeakr.\n");
   set_read("In Honor of One Who Has Gone Before.\n");
}

init() {
    ::init();
    add_action("go_dreamspeakr","visit");
    add_action("go_dreamspeakr","visit");
}

go_dreamspeakr(str) {
    if(str && str == "memorial") {
        this_player()->move_player("heads off to honor Dreamspeakr\'s Memory#players/jenny/memorial/field.c");
        return 1;
    }
    if(str && str == "realm") {
        this_player()->move_player("heads off to visit Dreamspeakr\'s realm#players/dreamspeakr/CASTLE/entrance.c");
        return 1;
    }
        notify_fail("Where did you want to visit?\n\tvisit memorial\n\tvisit realm\n");
        return 0;
}

get() { return 0; }

