inherit"room/room";
   object war;

int dir;

reset(arg) {

   if(!arg) {

   set_light(1);
   short_desc = "An obsidian plane.";
   long_desc =
   "You find yourself standing on a 10' square piece of black obsidian rock"+
",\nthat appears to be suspended in mid air.  To the east and west hang similiar "+
"\nslabs of rock, magestically floating.  You see no sky, or ground, but "+
"\nseem to be in a huge room, with only blackness for the ceiling and ground."+
"\n  These great planes of shining black rock are each 10' apart, and you may"+
"\nbe able to jump between them, although you don't know exactly what is belo"+
"w\nor above you in this strange cavern.\n";

dest_dir = ({
   "players/blue/plane/plane2","east",
   "players/blue/plane/plane10","west"
});
   
   if(!present("warrior",this_object())) {
      war=clone_object("players/blue/monster/plane_guardian");
         move_object(war, this_object());
   }
   }
}

init() {

   add_action("move_check_east", "east");
   add_action("move_check_west", "west");

}

move_check_east() {
   dir=0;
   dir=3;
   move_check();
   return 1;
}

move_check_west() {
   dir=0;
   dir=4;
   move_check();
   return 1;
}

move_check() {
   if(!call_other("players/blue/plane/plane_server", "move_check")) {
      do_move();
   }
}

do_move() {
      if(dir==3) {
         say(capitalize(this_player()->query_name()) + " leaps to the east"+
            " and lands on the next plane.\n");
         write("You leap to the next plane.\n");
         move_object(this_player(), "players/blue/plane/plane2");
         command("look", this_player());
         say(capitalize(this_player()->query_name()) + " arrives.\n");
         return 1;
      }
      if(dir==4) {
         say(capitalize(this_player()->query_name()) + " leaps to the east"+
            " and lands on the next plane.\n");
         write("You leap to the next plane.\n");
         move_object(this_player(),"players/blue/plane/plane10");
         command("look", this_player());
         say(capitalize(this_player()->query_name()) + " arrives.\n");
         return 1;
   }
   if(capitalize(this_player()->query_name()) == "Blue") {
      write(file_name(enviorment(this_player()))+ "\n");
      }
   return 1;
}
