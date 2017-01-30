id(str) { return str == "room";}
short() { return "Corridor of Elementals"; }
long() { write("This is a very long corridor.  It looks as though it has no end.\n"+
               "You get the feeling that you are not alone.\n");
         return 1;
}
reset(arg) { 
  if(!present("elemental", this_object())) {
    move_object(clone_object("/players/mouzar/quest/mon/earth"), this_object());
  }
  set_light(1);
}
init() {
  add_action("north","north");
  add_action("south","south");
}
south() {
  if(present("elemental",this_object())) {
    write("The elemental stands in your way.\n"); 
    return 1;
  }
  this_player()->move_player("south#/players/mouzar/quest/lhall4");
  return 1;
}
north() { 
  this_player()->move_player("east#/players/mouzar/quest/lhall2");
  return 1;
}
 
