/*
    Changelog:
    Dragnar 11/14/1998
    Changed int variables to names that make sense, i.e. locked
    Added new int demon_cloned, so players can't search the chest
    before the demon arrives.

    Bal 1996-03-15:
	+ built ~/call.c into this object
	+ changed all say()'s to tell_room()'s
*/

object  user;
int	opened, locked, demon_cloned;
int K;  /*  variable to make sure only one key  */

reset(arg) {
    if( opened )
	tell_room(environment(), "The chest slams shut.\n");
    locked = 1;
    opened = 0;
K = 1;
}

id(str) { return str=="chest"; }

short() { return "A Chest"; }

long() {
	write(
"It has strange symbols all over it that you have never seen before.\n"+
"Most of the lettering is black and in some type of language that you have\n"+
"never seen before.  You can make out some of the writing and as you read it\n"+
"a chill runs up your spine......'The one who opens this chest will face the\n"+
"wrath of Lucifer'\ Even so you can't help but want to search it.\n");
}

init() {
	add_action("unlock","unlock");
	add_action("open","open");
  add_action("search","search");
}

unlock(str) {
    if (str == "chest") {
    if( !locked ) {
	    write("It is not locked.\n");
	    return 1;
	}
	if (!present("cultkey", this_player())) {
        write("You try to break the lock, but fail.\n");
	    return 1;
	}
    locked = 0;
	write("You put the key in the lock and you hear a click.\n");
	say(capitalize(this_player()->query_real_name()) +
	    " unlocks the chest.\n");
	return 1;
    }
}

open(str) {

    if (str == "chest") {
    if( opened ) {
	    write("The chest is already open.\n");
	    return 1;
	}
    if( locked ) {
	    write("The chest is locked.\n");
	    return 1;
	}
    opened = 1;
	write("The chest cover opens with a loud creak.\n");
	say(capitalize(this_player()->query_real_name())+
	    " opens the lid of the chest.\n");

	call_out("cvcv",4);
	call_out("jbjb",8);
	call_out("ncnc",12);
	return 1;
    }
}

cvcv() {
    tell_room(environment(),
	"The chest begins to shake and the room gets very hot.\n");
}

jbjb() {
    tell_room(environment(),
	"Flames shoot from the top of the chest!\n");
}

ncnc() {
    object demon;

    tell_room(environment(),
	"A demon straight from hell crawls out of the chest.\n");
    demon=clone_object("/players/dragnar/mons/demon.c");
    move_object(demon, (environment(this_object())));
    demon_cloned = 1;
}

search(str) {
if(present("demon")) {
  write("The demon LAUGHS in your face and spits at you.\n");
  return 1; }
if(!str) { write("Search what?\n"); return 1; }
if(str != "chest") {
  write("You search the "+str+" and find nothing.\n"); return 1; }
if(str == "chest" && !opened) {
  write("You search the outside of the chest and discover a small\n"+
	"keyhole in the side.\n"); return 1; }
    if( !demon_cloned ) {
        write("You try and look in the chest, but it is too hot to approach!\n");
        return 1;
    }
if(str == "chest" && opened && K == 1) {
  write("You search the chest and find a small key in the bottom.\n");
  move_object(clone_object("players/dragnar/items/quest/mag4.c"),this_player());
  K = 0;
  return 1; }
else {
  write("You search the open chest and find it empty.\n");
  return 1; }
}
