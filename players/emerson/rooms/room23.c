inherit "room/room";
 
reset(arg) {
object customer,cooler;
int abc,xyz;
    if(arg) return;
    set_light(1);
   long_desc = "This is where the pizzas are taken from the oven\n" +
   "and cut into many slices. The cooks here are very busy.\n";
   short_desc = "Pizza Hut";
    dest_dir = ({ "/players/emerson/rooms/room21.c","east",
   "/players/emerson/rooms/room24.c","west"});

    abc = 0;
    if (!present("customer")) 
     {
      while(abc<1) 
       {
        abc += 1;
        customer=clone_object("players/emerson/mons/tcook.c");
        move_object(customer,this_object());
       }
     }
    xyz = 0;
    if (!present("cooler"))
    {
     while(xyz<3)
      {
       xyz += 1;
       cooler = clone_object("players/emerson/mons/cook.c");
       move_object(cooler,this_object());
       }
     }
}
