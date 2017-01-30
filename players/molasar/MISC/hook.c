
string rope, me;
object ob, ob1;
int latched;

id(str) { return str == "hook" || str == "grappling hook"; }

get() {
   if(latched) {
     write("You must unlatch the grappling hook first.\n");
     return 0;
   }
   return 1;
}

query_value() { return 20; }

query_weight() { return 1; }

short() {
   if(!rope) return "A grappling hook";
   if(rope && latched) return "A grappling hook with a rope latched to a tree";
   return "A grappling hook with a rope attached";
}

long() {
   write("A three-pronged grappling hook used for scaling obstacles.\n");
  if(rope) {
    write("There is a rope tied to the end of the hook.\n");
    return 1;
  }
  write("There is a small hole at the end of the hook for a rope.\n");
}

init() {
   add_action("throw","throw");
   add_action("untie","untie");
   add_action("unlatch","unlatch");
}

unlatch(str) {
   me = this_player()->query_name();

   if(str == "hook" || str == "grappling hook") {
     if(!latched) {
       write("The grappling hook is not latched onto anything.\n");
       return 1;
     }
     latched = 0;
     ob1->set_latched(0);
     write("You unlatch the grappling hook.\n");
     say(capitalize(me)+" unlatches a grappling hook.\n");
     return 1;
   }
}

throw(str) {
   me = this_player()->query_name();
   ob1 = present("elftree", environment(this_player()));

   if(!str) return 0;
   if(str == "hook" || str == "grappling hook") {
     if(!present(this_object(), this_player())) {
       write("You need to have it first!.\n");
       return 1;
     }
     if(!rope || !ob1) {
       write("You throw the grappling hook in the air.\n");
       write("Unforunatley gravity is working against you.\n");
       write("The grappling hook nicks your leg as it falls to the ground.\n");
       say(capitalize(me)+" throws a grappling hook into the air.\n");
       say("The grappling hook falls back to earth and hits "+capitalize(me)+".\n");
       this_player()->add_hit_point(-random(5));
       move_object(this_object(), environment(this_player()));
       return 1;
     }
   write("The hook latches on to a branch.\n");
   ob1->set_latched(1);
   move_object(this_object(), environment(this_player()));
   latched = 1;
   return 1;
   }
}

tie(str) {
   if(str != "hook" && str != "grappling hook") 
     return 0;
   rope = 1;
   ob = present("rope", this_player());
   destruct(ob);
   return 1;
}

untie(str) {
   me = this_player()->query_name();
   if(str == "rope") {
     if(!rope) {
       write("There is no rope tied to the grappling hook.\n");
       return 1;
     }
     rope = 0;
     move_object(clone_object("obj/rope"), this_player());
     write("You untie the rope from the grappling hook.\n");
     say(capitalize(me)+" unties the rope from the grappling hook.\n");
     return 1;
   }
}

query_rope() { return rope; }

