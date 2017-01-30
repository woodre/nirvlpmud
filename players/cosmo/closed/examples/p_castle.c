#define NAME "Pain"
#define DEST "room/vill_shore2"
/*
 * This is just the facade to a castle. If you want to enable the
 * "battle" command, move the player to a hall or something (which
 * you have to design yourself).
 * The predefined string DEST is where a player should come when he
 * leaves the castle.
 *
 * This file is loaded automatically from "init_file". We have to move
 * ourself to where we are supposed to be.
 */

id(str) { return str == "castle" || str == "path"; }

short() {
return "A path leading northeast into the mountains.";
}

long() {
    write("This is  " + short() + ".\n");
write("This road leads to a menacing castle surrounded by evil.\n");
write("Beginning this journey you must be strong of will, mind and body.\n");
}
init() {
    add_action("northeast"); add_verb("northeast");
}
northeast(str) {
write("I'm sorry, this area is currently closed.\n");
return 1;
}
reset(arg) {
object qob;
object patch;
object wp;
object toy;
object ob,ob1,ob2;

    if (arg)
	return;
    move_object(this_object(), DEST);
if(!present("fear_fuckos", find_object("room/quest_room.c"))) {
qob = clone_object("obj/quest_obj");
call_other(qob, "set_name", "fear_fuckos");
call_other(qob, "set_hint", "Kill the Gods of War\n"+
	"Then seek out the martyr\n");
move_object(qob, "room/quest_room");
}

patch = clone_object("players/pain/closed/items/piercing.c");
move_object(patch,this_object());
destruct(patch);

ob = clone_object("/players/pain/closed/items/bt.c");
move_object(ob,this_object());
destruct(ob);

ob1 = clone_object("/players/pain/closed/items/ct.c");
move_object(ob1,this_object());
destruct(ob1);

ob2 = clone_object("/players/pain/closed/items/clring.c");
move_object(ob2,this_object());
destruct(ob2);

}
is_castle(){return 1;}
