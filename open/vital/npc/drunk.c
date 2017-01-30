/******************************************************************************
 *  
 *  File:           drunk.c
 *  
 *  Author(s):      Vital@Nirvana
 *  
 *  Copyright:      Copyright (c) 2001 Vital@Nirvana
 *                  All Rights Reserved.
 *  
 *  Source:			Started 9/12/01.
 *  
 *  Notes:			This is mainly courtesy of Fred@Nirvana
 *  
 *  Change History: 9/16/01,
 *  
 *  
 *****************************************************************************/

#include "/players/vital/dest/dest.h"
#include "/players/vital/vital.h"

inherit "/players/vital/closed/std/monster.c";

reset(arg)  {
    ::reset(arg);
    if(arg) return;
    set_name("drunk");
    set_alias("man");
    set_race("human");
    set_gender("male");
    set_short("A Drunken Man");
    set_long("\
  The drunk is a dirty little man in his mid-thirties.  He is \n\
wearing old, tattered clothes with holes and stains all over them. \n\
He stumbles around the town, yelling meaningless phrases in between \n\
drinks. He is tired of living a life without purpose.\n"); 
    set_level(10+random(7));
    set_al(115);
    set_aggressive(0);
    set_chat_chance(10);
    load_chats( ({
        "The Drunk hollers: There ish beer in them, thar hillsh!\n",
        "The drunk hiccups.\n",
        "The Drunk yells: I have scheen him! Don't let him get me!\n",
        "The drunk asks: hey buddy, you got any shpare change?\n",
        "The Drunk yells: "+BLINK+"Fred"+NORM+" is a Sheer Genious!\n",
        "The Drunk yells: Did ya know s-s-sweat can s-s-sold?\n",
        "The Drunk yells: Dig! Dig I tell ya!\n",
        "The Drunk yells: Wanna schmell my bref?\n",
        "The Drunk yells: Shave the poodless! Pleash don't let the hair crawl!\n",
        "The Drunk yells: I have a penthoush!\n",
        "The Drunk asks: Can we s-s-swim in the shtreetssh?\n"
    }) );
    set_chance(15);
    set_spell_dam(5+random(9));
    set_spell_mess1("The drunken man stumbles crazily around the room.\n");
    set_spell_mess2("The drunken man pushes into you.\n");
    call_out("random_move",10);
    get_the_hooch();
} 

get_the_hooch() {
    object al;
    switch(random(100)) {
        case  0..59: al=DEST+"obj/malt.c"; break;
        case 60..89: al=DEST+"obj/fwiz.c"; break;
        case 90..99: al=DEST+"obj/pga.c"; break;
    }
    MO(CO(al),TO);
    return 1;
}
     
random_move() {
    int n;
    string dir;
    object room;
    room = ENV(TO);
    remove_call_out("random_move");
    call_out("random_move",5+random(5));
    if(!room) return;
    
    if(!query_attack()) {
        n = random(9);
        switch(n) {
            case 0 : dir = "north"; break;
            case 1 : dir = "east"; break;
            case 2 : dir = "south"; break;
            case 3 : dir = "west"; break;
            case 4 : dir = "northeast"; break;
            case 5 : dir = "northwest"; break;
            case 6 : dir = "southwest"; break;
            case 7 : dir = "southeast"; break;
            case 8 : dir = "out"; break;
        }
    return init_command(dir);
    }
    if(room == ENV(TO)) random_move();
}
