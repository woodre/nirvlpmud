/* inherit the room driver code */
inherit "room/room";
reset(arg) {
  object monster;
/* if we have monsters that we want to reload at reset, load them here */
/* before the if statement, that is :) */
  if(arg) 
    return ;    
  set_light(1); /* remove this statement to keep the room dark */
/* short_desc is a string from /room/room.c; it is what players see on who2 */
  short_desc = "A Roomy Room"; 
/* long_desc is what you see when you type 'look' */
/* the room driver handles displaying exits */
  long_desc  =
 "This is a large, spacious, roomy room. There's lots of room in this room.\n"
+"In fact, there's so much room, that's it's just too roomy.\n";
/* notice that long_desc needs newlines (\n) and a period, while short_desc */
/* does not */
/* dest_dir is an array of type string */
/* we assign exit room filenames first, then the commands to go that way */
  dest_dir =
  ({ /* needed to signify an array */
  "/room/church", "church",
  "/players/arrina/workroom", "workroom"
  });
/* now that the room is configured, we can make a monster */
/* this monster will not reload at reset, since it's at the end */
  monster = clone_object("/players/wizardchild/monsters/nchick");
  move_object(monster, this_object());
}
