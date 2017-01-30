/* Orginal code from Bern's Clerics, 
   Modified to become The Knight's Templar by Boltar.
*/
inherit "obj/monster.c";
string description;
string owner;
object ownerob;
reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_level(1);
    set_alias("squire");
    set_race("helper");
    set_al(0);
    set_wc(0);
/*
    bad news..  max hp is 5.. chk
            /doc/build/RULES/bags
        -verte
    set_hp(100);
*/
    set_ep(0);
    set_long("He eyes you suspiciously.\n");
    enable_commands();
/*
    set_heart_beat(1);
*/
}

set_owner(i) {
  set_name(lower_case(i)+"'s squire");
  set_short(i+"'s squire");
  owner = i;
  ownerob = find_player(lower_case(owner));
}

/*
heart_beat() {
  object ob;
::heart_beat();
  age += 1;
  ob = find_player(lower_case(owner));
  if (!ob) {
    say("Helper despairs of finding his owner.\n");
    say("Helper says: good bye cruel world!\n");
    destruct(this_object());
    return 1;
  }
  if (!present(ob, environment(this_object()))) {
   tell_room(environment(this_object()),
        short()+" leaves.\n");
    move_object(this_object(), environment(ob));
    tell_room(environment(ob), this_object()->short()+" arrives.\n");
  }
}

*/
pick_up(ob) {
  int weight;
  string bb;
  if (!ob) return 1;
  weight = ob->query_weight();
  bb=ob->short();
  if(!ob->is_money())
  if (!ob->get()) return 1;
  if (!add_weight(weight)) return 1;
  move_object(ob, this_object());
  say(short()+" gets "+bb+"\n");
  return 1;
}

drop_all() {
  object item, next;
  int weight;
  item = first_inventory(this_object());
  add_weight(-weight);
  while(item) {
    next = next_inventory(item);
    if (!item->drop()) {
      move_object(item, environment(this_object()));
      say(short()+" drops "+item->short()+"\n");
  weight = item->query_weight();
  add_weight(-weight);
    }
    item = next;
  }
  return 1;
}

drop_thing(ob) {
  int weight;
  weight = ob->query_weight();
  if (!ob->drop()) {
    move_object(ob, environment(this_object()));
    add_weight(-weight);
    say(short()+" drops "+ob->short()+"\n");
    return 1;
  }
  return 1;
}

drop_money() {
  int amt;
  object coins;
  amt = this_object()->query_money();
  if (!amt) return 1;
  coins = clone_object("obj/money");
  coins->set_money(amt);
  move_object(coins, environment(this_object()));
  say(short()+ " drops "+coins->short()+"\n");
  add_money(-amt);
  return 1;
}


get_all(i) {
  object item, next, container;
  if (i) {
    container = present(i, this_object());
    if (!container) container = present(i, environment(this_object()));
    if (!container) {
      say(short()+" complains that he doesn't have "+i+"\n");
    }
    item = first_inventory(container);
  }
  else item = first_inventory(environment(this_object()));
  while(item) {
    next = next_inventory(item);
    pick_up(item);
    item = next;
  }
  return 1;
}

query_guild() { return "cleric"; }

long() {
  write(short()+"\n"+
        "He eyes you suspiciously.\n");
  if (description) write(description +"\n");
}

describe(i) {
  description = i;
}

add_money(i) { money += i; }

query_save_flag() { return 1; }

query_ok() { return 1; }
sq_follow() {
   if(!environment(this_object())) return;
  if (!ownerob) {
    say("Helper despairs of finding his owner.\n");
    say("Helper says: good bye cruel world!\n");
    destruct(this_object());
    return 1;
  }
  remove_call_out("sq_follow");
    if(!environment(ownerob)) return;
  if(ownerob->query_ghost()) {
    call_out("sq_follow",6);
    return 1;
  }
  if (!present(ownerob, environment(this_object()))) {
   tell_room(environment(this_object()),
        short()+" leaves.\n");
    move_object(this_object(), environment(ownerob));
    tell_room(environment(ownerob), this_object()->short()+" arrives.\n");
  }
  call_out("sq_follow",6);
}
do_cmd(str) {
command(str,this_object());
return 1; 
}
is_npc(){ return 1; }
