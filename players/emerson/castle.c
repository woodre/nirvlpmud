#define NAME "Emerson"
#define DEST "room/vill_shore"
object ob;

id(str) { return str == "hut"; }

short() {
return "A Pizza Hut ('enter hut')";
}

long() {
write("This is a Pizza Hut owned by Emerson.\n")+
write("It is now open!\n");
}

init() {
  add_action("enter", "enter");
}

enter(str) {
    if (!id(str))
	return 0;
    write("You enter the Pizza Hut.\n");
    this_player()->move_player("into the Pizza Hut.#players/emerson/rooms/enter.c");
    return 1;
}

reset(arg) {
  object ob;
if (arg)  
   return;
  move_object(this_object(), DEST);
}
is_castle(){return 1;}
