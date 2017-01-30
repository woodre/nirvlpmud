
/*
 * RING OF INVISIBILITY (3/19/94)
 * Acts as invis spell
 * Has AC: 0  TYPE: ring  WEIGHT: 1
 */

int worn, ac;
object next, ob;
string name, type;

reset(arg) {
   if(arg)
     return;
   type = "ring";
   name = "ring";
   ac = 0;
   name = "Ring of Invisibility";
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
     return name+", "+call_other(next, "rec_short");
   return name;
}

short() { 
   string tmp_short;
   if(this_player()->query_level() > 30) {
     tmp_short = "Ring of Invisibility < ac "+ac+", "+type+" >";
     if(worn)
        return tmp_short+" (worn)";
     return tmp_short;
   }
   if(worn)
     return "A Ring of Invisibility (worn)";
   return "A Ring of Invisibility";
}

long() {
   write("In small letters inside the ring you read:\n");
   write("   The wearer of this ring shall pass unseen to all.\n");
}

id(str) { return str == name || str ==  type; }

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

query_value() { return 700; }

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
     this_player()->set_invs_sp();
     tell_room(environment(this_player()), 
         capitalize(this_player()->query_name())+
         " disappears in a puff of smoke.\n");
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
     this_player()->visible();
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
   this_player()->visible();
   this_player()->stop_wearing(name);
   worn = 0;
   return 1;
}

query_weight() { return 1; }

take_off() {
   this_player()->visible();   
   worn = 0;
   return 1;
}

query_save_flag() { return 1; }

