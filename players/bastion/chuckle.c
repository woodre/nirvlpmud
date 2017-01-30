#pragma combine_strings

mapping test;
id(str) { return "test"; }

short() { return "A test device"; }

long(str) {
     write("A little device.\n");
     write("Bing = " + test["bimble"] + "\n");
     return 1;
}

reset(arg) {
  if (arg) return;
  test = ([ "bing" : 1, "bong" : 2 ]);
  test += ([ "bimble" : "love!" ]);
}

init() {
    add_action("test_fun", "test");
     add_action("test_save_map", "map");
     add_action("check", "check");
}

get() { return 1; }

check(who) {
     object ob;
     if(!who) {
          write("Check whom?\n");
          return 1; 
     }
     ob=find_living(who);
     if(!ob) {
          write("No such person found.\n");
          return 1;
     }
     write("Check: "); write(ob); write("--");
     write(query_snoop(ob));
     write("\n");
     return 1;
}

test_save_map() {
     save_object("players/bastion/chuckle");
     write("Done.\n");
     return 1;
}

test_fun(arg) {
    write("This is a "
          "test!\n");
    return 1;
}
