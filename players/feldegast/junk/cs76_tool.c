#include "/players/feldegast/defines.h"

inherit "obj/treasure";

  string name;
  string guild_name;
  string hostname;
  string called_from_ip;
  int level, ex_lv;

void reset(int arg) {
  if(arg) return;
  set_id("rod");
  set_alias("recorder");
  set_short("Rod of Recording");
  set_long(
"This is a short, golden rod about two feet long with an inscription written"+
"lengthwise on it, and a 'flying WV' on its head.\n");
  set_weight(1);
  set_value(50);
}
void init() {
  add_action("cmd_read","read");
  add_action("cmd_record","record");
}
int cmd_read(string str) {
  notify_fail("Read what?\n");
  if(!str) return 0;
  if(!id(str)) return 0;
  write("The rod reads: CS76 Project 4 Data Recorder 11/13/98\n"+
        "               Type 'record' for instructions.\n");
  return 1;
}
int cmd_record(string str) {
  string data_string;
  notify_fail("Usage: record <player>\n");
  if(!str) return 0;
  name=0;
  if(!restore_object("pfiles/"+extract(str,0,0)+"/"+lower_case(str)) ||
     !name) {
    write("No such player exists.\n");
    return 1;
  }
    data_string=pad(name,15);
    data_string+=pad(level+ex_lv,5);
    data_string+=pad(guild_name,15);
    data_string+=pad(hostname,40);
    data_string+=pad(called_from_ip,20);
  write(data_string+"\n");
  write_file("/players/feldegast/junk/cs76-nirv.dat",data_string+"\n");
  return 1;
}
