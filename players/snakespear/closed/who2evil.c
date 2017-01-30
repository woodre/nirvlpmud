init()
{

  add_action("who2it","'who2'");
}

who2it()
{
  write("A small speck of power is granted to you. You are enliven.\n");
  return 1;
}

get() { return 1; }
drop() { return 1; }
