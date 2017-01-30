 
id(str) { return str == "room";}
short() {return "A rocky path";}
long() {write("This is a rocky path that leads into a small Halfling village.\n"+
               "You can hear the wild animals calling to each other.  Are they\n" +
               "planning to get together and kill you?\n" +
               "    There are two obvious exits: east and west\n"); return 1;}
  reset(arg) { if(!present("sign", this_object())) {
        move_object(clone_object("/players/mouzar/castle/newbie/sign2.c"), this_object());
set_light(1);
}
}
          
 
 
init() {
        add_action("east","east");
        add_action("west","west");
}
 
 
 
 
west() {
   if((this_player()->query_level() >6) && (this_player()->query_level() <21)) {
        write("As i said before. NO ONE ABOVE 5TH LEVEL!!!!!!\n"); return 1;}
          
        this_player()->move_player("west#/players/mouzar/castle/newbie/trail33");
         return 1;
      }
 
east() { this_player()->move_player("east#/players/mouzar/castle/newbie/npath1");
return 1;
}
