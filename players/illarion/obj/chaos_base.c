#include "/players/illarion/dfns.h"
inherit "obj/treasure";

int clothes;
string comm,comm_play,comm_room;
object worn_by;

int make_light(int n) {
  set_light(n);
}
int set_clothes(status n) {
  clothes=n;
}
int set_comm(string str1,string str2,string str3) {
  comm=str1;
  comm_play=str2;
  comm_room=str3;
  return 1;
}
void init() {
  ::init();
  if(clothes) {
    add_action("cmd_remove","remove");
    add_action("cmd_wear","wear");
  }
  if(comm)
    add_action("special_comm",comm);
}
void check_right_worn() {
  if(!worn_by) return;
  if(!environment()) { worn_by=0; return; }
  if(worn_by != environment()) worn_by=0;
}
short() {
  check_right_worn();
  return ::short()+(worn_by?" (worn)":"");
}
int cmd_wear(string str) {
  if(!str) FAIL("Wear what?\n");
  if(present(str,TP)!=this_object()) FAIL("Wear what?\n");
  check_right_worn();
  if(worn_by) {
    write("You already wear it.\n");
    return 1;
  } else {
    write("You wear the "+name+".\n");
    say(TPN+" wears "+name+".\n");
    worn_by=TP;
    return 1;
  }
}
int cmd_remove(string str) {
  if(!str) FAIL("Remove what?\n");
  if(present(str,TP)!=this_object()) FAIL("Remove what?\n");
  check_right_worn();
  if(worn_by) {
    write("You remove the "+name+".\n");
    say(TPN+" removes "+name+".\n");
    worn_by=0;
    return 1;
  } else {
    write("You are not wearing it.\n");
    return 1;
  }
}
int special_comm(string str) {
  string before,after;
  string to_room;
  if(!str || !id(str)) FAIL(capitalize(comm)+" what?\n");
  write(comm_play+"\n");
  if(sscanf(comm_room,"%s&NAME&%s",before,after))
    say((before?before:"")+TPN+(after?after:"")+"\n");
  else
    say(comm_room+"\n");
  return 1;
}
query_save_flag() { return 1; }
