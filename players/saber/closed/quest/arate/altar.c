#define tp this_player()->query_name()

id(str)
 { return str == "altar";  }

short() {
 return "The altar of Arate";
}

long() {
  write("The altar of Arate\n"+
      "The altar has been carved from the bones of a dragon, and\n"+
      "is covered with glowing runes of praise to Arate.  You\n"+
      "know that if you <pray> at the altar, you will be raised\n"+
      "from the dead.\n");
}

pray()  {
return call_other(this_player(), "remove_ghost", 0);
        }

init() {
   add_action("pray","pray");
}

get()  { return 0; }
drop()  { return 1; }
query_weight()  { return 100; }
