#include "/players/softly/closed/define.h"
#include "/players/softly/closed/ansi.h"
inherit "/players/softly/closed/std/room";
int i, snaked;
reset(arg){
  if(arg) return;

  if(!present("reverend")){ 
    move_object(clone_object("players/softly/algiers/mobs/reverend.c"),this_object());
  }
  if(!present("congre")) {
    for(i=0;i<9;i++) {
      move_object(clone_object("players/softly/algiers/mobs/congre.c"),this_object());
    }
  }
  set_light(1);

  short_desc = "Fellowship Church Sanctuary";
  long_desc ="\n"+
    "  A large room is walled with hardwood paneling. An aisle down the\n"+
    "center, covered with new-looking red carpet,  has rows of pews on\n"+
    "both sides.  An open area also covered with red carpet extends from\n"+
    "the front pews to the pulpit.  A small wooden fence juts out on both\n"+
    "sides of the pulpit.  Large double doors open to the outside. A small\n"+
    "door is on the east side, toward the back.\n";

  items = ({
    "door",
    "A small white swinging door sits unobtrusively on the east side",
    "doors",
    "A wooden doouble doors are polished and worn from many hands opening it",
    "pulpit",
    "The pulpit is surrounded by a small wooden fence",
    "fence",
    "Decorative white fencing separates the pulpit from the rest of the room",
    "paneling",
    "Light colored, highly polished hardwood paneling covers the walls",
    "aisle",
    "The center aisle bisects the room.  It is covered with red carpet",
    "pews",
    "The gleaming pews look new and are covered in fancy red cushions",
    "carpet",
    "A long dark red new carpet covers the central aisle and the\n"+
    "area around the pulpit",
    "door",
    "A wooden door is polished and worn with many hands opening it",
  });

  dest_dir = ({
    "/players/softly/algiers/rooms/church.c","exit",
    "/players/softly/algiers/rooms/churchkitch.c","east",
  });
}

make_snakes() 
{ 
  tell_room(environment(this_player()), BOLD+previous_object()->query_name() + 
	    " falls against the fence opening a hidden crate.\n"+NORM); 
  call_out("create_snake", 5); 
  snaked = 1; 
}

query_snaked() { return snaked; }

/* Can I do a switch to vary the snake-emerge message */
create_snake() 
{ 
  if(!present("snake 25", this_object())) 
    { 
      snaked ++; 
      move_object(clone_object("/players/softly/algiers/mobs/snakes.c"), this_object()); 
      tell_room(this_object(), "A snake slowly slithers out of the crate.\n"); 
    } 
  if(snaked > 39) return; 
  else call_out("create_snake", 5);
}
  
  
  
