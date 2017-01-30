string *names;

reset(arg) {
  if(arg) return;
  names = ({"zed","marcelus","mia","vincent","jules","wolf","butch","gimp",
    "kilo","lima","oscar","papa","tango","zulu",
   "alpha","bravo","charlie","delta","echo","foxtrot","golf","hotel"});
}

short() { return "A VDS tester"; } 
id(str) { return str == "VDS tester" || str == "tester"; }
long() { write("Type \"fill_map\" to test.\n"); }
init() {
  add_action("fill_map","fill_map");
  add_action("flip","flip");
}

fill_map() {
string plyr;
int exp;
  plyr = names[random(sizeof(names))];
  exp = -200 + random(1000);
  call_other("players/cosmo/hslist/exp_store.c","collector",plyr,exp);
  write(plyr+" "+exp+"\nOk.\n");
  return 1;
}

flip() {
  call_other("players/cosmo/hslist/exp_store.c","set_on");
  write("ok... done.\n");
  return 1;
}
