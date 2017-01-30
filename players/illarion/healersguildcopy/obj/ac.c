int ac;
id(str) { return str == "acer"; }
 
drop() { return 1; }
get() { return 0; }

init() {
   if(this_player() == environment(this_object())) {
     if(!this_player()->query_ghost()) this_player()->set_ac(this_player()->query_ac() + ac);
     destruct(this_object());
     return 1; 
   }
}

class(a) { ac = a;}
