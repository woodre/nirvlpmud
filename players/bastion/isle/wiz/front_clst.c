inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Front Closet";
  long_desc = 
   "Several hangers are on a pole attached from one wall to another here.\n";
  items = ({"hangers",
            "There are empty at the moment",
            "pole",
           "The pole is simply a wooden rod that supports hangers"});
  dest_dir = ({"players/bastion/isle/wiz/foyer", "east"});
  }
}
