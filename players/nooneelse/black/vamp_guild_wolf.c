/*
  vamp_guild_wolf.c
*/

#define PERSONALITY_CHANCE 5

#include "/open/ansi.h"
inherit "obj/monster";

string str, str2, master_name, wolf_name, cheat1, cheat2;
int wait_here, time_counter, wolf_muffled, wolf_protecting;
int personality_type; /* 0=affectionate  1=mean 2=perverse */
object obj, obj2;
object master; /* Added by Snow 3/99 */

init() {
  ::init();

  add_action("wolf_do",   wolf_name);
}

/* general commands to wolf */
wolf_do(str) {
  object obj;

  /* in case the player quits & the wolf is left */
   if(!master) {
    say("The "+BOLD+"wolf"+NORM+" looks lost and lopes off looking for "+
        capitalize(master_name)+".\n");
    destruct(this_object());
    return 1;
  }

  if (!str || str=="") return;

  /* was it my master? */
  if (!this_player()) return;
  if(this_player() != master) return;

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
    tell_room(environment(),
      "The "+BOLD+"wolf"+NORM+" seems to nod at "+capitalize(master_name)+
        " and lopes away.\n");
    obj=present("nooneelse@vampire@fangs", master);
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
    say("A "+BOLD+"wolf"+NORM+" named "+capitalize(wolf_name)+" says: "+str2+"\n");
    return 1;
  }

  /* tell wolf to wait here */
  sscanf(str, "wait %s", str2);
  if (str2=="here") {
    say("The "+BOLD+"wolf"+NORM+" pads into a dark area to sit and wait.\n");
    wait_here = 1;
    return 1;
  }

  /* tell wolf to follow me */
  sscanf(str, "follow %s", str2);
  if (str2=="me") {
    say("The "+BOLD+"wolf"+NORM+" pads out of a dark area and stands at "+
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
      write("The "+BOLD+"wolf"+NORM+" growls:  "+str2+" is not here to attack!\n");
    return 1;
  }

  /* stop the attack? */
  if (sscanf(str, "stop %s", str)==1) {
    if (str=="attack") {
      obj=this_object()->query_attack();
     if(obj)
      if (present(obj, environment(this_object()))) {
        obj->stop_fight();
        obj->stop_fight();
        obj->stop_hunter();
      }
      this_object()->stop_fight();
      this_object()->stop_fight();
      this_object()->stop_hunter();
      write("The "+BOLD+"wolf"+NORM+" has stopped fighting/hunting.  However, it's old\n"+
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
      write("The "+BOLD+"wolf"+NORM+" pants:  But I don't need healing right now.\n");
      return 1;
    }
    if(!obj->heal_value()) {
      write("That corpse has no value.\n"); return 1; }
    say(capitalize(master_name)+
        " whistles strangely and points at a corpse.\n");
    heal_self(obj->heal_value());
    destruct(obj);
	say("The "+BOLD+"wolf"+NORM+" excitedly jumps on the "+
	    "corpse and "+BOLD+"RIPS"+NORM+" through its\n"+
        "flesh to get at a vein.  It then sinks its FANGS into the\n"+
		"corpse and greedily "+HIR+"laps up its BLOOD"+NORM+".\n");
    return 1;
  }

  /* tell wolf to attack any aggressive monster it comes near */
  if (str=="protect me") {
    if (wolf_protecting) {
      wolf_protecting=0;
      write("The "+BOLD+"wolf's"+NORM+" protection mode is now "+HIR+"OFF"+NORM+".\n");
    }
    else {
      wolf_protecting=1;
      write("The "+BOLD+"wolf's"+NORM+" protection mode is now "+HIR+"ON"+NORM+".\n");
    }
    return 1;
  }

  /* tell wolf to shut up */
  if (str=="muffle") {
    if (wolf_muffled) {
      wolf_muffled=0;
	   write("The "+BOLD+"wolf"+NORM+" is now "+HIR+"UNMUFFLED"+NORM+".\n");
    }
    else {
      wolf_muffled=1;
	   write("The "+BOLD+"wolf"+NORM+" is now "+HIR+"MUFFLED"+NORM+".\n");
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
    return 1;
  }
  if(master && !present(master, environment())) {
    tell_room(environment(this_object()),
              "The "+BOLD+"wolf"+NORM+" lopes away after "+capitalize(master_name)+".\n");
    move_object(this_object(), environment(master));
    tell_room(environment(master),
              "A "+BOLD+"wolf"+NORM+" lopes in and stands at "+capitalize(master_name)+
              "'s left side.\n");
  }
  return;
}

reset(arg) {
  ::reset(arg);
  if (arg) return;

  wolf_muffled = 1;
  set_name("wolf");
  set_alias("wolf");
  wolf_name="wolf";
  set_level(8);
  set_hp(130);
  if(!present("yellow fangs")) {
    move_object(clone_object("/players/eurale/Vamp/OBJ/wolf_fangs.c"),
      this_object()); }
  init_command("wield yellow fangs");
  set_wc(14);
  set_ac(6);
  set_can_kill(1);
  set_aggressive(0);
  master_name = "null"; 
  enable_commands();
  set_heart_beat(1);
}

query_master_name() { return master_name; }
query_master() { return master; } /* Snow 3/99 */

heart_beat() {
  object wolf_obj;

  if (hit_point < max_hp) hit_point += 3;
  if (hit_point > max_hp) hit_point = max_hp;
   if(environment(this_object())) {
/* Snow 3/99 - make sure wolf has a master */
    if(!master) {
      if(!master_name) { destruct(this_object()); return 1; }
      master = find_player(master_name); }

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
      (query_attack() == master ||
       !this_object()->query_attack()->query_npc())) {
    this_object()->stop_fight();
    this_object()->stop_fight();
    this_object()->stop_hunter();
  }

  time_counter++;
  if (!wolf_muffled) {
    wolf_personality();
  }
/* Snow 3/99 */
  follow();

/* Snow 3/99 */
  if(master && wolf_protecting) {
    if(master->query_attack() && master->query_attack()->query_npc())
      attack_object(master->query_attack()); }

/*   took out this loop.. too long eval happens too often
  - mythos <3-1-1999>
  if (wolf_protecting) {
    obj = first_inventory(environment(this_object()));
    while (obj) {
  if(living(obj)) {
      obj2=obj->query_attack();
     if(obj2)
    if(living(obj2) && obj2->query_real_name()==master_name &&
          obj->query_npc())
        this_object()->attack_object(obj);
      obj=next_inventory(obj);
    }
  }
  }
*/

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
      return capitalize(master_name)+"'s "+BOLD+"wolf"+NORM+" named '"+
             capitalize(wolf_name)+"'";
    else
      return capitalize(master_name)+"'s "+BOLD+"wolf"+NORM;
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
      str2=capitalize(master_name)+"'s "+BOLD+"wolf"+NORM+" named '"+wolf_name+"'";
    else
      str2=capitalize(master_name)+"'s wolf";
  return 1;
}

/* give wolf a new master */
set_master(str) {
  master_name=str;
  master = find_player(master_name);
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
  say("The "+BOLD+"wolf"+NORM+" snarls:  You're not the sort of person I thought you were!\n"+
      "I'm not working for you anymore!\n\n"+
      "With that, the "+BOLD+"wolf"+NORM+" runs away.\n");
   obj=present("vampirefangs", master);
  obj->dismiss_a_wolf();
  destruct(this_object());
  return 1;
}

/* tell wolf to come to me */
summon_wolf() {
  tell_room(environment(this_object()),
           "The "+BOLD+"wolf's"+NORM+" ears stand up for a second.  He scrambles to his feet\n"+
           "and lopes away.\n");
  wait_here = 0;
  follow();
  return 1;
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
        master->query_possessive()+" thigh.\n");
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
        master->query_possessive()+" commands.\n");
      return 1;
    }
    if (i <= 39) {
      say(capitalize(wolf_name)+
          " looks defiantly at "+capitalize(master_name)+
          " and then sort of grins.\n");
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
