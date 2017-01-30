/*
  hamster_cage.c
*/

inherit "obj/treasure";

string str, hamster_eater_name, hamster_eater_real_name;
int number_of_hamsters, i;
object hamster_eater_obj;

init(arg) {
  add_action("eat_hamster",    "eat");
}

eat_hamster(str) {
  string str2;
  if (!str || str != "hamster") return 0;
  if (number_of_hamsters==0) {
    write("Your hamster cage is empty!\n");
    return 1;
  }
  number_of_hamsters -= 1;
  if (number_of_hamsters > 0)
    set_weight(number_of_hamsters);
  else
    set_weight(1);
  if (number_of_hamsters==0) {
    write("Your hamster cage is now empty!\n");
    return 1;
  }
  hamster_eater_name = lower_case(this_player()->query_name());
  hamster_eater_real_name = lower_case(this_player()->query_real_name());
  call_out("effect_1", 2);
  write("Ok.\n");
  return 1;
}

effect_1() {
  hamster_eater_obj=find_player(hamster_eater_real_name);
  if (!hamster_eater_obj) return 0;
  tell_my_room("\n"+capitalize(hamster_eater_name)+
      " opens a small cage and gets a quivering hamster out of it.\n");
  tell_me("\nYou open your cage and get a quivering hamster out of it.\n");
  call_out("effect_2", 2);
  return 1;
}

effect_2() {
  hamster_eater_obj=find_player(hamster_eater_real_name);
  if (!hamster_eater_obj) return 0;
  if (present("vampire fangs", hamster_eater_obj)) {
    tell_my_room("\n"+capitalize(hamster_eater_name)+" opens "+
      hamster_eater_obj->query_possessive()+
      " jaws wide, exposing needle-sharp\n"+
      "fangs and quickly closes them over the hamster.\n");
    tell_me("\nYou open your jaws wide, exposing your needle-sharp "+
            "fangs and\n"+
            "quickly close them over the hamster.\n");
  }
  else {
    tell_my_room("\n"+capitalize(hamster_eater_name)+" opens "+
      hamster_eater_obj->query_possessive()+" jaws wide, exposing sharp\n"+
      "teeth and quickly closes them over the hamster.\n");
    tell_me("\nYou open your jaws wide, exposing your sharp "+
            "teeth and\n"+
            "quickly close them over the hamster.\n");
  }
  call_out("effect_3", 3);
  return 1;
}

effect_3() {
  hamster_eater_obj=find_player(hamster_eater_real_name);
  if (!hamster_eater_obj) return 0;
  tell_my_room("\n"+capitalize(hamster_eater_name)+" clamps "+
      hamster_eater_obj->query_possessive()+
      " jaws down and you hear a crunch\n"+
      "and one muffled squeak as "+hamster_eater_obj->query_pronoun()+
      " chews.\n");
  tell_me("\nAs you clamp your jaws down, you hear a "+
          "crunch and one muffled\n"+
          "squeak as you chew.\n");
  call_out("effect_4", 4);
  return 1;
}

effect_4() {
  hamster_eater_obj=find_player(hamster_eater_real_name);
  if (!hamster_eater_obj) return 0;
  tell_my_room("\n"+capitalize(hamster_eater_name)+
               " seems to gag, then cough.\n");
  tell_me("\nYou feel a tickle deep in your throat.  You start to gag, "+
          "then cough.\n");
  call_out("effect_5", 3);
  return 1;
}

effect_5() {
  hamster_eater_obj=find_player(hamster_eater_real_name);
  if (!hamster_eater_obj) return 0;
  tell_my_room("\n"+capitalize(hamster_eater_name)+" moves "+
      hamster_eater_obj->query_possessive()+
      " jaws around a bit, then spits out\n"+
      "a furball.\n");
  tell_me("\nYou move your jaws around a bit, then spit out a furball.\n");
  hamster_eater_obj->add_spell_point(15);
  hamster_eater_obj->add_hit_point(15);
  return 1;
}

reset(arg) {
  if (arg) return 0;

  number_of_hamsters=5;
  set_value(500);
  set_weight(5);
}

short() { return "A hamster cage, with "+number_of_hamsters+" hamsters in it"; }

long() {
  write(short()+".\n"+
        "If you're so inclined, you can 'eat hamster' & get healed some.\n"+
        "\nA small label says: Made by Nooneelse's Doodads Inc.\n");
}

/* tell my room, but not me */
tell_my_room(str) {
  string players_here;
  if (first_inventory(environment(hamster_eater_obj)))
    players_here = first_inventory(environment(hamster_eater_obj));
  else
    players_here = first_inventory(hamster_eater_obj);
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

tell_me(str) {
  tell_object(hamster_eater_obj, str);
}

id(str) { return str=="hamster cage" || str=="cage"; }
