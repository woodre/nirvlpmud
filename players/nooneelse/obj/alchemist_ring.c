/*
 alchemist_ring.c
*/

/*
* This is a ring of fumbling.  It is cursed & can't be dropped except
* in the adventurer's guild or rogue's guild.  It will make the bearer
* drop 1 coin or one item that can be dropped (not if worn or wielded though)
* whenever the player does certain actions (see below).
*/

inherit "obj/armor";

object coins, stuff;

int silently, money, worn_wielded, weight, drop_item;

string str, str2, str3;

init() {
  ::init();

  add_action("read_ring", "read");
  add_action("do_curse", "i");
  add_action("do_curse", "look");
  add_action("do_curse", "examine");
  add_action("drop_ring", "drop");
}

/* Clue the player of the curse & tell how/where to get rid of it.      */
read_ring(str) {
  if (!str || str != "ring") return;
  write(
    "It says: You really should drop this off where you normally advance.\n");
  return 1;
}

/* Tie other curse actions in here. */
do_curse() {
  if (30 > random(100)) {
/* Don't drop anything if there's somethin non-living here. */
    drop_item=1;
    stuff=first_inventory(environment(this_player()));
    while (drop_item && stuff) {
      if (!living(stuff))
        drop_item=0;
      else
        stuff=next_inventory(stuff);
    }
    if (drop_item) {
      drop_random_item();
      return 0;
    }
    else {
/* Something is here, drop a coin instead */
      drop_a_coin();
      return 0;
    }
  }
  else {
/* Drop a coin most of the time. */
    drop_a_coin();
    return 0;
  }
}

/* Don't drop the ring unless player is in the Guild. */
drop_ring(str) {
  str2=this_player()->query_current_room();
  if (str2=="room/adv_guild" && present(str,this_player())==this_object()) {
    weight=this_object()->query_weight();
    if (!weight) weight=0;
    this_player()->add_weight(-weight);
    this_player()->add_money(43, 1);
    destruct(this_object());
    write("The Guildmaster's assistant thanks you for the ring and "+
          "gives you 43 coins.\n");
    return 1;
  }
  else {
    write("You realize that you like it too much to part with it.\n");
    return 1;
  }
  return 1;
}

reset(arg) {
  ::reset(arg);
  if (arg) return;

  set_name("ring");
  set_alias("Platinum Ring");
  set_short("platinum ring");
  set_long("This is an expensive looking ring that might be platinum & "+
           "it's your size.\n"+
           "There seems to be something written inside the band.\n");
  set_value(0);
  set_weight(1);
  set_ac(1);
  set_alias("ring");
  set_type("ring");
  set_arm_light(1);
}

prevent_insert() {
  write("The " + short() + " shakes and quivers and jumps back out.\n");
  return 1;
}

/* Drop a coin unless there's money already here. */
drop_a_coin() {
  if (!present("money", environment(this_player()))) {
    money=this_player()->query_money();
    if (money > 0) {
      this_player()->add_money(-1, 1);
      coins=clone_object("obj/money");
      coins->set_money(1);
      weight=coins->query_weight();
      if (!weight) weight=0;
      this_player()->add_weight(-weight);
      move_object(coins, environment(this_player()));
      write("\n");
      write("Oops!  You dropped a coin.\n");
      write("\n");
    }
  }
}

/* Drop an item unless there it's wielded, worn or non-droppable. */
drop_random_item() {
  drop_item=1;
  stuff=first_inventory(this_player());
  while (drop_item && stuff) {
    worn_wielded=1;
    str=stuff->short();
    str2=0;
    str3=0;
    if (str && !sscanf(str, "%sworn", str2) && !sscanf(str, "%swielded", str3))
      worn_wielded=0;
    if (str && worn_wielded && !stuff->drop()) {
      weight=stuff->query_weight();
      if (!weight) { weight=0; }
      this_player()->add_weight(-weight);
      move_object(stuff, environment(this_player()));
      write("\n");
      write("Oops!  You dropped " + stuff->short() + ".\n");
      write("\n");
      drop_item=0;
    }
    stuff=next_inventory(stuff);
  }
  if (drop_item) { drop_a_coin(); }
}
