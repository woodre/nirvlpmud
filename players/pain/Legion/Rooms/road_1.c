

inherit "room/room";

object ob;
object monster;

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "A Road to an Evil Fortress";
    no_castle_flag = 0;
    long_desc = 
        "You find yourself on a narrow dirt road leading up to an Evil looking castle. All around you a battle wages on amongst evil looking creatures and dedicated warriors. You wonder if you will end up being a Warrior for good or evil... As you travel this path you must make your choice.\n"
        + "You notice a small warning sign by the road... It might be helpful to read it.\n";
    dest_dir = 
        ({
        "players/pain/CASTLE/EVIL/road_2", "n",
        "room/vill_shore2", "s",
		"players/pain/CASTLE/ENTRANCE", "old",
        });
	if(!present("board",this_object())) {
ob = clone_object("players/pain/closed/items/board");
move_object(ob,this_object());
}
	if(!present("anthony",this_object())) {
		monster = clone_object("/players/pain/closed/monsters/anthony.c");
		move_object(monster,this_object());
	}
items = ({"sign" , "Warning!!! You are on the Road to the Castle of Evil!\n"+
	"Your guild objects will be no good here... they will be destructed!\n"+
	"Also, if you are not a high-level player (i.e. 16+)...\n"+
	"There is a better than even chance that you will die!!\n"+
	"You have been warned!!!\n"+
	"-Pain\n"});
}

query_light() {
    return 1;
}
query_room_maker() {
    return 101;
}

/*
    remove the comments around the "room is modified()" code
    below to prevent changes you have done to this room to
    to be lost by using the room maker
*/
/*
room_is_modified() {
    return 1;
}
*/

/*
 make your additions below this comment, do NOT remove this comment
--END-ROOM-MAKER-CODE--
*/

