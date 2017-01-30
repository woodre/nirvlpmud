#include "../DEFS"
inherit ROOM;

int door_open;

reset(arg){
    if(arg) return ;
    is_pk = 1;
    set_light(1);
    add_property("no_follow");
    short_desc = "Necromancer Passageway";
    long_desc = ""+
"   This tunnel is thin and narrow.  The walls are covered in dirt, allowing\n"+
"only a little of the white marble stone to show through.  North, as the stones\n"+
"become cleaner, unveils the Necromancer's stronghold.  South, a non-descript \n"+
"stone wall with a single leve penetrating through it.  Dust filters off the wall\n"+
"as if somethine has recently been moved.\n";

    items = ({
      "flesh","It has been eaten away from the bone and gives off a horrible stench",
      "bones","They are covered in dirt",
      "lever","A stone lever set into the wall.  Perhaps you could 'pull' it", 
    });

    smells = ({
      "flesh","It gives off a rotten stench as it is eaten away by time",
    });

    dest_dir = ({
      PATH+"/room/necro1.c","north",
    });
}

init(){
    ::init();
    add_action("search","search");
    add_action("pull","pull");
    add_action("enter","enter");
}


search(){
    tell_object(this_player(),"All you find is the lever that was in plain sight.\n");
    return 1;
}

pull(str){
    if(str != "lever"){
	notify_fail("What would you like to pull?\n");
	return 0;
    }
    write("You pull the lever down.\n");
    say(this_player()->query_name()+" pulls the lever down.\n");
    call_out("open_door",2);
    return 1;
}

open_door(){
    tell_room(this_object(),"A stone door slowly opens to reveal a passage.\n");
    items += ({
      "door","A stone door that opened from the wall.  It reveals a passage through the crypt.\nPerhaps you could 'enter' it",
      "passage","A passage that was revealed when the door was opened.\nPerhaps you could 'enter' it",
    });
    long_desc += BOLD+"A stone door is open, revealing a passageway.\n"+OFF;
    door_open = 1;
    if(!"/players/wocket/graveyard/crypt4.c"->query_door())
	"/players/wocket/graveyard/crypt4.c"->open_door();
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
    move_object(this_player(),"/players/wocket/graveyard/crypt4.c");
    command("glance",this_player());
    return 1;
}

query_door(){
    return door_open;
}
