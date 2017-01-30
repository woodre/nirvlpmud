inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Closet";
  long_desc = 
   "This small room smells of mothballs. Several boxes lie on the floor.\n";
  items = ({"boxes",
            "The boxes, made of some light-weight material, are empty"});
  dest_dir = ({"players/bastion/isle/wiz/w_hall1", "north"});
  }
}
