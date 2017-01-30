#include "/players/quicksilver/666/include/std.h"

inherit "obj/weapon.c";

wwrite(str) {
     tell_object(ENVTO, str);
}

wsay(str) {
     int i;
     object ob;
     
     ob = first_inventory(environment(ENVTO));
     while(ob) {
          if(ob != ENVTO) tell_object(ob, str);
          ob = next_inventory(ob);
     }
}
