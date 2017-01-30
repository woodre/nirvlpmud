/*
  scroll_astral_projection.c - the read/activation mechanism was inspired by
                               boltar's scrolls on nirvana
*/

object spirit_obj, body_obj;
int scroll_value;

query_save_flag() { return 1; }

init() {

  add_action("read",     "read");
  add_action("read",     "examine");
  add_action("activate", "activate");
}

read_scroll(str) {
  if (!str || !id(str)) return;
  long();
  return 1;
}

activate(arg) {
  if (arg != "astral scroll") return;
  if (spirit_obj) {
    write("You stop the activation of the scroll as you realize you are\n"+
          "already in spirit form.\n");
    return 1;
  }
  say(this_player()->query_name()+
      " pulls out a glinting, silvery, frosted scroll.\n"+
      "As "+this_player()->query_pronoun()+
      " unrolls the scroll, some silver dust falls to the ground.\n"+
      capitalize(this_player()->query_name())+
      " recites some mystical words in a mysterious tongue.  The dust\n"+
      "scattered on the ground forms a mysterious crystalline energy that "+
      "envelops "+this_player()->query_objective()+".\n"+
      "You see "+this_player()->query_name()+
      "'s spirit separate from "+this_player()->query_objective()+" body.\n");
  write("You pull out a glinting silvery frosted scroll.\n"+
        "As you unroll the scroll, some silver dust falls to the ground.\n"+
        "You recite the words on the scroll and a magical aura "+
        "surrounds you.\n"+
        "Something strange happens.  You see your body from above.\n");
  spirit_obj = clone_object("obj/monster");
  spirit_obj->set_name("spirit");
  spirit_obj->set_level(1);
  spirit_obj->set_short(
                "The spirit of "+capitalize(this_player()->query_name()));
  spirit_obj->set_long(
                "The spirit of "+capitalize(this_player()->query_name())+".\n");
  body_obj = this_player();
  move_object(clone_object("obj/soul"), spirit_obj);
  move_object(spirit_obj, environment(this_player()));
  write("Type 'body' to return to your body.\n");
  write("S 'body'>");
  input_to("move_spirit");
  return 1;
}

move_spirit(str) {
  string cmd, arg;
  object spirit_env;
  if (str=="body") {
    say(capitalize(this_player()->query_name())+" comes to "+
        this_player()->query_posessive()+" senses.\n");
    write("As you reenter your body, you see the scroll crumble to dust.\n");
    destruct(spirit_obj);
    destruct(this_object());
    return 1;
  }
  if (!spirit_obj || !living(spirit_obj)) return 1;
  if (str=="n") str="north";
  if (str=="ne") str="northeast";
  if (str=="e") str="east";
  if (str=="se") str="southeast";
  if (str=="s") str="south";
  if (str=="sw") str="southwest";
  if (str=="w") str="west";
  if (str=="nw") str="northwest";
  cmd = "";
  if (str[0]=="'") {
    cmd="say";
    str[0]=" ";
    arg=str;
  }
  else
  if (sscanf(str, "%s %s", cmd, arg) != 2) cmd = str;
  spirit_env = environment(spirit_obj);
  if (str=="quit")
    tell_object(body_obj,
      "You can not quit until you type 'body' to return to your body.\n");
  else
  if (cmd=="kill")
    tell_object(body_obj, "You are a spirit!  You can not fight!\n");
  else
  if (cmd=="say" || cmd=="'")
    say("Spirit says: "+arg+".\n");
  else
  if (cmd=="put" || cmd=="get" || cmd=="get" || cmd=="give" || cmd=="take")
    tell_object(body_obj, "Your hands pass right through it!\n");
  else
  if (cmd=="look" || cmd=="l") s_look(arg);
  else
  if (cmd=="exa" || cmd=="examine") s_look("examine "+arg);
  else
  if (cmd=="who") s_who();
  else
  if (cmd=="tell" || cmd=="whisper")
    tell_object(body_obj,
      "Your poor spirit does not have the energy to speak to anyone.\n");
  else {
    spirit_obj->init_command(str);
  }
  if (spirit_env != environment(spirit_obj)) s_look();
  write("S 'body'>");
  input_to("move_spirit");
  return 1;
}

/* special version of who for the spirit */
s_who() {
  object player_list;
  int i;
  string short_desc;
  player_list = users();
  for (i=0; i<sizeof(player_list); i++) {
    short_desc=0;
    short_desc=player_list[i]->short();
    if (short_desc && !(player_list[i]->query_invis() > 0))
      tell_object(body_obj, short_desc+"\n");
  }
  return 1;
}

/* special version of look for the spirit */
s_look(str) {
  object obj, tmp_obj, special_obj;
  string item_name, short_str, extra_str, str1;
  int item_weight;

  /* it's a 'look' or 'l' */
  if (!str) {
    environment(spirit_obj)->long();
    obj = first_inventory(environment(spirit_obj));
    while(obj) {
      if (obj != spirit_obj) {
        short_str = obj->short();
        if (short_str) {
          if (obj->is_player()) {
            if (!obj->query_invis() > 0)
              tell_object(body_obj, short_str+"\n");
          }
          else
            tell_object(body_obj, short_str+".\n");
        }
      }
      obj = next_inventory(obj);
    }
    return 1;
  }

  /* look at or examine a specific item */
  if (sscanf(str, "examine %s", item_name)==1 ||
      sscanf(str, "at %s", item_name)==1 ||
      sscanf(str, "in %s", item_name)==1) {
    item_name = lower_case(item_name);
    obj = present(item_name, environment(spirit_obj));
    if (!obj || obj->is_player() && obj->query_invis() > 0) {
      write("Look at what?\n");
      return 1;
    }
    if (!obj && environment(spirit_obj)->id(item_name))
      obj=environment(spirit_obj);
    if (!obj)
      obj=present(item_name, environment(spirit_obj));
    if (!obj) {
      tell_object(body_obj, "There is no '"+item_name+"' here.\n");
      return 1;
    }
    obj->long(item_name);
    item_weight=obj->query_weight();
    if (!living(obj)) {
      if (item_weight >= 5)
        write("It looks very heavy.\n");
      else if (item_weight >= 3)
        write("It looks heavy.\n");
    }
    if (!obj->can_put_and_get(item_name)) return 1;
    if (living(obj)) {
      special_obj = first_inventory(obj);
      while(special_obj) {
        extra_str = special_obj->extra_look();
        if (extra_str) tell_object(body_obj, extra_str+".\n");
        special_obj = next_inventory(special_obj);
      }
    }
    tmp_obj = first_inventory(obj);
    while(tmp_obj && tmp_obj->short()==0)
      tmp_obj = next_inventory(tmp_obj);
      if (tmp_obj) {
        if (living(obj))
          tell_object(body_obj,"\t"+capitalize(item_name)+" is carrying:\n");
        else
          tell_object(body_obj,"\t"+capitalize(item_name)+" contains:\n");
      }
      obj = first_inventory(obj);
    while(obj) {
        str1 = obj->short();
        if (str1) tell_object(body_obj, str1+".\n");
        obj = next_inventory(obj);
      }
    return 1;
  }

  tell_object(body_obj, "You can't focus your eyes on that.\n");
  return 1;
}

short() { return "A silver scroll"; }

long() {
  write("This scroll was created by creatures of another world.  It glitters\n"+
        "like it was made of silver dust.  You can't seem to make out many\n"+
        "of the words, but it seems to have something to do with astral\n"+
        "projection.\n\n"+
        "To activate it, be in a safe place and type:\n"+
        "   activate astral scroll\n");
}

extra_look() {
  if (!spirit_obj || !living(spirit_obj)) return 1;
  return (capitalize(body_obj->query_name())+" is in some kind of trance.");
}

query_value() {
  if (!scroll_value) return 500;
  return scroll_value;
}

query_weight() { return 1; }

set_scroll_value(arg) { scroll_value=arg; }

get() { return 1; }
drop() { return 0; }

catch_tell(str) {
  if (living(spirit_obj)) tell_object(body_obj, str+"\n");
  return;
}

id(str) {
  return str=="scroll" ||
         str=="astral scroll" ||
         str=="astral projection scroll";
}
