id(str) {
   return str == "nothing";
}

long() { write("How can you look at nothing?\n"); }

short() { return; }

init() {
   if(this_player()->query_real_name()=="rich||this_player()->query_real_name=="haji") {
     return;}
#ifndef __LDMUD__
          add_action("do_nothing"); add_xverb("");
#else
           add_action("do_nothing","",3);
#endif
}

do_nothing(str) {
   if(!str) { return 0; }
   write("What?\n");
   return 1;
}

get() { return 1; }

drop() {
   if(this_player()->query_real_name() == "haji") { return 0; }
   return 1;
}
