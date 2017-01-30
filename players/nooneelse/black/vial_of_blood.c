/*
 vial_of_blood.c
*/

/*
  This stuff is a way for players to join the vampire's cult.
*/

inherit "obj/treasure";

object obj, fangs;

string str;

init() {
  ::init();

  add_action("drink", "drink");
}

drink(str) {
  if (!str || str != "blood") return;
  write("You drink the blood and the vial crumbles to dust.\n");
  say(this_player()->query_real_name()+
      " drinks from a vial,  which then crumbles to dust.\n");
  join_cult();
  destruct(this_object());
  return 1;
}


query_save_flag() { return 1; }

reset(arg) {
  set_short("a glass vial");
  set_long("It is a small glass vial filled with a dark red liquid.\n" +
           "It looks like blood!\n");
  set_value(0);
  set_weight(1);
}

join_cult(str) {
  if (this_player()->query_guild_exp() > 0) {
    write("What?  You're already a member of a guild!\n");
    return 1;
  }
  say("You see a subtle change in "+this_player()->query_objective()+".\n");
  fangs=clone_object("players/nooneelse/black/vampire_fangs");
  move_object(fangs, this_player());
  this_player()->add_guild_exp(666);
  obj=present("vampire bite", this_player());
  if (obj) destruct(obj);
  call_other("players/nooneelse/black/cult_lower_hall", "???");
  call_other("players/nooneelse/black/cult_lower_hall", "add_player",
             this_player()->query_real_name());
  write("Welcome to the Vampire's Cult!\n\n");
  write("You have been given fangs indicating membership.\n");
  write("You can see the cult's commands by typing:\n"+
        "'help cult1' & 'help cult2'.\n");
  return 1;
}

prevent_insert() {
  write("You can't hide this away!\n");
  return 1;
}

id(str) { return (str=="vial" ||
                  str=="blood" ||
                  str=="vial of blood" ||
                  str=="glass vial" ||
                  str=="small vial"); }
