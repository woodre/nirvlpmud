

init() {
if(!environment()) return;
#ifndef __LDMUD__
add_action("catch_all"); add_xverb("");
#else
add_action("catch_all", "", 3);
#endif
call_out("destroy_this", 8);
}

catch_all(str){
write("You are frozen in shock from your symbiotes sudden retreat!\n");
return 1;
}


destroy_this(){
destruct(this_object());
return 1;
}

drop(){ return 1; }
get() { return 0; }
