/* wt.c: walkie-talkie */
#define MASTER "/players/wizardchild/closed/wtmaster.c"
init() {
  MASTER->add_all(this_object());
  add_action("enable", "enable");
  add_action("disable", "disable");
#ifndef __LDMUD__
  add_action("use_chan"); add_xverb("talk");
#else
  add_action("use_chan", "talk", 3);
#endif
  add_action("list_chan", "list_chan");
  add_action("dump_me", "dump_me");
  add_action("donate", "donate");
  add_action("remove_all", "quit");
}
query_auto_load() {
  return "/players/wizardchild/closed/wt.c";
}
short() { return "A walkie-talkie";    }
long()  { return MASTER->print_help(); }
id(str) { return MASTER->okid(str);    }
 
get()   { return 1; }
drop()  { return 0; }
 
enable(str)   { return MASTER->enable(str);        }
disable(str)  { return MASTER->disable(str);       }
use_chan(str) { return MASTER->use_chan(str);      }
list_chan()   { return MASTER->list_channels();    }
donate(str)   { return MASTER->donate(str);        }
dump_me()     { return MASTER->dump_me();          }
remove_all()  { MASTER->remove_all(this_object()); }
