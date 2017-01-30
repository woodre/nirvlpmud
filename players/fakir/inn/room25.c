#define TP this_player()
#define TPN this_player()->query_name()
#define TPP this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Winespring Inn";
long_desc =
   "Curtains frame the window overlooking the back of the inn.  The\n"+
   "roof of the stables is visible through the glass panes.  A bed\n"+
   "with a straw tick mattress sits in the corner.  A closed traveling\n"+
   "bag lies atop the bed.  A small night table sits next to the bed\n"+
   "with an unlit oil lamp resting upon it.\n";
           
items = ({
   "mattress",  "Heavy white cloth filled with shredded straw and grasses",
   "curtains",  "Plain white curtains with a sheer panel sewn into the fabric",
   "window",    "A four pane glass window common to the area. The glass is\n"+
                "somewhat cloudy due to the poor magic used in making it",
   "roof",      "Split wooden shakes racked from bottom to top",
   "stables",   "A long wooden structure where guests horses are kept",
   "panes",     "Cloudy glass about a quarter snitch thick",
   "bed",       "A square four post bed with a flat wooden headboard",
   
   "table",     "A wooden nightstand of sorts, it holds a candle and a book",
   "lamp",      "A glass lamp empty of any oil",
   "walls",     "Covered in a colorful paper and a wooden chair rail on all sides",
   "bag",       "A leather bag with a large center pocket and double draw string\n"+
                "pockets on each side",
});

dest_dir = ({
   
   "/players/fakir/inn/room28.c",  "hall",
   
});

  }
init()  {
   ::init();
     add_action("open_bag","open");
              }
     open_bag(arg) {
     if(arg != "bag"){ write("What do you want to open?\n"); return 1; }
   write("You open the bag and find a thiefs shim.\n");
   say (this_player()->query_name() +" opens the bag and finds a thiefs shim.\n");
   return 1;  
              }
