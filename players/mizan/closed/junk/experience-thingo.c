string experience;
id(str) { return str == "thingo"; }
short() { return "A thingo"; }

init() { add_action("pre","pre"); }
get() { return 1; }

pre(str) {
  if(!restore_object("players/" + str)) {
  write("No such player.\n");
  return 1; }
  write(capitalize(str) + " " + experience + ".\n");
  return 1;
}
