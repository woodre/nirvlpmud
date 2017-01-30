/*
  magic_shop_elemental.c - configurable to be either an elemental or a golem
*/

inherit "obj/monster";

string str, str2, master_name, elemental_type, elemental_name;
int elemental_scroll, wait_here, time_counter;
object obj;

init() {
  ::init();

  add_action("elemental_do",   elemental_name);
}

/* general commands to elemental */
elemental_do(str) {
  object obj;

  /* in case the player quits & the elemental is left */
  if (!find_player(master_name)) {
    say("The elemental looks lost and teleports back to its plane.\n");
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
    write("Command him with: "+elemental_name+" <command>\n");
    write(
"He can do the following:\n\n"+
"command           description\n"+
"----------------  ------------------------------------------------------\n"+
"help              display this message\n"+
"wait here         tells the elemental to wait here\n"+
"follow me         tells the elemental to stop waiting here & "+
"follow you again\n"+
"come to me        calls the elemental from wherever you told it to wait\n"+
"dismissed         send the elemental away\n"+
"attack <monster>  attack a specific monster\n"+
"stop attack       stop the attack\n");
    return 1;
  }

  /* dismiss elemental */
  if (lower_case(str)=="dismissed") {
    say("The elemental seems to nod at "+capitalize(master_name)+
        " and teleports back to it's plane.\n");
    destruct(this_object());
    return 1;
  }

  /* tell elemental to wait here */
  sscanf(str, "wait %s", str2);
  if (str2=="here") {
    say("The elemental moves into a dark area to wait.\n");
    wait_here = 1;
    return 1;
  }

  /* tell elemental to follow me */
  sscanf(str, "follow %s", str2);
  if (str2=="me") {
    say("The elemental moves to stand at "+capitalize(master_name)+
        "'s left side.\n");
    wait_here = 0;
    return 1;
  }

  /* was it a kill command? */
  if (sscanf(str, "attack %s", str2)==1 || sscanf(str, "kill %s", str2)==1) {
    obj=present(str2, environment(this_object()));
    if (obj && !obj->query_npc()) {
      write("Sorry, the elementals can't attack players.\n");
      return 1;
    }
    if (obj)
    obj=present(str2, environment(this_object()));
    if (obj && !obj->query_npc()) {
      write("Sorry, the elementals can't attack players.\n");
      return 1;
    }
    if (obj)
      this_object()->attack_object(obj);
    else
      write("The elemental growls:  "+str2+" is not here to attack!\n");
    return 1;
  }

  /* stop the attack? */
  if (sscanf(str, "stop %s", str)==1) {
    if (str=="attack") {
      obj=this_object()->attacked_by();
      obj->stop_fight();
      obj->stop_fight();
      obj->stop_hunter();
      this_object()->stop_fight();
      this_object()->stop_fight();
      this_object()->stop_hunter();
      return 1;
    }
  }

  /* end of elemental commands */
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
              "The elemental moves away after "+capitalize(master_name)+".\n");
    move_object(this_object(), environment(find_player(master_name)));
    tell_room(environment(find_player(master_name)),
              "A elemental moves in and stands at "+capitalize(master_name)+
              "'s left side.\n");
  }
  call_out("follow", 6);
  return;
}

reset(arg) {
  ::reset(arg);
  if (arg) return;

  set_name("elemental");
  set_alias("elemental");
  elemental_name="elemental";
  set_level(10);
  set_hp(200);
  set_ac(10);
  set_wc(20);
  set_can_kill(1);
  set_aggressive(0);
  call_out("follow", 6);
  enable_commands();
}

heart_beat() {
  if (this_object()->query_attack() == find_player(master_name)) {
    this_object()->stop_fight();
    this_object()->stop_fight();
    this_object()->stop_hunter();
  }

  ::heart_beat();
}

/*
  when the elemental kills, it can get the experience & give it to its owner
*/
add_exp(arg) {
  if (arg <= 0) return;
  if (find_player(master_name)) find_player(master_name)->add_exp(arg);
  tell_room(environment(this_object()),
            "The elemental teleports back to it's plane after "+
            "completing it's task.\n");
  destruct(this_object());
  return 1;
}

query_save_flag() { return 1; }

am_i_a_servant() { return 1; }

short() {
  if (this_player()->query_real_name()==master_name)
    if (elemental_name)
      return capitalize(master_name)+"'s elemental named '"+
             capitalize(elemental_name)+"'";
    else
      return capitalize(master_name)+"'s elemental";
  else
    return "A dangerous looking elemental";
}

long() {
  if (this_player()->query_real_name()==master_name)
    write(short()+".\n"+
          "Type '"+elemental_name+" help' to see how to talk to him.\n");
  else
    write(short()+".\n");
  str2="elemental";
  if (elemental_name)
    str2=capitalize(master_name)+"'s elemental named '"+elemental_name+"'";
  else
    str2=capitalize(master_name)+"'s elemental";
  return 1;
}

/* give elemental a new master */
set_elemental_master(str) {
  master_name=str;
  return 1;
}

/* set creature type */
set_creature_type(arg) {
  elemental_scroll=arg;
  return 1;
}

/* specify the elemental type */
set_elemental_type(str) {
  if (str != "fire" && str != "water" && str != "earth" && str != "air") return;
  elemental_type=str;
  return 1;
}

/* give elemental a name */
set_elemental_name(str) {
  elemental_name=str;
  name = lower_case(str);
  cap_name = capitalize(str);
  return 1;
}

/* tell elemental to come to me */
summon_elemental() {
  tell_room(environment(this_object()),
           "The elemental moves away.\n");
  wait_here = 0;
  return 1;
}

id(str) { return str=="elemental" ||
                 str=="guild_monster" ||
                 str==master_name+"elemental" ||
                 str==master_name+"_elemental" ||
                 str=="guild_monster" ||
                 str==elemental_name; }
