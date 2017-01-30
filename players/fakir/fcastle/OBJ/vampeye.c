inherit "obj/armor";
reset(arg) {
  if(arg)
    return ;
  ::reset(arg);
  set_name("vampire eyes");
  set_alias("eyes");
  set_short("Vampire Eyes (Bloody)");
  set_long("A small set of goggle-like eyes, which you could probably wear.\n"
          +"Though these probably would not do much in terms of protection, they would\n"
          +"definitely provide night vision, for a price.\n"
          +"Type 'peer' to do something in the dark.\n");
  set_ac(1);
  set_weight(1);
  set_type("helmet");
  set_value(2500);
}
id(str) { return str == "eyes" || str == "vampire eyes"; }
init() {
  ::init();
  add_action("wear_me", "wear");
  add_action("night_peer", "peer");
}
wear_me(str) {
  if(id(str))
    write("You squish the bloody vampire eyes over your own...Yuck!\n");
  return 0;
}
night_peer(str) {
  if(!str) {
    write("Type 'peer eyes' to do something in the dark.\n");
    return 1;
  }
  if(set_light(0)) {
    write("You have no need for vampire eyes here.\n");
    return 1;
  }
  if(this_player()->query_hp() <= 5) {
    write("Your too close to death to use the eyes.\n");
    return 1;
  }
  if(!this_object()->query_worn()) {
    write("You must be wearing the vampire eyes first.\n");
    return 1;
  }
  this_player()->add_hit_point(-5);
  write("You feel a slight pain in your eyes, but suddenly all is light as midday.\n");
  set_light(1);
  command("$look");
  command(str, this_player());
  set_light(-1);
  return 1;
}
