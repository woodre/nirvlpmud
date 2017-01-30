

/*
 * POTION OF HEALING (3/19/94)
 * Will heal 100 hp
 */

id(str) { return str == "potion"; }

reset(arg) {
   if(arg)
     return;
}

get() { return 1; }

query_value() { return 1000; }

short() { return "A potion of healing"; }

long() {
   write("A medium sized glass bottle containing a bluish liquid.\n");
   write("It is a potion of healing.\n");
}

init() {
   add_action("drink","drink");
}

drink(str) {
   if(!str || !id(str))
     return;
   write("You drink the potion in one huge gulp.\n");
   say(this_player()->query_name()+" quaffs a potion.\n");
   this_player()->heal_self(50);
   write("You feel better!\n");
   destruct(this_object());
   return 1;
}

