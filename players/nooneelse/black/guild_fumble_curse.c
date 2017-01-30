/*
  guild_fumble_curse.c

  This is a curse of fumbling.  It will make the cursed creature
  drop 50 coins or one item that can be dropped (not if worn or wielded though)
  whenever the player does certain actions (see init).
*/

reset(arg) {
  if (arg) return 0;

  call_out("destruct_this", 300);
}

query_value() { return 0; }

query_weight() { return 0; }

drop(str) { return 1; }

id(str) { return str=="vamp fumble curse" || str=="curse"; }

destruct_this() { destruct(this_object()); }

init() {
  add_action("do_curse",  "i");
  add_action("do_curse",  "look", 1);
  add_action("do_curse",  "examine", 2);
}

/* Tie other curse actions in here. */
do_curse() {
  object coins, stuff;
  int drop_item;
  if (30 > random(100)) {
    /* Don't drop anything if there's something non-living here. */
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

/* Drop a coin unless there's money already here. */
drop_a_coin() {
  object coins;
  int money;
  if (!present("money", environment(this_player()))) {
    money=this_player()->query_money();
    if (money > 0) {
      coins=clone_object("obj/money");
      coins->set_money(50);
      this_player()->add_money(-50, "gold");
      coins->move(environment(this_player()));
      write("\n");
      write("Oops!  You dropped some coins.\n");
      write("\n");
    }
  }
}

/* Drop an item unless there it's wielded, worn or non-droppable. */
drop_random_item() {
  object stuff;
  int worn_wielded, drop_item;
  string str, str2, str3;
  drop_item=1;
  stuff=first_inventory(this_player());
  while (drop_item && stuff) {
    worn_wielded=1;
    str=stuff->short();
    str2=0;
    str3=0;
    if (str && !stuff->query_worn() && !stuff->query_wielded()) worn_wielded=0;
    if (stuff==this_object() || stuff->id("nooneelsering")) worn_wielded=1;
    if (str && !worn_wielded) {
      stuff->move(environment(this_player()));
      if (environment(stuff) != this_player()) {
        write("\n");
        write("Oops!  You dropped "+stuff->short()+".\n");
        write("\n");
        drop_item=0;
      }
    }
    stuff=next_inventory(stuff);
  }
  if (drop_item) { drop_a_coin(); }
}
