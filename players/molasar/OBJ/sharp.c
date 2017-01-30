
string what, me, old_short;
int old_class, start_time;
object ob;

id(str) { return str == "sharp" || str == "sharpener"; }

get() { return 1; }

query_value() { return 1000; }

short() { return "A weapon sharpener"; }

long() { 
   write("A device used to sharpen your weapons.\n");
}

init() { 
   add_action("sharpen","sharpen");
}

sharpen(str) {
   me = this_player()->query_real_name();

   if(!str || sscanf(str, "%s", what) != 1) {
     write("Sharpen what?\n");
     return 1;
   }
   ob = present(what, this_player());
   if(!ob) {
     write("You do not have a "+what+".\n");
     return 1;
   }
   old_class = ob->weapon_class();
   old_short = ob->short();
   start_time = time();
   ob->set_class(old_class+2);
   if(ob->wielded() == 1) {
     find_player(me)->set_wc(old_class+2);
   }
   write("You sharpen the "+what+".\n");
   write("The "+what+" begins to glow.\n");
   say("The "+what+" starts to glow.\n");
   say(capitalize(this_player()->query_name())+" sharpens a "+what+".\n");
   ob->set_short(old_short+" (glowing)");
   set_heart_beat(1);
   return 1;
}

heart_beat() {
   if(time() > start_time + 30) {
     say("The "+what+" stops glowing.\n");
     ob->set_class(old_class);
     ob->set_short(old_short);
     if(ob->wielded() == 1) {
       find_player(me)->set_wc(old_class);
     }
     destruct(this_object());
     set_heart_beat(0);
     return 1;
   }
}

