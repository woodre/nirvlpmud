inherit "obj/treasure";
string who;
int count;
int count2;
reset(arg) {
  set_id("blade barrier");
  
  set_alias("blade");
  set_weight(100);
  set_heart_beat(1);
  set_short("A blade barrier");
  set_long("This blade barrier damages all the monsters in the room.\n");
}
set_who(w) { who = w; }
query_who() { return who; }

heart_beat() {
object ob, obj;
  if(count >  8) {
    tell_room(environment(this_object()), "The blade barrier fades away.\n");
    destruct(this_object());
    return;
  }
  if(!present(who, environment(this_object())))
    destruct(this_object());
  count2++;
  if(count2 > 4) count2 = 0;
  if(count2 == 2) {
  ob = first_inventory(environment(this_object()));
  while(ob) {
    obj = next_inventory(ob);
    if(living(ob) && ob->query_npc() && !ob->query_follower() ) {
        ob->hit_player(random(10) + 15);
      tell_room(environment(this_object()),
        ob->query_name()+" takes damage from the blade barrier.\n");
    }
    ob = obj;
  }
  count++;
  }
  return;
}


