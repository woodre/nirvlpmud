inherit "room/room";
int counter;

reset(arg)
{
  if (arg) return;
  set_light(1);
  short_desc = "Deep Space";
  long_desc = "The empty vastness of deep space....\n";
  counter = 1;
}

init()
{
  add_action("move_player", "north");
  add_action("move_player", "south");
  add_action("move_player", "east");
  add_action("move_player", "west");
  ::init();
}

move_player()
{
  while(counter < 15)
  {
    call_other(this_player(), "move_player", "str#players/morgoth/CASTLE/deep_space");
    counter += 1;
    return 1;
  }
  if(counter == 15)
  {
    call_other(this_player(), "move_player", "str#players/morgoth/CASTLE/Easteroid");
    write("A tingler attaches itself to your spine !!\n");
    counter = 1;
    return 1;
  }
}

realm(){return "NT";}
