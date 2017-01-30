  inherit "room/room";
  reset(arg){

    if(!arg){
    set_light(1);

   short_desc="Barren Earth ";
   long_desc=
  "You are south of the stable area, and the land is barren and \n" +
  "desolate.  There is an aura of malevolence in the air, and you\n" +
  "are filled with foreboding.  If you are not very strong and brave,\n" +
  "you should return to the castle!  The ground feels strange beneath\n" +
  "your feet, and it seems as if any step you take could emperil you\n" +
  "further.  It is DANGEROUS, go back before it is too late!\n";
   
  items=({
   "ground", "The ground looks normal, but feels strange, and to the\n"+
   "south is hidden by thick, dead grass and foliage",
   
  });
   dest_dir=({
  "/players/arrina/grounds/hunttrap.c","south",
  "/players/arrina/grounds/stable.c","north",
  
   });
}
}
