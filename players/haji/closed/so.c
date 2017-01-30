object summonee, prev_room;
object zombie, me;
string myname;



id(str) { return str == "aura"; }

reset(arg) {
tell_object(this_player(),"Your aura shimmers with power.\n");
   if (arg) return;

   me = this_player();
   if (me) myname = call_other(me, "query_name");
}

short() {
      return "aura of power";
}
long() {
   write("The aura surrounding "+myname+" glows with a malevolence that strikes fear into you!\n");
}

init_arg(arg) {
   me = this_player();
   myname = call_other(me, "query_name");
   write("*** You have become more powerful, "+myname+"!\n");
}

drop() { return 1; }

get() { return 1; }

init() {


    if(call_other(this_player(),"query_real_name",0)=="haji") {
   add_action("gohome"); add_verb("h");
   add_action("message"); add_verb("message");
   add_action("ghost","ghost");
   add_action("find"); add_verb("find");
   add_action("summon"); add_verb("fetch");
   add_action("sendback"); add_verb("sendback");
   add_action("pocket"); add_verb("inside");
   add_action("into"); add_verb("into");
   add_action("outone"); add_verb("outone");
   add_action("hps"); add_verb("hps");
   add_action("gender"); add_verb("gender");
   add_action("soothe"); add_verb("soothe");
   add_action("idle"); add_verb("idle");
   add_action("force"); add_verb("make");
   add_action("emoteall"); add_verb("emall");
   add_action("emota"); add_verb("echo");
   add_action("resethere"); add_verb("rh");
   add_action("holeto"); add_verb("holeto");
   add_action("z"); add_verb("zombie");
   add_action("orderz"); add_verb("orderz");
   add_action("unghost"); add_verb("unghost");
 }
}

find(str) {
   object ob;

   if (!str) {
      write("find <name>\n");
      return 1;
   }

   ob = find_player(str);
   if (ob) {
      write("Player:\n");
      write(call_other(ob, "look") + "\n");
      return 1;
   } 

   ob = find_living(str);
   if (ob) {
      write("Living:\n");
      write( call_other(environment(ob), "long")+"\n");
      return 1;
   }
   ob = find_object(str);
   if (ob) {
      write("Object:\n");
      write( call_other(environment(ob), "long")+"\n");
      return 1;
   }
   return 0;
}

summon(str) {
   string a_msg;

   summonee = find_player(str);
   if (!summonee)
      summonee = find_living(str);
   if (!summonee) {
      write("That person/thing is not in this world.\n");
      return 1;

   }
   tell_object(summonee, "You have been summoned...\n");
   a_msg = call_other(summonee, "query_mmgin", 0);
   if (!a_msg)
      a_msg = call_other(summonee, "query_name") + " appears on command.\n";
   tell_room(environment(me), a_msg);
   prev_room = environment(summonee);
   move_object(summonee, environment(me));
   tell_room(prev_room, call_other(summonee, "query_name") + " got bored with you.\n");
   return 1;
}

sendback() {

   if (!prev_room) {
      write("No where to send them!\n");
      return 1;
   }
   move_object(summonee, prev_room);
   tell_room(prev_room, call_other(summonee, "query_name")+
   " appears in a flash of light!\n");
   tell_room(environment(me), call_other(summonee, "query_name")+
   " disappears!\n");
   summonee = 0; prev_room = 0;
   return 1;
}

emoteall(str) {
   if (!str) {
      write("emoteall needs a string to emote.\n");
      return 1;
   }
   shout(str+"\n");
   write("all see: " + str + "\n");
   return 1;
}

emota(str) {
   if (!str) {
      write("echo needs a string to use.\n");
      return 1;
   }
   say(str+"\n");
   write("You echo: "+str+"\n");
   return 1;
}

into(str) {
object ob;

   if (!str) {
      write("into <what/who>\n");
      return 1;
   } 
   ob = find_living(str);
   if (!ob) {
      ob = present(str);
   }
   if (!ob) {
      write("Player/Object not found!\n");
      return 1;
   }
   say(myname + " turns into a vapor and disappears!\n");
   move_object(me, ob);
   call_other(me, "look");
   return 1;
}

pocket(str) {
string who, where;
object ob;

   if (!str) {
      write("pocket <who> <where>\n");
      return 1;
   } 

   if (sscanf(str, "%s %s", who, where) == 2) {
      ob = find_living(lower_case(who));

      tell_room(environment(ob), capitalize(who) + 
      " shrinks out of existence!\n");
      move_object(ob, find_living(where));
      return 1;
   }
   write("pocket <who> <where>\n");
   return 1;
}

outone(str) {
object whereto;

   whereto = environment(environment(me));
   if (!whereto) {
      write("You cannot step out from here!\n");
      return 1;
   }

   tell_room(environment(me), myname + " steps out one dimension!\n");
   move_object(me, environment(environment(this_player())));
   call_other(me, "look");
   tell_room(environment(me), myname+" expands out from another dimension!\n");
   return 1;
}

hps(str) {
   object ob;
   int hitpoints;

   if (!str) {
      write("hps <name>\n");
      return 1;
   }
   ob = find_player(str);

   if (!ob)
      ob = find_living(str);

   if (!ob)
      ob = present(str);

   if (!ob) {
      write("There is no name/thing.\n");
      return 1;
   }
   hitpoints = call_other(ob, "query_hp");
   write(capitalize(str) + ": " + hitpoints + " HPs.\n");
   return 1;
}

gender(str) {
   object targ;
   string who, what;

   if (!str) {
      write("gender <who> <gender>\n");
      return 1;
   } 
   if (sscanf(str, "%s %s", who, what) == 2) {
      targ = find_living(who);
      call_other(targ, "set_gender", what);
   } else 
      write("gender <who> <gender>\n");
   return 1;
}

soothe(str) {
   object who;

   if (!str) {
      write("soothe <who>\n");
      return 1;
   }

   who = present(str, environment(me) );
   if (!who)  {
      write("I do not see any " + str + ".\n");
      return 1;
   }

   if (!living(who)) {
      write("How can you soothe something that is not alive?\n");
      return 1;
   }

   write("You soothe " + str + ".\n");
   say(myname + " soothes " + str + ".\n");
   call_other(who, "stop_fight");
   call_other(me, "stop_fight");

   call_other(who, "stop_fight");
   call_other(me, "stop_fight");

   return 1;

}

idle(str) {
object w;

   if (!str) {
      write("idle <who>\n");
      return 1;
   }

   w = find_living(str);
   if (!w) {
      write("There is no "+str+"\n");
      return 1;
   } else {
      write(str+" :"+query_idle(w)+"\n");
      return 1;
   }
}

force(str) {
   object targ;
   string who, what;

   if (!str) {
      write("force <who> <what>\n");
      return 1;
   }
   if (sscanf(str, "%s %s", who, what) == 2) {
      targ  = find_living(who);
      command(what, targ);
      return 1;
   }
}


resethere(str) {
int n;

   n = call_other(environment(me), "reset", 0);
   write("Ok - got "+n+"\n");
   return 1;
}

holeto(str) {
object hole;

   hole = clone_object("players/joseff/objs/spacehole");
   if (!str)
      str = "players/joseff/workroom";

   call_other(hole, "set_to", str);
   move_object(hole, environment(me));
   write("You make a hole to "+str+".\n");
   say(myname + " creates a hole in the fabric of space here!\n");
   return 1;
}

z(str) {
string name;
object corpse_ob, ob;
string s1;

  if (zombie) { 
     write("You already have a zombie.\n"); 
     return 1; 
  }
  corpse_ob = present("corpse", environment(me));
  if(!corpse_ob) {
   FAIL("no corpse");
    return 1;
  }
  str = call_other(corpse_ob,"short",0);
  if(sscanf(str,"%sorpse of %s", s1, name) == 2) s1 = 0; 
  else if(sscanf(str,"%sremains of %s", s1, name) == 2) s1 = 0; 
  else if(sscanf(str,"%sbody of %s", s1, name) != 2) {
    write("There is somthing wrong with the corpse!\n");
    FAIL(); return 1;
  }


  zombie = clone_object("players/diablo/closed/z");
  ob = first_inventory(corpse_ob);
  while(ob) {
    object tob;
    tob = next_inventory(ob);
    move_object(ob, zombie);
    ob = tob;
  }
  destruct(corpse_ob);
  call_other(zombie, "set_name", "zombie");
  call_other(zombie, "set_alias", "zombie of "+lower_case(name));
  call_other(zombie, "set_short", "The zombie of "+name);
  call_other(zombie, "set_long", "The zombies eye seem to follow you!\n");
  call_other(zombie, "set_level", 19);
  call_other(zombie, "set_hp", 700);
  call_other(zombie, "set_al", -500);
  call_other(zombie, "set_wc", 19);
  call_other(zombie, "set_pobj", me);
  move_object(zombie, environment(me));
  say(myname + " chants in a low murmur and a corpse raises from the dead!\n");
  tell_room(environment(zombie),"The corpse of "+name+" rises as a zombie!\n");
  return 1;
}

FAIL(str) {
   write("Not Ok.\n");
   write("was: "+str+"\n");
   say(myname+" chants in a low murmur.\n");
}

orderz(str) {
object ob;

   if (!zombie) {
      write("You have none!\n");
      return 1;
   }

   call_other(zombie, "init_command", str);
   write("You order your zombie to: "+str+".\n");
   say(myname+" mumbles to himself.\n");
   return 1;
}


unghost(str) {
string s1, s2, whostr;
object who;

   if (!str) {
      write("unghost <who>\n");
      return 1;
   }
   if (sscanf(str, "ghost of %s", s1) != 1)
      whostr = "ghost of "+lower_case(str);
   else
     whostr = lower_case(str);

   who = present(whostr, environment(me));
   if (!who) {
      write("They are not present in this room.\n");
      return 1;
   }
   write("You restore "+str+".\n");
   say( myname + " chants in a low murmur ...\n");
   say("The "+str+" is restored to life!\n");
   call_other(who, "remove_ghost");
   return 1;
}

message(str) {
object ob;

   if (!str) {
      write("message <str>\n");
      return 1;
   }

   ob = clone_object("players/joseff/objs/message");
   call_other(ob, "set_mess", str);
   call_other(ob, "set_max", 180);
   move_object(ob, environment(me));
   call_other(ob, "start");
   write("You leave a message here ...\n");
   say(myname+" draws fiery letters in the air that stay there!\n");
   return 1;
}

gohome(str) {

   move_object( this_player(), "players/joseff/workroom");
   return 1;
}
ghost(str) {
string s1, s2, whostr;
object who;

   if (!str) {
      write("unghost <who>\n");
      return 1;
   }
   if (sscanf(str, "ghost of %s", s1) != 1)
      whostr = "ghost of "+lower_case(str);
   else
     whostr = lower_case(str);

   who = present(whostr, environment(me));
   if (!who) {
      write("They are not present in this room.\n");
      return 1;
   }
   write("You restore "+str+".\n");
   say( myname + " chants in a low murmur ...\n");
   say("The "+str+" is restored to life!\n");
   call_other(who, "second_life");
   return 1;
}

