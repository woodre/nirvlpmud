#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;

if (!present("voice")) {move_object(clone_object("/players/francesco/quest/mobs/voice_geometry.c"),this_object()); }
if (!present("silent")) {move_object(clone_object("/players/francesco/quest/items/silent.c"),this_object()); }

set_light(1);

long_desc =
 "   You are in the geometry area of the library.  This is an aisle\n"+
 "that is surrounded on both sides by metallic shelves.  On these\n"+
 "shelves are several books.  A tag is suspended on the left shelf.\n",

items = ({
     "shelves","The metallic shelves are very simple and robust to hold several books",
     "shelf","You can see a tag suspended on it and a button that can be pushed to lift\n"+
             "it up in order to show other books",
     "tag","Some strange words are written on the tag.  It might be useful to read it",
     "aisle","The sides of the aisle are made by the shelves",
     "books","Most of them are pale green",
     "button","A red button which can lift the shelf",
});
}


init() {
  ::init();
  add_action("read","read");
  add_action("push","push");
}

push(str){
  if(!str) {notify_fail("Push what?\n"); return 0;}
  if(str=="button") { write("The shelf moves up.\n"); return 1;}
  write("You cannot push "+str+".\n");
return 1;}

read(str){
    if(!str){
      write("Read what?\n");
      return 1; }
    if(str=="tag"){
      write(
     "                             G E O M E T R Y\n"+
     "\nLa geometria e' lo studio delle     The geometry is the study of the \n"+
     "forme e delle dimensioni.  Puo'     shapes and of the sizes.  It can\n"+
     "essere effettuato attraverso        be performed through the use of\n"+
     "equazioni e formule.                equations and formulas.\n\n");
return 1;}
}

realm(){ return "NT"; }

short() {return ""+"Geometry";}  