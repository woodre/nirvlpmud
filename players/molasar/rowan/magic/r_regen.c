
/*
 * RING OF REGENERATION (3/19/94)
 * Restores 5 hp every 30 seconds
 * Has AC: 0  TYPE: ring  
 */

#define REG_INTV 30
#define HP 5

int worn, ac;
object next, ob;
string name, type, str_name;

reset(arg) {
   if(arg)
     return;
   type = "ring";
   name = "ring";
   ac = 0;
   str_name = "A Ring of Regeneration";
}

link(ob) { next = ob; }

remove_link(str) {
   if(str == name) {
     ob = next;
     next = 0;
     return ob;
   }
   if(next)
     next = next->remove_link(str);
   return this_object();
}

init() {
   add_action("wear","wear");
   add_action("remove","remove");
}

rec_short() {
   if(next)
     return str_name+", "+call_other(next, "rec_short");
   return str_name;
}

short() { 
   string tmp_short;
   if(this_player()->query_level() > 30) {
     tmp_short = str_name+" < ac "+ac+", "+type+" >";
     if(worn)
        return tmp_short+" (worn)";
     return tmp_short;
   }
   if(worn)
     return str_name+" (worn)";
   return str_name;
}

long() {
  write("A blood red ring.\n");
  write("Written in flowing script around the outsie of the ring:\n");
  write("  Wear me and I shall close your wounds and heal your abrasions.\n");
}

id(str) { return str == "ring"; }

test_type(str) {
   if(str == type)
     return this_object();
   if(next)
     return next->test_type(str);
   return 0;
}

tot_ac() {
   if(next)
     return ac + call_other(next, "tot_ac");
   return ac;
}

query_type() { return "ring"; }

query_value() { return 5001; }

query_worn() { return worn; }

query_name() { return "ring"; }

armor_class() { return 0; }

wear(str) {
   object ob;
   
   if(!id(str))
     return 0;
   if(environment() != this_player()) {
     write("You must get it first!\n");
     return 1;
   }
   if(worn) {
     write("You already wear it!\n");
     return 1;
   }
   next = 0;
   ob = this_player()->wear(this_object());
   if(!ob) {
     call_out("regenerate", REG_INTV);
     worn = 1;
     return 1;
   }
   write("You already have an armor of class "+type+".\n");
   write("Worn armor "+ob->short()+"\n");
   return 1;
}

get() { return 1; }

drop(silently) {
   if(worn) {
     remove_call_out("regenerate");
     this_player()->stop_wearing(name);
     worn = 0;
     if(!silently)
       tell_object(environment(this_object()), "You drop your worn armor.\n");
   }
   return 0;
}

remove(str) {
   if(!id(str)) 
     return 0;
   if(!worn)
     return 0;
   remove_call_out("regenerate");
   this_player()->stop_wearing(name);
   worn = 0;
   return 1;
}

query_weight() { return 1; }

take_off() {
   remove_call_out("regenerate");   
   worn = 0;
   return 1;
}

query_save_flag() { return 1; }

regenerate() {
   if(!living(environment(this_object()))) {
     remove_call_out("regenerate");
     return 1;
   }
   environment(this_object())->heal_self(HP);
   tell_object(environment(this_object()), "Your ring glows softly.\n");
   call_out("regenerate", REG_INTV);
   return 1;
}

