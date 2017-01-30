

inherit "room/room";

reset(arg) {
  object ob;
    if (arg) return;

    set_light(1);
    no_exits=1;
    short_desc = "Hell";
    no_castle_flag = 0;
    long_desc = 
        "You are in a plane of raging lava and flame. Above you is a starless pall\n"
        + "of blackness. You can hear the wailing of countless disembodied others.\n";
    dest_dir = 
        ({
        });
     ob = clone_object("/players/bastion/obj/static");
     ob->set_object(this_object());
     ob->set_chat_chance(15);
     ob->set_short("A rocky outcropping");
     ob->set_name("rocks");
     ob->set_alias("outcropping");
     ob->load_chat("Flames lick at your heels.\n");
     ob->load_chat("You hear mournful wailing in the distance.\n");
     ob->load_chat("A sudden scream derails your train of thought!\n");
     ob->load_chat("A geyser of lava shoots high above you.\n");
     ob->load_chat("The rocks about you pulse with heat.\n");
     ob->load_chat("A winged shape soars through the blackened clouds.\n");
     ob->load_chat("Growling laughter sends a chill down your spine. You " +
                   "can't make out\nthe source.\n");
     move_object(ob, this_object());
     ob->start_check();
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


realm() { return "NT"; }

init() {
  add_action("nope","quit");
  ::init();
}

nope(str) { write("You can't do that.\n"); return 1; }
