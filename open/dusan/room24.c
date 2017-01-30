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
   "Curtains frame the window overlooking the back of the inn.  The\n"+
   "roof of the stables is visible through the glass panes.  A bed\n"+
   "with a straw tick mattress sits in the corner with the covers\n"+
   "thrown back.  A small night table sits next to the bed and a\n"+
   "burning candle throws fleeting shadows across the walls.\n";
           
items = ({
   "mattress",  "Heavy white cloth filled with shredded straw and grasses\n"+
                "There is a small cut or tear in the corner near the pillow",
   "cut",       "Obviously a place where someone might hide something",
   "tear",      "Upon closer inspection, this is definitely a cut from a sharp knife",
   "curtains",  "Plain white curtains with a sheer panel sewn into the fabric",
   "window",    "A four pane glass window common to the area. The glass is\n"+
                "somewhat cloudy due to the poor magic used in making it",
   "roof",      "Split wooden shakes racked from bottom to top",
   "stables",   "A long wooden structure where guests horses are kept",
   "panes",     "Cloudy glass about a quarter snitch thick",
   "bed",       "A square four post bed with a flat wooden headboard",
   "covers",    "A hand sewn quilt and a woolen blanket over cotton sheets",
   "table",     "A wooden nightstand of sorts, it holds a candle and a book",
   "candle",    "A half burned wax taper with a cotton wick",
   "walls",     "Covered in a colorful paper and a wooden chair rail on all sides",
   });
if(!present("Mnlander",this_object()))
 move_object(clone_object("/players/fakir/inn/NPC/Mnlander.c"),this_object());
if(!present("Wnlander",this_object()))
 move_object(clone_object("/players/fakir/inn/NPC/Wnlander.c"),this_object());

dest_dir = ({
   
   "/players/fakir/inn/room23.c",  "hall",
   
});

  }

init()  {
  ::init();
    add_action("search_mattress","search");
}
search_mattress(arg)  {
if(!arg || arg != "mattress") {
notify_fail("You find nothing by searching there.\n");
return 0; 
}
if(found) { write("You search in vain and find nothing.\n"); 
return 1; }
write("You search the mattress and find a small coin purse!\n");
move_object(clone_object("/players/fakir/inn/OBJ/purse2.c"),this_object());
 found = 1; return 1; 

}
