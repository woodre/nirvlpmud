inherit "room/room";
int found;

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "NW Guard Tower Loft";
long_desc =
"   Small cross shaped slits in the curved wall of the tower\n"+
"loft allow just a bit of light to enter the room.  Racks of\n"+
"arrows hang on the wall next to each viewing slit.  A trap\n"+
"door remains open in the center of the floor.  Matted straw\n"+
"and a few ragged blankets are piled together in a corner.\n";

items = ({
"slits",    "Vertical and horizontal slits about one foot wide,\n"+
            "which allow the archers room to shoot at attackers",
"wall",     "The wall is circular like the tower and made of stone",
"light",    "Sunlight entering from the slits in the wall",
"loft",     "The upper room of the SE Guard Tower",
"racks",    "Wooden racks holding scores of arrows each",
"arrows",   "Long wood arrows with metal fluted tips",
"door",     "A four foot trap door leading down",
"floor",    "Thick wooden beams worn smooth from many boots",
"straw",    "Pale yellow tall-grass from the valley",
"blankets", "Thickly woven woolen blankets. One looks rather odd",
"blanket",  "It seems to be wraped around some sort of object",

});

dest_dir = ({
   "/players/fakir/fcastle/room24.c", "down",
});
}

init()  {
  ::init();
    add_action("take_blanket","take");
}
take_blanket(arg)  {
if(!arg || arg != "blanket") {
notify_fail("It is not possible to take that.\n");
return 0; 
}
if(found==1) { write("The blanket has already been taken.\n"); 
return 1; 
}

write("You pick up and unwrap the blanket and find a statue!\n");
move_object(clone_object("/players/fakir/inn/OBJ/statue.c"),this_object());
found = 1;
return 1; 
}


