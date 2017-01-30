
/*
 * Full Platemail Armor (3/17/94)
 * Cannot wear any other type of armor except for shield.
 * AC 7  WEIGHT 4
 */

int worn, ac;
object worn_by;
object next;
string name, short_desc;
string type;

reset(arg) {
    if(arg)
	return;
    ac = 7;
    name = "armor";
    type = "armor";
    short_desc = "A suit of full platemail";
}

link(ob) { next = ob; }

remove_link(str) {
   object ob;

   if(str == name) {
     ob = next;
     next = 0;
     return ob;
   }
   if(next)
     next = call_other(next, "remove_link", str);
   return this_object();
}

init() {
    add_action("wear","wear");
    add_action("remove","remove");
    add_action("take_off","unwear");
}

rec_short() {
    if(next)
      return name+", "+call_other(next, "rec_short");
    return name;
}

short() {
   string tmp_short;
       
   if(!short_desc)
     return 0;
   if(this_player()->query_level() > 30) {
     tmp_short = short_desc+"  < ac "+ac+", "+type+" >";
     if(worn)
       return tmp_short+" (worn)";
     return tmp_short;
   }
   if(worn)
     return short_desc+" (worn)";
   return short_desc;
}

long() { 
   write("The suit is comprised of a helmet, greaves, gauntlets\n");
   write("chest protector, and bracers.\n");
   write("A large hawk is imprinted upon the chest plate. Clutched\n");
   write("in one of its claws is a sword, the other holds a\n");
   write("red rose in full bloom.\n");
}

id(str) { return str == "armor" || str == "plate" || str == "platemail"; }

test_type(str) {
    if(str != "shield")
      return this_object();
    if(next)
      return next->test_type(str);
    return 0;
}

tot_ac() {
    if(next)
      return ac+next->tot_ac();
    return ac;
}

query_type() { return "armor"; }

query_value() { return 10000; }

query_worn() { return worn; }

query_name() { return name; }

armor_class() { return ac; }

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
      worn_by = this_player();
      worn = 1;
      return 1;
    }
    write("You already have an armor of class "+type+".\n");
    write("Worn armor "+ob->short()+".\n");
    return 1;
}

get() { return 1; }

drop(silently) {
   if(worn) {
     worn_by->stop_wearing(name);
     worn = 0;
     worn_by = 0;
     if(!silently)
       tell_object(environment(this_object()),"You drop your worn armor.\n");
   }
   return 0;
}

remove(str) {
   if(!id(str))
     return 0;
   if(!worn) 
     return 0;
   worn_by->stop_wearing(name);
   worn_by = 0;
   worn = 0;
   return 1;
}

query_weight() { return 4; }

take_off() {
   worn_by = this_player();
   worn_by = 0;
   worn = 0;
   return 1;
}

query_save_flag() { return 1; }
