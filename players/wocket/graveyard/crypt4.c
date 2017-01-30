#include "/players/wocket/closed/ansi.h"
#define PATH "/players/wocket/graveyard/"
inherit "room/room";
/*
inherit "/players/wocket/graveyard/crypt1.c";
*/

int door_open;

reset(arg){
    /*
    ::reset(arg);
    */
    if(arg) return ;
    short_desc = BLU+"A Crypt"+NORM;
    long_desc = ""+
    "   The walls have been covered in dirt allowing only a little of\n"+
    "of the stone to show through.  This room is slightly larger then some\n"+
    "of the others letting more bodies fill it up.  The stench is very strong\n"+
    "as rotting flesh falls from the bones they were attached too.\n";
    set_light(1);
    items = ({
      "bodies","They are partially decomposed, with torn clothes",
      "walls","They are made of stone and covered with dirt",
      "dirt","It is grey in color and covers the walls and floors",
      "heap","Many killed dryants have been tossed in the crypt with no proper burial, forming\na heap of bodies",
      "stone","The stone can barely be seen through the encrusted dirt",
      "flesh","It has been eaten away from the bone and gives off a horrible stench",
      "bones","They are covered in dirt",
      "rock","There is a loose stone set in the wall.  Perhaps you could 'pull' it",
    });
    /*
    smells += ({
	"flesh","It gives off a rotten stench as it is eaten away by time",
    });
    */
    dest_dir = ({
      PATH+"crypt2.c","south",
    });
}

init(){
    ::init();
    add_action("search","search");
    add_action("pull","pull");
    add_action("enter","enter");
}


search(){
    tell_object(this_player(),"You search and find a loose rock set out from the wall.\n");
    return 1;
}

pull(str){
    if(str != "rock"){
	notify_fail("What would you like to pull?\n");
	return 0;
    }
    write("You pull the rock from the wall.\n");
    say(this_player()->query_name()+" pulls a rock from the wall.\n");
    call_out("open_door",2);
    return 1;
}

open_door(){
    tell_room(this_object(),"A hidden door slowly opens to reveal a passage.\n");
    items += ({
      "door","A hidden door that opened from the wall.  It reveals a passage through the crypt.\nPerhaps you could 'enter' it",
      "passage","A passage that was revealed when the hidden door was opened.\nPerhaps you could 'enter' it",
    });
    door_open = 1;
    long_desc += BOLD+"A stone door is open, revealing a passageway.\n"+OFF;
    if(!"/players/guilds/necro/room/necroent.c"->query_door())
	"/players/guilds/necro/room/necroent.c"->open_door();
    call_out("close_door",10);
}

close_door(){
    tell_room(this_object(),"The stone door closes.\n");
    door_open = 0;
    reset();
}

enter(str){
    if(str != "passage" && str != "door" && str != "passageway"){
	notify_fail("What would you like to enter?\n");
	return 0;
    }
    if(!door_open){
	notify_fail("There is no passageway here.\n");
	return 0;
    }

    write("You enter through the passageway.\n");
    say(this_player()->query_name()+" leaves through the passageway.\n");
    move_object(this_player(),"/players/guilds/necro/room/necroent.c");
    command("glance",this_player());
    return 1;
}

query_door(){
    return door_open;
}
