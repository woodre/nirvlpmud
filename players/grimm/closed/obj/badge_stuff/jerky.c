inherit "/obj/treasure";
string nme;
int jerk;
reset(arg) {
  if(arg) return;
  nme = "Nothing";
  jerk = 5;
  set_alias("jerky");
  set_weight(1);
  set_long("This is a rough jerky made from the corpse of a "+capitalize(nme)+".\n");
}

set_nme(str) {
  nme = str;
  return 1;
}

init() {
  add_action("eat","eat");
}

eat(str) {
  if(!str || str != "jerky") return 0;
  if(str=="jerky") {
    this_player()->add_hit_point(jerk);
    say(capitalize(this_player()->query_name())+" eats a strip of jerky.\n");
     if(jerk>15) 
       write("You eat some jerky and smell the smoke wafting from your ears.\n");
     else if(jerk>10)
       write("You eat some jerky and wipe the tears from your eyes.\n");
     else if(jerk>5)
       write("You eat some jerky and wipe the sweat from your brow.\n");
     else
    write("You eat some jerky and feel better.\n");
    destruct(this_object());
    return 1;
  }
  return 0;
}

short() {
  return capitalize(nme)+" Jerky";
}

long() {
  write("This is rough jerky made from the corpse of a "+capitalize(nme)+".\n");
  return 1;
}

add_jerk(x) { jerk = jerk+x; return 1; }

query_jerk() { return jerk; }
