 
id(str) {return str == "dust" || "buster" ;}
 
short() {return str == "A dust buster" ;}
 
long() {return str == "To use type destroom\n.";}
                                                 
get() { return 1;}
 
drop() { return 0;}
 
init() {
  add_action ("destroom", "destroom");
 }
 
destroom(str) {
   string what;
   object ob, me;
 
  
   ob = present(what, environment(this_player));  
   while ob {
        
   if(!ob) {
     write("This room has nothing to dest.\n");
     return 1;
   }
   destruct(ob);
   write("You dested a "+what+" from room.\n");  } 
   return 1;
}

