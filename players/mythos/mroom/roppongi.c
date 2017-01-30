inherit "room/room";
reset(arg) {
  if(!present("messenger")) {
    move_object(clone_object("/players/mythos/mmon/bustle.c"),this_object()); }
  if(!arg) {
  set_light(1);
    short_desc = "<<Roppongi Station>> ";
    long_desc =
    "                    Roppongi Station\n"+
    "The air is humid and the sound of trains gives you a headache.\n"+
    "People walk about- people of many cultures and lands.  Here is\n"+
    "the place where western culture has caught hold powerfully and \n"+
    "many come here for business and pleasure....\n";
  items = ({
    "juliana","Head to the hottest place on earth",
    "shinjuku","Go to the place of commerce",
    "ginza","Shoppers galour!",
    "tower","Head to the famous Tokyo Tower",
    "out","Walk the streets for a while",
  });

  dest_dir = ({
     "/players/mythos/mroom/juliana.c","juliana",
    "/players/mythos/mroom/ginza.c","ginza",
    "/players/mythos/mroom/shinjuku.c","shinjuku",    
    "/players/mythos/mroom/ttower.c","tower",
    "/players/mythos/mroom/roppongi1.c", "out",
  });
} }
