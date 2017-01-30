short() { return "A bouquet of flowers"; }
long() {
  write("This is a pleasantly aromatic bouquet of\n"+
  "flowers tied at the base with a silky linen.\n"+
  "Perhaps you could 'toss' this bouquet into\n"+
  "the crowd and see what happens...\n");
}

id(str) { return str == "bouquet" || str == "flowers"; } 
get() { return 1; }
init() {
  add_action("tossme","toss");
}

tossme(arg) {
  write("You toss the bouquet of flowers into the crowd!\n");
  write("Too bad... it is ripped to pieces by the gathered mob.\n"+
  "Looks like no one will get THIS good luck charm *grin*\n");
  say((this_player()->query_name()) + " tosses a bouquet of flowers into the crowd...\n"+
  "Suddenly all the single females lunge for it but end up only \n"+
  "tearing the entire thing to shreds. Oh well.\n");
  destruct(this_object());
  return 1;
}
