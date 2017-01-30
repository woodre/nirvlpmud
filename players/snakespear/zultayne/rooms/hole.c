inherit "room/room";

reset(arg){
   if(!present("gargoyle")) {
     move_object(clone_object("/players/snakespear/zultayne/critters/rubygar.c"),this_object());
   }
   if(arg) return;
      
set_light(0);
short_desc="Dark Hole";
long_desc=
  "  This is a burrow just underneath the foyer floor.  This appears to\n"+
  "be a hiding place for a warrior.  There isn't much to look at here,\n"+
  "except the bones lying scattered all over the floor.  The aroma here\n"+  
  "is awful.  The only light source is a small amount of light, leaking\n"+
  "in from the small hole through which you entered.  There are quiet\n"+
  "voices calling from somewhere.\n";


items=({
     "bones", "Bones from past victims of the Ruby Gargoyle",
     "hole", "A small hole in the ceiling.  It leads back to the foyer",
     "floor","The floor covered with blood and rotting flesh",
     "blood","Dried poools of blood",
     "flesh","Ripped away by claws, this flesh lays here and rots",
     "foyer","The luxurious entrance room to Zultayne",
});
      
      
dest_dir=({
        "/players/snakespear/zultayne/rooms/foyer.c","climb",
});
      
}

realm() { return "NT"; }

init()  {
    ::init();
    add_action("search_room","search");
    add_action("smell","smell");
    add_action("listen","listen");
}

search_room(str) {
      if(!str) {
            write("What do you want to search?\n");
            return 1; }
   if(str == "bones") {
	    write("You shuffle around in the dried bones and find nothing.\n");
	    return 1; }
	  else {
	    write("You search the "+str+" but find nothing.\n");
	    return 1; }  
}
smell(str) {
      if(!str) {
            write("What do you want to smell?\n");
            return 1; }
   if(str == "aroma") {
	    write("You smell an awful stench, must be from all the corpses.\n");
	    return 1; }
	  else {
	    write("You try to smell "+str+", but can't smell anything unusual.\n");
	    return 1; }  
}
listen(str) {
      if(!str) {
            write("What do you want to listen to?\n");
            return 1; }
   if(str == "voices") {
	    write("You can hear these quiet voices, but can't make out a word.\n");
	    return 1; }
	  else {
	    write("You strain to hear the "+str+", but never hear a thing.\n");
	    return 1; }  
}
