inherit "/players/softly/point/rooms/std_lh.c";

  reset(arg) {
  if(!present("kidd")) 
  move_object(clone_object("players/softly/point/mobs/kidd"),this_object());
  if(arg) return;
  ::reset();
set_light(0);
long_desc =
"  A broad cold room with curved masonry walls coated with\n\
a coat of very dirty, streaked white paint.  The surface\n\
has begun to crumble and in places light shows through.  A\n\
curved iron staircase dominates the space.  Looking up the\n\
top cannot be seen.  There is nothing but darkness below.\n";

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
  "railing","A thin iron bar is attached to the staircase.\n\
It is no longer well anchored",
  "paint",
"The paint is dirty and streaked.  It has begun to peel",
  "light","Occasional spots of sunlight show through the walls",
  "darkness","It seems as if there is nothing beneath",
  });


dest_dir = ({
  "/players/softly/point/rooms/lh7.c","up",
  "/players/softly/point/rooms/lh5.c","down",
  });
}

