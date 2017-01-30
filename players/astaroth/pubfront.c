inherit        "room/room";
 
reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "The Horse and Groom";
  long_desc =
 "You are standing outside the Horse and Groom pub.\n"+
              "Popping in and having a few drinks seem like a good\n"+
              "idea to you right now.\n"+
  "\n";
  items = ({"window",
            "You see people inside drinking like they are unware that the world may\nend in about 20 minutes."});
  dest_dir = ({"players/astaroth/pub", "in",
               "players/astaroth/chapel", "south",
               "players/astaroth/vogon", "east"});
  }
}
