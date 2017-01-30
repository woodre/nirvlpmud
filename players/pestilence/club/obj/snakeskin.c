inherit "obj/treasure";

reset(arg) {
  if(arg) return;
  set_id("snakeskin");
  set_alias("snake skin");
  set_short("snakeskin from a water viper");
  set_long(
"This is the skin from a water viper.  It is brown\n"+
"and black scales, and stretches to seven feet long.\n"+
"It is possible to find someone to barter these.\n"
  );
  set_weight(2);
  set_value(3200+random(300));
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
