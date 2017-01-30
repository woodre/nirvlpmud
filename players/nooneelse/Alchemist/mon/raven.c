/*
  raven.c - OF COURSE it looks like the vamp's servant! I made both ;)
*/

#include "/players/nooneelse/Alchemist/lib/defs.h"

inherit "obj/monster";

object obj, from_obj;
string str, master_name, raven_name;
int wait_here, wait_counter;


init() {
  ::init();

  add_action("raven_do",  raven_name);
  add_action("fix_raven", "fix");
}

/* general commands to raven */
raven_do(str) {
  object item_obj, destination_obj, container_obj, environment_of_obj;
  object obj2, next_obj2;
  string item_str, container_str, destination_str;
  int weight, dont_take_this, dont_give_this;

  if (!find_player(master_name)) {
    say(NORM+CYN+capitalize(raven_name)+" asks: where is my master?\n"+
        capitalize(master_name)+" needs to fix me.\n"+NORM);
    return 1;
  }

  if (!str || str=="") return;
  if (!this_player()) return;


  /* was it my master? */
  if(this_player() != find_player(master_name)) return;

  /* dismiss raven */
  if (lower_case(str)=="dismissed") {
    say(NORM+CYN+capitalize(raven_name)+" nods glumly at "+
        capitalize(master_name)+".\n"+NORM);
    obj=present("Alchemist Pouch", find_player(master_name));
    obj->dismiss_a_raven();
    destruct(this_object());
    return 1;
  }

/* tell raven to wait here */
  if (lower_case(str)=="wait here") {
    say(NORM+CYN+capitalize(raven_name)+" nods at "+capitalize(master_name)+".\n"+NORM);
    say(NORM+CYN+capitalize(raven_name)+" says: I'll wait here for 5 minutes.\n"+NORM);
    wait_here = 1;
    wait_counter = 0;
    return 1;
  }

/* tell raven to follow me */
  if (lower_case(str)=="follow me") {
    say(NORM+CYN+capitalize(raven_name)+" nods at "+capitalize(master_name)+".\n"+NORM);
    wait_here = 0;
    return 1;
  }

/* help */
  if (str=="help") {
    short();
    write(NORM+CYN+"Command him with: "+raven_name+" <command>\n"+
"Your raven can do the following:\n\n"+
"wait here         tells the raven to wait here\n"+
"                  (he'll wait 5 mintues, then quit)\n"+
"follow me         tells the raven to stop waiting here & follow you again\n"+
"dismissed         destroy the raven\n"+
"help              display this message\n"+
"fix raven         fix your raven (if he won't listen anymore)\n\n"+
"He can also do a lot of player-type commands like: "+raven_name+
" get torch\n\n"+NORM);
    return 1;
  }

  /* get something */
  if (sscanf(str, "get %s", str)==1 || sscanf(str, "take %s", str)==1) {
    if (str=="all") {
      get_all(environment(this_object()));
      return 1;
    }
    if (sscanf(str, "%s from %s", item_str, container_str) != 2) {
      pick_item(str);
      return 1;
    }
    container_obj = present(lower_case(container_str));
    if (!container_obj) {
      write(NORM+CYN+capitalize(raven_name)+" says: There is no "+container_str+
            " here.\n"+NORM);
      return 1;
    }
    if (!call_other(container_obj, "can_put_and_get", 0)) {
      write(NORM+CYN+capitalize(raven_name)+" says: I can't do that!\n"+NORM);
      return 1;
    }
    if (item_str=="all") {
      get_all(container_obj);
      return 1;
    }
    item_obj = present(item_str, container_obj);
    if (!item_obj){
      write(NORM+CYN+capitalize(raven_name)+" says: There is no "+item_str+" in the "+
            container_str+".\n"+NORM);
      return 1;
    }
    if (!call_other(item_obj, "get", item_str) ||
        call_other(container_obj, "forbid_item_leave", item_obj) ||
        call_other(item_obj, "forbid_leave_container", container_obj)) {
      write(NORM+CYN+capitalize(raven_name)+" says: I can't take "+item_str+" from "+
            container_str+".\n"+NORM);
      return 1;
    }
    weight = call_other(item_obj, "query_weight", 0);
    if (!add_weight(weight)) {
      write(NORM+CYN+capitalize(raven_name)+" says: I cannot carry more.\n"+NORM);
      return 1;
    }
    /* no handling money */
    if (item_obj->id("money") || item_obj->id("coins")) {
      write(NORM+CYN+capitalize(raven_name)+" says: I cannot carry money.\n"+NORM);
      return 1;
    }
    /* no getting items with living things in it */
    dont_take_this=0;
    obj2 = first_inventory(item_obj);
    while(obj2) {
      if (obj2->living()) dont_take_this=1;
      obj2 = next_inventory(obj2);
    }
    if (dont_take_this) {
      say(capitalize(raven_name)+" says:\n"+
          "   I don't like "+item_str+" and I won't take it!\n");
      return 1;
    }
    call_other(container_obj, "add_weight", -weight);
    move_object(item_obj, this_object());
    call_other(container_obj, "notify_item_leave", item_obj);
    call_other(item_obj, "notify_leave_container", container_obj);
    say(NORM+CYN+capitalize(raven_name)+" takes "+item_str+" from "+
        container_str+".\n"+NORM);
    return 1;
  }

  /* drop something */
  if (sscanf(str, "drop %s", str)==1) {
    if (str=="all") {
      drop_all();
      return 1;
    }
    else {
      obj=present(str, this_object());
      drop_one_item(obj);
      return 1;
    }
  }

  /* no handling money */
  if (lower_case(str)=="give me money") {
    say(NORM+CYN+capitalize(raven_name)+" says: I cannot carry money.\n"+NORM);
    return 1;
  }

  /* give something to someone */
  if (sscanf(str, "give %s to %s", item_str, destination_str)==2) {
    if (item_str=="all") {
      destination_obj = present(destination_str, environment(this_object()));
      if (!destination_obj) {
        write(NORM+CYN+capitalize(raven_name)+" says: There is no "+
              capitalize(destination_str)+" here.\n"+NORM);
        return 1;
      }
      if (!living(destination_obj)) {
        write(NORM+CYN+capitalize(raven_name)+" says: I can't do that.\n"+NORM);
        return 1;
      }
      give_all_stuff(destination_str);
    }
    if (item_str) {
      item_str = lower_case(item_str);
      item_obj = present(item_str, this_object());
      /* no handling money */
      if (item_obj->id("money") || item_obj->id("coins")) {
        write(NORM+CYN+capitalize(raven_name)+" says: I cannot carry money.\n"+NORM);
        return 1;
      }
      if (!item_obj) {
        write(NORM+CYN+capitalize(raven_name)+" says: I have no "+item_str+".\n"+NORM);
        return 1;
      }
      if (environment(item_obj)==this_object() &&
          call_other(item_obj, "drop", 0)==1) {
        return 1;
      }
      else {
        if (!call_other(item_obj, "get")) {
          write(NORM+CYN+capitalize(raven_name)+" says: I can't do that.\n"+NORM);
          return 1;
        }
      }
    }
    destination_obj = present(destination_str, environment(this_object()));
    if (!destination_obj) {
      write(NORM+CYN+capitalize(raven_name)+" says: There is no "+
            capitalize(destination_str)+" here.\n"+NORM);
      return 1;
    }
    if (!living(destination_obj)) {
      write(NORM+CYN+capitalize(raven_name)+" says: I can't do that.\n"+NORM);
      return 1;
    }
    weight = call_other(item_obj, "query_weight", 0);
    if (!call_other(destination_obj, "add_weight", weight)) {
      write(NORM+CYN+capitalize(raven_name)+" says: "+capitalize(destination_str)+
            " can't carry any more.\n"+NORM);
      return 1;
    }
    /* no giving items with living things in it */
    dont_give_this=0;
    obj2 = first_inventory(item_obj);
    while(obj2) {
      if (obj2->living()) dont_give_this=1;
      obj2 = next_inventory(obj2);
    }
    if (dont_give_this) {
      say(NORM+CYN+capitalize(raven_name)+" says:\n"+
          "   I don't like "+item_str+" and I won't keep it!\n"+NORM);
      drop_one_item(item_obj);
      return 1;
    }
      add_weight(-weight);
      move_object(item_obj, destination_obj);
      say(NORM+CYN+capitalize(raven_name)+" gives "+item_str+" to "+
          capitalize(destination_str)+".\n"+NORM);
      return 1;
  }

  /* check for the direction commands & fix em so he can understand */
  switch (str) {
    case "n": str="north"; break;
    case "ne": str="northeast"; break;
    case "e": str="east"; break;
    case "se": str="southeast"; break;
    case "s": str="south"; break;
    case "sw": str="southwest"; break;
    case "w": str="west"; break;
    case "nw": str="northwest"; break;
    case "u": str="up"; break;
    case "d": str="down"; break;
  }

  /* was it a kill command? */
  if (sscanf(str, "kill %s", str)==1) {
    write(NORM+CYN+"Your raven regretfully says: I'm sorry, I cannot fight.\n"+NORM);
    return 1;
  }

  /* no selling (& some other things) for ravens */
  if (extract(str,0,3)=="sell" ||
      extract(str,0,4)=="place" ||
      extract(str,0,7)=="retrieve" ||
      extract(str,0,6)=="restore" ||
      extract(str,0,6) == "throw" ||
      extract(str,0,6) == "toss" ||
      extract(str,0,6) == "flame" ||
      extract(str,0,6) == "use" ||
      extract(str,0,6) == "wave" ||
      extract(str,0,6) == "shoot" ||
      extract(str,0,6) == "fire" ||
      extract(str,0,5) == "mount" ||
      extract(str,0,5) == "dismount" ||
      extract(str,0,5) == "wager" ||
      extract(str,0,5) == "yield" ||
      extract(str,0,4)=="value" ||
      extract(str,0,4)=="wear" ||
      extract(str,0,5)=="wield") {
    write(NORM+CYN+capitalize(raven_name)+" fumbles around trying to: "+str+"\n"+
          "and fails miserably.\n"+NORM);
    return 1;
  }

  /* try a player-type command */
  write(NORM+CYN+capitalize(raven_name)+" tries to: "+str+"\n");
  if (command(str, this_object()))
    write("and succeeds!\n"+NORM);
  else
    write("and fails miserably.\n"+NORM);

  return 1;
}

/* give all items to someone */
give_all_stuff(destination_str) {
  object obj2, obj3, destination_obj;
  int weight, dont_give_this;

  obj2 = first_inventory(this_object());
  if (!obj2) {
    write(NORM+CYN+capitalize(raven_name)+" says: I have nothing to give "+
          capitalize(destination_str)+".\n"+NORM);
    return 1;
  }
  while(obj2) {
    destination_obj = present(destination_str, environment(this_object()));
    weight = obj2->query_weight();
    /* no giving items with living things in it */
    dont_give_this=0;
    obj3 = first_inventory(obj2);
    while(obj3) {
      if (obj3->living()) dont_give_this=1;
      obj3 = next_inventory(obj3);
    }
    if (environment(obj2)==this_object() &&
        call_other(obj2, "drop", 0)!=1 &&
        obj2->get() &&
        destination_obj &&
        living(destination_obj) &&
        destination_obj->add_weight(weight) &&
        !dont_give_this) {
      add_weight(-weight);
      move_object(obj2, destination_obj);
      write(NORM+CYN+capitalize(raven_name)+" hands over "+obj2->short()+".\n"+NORM);
      say(NORM+CYN+capitalize(raven_name)+" gives "+obj2->short()+" to "+
          capitalize(destination_str)+".\n"+NORM);
    }
    obj2 = next_inventory(obj2);
  }
}

/* follow your master */
follow(str) {
  if (wait_here) {
    wait_counter = wait_counter + 6;
    if (wait_counter >= 300) {
      say(NORM+CYN+capitalize(raven_name)+" says: I'm tired of waiting.  I quit!\n"+NORM);
      obj=present("Alchemist Pouch", find_player(master_name));
      if (obj) {
        obj->dismiss_a_raven();
        tell_object(obj, NORM+CYN+capitalize(raven_name)+
                         " says: I'm tired of waiting.  I quit!\n"+NORM);
      }
      destruct(this_object());
      return 1;
    }
    call_out("follow", 6);
    return;
  }
  if (find_player(master_name) &&
      !present(find_player(master_name), environment(this_object()))) {
    tell_room(environment(this_object()),
              NORM+CYN+capitalize(raven_name)+" flies after "+
              capitalize(master_name)+".\n"+NORM);
    move_object(this_object(),environment(find_player(master_name)));
    tell_room(environment(find_player(master_name)),
              NORM+CYN+capitalize(raven_name)+" flies in and looks at " +
              capitalize(master_name)+".\n"+NORM);
  }
  call_out("follow", 6);
  return;
}

/* give raven a new master */
set_master(str) {
  master_name=str;
  return 1;
}

/* if the master's obj changes for some reason */
fix_raven(str) {
  if (!str || (str != "raven")) return;
  if (lower_case(this_player()->query_real_name()) != master_name) {
    write(NORM+CYN+"You're not my master!  Only "+capitalize(master_name)+
          " can fix me!\n"+NORM);
    return 1;
  }
  write(NORM+CYN+"Ok.\n"+NORM);
  return 1;
}

reset(arg) {
  ::reset(arg);
  if (arg) return;

  raven_name="raven";
  set_level(8);
  set_hp(130);
  set_ac(4);
  set_wc(12);
  set_can_kill(1);
  set_aggressive(0);
  set_ep(-666666);
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

short() {
  if (master_name)
    if (raven_name=="raven")
      write(NORM+CYN+capitalize(master_name)+"'s beautiful black raven.\n"+NORM);
    else
      write(NORM+CYN+capitalize(master_name)+"'s beautiful black raven named "+
            capitalize(raven_name)+".\n"+NORM);
  else
    if (raven_name=="raven")
      write(NORM+CYN+"A beautiful black raven.\n"+NORM);
    else
      write(NORM+CYN+"An beautiful black raven named "+capitalize(raven_name)+".\n"+NORM);
}

long() {
  if (master_name)
    if (raven_name=="raven")
      write(NORM+CYN+"This is "+capitalize(master_name)+"'s beautiful black raven.\n" +
            "Type 'raven help' to see how to talk to him.\n"+NORM);
    else
      write(NORM+CYN+"This is "+capitalize(master_name)+"'s beautiful black raven named "+
            capitalize(raven_name)+".\n"+
            "Type '"+raven_name+" help' to see how to talk to him.\n"+NORM);
  else
    if (raven_name=="raven")
      write(NORM+CYN+"This is a beautiful black raven without a master.\n" +
            "Type 'raven help' to see how to talk to him.\n"+NORM);
    else
      write(NORM+CYN+"This is a beautiful black raven without a master named "+
            capitalize(raven_name)+".\n" +
            "Type '"+raven_name+" help' to see how to talk to him.\n"+NORM);
  if (wait_here) {
    int how_long;
    how_long = 5 - (wait_counter / 60);
    write(NORM+CYN+capitalize(raven_name)+
          " notices you staring and says:\n"+
          "   I've been told to wait here for another "+how_long);
    if (how_long==1)
      write (" minute.\n"+NORM);
    else
      write (" minutes.\n"+NORM);
  }
  return 1;
}

pick_item(str) {
  object environment_of_obj, obj2, next_obj2;
  int weight, dont_take_this;
  str = lower_case(str);
  obj = present(str, environment(this_object()));
  if (!obj) {
    write(NORM+CYN+capitalize(raven_name)+" says: That is not here.\n"+NORM);
    return 1;
  }
  /* no handling money */
  if (obj->id("money") || obj->id("coins")) {
    write(NORM+CYN+capitalize(raven_name)+" says: I cannot carry money.\n"+NORM);
    return 1;
  }
  if (environment(obj)==this_object()) {
    write(NORM+CYN+capitalize(raven_name)+" says: I already have it!\n"+NORM);
    return 1;
  }
  environment_of_obj=environment(obj);
  if (call_other(obj, "get", 0)==0 ||
      (environment_of_obj &&
       call_other(environment_of_obj, "forbid_item_leave", obj) ||
       call_other(obj, "forbid_leave_container", environment_of_obj))) {
    write(NORM+CYN+capitalize(raven_name)+" says: I can't take that.\n"+NORM);
    return 1;
  }
  /* no getting items with living things in it */
  dont_take_this=0;
  obj2 = first_inventory(obj);
  while(obj2) {
    if (obj2->living()) dont_take_this=1;
    obj2 = next_inventory(obj2);
  }
  if (dont_take_this) {
    say(NORM+CYN+capitalize(raven_name)+" says:\n"+
        "   I don't like "+str+" and I won't take it!\n"+NORM);
    return 1;
  }
  weight = call_other(obj, "query_weight", 0);
  if (add_weight(weight)) {
    move_object(obj, this_object());
    call_other(environment_of_obj, "notify_item_leave", obj);
    call_other(obj, "notify_leave_container", environment_of_obj);
    say(NORM+CYN+capitalize(raven_name)+" takes "+str+".\n"+NORM);
    return 1;
  }
  write(NORM+CYN+capitalize(raven_name)+" says: I can't carry that much.\n"+NORM);
  return 1;
}

get_all(from_obj) {
  object next_obj, obj2, next_obj2;
  string item_str;
  int dont_take_this, weight;

  obj = first_inventory(from_obj);
  while(obj) {
    next_obj = next_inventory(obj);
    if (obj != this_object()) {
      item_str = call_other(obj, "short", 0);
        /* no getting items with living things in it or money */
        dont_take_this=0;
        if (obj->id("money") || obj->id("coins")) dont_take_this=1;
        obj2 = first_inventory(obj);
        while(obj2) {
          if (obj2->living()) dont_take_this=1;
          if (obj2->id("money") || obj2->id("coins")) dont_take_this=1;
          obj2 = next_inventory(obj2);
        }
        if (dont_take_this)
          say(NORM+CYN+capitalize(raven_name)+" says:\n"+
              "   I don't like "+item_str+" and I won't take it!\n"+NORM);
        else
        if (item_str && call_other(obj, "get", 0)) {
          weight = call_other(obj, "query_weight", 0);
          if (add_weight(weight)) {
            move_object(obj, this_object());
            /* if from_obj==container_str, then update its weight */
            if (call_other(from_obj, "can_put_and_get"))
              call_other(from_obj, "add_weight", -weight);
            say(NORM+CYN+capitalize(raven_name)+" takes "+item_str+".\n"+NORM);
          }
          else {
            write(NORM+CYN+item_str+" : Too heavy.\n"+NORM);
          }
        }
      }
      obj = next_obj;
  }
}

drop_all() {
  object ob, next_obj;
  ob = first_inventory(this_object());
  while(ob) {
    next_obj = next_inventory(ob);
    drop_one_item(ob);
    ob = next_obj;
  }
}

drop_one_item(ob) {
  int weight;
  if (!ob) {
    write(NORM+CYN+capitalize(raven_name)+" says: I don't have that!\n"+NORM);
    return;
  }
  if (call_other(ob, "drop", 0)) return;
  weight = call_other(ob, "query_weight", 0);
  if (!weight) weight = 0;
  add_weight(-weight);
  move_object(ob, environment(this_object()));
  say(NORM+CYN+capitalize(raven_name)+" drops "+call_other(ob, "short", 0)+".\n"+NORM);
  return 1;
}

set_master_name(str) {
  master_name = str;
}

set_raven_name(str) {
  raven_name = str;
  /* added because some were abusing the ravens by naming them after players */
  /* took out because i put a fix in for this
  raven_name = "raven";
  this_object()->set_name("raven");
  */
  this_object()->set_name(raven_name);
}

id(str) { return str=="raven" ||
                 str=="alchemist raven" ||
                 str=="guild_monster" ||
                 str=="guild_pet" ||
                 str==master_name+"raven" ||
                 str==master_name+"'s raven" ||
                 str==raven_name; }

is_pet() { return 1; }
is_raven() { return 1; }
query_save_flag() { return 1; }
am_i_a_raven() { return 1; }
