inherit "/players/catwoman/weapon/weapon.c";
#define weapon this_object()


init() {
    ::init();
     call_other(weapon, "set_name", "staff");
     call_other(weapon, "set_short_desc", "staff of power");
     call_other(weapon, "set_long_desc", "A large oak staff.\n");
/*     call_other(weapon, "set_value", 3000);*/
     call_other(weapon, "set_id", "staff");
     call_other(weapon, "set_class", 15);
     call_other(weapon, "set_alt_name", "staff");
     call_other(weapon, "set_weight", 5);
     call_other(weapon, "set_alias", "staff");

}
wield(str) {
  object name;
    if(!id(str))
     return 0;
  name = call_other(this_player(), "query_name", 0);
  if(wielded) {
    write("You already wield it!\n");
    return 1;
  }
    
    write("As you wield the staff is spins with a life of its own.\n");
    say("The staff of power spins in the air.\n");
    wielded_by = this_player();
    call_other(this_player(), "wield", this_object());
    wielded = 1;
    return 1;
  }

query_value() {return 1500;}

