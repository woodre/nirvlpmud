inherit "obj/monster";
#define OWN capitalize(owner)
#define OB find_player(owner)
  string owner, mood;
  int count;
reset(arg){
  ::reset(arg);
  if(arg)
    return;
 set_name("Khirstel");
 set_short("A Khirstel");
 set_long("A Khirstel.\n");
 set_level(1);
 set_hp(75);
 set_wc(16);
 set_ac(10);
 set_al(200);
 set_can_kill(1);
 mood = "grinning";
 owner = "noone";
 enable_commands();
  call_out("follow_owner", 3);
  call_out("mood_shift", 35);
}

id(str){ return str == owner+"'s khirstel" || str == "khirstel" ||
    str == "mage_pet" || str == owner+"'s pet";
}
query_mage_pet(){ return 1; }

short(){
  if(present("mageobj", this_player()))
    return OWN+"'s Khirstel ("+mood+")";
  else
    return "A Khirstel ("+mood+")";
}

long(){
  if(this_player()->query_real_name() == owner)
    write(
    "This is your Khirstel, a magically summoned creature from another\n"+
    "realm. The Khirstel is a small round furry animal. This small\n"+
    "hairball-like creature is known to be very moody.\n"+
    "Kristel Commands are: \n"+
    "  kget <str>     - get an object from your khirstel.\n"+
    "  ktake <str>    - have your khirstel pick something up.\n"+
    "  klook <str>    - have your khirstel take a look <dir>.\n"+
    "  kwhistle       - call your khirstel if it gets lost.\n"+
    "  kdismiss       - dismiss your khirstel.\n"+
    "  kemote         - emote with khirstel.\n"+
    "  kgive <item> to <who> - give item to person.\n"+
    "\n"+
    "Khirstel has "+this_object()->query_hp()+" hps left.\n");
  else
    write(
    OWN+"'s Khirstel. The Khirstel is a small hairball-like creature.\n"+
    "It looks like a round ball of fur. These hairy critters are known\n"+
    "to be very tempermental.\n");
    return;
}

query_owner(){ return owner; }
set_owner(str){ owner = str; }
query_mood(){ return mood; }
set_mood(str){ mood = str; }

init(){
  ::init();
   add_action("klook","klook");
   add_action("kget","kget");
   add_action("kdismiss","kdismiss");
   add_action("ktest","ktest");
   add_action("kkick","kick");
   add_action("kemote","kemote");
   add_action("kgive","kgive");
   add_action("ktake","ktake");
}

do_khirstel(){
  if(!find_player(owner)){
    destruct(this_object());
    return 1;
    }
  if(mood == "grinning"){
    tell_room(environment(this_object()),
    "Khirstel giggles inanely.\n");
    tell_object(find_player(owner),
    "You feel kind of giddy.\n");
  } else if(mood == "snarling"){
    tell_room(environment(this_object()),
    "Khirstel issues a long deep growl.\n"+
    "Khirstel snaps his jaws menacingly.\n");
    khir_attack();
  } else if(mood == "snoring"){
    tell_room(environment(this_object()),
    "Khirstel snores loudly.\n");
  } else if(mood == "smiling"){
    tell_room(environment(this_object()),
    "Khirstel smiles happily.\n");
    tell_object(find_player(owner),
    "You feel a little happier too.\n");
  } else if(mood == "sniffing"){
    tell_room(environment(this_object()),
    "Khirstel sniffs around the room.\n");
  }
  call_out("do_khirstel", 25+random(35));
  return 1;
}

mood_shift(){
  int x;
  if(!find_player(owner)){
    destruct(this_object());
    return 1;
    }
  x = random(6);

  if(x == 1){
    tell_room(environment(this_object()),
    "Khirstel grins.\n");
    mood = "grinning";
  } else if(x == 2){
    tell_room(environment(this_object()),
    "Khirstel snarls dangerously.\n");
    mood = "snarling";
  } else if(x == 3){
    tell_room(environment(this_object()),
    "Khirstel falls asleep.\n");
    mood = "snoring";
  } else if(x == 4){
    tell_room(environment(this_object()),
    "Khirstel smiles.\n");
    mood = "smiling";
  } else if(x == 5){
    tell_room(environment(this_object()),
    "Khirstel sneezes.\n");
    mood = "sniffing";
  }
  if(this_object()->query_attack()){
    tell_room(environment(this_object()),
    "Khirstel suddenly stops fighting.\n");
    if(this_object()->query_attack()->query_attack() == this_object())
      this_object()->query_attack()->stop_fight();
    this_object()->stop_fight();
    this_object()->stop_hunter();
   }
  call_out("mood_shift", 80+random(40));
  return 1;
}

follow_owner(){
  if(!find_player(owner)){
    destruct(this_object());
    return 1;
    }
  if(!present(owner, environment(this_object()))){
    tell_room(environment(this_object()),
    "Khirstel waddles out of the room.\n");
    move_object(this_object(), environment(find_player(owner)));
    tell_room(environment(this_object()),
    "Khirstel waddles into the room following "+OWN+".\n");
    }
  call_out("follow_owner", 3);
  return 1;
}

kemote(str){
  if(this_player()->query_real_name() == owner){
  if(!str){
    write("Khirstel Emote what?\n");
    say("Khirstel pees on "+OWN+"'s foot.\n");
    return 1;
    }
  write("You do a khirstel emote:\n");
  tell_room(environment(this_object()),
  OWN+"'s Khirstel "+str+"\n");
  return 1;
  }
}

kgive(str){
  string who, what;
  object ob, obj;

  if(this_player()->query_real_name() == owner){
  if(!str){
    write("Khirstel gives you a wierd look.\n");
    return 1;
    }
  if(sscanf(str, "%s to %s", what, who)!=2){
    write("Khirstel gives you a wierd look.\n");
    return 1;
    }
  ob = present(what, this_object());
  obj = present(who, environment(this_object()));
  if(!ob || !obj){
    write("Khirstel gives you a wierd look.\n");
    return 1;
    }
  if(!transfer(ob, obj)){
  write("Khirstel gives "+what+" to "+capitalize(who)+".\n");
  tell_object(ob, OWN+"'s khirstel gives you a "+what+".\n");
  say(OWN+"'s khirstel gives something to "+capitalize(who)+".\n");
  return 1;
  } else {
  write("Khirstel cannot give the "+what+" to "+capitalize(who)+".\n");
  return 1;
  }
 }
}

kdismiss(){
  if(this_player()->query_real_name() == owner){
  write("You dismiss your khirstel.\n");
  write("Khirstel gives you a big wet slobberly lick and disappears.\n");
  say("Khirstel disappears.\n");
  destruct(this_object());
  return 1;
  }
}

klook(str){
  object obj;
  if(this_player()->query_real_name() == owner){
  if(!str){
    write("Look where?\n");
    return 1;
    }

  write("You send your khirstel "+str+", to sneak a peek.\n");
  command(str, this_object());
  if(environment(this_object()) == environment(this_player())){
    write("Khirstel gives you a confused look.\n"+
    "Are you sure there's an exit '"+str+"'?\n");
    return 1;
    }
  write("Khirstel sees: \n");
  obj = present("mageobj", this_player());
  move_object(obj, environment(this_player()));
  move_object(this_player(), environment(this_object()));
  command("look", this_player());
  move_object(this_player(), environment(obj));
  move_object(obj, this_player());
  move_object(this_object(), environment(this_player()));
  tell_room(environment(this_object()), "Khirstel arrives.\n");
  return 1;
  }
}

khir_attack(){
  if(OB->query_attack()){
    tell_room(environment(this_object()),
    "Khirstel jumps into the battle!\n");
    this_object()->attack_object(OB->query_attack());
  }
  return 1;
}

kget(str){
  object obj;
  int wt;

  if(this_player()->query_real_name() == owner){
  if(!str){
    write("Khirstel gives you a wierd look.\n");
    return 1;
    }
  if(str == "all"){
    "/players/pavlik/guild/mages/mage-master2.c"->k_getall(this_object());
    return 1;
    }
  obj = present(str, this_object());
  if(!obj){
    write("Khirstel doesn't seem to have a "+str+" ... \n");
    return 1;
    }
  if(!transfer(obj, this_player())){
  write(
  "You bury your arm up to the elbow in hairball and rummage around\n"+
  "for the "+str+".  After a moment or two of searching you take the\n"+
  "item from the khirstel.\n"+
  "You take a "+obj->short()+".\n");
  return 1;
  } else {
  write("Khirstel cannot give you the "+str+".\n");
  return 1;
  }
 }
}

ktake(str){
  if(this_player()->query_real_name() == owner){
  "/players/pavlik/guild/mages/mage-master2.c"->ktake(this_object(), str);
  return 1;
  }
}

kkick(str){
  int x;
  if((str == "khirstel")&&(this_player()->query_real_name()==owner)){
    x = random(100);
    write("You kick Khirstel.\n");
    say(OWN+" kicks Khirstel.\n");
    if(x < 29){
      say("The poor khirstel wimpers and crawls away.\n");
      write("Now don't you feel like a big bully?\n");
      destruct(this_object());
      return 1;
    } else if(x > 69){
      say("The khirstel gets really upset and chews a hole in "+OWN+
          "'s boot!\n");
      mood = "snarling";
      return 1;
    }
  return 1;
  }
}

ktest(str){
  write("mood = "+str+".\n");
  mood = str;
  return 1;
}
