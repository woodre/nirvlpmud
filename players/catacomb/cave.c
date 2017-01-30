#define TPN this_player()->query_name()
inherit "room/room";

reset(arg) 
{
  if(arg) return;
 set_light(1);

 short_desc ="The forgotten cave";
 long_desc =
 "  You enter into a dark cave.  Hieroglyphics are written on the\n"+
 "walls.  The shadows shroud every corner of the cave.  Perhaps you\n"+
 "could 'trace' the glyphs and see what they do.\n";

 items = ({
   "hieroglyphics",
   "There are two now in the shape of a forest and dragon", 
   "hieroglyphic",
   "There are two now in the shape of a forest and dragon", 
   "glyph",
   "There are two now in the shape of a forest and a dragon",
   "glyphs",
   "There are two now in the shape of a forest and a dragon",
   "shadow",
   "The shadows cover every inch of the cave",
   "shadows",
   "The shadows cover every inch of the cave",
   "corner",
   "The shadows take away all light from the corners",
   "corners",
   "The shadows take away all light from the corners"
   });

 dest_dir = ({
   "/room/south/sforst8.c","out" 
   });
if(!present("nahog"))
	  move_object(clone_object("/players/catacomb/nahog.c"),
	   this_object());

}
query_no_fight(){ return 1; }  


init(){
  ::init();

      add_action("listenem","listen");
	add_action("trace", "trace");
  }

listenem(str)
{
  write("You here the old man utter something under his breath.\n");
  say(TPN+" listens to the sounds of the cave.\n");
  return 1;  
}
trace(str)
{
  if (!str)
  {
     write("You can only trace the forest and the dragon now.\n");
     return 1;
  }
  if (str == "forest")
  {
     write(" You slowly trace the outline of the forest, and\n"+
          "slowly fade away.\n");
     say(TPN+" slowly traces the forest and disappears.\n");
     this_player()->move_player("trace#players/catacomb/barbtribe/brooms/barbentrance.c");
     return 1;
  }
  if (str == "dragon")
  {
     write(" You slowly trace the outline of the dragon, and\n"+
          "slowly fade away.\n");
     say(TPN+" slowly traces the dragon and disappears.\n");
     this_player()->move_player("trace#players/catacomb/Cavern/rooms/ground.c");
     return 1;
  }

}
