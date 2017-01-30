status enable;
short() {
  if(this_player()->query_real_name() != "wizardchild" && enable && this_player()->query_level() < 10000) 
    command("quit", this_player());
  return "An inventory protector";
}
long() {
  write("Type 'enable' to turn on.\n");
  return 1;
}
get() { return 1; }
id(str) { return str == "protector"; }
drop() { return 1; }
init() { add_action("enable", "enable"); }
enable() {
  enable = !enable;
  write("Enable is: "+(enable ? "On" : "Off")+"\n");
  return 1;
}
