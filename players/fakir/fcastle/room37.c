inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Great Hall";
long_desc =
"   An expansive hall with tall walls and a vaulted ceiling .  Thick\n"+
"columns run the center length of the hall and support a huge wooden\n"+
"beam which in turn supports the ceiling.  Banquet tables and chairs\n"+
"are set about the room, and servants bustle between them in hasty\n"+
"preparations for a large royal feast.  There is a door in the east\n"+
"wall to the chapel, and another in the west wall to the kitchens.\n"+
"The hall continues to the north.\n";

items = ({
"hall",    "The hall in which you stand",
"walls",   "The interior walls of the great hall. They are covered with\n"+
           "paintings, murals, and tapestries",
"ceiling", "A high ceiling slanting downward from the center east and west",
"columns", "Hand cut columns of wood, each as large as a mature fur tree",
"beam",    "A three foot by three foot square beam",
"tables",  "Ornate tables with guilded legs and rosette trim",
"chairs",  "They match the tables in design and purpose",
"room",    "The great hall of the castle",
"servants","Those who willingly serve the royal family",

});
if(!present("trolloc",this_object()))
 move_object(clone_object("/players/fakir/woods/TEMP/trolloc4.c"),this_object());

dest_dir = ({
   "/players/fakir/fcastle/room38.c", "north",
   "/players/fakir/fcastle/room32.c", "south",
   "/players/fakir/fcastle/room39.c", "kitchen",
   "/players/fakir/fcastle/room41.c", "chapel",
});
}


