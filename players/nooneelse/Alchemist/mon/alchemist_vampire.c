/*
  alchemist_vampire.c
*/

#include "/players/nooneelse/Alchemist/lib/defs.h"

inherit "obj/monster";

string str, str2, master_name, vampire_name, cheat1, cheat2;
int wait_here, time_counter, vampire_protecting;
object obj, obj2;

init() {
  ::init();

  add_action("vampire_do",   vampire_name);
}

/* general commands to vampire */
vampire_do(str) {
  object obj;

  /* in case the player quits & the vampire is left */
  if (!find_player(master_name)) {
    say(NORM+CYN+"The vampire looks lost and lopes off looking for "+
        capitalize(master_name)+".\n"+NORM);
    destruct(this_object());
    return 1;
  }

  if (!str || str=="") return;

  /* was it my master? */
  if (!this_player()) return;
  if(this_player() != find_player(master_name)) return;

  /* help */
  if (str=="help") {
    short();
    write(NORM+CYN+"Command him with: "+vampire_name+" <command>\n"+
"He can do the following:\n\n"+
"command              description\n"+
"----------------     ------------------------------------------------------\n"+
"help                 display this message\n"+
"say <msg>            a say that you can send through your vampire\n"+
"wait here            tells the vampire to wait here\n"+
"follow me            tells the vampire to stop waiting here & follow you again\n"+
"vampire come to me   calls the vampire from wherever you told it to wait\n"+
"dismissed            send the vampire away\n"+
"attack <monster>     attack a specific monster\n"+
"stop attack          stop the attack\n"+
"protect me           attack any aggressive monster it gets near (toggle)\n"+
"refine corpse        refine a corpse to heal itself\n\n"+NORM);
    return 1;
  }

  /* dismiss vampire */
  if (lower_case(str)=="dismissed") {
    say(NORM+CYN+"The vampire nods at "+capitalize(master_name)+
        " and glides away.\n"+NORM);
    obj=present("Alchemist Pouch", find_player(master_name));
    obj->dismiss_a_vampire();
    destruct(this_object());
    return 1;
  }

  /* vampire say */
  str2=0;
  sscanf(str, "say %s", str2);
  if (str2) {
    cheat1=0;
    cheat2=0;
    sscanf(str, "give%s", cheat1);
    sscanf(str, "hand%s", cheat2);
    if (cheat1 || cheat2) {
      write(NORM+CYN+"You can't use the emote/say command to do that!\n"+NORM);
      return 1;
    }
    say(NORM+CYN+"A vampire named "+capitalize(vampire_name)+" says: "+
        str2+"\n"+NORM);
    return 1;
  }

  /* tell vampire to wait here */
  sscanf(str, "wait %s", str2);
  if (str2=="here") {
    say(NORM+CYN+"The vampire glides into a dark area to stand and wait.\n"+NORM);
    wait_here = 1;
    return 1;
  }

  /* tell vampire to follow me */
  sscanf(str, "follow %s", str2);
  if (str2=="me") {
    say(NORM+CYN+"The vampire glides out of a dark area and stands at "+
        capitalize(master_name)+"'s left side.\n"+NORM);
    wait_here = 0;
    return 1;
  }

  /* was it a kill command? */
  if (sscanf(str, "attack %s", str2)==1 || sscanf(str, "kill %s", str2)==1) {
    obj=present(str2, environment(this_object()));
    if (obj && !obj->query_npc()) {
      write(NORM+CYN+"Sorry, the vampires can't attack players.\n"+NORM);
      return 1;
    }
    if (obj)
      this_object()->attack_object(obj);
    else
      write(NORM+CYN+"The vampire snarls:  "+str2+" is not here to attack!\n"+NORM);
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
      write(NORM+CYN+"The vampire has stopped fighting/hunting.  However, it's old\n"+
            "enemy may not have.\n"+NORM);
      return 1;
    }
  }

  /* tell vampire to refine a corpse & heal itself */
  sscanf(str, "drain %s", str2);
  if (str2=="corpse") {
    obj=present("corpse", environment());
    if (!obj) {
      write(NORM+CYN+"A corpse must be present to do that.\n"+NORM);
      return 1;
    }
    if (this_object()->query_hp() > 100) {
      write(NORM+CYN+"The vampire says:  But I don't need healing right now.\n"+NORM);
      return 1;
    }
    say(NORM+CYN+capitalize(master_name)+
        " mumbles strangely and points at a corpse.\n"+NORM);
    destruct(obj);
    this_object()->heal_self(15);
    say(NORM+CYN+"The vampire excitedly jumps on the corpse and rips through its\n"+
        "flesh to get at a vein.  It then sinks its fangs into the\n"+
        "corpse and greedily laps up it's blood.\n"+NORM);
    return 1;
  }

  /* tell vampire to attack any aggressive monster it comes near */
  if (str=="protect me") {
    if (vampire_protecting) {
      vampire_protecting=0;
      write(NORM+CYN+"The vampire's protection mode is now OFF.\n"+NORM);
    }
    else {
      vampire_protecting=1;
      write(NORM+CYN+"The vampire's protection mode is now ON.\n"+NORM);
    }
    return 1;
  }
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
              NORM+CYN+"The vampire glides away after "+capitalize(master_name)+
              ".\n"+NORM);
    move_object(this_object(), environment(find_player(master_name)));
    tell_room(environment(find_player(master_name)),
              NORM+CYN+"A vampire glides in and stands at "+capitalize(master_name)+
              "'s left side.\n"+NORM);
  }
  call_out("follow", 6);
  return;
}

reset(arg) {
  ::reset(arg);
  if (arg) return;

  set_name("vampire");
  set_alias("vampire");
  vampire_name="vampire";
  set_level(8);
  set_hp(130);
  set_ac(6);
  set_wc(14);
  set_can_kill(1);
  set_aggressive(0);
  set_ep(-66666);
  call_out("follow", 6);
  enable_commands();
  set_heart_beat(1);
}

query_master_name() { return master_name; }

heart_beat() {
  object vampire_obj;

  /* the other guilds seem to be healing their pets faster like this so why not */
  if (hit_point < max_hp) hit_point += 3;
  if (hit_point > max_hp) hit_point = max_hp;

  /* make sure the player only has one vampire */
  vampire_obj=0;
  vampire_obj=present("vampire", environment(this_object()));
  if (vampire_obj && vampire_obj != this_object()) {
    if (vampire_obj->query_master_name()==master_name) {
      destruct(vampire_obj);
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
  /* see if there's any aggressive monsters here */
  if (vampire_protecting) {
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
  when the vampire kills, it can get the experience & give it to its owner
*/
add_exp(arg) {
  if (arg <= 0) return;
  if (find_player(master_name)) find_player(master_name)->add_exp(arg);
}

query_save_flag() { return 1; }

am_i_a_servant() { return 1; }
am_i_a_vampire() { return 1; }

short() {
  if (this_player()->query_real_name()==master_name)
    if (vampire_name)
      return NORM+CYN+capitalize(master_name)+"'s vampire named '"+
             capitalize(vampire_name)+"'"+NORM;
    else
      return NORM+CYN+capitalize(master_name)+"'s vampire"+NORM;
  else
    return NORM+CYN+"A dangerous looking vampire"+NORM;
}

long() {
  if (this_player()->query_real_name()==master_name)
    write(NORM+CYN+short()+".\n"+
          "Type '"+vampire_name+" help' to see how to talk to him.\n"+NORM);
  else
    write(short()+".\n");
    str2="vampire";
    if (vampire_name)
      str2=capitalize(master_name)+"'s vampire named '"+vampire_name+"'";
    else
      str2=capitalize(master_name)+"'s vampire";
    write(NORM+CYN+str2+"\n"+NORM);
  return 1;
}

/* give vampire a new master */
set_master(str) {
  master_name=str;
  return 1;
}

/* give vampire a name */
set_name(str) {
  vampire_name=str;
  name = lower_case(str);
  cap_name = capitalize(str);
  return 1;
}

/* tell vampire to come to me */
summon_vampire() {
  tell_room(environment(this_object()),
            NORM+CYN+
            "The vampire's ears seem to twitch for a second. Then he glides away.\n"+
            NORM);
  wait_here = 0;
  return 1;
}

id(str) { return str=="vampire" ||
                 str=="alchemist vampire" ||
                 str=="guild_monster" ||
                 str=="guild_pet" ||
                 str==master_name+"vampire" ||
                 str==master_name+"_vampire" ||
                 str=="guild_monster" ||
                 str==vampire_name; }

is_pet() { return 1; }
