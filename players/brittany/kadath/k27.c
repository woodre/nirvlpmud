#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
int KEY;

reset(arg) {
   if(arg) return;
KEY = 1;
   set_light(1);
   
   short_desc = WHT+"Ulthar village"+NORM;
   long_desc =
   "     The path is scattered with some small stones.  There is\n"+
   "something small shinning on the path.  The stones trail alongside\n"+
   "the river, like some sort of guide.  On the last stone, there\n"+
   "is an arrow with some markings below it.  There is a cave east\n"+
   "of here and a huge cemetary is off to the west.\n";
   
   items = ({
         "path","The path leads south, you notice something on the\n"+
         "path, maybe you should 'search' it",
         "stones","Small different shaped stones",
         "stone","A big stone with markings and an arrow carved into it",
         "towers","The circular stone towers",
         "cave","A dark opening leads into the cave",
         "opening","A dark opening leading into the cave",
         "cemetary","The cemetary has cyclopean round towers",
         "tavern","A small tavern is west of here",
         "river","A natural stream of flowing water",
 "arrow","An arrow carved into the stone points 'south', some\n"+        
         "markings are scribe below it",
         "markings","Markings scribe below the arrow, maybe you should 'read' it",
          });

   dest_dir = ({
        "/players/brittany/kadath/k23.c","north",
        "/players/brittany/kadath/k29.c","east", 
        "/players/brittany/kadath/k32.c","west",
          });
   
}
init(){
::init();
add_action("search","search");
add_action("read","read");
}
 
search(str){
 if(!str || str != "path") {
  notify_fail("Search what?\n");
  return 0;
}
   if(!str || str != "path") {
      notify_fail("You search the "+str+" and find nothing of interest.\n");
      return 0;
   }
 
  if(str == "path" && KEY == 1) {
   write("You search the path and find a key.\n");
move_object(clone_object("/players/brittany/kadath/OBJ/merchant_key.c"),this_player());
   KEY = 0;
return 1; }
else {    
      write("You search the path and find nothing.\n");
      return 1; }
}

read(str) {
    if(!str || str != "markings") {
        notify_fail("What do you want to read?\n");
        return 0; }
 
    write(
   "The markings read:\n\n"+
    "West of here is the realm of the stone circular towers.\n");
     return 1;
}
