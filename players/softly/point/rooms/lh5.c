inherit "/players/softly/point/rooms/std_lh.c";
int found;
  reset(arg) {
  if(arg) return;
  ::reset();
set_light(0);
long_desc =
"  A broad cold room with curved masonry walls coated with\n\
a coat of very dirty, streaked white paint.  The surface\n\
has begun to crumble and in places light shows through.  A\n\
curved iron staircase dominates the space.  Looking up the\n\
top cannot be seen.  The floor is covered with rubble.\n";

items = ({
  "room",
"A conical room, walls of rough masonry, is dominated\n\
 by a cylindrical iron staircase",
  "walls",
"The masonry walls are greyish white.  They are cracked\n\
 and beginning to crumble in many places.  Chunks of\n\
 concrete are loose",
  "staircase",
"A sharply curved staircase roughly made of iron\n\
 reaches up and out of sight.  It has a railing\n\
 that is no longer well anchored",
  "surface",
"The masonry walls are greyish white.  They are cracked\n\
 and beginning to crumble in many places.  Chunks of\n\
 concrete are loose",
  "rubble",
"Broken bottles, discarded wrappings, chunks of concrete,\n\
 nails and screws, and pieces of iron pipe are scattered\n\
 on the floor",
  "floor","An unpainted concrete floor, covered with rubble",
  "railing","A thin iron bar is attached to the staircase.\n\
It is no longer well anchored",
  "paint",
"The paint is dirty and streaked.  It has begun to peel",
  });

dest_dir = ({
  "/players/softly/point/rooms/lh6.c","up",
  "/players/softly/point/rooms/lh2.c","west",
  });
}
void init()
{
    ::init();
  add_action("search", "search");
}

search(str){
if(!str) return;
if(found){ write("There is nothing in the rubble.\n"); 
return 1; 
}

if(str == "rubble"){
write("You found a gold nugget in the rubble.\n");
move_object(clone_object("/players/softly/point/obj/nugget"), this_player());
found = 1;
return 1; 
} 
return; 
}
