inherit "room/room";
 
reset(arg) {
object customer,michael;
    int abc;
    if(arg) return;
    set_light(1);
    long_desc = "You notice something different about this part of the dining area.\n"+
    "The customers look more like mobsters from the Corleone\n"+
    "crime family! Maybe you should leave before they see you!\n";
   short_desc = "The Dining Area";
    dest_dir = ({ "/players/emerson/rooms/room2.c","west",
              "/players/emerson/rooms/dine10.c","east",
                  "/players/emerson/rooms/dine2.c","south"});


     michael=clone_object("players/emerson/mons/michael.c");
     move_object(michael,this_object());

    abc = 0;
/* if (!present("customer")) changed to check for man  -Snow */
  if(!present("button man"))
     {
      while(abc<3) 
       {
        abc += 1;
        customer=clone_object("players/emerson/closed/button.c");
        move_object(customer,this_object());
       }
     }
}
