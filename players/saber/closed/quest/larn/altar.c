#define tp this_player()->query_name()

id(str)
 { return str == "altar";  }

short() {
 return "The altar of Larn";
}

long() {
  write("The altar of Larn\n"+
        "The altar has been forged from moonfire silver, and is\n"+
        "covered with runes and chants of praise to Larn.  You\n"+
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
