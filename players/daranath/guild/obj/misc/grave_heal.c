#define tp this_player()
#define NECRO present("necro_ob",tp)

int occup;
object who;

id(str) { return str == "grave_heal" || str == "grave"; }

short() { return "A recently opened grave"; }

long() {
write("The strong smell of death comes from this recently opened gravesite.\n"+
      "You feel you can <rest> within the grave.\n");
}

reset(arg) {
  if(arg) return;
  occup = 0;
  who = 0;
}

init() {
  if(environment(tp) == this_object()) {
    add_action("leave_grave","leave");
  } else if(environment(tp) == environment(this_object())) {
    add_action("rest_grave","rest");
  }
}

rest_grave(str) {
  if(!str) {write("What would you like to rest in?\n"); return 1; }
  if(id(str)) {
    if(!NECRO) { write("you may not enter the grave.\n"); return 1; }
    if(occup) { write("The Grave is already occupied.\n"); return 1; }
  say(tp->query_name()+" enters the recently opened gravesite.\n");
  write("You rest within the embrace of the gravesite.\n");
	move_object(tp,this_object());
	who = tp;
    set_heart_beat(1);
return 1;
  }
}

leave_grave() {
  write("You leave the grave.\n");
  move_object(tp,environment(this_object()));
  destruct(this_object());
  return 1; 
}

heart_beat() {
  if(who) {
    tell_object(who,"You feel at peace within the grave.\n");
    who->heal_self(1);
  }
}

exit() { occup = 0; who = 0; set_heart_beat(0); }
realm() {return "NT";}

