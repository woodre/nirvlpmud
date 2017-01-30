
int worn, ac;
object worn_by, next, ob;

id(str) { return str == "helm" || str == "helmet"; }

query_name() { return "helm of intelligence"; }

reset(arg) {
   if(arg)
     return;
   worn = 0;
}

short() {
   if(worn) return "A golden helmet (worn)";
   return "A golden helmet";
}

long() {
   write("A helmet which radiates some kind of magical property.\n");
}

init() {
   add_action("wear","wear");
}

wear(str) {
   if(!id(str)) return 0;
   if(environment() != this_player()) {
     write("You must get it first!\n");
     return 1;
   }
   if(worn) {
     write("You already wear it.\n");
     return 1;
   }
   worn_by = this_player();
   next = 0;
   worn = 1;
   ob = this_player()->wear(this_object());
   if(worn_by->query_attrib("mag") < 19) 
   worn_by->raise_magic_aptitude(2);
   return 1;
}

drop(silently) {
   if(worn) {
     worn_by->stop_wearing("helm of intelligence");
     worn_by->raise_magic_aptitude(-2);
     worn = 0;
     worn_by = 0;
     if(!silently)
       write("You drop your worn armor.\n");
     }
   return 0;
}

query_value() { return 1000; }

get() { return 1; }

query_weight() { return 1; }

armor_class() { return -2; }

query_worn() { return worn; }

query_type() { return "helmet"; }

tot_ac() {
   if(next)
     return -2 + call_other(next, "tot_ac");
   return -2;
}

test_type(str) {
   if(str == "helmet") return this_object();
   if(next) next->test_type(str);
   return 0;
}

remove_link(str) {
   object ob;
   if(str == "helm of intelligence") {
     ob = next;
     next = 0;
     return ob;
   }
   if(next) next = next->remove_link(str);
   return this_object();
}

link(ob) { next = ob; }

