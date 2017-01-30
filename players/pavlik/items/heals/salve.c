#define ME capitalize(this_player()->query_real_name())

id(str) {
  return str == "salve";
}

reset() {}

long() {
  write(
  "A salve with healing powers.  Simply 'apply' the salve to\n"+
  "speed the healing of your wounds.\n");
  return;
}

short() { return "A healing salve"; }

init() {
  add_action("apply_salve","apply");
}

apply_salve(arg) {
  if(id(arg)) {
    write(
    "You apply the salve to your wounds.\n"+
    "The natural properties of the salve cool your skin.\n"+
    "You feel better.\n");
    say(ME+" uses a healing salve.\n");
    this_player()->heal_self(20+random(30));
    this_player()->add_weight(-1);
    destruct(this_object()); 
    return 1;
  }
}

get() { return 1; }
query_weight() { return 1; }
query_value() { return 500; }
query_save_flag(){ return 1; }

