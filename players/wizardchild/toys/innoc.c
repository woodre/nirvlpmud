#define FLU_ID "flu"
#define NO_FLU_OB "/players/saber/closed/virus/no_disease"
#define NO_FLU_ID "no_disease"
status used;
short() { return "An innoculation gun ("+(used?"empty":"full")+")"; }
id(str) { return str == "gun" || str == "innoculation gun"; }
get()   { return 1; }
query_value() { return 25+((!used)*25); }
long()  {
  write("A clunky, light gun-shaped item, used for injecting small doses of\n");
  write("a virus into the body. Once the virus has been introduced, the body's\n");
  write("immune system takes over.\n");
  if(used)
    write("This one appears to be all used up.\n");
  else
    write("You could inject it into yourself, or into someone else.\n");
  return 1;
}
init()  {
  add_action("inject", "inject");
}
inject(str) { 
  if(used) {
    write("This gun has already been used, and can't be used again.\n");
    return 1;
  }
  if(!str)
    return cure_me();
  return cure_other(str);
}
cure_me() {
  object ob, ob2;
  if(present(NO_FLU_ID, this_player())) {
    write("Your immune system can handle the virus.\n");
    return 1;
  }
  if(this_player()->query_hp() <= 10) {
    write("You are too weak to intake this immunization shot.\n");
    return 1;
  }
  ob = clone_object(NO_FLU_OB);
  write("You muster enough strength to shoot yourself.\n");
  used = 1;
  this_player()->add_hit_point(-10);
  move_object(ob, this_player()); 
  ob2 = present(FLU_ID, this_player());
  if(ob2) destruct(ob2);
  return 1;
}
cure_other(str) {
  object who, ob, ob2;
  who = present(str, environment(this_player()));
  if(!who || !who->is_player()) {
    write("That player is not here.\n");
    return 1;
  }
  if(present(NO_FLU_ID, this_player())) {
    write("That player is strong enough to resist the flu.\n");
    return 1;
  }
  if(who->query_hp() <= 10) {
    write("That player is too weak to take a shot.\n");
    return 1;
  }
  ob = clone_object(NO_FLU_OB);
  write("You sacrafice your innoculation gun, and immunize "+capitalize(str)+".\n");
  tell_object(who, "You are immunized by "+this_player()->query_name()+". OUCH!!\n");
  used = 1;
  who->add_hit_point(-10);
  move_object(ob, who);
  ob2 = present(FLU_ID, who);
  if(ob2) destruct(ob2);
  return 1;
}
