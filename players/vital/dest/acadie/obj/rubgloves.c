/******************************************************************************
 *  
 *  File:           rubgloves.c
 *  
 *  Author(s):      Vital@Nirvana
 *  
 *  Copyright:      Copyright (c) 2001 Vital@Nirvana
 *                  All Rights Reserved.
 *  
 *  Source:			Started 4/27/01.
 *  
 *  Notes:			Small hit_player and low AC ring type
 *  
 *  Change History: 
 *  
 *  
 *****************************************************************************/

#include <ansi.h>
#include "/players/vital/closed/headers/vital.h"
#include "/payers/vital/dest/include/dest.h"

inherit "/obj/armor";

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("glove");
   set_alias("rubber glove");
   set_short("Rubber Glove");
   set_long("A single rubber, latex glove used in body cavity exams.\n");
   set_ac(1);
   set_type("ring");  /* armor,helmet,boots,ring,amulet,shield,misc  */
   set_weight(2);
   set_value(200+random(250));
}

do_special(owner) {
    int x;
    object attacker;
    attacker = (object)environment()->query_attack();
    if(!attacker) return 0;
    x = 1+random(10);
    if(!random(12)) {
        switch(random(4)) {
            case 0: tell_object(owner, "You inflict "+HIR+"pain"+NORM+" on the enemy with a full body-cavity search.\n");
                    say(CTPN+" inflicts serious "+HIR+"pain"+NORM+" on "+C(attacker->query_name())+".\n");
                    break;
            case 1: tell_object(owner, "You "+HIM+"violate"+NORM+" the enemy's dignity.\n");
                    say(CTPN+HIM+" violates"+NORM+" "+C(attacker->query_name())+".\n");
                    break;
            case 2: tell_object(owner, "Your Internal Inspection only increases the enemy's discomfort.\n");
                    say(CTPN+" increases the pain that "+C(attacker->query_name())+" feels.\n");
                    break;
            case 3: tell_object(owner, "You show "+C(attacker->query_name())+" where the sun doesn't shine.\n");
                    say(CTPN+" shows "+C(attacker->query_name())+" where the sun doesn't shine.\n");
                    break;
        }
        attacker->hit_player(x);
        return 1;
    }
}
