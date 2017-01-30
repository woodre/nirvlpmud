 
id(str) { return str == "room";}
short() {return "A rocky path";}
long() {write("This is a rocky path heading west to a large run down building.\n" +
               "You can hear the wild animals calling to each other.  Are they\n" +
               "planning to get together and kill you?\n" +
               "    There are two obvious exits: east and west\n"); return 1;}
  reset(arg) { if(!present("golem", this_object())) {
        move_object(clone_object("/players/mouzar/castle/monsters/ngolem"), this_object());
set_light(1);
}
}
          
 
 
init() {
        add_action("east","east");
        add_action("west","west");
}
 
 
 
 
west() {
   if((this_player()->query_level() >6) && (this_player()->query_level() <21) && (present("golem",this_object()))) {
        write("The golem stops you from going any farther down the path.\n"+
            "The Stone golem says: You are to high level to go any farther.\n"); return 1;}
          
        this_player()->move_player("west#/players/mouzar/castle/newbie/npath2");
         return 1;
      }
 
east() { this_player()->move_player("east#/players/mouzar/castle/path3");
return 1;
}
 
