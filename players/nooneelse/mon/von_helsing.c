/*
 von_helsing.c
*/

inherit "obj/monster";

string str, moves_str, destination_str;
int which_destination, how_long_here;

reset(arg) {
  if (sizeof(explode(file_name(this_object()),"#"))==1) return;
  if (arg) return;
  ::reset(arg);

  set_name("von helsing");
  set_alias("old man");
  set_race("man");
  set_alt_name("nooneelsevonhelsing");
  set_level(7);
  set_hp(250);
  set_wc(16);
  set_ac(8);
  set_ep(10200);
  set_al(0);
  this_object()->load_chat(
    "Von Helsing says: I used to be strong enough to hunt "+
    "the undead creatures.\n");
  this_object()->load_chat(
    "Von Helsing says: You must have a stake AND a hammer to destroy them!\n");
  this_object()->load_chat(
    "Von Helsing says: Once you have knocked them down, you must hurry!\n");
  this_object()->load_chat(
    "Von Helsing says: You must drive the stake into the vampire "+
    "to finish it.\n");
  this_object()->load_chat(
      "Von Helsing says: Remember the traditional protections!\n"+
      "                  You need garlic, a cross and holy water!\n");
  this_object()->load_a_chat(
    "Von Helsing says: You fool!  I could have helped you!\n");
  this_object()->load_a_chat(
    "Von Helsing says: Now you must do it alone!\n");
  this_object()->load_a_chat(
    "Von Helsing says: Now you'll never know the secret!\n");
  this_object()->set_chat_chance(25);
  this_object()->set_a_chat_chance(40);
  if (!moves_str) load_moves_str();
  sscanf(moves_str[0], "%s %d", destination_str, how_long_here);
  call_out("make_a_move", how_long_here);
}

make_a_move() {
  sscanf(moves_str[which_destination], "%s %d", destination_str, how_long_here);
  command(destination_str, this_object());
  which_destination=which_destination+1;
  if (which_destination > 24) {
    which_destination=0;
  }
  call_out("make_a_move", how_long_here);
  return 1;
}

load_moves_str() {
  moves_str=allocate(25);

  moves_str[0] = "west 20";
  moves_str[1] = "south 20";
  moves_str[2] = "north 20";
  moves_str[3] = "west 20";
  moves_str[4] = "east 20";
  moves_str[5] = "north 20";
  moves_str[6] = "west 20";
  moves_str[7] = "north 20";
  moves_str[8] = "south 20";
  moves_str[9] = "west 20";
  moves_str[10] = "east 20";
  moves_str[11] = "east 20";
  moves_str[12] = "east 20";
  moves_str[13] = "east 20";
  moves_str[14] = "west 20";
  moves_str[15] = "west 20";
  moves_str[16] = "north 20";
  moves_str[17] = "east 20";
  moves_str[18] = "northwest 20";
  moves_str[19] = "east 20";
  moves_str[20] = "west 20";
  moves_str[21] = "south 20";
  moves_str[22] = "south 20";
  moves_str[23] = "south 20";
  moves_str[24] = "east 20";
}
