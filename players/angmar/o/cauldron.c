#pragma strong_types

inherit "obj/container";

void
reset(status arg) {
  ::reset(arg);
  if (arg)
    return;
  set_name("cauldron");
  set_short("A big cauldron");
  set_long("A big black iron cauldron. I wonder what it has been used for?\n");
  set_weight(100);
  set_value(0);
  set_max_weight(100000);
}

void
reward() {
  object money, ob, next_ob;

  tell_room(environment(this_object()), 
    "Gosh! Steam comes out of the cauldron!\n");
  ob = first_inventory(this_object());
  while(ob) {
    next_ob = next_inventory(ob);
    destruct(ob);
    ob = next_ob;
  }
  if(this_player()->query_level() < 12) {
    money = clone_object("obj/money");
    money->set_money((int)this_player()->query_level() * 100 + random(100));
    move_object(money, this_object());
  }
  move_object(clone_object("players/angmar/o/silver_ring"), this_object());
}

mixed
check_ingredients() {
  object corpse;
  string a;

  if (!present("dead fish") ||
      !present("slimy mushroom") ||
      !present("rat skeleton") ||
      !present("corncob") ||
      !present("angmars recipe")) {
    return 0;
  }
  corpse = present("corpse");
  if (!corpse) {
    return 0;
  }
  return (sscanf(corpse->short(),"corpse of %s",a) == 1) ||
         (sscanf(corpse->short(),"Corpse of %s",a) == 1);
}

void
catch_it(string str) {
  string a,b;

  if (sscanf(str,"%skashmirak gorondolum%s",a,b) == 2) {
    if(check_ingredients())
      reward();
    else
      write("Nothing happens.\n");
  }
}

status can_put_and_get() { return 1; }
status get() { return 0; }
