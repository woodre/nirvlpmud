#define ME capitalize(this_player()->query_name())
#define LE capitalize(environment(this_object())->query_name())
#define ENV environment(this_object())

string *follow;

reset(arg){
  if(arg) return;
  follow = ({ });
  call_out("follow", 4);
}

id(str) {
  return str == "ilstkarn_follow" || str == "follow" || str == "follow object";
}

long(){
  write("\n"+
  "This is an Ilstkarn follow object.  It allows other players\n"+
  "to follow you in the realms of Ilstkarn.\n"+
  "You can use the following commands:\n\n");
  write(
  "   foladd <player>     - add a follower.\n"+
  "   folrem <player>     - remove a follower.\n"+
  "   folist              - list following players.\n"+
  "   foldel              - trash this object.\n\n");
  return;
}

short(){
  return "A follow object (leader)";
}

get() {
  return 1;
}

drop() {
  return 1;
}

query_weight() {
  return 0;
}

query_value() {
  return 0;
}

query_save_flag() {
  return 1;
}

query_leader_ob() { return 1; }
query_follow(){ return follow; }

allowed_follow(name) {
  int i;

  for(i=0; i<sizeof(follow); i++) {
    if(follow[i] == name) return 1;
  }
  return 0;
}

init() {
  add_action("foladd", "foladd");
  add_action("folrem", "folrem");
  add_action("folist", "folist");
  add_action("foldel", "foldel");
  add_action("folon", "folon");
  add_action("foloff","foloff");
}

foladd(str) {
  object ob, obj;

  obj = present(str, environment(this_player()));

  if(!obj || !obj->is_player()) {
    write("That person is not here.\n");
    return 1;
  }

  if(present("ilstkarn_follow", obj)) {
    if(present("ilstkarn_follow", obj)->query_leader()) {
      write(capitalize(str)+" is already following someone.\n");
      return 1;
    }
    if(present("ilstkarn_follow", obj)->query_leader_ob()) {
      write(capitalize(str)+" is already leading a group.\n");
      return 1;
    }
  }

  write("You offer to lead "+capitalize(str)+".  ");
  write("Waiting for confirmation...\n");

  if(present("ilstkarn_follow", obj)) {
    present("ilstkarn_follow", obj)->ask_follow(this_player()->query_real_name());
  }
  else {
    ob = clone_object("players/pavlik/items/ilstkarn/ilstkarn_follow");
    move_object(ob, obj);
    ob->ask_follow(this_player()->query_real_name());
  }

  return 1;
}

confirm_follow(who) {
  tell_object(ENV, capitalize(who)+" has accepted your request.\n"+
                   capitalize(who)+" now follows you.\n");

  follow += ({ who });

  return 1;
}

folrem(who) {
  object obj;
  int f, i;

  f = 0;
  for(i=0; i<sizeof(follow); i++) {
     if(follow[i] == who) {
       write(capitalize(who)+" is removed from the follow.\n");
       follow -= ({ who });
       f = 1;
       obj = find_player(who);
       if(obj) {
         tell_object(find_player(who), "You no longer follow "+ME+".\n");
         if(present("ilstkarn_follow", obj))
            present("ilstkarn_follow", obj)->set_leader(0);
       }
       break;
     }
  }
  
  if(!f) {
    write(capitalize(who)+" is not following you.\n");
  }
  return 1;
}

remove_follower(str) {
  int i;

  for(i=0; i<sizeof(follow); i++) {
    if(follow[i] == str) {
      tell_object(ENV, capitalize(str)+" is no longer following you.\n");
      follow -= ({ str });
    }
  }
  return 1;
}

folist() {
  int i;

  write("The current people are following you:\n");

  for(i=0; i<sizeof(follow); i++) {
     write("\t"+follow[i]+"\n");
  }
  return 1;
}

foldel() {
  object obj;
  int i;

  write("You trash the Ilstkarn follow object.\n");
  for(i=0; i<sizeof(follow); i++) {
    obj = find_player(follow[i]);
    if(obj && present("ilstkarn_follow", obj)) {
      tell_object(obj, "You no longer follow "+ME+".\n");
      present("ilstkarn_follow", obj)->set_leader(0);
    }
  }
  destruct(this_object());
  return 1;
}

follow() {
  object obj, folob;
  object env, folenv;
  int i;

  env = environment(ENV);

  if(!env->query_ilstkarn()) {
    call_out("follow", 5);
    return 1;
  }

  if(env->query_ghost()) {
    destruct(this_object());
    return 1;
  }

  for(i=0; i<sizeof(follow); i++) {
     obj = find_player(follow[i]);
     
     if(obj && environment(obj) != env && environment(obj)->query_ilstkarn()) {
       folob = present("ilstkarn_follow", obj);
       folenv = environment(obj);

       if(folob) {
         if(env->query_nofollow() || folenv->query_nofollow()) {
           if(!folob->query_follow_delay()) {
             tell_object(obj,
             "You must follow the leader manually to his location.\n"+
             "delaying follow.....\n");
             folob->set_follow_delay(3);
           }
           else {
             folob->tick_follow_delay();
           }
         }
         else {
           tell_object(obj, "You follow "+LE+".\n");
           tell_room(env, capitalize(follow[i])+" arrives following "+LE+".\n");
           move_object(obj, env);
           command("look", obj);
           tell_room(folenv, capitalize(follow[i])+" leaves following "+LE+".\n");
         }
      }
    }
  }

  call_out("follow", 3);
  return 1;
}

