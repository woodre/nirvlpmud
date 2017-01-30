inherit "room/room";
reset(arg) {
  if(arg) return;

short_desc = "An Altar ";
long_desc = 
"This is the altar of the temple. Many people come here to worship \n"+
"and pray. Tapestries depicting famous battles throughout time. The \n"+
"wall is painted a dull grey color with wood trim.\n";
  items=({
    "trim","Trim made of a solid wood that is stained a darker shade",
"tapestries", "You see a group of tapestries on each wall.\n"+
"On the west wall you see a tapestry of the fight between Kami and Piccolo.\n"+
"On the north wall you see a tapestry of the fight between Nail and Frieza.\n"+
"On the east wall you see a tapestry of the fight between Piccolo and Frieza.\n"+
"On the south wall you see a tapestry of the fight between Piccolo and Cell",
"wall","The wall is painted a light grey that can barely be made out from the stone",
"altar","This is the place in which people come to pray and worship",
});
set_light(1);

dest_dir = ({
"/players/mosobp/areas/TEMPLE/rooms/temple13.c","north",
"/players/mosobp/areas/TEMPLE/rooms/temple9.c","east",
"/players/mosobp/areas/TEMPLE/rooms/temple3.c","south",
"/players/mosobp/areas/TEMPLE/rooms/temple7.c","west",
});
move_object(clone_object("/players/mosobp/areas/TEMPLE/NPC/dende.c"), this_object());
return 1;
}
