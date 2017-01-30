inherit "obj/treasure";
object ob;
int a;
int heal;
int count;
reset(arg) {
if (arg) return;
  set_alias("REGENERATE");
  set_weight(0);
  set_value(0);
  heal = 150;
  set_heart_beat(1);
}

drop() { return 1; }
query_heal() { return heal; }
heart_beat() {
  count++;
  if(count > 3) count = 0;
  ob = environment(this_object());
  if(!ob || !living(ob)) {
    destruct(this_object());
    return;
  }
  if(heal > 0 && count == 2) {
    a = random(5);
    ob->heal_self(5);
    if(a < 1) 
      tell_object(ob,"You feel yourself regenerating and healing.\n");
    heal = heal - 5;
  }
  if(heal <= 0) destruct(this_object());
  return;
}

