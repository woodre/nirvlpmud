/*
 vial.c
*/

/*
 * This stuff is good for a single use against the vampires in nooneelse's
 * castle.  If a player drinks it, it will alter their alignment by +200.
*/

inherit "obj/treasure";

string str;

object vampire;

int new_alignment, hp_now;

init() {
  ::init();

  add_action("throw", "throw");
  add_action("throw", "toss");
  add_action("drink", "drink");
}

throw(str) {
  if (!str || str != "vial") { return 0; }
  vampire=0;
  vampire=present("vampire", environment(this_player()));
  if (!vampire) {
    write("Ok.\n");
    write(this_player()->query_name() + " shatters a vial against the wall.\n");
    destruct(this_object());
    return 1;
  }
  write("Ok.\n");
  write(this_player()->query_name()+
        " throws a vial of liquid at the creature.\n"+
        "It screams in agony.\n");
  if (vampire->query_hit_point())  hp_now=(vampire->query_hit_point()) / 4;
  else
  if (vampire->query_hp())  hp_now=(vampire->query_hp()) / 4;
  vampire->reduce_hit_point(hp_now);
  destruct(this_object());
  return 1;
}

drink(str) {
  if (!str || str != "water") { return 0; }
  write("You drink the holy water and the vial crumbles to dust.\n");
  say(this_player()->query_real_name()+
      " drinks from a vial,  which then crumbles to dust.\n");
  new_alignment=this_player()->query_alignment() + 200;
  this_player()->set_al(new_alignment);
  destruct(this_object());
  return 1;
}


reset(arg) {
  set_short("a glass vial");
  set_long("It is a small glass vial filled with a clear liquid.  There is\n" +
           "an ancient Holy Symbol etched in the side.\n");
  set_value(25);
  set_weight(1);
}

id(str) { return (str=="vial" ||
                  str=="holy water" ||
                  str=="glass vial" ||
                  str=="small vial" ||
                  str=="holy item"); }
