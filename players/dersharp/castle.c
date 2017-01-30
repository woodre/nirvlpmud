#define NAME "Dersharp"
#define DEST "room/forest12"
#define destruct_object
#define TP		capitalize(this_player()->query_real_name())

id(str) {return str == "road"; }

short() {
    return "A road leads off to a mountain in the north and also to the west";
}

long() {
	write("The northern road leads off to a large dark mountain.  The road\n"+
	      "which leads to the west is shrouded in darkness....\n");

}

init() {
  add_action("north", "north");
  add_action("west", "west");
}
north() {
	write("You your way to the north.\n");
	move_object(this_player(), "/players/dersharp/road/roadn1");
        say(TP+" heads north!\n");
        command("look",this_player());
        return 1;
	}
west() {
        call_other(this_player(), "move_player", "enter#players/dersharp/rooms/enter.c");
/*
    vertebraker change:
    look not needed in move_player() 2:21p[10-4-01]
	command("look",this_player() );
*/
	return 1;
}

reset(arg) {
    if (arg)
	return;
    move_object(this_object(), DEST);
    destruct_object(clone_object("/players/dersharp/wedding"));
}
is_castle(){return 1;}
