 /***                 servant3.0 for the SHADOW guild                     ***/
 /***                           2-19-94                                   ***/

inherit "obj/monster";

#define TP this_player()
#define TO this_object()
#define ENVTP environment(this_player())
#define ENVTO environment(this_object())
#define ENV(x) environment(x)
#define CN capitalize(TP->query_name())
#define TELROOM(x) tell_room(ENVTO, x)
#define CALLCOST 15
#define GUARDCOST 30


object master, guard, pearl, thief, mark;
string master_name;
int follow, warned;

reset(int arg) {
  ::reset(arg);
   if(arg) return;
   set_level(8);
   set_hp(130);
   set_ac(4);
   set_wc(12);
   set_name("servant");
   set_alias("guild_pet");
   set_short("A servant");
   set_long("You can barely make out its form in its master's sh"+
                "adow.  It waits patiently.\n");
   guard = 0;
   follow = 1;
   warned = 0;
}


short() {
   ::short();
   if(TP&&TP == master) 
      return short_desc +" ("+hit_point+"/"+max_hp+")";
   if(guard) return short_desc + ", guarding "+guard->short();
   return short_desc;
}

heart_beat() {
   ::heart_beat();
   if(!pearl) destruct(TO);
   pearl->tell_hp(hit_point);
   if(!master) {
      master = find_player(master_name);
      if(!master) {
         TELROOM(short_desc + " dissloves into the darkness.\n");
         destruct(this_object());
      }
   }
   if(follow && ENVTO != ENV(master)) {
      TELROOM(short_desc +" disappears.\n");
      move_object(TO, ENV(master));
      TELROOM(short_desc +" materializes.\n");
   }
   if(guard) {
      thief = guard->query_attack();
      if(thief) {
         warn_thief();
           if(!present("shadow-mark", thief)&&!TO->query_attack()) {
            guard->stop_fight();
            thief->stop_fight();
            thief->attack_object(TO);
             attack_object(thief);         
             guard->stop_fight();
         }
      }
   }
}


command_give(str) {
   object ob;
   int tran;
   if(!str) return;
   ob = present(str, TO);
   if(!ob) {
      reply("I don't have a "+str+".\n");
      return 1;
   }
   if(!present(TP, ENVTO)) {
      reply("You aren't here!!!\n");
      return 1;
   }
   tran = transfer(ob, TP);
   if(tran == 0) {
      tell_room(ENVTO, short_desc +" gives "+ ob->short() + " to "+ CN +".\n");
      return 1;
   }
   if(tran == 1) {
      reply("You can't carry that much!\n");
      return 1;
   }
   write("Undefine error.\n");
   return 1;
}

command_look(str) {
   object here, ob;
   if(str) {
      ob = present(str, ENVTO);
      if(ob) write(ob->long());
      else reply("That is not there.\n");
      return 1;
   }
   here = ENVTO;
   write(here->long());
   ob = first_inventory(here);
   while(ob) {
      if(ob->short()) write(ob->short() +"\n");
      ob = next_inventory(ob);
   }
   return 1;
}

valid_direction(str) {
  return (str == "north"  || str == "south"  ||  str == "east"  ||
          str == "west"   || str == "gate"   || str == "down"   || 
          str == "up"     || str == "enter" );
}

command_move(str) {
   object old_room;
   old_room = ENVTO;
   if(!valid_direction(str)) {
      reply("I can't go that way.\n");
      return 1;
   }
   command(str, TO);
   if(ENVTO->realm() == "NT") {
      move_object(TO, old_room);
      reply("I can't go there.\n");
      return 1;
   }
   if(ENVTO != ENVTP) {
      follow = 0;
      command_look();
   }
   return 1;
}

command_get(str) {
   object ob;
   ob = present(str, ENVTO);
   if(!ob) {
      reply("There is no "+str+" here.\n");
      return 0;
   }
   if(!ob->get()) {
      reply("I can't take that!!!\n");
      return 0;
   }
   if(!add_weight(ob->query_weight())) {
      reply("That is too heavy.\n");
      return 0;
   }
   move_object(ob, TO);
   if(ENVTO != TP) write("Your servant takes: "+ob->short() +"\n");
   tell_room(ENVTO, short_desc+" takes: "+ob->short()+".\n");
   return 1;
}


start_attack(str) {
   object att;
   if(TO->query_attack()) {
      reply("I can only attack one thing at a time.");
      return 1;
   }
   att = present(str, ENVTO);
   if(!att) {
      reply("There isn't a "+str+" here.");
      return 1;
   }
   if(att->is_player()) {
      reply("I can't attack a player.");
      return 1;
   }
   if(att->is_living()) {
      reply("That's not alive.");
      return 1;
   }
   write("Your servant nods.n");
   write("Your servant begins to pound into "+att->short()+"n");
   say(short()+" begins to pound into "+att->short()+".n");
   TO->attack_object(att);
   if(!att->query_attack()) att->attack_object(TO);
   return 1;
}

start_guard(str) {
   if(guard) {
      reply("I'm already guarding "+guard->short()+".");
      return 1;
   }
   guard = present(str, ENVTO);
   if(!guard) {
      reply("There isn't a "+str+" here.");
      return 1;
   }
   if(guard->is_player()) {
      reply("I can't guard a player.");
      return 1;
   }
   if(!living(guard)) {
      reply("That's not alive.");
      return 1;
   }
   if(guard->query_attack()) {
      reply("I can't guard a monster thats already being attacked.");
      return 1;
   }
   if(!mark->less_pts(GUARDCOST)) return 1;
   write("Your servant nods and stands at attention.\n");
   say(short_desc +" starts to guard "+guard->short()+".\n");
   follow = 0;
   return 1;
}
 
call_me() {
   if(ENVTO != ENV(master) && !mark->less_pts(CALLCOST)) return 1;
   follow = 1;
   guard = 0;
   if(ENVTO == ENV(master)) {
      write("Your servant stands at attention.\n");
      say(short_desc +" stands at attention.\n");
      return 1;
   }
   return 1;
}

command_wait(str) {
   follow = 0;
   write("Your servant nods.\n");
   say(short_desc +" nods.\n");
   return 1;
}

warn_thief() {
   if(warned) return 1;
   if(thief) tell_object(master, "Your servant tells you: "+
     capitalize(thief->query_name())+" is trying to kill the monster "+
     "I'm guarding.\n");
   if(TO->query_attack()) 
      tell_object(master, "Your servant tells you: I'm attacking "+
        capitalize((TO->query_attack())->query_name())+"!.\n");
   warned = 1;
   return 1;
}
set_mark(str) {
   mark = str;
   return 1;
}

set_master_object(object ob) {
   set_heart_beat(1);
   master = ob;
   return 1;
}

set_master_name(str) {
   master_name = str;
   return 1;
}

query_master_name() {
   return master_name;
}


query_master() {
   return master;
}

name_servant(string str) {
   if(!str || str == " ") return 1;
   set_short(str);
}

query_pet() {
   return 1;
}

set_pearl(ob) {
   pearl = ob;
   return 1;
}

reply(str) {
   tell_object(TP, "Your servant tells you: "+str+"\n");
   if(ENVTO == ENVTP) 
      say(short_desc + " says some thing in a dark language that you fail "+
          "to understand.\n", TP);
   return 1;
}

empty_inv() {
   object ob, temp;
   ob = first_inventory(TO);
   while(ob) {
      temp = next_inventory(ob);
      transfer(ob, master);
      if(ENV(ob) != master) {
         move_object(ob, ENVTO);
         tell_room(ENVTO, short_desc+" drops: "+ob->short()+"\n");
      } else {
         tell_room(ENVTO, short_desc+" give "+ob->short()+" to "+CN+".\n");
      }
      ob = temp;
   }
   return 1;
}

query_short() {
   return short_desc;
}

what_i_see() {
   object here, ob;
   here = ENVTO;
   write(here->long());
   ob = first_inventory(here);
   while(ob) {
      write(ob->short());
      write(".\n");
      ob = next_inventory(ob);
   }
   return 1;
}

take_object(str) {
   object ob;
write("Caught string: "+str+"\n");
   ob = present(str, ENVTO);
   if(!ob) return "That is not there.\n";
   if(!ob->get()) return "Your servant can't take that!!!\n";
   if(!add_weight(ob->query_weight())) return "That is too heavy.\n";
    tell_room(ENVTO, short_desc+" takes: "+ob->short()+".\n");
   return "1";
}
