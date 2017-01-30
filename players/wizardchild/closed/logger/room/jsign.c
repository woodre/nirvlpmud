short() {
  return "A small wooden sign";
}
long()  {
  write("+----------------------------+\n");
  write("|Logger's Guild Join-up Room.|\n");
  write("|Guildmaster: Wizardchild.   |\n");
  write("+----------------------------+\n");
  write("The following commands are available:\n");
  if(!present("logger pack", this_player())) {
    write("get pack       Get a new pack if you have lost yours.\n");
    write("join_guild     Join the logger's guild (yay!)\n");
    write("info           Get a little information on this guild.\n");
  } else {
    write("enter          Enter the guild hall.\n");
    write("leave_guild    Leave the logger's guild.\n");
  }
  return 1;
}
id(str) { return str == "sign" || str == "wooden sign"; }
init() {
  add_action("read", "read");
}
read(str) {
  if(!id(str)) 
    return 0;
  long();
  return 1;
}
