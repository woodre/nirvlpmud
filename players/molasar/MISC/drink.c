
string name, alias, short_desc, long_desc, drink_mess1, drink_mess2, container;
int value, heal, full, strength;

set_name(a) { name = a; }

set_alias(b) { alias = b; }

set_short(c) { short_desc = c; }

set_long(d) { long_desc = d; }

set_drink_mess1(e) { drink_mess1 = e; }

set_drink_mess2(f) { drink_mess2 = f; }

set_heal(g) { heal = g; }

set_strength(h) { strength = h; }

set_container(i) { container = i; }

set_value(j) { value = j; }

query_value() {
   if(full) 
     return 0;
   return value;
}

get() { return 1; }

reset(arg) {
   if(arg) return;
   container = "bottle";
   drink_mess1 = "That hit the spot!\n";
   value = 2;
   full = 1;
}

id(str) {
   if(full)
     return str == "alcohol" || str == name || str == alias;
   return str == container;
}


short() {
   if(full) {
     return short_desc;
   } else
   return "An empty "+container;
}

long() {
   if(full) {
     if(!long_desc) {
       write("A "+name+".\n");
     } else
     write(long_desc);
     return 1;
   } else
   write("An empty "+container+"\n");
}

init() {
   add_action("drink","drink");
}

drink(str) {
   if(!str || !id(str)) { return 0; }
   if(!full) {
     write("You find you are out of that.\n");
     return 1;
   }
   if(!this_player()->drink_alcohol(strength)) {
     say(capitalize(this_player()->query_name())+" spews a "+name+
        " all over you!\n");
     return 1;
   }
   write(drink_mess1);
   say(capitalize(this_player()->query_name())+" "+drink_mess2);
   this_player()->drink_alcohol(strength);
   this_player()->heal_self(heal);
   full = 0;
   return 1;
}

