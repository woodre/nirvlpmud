/*
  anything_wand.c
*/

inherit "obj/treasure";

int wand_charges;
string str, wand_name, who_or_what;
object target_obj;

reset(arg) {
  set_id("wand");
  set_short("A wand");
  set_long("It is a thin wand of ironwood.\n"+
           "\nA small label says: Made by Nooneelse's Doodads Inc.\n");
  set_weight(1);
  wand_charges=12;
}

query_save_flag() { return 1; }

query_value() { return wand_charges * 200; }

set_wand_charges(arg) { sscanf(arg, "%d", wand_charges); }

query_wand_charges() { return wand_charges; }

init() {
  add_action("use_wand", "use");
  add_action("use_wand", "wave");
}

use_wand(str) {
  int random_spell_nbr;
  string at_on;
  who_or_what = 0;
  if (!str) return;
  if (query_verb()=="wave") {
    sscanf(str, "%s at %s", wand_name, who_or_what);
    at_on="at";
  }
  else {
    sscanf(str, "%s on %s", wand_name, who_or_what);
    at_on="on";
  }
  if (!id(wand_name) || !who_or_what &&
      (!present(who_or_what, this_player()) &&
       !present(who_or_what, environment(this_player())))) {
    write(capitalize(query_verb())+" wand "+at_on+" who or what?\n");
    return 1;
  }
  target_obj=present(who_or_what, environment(this_player()));
  if (wand_charges < 1) {
    write("Seems it doesn't have any charges left.\n");
    return 1;
  }
  if (this_player()->query_level() < 21 &&
      (!target_obj->query_npc() && !target_obj->query_pl_k())) {
    write("You can't damn a player that hasn't set player-killer!\n");
    return 1;
  }
  if (this_player()->query_level() < 21 &&
      !target_obj->query_npc() &&
      !my_player()->query_pl_k()) {
    write("You can't damn a player unless you set player-killer!\n");
    return 1;
  }
  random_spell_nbr = random(4);
  wand_charges = wand_charges - 1;
  target_obj->attacked_by(this_player());
  if (random_spell_nbr==0) magic_dart(who_or_what);
  if (random_spell_nbr==1) lightning(who_or_what);
  if (random_spell_nbr==2) firebolt(who_or_what);
  if (random_spell_nbr==3) blast(who_or_what);
  return 1;
}

magic_dart(who_or_what) {
  int random_nbr;
  random_nbr = random(40);
  target_obj->hit_player(random_nbr);
  write("A glowing blue magic dart springs from the wand to strike "+
        capitalize(who_or_what)+"!\n");
  say("A glowing blue magic dart springs from "+this_player()->query_name()+
      "'s wand to strike "+capitalize(who_or_what)+"!\n");
  return 1;
}

lightning(who_or_what) {
  int random_nbr;
  random_nbr = random(55);
  if (random_nbr > 50) random_nbr = 50;
  target_obj->hit_player(random_nbr);
  write("A sizzling ball of lightning springs from the wand to strike "+
        capitalize(who_or_what)+"!\n");
  say("A sizzling ball of lightning springs from "+this_player()->query_name()+
      "'s wand to strike "+capitalize(who_or_what)+"!\n");
  return 1;
}

firebolt(who_or_what) {
  int random_nbr;
  random_nbr = random(75);
  if (random_nbr > 50) random_nbr = 50;
  target_obj->hit_player(random_nbr);
  write("A flamming bolt of fire springs from the wand to strike "+
        capitalize(who_or_what)+"!\n");
  say("A flamming bolt of fire springs from "+this_player()->query_name()+
      "'s wand to strike "+capitalize(who_or_what)+"!\n");
  return 1;
}

blast(who_or_what) {
  int random_nbr;
  random_nbr =  20 + random(100);
  if (random_nbr > 50) random_nbr = 50;
  target_obj->hit_player(random_nbr);
  write("A glowing green energy blast springs from the wand to strike "+
        capitalize(who_or_what)+"!\n");
  say("A glowing green energy blast springs from "+this_player()->query_name()+
      "'s wand to strike "+capitalize(who_or_what)+"!\n");
  return 1;
}
