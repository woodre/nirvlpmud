inherit "room/room";
 
reset(arg) {
object customer,cooler;
object machine;
object board;
object pinball;
int abc,xyz;
    if(arg) return;
    set_light(1);
   long_desc = "You are in the entrance area of Pizza Hut.  You are amazed by the size of this\n" +
     "place! To the east you can see the dining area and to the west seems to lead\n"+
     "to the back area of Pizza Hut.\n";
   short_desc = "The Entrance Area";
    dest_dir = ({ "/players/emerson/rooms/wait.c","west",
      "/players/emerson/rooms/room2.c","east",
      "/room/vill_shore","exit"});
board=clone_object("/players/emerson/obj/bb.c");
move_object(board,this_object());

pinball=clone_object("players/emerson/obj/pin.c");
move_object(pinball,this_object());
machine=clone_object("players/emerson/mons/machine.c");
move_object(machine,this_object());
    abc = 0;
    if (!present("customer")) 
     {
      while(abc<2) 
       {
        abc += 1;
        customer=clone_object("players/emerson/mons/cashier.c");
        move_object(customer,this_object());
       }
     }
    xyz = 0;
    if (!present("cooler"))
    {
     while(xyz<2)
      {
       xyz += 1;
       cooler = clone_object("players/emerson/mons/cooler.c");
       move_object(cooler,this_object());
       }
     }
}
