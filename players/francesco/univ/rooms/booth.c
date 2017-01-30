#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;


set_light(1);

short_desc = "Info center";
long_desc =
   "   This room has two doors that will lead you to those rooms where\n"+
   "the visitors who come to the University can get first aid info.\n"+
   "Some posters and a sign hang on the walls.\n";

items=({
        "posters","They depict some overhead views of the University",
        "doors","Revolving type doors, located one in front of the other",
        "sign","The sign reads:\n"+
               "WEST  for info about University physical layout\n"+
               "EAST  for info about University educational programs",
        "walls","Very clean white painted walls",
});

dest_dir = ({
  "/players/francesco/univ/rooms/main_entrance.c","southwest",
  "/players/francesco/univ/rooms/booth2.c","east",
  "/players/francesco/univ/rooms/booth3.c","west",
});

}
