int amount_of_delay;
string name;
string activated_mesg;
status is_armed;
int weight;
int value;
int damage;
object targetloc;
 
long() {
    write("To use Rune:\n 1. Arm Rune\n 2. Drop Rune\n 3. Leave Room.\n");
}
 
reset(arg) {
    if (arg)
        return;
    amount_of_delay = 5; name = "rune"; is_armed = 0; weight = 2; activated_mesg = "BOOM!!\n"; damage = 30; value = 150;
}
set_weight(w) {weight = w;}
set_damage(d) {damage = d;}
set_mesg(m) {activated_mesg = m;}
set_value(v) {value = v;}
query_weight() {return weight;}
set_name(n) {name = n;}
set_fuel(f) {amount_of_delay = f;}
short() {
    if (is_armed)
       return name + " (armed)";
    if (amount_of_delay == 0)
       return name + " (burnt out)";
    return name;
}
 
init() {
destruct(this_object());
return 1;
    add_action("arm","arm");
    add_action("drop","drop");
}
 
arm(str) {
object me;
me = this_player();
   if (!str || str != name)
     return 0;
   if (me->query_pl_k() == 0){
	write("you cant kill players\n");
	return 1;
	}
   if (amount_of_delay == 0) {
      write("End of fuel.\n");
      return 1;
}
   if (is_armed) {
      write("It is already armed!\n");
      return 1;
}
is_armed = 1;
    write("Ok.\n");
      set_heart_beat(1);
      return 1;
  }
heart_beat() {
    object ob;
    if (!is_armed)
      return;
    amount_of_delay -= 1;
    say("Tick...\n");
    if (amount_of_delay > 0)
       return;
    say(activated_mesg);
    set_heart_beat(0);
    is_armed = 0;
    ob = environment();
    if (call_other(ob, "query_level"))
        call_other(ob, "add_weight", -weight);
    went_off();
    destruct(this_object());
}
 
id(str) {
    return str == name;
}
query_value() {
    return value;
}
get() { return 1; }
 
went_off() {
   object ob;
   object next_ob;
   int k, points, dam;
   ob = first_inventory(targetloc);
   dam = random(damage/2) + damage/2;
   k = 0;
   while(ob) {
    next_ob = ob;
	if(ob->query_pl_k() == 1){
     if (living(ob)) {
        points = call_other(ob,"query_hp", 0);
        if ((points - dam - 1) < 0 ) { dam = points - 2; }
        call_other(ob, "hit_player", dam);
}
}
ob = next_inventory(ob);
     k = k + 1;
}
return k;
 }
 
drop(silently) {
     targetloc = environment(this_player());
        return 0;
}


