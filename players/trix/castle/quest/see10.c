inherit "room/room";
int discovered;
reset(arg) {
   object dog;
   if(arg) return;
   set_light(1);
   long_desc =
              "You reached the dead end of the path followed by the dirty water, the water\n"+
              "disappears in dark dephts flowing through a huge grating, and depositing\n"+
              "every kind of things on it.\n";
    short_desc = "A dirty sewer";
    items= ({ "grating","A large grating through which the dirty waters flow, its grid is full of waste\n"+
              "material, but maybe you could find something precious searching in it"}); 
    dest_dir = ({
                  "/players/trix/castle/quest/see9","west",
                  "/players/trix/castle/quest/sed9","northwest"
                                                        });
    discovered=0;
    dog=clone_object("/players/trix/castle/quest/monst/dog");
    move_object(dog,this_object());
    dog=clone_object("/players/trix/castle/quest/monst/dog");
    move_object(dog,this_object());
    dog=clone_object("/players/trix/castle/quest/monst/dog");
    move_object(dog,this_object());

}
init()
{  ::init();
  add_action("search","search");
}
search(arg)
{ object pen;
  if(present("dog",this_object())) { write("The dog won't let you search!\n"); return 1; }
  if(arg!="grid") { write("Search what?!?\n"); return 1; }
  if(discovered) { write("You search the grid but find nothing, someone must have preceded you!\n"); return 1; }
  discovered=1;
  write("You search the grid and find a wierd looking pendant, symbol of the cult of \nMelko.\n");
  pen=clone_object("/players/trix/castle/quest/monst/pendant");
  move_object(pen,this_player());
  return 1;
} 
realm(){return "NT";}
