
/*
 * SPHERE OF ANNIHILATION (3/25/94)
 * Will destruct any item put into it.
 * VALUE: 250
 */

get() { return 1; }

query_value() { return 250; }

id(str) { return str == "sphere"; }

short() { return "A sphere of annihilation"; }

long() {
   write("A large black sphere which pulses with energy.\n");
   write("You can insert items into the sphere to destroy them.\n");
   write("COMMAND: insert <item> into sphere\n");
}

init() {
   add_action("insert","insert");
}

insert(str) {
   string item, itemob;

   if(sscanf(str, "%s into sphere", item) != 1)
     return;
   itemob = present(item, this_player());
   if(!itemob) {
     write("You do not have a "+item+".\n");
     return 1;
   }
   if(itemob->id("ND") || itemob->drop()) {
     write("You attempt to insert the "+item+" but it is repelled "+
           "by the sphere.\n");
     return 1;
   }
   write("The sphere pulses as the "+item+" is inserted.\n");
   say(this_player()->query_name()+" inserts "+itemob->short()+
           " into a black sphere.\n");
   destruct(itemob);
   return 1;
}


