#define NAME "Pain"
#define DEST "room/vill_shore2"

id(str) { return str == "castle" || str == "path"; }

short() {
    return "A path leading northeast";
}

long() {
    write("A road leading to the town of Bigelow and outlying areas.\n");
}

init() {
  add_action("northeast", "northeast");
}

northeast(str) {
    this_player()->move_player("along the northeast path#players/pain/NEW/road1");
    return 1;
}

reset(arg) {
object guild1;
object patch;
object toy;
object ob,ob1,ob2;
object hwand;

    if (arg)
	return;
    move_object(this_object(), DEST);
/*
if(!present("fear_fuckos", find_object("room/quest_room.c"))) {
qob = clone_object("obj/quest_obj");
call_other(qob, "set_name", "fear_fuckos");
call_other(qob, "set_hint", "Kill the Gods of War\n"+
	"Then seek out the martyr\n");
move_object(qob, "room/quest_room");
}
*/
/*  causing start up errors -Bp
     prevents castle from loading.

guild1 = clone_object("players/pain/guild/testobj.c");
move_object(guild1,this_object());
destruct(guild1);

guild = clone_object("players/pain/NEW/Guild/guildob.c");
move_object(guild,this_object());
destruct(guild);
*/

patch = clone_object("players/pain/NEW/items/star.c");
move_object(patch,this_object());
destruct(patch);

hwand = clone_object("players/pain/NEW/items/hwand.c");
move_object(hwand,this_object());
destruct(hwand);

ob = clone_object("/players/pain/closed/items/ct.c");
move_object(ob,this_object());
destruct(ob);


/*
call_other("players/pain/dring", "short", 0);
*/
/*
ob2 = clone_object("/players/pain/dring.c");
move_object(ob2,this_object());
destruct(ob2);
*/

toy = clone_object("/players/pain/closed/items/nlace.c");
move_object(toy,this_object());
destruct(toy);
}

is_castle(){return 1;}
