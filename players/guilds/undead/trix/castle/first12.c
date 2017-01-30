inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc =
"This room is utterly astounding. It is impossible to mistake this room for\n"+
"any other than the castle library. A balcony surrounds the room separating it\n"+
"into levels. Shelves line every wall. Leather bound books line every shelf\n"+
"from floor to ceiling on both levels. Tables or what is left of them are\n"+
"spread across the floor. A man wanders about the room dusting, and replacing\n"+
"the books. Olny one book is slightly out of place. A set of spiral stairs\n"+
"leads up to the balcony. On the northern wall there is a door covered in\n"+
"religious ruins. To the west the main gallery.\n";
    short_desc ="The castle library";
    dest_dir = ({
                  /* "/players/trix/closed/guild/castle/second","up", */
                  "/players/trix/closed/guild/castle/first4.c","north",
                  "/players/trix/closed/guild/castle/first3.c","west"
                                                        });
    items=({ "book","\bA dusty old book that is slightly out of place"});
}
init(){
 ::init();
     add_action("pull","pull");
     }
pull(str)
{ if(str=="book") {
   write("You pull the book and a part of the shelves lined wall spins and sinks back.\n"+
         "Darkness engulfes you as you enter the passage before the wall closes up\n"+"behind your back.\n");
   move_object(this_player(),"/players/trix/closed/guild/castle/first13");
   return 1;
   }
  return;
}
realm(){return "NT";}

