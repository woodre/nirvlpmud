inherit "obj/monster";
#define IT capitalize(this_object()->query_attack()->query_name())
#define ME capitalize(this_player()->query_name())
#define ROOM environment(this_object())

object obj;

reset(arg){
  ::reset(arg);
  if(arg) return;
  set_name("Dreadnaught");
  set_alias("dreadnaught");
  set_race("unknown");
  set_short("A Dreadnaught");
  set_long(
  "The Dreadnaught is the creation of a twisted and sinister mind.  This\n"+
  "beast is a large battering-ram possessed with the spirit of a Demon.\n"+
  "The 'naughts four spiked wheels churn powerfully is it rumbles across\n"+
  "the rocky ground.  Black smoke pours from the Dreadnaught and it's\n"+
  "razorbladed battering-ram sends a shiver down your spine.\n");
  set_level(20+random(5));
  set_al(-1000);
  set_wc_bonus(5);
  set_hp(400+random(300));
  set_wc(20+random(20));
  set_ac(50);
  set_aggressive(0);
  set_dead_ob(this_object());
  money = 1000+random(1000);
  call_out("kombat", 3);
}

init() {
  ::init();
  if(this_player()->is_player() && !query_attack()) 
    call_out("rumble", 5, this_player());
}

rumble(ob) {
  if(!present(ob, environment(this_object()))) {
    return 1;
  }

  if(ob->query_alignment() < 0) {
    tell_object(ob,
    "The sinister Deadnaught charges you at full speed!!!  The wicked blade\n"+
    "of the battering-ram swerves away at the last possible moment.\n"+
    "You hear a low demonic laughter from the evil machine.\n");
  }
  else {
    tell_object(ob,
    "The sinister Dreadnaught charges you at full speed!!!\n"+
    "The wicked blade of the battering-ram SLAMS into you and GASHES you!\n");
    ob->hit_player(random(50));
    this_object()->attack_object(ob);
  }
  return 1;
}

kombat(){
  int ranx;

  if(!this_object()->query_attack()){
    call_out("kombat", 15);
    return 1;
  }

  obj = this_object()->query_attack();
  ranx = random(18);

  if(!present(obj, environment(this_object()))){
    call_out("kombat", 10);
    return 1;
  }

  /* random battle message */
  if(ranx == 0) tell_room(ROOM,
    "Black smoke pours from the Dreadnaught as it charges across the rocky ground.\n");
  else if(ranx == 1) tell_room(ROOM,
    "The Dreadnaught's heavy battering-ram SLAMS into "+IT+"!\n"+
    IT+" go sprawling across the rocky ground.\n");
  else if(ranx == 2) tell_room(ROOM,
    "The Deadnaughts spiked wheels SHRED "+IT+"'s flesh!\n");
  else if(ranx == 3) tell_room(ROOM,
    "Dreadnaught laughs demonically as it rolls over "+IT+"!\n");
  else if(ranx == 6) tell_room(ROOM,
    "Dreadnaught GASHES "+IT+" with its razorsharp battering-ram!\n");
  else if(ranx == 8) stun();
  else if(ranx == 11) tell_room(ROOM,
    "Dreadnaught MAULS "+IT+" with its sledgelike battering-ram!\n");
  else if(ranx == 14) tell_room(ROOM,
    "Dreadnaught rumbles past you, spitting up tiny rocks and a cloud of dust.\n");

  /* i really don't like pets */  
  if(obj->query_npc() || obj->is_pet()) {
     obj->hit_player(50);
  }

  /* do some extra damage */
  if(random(3) == 1) obj->hit_player(10+random(10));

  call_out("kombat", 5);
  return 1;
}

/*
 * This function leaves the player unable to do ANYTHING by cloning an
 * object on them that has add_action("null");
 * The object leaves the player completely helpless for a short time
 */
stun(){
 object ob;
 if(present("concussion_obj", obj)){
    tell_room(ROOM,
    "Dreadnaught rumbles past you, spitting up tiny rocks and a cloud of dust.\n");
 } else {
    tell_room(ROOM,
    "Dreadnaught speeds forward at full speed and SLAMS "+IT+" IN THE HEAD!!!\n"+
    IT+" crumples to the ground.\n");
    tell_object(obj, ">>> You are knocked unconscious!\n");
    ob = clone_object("players/pavlik/ilstkarn/obj/concussion");
    move_object(ob, obj);
    ob->do_conc();
  }
}

monster_died(){

  tell_room(ROOM,
  "The Dreadnaughts broken machinery burts into flames and explodes!\n"+
  "You hear the terrible howl of a banished demon from within the explosion.\n");
  move_object(clone_object("players/pavlik/ilstkarn/treasure/dreadnaught_engine"), ROOM);
  destruct(present("corpse", ROOM));

  write_file("/players/pavlik/ilstkarn/KILL_LOG",
        ctime() + "\t"+query_name()+" killed by "+capitalize(this_player()->query_name())+" ("+ 
        this_player()->query_level()+")\n");

  return 0;
}
