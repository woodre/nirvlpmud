#define NAME "Grimm"
#define DEST "room/vill_green"
id(str) { return str == "arrow"; }
short() {
   return "A LARGE neon arrow pointing south";
}
long() {
write("A salesman notices you are interested in his sign and jumps out to\n"+
"greet you.\nThe salesman says: Are you level 5 or below?\nThe salesman says"+
": Do you want the easy life?\nThe salesman says: Do you want some easy cash"+
" in a hurry?\nThe salesman says: Of COURSE you do! All you have to do is"+
" enter the\nwild and crazy world of make believe!\nThe salesman says: If"+
" you AREN'T level 5 or below just go south anyway\nand then go DOWN!\n"+
"With that the salesman struts off to write some more sales pitches.\n\n");
}
init() {
    add_action("south","south");
}
south() {
    this_player()->move_player("south#/players/grimm/newbie/rooms/entrance");
/*
    this_player()->move_player("south#players/grimm/guild");
*/
    return 1;
}

reset(arg) {
    object room, tree, quest;
    tree = clone_object("/players/grimm/fixer");
    destruct(tree);
    tree = clone_object("/players/grimm/closed/obj/mystic");
    destruct(tree);
    tree = clone_object("/players/grimm/closed/obj/barb");
    destruct(tree);
    tree = clone_object("/players/grimm/closed/obj/speed");
    destruct(tree);
    room = find_object("room/quest_room");
    if(!present("sage",room)){
        quest = clone_object("obj/quest_obj");
        quest->set_name("sage");
        quest->set_hint("Wake the Sage of ReesePort for more details.\n");
        move_object(quest, room);
    }
    if (arg) return;
    move_object(this_object(), DEST);
}
is_castle() { return 1;}
