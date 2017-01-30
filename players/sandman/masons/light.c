

int start_time;

reset(arg) {
   if(!arg)
     set_light(1);
   start_time = time();
   set_heart_beat(1);
}

id(str) { return str == "light" || str == "fire"; }

short() { return "A small magical fire"; }

long() {
   write("A small magical fire.\n");
}

heart_beat() {
   if(time() < start_time + 180) {
     set_light(1);
     return 1;
   } else
   set_light(-1);
   say("The small magical fire goes dark.\n");
   destruct(this_object());
   return 1;
}

