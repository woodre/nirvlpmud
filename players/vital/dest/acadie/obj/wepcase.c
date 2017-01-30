/******************************************************************************
 *  
 *  File:           wepcase.c
 *  
 *  Author(s):      Vital@Nirvana
 *  
 *  Copyright:      Copyright (c) 2001 Vital@Nirvana
 *                  All Rights Reserved.
 *  
 *  Source:			Started 4/5/01.
 *  
 *  Notes:			
 *  
 *  Change History: 4/29/01, 9/6/01, 
 *  
 *  
 *****************************************************************************/

#include <ansi.h>
#include "/players/vital/closed/headers/vital.h"
#include "/players/dest/include/dest.h"

#define OWNER "vital"
#define SIZE 5

inherit STD+"treasure.c";

string *trophies, *comments;
mapping Case;
int open;

reset(arg) {
   if(arg) return;
   open = 0;
   set_id(({"case","weapons case","cases","weapon case","treasure case","treasure","trophy case","trophies"}));
   set_name("case");
   set_alias("trophy case");
   set_short("A large trophy case");
   set_long(
"  This is a large, wooden case that dominates much of the interior. \n\
The craftmanship on this piece of furniture is remarkable in its stark \n\
contrast to the surrounding simplicity. The front has many carvings of \n\
great warriors from many lands fighting many battles. The sides are \n\
inlaid with precious stones and rare minerals from around the universe. \n");
   set_weight(10000);
   set_value(0);
   set_read("\
\"Ye draw nigh this day unto battle against your enemies\: \n\
let not your heart faint; fear not, nor tremble, neither \n\
be ye affrighted at them.\"\n");
   set_info("\
This massive trophy case has been passed down within Ingvaard's \n\
family for nearly 12 generations.\n");
}

drop() { NOTIFY("You are not even supposed to have this object!\n"); }

get() { FAIL("What are you thinking? It is way too big to pick up!"); }

init() {
    ::init();
    if(TPN == OWNER) {
        add_action("case_open","open");
        add_action("case_close","close");
        add_action("case_reset","reset");
        add_action("store_trophy","store");
    }
    add_action("search_me","search");
}

case_open(str) {
    object obj;
    string desc;
    if(TPN != OWNER) {
        say(CTPN+" tries to open "+C(OWNER)+"'s trophy case.\n");
        FAIL("Is your name "+C(OWNER)+"?\nShould you even be here?\nYou cannot open "+C(OWNER)+"'s trophy case!\n");
    if(!str || str != "case") {
        say(CTPN+" tries like a buffoon to do something, but "+TPP+" stupidity gets in the way.\n");
        FAIL("What are you trying to do?\nType 'store <trophy item> <personal description>'.\n");
    }
    if(open) {
        say(CTPN+" tries to open the case that is already open.\n");
        FAIL("It is already open.\n");
    }
    say(CTPN+" opens the trophy case.\n");
    write("You open up the trophy case.\n");
    open = 1;
}

case_close(str) {
    if(TPN != OWNER) {
        say(CTPN+" tries to close "+OWNER+"'s trophy case.\n");
        FAIL("Is your name "+OWNER+"?\nShould you even be here?\nYou cannot close "+OWNER+"'s trophy case!\n");
    if(!str || str != "case") {
        say(CTPN+" tries like a buffoon to do something, but "+TPP+" stupidity gets in the way.\n");
        FAIL("What are you trying to close?\n");
    }
    if(!open) {
        say(CTPN+" tries to close the case that is already closed.\n");
        FAIL("It is already closed.\n");
    }
    say(CTPN+" closes the trophy case.\n");
    write("You close up the trophy case.\n");
    open = 0;    
}

store_trophy(str) {
    string bob, larry;
    object obj;
    if(TPN != OWNER) {
        say(CTPN+" tries to mess with "+OWNER+"'s trophy case.\n");
        FAIL("Is your name "+OWNER+"?\nShould you even be here?\nYou cannot use "+OWNER+"'s trophy case!\n");
    if(!str || (sscanf(str,%s %s,bob,larry) != 2) ) {
        say(CTPN+" tries like a buffoon to do something, but "+TPP+" stupidity gets in the way.\n");
        FAIL("What are you trying to close?\n");
    }
    if(!present(bob,TP)) {} /* start again here w/ checking code */
    if(!open) {
        say(CTPN+" tries to stick something in the closed case.\n");
        FAIL("It is closed.\nOpen the case first.\n");
    }
    if(sizeof(trophies) > 4) { FAIL("The maximum number of trophies in the case is SIZE.\n"); }
    say(CTPN+" closes the trophy case.\n");
    write("You close up the trophy case.\n");
    open = 0;    
}

