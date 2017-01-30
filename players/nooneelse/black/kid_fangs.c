/*
  kid_fangs.c - fangs, tuxedo, cape & gloves for vamps kids
  added lines 7 & 22 so the fangs would be visible -Eurale (7/30)
*/

inherit "obj/treasure";
#include "/open/ansi.h"

string kid_name;

reset(arg) {
  if (arg) return;

  set_weight(666);
  set_value(0);
}

id(str) { return str=="kid fangs" ||
                 str=="kid stuff" ||
                 str=="vampire kid stuff"; }

short() { return HIR+"small bloody fangs"+NORM; }

drop() { destruct(this_object()); }

extra_look() {
  if (environment(this_object())->is_kid() ||
      (environment(this_object())->am_i_a_servant() &&
       !environment(this_object())->am_i_a_wolf()))
    return environment(this_object())->query_name()+
           " is wearing a black tuxedo and a black, satin lined cloak";
  if (environment(this_object())->am_i_a_servant() &&
      environment(this_object())->am_i_a_wolf())
    return environment(this_object())->query_name()+
           " is wearing a black doggie tuxedo and a black, satin lined cape";
}

init() {
  add_action("smile",          "smile");
  add_action("eat_hamster",    "eat");
  add_action("drain_corpse",   "drain");
  if (environment(this_object())) {
    kid_name = environment(this_object())->query_name();
    if (!environment(this_object())->is_kid() &&
        !environment(this_object())->am_i_a_servant())
      call_out("trash_this", 10);
  }
}

trash_this() {
  if (!environment(this_object())->is_kid() &&
      !environment(this_object())->am_i_a_servant())
    destruct(this_object());
}

smile() {
    tell_room(environment(environment(this_object())),
              environment(this_object())->query_name()+
              " smiles happily, exposing sharp fangs.\n");
  return 1;
}

eat_hamster(str) {
  string str2;
  if (!str || str != "hamster") return 0;
  call_out("effect_1", 2);
  return 1;
}

effect_1() {
  tell_room(environment(environment(this_object())),
      "\n"+environment(this_object())->query_name()+
      " opens a small cage and gets a quivering hamster out of it.\n");
  call_out("effect_2", 2);
  return 1;
}

effect_2() {
  tell_room(environment(environment(this_object())),
      "\n"+environment(this_object())->query_name()+" opens "+
      environment(this_object())->query_possessive()+
      " jaws wide, exposing needle-sharp\n"+
      "fangs and quickly closes them over the hamster.\n");
  call_out("effect_3", 3);
  return 1;
}

effect_3() {
  tell_room(environment(environment(this_object())),
      "\n"+environment(this_object())->query_name()+" clamps "+
      environment(this_object())->query_possessive()+
      " jaws down and you hear a crunch\n"+
      "and one muffled squeak as "+environment(this_object())->query_pronoun()+
      " chews.\n");
  call_out("effect_4", 4);
  return 1;
}

effect_4() {
  tell_room(environment(environment(this_object())),
      "\n"+environment(this_object())->query_name()+
      " seems to gag, then cough.\n");
  call_out("effect_5", 3);
  return 1;
}

effect_5() {
  tell_room(environment(environment(this_object())),
      "\n"+environment(this_object())->query_name()+" moves "+
      environment(this_object())->query_possessive()+
      " jaws around a bit, then spits out\n"+
      "a furball.\n");
  return 1;
}

drain_corpse(str) {
  object corpse_obj, kid_obj, kids_room_obj;
  string kid_possessive;
  kid_obj=environment(this_object());
  kids_room_obj=environment(environment(this_object()));
  if(!kid_obj) return 1;
  if(!kids_room_obj) return 1;
  if (!str || str != "corpse") {
    tell_room(kids_room_obj,
            kid_obj->query_name()+
            " asks: Drain what?\n");
    return 1;
  }
  corpse_obj=present("corpse", kids_room_obj);
  if (!corpse_obj) corpse_obj=present("corpse", kid_obj);
  if (!corpse_obj) {
    tell_room(kids_room_obj,
            kid_obj->query_name()+
            " says: a corpse must be present to do that.\n");
    return 1;
  }
  kid_obj->heal_self(corpse_obj->heal_value());
  destruct(corpse_obj);
  if (kid_obj->query_gender()=="male")
    kid_possessive="his";
  else
  if (kid_obj->query_gender()=="female")
    kid_possessive="her";
  else
      kid_possessive="its";
  tell_room(kids_room_obj,
            kid_obj->query_name()+" sinks "+kid_possessive+
            " fangs into the corpse and drains it's blood.");
  return 1;
}

do_kid_stuff(str) {
  object kid_obj;
  int random_nbr;
  random_nbr = random(100);
  if (random_nbr < 10)
    kid_crap();
  else
  if (random_nbr < 20)
    kid_pee();
  else
  if (random_nbr < 30)
    kid_spit();
  else
  if (random_nbr < 40)
    kid_stare();
  else
  if (random_nbr < 50)
    kid_fondle();
  else
    kid_pick_nose();
  call_out("do_kid_stuff", 180);
}

/* gag routines */
kid_crap() {
  tell_room(environment(environment(this_object())),
            capitalize(kid_name)+" looks around for a second, "+
            "squats and takes a dump in the corner.\n");
  move_object(clone_object("/players/nooneelse/vampire/wolf_poop"),
              environment(environment(this_object())));
}

kid_pee() {
  tell_room(environment(environment(this_object())),
            capitalize(kid_name)+" looks around for a second, "+
            "then takes a leak in the corner.\n");
  move_object(clone_object("/players/nooneelse/black/wolf_pee"),
              environment(environment(this_object())));
}

kid_spit() {
  tell_room(environment(environment(this_object())),
            capitalize(kid_name)+" starts snorting.  "+
            "After a second, "+capitalize(kid_name)+
            " hocks a nasty one into the corner.\n");
}

kid_stare() {
  tell_room(environment(environment(this_object())),
            capitalize(kid_name)+
            " stares vacantly at the front of your pants.\n");
}

kid_fondle() {
  tell_room(environment(environment(this_object())),
            capitalize(kid_name)+" sticks a hand down the front of "+
            "your pants and starts fumbling around.\n");
}

kid_pick_nose() {
  tell_room(environment(environment(this_object())),
            capitalize(kid_name)+" wriggles "+
            environment(this_object())->query_possessive()+" nose.  "+
            "After a second, "+capitalize(kid_name)+
            " starts picking\n"+
            environment(this_object())->query_possessive()+
            "nose and flicking the results into a corner.\n");
}
