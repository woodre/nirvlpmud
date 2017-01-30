inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "SE Guard Tower Loft";
long_desc =
"   Small cross shaped slits in the wall allow just a bit\n"+
"of light to enter the loft.  Racks of arrows hang on the\n"+
"wall next to each viewing slit.  A trap door lies open in\n"+
"the center of the floor.\n";

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

});

dest_dir = ({
   "/players/fakir/fcastle/room18.c", "down",
});
}


