inherit "room/room";
reset(arg) {
  if(arg) return;
 
short_desc = "A Temple Foyer";
long_desc = 
"This room has a few pictures hanging up on the walls, and in one \n"+
"corner of the room there is a desk. In another corner of the room is a \n"+
"bookshelf. The rest of the room is bare.\n";
  items=({
"pictures","Pictures of everyday things in Namekian life",
"desk","A desk covered in papers and books",
"bookshelf","This bookshelf appears to be empty",
"corner","A desk sits in the corner of the room",
"papers","Various papers concerning things around the temple",
"books","Books about the Namekian history",
"walls","The walls are covered by pictures of everyday things on Namek",
});
set_light(1);

dest_dir = ({
"/players/mosobp/areas/TEMPLE/rooms/temple10.c","south",
"/players/mosobp/areas/TEMPLE/rooms/temple14.c","west",
});
move_object(clone_object("/players/mosobp/areas/TEMPLE/NPC/prince.c"), this_object ());
move_object(clone_object("/players/mosobp/areas/TEMPLE/NPC/princess.c"), this_object ());
return 1;
}
