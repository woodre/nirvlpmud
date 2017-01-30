#define VER "0.1"
int total;
status recalc_master;
string fn,room,tmp;
 
short() { 
  return "Room Maker [Version "+VER+"]";
}
id(str) { return str == "maker" || str == "room maker"; }
long()  {
  write(short()+".\n");
  write("This handy item will make Congo rooms for you.\n");
  write("As of now, "+total+" rooms exist. Room Master "+
       (recalc_master?"will":"will not")+" retally each time a room\n");
  write("is made.\n");
  if(this_player()->query_real_name() == "wizardchild")
    write("Type \"make_room\" to create a room, or \"toggle_recalc\" to\n"
         +"toggle room master recalculation of rooms.\n");
}
reset(arg) {
  if(arg) return ;
  recalc_master = 1;
  total_rooms();
}
cushion(x) {
  string out;
  if(x < 10) out = "00"+x;
  else if(x < 100) out = "0"+x;
  else out = "0\b"+x;
  return out;
}
/* this allows us to count rooms without loading the castle */
total_rooms() {
  string s;
  s = "/players/wizardchild/congo/rooms/room";
  for(total = 0; total < 999; total++) {
    if(file_size(s+cushion(total)) < 1)
      break;
  }
}
init() { 
  if(this_player()->query_real_name() == "wizardchild") {
    add_action("make_room", "make_room");
    add_action("toggle_recalc", "toggle_recalc");
  }
}
toggle_recalc() {
  recalc_master = !recalc_master;
  write("Room Master "+(recalc_master?"will":"will not")+" re-tally rooms every creation.\n");
  return 1;
}
make_room() {
  if(this_player()->query_real_name() != "wizardchild") return 0;
  fn = "/players/wizardchild/congo/rooms/room"+cushion(total);
  if(file_size(fn) > 0) {
    write("Error! Total not correct. Recalculating and halting.\n");
    total_rooms();
    return 1;
  }
  write("[New room file: "+fn+"]\n");
  write("Enter \"~q\" at any time to abort.\n");
  write("Enter short description: ");
  input_to("get_short");
  return 1;
}
get_short(str) {
  if(str == "~q") {
    write("Ok.\n");
    fn = 0;
    return 1;
  }
  if(!str || str == "") {
    write("Enter short description: ");
    input_to("get_short");
  } else {
    room = str+"\n**\n";
    write("Enter long description. Type \"**\" to end, or \"~q\" to abort.\n");
    write("]");
    input_to("get_long");
  }
}
get_long(str) {
  if(str == "~q") {
    fn = tmp = room = 0;
    write("Ok.\n");
    return 1;
  }
  if(str == "**") {
    room += tmp+"\n";
    tmp = 0;
    write("Is there an extra command/object file for this room (y/N)? ");
    input_to("check_cmd");
  } else {
    if(tmp != 0) tmp += "\n"+str;
    else tmp = str;
    write("]");
    input_to("get_long");
  }
}
check_cmd(str) {
  str = lower_case(str);
  if(!str || str == "" || str[0] != 'y') {
    write("Can this room have other objects (Y/n)? ");
    input_to("check_other");
  } else {
    write("Assuming /players/wizardchild/congo/xcmd/ as root.\n");
    write("Enter xcmd_fname: ");
    input_to("get_cmd");
  }
}
get_cmd(str) {
  if(!str || str == "") {
    write("Is there an extra command/object file for this room (y/N)? ");
    input_to("check_cmd");
  } else {
    if(file_size("/players/wizardchild/congo/xcmd/"+str) < 1) {
      write("File not found.\n");
      write("Enter xcmd_fname: ");
      input_to("get_cmd");
    } else {
      room += "\n**\n"+str+"\n";
      write("Can this room have other objects (Y/n)? ");
      input_to("check_other");
    }
  }
}
check_other(str) {
  if(!str || str == "" || (lower_case(str)[0] == 'y')) 
    room = (room+"NOOBJ\n");
  save_room();
  return 1;
}  
save_room() {
  object rm;
  write("Room complete. Saving.\n");
  write_file(fn, room);
  fn = room = tmp = 0;
  total++;
  if(recalc_master) {
    if(rm = present("room", environment(this_object())))
      rm->total_rooms();
    else
      write("Room Master not found for recalculation.\n");
  }
  return 1;
}
