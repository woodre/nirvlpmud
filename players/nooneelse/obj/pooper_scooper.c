/*
  pooper_scooper.c
*/

inherit "obj/treasure";

string str;
object obj;

init(arg) {
  add_action("scoop_poop", "scoop");
}

scoop_poop(str) {
  string str2;
  if (!str || str=="pee") {
    obj=present("cult_wolf_pee", environment(this_player()));
    if (!obj) {
      write("Huh?  There isn't any here.\n");
      return 1;
    }
  }
  if (!str || str=="poop") {
    obj=present("cult_wolf_poop", environment(this_player()));
    if (!obj) {
      write("Huh?  There isn't any here.\n");
      return 1;
    }
  }
  destruct(obj);
  tell_my_room(this_player()->query_name()+
               " uses a handy-dandy-super-duper pooper-scooper to\n"+
               "clean up a little.\n");
  write("You use your handy-dandy-super-duper pooper-scooper to\n"+
        "clean up a little.\n");
  return 1;
}

reset(arg) {
  if (arg) return;

  set_value(25);
  set_weight(1);
}

short() { return "A pooper scooper"; }

long() {
  write(short()+".\n"+
        "If you're so inclined, you can 'scoop poop' or 'scoop pee' to\n"+
        "help clean up your neighborhood.\n"+
        "\nA small label says: Made by Nooneelse's Doodads Inc.\n");
}

/* tell my room, but not me */
tell_my_room(str) {
  string players_here;
  if (first_inventory(environment(this_player())))
    players_here = first_inventory(environment(this_player()));
  else
    players_here = first_inventory(this_player());
  while (players_here) {
    if (living(players_here) &&
        !players_here->query_npc() &&
        players_here != environment()) {
      tell_object(players_here, str);
    }
    players_here=next_inventory(players_here);
  }
  return 1;
}

id(str) { return str=="pooper scooper" ||
                 str=="pooper_scooper" ||
                 str=="scooper"; }
