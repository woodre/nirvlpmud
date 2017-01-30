
/*
 * SCROLL (2/15/94)
 * Given to an invited player so they can learn more of the guild
 */

id(str) { return str == "scroll"; }

get() { return 1; }

query_value() { return 0; }

drop() {
   write("The scroll crumbles as it leaves your hand.\n");
   destruct(this_object());
   return 1;
}

short() { return "A large golden scroll"; }

long() {
   write("}-=-=-=-=-=-{ AN INVITATION TO THE PALADINS }-=-=-=-=-=-{\n");
   write("To learn more about the Paladins:  info, info <topic>\n");
   write("To join: join\n");
   write("The Paladins Guild is located in Sandman's castle.\n");
   write("}-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-{\n");
}

init() {
   add_action("info","info");
   add_action("join","join");
}

info(str) {
   if(!str) {
     cat("/players/sandman/paladin/helpdir/info");
     return 1;
   }
   if(!cat("/players/sandman/paladin/helpdir/"+str)) 
     write("No such help file: "+str+"\n");
   return 1;
}

join() {
   call_other("/players/sandman/paladin/entry","join");
   return 1;
}

