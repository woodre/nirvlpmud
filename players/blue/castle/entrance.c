inherit"room/room";

reset(arg) {

   if(!arg) {

   set_light(1);
   short_desc = "The Grand Entrance";
   long_desc = 
"All around you are the remains of what once was very beautiful.  There are\n"+
"velvet chairs, all rotted away, paintings, all chipped and beaten.  There\n"+
"appears to be nothing of value here, but to the north you see an open space"+
"\nand to the east is another open space, with all kinds of obnoxious bright"+
"\nsigns flashing.\n";

   dest_dir = ({
      "players/blue/castle/entry1","north",
      "players/blue/stores/storefront","east",
      "players/blue/castle/pit_enter","west",
      "room/plane2","out"
   });

   }
}
