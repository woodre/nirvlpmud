inherit "room/room";
reset(arg)
  {
  if( !present("log") )
  move_object(clone_object("/players/arrina/treas/log"),this_object());
  if(!arg)
  {
  set_light(1);
  short_desc="Dead Orchard";
  long_desc=
    "This was once a well tended orchard, but no more. The \n"+
     "skeletal trunks of apples or pears have borne no fruit for\n"+
     "a long time, now slumping to the ground or leaning from \n"+
     "their once ordered rows. The west wall of the castle stands\n"+
     "to the east, and a stable lies south.\n";
  items=({
    "trees", "The fruit trees have all died, they have no fruit",
    "fruit", "The fruit trees have all died, they have no fruit",
       });

  dest_dir=({
    "/players/arrina/grounds/stable.c","south",
    "/players/arrina/grounds/high0.c","east",
 });
    }
    }


