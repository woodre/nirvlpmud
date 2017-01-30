/* eggs.c: ant eggs */
short() { return "A small pile of ant eggs"; }
long()  {
  write("A group of slimy ant eggs. Although they are probably a good source of\n");
  write("protein, you are too picky to eat such things.\n");
  return 1;
}
id(str) { return str == "eggs" || str == "ant eggs" || str == "pile of eggs"; }
get()          { return 1;  }
query_weight() { return 1;  }
query_value()  { return 60; }
init() {
  add_action("try_eat", "eat");
}
try_eat(str) {
  if(!id(str)) 
    return ;
  write("You are too picky too eat such things.\n");
  return 1;
}
