#pragma strong_types

inherit "obj/armor";

int heals;

void
reset(status arg) {
  ::reset(arg);
  if (arg)
    return;
  set_short("A small gold ring");
  set_long(
"A small gold ring, it has a large 'K' ingraved.\n"+
"You can also see some healing runes on the ring.\n");
  set_name("ring");
  set_weight(1);
  set_type("ring");
  heals = 0;
}

void
init() {
  ::init();
  add_action("heal", "heal");
}

int query_value() { return 10000/(heals+1); }

status
heal() {
  if (this_object()->query_worn()) {
    if (heals < 4) {
      write("You are completely healed.\n");
      heals = heals+1;
      this_player()->heal_self(1000);
      if (heals == 3) {
        write("The ring suddenly crumbles to dust  !\n");
        move_object(this_object(), "players/kantele/store");
        return 1;
      }
    }
    return 0;
  }
  return 0;
}
