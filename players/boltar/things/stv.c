

short()
{
     return "A serveillance televison set";
}

query_value()
{
        return 3;
}

  query_weight() {   return 300; }
long()
{
   write("A small tv set, you might be able to use to view someone.\n");
   write("Or see where they are.\n");
}

init() {
     add_action("see", "see");
     add_action("view", "view");
}

id(str) {
    return str == "televison" || str == "tv" || str == "set";
}

see(str) {
  object ob;
  if (!str) {
     write("you must try see where some one is.\n");
     return 1;
   }
   ob = find_living(str);
   if(!ob || ob->query_level() > 20) {
     write(str + " cannot be found by the network of cameras.\n");
     return 1;
     }
    if(ob->query_invis()) {
     write(str + " cannot be found by the network of cameras.\n");
     return 1;
     }
   call_other(ob, "look", 0);
    return 1;
}

get() {
      write("It's bolted to the table.\n");
    return 0;
}
view(str) {
  object what;
	    object special;
  object ob;
       if(!str) {
          write("The cameras need someone to look for.\n");
          return 1;
          }
   what = find_living(str);
   if(!what || what->query_level() > 20) {
   write ("The cameras cannot find " + str + ".\n");
    return 1;
     }
    if(what->query_invis()) {
   write ("The cameras cannot find " + str + ".\n");
    return 1;
     }
   call_other(what, "long", 0);
	    special = first_inventory(what);
	    while (special) {
	        string extra_str;
		extra_str = call_other(special, "extra_look");
		if (extra_str)
		    write(extra_str + ".\n");
		special = next_inventory(special);
	    }
    ob = first_inventory(what);
    if (ob) {
   write(call_other(what, "query_real_name", 0) + " is carring: \n");

    while(ob) {
        if (call_other(ob, "short", 0)) {
        write(call_other(ob, "short") + "\n");
}
	ob = next_inventory(ob);
    }
    }
   return 1;
}
