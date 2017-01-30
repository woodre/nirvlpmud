#define TP this_player()
#define TPN this_player()->query_name()
#define TPP this_player()->query_possessive()
inherit "room/room";
int found;

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Winespring Inn";
long_desc =
   "Curtains frame the window over looking the front of the inn and the\n"+
   "road through the village.  A bed with a straw tick mattress sits in\n"+
   "the corner.  A small night table sits next to the bed and a burning\n"+
   "candle throws fleeting shadows across the walls.  A small traveling\n"+
   "case is on the bed.\n";
           
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
   "case",      "A small black case, of the sort used to carry valuable items,\n"+
                "Perhaps you should open it",
});
if(!present("fchild",this_object()))
 move_object(clone_object("/players/fakir/inn/NPC/fchild.c"),this_object());
if(!present("mchild",this_object()))
 move_object(clone_object("/players/fakir/inn/NPC/mchild.c"),this_object());
if(!present("twife",this_object()))
 move_object(clone_object("/players/fakir/inn/NPC/twife.c"),this_object());

dest_dir = ({
   
   "/players/fakir/inn/room23.c",  "hall",});

}
init()  {
  ::init();
    add_action("open_case","open");
}
open_case(arg)  {
if(!arg || arg != "case") {
notify_fail("You cannot possibly open that.\n");
return 0; 
}
if(found==1) { write("The case is already open.\n"); 
return 1; 
}

write("You open the small case and find a jade statue!\n");
move_object(clone_object("/players/fakir/inn/OBJ/statue.c"),this_object());
found = 1;
return 1; 
}
