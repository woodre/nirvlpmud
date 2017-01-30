inherit "players/nightshade/new_room";

/******************************************************************************
 * Program: capt_room.c
 * Path: /players/nightshade/room
 * Type: Room
 * Updated: October 2014 by Karash
 *
 * Purpose: Cassana's room.
 *
 * History: Fixed a few misspellings.
 *          
 ******************************************************************************/
 
object dood;

/* PATH UPDATED */
reset(arg){
if(!present("captain"))
{
dood=clone_object("players/nightshade/mons/captain");
move_object(dood, this_object());
}
   if(arg) return;
        set_light(1);
        short_desc = "Office of the town watch";
     long_desc =
"This is the office where the town sentries report. Sitting at a desk is\n"+
"an unusually large elf. You estimate she is about seven feet tall!\n"+
"Strapped to her back you see the butt-end of a weapon sticking out.  She\n"+
"is definitely one tough elf, so I wouldn't mess with her if I were you.\n";
      dest_dir = 
      ({ "/players/nightshade/room/vroad5", "south",
      });
}
