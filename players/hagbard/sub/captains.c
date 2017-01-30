
  


reset(arg) {
     object fi,ob;

    if(present("door",this_object())) {
       fi=present("door",this_object());
       destruct(fi);
    }


      if (arg) return;
      set_light(1);
}


short(){

   return "Hagbard's ready room.";
}


long() {

   write("This is Hagbard's ready room.  It is a magnificant room.\n");
   write("The only exit is to the east.\n");
}

init() {


      add_action("move","east");
      add_action("search","search");
      add_action("shit","north");
}



move(){

     call_other(this_player(),"move_player","east#/players/hagbard/sub/contower");
     return 1;
}

search() {
    object duh;

  if(present("door")) write("There is only a secret door to the north.\n");
    else {
    write("You find a secret door leading north.\n");
    duh = clone_object("/players/hagbard/things/door.c");
    move_object(duh,this_object());
}
    return 1;
}
shit(){

   if (present("door"))
   call_other(this_player(),"move_player","north#/players/hagbard/sub/capsroom");
   else
      write("You can't go that way.\n");
   return 1;
}
