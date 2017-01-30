#define TP this_player()
#define TPN this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(0);

short_desc =("Durkor Caverns");
long_desc =(
" The walls appear to have something carved into them.  The\n"+
"passage grows smaller to the south, while opening up to the \n"+
"north.  The smell of burning bodies pervaded the area.\n");

if(!present("lich"))
	  move_object(clone_object("/players/catacomb/Cavern/mobs/lich1.c"),
	    this_object());

items = ({
  "walls",
  "The walls are clear of blood but something is scraped into them",
  "scraping",
  "The scraping seems to form some word",
  "word",
  "The word says 'mein'"
});

dest_dir = ({
  "/players/catacomb/Cavern/rooms/lvl4_7.c","north",
  "/players/catacomb/Cavern/rooms/lvl4_9.c","south"
 
});
}


