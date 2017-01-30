inherit "room/room";

reset(arg) {
if(!arg){
set_light(1);
short_desc="Great Shark (eaten alive)";
long_desc=
"You have been swallowed alive by the Great Shark!  You are now\n"+
"all squished up in the belly of the Great Shark.  The sharks\n"+
"stomach acids are certainly not good for your skin!\n";

dest_dir=({
});

call_out("acid", 3);

   }
}

query_ilstkarn(){ return "shark"; }
realm(){ return "NT"; }
query_nofollow(){ return 1; }
query_no_teleport(){ return 1; }
query_underwater(){ return 1; }

init() {
  ::init();
  if(!this_player()->is_player()) {
    tell_room(this_object(),
    capitalize(this_player()->query_name())+" dies in the sharks stomach.\n");
    this_player()->hit_player(10000);
    return;
  }
#ifndef __LDMUD__
  add_action("no_way"); add_xverb("");
#else
  add_action("no_way", "", 3);
#endif
  add_action("s_look","look");
  add_action("s_look","l");
  if(this_player()->query_level() > 20) { 
    add_action("out","out"); 
  }
  call_out("escape", 10+random(30), this_player());
}

s_look() {
  write(long_desc);
  return 1;
}

out() {
  write("You leave out.\n");
  this_player()->move_player("out#players/pavlik/ilstkarn/lake1");
  return 1;
}

no_way() {
  write("You have been swallowed by the Great Shark!\n");
  write("You can't do anything!\n");
  return 1;
}

eject_all(env) {
  object obj;
  int i;

  tell_room(this_object(),
  "With one last breath the Great Shark coughs you up!\n");

  obj = all_inventory(this_object());
  for(i=0; i<sizeof(obj); i++) {
    move_object(obj, env);
  }
  return 1;
}

escape(ob) {
  object shark;

  if(!ob || !present(ob, this_object())) {
    return 1;
  }

  shark = find_living("great_shark");

  if(!shark) {
    tell_object(ob,
    "With one last breath the Great Shark coughs you up!\n");
    move_object(ob, "players/pavlik/ilstkarn/lake1");
    return 1;
  }

  tell_object(ob,
  "The Great Shark coughs you up!\n");
  tell_room(environment(shark),
  "The Great Shark coughs up "+capitalize(ob->query_name())+"!\n");
  move_object(ob, environment(shark));
  return 1;
}

acid() {
  object obj;
  int i;

  tell_room(this_object(), "Stomach acids burn your skin!\n");
  obj = all_inventory(this_object());
  for(i=0; i<sizeof(obj); i++) {
    if(living(obj[i])) obj[i]->hit_player(1+random(5));
  }
  call_out("acid", 3+random(3));
  return 1;
}

