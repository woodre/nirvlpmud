/******************************************************************************
 *  
 *  File:           blaster.c
 *  
 *  Author(s):      Vital@Nirvana
 *  
 *  Copyright:      Copyright (c) 1997 Vital@Nirvana
 *                  All Rights Reserved.
 *  
 *  Source:			Started 1/25/01.
 *  
 *  Notes:			
 *  
 *  Change History: 
 *  
 *  
 *****************************************************************************/

#include <ansi.h>
#include "/players/vital/closed/headers/vital.h"
#include "/players/vital/dest/include/spaceport.h"

inherit "obj/weapon.c";

reset(arg) {
  ::reset(arg);
  if (arg) return;

  set_name("blaster");
  set_alias("husky");
  set_short("Husky Mk VI");
  set_id("blaster");
  set_long("  This is the universally famous Husky Mk VI blaster. It has \n\
been the standard issue weapon for many militaries, militias and \n\
mercenaries. It is simple in design and functionality. The barrel \n\
is a short length of clear plass and mounted in a black resin stock. \n\
There is a place along the side and bottom where the blaster can \n\
be upgraded.\n"  );
  set_type("blaster");
  set_class(15);
  set_weight(3);
  set_value(1000+random(200));
}

init() {
    ::init();
    add_action("upgrade_me","upgrade");
}

parts_check() {
    object upgradePart;
    string junka, junkb, junkc, part;
    upgradePart = present("upgrade_part",TP);
    junka = file_name(upgradePart);
    sscanf(junka,"%s#%s",junkb,junkc);
    if(junkb != DEST+"obj/part1.c") {
        write("You are missing an important piece required for the upgrade'\n");
        return 0;
    }
    part = upgradePart->query_short();
    write("You take the Husky Mk VI Blaster in one hand and the "+part+" in your other hand.\n");
    return 1;
}

intell_check() {
    int x;
    x = environment()->query_attrib("int");
    if(x < 18) {
        write("You cannot seem to figure out how to upgrade the blaster.\n");
        write("The whole process would be better accomplished by someone smarter.\n");
        return 0;
    }
    write("You intuitively know how the pieces fit together to upgrade the weapon.\n");
    return 1;
}

upgrade_me(string str) {
    object newBlaster;
    int x, y;
    x = parts_check();
    y = intell_check();
    if(!str) {
        notify_fail("What are you trying to upgrade?\n");
        return 0;
    }
    if(str == "blaster") {
        if(x) {
        if(y) {
        newBlaster = clone_object(DEST+"weapon/blaster2.c");
        write("You slide the upgrade into the blaster and are rewarded with a stronger weapon.\n");
        move_object(newBlaster, environment());
        destruct(this_object());
        return 1;
        }
        }
    }
    write("You were unable to upgrade the Husky Mk VI for some reason.\n");
    return 0;
}
