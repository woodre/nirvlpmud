inherit "/obj/treasure.c";

reset(int arg) {
   if(arg) return;
   set_id("doll");
    set_short("A Jara Doll");
  set_long("A six-inch doll, with long brown hair set in soft curls. She has\n"+
    "a warm smile and her cheeks are rosy. A string hangs from her back.\n");
  set_weight(1);
  set_value(0);
    set_dest_flag(1);
}

init() {
  ::init();
  add_action("flame","pull");
}
flame(arg) {
  if(arg == "string") {
    switch(random(2)) {
      case 0: write("You pull the string...\n"+
                    "The Jara Doll's says: Happy Valentine's Day!\n");
              say(this_player()->query_name()+" pulls the string on the doll...\n"+
                  "The doll says: Happy Valentine's Day!\n");
              break;
      case 1: write("You pull the string...\n"+
                  "The Jara Doll cuddles up to you!\n");
              say(this_player()->query_name()+" pulls the string on the doll...\n"+
                  "The Jara Doll looks like she needs some cuddling!\n");
              break;
    }
    return 1;
  }
}
