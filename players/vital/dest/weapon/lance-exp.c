/******************************************************************************
 *  
 *  File:           lance.c
 *  
 *  Author(s):      Vital@Nirvana
 *  
 *  Copyright:      Copyright (c) 2001 Vital@Nirvana
 *                  All Rights Reserved.
 *  
 *  Source:			Started 4/30/01.
 *  
 *  Notes:			
 *  
 *  Change History: 1/31/02, 2/9/02,
 *  
 *  
 *****************************************************************************/

#include <ansi.h>
#include "/players/vital/closed/headers/vital.h"
#include "/players/vital/dest/include/spaceport.h"

#define COST (5+random(35))

inherit "obj/weapon.c";

int on;
string bleh, blehw, blehbleh, *owners;

reset(arg) {
  ::reset(arg);
  if (arg) return;
  on = 0;
  set_name("lance");
  set_alias("power lance");
  set_short("Power Lance");
  set_long(
"  Power Lance\n\
The Power Lance is a extensible weapon designed for the combat related \n\
defensive maneuvers. It has been designed to help the owner be the \n\
best soldier that they can be in battle. The ability to parry and \n\
defend against attacks with the lance is a hard skill to learn.\n");
  set_type("lance");
  set_class(1);
  set_weight(4);
  set_value(1000+random(100));
  set_hit_func(this_object());
  set_read(BOLD+BLK+"Mark"+NORM+" IV Power Lance\nOperational instructions in main database.\n");
  set_info(
"This fusion power lance can be a formidable weapon for offense when\n\
it is correctly "+HIR+"power"+NORM+"ed "+HIB+"up"+NORM+". There is a small button on the side that\n\
can be "+HIR+"power"+NORM+"ed "+HIB+"up"+NORM+".\n");
}

weapon_hit(attacker) {
    int w, x, y, z;
    string aname;
    aname = C(attacker->query_name());
    w = random(5);
    x = random(100);
    if(!on) return random(4);
    if((z=TP->query_attrib("int")) < 18) {
        z = z/2;
        switch(w) {
            case 0:
                write("The staff twists and turns in your hands.\n");
                say("The staff twists in the hands of "+CTPN+".\n");
                break;
            case 1:
                write("The staff beeps once as it misses.\n");
                say("The staff emits a single beep as it misses "+aname+".\n");
                break;
            case 2:
                write("You lose your grip on the staff.\n");
                say(CTPN+" loses his grip on his weaon.\n");
                break;
            case 3:
                write("You stumble and trip over the staff as you enter combat.\n");
                say(CTPN+" stumbles over the staff and miss.\n");
                break;
            case 4:
                write("There is no damage done to the enemy because you don't have any skill with the staff.\n");
                say("The staff misses "+aname+" completely.\n");
                break;
        }
        z -= w;
        if(z < 0) z = 0;
        return z;
    }
    if(x < ((z*3)/2)) {
        switch(w) {
            case 0:
                write("The staff "+HIY+"glows"+NORM+" and seems to leap for the enemy.\n");
                say("The staff twists in the hands of "+CTPN+" as it leaps for "+aname+".\n");
                break;
            case 1:
                write("You swing the staff around toward "+aname+".\n");
                write("The staff whines loudly as it completes its attack arc.\n");
                say(CTPN+" swings the staff around toward "+aname+".\n");
                say("The staff whines loudly as it completes the attack arc.\n");
                break;
            case 2:
                write("You blast "+aname+" with the power of the staff.\n");
                say(CTPN+" blasts "+aname+" with the power of the staff.\n");
                break;
            case 3:
                write("You crack "+aname+" over the head with the "+HIG+"glowing"+NORM+" end of the staff.\n");
                say(CTPN+" cracks "+aname+" over the head with the "+HIG+"glowing"+NORM+" end of the staff.\n");
                break;
            case 4:
                write("There is a large "+BLINK+YEL+"flash"+NORM+" and a loud pop!\n");
                write(aname+" reels backwards from the power of the staff's attack.\n");
                say("There is a large "+BLINK+YEL+"flash"+NORM+" and a loud pop!\n");
                say(aname+" reels backwards from the power of the staff's attack.\n");
                break;
        }
        z += w;
        if(z > 25) z = z;
        if(z < 1) z = z*z;
        attacker->hit_player(z);
        return z;
    }
    if(((TP->query_attrib("mag"))/2) < (x/10) ) {
        power_down("lance");
        return z;
    }
    return 0;
}

init() {
    ::init();
    add_action("power_up","power");
    add_action("power_down","retract");
    add_action("settings","adjust");
}

settings(string arg) {
    string temp;
    if (!arg)
    {
      notify_fail("You must adjust the owner.\n");
      return 0;
    }
    if(sscanf(arg,"owner %s",temp) != 1) { FAIL("You have to designate \"adjust owner <name>\"\n"); }
    if(!FP(owner)) { FAIL("That person is not around.\n"); }
    if(!sizeof(owner)) owner = ([]);
    owner + temp;
    write(capitalize(temp)+" has been authorized to use the lance.\n");
    return 1;
}
    

power_up(string arg) {
    int x;
    string updown;
    if(!arg) { FAIL("What are you trying to do?\n"); }
    if(sscanf(arg,"%s lance",updown) != 1) { FAIL("You have to "+HIR+"power"+HIB+" up"+NORM+" the lance.\n"); }
    if(updown == "down") { power_down("lance"); return 1; }
    if(!updown || updown != "up") { FAIL("You have to "+HIB+"power"+HIB+" up"+NORM+" the lance.\n"); }
    if(on) {
        write("The lance is already powered up and shocks you.\n");
        TP->heal_self(-COST);
        return 1;
    }
    if(updown == "up" && !on) {
        if((x = TP->query_level()) < 15) {
            set_class(4);
            on = 1;
            short_desc = short_desc + " ["+GRN+"extended"+NORM+"]";
            write("The lance powers up and extends to 150 cm.\n");
            TP->heal_self(-COST/2);
            return 1;
        }
        set_class(3);
        on = 1;
        short_desc = short_desc + " ["+GRN+"extended"+NORM+"]";
        TP->heal_self(-COST);
        write("The lance powers up and extends to 150 cm.\n");
    }
    return 1;
}

power_down(str) {
    if(!str || str != "lance") { FAIL("You have to "+HIG+"retract"+NORM+" or "+HIR+"power"+NORM+" down the lance.\n"); }
    if(!on) {
        write("The lance is not powered up. The feedback from the lance shocks you.\n");
        TP->heal_self(-COST);
        return;
    }
    set_class(1);
    on = 0;
    write("The lance powers down and collapses to 25 cm.\n");
    short_desc = "Power Lance";
    return 1;
}

query_save_flag() {
    if(on) {
        write("You cannot store the lance if it is powered up!\n");
        return 1;
    }
}

