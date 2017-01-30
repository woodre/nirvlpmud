inherit "obj/monster";
#define IT capitalize(this_object()->query_attack()->query_name())
#define ME capitalize(this_player()->query_name())
#define ROOM environment(this_object())

object obj;

reset(arg){
 ::reset(arg);
 if(arg) return;
 set_name("Kreeg");
 set_alias("kreeg");
 set_race("giant");
 set_gender("male");
 set_short("Kreeg the Storm Giant");
 set_long(
 "A towering attitude of thunder and lighting, Kreeg shines brilliantly under\n"+
 "the aura of his deadly lightning bolts.  The giants Storm Armor crackles\n"+
 "with electricity as does his malicious grin.  You hope he isn't hungry.\n");
 set_level(25);
 set_al(-1000);
 set_wc_bonus(4);
 set_ac_bonus(8);
 set_hp(750);
 set_wc(40);
 set_aggressive(0);
 set_dead_ob(this_object());
 set_a_chat_chance(20);
 load_a_chat("Kreeg grabs a lightning bolt from the sky and hurls it at you!\n");
 load_a_chat("Kreeg's evil laughter echoes all around you.\n");
 load_a_chat("Kreeg bellows: Thou are no match for me!\n");
 move_object(clone_object("players/pavlik/ilstkarn/armor/storm_shield"), this_object());
 move_object(clone_object("players/pavlik/ilstkarn/armor/storm_cloak"), this_object());
 init_command("wear shield");
 init_command("wear cloak");
 set_ac(25);
 call_out("kombat", 3);
}

init() {
  ::init();
  add_action("drop_head","drop");
  if(this_player()->is_player() && !query_attack()) 
    call_out("growl", 5, this_player());
}

growl(ob) {
  if(!present(ob, environment(this_object()))) {
    return 1;
  }

  if(ob->query_alignment() < 0) {
   if(present("ranger_head", ob)) {
    tell_object(ob, "Kreeg booms: Drop the ranger's head in the dirt.\n");
    tell_object(ob, "Kreeg's evil laughter echoes all around you.\n");
    }
   else {
    tell_object(ob, "Kreeg booms: Why do you disturb me mortal one?\n");
    tell_object(ob, "Kreeg booms: Bring me the Ranger's head and perhaps I'll let you live.\n");
   }
  }
  else {
    tell_object(ob, "Kreeg bellows: Aha!  The tasty meat of the benevolent!\n");
    tell_object(ob, "Kreeg bellows: Bring thyself here to be my dinner!\n");
    tell_object(ob, "Kreeg's evil laughter echoes all around you.\n");
  }
  return 1;
}

drop_head(str) {
  if(str == "head" || str == "ranger head") {
    if(present("ranger_head", this_player())) {
      write("You drop the ranger's head in the dirt.\n");
      say(ME+" drops the ranger's head in the dirt.\n");
      return 1;
    }
  }
}

kombat(){
  int ranx;

  if(!this_object()->query_attack()){
    call_out("kombat", 15);
    return 1;
  }

  obj = this_object()->query_attack();
  ranx = random(10);

  if(!present(obj, environment(this_object()))){
    call_out("kombat", 10);
    return 1;
  }

  /* random battle message */
  if(ranx == 0) tell_room(ROOM,
  "Kreeg bellows his mighty war cry!\n"+
  "You cover your ears in pain against his thunderous voice!\n");
  else if(ranx == 1) tell_room(ROOM,
  "Kreeg stomps "+IT+" under his huge foot!\n");
  else if(ranx == 3) tell_room(ROOM,
  "Kreeg casts a mighty bolt of lightning against "+IT+".\n"+
  "The bolt blasts a huge crater into the earth, knocking you to the ground!\n");
  else if(ranx == 5) tell_room(ROOM,
  "Kreeg the Storm Giant picks "+IT+" up and tosses him around like a toy.\n");
  else if(ranx == 6) stun();
  else if(ranx == 7) tell_room(ROOM,
  "Kreeg blasts "+IT+" in the chest with a powerful bolt of lightning!\n"+
  IT+"'s body spasms wildly with shock!\n");
  else if(ranx == 9) tell_room(ROOM,
  "Kreeg pelts "+IT+" with a torrent of hail!\n");

  /* i really don't like pets */  
  if(obj->query_npc() || obj->is_pet()) {
    if(random(19) == random(9)) {
     tell_room(ROOM,
     "Kreeg lifts "+IT+" into the air and hurls it into the Chasm!!!\n"+
     IT+" plunges to its death!\n");
     move_object(obj, "room/void");
     destruct(obj);
     call_out("kombat", 10);
     return 1;
    }
    else {
     obj->hit_player(15); obj->hit_player(10, "other|electric");
    }
   }

  /* do some extra damage */
  if(random(3) == 1) obj->hit_player(10+random(30));
  else obj->hit_player(random(10));

  call_out("kombat", 10);
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
    "Kreeg beats "+IT+"'s unconscious body mercilessly!\n");
 } else {
    tell_room(ROOM,
    "Kreeg claps his hands and a BOOMING thunder rolls across the land!\n"+
    "You are knocked to the ground by the concussive blast!\n"+
    IT+" is knocked unconscious by the blast!!!\n");
    ob = clone_object("players/pavlik/ilstkarn/obj/concussion");
    move_object(ob, obj);
    ob->do_conc();
  }
}

/*
 * Non of this heal_self crap
 */
heal_self(i) {
  if(i <=0) {
    return;
  }
  else {
    ::heal_self(i);
  }
  return;
}

/*
 * No modifying stats either!
 */
set_ac(x) {
  if(this_player() != this_object()) { return; }
  ::set_ac(x);
  return 1;
}

set_wc(x) {
  if(this_player() != this_object()) { return; }
  ::set_wc(x);
}

set_heal_rate(x,y) {
  if(this_player() != this_object()) { return; }
  ::set_heal_rate(x,y);
}

monster_died(){
  object ob;
  string tmp;
  int i;

  tell_room(environment(this_object()),
  "A blazing storm of lightning erupts from the Storm Giant's corpse!\n"+
  "A powerful surge of electricity shocks you!\n");

  ob = all_inventory(environment(this_object()));
  for(i=0; i<sizeof(ob); i++) {
    if(living(ob[i])) {
      tmp = ob[i]->query_guild_name();
        ob[i]->hit_player(10+random(20), "other|electric");
    }
  }

  write_file("/players/pavlik/ilstkarn/KILL_LOG",
        ctime() + "\t"+query_name()+" killed by "+capitalize(this_player()->query_name())+" ("+ 
        this_player()->query_level()+")\n");

  return 0;
}
