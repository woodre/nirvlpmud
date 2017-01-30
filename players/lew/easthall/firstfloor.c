inherit "room/room";

reset(arg){
   object guard;
   if(!arg) {
      set_light(1);
      short_desc = "First East";
      long_desc =
      "Welcome to the first floor of East Hall.  below here is what is\n"+
      "know as the time machine.  Hundreds of hours are spent here by \n"+
      "those that reside here.  You may even find a few people you know. \n";
      
      
      move_object(clone_object("players/lew/easthall/ben"), this_object());
      dest_dir = ( {
            "players/lew/easthall/basement", "down",
            "players/lew/lounge2", "west",
            });
   }
   
}

/*  added for quest 3/29/97  Eurale  */
init() {
  ::init();
  add_action("down","down");
}

down() {
if(present("gonzo")) {
  write("Gonzo snickers, 'They're working down there!'\n");
  return 1; }
else {
  this_player()->move_player("down#players/lew/easthall/basement.c");
  return 1; }
}
