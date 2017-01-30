/* A little experiment */
#include "defs.h"

inherit MONSTER;

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("protoman");
  set_short("The Protoman");
  set_long("A protoman");
  set_level(100);
  set_wc(100);
  set_ac(60);
  set_hp(1000);
  set_race("golem");
}

void init() {
  ::init();
  add_action("cmd_rename", "rename");
  add_action("cmd_read", "read");
  add_action("cmd_force", "proto");
  add_action("local_clone", "protoclone");
}

int cmd_rename(string str) {
  if(str) set_name(str);
  write("Ok.\n");
  return 1;
}

int cmd_force(string str) {
  command(str,this_object());
  write("Protoman says: Done.\n");
  return 1;
}

int local_clone(string str) {
  object ob;
  ob=clone_object(str);
  if(!ob) {
    write("Invalid path.\n");
    return 1;
  }
  move_object(ob,this_object());
  return 1;
}

catch_tell(str) {
  FTELL("~"+str);
}

query_real_name() { return name; }
cmd_read(str) {
  object read;
  read=present("mailread",this_object());
  if(!read) return;
  call_other(read,"read");
  write("Ok.\n");
  return 1;
}
