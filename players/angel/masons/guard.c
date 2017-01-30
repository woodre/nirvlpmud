
int start_time, follow;
string owner;

reset(arg) {
   if(!arg)
     start_time = time();
   set_heart_beat(1);
}

id(str) { return str == "guardian" || str == "guardian demon" || str == "demon"; }

set_owner(ow) { owner = ow; }

query_owner() { return owner; }

init() {
   add_action("not","kill");
   add_action("not","fireball",2);
   add_action("not","shock",2);
   add_action("not","missile", 2);
   add_action("not","harm");
   add_action("dismiss","dismiss");
   add_action("follow","follow");
}

follow() {
   if(this_player()->query_real_name() != owner) {
     write("The Guardian Demon glares at you!\n");
     return 1;
   }
   if(follow == 1) {
     write("The Guardian will not follow you now.\n");
     follow = 0;
     return 1;
   }
   write("The Guardian will follow you.\n");
   follow = 1;
   return 1;
}

short() { return "A large guardian demon"; }

long() {
   write("A very large and impressive demon placed here by "+
         capitalize(owner)+".\n");
}

not() {
   string me;
   me = this_player()->query_real_name();

   if(this_player()->query_real_name() != owner) {
   write("The guardian lifts his hands and stops your attack.\n");
   write("The guardian says:  This monster belongs to "+capitalize(owner)+".\n");
   if(find_player(owner)) {
     tell_object(find_player(owner),
       "Your Guardian tells you: "+capitalize(me)+" tried to attack your "+
       "monster.\n");
   }
   return 1;
   }
}

dismiss(str) {
   if(!id(str)) {
     write("Dismiss what?\n");
     return 1;
   }
   if(this_player()->query_real_name() != owner) {
     write("The guardian is not yours to dismiss!\n");
     return 1;
   }
   write("You dismiss your guardian servant.\n");
   say(capitalize(this_player()->query_name())+" waves a hand and the "+
      "guardian demon disappears.\n");
   destruct(this_object());
   return 1;
}

heart_beat() {
   if(time() > start_time + 600) {
    if(find_player(owner)) {
     tell_object(find_player(owner),
       "Your Guardian tells you:  Your lease on my services has run out.\n");
    }
    say("The guardian demon disappears in a puff of smoke.\n");
    destruct(this_object());
    return 1;
   }
   if(follow) {
     if(!present(this_object(), environment(find_player(owner))) &&
       find_player(owner)) {
       move_object(this_object(), environment(find_player(owner)));
       say("A Guardian demon arrives.\n");
       return 1;
     }
   }
}

