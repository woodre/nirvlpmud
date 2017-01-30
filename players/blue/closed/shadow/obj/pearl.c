 /*         pearl3_0   - servant controlling object                    */
 /*                       2-19-94                                      */



#define THIS_FILE "/players/blue/closed/shadow/obj/pearl.c"
#define TP this_player()
#define ENVTP environment(this_player())
#define SERVANT_FILE "/players/blue/closed/shadow/obj/testservant.c"
#define TO this_object()
#define CN capitalize(TP->query_name())
#define ENVTO environment(this_object())
#define ENV(x) environment(x)
#define TELROOM(x) tell_room(ENVTO, x)
#define MAX_HP 130
#define TEOWN(x) tell_object(ENVTO, x);

int form, servant_hp;
object servant, mark, master;
string servant_short, master_name;



id(str) {  if(form) return str =="pearl"||str == "pearl_object";
                  return str=="pearl_object";
}

short() {
   string pearl_short;
   if(form) {
      pearl_short = "A Black Pearl";
      if(this_player()&&this_player()==ENVTO)
          pearl_short += " ("+servant_hp+"/"+MAX_HP+")";
   } else pearl_short = 0;
   return pearl_short;
}

long() {
   if(this_player()&&this_player()==ENVTO) {
      write("This is your black pearl.  Type 'info servants' for how"+
        " to use it.\n");
       return 1;
   }
   write("A Black Pearl.  It seems worthless.\n");
   return 1;
}

get() { return 0; }
drop () { return 1; }
query_value() { return 0; }
query_weight() { return 0; }

reset(arg) {

   if(arg) return;

 
   form = 1;
   servant_hp = 130;
   master_name = 0;
   master = 0;
   mark = 0;
   servant_short = "A Shadow Servant";
   set_heart_beat(1);

}

query_auto_load() {
   return THIS_FILE+":"+servant_hp+"#"+master_name+
            "#"+servant_short;
}

init_arg(str) {
   sscanf(str,"%d#%s#%s",servant_hp, master_name, servant_short);
}

heart_beat() {
   if(!master) {
      master = find_player(master_name);
      if(!master) {
         if(servant) destruct(servant);
         destruct(TO);
      }
   }
   if(!form && !servant) {
      TEOWN("Your sevant is gone.\n");
      destruct(TO);
      return 1;
   }
   if(!mark) mark = present("shadow-mark", master);
   if(!mark) {
      if(servant) destruct(servant);
      destruct(TO);
   }
   mark->set_pearl(TO);
}

init() {
   
   add_action("do_come", "come");
   add_action("change_me", "change");
   add_action("name_servant","name");
   add_action("wait_me","wait"); 
   add_action("do_attack","attack");
   add_action("do_guard","guard");
   add_action("command_me","command");

}

change_me() {
   if(form) {
       if(servant && ENV(servant) == ENVTP) {
         form = 0;
         return 1;
      }
      servant = clone_object(SERVANT_FILE);
      servant->set_hp(servant_hp);
      servant->set_short(servant_short);
      servant->set_master_object(ENVTO);
      servant->set_master_name(ENVTO->query_real_name());
      servant->set_mark(mark);
      servant->set_pearl(TO);
      move_object(servant, ENV(ENVTO));
      say(CN+" drops a small black pearl to the ground.\n");
      write("You drop a pearl to the ground.\n");
      tell_room(ENV(ENVTO), "A dark mist forms and a humanoid shape"+
          " appears.\n");
      form = 0;
      mark->set_servant(servant);
      return 1;
   }
   form = 1;
   if(servant) {
      if(present(TP, ENV(servant))) servant->empty_inv();
      write("Your servant turns into a mist, then solidies into a small"+
        " black pearl.\n");
      write("You pick it up.\n");
      say(servant->query_short()+" turns into a mist, then solidies"+
        " into a small black pearl.\n");
      say(CN+" picks it up.\n");
      servant_hp = servant->query_hp();
      destruct(servant);
   }
   return 1;
}

do_guard(str) {
   if(form) return;
   if(!servant->start_guard(str));
   return 1;
}

do_come() {
   if(form) return;
   if(!servant) {
      form = 1;
      return;
   }
   servant->call_me();
   return 1;
}

do_attack(str) {
   if(form) return;
   if(!servant) {
      form = 1;
      return;
   }
   if(!str) {
      write("Usage: 'attack <monster>'.\n");
      return 1;
   }
   servant->start_attack(str);
   return 1;
}

set_master_name(str) {
   master_name = str;
   return 1;
}

tell_hp(num) {
   servant_hp = num;
   return 1;
}

set_shadow_mark(ob) {
   mark = ob;
}

command_me(str) {
   string com, rest, dum;
   string ret, func;
   int n;
   if(!str) return;
   if(form) return;
   if(sizeof(explode(str, " ")) == 1) {
      com = str;
      rest = "0";
   } else {
      sscanf(str, "%s %s", com, rest);
   }
   func = "command_"+ com;
   if(!call_other(servant, func, rest)) {
      write("Your servant looks at you, a bit puzzled.\n");
      return 1;
   }
   return 1;
}

name_servant(str) {
   if(form) return;
   if(!str) {
      write("Usage: 'name <servant name>'.\n");
      return 1;
   }
   if(!servant || !present(servant, ENVTP)) {
      write("Your servant must be present to rename it.\n");
      return 1;
   }
   servant_short = str;
   servant->set_short(str);
   write("Your servant's name is now "+str+".\n");
   return 1; 
}

end_game() {
   if(!form) change_me();
}
