/*
  servant.c
*/

#define PERCENT_CHANCE_OF_EATING 5

inherit "obj/monster";

object obj, from_obj;
string str, master_name, servant_name;
int wait_here, wait_counter, servant_muffled;


init() {
  ::init();

  add_action("servant_do",  servant_name);
  add_action("fix_servant", "fix");
}

/* general commands to servant */
servant_do(str) {
  object item_obj, destination_obj, container_obj, environment_of_obj;
  object obj2, next_obj2;
  string item_str, container_str, destination_str;
  int weight, dont_take_this, dont_give_this;

  if (!find_player(master_name)) {
    say(capitalize(servant_name)+" sniffs and says I lost my master!\n"+
        capitalize(master_name)+" needs to fix me.\n");
    return 1;
  }

  if (!str || str=="") return;
  if (!this_player()) return;

  /* so i was bored.  so what? */
  if ((this_player()->query_real_name()=="nooneelse" ||
       this_player()->query_real_name()=="nancy") &&
      str=="eat") {
    servant_eat();
    str=0;
    return 1;
  }

/* was it my master? */
  if(this_player() != find_player(master_name)) {
    say("The servant sniffs and glares at "+
        this_player()->query_name()+"\n"+" and says:\n"+
        "  I only listen to "+capitalize(master_name)+"!\n");
    return 1;
  }

/* dismiss servant */
  if (lower_case(str)=="dismissed") {
    say(capitalize(servant_name)+" looks sadly at "+
        capitalize(master_name)+" and says: As you wish.\n");
    obj=present("nooneelse@vampire@fangs", find_player(master_name));
    obj->dismiss_a_servant();
    destruct(this_object());
    return 1;
  }

/* tell servant to wait here */
  if (lower_case(str)=="wait here") {
    say(capitalize(servant_name)+" snaps to attention and salutes at "+
        capitalize(master_name)+" and says: Yes boss!\n");
    say(capitalize(servant_name)+" says: I'll wait here for 5 minutes.\n");
    wait_here = 1;
    wait_counter = 0;
    return 1;
  }

/* tell servant to follow me */
  if (lower_case(str)=="follow me") {
    say(capitalize(servant_name)+" snaps to attention and salutes at "+
        capitalize(master_name)+" and says: Yes boss!\n");
    wait_here = 0;
    return 1;
  }

/* help */
  if (str=="help") {
    short();
    write("Command him with: "+servant_name+" <command>\n");
    write(
"He can do the following:\n\n"+
"wait here         tells the servant to wait here\n"+
"                  (he'll wait 5 mintues, then quit)\n"+
"follow me         tells the servant to stop waiting here & follow you again\n"+
"dismissed         destroy the servant\n"+
"help              display this message\n"+
"muffle            shut the hell up while i'm fighting! (toggle)\n"+
"fix servant       fix your servant (if he won't listen anymore)\n\n"+
"He can also do a lot of player-type commands like: "+servant_name+
" get torch\n\n");
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
      write(capitalize(servant_name)+" says: There is no "+container_str+
            " here.\n");
      return 1;
    }
    if (!call_other(container_obj, "can_put_and_get", 0)) {
      write(capitalize(servant_name)+" says: I can't do that!\n");
      return 1;
    }
    if (item_str=="all") {
      get_all(container_obj);
      return 1;
    }
    item_obj = present(item_str, container_obj);
    if (!item_obj){
      write(capitalize(servant_name)+" says: There is no "+item_str+" in the "+
            container_str+".\n");
      return 1;
    }
    if (!call_other(item_obj, "get", item_str) ||
        call_other(container_obj, "forbid_item_leave", item_obj) ||
        call_other(item_obj, "forbid_leave_container", container_obj)) {
      write(capitalize(servant_name)+" says: I can't take "+item_str+" from "+
            container_str+".\n");
      return 1;
    }
    weight = call_other(item_obj, "query_weight", 0);
    if (!add_weight(weight)) {
      write(capitalize(servant_name)+" says: I cannot carry more.\n");
      return 1;
    }
    /* no handling money */
    if (item_obj->id("money") || item_obj->id("coins")) {
      write(capitalize(servant_name)+" says: I cannot carry money.\n");
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
      say(capitalize(servant_name)+" says:\n"+
          "   I don't like "+item_str+" and I won't take it!\n");
      return 1;
    }
    call_other(container_obj, "add_weight", -weight);
    move_object(item_obj, this_object());
    call_other(container_obj, "notify_item_leave", item_obj);
    call_other(item_obj, "notify_leave_container", container_obj);
    say(capitalize(servant_name)+" takes "+item_str+" from "+
        container_str+".\n");
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
    say(capitalize(servant_name)+" says: I cannot carry money.\n");
    return 1;
  }

/* give something to someone */
    if (sscanf(str, "give %s to %s", item_str, destination_str)==2) {
      if (item_str=="all") {
        destination_obj = present(destination_str, environment(this_object()));
        if (!destination_obj) {
          write(capitalize(servant_name)+" says: There is no "+
                capitalize(destination_str)+" here.\n");
          return 1;
        }
        if (!living(destination_obj)) {
          write(capitalize(servant_name)+" says: I can't do that.\n");
          return 1;
        }
        give_all_stuff(destination_str);
        return 1;
      }
      if (item_str) {
        item_str = lower_case(item_str);
        item_obj = present(item_str, this_object());
        /* no handling money */
     if(item_obj)
        if (item_obj->id("money") || item_obj->id("coins")) {
          write(capitalize(servant_name)+" says: I cannot carry money.\n");
          return 1;
        }
        if (!item_obj) {
          write(capitalize(servant_name)+" says: I have no "+item_str+".\n");
          return 1;
        }
        if (environment(item_obj)==this_object() &&
            call_other(item_obj, "drop", 0)==1) {
          return 1;
        }
        else {
          if (!call_other(item_obj, "get")) {
            write(capitalize(servant_name)+" says: I can't do that.\n");
            return 1;
          }
        }
      }
      destination_obj = present(destination_str, environment(this_object()));
      if (!destination_obj) {
        write(capitalize(servant_name)+" says: There is no "+
              capitalize(destination_str)+" here.\n");
        return 1;
      }
      if (!living(destination_obj)) {
        write(capitalize(servant_name)+" says: I can't do that.\n");
        return 1;
      }
      weight = call_other(item_obj, "query_weight", 0);
      if (!call_other(destination_obj, "add_weight", weight)) {
        write(capitalize(servant_name)+" says: "+capitalize(destination_str)+
              " can't carry any more.\n");
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
      say(capitalize(servant_name)+" says:\n"+
          "   I don't like "+item_str+" and I won't keep it!\n");
      drop_one_item(item_obj);
      return 1;
    }
      add_weight(-weight);
      move_object(item_obj, destination_obj);
      say(capitalize(servant_name)+" gives "+item_str+" to "+
          capitalize(destination_str)+".\n");
      return 1;
  }

/* check for the direction commands & fix em so he can understand */
  if (str=="n") str="north";
  if (str=="ne") str="northeast";
  if (str=="e") str="east";
  if (str=="se") str="southeast";
  if (str=="s") str="south";
  if (str=="sw") str="southwest";
  if (str=="w") str="west";
  if (str=="nw") str="northwest";
  if (str=="u") str="up";
  if (str=="d") str="down";

/* was it a kill command? */
  if (sscanf(str, "kill %s", str)==1) {
    write("Your servant regretfully says: I'm sorry, I cannot fight.\n");
/*
    obj=present(str, environment(this_object()));
    this_object()->attacked_by(obj);
*/
    return 1;
  }

/* no selling (& some other things) for servants */
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
      extract(str,0,4)=="value") {
   write(capitalize(servant_name)+" tries to: "+str+"\n");
    write("and fails miserably.\n");
    return 1;
}
  /* tell servant to shut up */
  if (str=="muffle") {
    if (servant_muffled) {
      servant_muffled=0;
      write("The servant's muffle is now OFF.\n");
    }
    else {
      servant_muffled=1;
      write("The servant's muffle is now ON.\n");
    }
    return 1;
  }

/* try a player-type command */
  write(capitalize(servant_name)+" tries to: "+str+"\n");
  if (command(str, this_object()))
    write("and succeeds!\n");
  else
    write("and fails miserably.\n");

  return 1;
}

/* give all items to someone */
give_all_stuff(destination_str) {
  object obj2, obj3, obj4, destination_obj;
  int weight, dont_give_this;
  obj2 = first_inventory(this_object());
  if (!obj2) {
    write(capitalize(servant_name)+" says: I have nothing to give "+
          capitalize(destination_str)+".\n");
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
    obj4 = next_inventory(obj2);
    if (environment(obj2)==this_object() &&
        call_other(obj2, "drop", 0)!=1 &&
        obj2->get() &&
        destination_obj &&
        living(destination_obj) &&
        destination_obj->add_weight(weight) &&
        !dont_give_this) {
      add_weight(-weight);
      move_object(obj2, destination_obj);
      say(capitalize(servant_name)+" gives "+obj2->short()+" to "+
          capitalize(destination_str)+".\n");
    }
    obj2 = obj4;
  }
}

/* follow your master */
follow(str) {
  if(!environment(this_object())) return 1;
  if (wait_here) {
    wait_counter = wait_counter + 6;
    if (wait_counter >= 300) {
      say(capitalize(servant_name)+" says: I'm tired of waiting.  I quit!\n");
   if(find_player(master_name)) {
      obj=present("nooneelse@vampire@fangs", find_player(master_name));
   if(obj)
      obj->dismiss_a_servant();
     tell_object(find_player(master_name),capitalize(servant_name)+
                  " says: I'm tired of waiting.  I quit!\n");
   }
      destruct(this_object());
      return 1;
    }
    call_out("follow", 6);
    return;
  }
  if(master_name)
  if(find_player(master_name))
  if(!present(master_name,environment(this_object())) ) {
    tell_room(environment(this_object()),
              capitalize(servant_name)+" trots away after "+
              capitalize(master_name)+".\n");
    move_object(this_object(),environment(find_player(master_name)));
    tell_room(environment(find_player(master_name)),
              capitalize(servant_name)+" runs in and bows to " +
              capitalize(master_name)+".\n");
  }
  call_out("follow", 6);
  return;
}

/* give servant a new master */
set_master(str) {
  master_name=str;
  return 1;
}

/* if the master's obj changes for some reason */
fix_servant(str) {
  if (!str || str != "servant") return;
  if (lower_case(this_player()->query_real_name()) != master_name) {
    write("You're not my master!  Only "+capitalize(master_name)+
          " can fix me!\n");
    return 1;
  }
  write("Ok.\n");
  return 1;
}

reset(arg) {
  ::reset(arg);
  if (arg) return;

  servant_name="servant";
  set_level(8);
  set_hp(130);
  set_ac(4);
  set_wc(12);
  set_can_kill(1);
  set_aggressive(0);
  set_ep(-666666);
  call_out("follow", 6);
  enable_commands();
   master_name = 0;
}

heart_beat() {
  if(master_name) if(find_player(master_name))
  if (this_object()->query_attack() == find_player(master_name)) {
    this_object()->stop_fight();
    this_object()->stop_fight();
    this_object()->stop_hunter();
  }
  /* another thing created out of my boredom */
  if (random(100) < PERCENT_CHANCE_OF_EATING && !servant_muffled) servant_eat();

  ::heart_beat();
}

query_save_flag() { return 1; }

am_i_a_servant() { return 1; }

short() {
  if (master_name)
    if (servant_name=="servant")
      write(capitalize(master_name)+"'s ugly servant.\n");
    else
      write(capitalize(master_name)+"'s ugly servant named "+
            capitalize(servant_name)+".\n");
  else
    if (servant_name=="servant")
      write("An ugly servant.\n");
    else
      write("An ugly servant named "+capitalize(servant_name)+".\n");
}

long() {
  if (master_name)
    if (servant_name=="servant")
      write("This is "+capitalize(master_name)+"'s ugly servant.\n" +
            "Type 'servant help' to see how to talk to him.\n");
    else
      write("This is "+capitalize(master_name)+"'s ugly servant named "+
            capitalize(servant_name)+".\n"+
            "Type '"+servant_name+" help' to see how to talk to him.\n");
  else
    if (servant_name=="servant")
      write("This is an ugly servant without a master.\n" +
            "Type 'servant help' to see how to talk to him.\n");
    else
      write("This is an ugly servant without a master named "+
            capitalize(servant_name)+".\n" +
            "Type '"+servant_name+" help' to see how to talk to him.\n");
  if (wait_here) {
    int how_long;
    how_long = 5 - (wait_counter / 60);
    write(capitalize(servant_name)+
          " notices you staring and says:\n"+
          "   I've been told to wait here for another "+how_long);
    if (how_long==1)
      write (" minute.\n");
    else
      write (" minutes.\n");
  }
  return 1;
}

pick_item(str) {
  object environment_of_obj, obj2, next_obj2;
  int weight, dont_take_this;
  str = lower_case(str);
  obj = present(str, environment(this_object()));
  if (!obj) {
    write(capitalize(servant_name)+" says: That is not here.\n");
    return 1;
  }
  /* no handling money */
  if (obj->id("money") || obj->id("coins")) {
    write(capitalize(servant_name)+" says: I cannot carry money.\n");
    return 1;
  }
  if (environment(obj)==this_object()) {
    write(capitalize(servant_name)+" says: I already have it!\n");
    return 1;
  }
  environment_of_obj=environment(obj);
  if (call_other(obj, "get", 0)==0 ||
      (environment_of_obj &&
       call_other(environment_of_obj, "forbid_item_leave", obj) ||
       call_other(obj, "forbid_leave_container", environment_of_obj))) {
    write(capitalize(servant_name)+" says: I can't take that.\n");
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
    say(capitalize(servant_name)+" says:\n"+
        "   I don't like "+str+" and I won't take it!\n");
    return 1;
  }
  weight = call_other(obj, "query_weight", 0);
  if (add_weight(weight)) {
    move_object(obj, this_object());
    call_other(environment_of_obj, "notify_item_leave", obj);
    call_other(obj, "notify_leave_container", environment_of_obj);
    say(capitalize(servant_name)+" takes "+str+".\n");
    return 1;
  }
  write(capitalize(servant_name)+" says: I can't carry that much.\n");
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
          say(capitalize(servant_name)+" says:\n"+
              "   I don't like "+item_str+" and I won't take it!\n");
        else
        if (item_str && call_other(obj, "get", 0)) {
/*@#@#@#@#@#@#@#@#*/
          weight = call_other(obj, "query_weight", 0);
          if (add_weight(weight)) {
            move_object(obj, this_object());
 /* if from_obj==container_str, then update its weight */
            if (call_other(from_obj, "can_put_and_get"))
              call_other(from_obj, "add_weight", -weight);
            say(capitalize(servant_name)+" takes "+item_str+".\n");
          }
          else {
            write(item_str+" : Too heavy.\n");
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
    write(capitalize(servant_name)+" says: I don't have that!\n");
    return;
  }
  if (call_other(ob, "drop", 0)) return;
  weight = call_other(ob, "query_weight", 0);
  if (!weight) weight = 0;
  add_weight(-weight);
  move_object(ob, environment(this_object()));
  say(capitalize(servant_name)+" drops "+call_other(ob, "short", 0)+".\n");
  return 1;
}

set_master_name(str) {
  master_name = str;
}

set_servant_name(str) {
  servant_name = str;
}

master_turned_good() {
  say(capitalize(servant_name)+" yells what?!\n"+
      "You're not the sort of person I thought you were!\n"+
      "I'm not working for you anymore!\n");
  if (first_inventory(this_object())) {
    say("Here's your junk.  Carry it yourself!\n");
    drop_all();
  }
  say("With that, "+capitalize(servant_name)+" stalks off.\n");
  destruct(this_object());
  return 1;
}

servant_eat() {
  string servant_food, food_noise;
  int i;
  tell_room(environment(this_object()),
            capitalize(servant_name)+
            " seems to notice something on the ground and picks it up.\n\n");
  i=random(4);
  if (i==0) servant_food="big, fat, juicy earthworm";
  if (i==1) servant_food="huge juicy caterpiller";
  if (i==2) servant_food="big, wiggling sewer roach";
  if (i==3) servant_food="big, black, beetle";
  if (i==0 || i==1) food_noise="slurping";
  if (i==2 || i==3) food_noise="crunching";
  tell_room(environment(this_object()),
            "You hear "+food_noise+" noises as "+capitalize(servant_name)+
            " stuffs a "+servant_food+"\n"+
            "into his mouth and starts to chew.\n\n"+
            "After a moment, with a smile of satisfaction, he gulps loudly\n"+
            "as he swallows.\n");
}

id(str) { return str=="servant" ||
                 str=="guild_monster" ||
                 str=="guild_pet" ||
                 str==master_name+"servant" ||
                 str==master_name+"_servant" ||
                 str==servant_name; }

is_pet() { return 1; }
