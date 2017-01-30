inherit "obj/weapon.c";
int fuel;

reset(arg) {
  ::reset(arg); 
  if(arg) return;
  set_name("deathsword");
  set_alias("sword");
  set_short("Deathsword");
  set_long("By typing statsword a level 4 or higher can check the fuel.\n");
  set_value(3000);
  set_class(19);
  set_weight(5);
  call_out("fake_beat",3);
}

query_save_flag() { return 1;}

init() {
    add_action("charge", "charge");
    add_action("stat_sword", "statsword");
    ::init();
}

wield(str) {
  object name;
  int align;
  if(!id(str))
     return 0;
  name = call_other(this_player(), "query_name", 0);
  if(wielded) {
    write("You already wield it!\n");
    return 1;
  }
  align = call_other(this_player(), "query_alignment", 0);
  if(align >= 0) {
    write("Deathsword screams in pain as you attempt to wield her.  She\n");
    write("shrieks at you 'I am far more evil than thou!' and sends a\n");
    write("jolt to you.\n");
    say(name + " attempts to wield the deathsword and fails.\n");
    call_other(this_player(), "hit_player", 20);
    return 1;
  }
  if(align < 0) {
    write("You grab the deathsword, and it begins to glow with an smokey\n");
    write("black glow.  Deathsword howls in anticipation of its next\n");
    write("victim.\n");
    say("Deathsword howls with the anticipation of its next kill.\n");
    wielded_by = this_player();
    call_other(this_player(), "wield", this_object());
    wielded = 1;
    return 1;
  }
}
charge(str) {
object ob;
	if (!id(str)) return 0;
	if (str != "deathsword") return 0;
	ob = present("swordbat",this_player());
	if (!ob) {
		write("you have no sword charger.\n");
		return 1;
	}
	fuel = 0;
	destruct(ob);
	return 1;
}

fake_beat() {
  if(fuel > 3000) {
    say("Dragonslayer glows with a murky green light.\n");
    say("Dragonslayer shrieks then returns to its master who created it.\n");
    call_other(wielded_by, "stop_wielding");
    destruct(this_object());
  }
  if(wielded == 1) {
    fuel += 3;
  }
call_out("fake_beat",5);
return 1;
}

stat_sword() {
  if(this_player()->query_level() < 4)
    { return 0; }
  write("Status of Deathsword\n");
  write("  Fuel Used :: " + fuel + "\n");
  write("  Fuel Left :: " + (3000 - fuel) + "\n");
  return 1;
}

