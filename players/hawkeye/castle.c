#define NAME "Hawkeye"
#define DEST "room/crop"
object ob;

id(str) { return str == "portal"; }

short() {
  return "Time portal to 1951";
/* Removed as monk guild no longer exists... -Snow 1/00
   return "Time portal to 1951\n"+
          "A small trail that leads west";
*/
}

long() {
    write("This is the Castle of Hawkeye\n");
}

init() {
  add_action("enter", "enter");
/* Removed as monk guild no longer exists.. -Snow 1/00
    add_action("west"); add_verb("west");
*/
}

enter(str) {
    if (!id(str))
	return 0;
    write("You feel yourself sucked into a dimensional portal.\n");
    this_player()->move_player("in a puff of smoke#players/hawkeye/room/entrance.c");
    return 1;
}

west() {
  this_player()->move_player("west#players/hawkeye/closed/guild/join.c");
  return 1;
}
reset(arg) {
object o;
  object ob;
object ob1,ob2;
object flyer;
if (arg)  
   return;
if(!present("M*A*S*H",find_object("room/quest_room.c"))) {
o = clone_object("obj/quest_obj");
call_other(o,"set_name","M*A*S*H");
call_other(o,"set_hint","Ask Radar for more help.\n");
move_object(o,"room/quest_room");
}
  move_object(this_object(), DEST);
/*
  ob = clone_object("players/hawkeye/closed/glass.c");
ob2 = clone_object("players/hawkeye/items/bam.c");
move_object(ob,this_object());
move_object(ob2,this_object());
  destruct(ob);

destruct(ob2);
    no autoloading wiztools - mythos <8-8-97>  */
}
is_castle(){return 1;}
