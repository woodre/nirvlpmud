#include "../DEFS"
inherit ROOM;

reset(int arg){
    if(!present("pedestal")) {
	move_object(clone_object(OBJ+"/misc/guildboard.c"),this_object());
    }
    if(arg) return;
    is_pk = 1;
    set_light(1);
    add_property("no_follow");
    short_desc= "Necromancer Stronghold";
    long_desc="  "+
    "The Main Chamber is surrounded by white marble walls, interlaced with deep\n"+
    "blue veins.  The torches here cast a dim glow across the walls and floor of\n"+  
    "the chamber, and a pedestal stands in the center of the room with a large book\n"+
    "upon it. An arched door leads east into the library, and the marble chamber\n"+
    "continues to the south.  There is a spiral staircase in the center of the room,\n"+
    "leading deeper within the earth, and a hallway is to the west.\n";


    items=({
      "wall","The red stone walls are the same as elsewhere in the tower",
    });

    dest_dir=({
      PATH+"/room/necro5.c","north",
      PATH+"/room/necro1.c","south",
      PATH+"/room/necro3.c","east",
      PATH+"/room/necro4.c","west",
      PATH+"/room/crypt1.c","down",
    });
}

init(){
    ::init();
    add_action("down","d");
    add_action("down","down");
}

down(){
    write("The passageway is currently blocked.\n");
    return 1;
}
