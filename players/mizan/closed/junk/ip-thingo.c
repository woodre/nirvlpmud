string called_from_ip;
id(str) { return str == "thingo"; }
short() { return "A thingo"; }

init() { add_action("pre","pre"); }
get() { return 1; }

pre(str) {
  if(!restore_object("players/" + str)) {
  write("No such player.\n");
  return 1; }
  write(called_from_ip+"\n");
  return 1;
}
