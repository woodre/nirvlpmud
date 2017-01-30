/* Note: This doesn't work even remotely, but I thought it was worth a try. */
#include "/players/feldegast/defines.h"
inherit "obj/treasure";

reset(arg) {
  set_id("wand");
  set_short("A short, black wand");
  set_long("A magic wand for testing wizard stuff.\nWave the wand to use it.\n");
  set_weight(1);
  set_value(1000);
}
init() {
  add_action("cmd_wave","wave");
}
int cmd_wave(string str) {
  string *files;
  int i;
  files=get_dir(str);
  for(i=0; i< sizeof(files); i++) {
    write(files[i]+"\n");
  }
  return 1;
}
