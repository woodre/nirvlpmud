inherit "obj/treasure";

reset(arg) {
  if(arg) return;
  set_id("crocodile skin");
  set_alias("skin");
  set_short("Skin from a small crocodile.");
  set_long(
"This is the skin from a small crocodile.  It is green\n"+
"and very rigid.  The right person would like to have this\n"+
"to use for making a pair of boots or it's possible\n"+
"to find someone to barter these.\n"
  );
  set_weight(2);
  set_value(2000+random(300));
}

init() {
  add_action("cmd_barter","barter");
}

cmd_barter(str) {
  if(id(str)) {
    if(present("mr. duke",environment(this_player()))) {
      write("Mr. Duke says: Wow I'm glad to see this, this means\n"+
            "you have been adventuring in the sewer!\n"+
            "Mr. Duke says: I'll give you "+value+" coins for it.\n");
      this_player()->add_money(value);
      destruct(this_object());
      this_player()->recalc_carry();
      return 1;
    }
  }
}
