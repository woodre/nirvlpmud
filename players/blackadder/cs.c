#define NAME "Bastion"
#define DEST "room/sea"
int code;
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

id(str) { return (str=="castle" || str=="island"); }

short() {
     return "You see an island far off to the north";
}

long() {
     write("This is the entryway to lands of the archmage Bastion.\n\n");
     write("The island to the north looks like a safe refuge from the\n");
     write("bitter cold of the surrounding ocean.\n");
}

init() {
    add_action("enter", "north");
    add_action("enter", "enter");
}

enter(str) {
     this_player()->move_player("north#players/bastion/isle/nearshore");
     return 1;
}

reset(arg) {
     object ob, room, q;
     room=find_object("room/quest_room");
     if(!present("staff", room)) {
          q=clone_object("obj/quest_obj");
          q->set_name("staff");
          q->set_hint("Seek out the old hermit. He'll have a task for you.");
          move_object(q, room); }
     code=random(10) + (random(10)*10) + (random(10)*100) + random(10)*1000 +
      (random(10)*10000) + (random(10)*100000);
     if (arg)
	return;
     move_object(this_object(), DEST);
     ob=clone_object("players/bastion/monster/damian");
     move_object(ob, "/players/bastion/isle/wiz/vault2");
     find_object("players/bastion/isle/wiz/vault2")->reset();
     destruct(ob);
}

set_code(str) { code=str; }
query_code() { return code; }
