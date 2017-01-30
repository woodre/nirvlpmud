#define NAME "Sparrow"
#define DEST "players/wren/Area/coastline/coast3"
/*
 * This is just the facade to a castle. If you want to enable the
 * "enter" command, move the player to a hall or something (which
 * you have to design yourself).
 * The predefined string DEST is where a player should come when he
 * leaves the castle.
 *
 * This file is loaded automatically from "init_file". We have to move
 * ourself to where we are supposed to be.
 */

id(str) { return str == "castle"; }

short() {
    return "Castle of " + NAME;
}

long() {
    write("This is the " + short() + ".\n");
    write(NAME + " is a rather new wizard, but it is an amazing castle\n");
    write("just the same. However, the gates are closed.\n");
}

init() {
    add_action("enter"); add_verb("enter");
}

enter(str) {
    if (!id(str))
	return 0;
    write("It is not an open castle.\n");
    return 1;
}

reset(arg) {
    string *drop;
    object ob;
    string room;
    if (arg)
	return;
    move_object(this_object(), DEST);
    if(!find_object("/players/sparrow/areas/bwo/npc/bwo_template.c")) {
      drop = ({"/players/maledicta/cont/rooms/444",
               "/players/maledicta/cont/rooms/771",
               "/players/maledicta/cont/rooms/109",
               "/players/mythos/aroom/forest/forest5",
               "/players/earwax/area/fields/room/tunnel3",
               "/players/maledicta/cont/rooms/892",
               "/players/maledicta/cont/rooms/887",
               "/players/jaraxle/cont/rdragon/rooms/pond2",
               "/players/angel/area/school/room/principal_office_02.c",
               "/players/angel/area/walmart/room/automotives.c",
               "/room/south/sshore30.c",
               "/room/south/sforst38.c",
               "/players/wocket/turtleville/tvmarsh6.c",
               "/players/saber/tower/tower20+9.c",
               "/players/eurale/Fiend/mm18.c",
               "/players/eurale/Keep/k53.c",
               "/players/bastion/isle/wiz/shore5.c",
               "/players/trix/castle/primo/apse20.c",
               "/players/fakir/woods/room20.c",
               "/players/beck/room/park19.c",
               "/players/mythos/aroom/forest/around.c",
               "/players/vertebraker/swamp/ROOMS/s25.c",
               "/players/fred/forest/Rooms/forest24.c",});
      room = drop[random(23)];    
      ob = clone_object("/players/sparrow/areas/bwo/npc/bwo_template");
      room->blarg();
      ob->move_player("quietly, disappearing into a shadow#"+room);
     log_file("sparrow.bwm", "Log Entry: "+ctime()+" Obj: "+file_name(ob)+"\n   Monk created by castle and moved to room: "+room+"\n");
    }
}
is_castle(){return 1;}
