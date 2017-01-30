#define HEAL random(10)
object owner;

id(str) { return str=="symbol"; }
reset(arg) {
  if(arg) return;
  set_heart_beat(1);
}
short() { return "Symbol of the Testers Guild"; }
long() {
  write("This is the solemn symbol of the honorable guild of testers.\n");
}

extra_look() {
  return environment()->query_name()+" is a test character.\n";
}

init() {
  if(!owner) owner=this_player();
  add_action("cmd_spell","spell");
  add_action("cmd_spell","sp");
}
heart_beat() {
  if(!owner) return;
  if(owner->query_hp() < owner->query_mhp() && !random(4)) {
    owner->heal_self(HEAL);
    tell_object(owner,"You are healed by your wizard's niftyness.\n");
  }
}
