object owner;
object pet;

id(str) { return str == "joystick"; }

short() { return "An Atari 2600 joystick"; }

long() {
  write("This thing is a relic from time zero...\n");
}
 
get() { return 1; }
drop() { return 1; }
 
reset() {
  owner=find_player("mizan");
  if(!owner) {
    write("This does not belong to you.\n");
    destruct(this_object());
    return 1;
  }
  pet=find_living("summerhead");
  if(!pet) {
    write("Error... Summerhead not located.\n");
    destruct(this_object());
    return 1;
  }
}
 
init() {
  add_action("sflow","sflow");
  add_action("sjunk","sjunk");
#ifndef __LDMUD__
  add_action("single_com"); add_xverb("");
#else
  add_action("single_com", "", 3);
#endif
}
 
sflow() {
   write("Commanding in continuous stream to pet. Give '*' to stop.\n>>");
  input_to("command_line");
  return 1;
}
 
single_com(str) {
    string tempr;
    if(sscanf(str, "!%s", tempr) == 1) {
      write("SCOM: " + str + "\n");
      command(tempr, pet);
      return 1;
    } else
  return 0;
}
 
command_line(str) {
  if(!str) {
    write(">>");
    input_to("command_line");
    return 1;
  }
  if(str == "*") {
    write(">>Quit.\n");
    return 1;
  }
  write(">>");
  command(str, pet);
  input_to("command_line");
  return 1;
}
 
sstop() {
  write("SSTOP: Destructing joystick.\n");
  destruct(this_object());
  return 1;
}
 
