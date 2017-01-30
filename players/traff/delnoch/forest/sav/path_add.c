
path() {
  if(!path) {
    write("What?\n");
    return 1; }
  path = 0 ;
  write("You move off, down the path.\n");
  call_other(this_player(),"move_player","down a path#"+FR+"forest1.c");
  return 1; }

search(str)  {

  if(!str)  {
    write("Search what?\n");
    return 1;  }
   
  path = 1;
  write("You search the "+str+" and find a path.\n");
  write("Perhaps the 'path' leads somewhere.\n");
  return 1;  }
