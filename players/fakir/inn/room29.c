#define TP this_player()
#define TPN this_player()->query_name()
#define TPP this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(0);

short_desc = "Winespring Inn";
long_desc =
   "A blackend animal hide is tacked over the window of this room blocking out\n"+
   "all light.  The bed is neatly made and has been fitted with clean sheets and\n"+
   "costly blankets sewn of otter and fox skins.  The room is quite warm.\n";
           
items = ({
   
   "window",    "A four pane glass window common to the area", 
   "bed",       "A square four post bed with a flat wooden headboard",
   "hide",      "You cannot determine its origin nor what type of beast it may\n"+
                "have been taken from",
   "sheets",    "Tan in color and made from cotton",
   "blankets",  "Sewn skins of otter and fox",
   "longbow",   "The prefered weapon of the beastmen",
   "quiver",    "Stiched with animal gut and deeply tanned it is a work of art",
   "arrows",    "Wicked broadheads and firebird flething set them apart from the\n"+
                "normal arrows used in the two rivers area", 
   
});
if(!present("beastman",this_object()))
 move_object(clone_object("/players/fakir/inn/NPC/beastman.c"),this_object());

dest_dir = ({
   
   "/players/fakir/inn/room27.c",  "hall",});

}
