#include "/players/fakir/color.h"
inherit "room/room";
int found;

reset(arg) {
  if(arg) return;
found = 1+random(3);
set_light(1);

short_desc = "Caemyln Wilderness";
long_desc =
"   Thick bushes line the narrow path, and a few maple trees wave\n"+
"in the slight breeze above.  A small hovel of bark and grassy sod\n"+
"has been built just to the north.  Smoke curls from the short but\n"+
"sturdy stone chimney.\n";

items = ({
"bushes",      "Mostly dense and thick brush, with sharp thorns...",
"path",        "A well worn dirt path which it seems you must follow",
"trees",       "Tall white maple trees, waving in the breeze",
"hovel",       "A small dwelling, hastily built in the wilderness",
"bark",        "Maple bark, stripped from trees round about",
"sod",         "Dirt flecked with grasses still green and growing",
"smoke",       "White puffy smoke from a slow burning fire",
"chimney",     "A stone chimney of very good design. You could\n"+
               "'plug up the chimney' to force those inside to\n"+
               "come out and fight",
});

dest_dir = ({
   "/players/fakir/caemlyn/room5.c", "northeast",
   "/players/fakir/caemlyn/room3.c", "southwest",
});
}
init()  {
  ::init();
    add_action("plug_chimney","plug");
}
plug_chimney(arg)  {
if(!arg || arg != "chimney") {
notify_fail(WHITE+"You did something wrong. Try again.\n"+OFF);
return 0; 
}
if(found==0) { 
move_object(this_player(),"/players/fakir/caemlyn/room93.c");
return 1; }
if(present("digger",this_object())) {
write("\n'You must kill this ruffian before you smoke out another.'\n"+OFF);
return 1;
}
write(\nWHITE+"     'COUGH!!!  COUGH!!! COUGH!!!  I'm comming out you bastard!\n\n"+
                     "      A pissed off ruffian emerges from the hovel.'\n"+OFF);  
move_object(clone_object("/players/fakir/woods/NPC/digger.c"),this_object());
found=found-1; 
return 1; 

}



