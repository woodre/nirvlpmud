#include "defs.h"

inherit ROOM;

void reset(int arg) {
  if(arg) return;
  set_light(1);
  short_desc="Tower of the Righteous";
  long_desc = 
"  This is a small window-less room in the Tower of the Righteous.\n"+
"A lamp sits upon a small desk with a ledger on it.  A hole in the\n"+
"wall leads back out.\n";
  items=({
    "lamp", "An oil lamp sits upon the desk, providing a little light",
    "desk", "The small desk sits in the corner.  There is a ledger on it",
    "hole", "There appears to be a tapestry just on the other side of\n"+
            "the hole",
    "ledger", "There is a ledger on the desk that you can read.\n",
  });
  dest_dir=({
    PATH+"barrack5.c","out",
  });
}

void init() {
  ::init();
  add_action("cmd_read", "read");
}

int cmd_read(string str) {
  object capo;
  if(str!="ledger") {
    notify_fail("Read what?\n");
    return 0;
  }
  write(
"Income\n\
Sakadi's monthly bribe.......3000\n\
Misc. Protection fees........1230\n\
Salary........................800\n\
Investments..................1124\n\n\
Expenses\n\
Hair oil......................600\n\
Bribing guards...............2000\n\
Booze........................1240\n\
Gambling.....................2250\n"
  );
  call_other(PATH+"barrack5.c","???");
  capo=find_living("valesh");
  capo->set_al(-500);
  return 1;
}
  
