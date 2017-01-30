inherit "/obj/weapon";
int dropped;
reset(arg) {
  if(arg) return;
  set_short("Shadow");
  set_id("shadow");
  set_alias("blade");
  set_long(
"This is a very ancient sword that was made long ago from the tooth of a\n"+
"very powerful demon.  The blade is approximately 9 foot long, is jet black,\n"+
"and is extremely deadly (probably the deadliest in history).  The wielder\n"+
"should be warned, however, the blade has been know to have an attitude.\n"+
"You see a little inscription on the side that simply reads: \"fix\"\n");
/* High wc, high weight, high value on a VERY hard creature
(see /players/grimm/monster/exterm.c) and set up so that only >1< will
be on the game at any one time. */
  set_class(25);
  set_weight(10);
  set_value(200000);
  dropped=0;
/*
  call_out("kill_weapons",1);
*/
  set_hit_func(this_object());
}

weapon_hit(attacker) {
  if(random(100)<31) {
  say("Shadow drains the life out of it's victim!\n");
  write("Shadow drains the life out of it's victim!\n");
  return 10;
  }
  return 5;
}

id(str) { return str=="blade" || str=="shadow" || str=="sword" ||
                 str=="shadow sword" || str=="shadow blade"; }

drop() {
  if(!dropped) {
    dropped++;
    return 0;
  }
  write("The shadow blade feels unwanted and returns home to its original master.\n");
  say("The shadow blade feels unwanted and returns home to its original master.\n");
  "/players/grimm/rooms/haphaz_k12d2"->reset("force");
  destruct(this_object());
  return 1;
}

kill_weapons() {
  object ob, me, prev;
  me=environment(this_object());
  ob=first_inventory(me);
tell_object(find_living("grimm"),"startin\n");
tell_object(environment(this_object()),ob->short()+"\n");
  while(ob) {
tell_object(find_living("grimm"),
  "'"+ob->short()+"'\n");
    if(!(ob==this_object())) {
      if(ob->weapon_class()) {
        say("Shadow gets jealous of a "+ob->short()+" and destroys it.\n");
        prev=ob;
        ob=next_inventory(ob);
        destruct(prev);
      } else ob=next_inventory(ob); }
    else ob=next_inventory(ob);
  }
tell_object(find_living("grimm"),"killing\n");
  call_out("kill_weapons",5);
  return 1;
}

/* Won't autoload because the item is not initialized in the /room/init_file,
BUT the autoload section below allows the item to NOT be stored in the
lockers ;)   */
query_auto_load() {
  return "/players/grimm/weapons/shadow:"; }

init() {
  ::init();
  add_action("fix_weapon","fix");
}
