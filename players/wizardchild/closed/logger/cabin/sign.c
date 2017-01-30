/* sign.c: info on how to use cabins */
string new_str;
short() { return "A small wooden sign"; }
long() { 
  write("You could read it.\n");
  return 1;
}
get() { return 0; }
id(str) { return str == "sign" || str == "wooden sign" || str == "small wooden sign"; }
init() {
  add_action("cabin_out", "cabin_out");
  add_action("cabin_in", "cabin_in");
  add_action("read", "read");
}
read(str) {
  if(!id(str)) return 0;
  write("Welcome, Logger, to your log cabin.\n");
  write("First off, please realize that these cabins aren't a right, and at any time\n");
  write("they could be removed. With that in mind, please don't exploit any bugs you\n");
  write("may find in them. Now, for the commands:\n");
  write("list    List the items in your cabin.\n");
  write("drop    Drop an item, automatically storing it.\n");
  write("get     Get an item from your cabin.\n");
  write("enter   Enter your cabin.\n");
  write("leave   Leave your cabin.\n");
  write("Get and Drop work with 'all', hence 'drop all' is valid.\n");
  write("There are ten spaces here to drop things. You can set the description of your\n");
  write("cabin using 'cabin_out' and 'cabin_in', where out is what players to see when\n");
  write("they are outside and look at your cabin, and in is what you see inside.\n");
  return 1;
}
cabin_out() {
  if(environment(this_object())->query_owner() != this_player()->query_real_name()) 
    return 0;
  new_str = "";
  input_to("get_out");
  write("Enter your cabin's outer description, end with '**'\n");
  write("[>");
  return 1;
}
get_out(str) {
  if(str == "**") {
    present("logger pack", this_player())->set_cabin_outside(new_str);
    write("Description set. You will not see the new description until the next time\n");
    write("your cabin loads.\n");
    new_str = 0;
    return ;
  } else {
    new_str = new_str + str;
    write("[>");
    input_to("get_out");
  }
  return 1;
}
cabin_in() {
  if(environment(this_object())->query_owner() != this_player()->query_real_name())
    return 0;
  new_str = "";
  input_to("get_in");
  write("Enter your cabin's inner description, end with '**'\n");    
  write("[>");
  return 1;
}
get_in(str) {
  if(str == "**") {
    present("logger pack", this_player())->set_cabin_long(new_str);
    write("Description set. You will not see the new description until the next time\n");
    write("your cabin loads.\n");
    new_str = 0;
    return ;
  } else {
    new_str = new_str+str;
    write("[>");
    input_to("get_in");
  }
  return 1;
}
