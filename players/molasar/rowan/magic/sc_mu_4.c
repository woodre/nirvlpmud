
/*
 * SCROLL OF 2 MAGIC-USER SPELLS (3/19/94)
 * --dimension door  Randomly teleport player
 * --death spell     Massive damage to one monster
 */

int door, death;

reset(arg) {
   if(arg)
     return;
   door = 1;
   death = 1;
}

id(str) { return str == "scroll"; }

get() { return 1; }

query_value() {
   if(door && death)
     return 500;
   return 250;
}

short() { return "A scroll of magic-user spells"; }

long() {
   write("A scroll written on fine parchment.\n");
   write("This scroll is empowered with magic-user spells.\n");
   if(door)
     write("--dimension door  Will teleport you to random destination\n");
   if(death)
     write("--death spell     Inflict massive damage on one monster\n");
}

init() {
   add_action("dimension","dimension");
   add_action("death","death");
}

dimension(str) {
   int i;
   object dest;
   dest = allocate(5);
   dest = ({ "/room/church", "/room/shop", "/room/clearing",
             "/players/molasar/rowan/xroads",
             "/players/molasar/rowan/twn_hall" });
   if(!str || str != "door" || !door)
     return;
   if(environment(this_player())->realm() == "NT") {
     write("You read from the scroll yet nothing happens.\n");
     return 1;
   }
   i = random(5);
   say(capitalize(this_player()->query_name())+" reads from a scroll.\n"+
       capitalize(this_player()->query_name())+" disappears in a puff "+
       "of smoke.\n");
   write("You find yourself somewhere else.\n");
   move_object(this_player(), dest[i]);
   this_player()->look();
   door = 0;
   if(!death)
     destruct(this_object());
   return 1;
}

death(str) {
   int mag, dam, i;
   object target;
   string who;

   if(!death)
     return;
   if(sscanf(str, "spell %s", who) != 1) {
     write("USAGE: death spell <target>\n");
     return 1;
   }
   target = present(who, environment(this_player()));
   if(!target) {
     write(capitalize(who)+" is not here.\n");
     return 1;
   }
   if(!target->query_npc()) {
     write("You cannot use this spell against players.\n");
     return 1;
   }
   mag = this_player()->query_attrib("mag");
   dam = 2*mag;
   say(capitalize(this_player()->query_name())+" reads from a scroll.\n");
   tell_room(environment(this_player()), capitalize(who)+" doubles over "+
       "in pain.\n");
   i = 0;
   while(i < 2) {
     if(target)
       target->hit_player(dam);
     i++;
   }
   death = 0;
   if(!door)
     destruct(this_object());
   return 1;
}

