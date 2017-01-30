/******************************************************************************
 *  
 *  File:           pimp.c
 *  
 *  Author(s):      Vital@Nirvana
 *  
 *  Copyright:      Copyright (c) 2001 Vital@Nirvana
 *                  All Rights Reserved.
 *  
 *  Source:			Started 9/20/01.
 *  
 *  Notes:			"I'm a Bad, Bad Man"
 *  
 *  Change History: 
 *  
 *  
 *****************************************************************************/

#include "/players/vital/dest/include/dest.h"
#include <ansi.h>
#include "/players/vital/closed/headers/vital.h"

inherit "/players/vital/closed/std/monster.c";

string grace;

reset(arg)  {
    ::reset(arg);
    if(arg) return;
    set_name("pimp");
    set_alias("man");
    set_race(get_race());
    set_gender("male");
    set_short(HIM+"P"+HIC+"i"+HIR+"m"+HIB+"p"+NORM+" Daddy");
    set_long("\
  There are many people who are roaming the seedy side of town and \n\
this guy is one of the seediest. He deals in women like ranchers deal \n\
in cattle. His only concern is the amount of money he can make off of \n\
\"girls\" tonight.\n\
  The only redeeming quality of this low-life is his smashing good \n\
wardrobe. His clothes are not your typical, common man, Sach's 5th \n\
Avenue duds. Instead he is dressed in the latest selections from the \n\
Salvation Army discount rack.\n");
    set_wander(5+random(10),0,({ }) );
    set_level(14+random(3));
    set_al(-545);
    set_aggressive(0);
    set_chat_chance(10);
    set_a_chat_chance(25);
    load_chats( ({
        HIM+"P"+HIC+"i"+HIR+"m"+HIB+"p"+NORM+" Daddy says, \"It's about time!\n",
        HIM+"P"+HIC+"i"+HIR+"m"+HIB+"p"+NORM+" Daddy says, \"Hey man, what you want?\"\n",
        HIM+"P"+HIC+"i"+HIR+"m"+HIB+"p"+NORM+" Daddy says, \"I've gotta honey, can make you holler for $50.\"\n",
        HIM+"P"+HIC+"i"+HIR+"m"+HIB+"p"+NORM+" Daddy smiles with a shiny, "+BLINK+"toothy "+NORM+YEL+"g"+HIW+"r"+NORM+YEL+"i"+BOLD+"n.\n"
    }) );
    load_a_chats( ({
        HIM+"P"+HIC+"i"+HIR+"m"+HIB+"p"+NORM+" Daddy screams, \"I'm gonna get you, sucka!\"\n",
        "The "+HIM+"P"+HIC+"i"+HIR+"m"+HIB+"p"+NORM+" digs his "+HIY+"gold"+NORM+" rings into your face.\n"
    }) );
    set_chance(15);
    set_spell_dam(15+random(55));
    set_spell_mess1("The pimp becomes a deadly force of golden flashes.\n");
    set_spell_mess2("The pimp raises his arm and back-hands you across the face.\n");
    get_stuff();
    add_money(500+random(1000));
} 
     
get_race() {
    switch(random(5)) {
        case 0: grace = "human"; break;
        case 1: grace = "simbari"; break;
        case 2: grace = "krondaku"; break;
        case 3: grace = "poltroyan"; break;
        case 4: grace = "gi"; break;
    }
    return grace;
}

get_stuff() {
    object phat, coat, neck, boots, shirt;
    phat  = ACADIE+"obj/phat.c";
    coat  = ACADIE+"obj/pcoat.c";
    neck  = ACADIE+"obj/pneck.c";
    boots = ACADIE+"obj/pboots.c";
    shirt = ACADIE+"obj/pshirt.c";
    MO(CO(phat),TO); command("wear hat");
    MO(CO(neck),TO); command("wear chain");
    MO(CO(boots),TO); command("wear boots");
    MO(CO(shirt),TO); command("wear shirt");
    MO(CO(coat),TO); command("wear suit");
    return;
}
