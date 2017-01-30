#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

int counter;

reset(arg) {
  if(arg) return;
counter = 0;
set_light(1);

short_desc = "Discovery" ;
long_desc =
     "   DISCOVERY SPACECRAFT,  1,000,000 MILES FROM EARTH\n"+
     "The hibernation room shows four aligned sarcophagi which hold some\n"+
     "of the crew of the Discovery.  They will be revived when the space\n"+
     "mission will come to its climax.  There is a connection to the hub\n"+
     "of the spacecraft.  The hub is located to the west and can be \n"+
     "accessed through a tube-shaped aisle.\n",

items = ({
   "hub","The center of the spacecraft",
   "aisle","A tube leading to the hub of the spacecraft",
   "sarcophagi","They are cylinders, about eight feet long, through their \n"+
                "windows it is possible to see the hibernating men.\n"+
                "With some efforts they might be 'open'ed",
});

dest_dir = ({
  "/players/francesco/2001/rooms/discovery25.c","west",
  "/players/francesco/2001/rooms/discovery14.c","south",
  "/players/francesco/2001/rooms/discovery17.c","north",
});

}



init(){
      ::init();
      add_action("open","open");
      }

open(str) 
  {
  if(!str) 
    {write("Open what?\n"); 
  return 1;}
  if(str!="sarcophagus") 
    {write("Open what?\n"); 
  return 1;}
  counter++;
  if(counter==5)
    {write("All the hibernating men had been revived already.\n");
  return 1;}
  write("As you open the sarcophagus, an hibernating man is revived.\n"+
        "A red flashing lamp goes on and a recorded voice starts speaking:\n"+
        "Attention, Attention, the hibernation procedure has been broken.\n");
  move_object(clone_object("/players/francesco/2001/mobs/hiberman.c"),this_object());
return 1;
}

