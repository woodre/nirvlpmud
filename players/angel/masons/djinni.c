
id(str) { return str == "djinni"; }

int start_time;
string owner;

reset(arg) {
   if(!arg) 
     start_time = time();
   set_heart_beat(1);
}

set_owner(ow) { owner = ow; }

query_owner() { return owner; }

heart_beat() {
   if(time() > start_time + 300) {
     say("The Djinni gets tired of waiting and leaves.\n");
     destruct(this_object());
     return 1;
   }
}

short() { return "A powerful Djinni"; }

long() {
  write("A eight foot tall Djinni who glares at you as you look at him.\n");
}

init() {
   if(this_player()->query_real_name() != owner) {
     write("The Djinni is not yours to control.\n");
     return 1;
   }
   add_action("transfer","transfer");
}

transfer(str) {
   object ob, dest;
   string who, what;
   int val;

   if(!str || sscanf(str, "%s to %s", what, who) != 2) {
     write("Useage:  transfer <object> to <player>\n");
     return 1;
   }
   ob = present(what, this_player());
   if(what == "hole" || what == "portable hole")
  {
     write("The djinni cannot move such a object.\n");
    return 1;
   }
   if(!ob) {
     write("You do not have a "+what+".\n");
     return 1;
   }
   if(!find_player(who)) {
     write(capitalize(who)+" is not on.\n");
     return 1;
   }
   dest = environment(find_player(who));
   val = ob->query_value();
   val = val/10;
   if(this_player()->query_money() < val) {
     write("You do not have enough money.\n");
     return 1;
   }
   write("The Djinni takes the "+what+" and "+val+" gold coins and leaves.\n");
   say("The Djinni leaves.\n");
   move_object(this_object(), dest);
   tell_room(dest, "A Djinni arrives.\n");
   tell_room(dest,
       "The Djinni hands "+capitalize(who)+" a "+what+" and leaves.\n");
   move_object(ob, find_player(who));
   this_player()->add_money(-val);
   destruct(this_object());
   return 1;
}

