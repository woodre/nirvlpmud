#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;

if (!present("mosquito")) {
  move_object(clone_object("/players/francesco/univ/mob/mosquito.c"),
	this_object());  }

set_light(1);

short_desc = "A private booth" ;
long_desc =
     "    The walls of this private booth are engraved with graffiti\n"+
     "A toilet and a dispenser are the only items in here.\n",
items = ({
   "toilet","Plain white toilet, with a piggy-back water container",
   "dispenser","A paper dispenser, likely to clean yourself",
   "walls","Made of strong plastic, they can yet easily be engraved",
   "graffiti","For sure they were not done by a sane guy.\n"+
              "They depict all sort of bad images and poems",  

 });

dest_dir = ({
  "/players/francesco/univ/rooms/restroom.c","exit",
});

}
