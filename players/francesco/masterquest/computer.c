#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;

if (!present("computer")) {move_object(clone_object("/players/francesco/masterquest/puter.c"),this_object()); }

set_light(1);

long_desc =
 "   The computer room is an open area, delimited by colored lines\n"+
 "painted on the floor.  Some metallic shelves lie along the walls.\n"+
 "On a side table there is a computer.  Some students run back and \n"+
 "forth and sit at the chair in front of the table, to 'login' into\n"+
 "Fran's computer.\n",

items = ({
     "shelves","The metallic shelves are very simple and robust to hold some user manuals",
     "students","They seem very busy and concentrated on their work",
     "table","A small desk with a chair in front of it",
     "chair","The chair seems confortable",
     "lines","They delimitate the area",
     "walls","Recently painted with a relaxing color",
     "floor","The floor is made of tiles and shiny",

});


dest_dir = ({
    "/players/francesco/masterquest/lab.c","exit",
});
}


init() {
  ::init();
}


short() {return ""+"Computer lab";}  

