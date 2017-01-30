
int start_time;

id(str) { return str == "curse" || str == "blindness"; }

short() { return "Temporary blindness"; }

long() {
   write("You shouldn't be able to look at this.\n");
}

drop() { return 1; }

query_auto_load() {
   return "players/molasar/MAGIC/sight_curse:"+start_time;
}

init_arg(str) {
   sscanf(str, "%d", start_time);
   set_light(-1);
}

start(ob) {
   move_object(this_object(), ob);
   start_time = time();
   set_light(-1);
   tell_object(ob, "You feel a stinging in your eyes.\n");
}

init() {
   add_action("blind","look");
   add_action("blind","l");
}

blind() {
   if(time() < start_time + 200) {
     write("Your eyes sting too much to open them.\n");
     say(capitalize(this_player()->query_name())+" fumbles about.\n");
     return 1;
   } else {
     set_light(1);
     destruct(this_object());
     return 0;
   }
}

