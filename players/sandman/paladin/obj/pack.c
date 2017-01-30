

/*
 * Pack for warhorse.c
 */
int weight;

reset(arg) {
   if(arg)
     return;
   weight = 0;
}

id(str) { return str == "pack" || str == "horse_pack"; }

short() { return "A horse pack"; }

long() {
   write("A leather pack strapped to the horse's saddle.\n");
}

query_weight() { return weight; }

add_weight(w) {
   weight += w;
   return 1;
}

can_put_and_get() { return 1; }

