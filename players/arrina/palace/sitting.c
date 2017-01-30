inherit "room/room";
reset(arg) {
  if(!arg) {
  set_light(1);

  short_desc = "Sitting Room";

  long_desc =
    "You have entered a sitting room where guests wait to be\n"+
    "received by the masters of this castle. Comfortable\n"+ 
    "sofas and chairs carved from Rowan wood are set within.\n"+  
    "Upon many rows of shelves sit a variety of books, ranging\n"+ 
    "from fairy tales to the art of warfare, for guests to\n"+ 
    "examine while they wait. The chamber is lit and warmed\n"+ 
    "by flames from a fireplace set in the opposite wall.\n"+ 
    "Upon the mantel of the fireplace lies a crystal rose\n"+ 
    "within a glass case. An inscription upon the case reads,\n"+ 
    "'To My Beloved'. A faint, calming music seems to emanate\n"+ 
    "from the walls.\n";

  items = ({
    "sofas","Exquisite, yet comfortable, furniture fills the\n"+ 
    "room. You feel an aura of protection when\n"+ 
    "seated here",
    "chairs","Exquisite, yet comfortable, furniture fills the\n"+ 
    "room. You feel an aura of protection when\n"+ 
    "seated here",
    "shelves","You find a wide selection of books to satisfy\n"+ 
    "any interest",
    "books","You find a wide selection of books to satisfy\n"+ 
    "any interest",  
    "fireplace","The fire blazes peacefully",
    "fire","The fire blazes peacefully",
    "rose","This delicate crystal rose was grown with a beauty\n"+ 
    "unmatched in this world",
  });

  dest_dir = ({
    "/players/arrina/palace/feasthall.c","north",
    "/players/arrina/palace/entry.c","east",
  });
} }









