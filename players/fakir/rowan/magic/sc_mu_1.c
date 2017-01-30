

/*
 * SCROLL OF 2 MAGIC-USER SPELLS (3/19/94)
 * --fireball    Damage to all monsters in room dam = mag + random(mag)
 * --detect invisiblity  Shows all invisible players
 */

int fire, invis;

reset(arg) {
   if(arg)
     return 1;
   fire = 1;
   invis = 1;
}

id(str) { return str == "scroll"; }

get() { return 1; }

query_value() {
   if(fire && invis)
      return 800;
   return 400;
}

short() { return "A scroll of magic-user spells"; }

long() {
   write("A scroll made of fine parchment.\n");
   write("This is a scroll of magic-user spells.\n");
   if(fire)
     write("--cast fireball        Explode fireball, damaging all "+
           "monsters in the room.\n");
   if(invis)
     write("--detect invisibility  Show invisible players.\n");
}

init() {
   add_action("cast","cast");
   add_action("detect","detect");
}

cast(str) {
   int mag, dam;
   object invob, next_invob;
   if(!str || str != "fireball" || !fire)
     return;
   mag = this_player()->query_attrib("mag");
   dam = mag + random(mag);
   invob = first_inventory(environment(this_player()));
   say(capitalize(this_player()->query_name())+" reads from a scroll.\n");
   tell_room(environment(this_player()), "A fireball explodes in the room.\n");
   while(invob) {
     next_invob = next_inventory(invob);
     if(invob->query_npc())
       invob->hit_player(dam);
     invob = next_invob;
   }
   fire = 0;
   if(!invis)
     destruct(this_object());
   return 1;
}

detect(str) {
   object list;
   int i;

   if(!str || str != "invisibility" || !invis)
     return;
   list = users();
   write("Invisible Players Logged On:\n");
   write("=============================================================\n");
   for(i=0; i < sizeof(list); i++) {
      if(list[i]->query_invis() && list[i]->query_level() < 21)
        write(list[i]->query_real_name()+"\n");
   }
   write("=============================================================\n"); 
   invis = 0;
   if(!fire)
     destruct(this_object());
   return 1;
}

