inherit "room/room";
reset(arg) {
  if(!present("hidz")) {
   move_object(clone_object("/players/stark/forest/mon/hidz.c"),this_object());
  }
  if (arg) return;
  set_light(1);
  short_desc="Cavern";
  long_desc=
"   The tunnel walls flatten out and smooth off as they curve south.  \n"+
"The ceiling too becomes less cragged and evens out.  The floor has a \n"+
"path picked clean of jagged rocks and swept of dust.  There are \n"+
"markings on the north wall.\n";

  items=({
"tunnel",
"The tunnel curves southward at this junction",
"walls",
"There seems order and care along these walls",
"ceiling",
"Although still with its bumps and cracks, the ceiling is much smoother than before",
"floor",
"The soft rock has been brushed off and polished to a shine",
"markings",
"Markings dug into the wall, perhaps you could read them",
"marks",
"Markings dug into the wall, perhaps you could read them"
  });

  dest_dir=({
    "/players/stark/forest/cavern6","south",
    "/players/stark/forest/cavern2","east"
  });
}   

init() {
  ::init();
  add_action("search","search");
  add_action("read","read");
}

read(str){
if(str == "marks" || str == "markings"){
write(
"    We are the Sithos,\n"+
"  We have lived here for only a short time.\n"+
"       We are the guardians of Sithos,\n"+
"      Please leave this place.\n");
return 1;}
write("Read what?\n");
return 1;}

search(str) {
  write("You briefly search about the cave and find nothing.\n");
  return 1;
}

