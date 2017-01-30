/******************************************************************************
 *  
 *  File:           womandriver.c
 *  
 *  Author(s):      Vital@Nirvana
 *  
 *  Copyright:      Copyright (c) 1997 Vital@Nirvana
 *                  All Rights Reserved.
 *  
 *  Source:			Started 9/9/01.
 *  
 *  Notes:			
 *  
 *  Change History: 
 *  
 *  
 *****************************************************************************/

#include "/players/vital/spaceport/spaceport.h"
inherit "/players/vital/closed/std/monster.c";

string grace;

reset(arg) {
    ::reset(arg);
    if(arg) return;
	set_name("woman");
	set_alias("driver");
	set_gender("female");
	set_race(get_race());
	set_short(BLINK+"Crazy"+NORM+" Woman Driver");
	set_long("\
  The wild-eyed, frantic expression bearing down upon you could only \n\
belong to the "+short_desc+". With make-up smeared from ear to ear \n\
chin to forehead, she is a scary sight. Add to that the 120 kilobeanos \n\
of vehicle, and she will mow you down. Watch out for your pets and \n\
kids.\n");
	set_level(19);
	set_attrib("ste",25);
	set_attrib("pie",5);
	set_attrib("wil",25);
	set_attrib("int",1);
	set_wander(3,1,({}));
	set_chance(random(25)+25);
	set_spell_mess1(short_desc+" looks like she could explode.\n");
	get_spell_mess2();
	set_spell_dam(10+random(10));
	set_chat_chance(random(15)+10);
	load_chats( ({
	    "The "+short_desc+" screams at errant pedestrians.\n",
	    "The "+short_desc+" wildly looks around, everywhere except for where she is going.\n",
	    short_desc+" screams, \"Get off of my road you stupid people!\n",
	    short_desc+" veers into a trashcan, careens off of a curb \nand tags a lamppost before flying on down the sidewalk.\n"
	}) );
	set_a_chat_chance(60);
	load_a_chats( ({
	    "The "+short_desc+" veers, careens and screeches along the sidewalk.",
	    short_desc+" screams: \"Outta my way!\"\n",
	    "You hear the screams of mothers, reaching to save their children.\n"
	}) );
	set_info("This "+short_desc+" gives creedence to the stereotype found all throughout \n history of the disasterous effects of crossing XX chromosomes with \nmoving vehicles. From Cleopatra\'s chariot to Erica the Red's Viking \nLong-Boat to Susan's Mercury Grand Marquis.\n");
}

id(str) { return str == "woman driver" || str == "Woman" || str == "Driver" || str == "crazy woman" || str == "crazy driver" || str == name || str == alias || str == race || str == alt_name; }


get_spell_mess2() {
    switch(random(4)) {
        case 0: return "The "+short_desc+" slams into you with her vehicle.\n";
        case 1: return short_desc+" screams at you.\n";
        case 2: return short_desc+" yells, \"You are not worth smearing on my bumper.\"\n";
        case 3: return short_desc+" chases you around with her vehicle.\n";
    }
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
