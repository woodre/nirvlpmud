#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
if (!present("tecnico1")) {
  move_object(clone_object("/players/francesco/univ/mob/tecnico1.c"),
	this_object());  }

if (!present("laser")) {
  move_object(clone_object("/players/francesco/univ/items/laser.c"),
	this_object());  }


set_light(1);

short_desc = "Machine tools laboratory" ;
long_desc =
     "    The machine tools present in this laboratory are really \n"+
     "astonishing.  The lathe, the milling machine and the grinder\n"+
     "are not very new yet perfectly maintained.  However, the \n"+
     "non-traditional ones, namely the EDM, the Laser and the \n"+
     "Water-jet demonstrate that the departmental research is really\n"+
     "up to date.  Further, a little laser calls your attention.\n",
items = ({
  "laser","Just a small tube, with a little orifice at one end.  It shows also\n"+
         "some engravings on it: 'Laser beam, caution'.  You feel like you\n"+
         "could 'grab' it, but it might be very dangerous.",
  "lathe","Horizonthal lathe for machining mainly axysimmetric items",
  "milling","It can produce differently shaped surfaces by interaction of a rotating\n"+
            "tool with the material",
  "grinder","It works with grinding wheels rotating at high speed. By means of\n"+
            "suitable abrasives it is possible to attain very low roughness",
  "edm","Electrical Discharge Machine, the sparks between the tool and the work\n"+
        "remove the material. It can machine very hard materials",
  "water-jet","Low precision machine but with high productivity, using the power\n"+
              "of a high pressure water stream",



});



dest_dir = ({
   
   "/players/francesco/univ/rooms/dimec5.c","west",
});

}
