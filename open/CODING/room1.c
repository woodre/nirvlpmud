inherit "room/room";
reset(arg) {
  object monster;
  if(arg) 
    return ;    
  set_light(1); 
  short_desc = "A Roomy Room"; 
  long_desc  =
 "This is a large, spacious, roomy room. There's lots of room in this room.\n"
+"In fact, there's so much room, that's it's just too roomy.\n";
  dest_dir =
  ({ /* needed to signify an array */
  "/room/church", "church",
  "/room/shop","shop"
  });
  monster = call_other("/open/CODING/beastie","make_monster");
  move_object(monster, this_object());
}
