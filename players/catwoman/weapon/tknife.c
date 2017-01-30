inherit "/players/catwoman/weapon/weapon.c";
#define weapon this_object()

int fuel;
object knife;
init() {
    set_heart_beat(1);

    ::init();
     call_other(weapon, "set_name", "blade");
     call_other(weapon, "set_short_desc", "shadow blade");
     call_other(weapon, "set_id", "blade");
     call_other(weapon, "set_class", 15);
     call_other(weapon, "set_alt_name", "blade");
     call_other(weapon, "set_weight", 2);
     call_other(weapon, "set_alias", "blade");
     call_other(weapon, "set_save_flag", 0);
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

    write("You grab hold of the shadows.\n");
    say("Shadows take shape.\n");
    wielded_by = this_player();
    call_other(this_player(), "wield", this_object());
    wielded = 1;
    return 1;

}

heart_beat() {
  if(fuel == 2000) {
    say("The shadows fade and vanish.\n");
    call_other(wielded_by, "stop_wielding");
    set_heart_beat(0);
    destruct(this_object());
  }
  if(wielded == 1) {
    fuel += 1;
  }
}
drop(){
	write("The blade returns to the shadows.\n");
	destruct(this_object());
	return 1;
}

query_value() {return 3000;}
