inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Kitchen";
  long_desc = 
   "You have entered a spacious kitchen. A multitude of cabinets hang on\n"+
   "the southern and western walls, while a fire carresses a boiling\n"+
   "kettle in the fireplace, north. A sink set in a large counter stands\n"+
   "in the center of the room containing dirty untensils and dishware.\n"+
   "Doors lead northeast, east, south and west.\n";
  items = ({"cabinets",
            "The cabinets contain various dishware, cookingware, and foodstuffs\nfrom pasta to something call 'Twinkies'",
            "kettle",
            "The kettle looks to contain some sort of broth",
            "fireplace",
            "The kettle looks to contain some sort of broth",
            "sink",
            "These dishes need washing"});
  dest_dir = ({"players/bastion/isle/wiz/subhall", "northeast",
               "players/bastion/isle/wiz/pantry", "east",
               "players/bastion/isle/wiz/w_hall2", "south",
               "players/bastion/isle/wiz/great_hall", "west"});
  }
}
