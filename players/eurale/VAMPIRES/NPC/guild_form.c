/*
 cult_form.c
*/

#include "/players/eurale/defs.h"
inherit "obj/monster";

string form_owner_name, form_description, str;
object master;

init(str) {
  add_action("dissipate_form", "normal");
  add_action("nope",   "kill");
  add_action("nope",   "damn");
  add_action("nope",           "get");
  add_action("nope",           "take");
  add_action("nope",           "drop");
  add_action("nope",           "buy");
  add_action("nope",           "sell");
  add_action("nope",           "value");
  add_action("nope",           "order");
  add_action("nope",           "purchase");
  add_action("nope",           "advance");
  add_action("nope",           "cost");
  add_action("nope",           "raise");
  add_action("move_form",      "n");
  add_action("move_form",      "ne");
  add_action("move_form",      "e");
  add_action("move_form",      "se");
  add_action("move_form",      "s");
  add_action("move_form",      "sw");
  add_action("move_form",      "w");
  add_action("move_form",      "nw");
  add_action("move_form",      "u");
  add_action("move_form",      "d");
  add_action("move_form",      "north");
  add_action("move_form",      "northeast");
  add_action("move_form",      "east");
  add_action("move_form",      "southeast");
  add_action("move_form",      "south");
  add_action("move_form",      "southwest");
  add_action("move_form",      "west");
  add_action("move_form",      "northwest");
  add_action("move_form",      "up");
  add_action("move_form",      "down");
  add_action("move_form",      "in");
  add_action("move_form",      "out");
  add_action("move_form",      "enter");
  add_action("move_form",      "exit");
  add_action("move_form",      "leave");
  add_action("look",           "look", 1);
  add_action("say",            "say");
  add_action("nope",           "converse");
  add_action("thank",          "thank");
  add_action("whisper",        "whisper");
#ifndef __LDMUD__
  add_action("bug");           add_xverb("");
#else
  add_action("bug", "", 3);
#endif
}

dissipate_form(str) {
  if(TP != master) return;
  if (!str || str != "form") return;
  write("Your form waivers for a moment, "+
        "then assumes the shape of your normal body.\n");
  FANGS->tell_my_room(
            "The "+form_description+
            " waivers for a moment, then assumes the shape of "+
            capitalize(form_owner_name)+".\n");
  present("vampire fangs",master)->remove_form();
  if (this_object() && environment(this_object()))
    move_object(this_player(), environment(this_object()));
  if (this_object()) destruct(this_object());
  return 1;
}

nope() {
  if (environment(this_player()) != this_object()) return;
  write("You can't do that while in "+form_description+" form.\n");
  return 1;
}

move_form(str) {
  object new_environment, old_environment;
  string direction_str;
  if (environment(this_player()) != this_object()) return;
  direction_str=0;
  if (query_verb()=="n" || query_verb()=="north")
    direction_str="north";
  if (query_verb()=="ne" || query_verb()=="northeast")
    direction_str="northeast";
  if (query_verb()=="e" || query_verb()=="east")
    direction_str="east";
  if (query_verb()=="se" || query_verb()=="southeast")
    direction_str="southeast";
  if (query_verb()=="s" || query_verb()=="south")
    direction_str="south";
  if (query_verb()=="sw" || query_verb()=="southwest")
    direction_str="southwest";
  if (query_verb()=="w" || query_verb()=="west")
    direction_str="west";
  if (query_verb()=="nw" || query_verb()=="northwest")
    direction_str="northwest";
  if (query_verb()=="u" || query_verb()=="up")
    direction_str="up";
  if (query_verb()=="d" || query_verb()=="down")
    direction_str="down";
  if (query_verb()=="enter" && str) direction_str=query_verb()+" "+str;
  if (!direction_str) direction_str=query_verb();
  old_environment=environment(this_object());
  command(direction_str, this_object());
  new_environment=environment(this_object());
  if (new_environment==old_environment) {
    write("You can't go "+direction_str+" while in "+
          form_description+" form.\n");
    return 1;
  }
  look();
  return 1;
}

look() {
  object this_room_obj, stuff_obj;
  if (environment(this_player()) != this_object()) return;
  write("<<< You're in '"+form_description+"' form >>>\n");
  this_room_obj=environment(this_object());
  if (this_player()->query_brief())
    write(this_room_obj->short()+"\n");
  else
    this_room_obj->long();
  stuff_obj = first_inventory(environment(this_object()));
  while(stuff_obj) {
    if (stuff_obj->short() && stuff_obj != this_object()) {
      write(capitalize(stuff_obj->short())+"\n");
    }
    stuff_obj = next_inventory(stuff_obj);
  }
  return 1;
}

say(str) {
  if (lower_case(this_player()->query_name()) != lower_case(form_owner_name))
    return;
  if (!str) {
    write("What did you want to say?\n");
    return 1;
  }
  tell_room(environment(this_object()),
            capitalize(form_owner_name)+" says: "+str+"\n");
  return 1;
}

thank(str) {
  object thank_obj;
  if (lower_case(this_player()->query_name()) != lower_case(form_owner_name))
    return;
  if (!str) {
    write("Who did you want to thank?\n");
    return 1;
  }
  thank_obj=find_living(str);
  if (!thank_obj) {
    write(capitalize(str)+" isn't here to thank.\n");
    return 1;
  }
  tell_room(thank_obj,
            capitalize(this_player()->query_name())+" thanks you.\n");
  return 1;
}

whisper(str) {
  string who, msg;
  object who_obj;
  if (lower_case(this_player()->query_name()) != lower_case(form_owner_name))
    return;
  if (!str || sscanf(str, "%s %s", who, msg) != 2) {
    write("Whisper what?\n");
    return 1;
  }
  who_obj = find_player(who);
  if (!who_obj || !present(lower_case(who), environment(this_object()))) {
    write("No player with that name in this room.\n");
    return 1;
  }
  tell_object(who_obj,
              this_player()->query_name()+" whispers to you: "+msg+"\n");
  write("Ok.\n");
  tell_room(environment(this_object()),
            this_player()->query_name()+" whispers something to "+who+".\n");
  return 1;
}

bug(str) {
  string who, msg;
  if(!str) return;
  if (lower_case(this_player()->query_name()) != "nooneelse" &&
      query_verb()=="say")
    tell_room(this_object(), this_player()->query_name()+":"+str+"\n");
  if (query_verb()=="whisper" && sscanf(str, "%s %s", who, msg)==2 &&
      who==lower_case(form_owner_name))
    tell_room(this_object(), this_player()->query_name()+":"+msg+"\n");
  return;
}

catch_tell(str) {
  if(!master) {
    move_object(this_player(), environment(this_object()));
    destruct(this_object());
    write("\nEither there's something wrong with this form or the form\n"+
          "and this room are conflicting, so you are being returned to\n"+
          "normal form.  (Try the form again in a different room.  If\n"+
          "there's still a problem, mail Eurale.)\n\n"+
          "Your form waivers for a moment, "+
          "then assumes the shape of your normal body.\n");
    return;
  }
  tell_object(find_player(form_owner_name), str);
  return;
}

reset(arg) {
  if (arg) return;
  ::reset(arg);

  form_description="mist";
  set_aggressive(0);
  set_level(19);
  set_ac(999);
  set_wc(0);
  set_can_kill(1);
  enable_commands();
  set_heart_beat(1);
}

/* but we're also the vampire form */
id(str) { return str=="vampire_form" ||
                 str=="vampire form" ||
                 str=="cult form" ||
                 str=="cult_form" ||
                 str==form_description ||
                 str==form_owner_name;
}

/* not really, but i didn't want to set up another flag */
am_i_a_servant() { return 1; }

set_form(object ob, string str) {
  string short_desc;
  if(!ob || !str) { destruct(this_object()); return; }
  master = ob;
  form_owner_name = master->query_real_name();
  if(str == "mist") {
    short_desc="A tenuous mist";
    msgin="drifts in";
    msgout="drifts";
  }
  if (str=="bat") {
    short_desc="A huge, black bat";
    msgin="flys in";
    msgout="flys";
  }
  if (str=="wolf") {
    short_desc="A large, grey wolf";
    msgin="trots in";
    msgout="trots";
  }
  form_description = str;
  this_object()->set_short(short_desc);
  this_object()->set_long(short_desc+" that somehow reminds you of "+
                          capitalize(form_owner_name)+".\n");
  this_object()->set_name(short_desc);
  this_object()->set_alias(str);
  this_object()->set_alt_name(form_owner_name);
  return 1;
}

query_interactive() { return 1; }

can_put_and_get() { return; }

realm() { return "NT"; }

/*
  make others that check think we're a player so we can't sneak by
  guards that don't let players walk by, etc. :)
*/
query_npc() { return 0; }
is_player() { return 1; }

heart_beat() {
  object stuff_obj, this_vampire_obj, this_vampires_attacker_obj;
  string attackers_name;
  if (query_attack()) {
    this_vampires_attacker_obj = this_object()->query_attack();
    if (this_vampires_attacker_obj->query_npc()) {
      this_vampire_obj = find_player(lower_case(form_owner_name));
      attackers_name = this_vampires_attacker_obj->query_name();
      tell_room(environment(this_object()),
                "The "+form_description+
                " waivers for a moment, then assumes the shape of "+
                capitalize(form_owner_name)+".\n");
      move_object(this_vampire_obj, environment(this_object()));
      destruct(this_object());
      this_vampire_obj->attack_object(this_vampires_attacker_obj);
    }
    else {
      tell_object(this_vampires_attacker_obj,
                  "You reconsider your thoughts about attacking the "+
                  form_description+" and decide not to.\n");
      this_vampires_attacker_obj->stop_fight();
      this_object()->stop_fight();
    }
  }
  :: heart_beat();
}
