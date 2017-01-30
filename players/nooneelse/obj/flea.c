/*
  flea.c
*/

inherit "obj/treasure";

int start_time;

query_auto_load() {
  return "/players/nooneelse/obj/flea:" + start_time;
}

start(obj) {
  move_object(this_object(), obj);
}

get() { return 1; }

drop() { return 1; }

reset(arg) {
  set_short("A flea");
  set_long("An annoying flea.\n");
  set_weight(0);
  set_value(0);
  call_out("flea_activity", 5);
}

id(str) { return str=="flea"; }

init() {
  ::init();

  add_action("mess_with_flea", "scratch");
  add_action("mess_with_flea", "kill");
  add_action("mess_with_flea", "swat");
}

mess_with_flea(arg) {
  string str;

  if (!arg) return 0;
  str=0;
  sscanf(arg, "%s flea", str);
  if (!str) sscanf(arg, "flea %s", str);
  if (arg=="flea" || arg=="fleas") str="flea";
  if (!str) return 0;
  write("You attempt to "+query_verb()+
        " the tiny flea, but it hops out of the way!\n"+
        "Annoyed at your attempt, it bites you!  OUCH!\n");
  tell_my_room(environment(this_object())->query_name()+
               " jumps as if just bitten by something!");
  return 1;
}

flea_activity() {
  int random_nbr;

  if (!environment(this_object()) || !living(environment(this_object())))
    destruct(this_object());

  random_nbr=random(100);

  /* bite the carrier */
  if (random_nbr < 15) {
    tell_object(environment(this_object()),
                "OUCH!  You feel the sharp pinch of a flea bite!\n");
    tell_my_room(environment(this_object())->query_name()+
                 " jumps as if just bitten by something!");
    call_out("flea_activity", random(20)+10);
    return 1;
  }

  /* multiply onto another carrier */
  if (random_nbr > 80) {
    flea_hop();
    call_out("flea_activity", random(20)+10);
    return 1;
  }

  call_out("flea_activity", random(20)+10);
}

/* tell my room, but not me */
tell_my_room(str) {
  string players_here;
  players_here = first_inventory(environment(environment(this_object())));
  while (players_here) {
    if (living(players_here) &&
        !players_here->query_npc() &&
        players_here != environment(this_object())) {
      tell_object(players_here, str+"\n");
    }
    players_here=next_inventory(players_here);
  }
  return 1;
}

/* tell my room, but not me */
flea_hop() {
  string players_here;
  players_here = first_inventory(environment(environment(this_object())));
  while (players_here) {
    if (living(players_here) && players_here != environment(this_object())) {
      move_object(clone_object("/players/nooneelse/obj/flea"), players_here);
      tell_object(players_here,
        "You feel a light tickle, as if an insect has landed on you.\n");
      tell_object(environment(this_object()),
        "You see a flea hop onto "+players_here->query_name()+".\n");
    }
    players_here=next_inventory(players_here);
  }
  return 1;
}
