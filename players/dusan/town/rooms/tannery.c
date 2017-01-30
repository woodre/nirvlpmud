#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
 if(!present("tanner")){
     move_object(clone_object("/players/dusan/town/mobs/tanner.c"), this_object());}  
  if(arg) return;
set_light(1);

short_desc = "Tannery";
long_desc =	
           "   A foul stench assualts you as you enter this large wooden \n"+
           "structure.  There are animal skins hanging everywhere and large\n"+
           "wooden vats that contain some unidentifiable mess that seems to \n"+
           "where the foul smell is coming from. The only obvious exit is \n"+
           "back to the west. \n" ;
items = ({
  "road","You can see the main road to through the door",
  "stentch","An indescribable stentch",
  "structure","A large wooden structure",
  "skins","Various animal skins some with fur somewith out",
  "vats","Large wooden vats filled with a dark liquid mess",
  "mess","A liquid with all kinds of foul smelling substances it seems to be what the skins are cured in",
});

dest_dir = ({
  "/players/dusan/town/rooms/twn6","west",
});

}
