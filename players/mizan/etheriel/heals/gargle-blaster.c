id(str) { return str == "blaster"; }
/* For Merlyn */
short() { return "A Pan-Galactic Gargle Blaster"; }
long() {
  write("This is a stainless steel thermos that is cold to the touch.\n"+
        "When you pop off the lid, you notice that it is filled with a\n"+
        "thick, foul-smelling blue muck. You are not too sure if it is\n"+
        "life-threatening or not if you drink it, but a small sticker\n"+
        "on it that reads '100% Kosher' makes you breathe a sigh of relief.\n");
}

 query_save_flag() { return 1; }
get() { return 1; }
query_weight() { return 1; }
query_value() { return 2000; }

init() {
  add_action("drinkit","drink");
}

drinkit(str) {
  if(!str || str != "blaster") return 0;
  if(!this_player()->drink_alcohol(10)) {
      write("Doh! If you drank this right now you'd be DEAD for sure!\n");
    return 1;
  }
  say((this_player()->query_name())+" pops the lid off a thermos and guzzles a thick blue ooze.\n");
  write("You feel as if you were struck by a lemon wrapped around a gold brick.\n");
    this_player()->heal_self(330);
    destruct(this_object());
    return 1;
}
