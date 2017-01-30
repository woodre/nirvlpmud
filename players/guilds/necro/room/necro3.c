#include "../DEFS"

inherit ROOM;

reset(arg) {
    if(arg) return;
    is_pk = 1;
    add_property("no_follow");
    move_object(clone_object(OBJ+"/misc/bookcase.c"),this_object());
    move_object(clone_object(OBJ+"/misc/chairs.c"),this_object());
    set_light(1);
    short_desc= "Necromancer Library";
    long_desc= "  "+
    "The library within the necromancer stronghold is a small room, lined with\n"+
    "rows of shelves.  The bookcases reach from the floor to the ceiling, and the \n"+
    "only light comes from the dim glow of a fireplace that has been built into\n"+
    "the north wall.  The books on the shelf vary widely in age, some worn from\n"+ 
    "time, while others are in excellent condition.  There are some aged scrolls,\n"+
    "maps, and manuscripts upon one shelf, and a stack of unorganized papers have\n"+
    "been placed on another.  The doorway leads west along with another archway to\n"+
    "the south.\n";

    items = ({
      "fireplace","Set into the north wall, it glows a warm yellow",
      "books","They fill the bookcases and vary widely in size and shape",
      "doorway","It leads to the west",
    });

    dest_dir=({
      PATH+"/room/necro2.c","west",
      PATH+"/room/necro6.c","south",
    });
    call_out("randemote",random(60));
}

randemote(){
    string msg;
    switch(random(3)){
    case 0:  msg = "The fireplace crackles, filling the room with warmth.\n";
	break;
    case 1:  msg = "A cinder from the fireplace flies out into the room.\n";
	break;
    case 2:  msg = "Shadows flicker along the floor, cast out by the fireplace.\n";
    }
    tell_room(this_object(),msg);
    call_out("randemote",random(60));
}

exit(){
    ::exit();
    if(this_player()){
	if(present("chairs",this_object())){
	    if(present("chairs",this_object())->query_chair1() == this_player()->query_real_name()){
		command("stand",this_player());
	    }
	    if(present("chairs",this_object())->query_chair2() == this_player()->query_real_name()){
		command("stand",this_player());
	    }
	}
    }
}
