inherit "room/room";

reset(arg) 
{
  if(arg) return;
  
  if(!present("Steve"), this_object())
  {
    move_object(clone_object("/players/highlander/areas/acs/mobs/steve.c"), this_object());
  }
  
  if(!present("Mike"), this_object())
  {
    move_object(clone_object("/players/highlander/areas/acs/mobs/mike.c"), this_object());
  } 

  ::reset()
  set_light(1);

  short_desc = "Big Room";
  long_desc =
  "  You are standing in a really big room with several doors leading\n"+
  "in different directions.  You might be able to look at each door.\n";

  items = ({
    "room",
    "A large room painted completely white", 
  });  

  dest_dir = ({
    "/players/fred/blah/r1.c","south",
    "/players/fred/blah/r2.c","north",
  });
}


init()
{
  ::init();

  add_action("Cmd_look","look",1);
}

Cmd_look(string str)
{
  if(str == "at door1")
  {
    write("The first door appears to lead to a jungle area\n");
    return 1;
  }
  if(str == "at door2")
  {
    write("The second door appears to lead to the middle of an ocean.\n");
    return 1;
  }
  if(str == "at door3")
  {
    write("The third door appears to lead to an apartment complex.\n");
    return 1;
  }
  else
  {
    write("You can look at door1, door2, or door3.\n");
    return 1;
  }
}
 
 