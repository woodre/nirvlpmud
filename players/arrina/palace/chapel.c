inherit "room/room";
reset(arg) {
  if(!arg) {
  set_light(1);
    short_desc = "Chapel";
    long_desc =
   "You have entered an immense chapel extending the length\n"+ 
   "and height of the castle. Rows of pews, carved from\n"+ 
   "oak, fill the chapel. The walls contain scenes in\n"+ 
   "stained glass depicting Paladins on war-horses engaged\n"+ 
   "in combat and carrying out heroic deeds. The figures\n"+ 
   "are backed by a trail of holy fire that extends through\n"+ 
   "each scene up to a bronze bowl, where it blazes over a\n"+ 
   "central altar. An aura of holiness and power fills\n"+ 
   "the chapel.\n";
  items = ({
   "pews", "These are uncomfortable pews designed for true penance and suffering",
   "scenes" , "The scenes glow in the light of fire",
   "glass","The scenes glow in the light of fire",
   "paladins","Heroic and righteous figures they are",
   "altar","This is a plain, undecorated altar",
   "fire", "The fire has an aura of immense holy power",
   "bowl","The fire has an aura of immense holy power",
  });

  dest_dir = ({
    "/players/arrina/palace/entry.c","west",
  });
} }

