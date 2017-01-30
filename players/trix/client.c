
/*
 * Sample daemonized object. Learn how this works and life will begin.
 */

#define MASTER_R "/open/Mi-daemon.c"

id(str) { return str == "kazoo"; }
short() { return "The kazoo of Squish"; }
long() {
  write("This is the kazoo of of Squish. It is a magical item, and you\n"+
  "can do many neat things with it.\n");
  MASTER_R->commands();
}

get() { return 1; }
query_value() { return 1; }

init() {
  add_action("bgrin","bgrin");
  add_action("girn","girn");
  add_action("doh","doh");
  add_action("bog","bog");
  add_action("bah","bah");
  add_action("gribble","gribble");
  add_action("fucknut","fucknut");
  add_action("squish","squish");
  add_action("moo","moo");
  add_action("boink","boink");
}

bgrin() { MASTER_R->bgrin(); return 1; }
girn() { MASTER_R->girn(); return 1; }
doh() { MASTER_R->doh(); return 1; }
bog() { MASTER_R->bog(); return 1; }

bah(str) { MASTER_R->bah(str); return 1; }
gribble(str) { MASTER_R->gribble(str); return 1; }
fucknut(arg) { MASTER_R->fucknut(arg); return 1; }
squish(arg) { MASTER_R->squish(arg); return 1; }
moo(arg) { MASTER_R->moo(arg); return 1; }
boink(arg) { MASTER_R->boink(arg); return 1; }
