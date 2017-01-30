inherit "obj/treasure";

reset(arg) {
  if(arg) return;
  set_id("body");
  set_alias("unborn ant");
  set_short("an unborn ant body");
  set_long(
"This is a body of a small ant thats hasn't fully developed.  All of its body\n"+
"parts are present.  The main part of its body seems to be missing some internal\n"+
"organs.  Part of its skeleton is also on the outside of its body.  It is possible\n"+
"that a human might buy this from you.\n"
  );
  set_weight(3);
  set_value(1000+random(2000));
}

init() {
  add_action("cmd_barter","barter");
}

cmd_barter(str) {
  if(id(str)) {
    if(present("mr. duke",environment(this_player()))) {
      write("Mr. Duke says: Wow i'm glad to see this, this means\n"+
            "there are less ants to worry about, Thank you!\n"+
            "Mr. Duke says: I'll give you "+value+" coins for it.\n");
      this_player()->add_money(value);
      destruct(this_object());
      this_player()->recalc_carry();
      return 1;
    }
  }
  notify_fail("Barter what?\n");
}
