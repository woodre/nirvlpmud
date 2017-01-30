#define TP this_player()
#define TPN this_player()->query_name()
#define TPP this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Winespring Inn";
long_desc =
   "Curtains frame the window over looking the front of the inn and the\n"+
   "road through the village.  A bed with a straw tick mattress sits in\n"+
   "the corner.  A small night table sits next to the bed and a burning\n"+
   "candle throws fleeting shadows across the walls.  A leather backpack\n"+
   "is hanging on the bedpost and a staff is propped in the corner of the\n"+
   "room.\n";
           
items = ({
   "mattress",  "Heavy white cloth filled with shredded straw and grasses",
   "curtains",  "Plain white curtains with a sheer panel sewn into the fabric",
   "window",    "A four pane glass window common to the area. The glass is\n"+
                "somewhat cloudy due to the poor magic used in making it.\n"+
                "You can see the road and beyond that the Winespring River",
   "bed",       "A square four post bed with a flat wooden headboard",
   "covers",    "A hand sewn quilt and a woolen blanket over cotton sheets",
   "table",     "A wooden nightstand of sorts, it holds a candle and a book",
   "candle",    "A half burned wax taper with a cotton wick",
   "walls",     "Covered in a colorful paper and a wooden chair rail on all sides",
   "bag",       "A canvass draw string bag with a long leather strap for ease in\n"+
                "carrying it over ones shoulder.  The bag is closed",
   "road",      "The dirt road going north south through the village and skirting\n"+
                "the east bank of the Winespring River",
   "backpack",  "A strong leather pack aielmen carry in the boarderlands",
   "staff",     "A stout staff and a very formidible weapon",
});
if(!present("maid",this_object()))
 move_object(clone_object("/players/fakir/inn/NPC/maid.c"),this_object());

dest_dir = ({
   
   "/players/fakir/inn/room28.c",  "hall",});

}
