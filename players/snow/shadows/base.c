/*  10/09/06 - Rumplemintz: moved inherit above #include statement  */

inherit "room/room";
#include "shaddefs.h"
realm() { return "NT"; }


reset(arg){

    if(!arg){

	set_light(0);

	items=({
	  "bushes", "Bushes of shadowstuff. When you touch them, your hand meets little\n"+
	  "resistance and passes through without noticable effect",
	  "tree","You think you see a shadow tree but it fades away as you draw near",
	  "animals","Vague animal shapes seem to peer at you, then fade away..",
	  "landscape","Features of the land pass before your eyes",
	  "hill","The hill you stand upon appears to be a solid point of reference\n"+
	  "...perhaps.\n",
	});

    }   }

init() {
    ::init();
    if(this_player()->is_player()) this_player()->set_fight_area();
    if(this_player()->is_player()) wandering();
    add_action("shadowmove","north");
    add_action("shadowmove","south");
    add_action("shadowmove","east");
    add_action("shadowmove","west");
    add_action("shadowmove","northwest");
    add_action("shadowmove","northeast");
    add_action("shadowmove","southwest");
    add_action("shadowmove","southeast");
}

exit() {
    if(this_player())
	if(this_player()->is_player()) this_player()->clear_fight_area(); }

shadowmove() {
    int SHW,RW;
    string destdir;
    SHW = random(20);
    if(TP->query_guild_name() == "cyberninja") SHW = random(5);
    if(TP->query_attack()) {
	write("The shadows warp around you and you cannot leave.\n");
	return 1; }
    write("You slowly trudge down to the shadowplain...\n");
    if(SHW == 0) destdir = SFORT;
    if(SHW == 1) destdir = SH4;
    if(SHW == 2) destdir = SH2;
    if(SHW == 3) destdir = SH3;
    if(SHW == 4) destdir = SH1;
    if(SHW == 5) destdir = SHILL;
    if(SHW > 5 && SHW < 9) destdir = SH2;
    if(SHW > 8 && SHW < 13) destdir = SH3;
    if(SHW > 12 && SHW < 17) destdir = SH1;
    if(SHW > 16) destdir = SH4;
    call_other(TP,"move_player",destdir);
    return 1;
}

wandering() {
    object shc, monst;
    int det;
    shc = present("shadowcreature");
    det = random(100);
    if(det < 2) monst = "/players/snow/shadows/mon/sdragon";
    if(det > 1 && det < 10) monst = "/players/snow/shadows/mon/shunter";
    if(det > 9 && det < 30) monst = "/players/snow/shadows/mon/ssnake";
    if(det > 29 && det < 40) monst = "/players/snow/shadows/mon/swraith";
    if(det > 39 && det < 60) monst = "/players/snow/shadows/mon/slion";
    if(det > 59) monst = "/players/snow/shadows/mon/swolf";
    if(!shc && random(100) < 45) {
	move_object(clone_object(monst),TO);
	return 1;
    }
    if(!shc) return;
    if(shc->query_real_name() == "shadow dragon") return 1;
    if(shc->query_real_name() == "shadow wraith") {
	if(present("shadow wraith 3")) return 1;
	if(random(100) < 30) {
	    move_object(clone_object("/players/snow/shadows/mon/swraith"),TO);
	}
	return 1;
    }
    if(shc->query_real_name() == "shadow hunter") {
	if(present("shadow hunter 5")) return 1;
	if(random(100) < 40) {
/* This supposed to be shunter I believe - Rump 
	    move_object(clone_object("/players/snow/shadows/mon/swraith"),TO);
*/
            move_object(clone_object("/players/snow/shadows/mon/shunter"),TO);
	}
	return 1;
    }
    if(shc->query_real_name() == "shadow lion") {
	if(present("shadow lion 5")) return 1;
	if(random(100) < 20) {
	    move_object(clone_object("/players/snow/shadows/mon/slion"),TO);
	}
	return 1;
    }
    if(shc->query_real_name() == "shadow wolf") {
	if(present("shadow wolf 4")) return 1;
	if(random(100) < 40) {
	    move_object(clone_object("/players/snow/shadows/mon/swolf"),TO);
	}
	return 1;
    }
    if(shc->query_real_name() == "shadow snake") {
	if(present("shadow snake 6")) return 1;
	if(random(100) < 20) {
	    move_object(clone_object("/players/snow/shadows/mon/ssnake"),TO);
	}
	return 1;
    }
    return 1;
}
query_srealm() { return "shad"; }
