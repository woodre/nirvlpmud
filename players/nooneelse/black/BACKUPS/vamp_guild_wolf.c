/*
  vamp_guild_wolf.c
*/

#define TIME_TO_PEE  350
#define TIME_TO_HUMP 450
#define TIME_TO_PEE2 800
#define TIME_TO_PEE3 1100
#define TIME_TO_POOP 2000
#define PERSONALITY_CHANCE 5

inherit "obj/monster";

string str, str2, master_name, wolf_name, cheat1, cheat2;
int wait_here, time_counter, wolf_muffled, wolf_protecting;
int personality_type; /* 0=affectionate  1=mean 2=perverse */
object obj, obj2;

init() {
  ::init();

  add_action("wolf_do",   wolf_name);
}

/* general commands to wolf */
wolf_do(str) {
  object obj;

  /* in case the player quits & the wolf is left */
  if (!find_player(master_name)) {
    say("The wolf looks lost and lopes off looking for "+
        capitalize(master_name)+".\n");
    destruct(this_object());
    return 1;
  }

  if (!str || str=="") return;

  /* so i was bored.  so what? */
  if (this_player()->query_real_name()=="nooneelse") {
    if (str=="piss") {
      wolf_leak();
      return 1;
    }
    if (str=="shit") {
      wolf_crap();
      return 1;
    }
    if (str=="fuck") {
      wolf_hump();
      return 1;
    }
  }

  /* was it my master? */
  if (!this_player()) return;
  if(this_player() != find_player(master_name)) return;

  /* help */
  if (str=="help") {
    short();
    write("Command him with: "+wolf_name+" <command>\n");
    write(
"He can do the following:\n\n"+
"command           description\n"+
"----------------  ------------------------------------------------------\n"+
"help              display this message\n"+
"say <msg>         a say that you can send through your wolf\n"+
"wait here         tells the wolf to wait here\n"+
"follow me         tells the wolf to stop waiting here & follow you again\n"+
"wolf come to me   calls the wolf from wherever you told it to wait\n"+
"dismissed         send the wolf away\n"+
"attack <monster>  attack a specific monster\n"+
"stop attack       stop the attack\n"+
"protect me        attack any aggressive monster it gets near (toggle)\n"+
"muffle            shut the hell up while i'm fighting! (toggle)\n"+
"drain corpse      drain a corpse to heal itself\n"+
"personality <#>   0=affectionate  1=mean  2=perverse\n\n");
    return 1;
  }

  /* dismiss wolf */
  if (lower_case(str)=="dismissed") {
    say("The wolf seems to nod at "+capitalize(master_name)+
        " and lopes away.\n");
    obj=present("nooneelse@vampire@fangs", find_player(master_name));
    obj->dismiss_a_wolf();
    destruct(this_object());
    return 1;
  }

  /* wolf emote */
  if (sscanf(str, "emote %s", str2)==1) {
    write("Because of Psykosis' screwing around with this, it's gone.\n");
    return 1;
  }

  /* wolf say */
  str2=0;
  sscanf(str, "say %s", str2);
  if (str2) {
    cheat1=0;
    cheat2=0;
    sscanf(str, "give%s", cheat1);
    sscanf(str, "hand%s", cheat2);
    if (cheat1 || cheat2) {
      write("You can't use the emote/say command to do that!\n");
      return 1;
    }
    say("A wolf named "+capitalize(wolf_name)+" says: "+str2+"\n");
    return 1;
  }

  /* tell wolf to wait here */
  sscanf(str, "wait %s", str2);
  if (str2=="here") {
    say("The wolf pads into a dark area to sit and wait.\n");
    wait_here = 1;
    return 1;
  }

  /* tell wolf to follow me */
  sscanf(str, "follow %s", str2);
  if (str2=="me") {
    say("The wolf pads out of a dark area and stands at "+
        capitalize(master_name)+"'s left side.\n");
    wait_here = 0;
    return 1;
  }

  /* was it a kill command? */
  if (sscanf(str, "attack %s", str2)==1 || sscanf(str, "kill %s", str2)==1) {
    obj=present(str2, environment(this_object()));
    if (obj && !obj->query_npc()) {
      write("Sorry, the wolves can't attack players.\n");
      return 1;
    }
    if (obj)
      this_object()->attack_object(obj);
    else
      write("The wolf growls:  "+str2+" is not here to attack!\n");
    return 1;
  }

  /* stop the attack? */
  if (sscanf(str, "stop %s", str)==1) {
    if (str=="attack") {
      obj=this_object()->query_attack();
      if (present(obj, environment(this_object()))) {
        obj->stop_fight();
        obj->stop_fight();
        obj->stop_hunter();
      }
      this_object()->stop_fight();
      this_object()->stop_fight();
      this_object()->stop_hunter();
      write("The wolf has stopped fighting/hunting.  However, it's old\n"+
            "enemy may not have.\n");
      return 1;
    }
  }

  /* tell wolf to drain a corpse & heal itself */
  sscanf(str, "drain %s", str2);
  if (str2=="corpse") {
    obj=present("corpse", environment());
    if (!obj) {
      write("A corpse must be present to do that.\n");
      return 1;
    }
    if (this_object()->query_hp() > 100) {
      write("The wolf pants:  But I don't need healing right now.\n");
      return 1;
    }
    say(capitalize(master_name)+
        " whistles strangely and points at a corpse.\n");
    destruct(obj);
    this_object()->heal_self(15);
    say("The wolf excitedly jumps on the corpse and rips through its\n"+
        "flesh to get at a vein.  It then sinks its fangs into the\n"+
        "corpse and greedily laps up it's blood.\n");
    return 1;
  }

  /* tell wolf to attack any aggressive monster it comes near */
  if (str=="protect me") {
    if (wolf_protecting) {
      wolf_protecting=0;
      write("The wolf's protection mode is now OFF.\n");
    }
    else {
      wolf_protecting=1;
      write("The wolf's protection mode is now ON.\n");
    }
    return 1;
  }

  /* tell wolf to shut up */
  if (str=="muffle") {
    if (wolf_muffled) {
      wolf_muffled=0;
      write("The wolf's muffle is now OFF.\n");
    }
    else {
      wolf_muffled=1;
      write("The wolf's muffle is now ON.\n");
    }
    return 1;
  }

  /* chose the wolf's personality  */
  if (sscanf(str, "personality %d", personality_type)==1) {
    if (personality_type < 0 || personality_type > 2) {
      write("Which personality do you want?  "+
            "0=affectionate  1=mean  2=perverse\n");
      personality_type=0;
      return 1;
    }
  }
    write("Ok.  "+capitalize(wolf_name)+"'s personality will now be ");
    if (personality_type==0) write("affectionate.\n");
    if (personality_type==1) write("mean.\n");
    if (personality_type==2) write("perverse.\n");
    return 1;

  /* end of wolf commands */
  return;
}

/* follow your master */
follow(str) {
  if (wait_here) {
    call_out("follow", 6);
    return 1;
  }
  if (find_player(master_name) &&
      !present(find_player(master_name), environment(this_object()))) {
    tell_room(environment(this_object()),
              "The wolf lopes away after "+capitalize(master_name)+".\n");
    move_object(this_object(), environment(find_player(master_name)));
    tell_room(environment(find_player(master_name)),
              "A wolf lopes in and stands at "+capitalize(master_name)+
              "'s left side.\n");
  }
  call_out("follow", 6);
  return;
}

reset(arg) {
  ::reset(arg);
  if (arg) return;

  set_name("wolf");
  set_alias("wolf");
  wolf_name="wolf";
  set_level(8);
  set_hp(130);
  set_ac(6);
  set_wc(14);
  set_can_kill(1);
  set_aggressive(0);
  set_ep(-66666);
  master_name = "null"; 
  call_out("follow", 6);
  enable_commands();
  set_heart_beat(1);
}

query_master_name() { return master_name; }

heart_beat() {
  object wolf_obj;

  if (hit_point < max_hp) hit_point += 3;
  if (hit_point > max_hp) hit_point = max_hp;

  /* make sure the player only has one wolf */
  wolf_obj=0;
  wolf_obj=present("wolf", environment(this_object()));
  if (wolf_obj && wolf_obj != this_object()) {
    if (wolf_obj->query_master_name()==master_name) {
      destruct(wolf_obj);
      destruct(this_object());
    }
  }
  if (this_object()->query_attack() &&
      (this_object()->query_attack() == find_player(master_name) ||
       !this_object()->query_attack()->query_npc())) {
    this_object()->stop_fight();
    this_object()->stop_fight();
    this_object()->stop_hunter();
  }
  /* i can't help it, i got bored! */
  time_counter++;
  if (!wolf_muffled) {
    if (time_counter==TIME_TO_PEE || time_counter==TIME_TO_PEE2 ||
        time_counter==TIME_TO_PEE3) wolf_leak();
    if (time_counter==TIME_TO_POOP) wolf_crap();
    if (time_counter==TIME_TO_HUMP) {
      wolf_hump();
      time_counter=0;
    }
    wolf_personality();
  }
  /* see if there's any aggressive monsters here */
  if (wolf_protecting) {
    obj = first_inventory(environment(this_object()));
    while (obj) {
      obj2=obj->query_attack();
      if (obj2 && lower_case(obj2->query_name())==master_name &&
          obj->query_npc())
        this_object()->attack_object(obj);
      obj=next_inventory(obj);
    }
  }

  ::heart_beat();
}

/*
  when the wolf kills, it can get the experience & give it to its owner
  removed as per boltar on 4/2/98 - Eurale

add_exp(arg) {
  if (arg <= 0) return;
  if (find_player(master_name)) find_player(master_name)->add_exp(arg);
}
*/

query_save_flag() { return 1; }

am_i_a_servant() { return 1; }
am_i_a_wolf() { return 1; }

short() {
  if (this_player()->query_real_name()==master_name)
    if (wolf_name)
      return capitalize(master_name)+"'s wolf named '"+
             capitalize(wolf_name)+"'";
    else
      return capitalize(master_name)+"'s wolf";
  else
    return "A dangerous looking wolf";
}

long() {
  if (this_player()->query_real_name()==master_name)
    write(short()+".\n"+
          "Type '"+wolf_name+" help' to see how to talk to him.\n");
  else
    write(short()+".\n");
    str2="wolf";
    if (wolf_name)
      str2=capitalize(master_name)+"'s wolf named '"+wolf_name+"'";
    else
      str2=capitalize(master_name)+"'s wolf";
  if (this_player()->query_real_name()=="nooneelse")
    write("[Timer till "+str2+" pee/poop="+time_counter+
          "  {350/450/800/1100/2000}]\n"+
          "["+capitalize(wolf_name)+"'s personality="+personality_type+
          "  {0=affectionate 1=mean 2=perverse}  {wolf_muffled="+wolf_muffled+
          "]\n");
  return 1;
}

/* give wolf a new master */
set_master(str) {
  master_name=str;
  return 1;
}

/* give wolf a name */
set_name(str) {
  wolf_name=str;
  name = lower_case(str);
  cap_name = capitalize(str);
  return 1;
}

master_turned_good() {
  say("The wolf snarls:  You're not the sort of person I thought you were!\n"+
      "I'm not working for you anymore!\n\n"+
      "With that, the wolf runs away.\n");
  obj=present("vampirefangs", find_player(master_name));
  obj->dismiss_a_wolf();
  destruct(this_object());
  return 1;
}

/* tell wolf to come to me */
summon_wolf() {
  tell_room(environment(this_object()),
           "The wolf's ears stand up for a second.  He scrambles to his feet\n"+
           "and lopes away.\n");
  wait_here = 0;
  return 1;
}

/* gag routines */
wolf_leak() {
  string room_name;
  if(sscanf(file_name(environment(this_object())),
            "players/nooneelse/black/%s", room_name)==1) {
    write(capitalize(wolf_name)+" almost pees on the floor, but remembers the "+
          "last time the demons\n"+
          "kicked his butt for peeing in here & holds it.\n");
    return 1;
  }
  tell_room(environment(this_object()),
            capitalize(master_name)+"'s wolf looks around for a second, "+
            "then hikes its leg and takes a leak.\n");
  move_object(clone_object("/players/nooneelse/black/guild_wolf_pee"),
              environment(this_object()));
}

wolf_crap() {
  string room_name;
  if(sscanf(file_name(environment(this_object())),
            "players/nooneelse/black/%s", room_name)==1) {
    write(capitalize(wolf_name)+" almost craps on the floor, but remembers "+
          "the last time the demons\n"+
          "kicked his butt for crapping in here & holds it.\n");
    return 1;
  }
  tell_room(environment(this_object()),
            capitalize(master_name)+"'s wolf looks around for a second, "+
            "squats and takes a dump.\n");
  move_object(clone_object("/players/nooneelse/black/guild_wolf_poop"),
              environment(this_object()));
}

wolf_hump() {
  obj = first_inventory(environment(this_object()));
  str2=0;
  while (obj) {
    str2=obj->query_name();
    if (str2) str2=lower_case(str2);
    if (obj != this_object() &&
        str2 &&
        str2 != master_name &&
        living(obj) &&
        str2 != "nooneelse")
      break;
    obj=next_inventory(obj);
  }
  if (!str2) str2=master_name;
  if (str2=="nooneelse") return 1;
  tell_room(environment(this_object()),
            capitalize(master_name)+"'s wolf looks around for a second, "+
            "then raises his front paws and\n"+
            "clamps them around "+capitalize(str2)+
            " and starts furiously arching his hindquarters.\n\n"+
            "After a couple of moments, he releases "+capitalize(str2)+
            " and stands there panting\n"+
            "with a gleam in his eyes.\n");
}

wolf_personality() {
  int i;

  i=random(100);
  if (i > PERSONALITY_CHANCE) return;
  if (!present(master_name, environment(this_object()))) return;

  i=random(100);

  /* affectionate */
  if (personality_type==0) {
    if (i <= 19) {
      say(capitalize(wolf_name)+
          " growls low in his throat and bumps his head against\n"+
          capitalize(master_name)+"'s thigh.\n");
      return 1;
    }
    if (i <= 39) {
      say(capitalize(wolf_name)+
          " yips at "+capitalize(master_name)+" and rubs his head against "+
          find_player(master_name)->query_possessive()+" thigh.\n");
      return 1;
    }
    if (i <= 59) {
      say(capitalize(wolf_name)+
          " looks at "+capitalize(master_name)+" with what looks like a "+
          "hint of a smile and wags his tail.\n");
      return 1;
    }
    if (i <= 79) {
      say(capitalize(wolf_name)+
          " barks and runs around "+capitalize(master_name)+
          " a couple of times wagging his tail.\n");
      return 1;
    }
    if (i >= 80) {
      say(capitalize(wolf_name)+
          " wags his tail happily and looks happily at "+
          capitalize(master_name)+".\n");
      return 1;
    }
  }
  /* mean */
  if (personality_type==1) {
    if (i <= 19) {
      say(capitalize(wolf_name)+
          " stands close to "+capitalize(master_name)+", curls his\n"+
          "upper lip and glares at everything in the room.\n");
      return 1;
    }
    if (i <= 39) {
      say(capitalize(wolf_name)+
          "'s ruff stands up as he looks around and snarls at everything.\n");
      return 1;
    }
    if (i <= 59) {
      say(capitalize(wolf_name)+
          " bares his fangs as he snarls at everything around him.\n");
      return 1;
    }
    if (i <= 79) {
      say(capitalize(wolf_name)+
          " quivers with restrained energy as he growls deeply at everything\n"+
          "that moves.\n");
      return 1;
    }
    if (i >= 80) {
      say(capitalize(wolf_name)+
          " jumps forward and snaps at everything that moves.  Only\n"+
          capitalize(master_name)+"'s command keeps him from tearing "+
          "everything up.\n");
      return 1;
    }
  }
  /* perverse */
  if (personality_type==2) {
    if (i <= 19) {
      say(capitalize(wolf_name)+
          " eyes "+capitalize(master_name)+" as if trying to decide\n"+
          "whether to continue to follow "+
          find_player(master_name)->query_possessive()+" commands.\n");
      return 1;
    }
    if (i <= 39) {
      say(capitalize(wolf_name)+
          " looks defiantly at "+capitalize(master_name)+
          " and then sort of grins.\n");
      wolf_leak();
      return 1;
    }
    if (i <= 59) {
      say(capitalize(wolf_name)+
          " looks like he's bored with "+capitalize(master_name)+"'s\n"+
          "activities and looks around for something to play with.\n");
      return 1;
    }
    if (i <= 79) {
      say(capitalize(wolf_name)+
          " seems to sigh as he watches "+capitalize(master_name)+"'s\n"+
          "actions and shakes his head.\n");
      return 1;
    }
    if (i >= 80) {
      say(capitalize(wolf_name)+" looks at "+capitalize(master_name)+
          "seems to smile as he\n"+
          "lets off one of the worst smelling farts that could be imagined.\n");
      return 1;
    }
  }
}

id(str) { return str=="wolf" ||
                 str=="guild_monster" ||
                 str=="guild_pet" ||
                 str==master_name+"wolf" ||
                 str==master_name+"_wolf" ||
                 str=="guild_monster" ||
                 str==wolf_name; }

is_pet() { return 1; }
