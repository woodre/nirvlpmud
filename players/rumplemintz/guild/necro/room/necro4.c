#include "../DEFS"
inherit ROOM;

reset(int arg){
    if(!arg){
	is_pk = 1;
	set_light(1);
	add_property("no_follow");
	short_desc= "Necromancer Stronghold";
	long_desc="  "+
	"A small hallway with the same marble walls as the rest of the underground\n"+
	"stronghold.  Two exits lead one through this curved passageway to the east,\n"+
	"and south.  Rats scurry along the edge of the wall gathering food as they\n"+
	"pass.  Small chunks of marble have crumble off the walls, leaving piles of dust\n"+
	"and dirt along the floor.\n";

	items=({
	  "room","The room has the same white marble walls as the guild",
	  "walls","The white marble is covered with blood stains",
	  "wall","The white marble is covered with blood stains",
	  "marble","Expensive white marble makes up the guild hall",
	});

	dest_dir=({
	  PATH+"/room/necro7.c","south",
	  PATH+"/room/necro2.c","east",
	});

    }
}

init(){
    ::init();
    add_action("search","search");
}

search(){
    write("Bits of bone and areas of dried blood are all about the room.\n");
    say(this_player()->query_name()+" searches the area.\n");
    return 1;
}

realm() {return "NT";}

