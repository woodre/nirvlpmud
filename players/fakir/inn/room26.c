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
   "Curtains frame the broken window overlooking the back of the inn.\n"+
   "The roof of the stables is visible through the broken panes.  On\n"+
   "the bed is a body covered in blood.  Loose clothing and personal\n"+
   "items litter the floor.  A small night table is tipped on its side\n"+
   "and the mattress from the bed is askew and turned back, as if it had\n"+
   "been searched.  A broken travelling chest rests at the foot of the bed,\n"+
   "and an open coin purse lies next to it.\n";
           
items = ({
   "mattress",  "Heavy white cloth filled with shredded straw and grasses",
   "cut",       "Obviously a place where someone might hide something",
   "tear",      "Upon closer inspection, this is definitely a cut from a sharp knife",
   "curtains",  "Plain white curtains with a sheer panel sewn into the fabric.\n"+
                "Something is hiding behind them.  Beware if you 'search' them.",
   "window",    "A four pane glass window common to the area. The glass is\n"+
                "broken out and the frame is cracked",
   "roof",      "Split wooden shakes racked from bottom to top",
   "stables",   "A long wooden structure where guests horses are kept",
   "panes",     "Cloudy jagged glass about a quarter snitch thick",
   "bed",       "A square four post bed with a flat wooden headboard",
   "covers",    "A hand sewn quilt and a woolen blanket over cotton sheets",
   "table",     "A wooden nightstand of sorts, it has been overturned and searched",
   "candle",    "A half burned wax taper with a cotton wick",
   "walls",     "Covered in a colorful paper and a wooden chair rail on all sides",
   "chest",     "An ornate hardwood chest with heavy leather straps.  The lock has\n"+
                "been picked and the chest is open and empty",
   "body",      "From the cut of his clothing, this was a wealthy merchant",
   "blood",     "Deep red and quite fresh",
   "clothing",  "Samples of shirts, trousers, and other items of clothing",
   "items",     "Toothbrush, comb, shoe polish, razor, and other such junk",
   "purse",     "It is open and empty. Someone has done this horrible deed.\n"+
                "Be on your guard for evil certainly lurks nearby.",
   
});

dest_dir = ({
   
   "/players/fakir/inn/room27.c",  "hall",
   
});
}

init()  {
  ::init();
    add_action("search_curtains","search");
}
search_curtains(str)  {
if(str && str != "curtains") {
notify_fail("You find nothing when you search there.\n");
return 0; 
}
if(found) { write("You find nothing.\n"); 
return 1; }
write("You search the curtains and find someone hiding behind them!\n");
move_object(clone_object("/players/fakir/inn/NPC/shadow.c"),this_object());
 found = 1; return 1; 

}



  

