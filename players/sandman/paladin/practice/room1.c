
/*
 * PRACTICE ROOM 1
 */

#define MASTER "/players/sandman/paladin/practice/master"

reset(arg) {
   if(!arg)
     set_light(1);
}

init() {
   if(this_player() && !this_player()->query_npc())
     MASTER->place_practice_shadow(this_player());
   add_action("summon","summon");
   add_action("west","west");
}

west() {
   clear_room();
   if(this_player()->query_practice_shadow())
     MASTER->remove_practice_shadow(this_player());
   this_player()->move_player("west#players/sandman/paladin/practice/hall");
   return 1;
}

summon(str) {
   MASTER->get_monster(str);
   return 1;
}

short() { return "A practice room"; }

long() {
   write("You are in a practice room.\n");
   write("Here you may fight monsters to test out the different\n");
   write("combat methods and weapon proficiences.\n");
   write("You cannot be killed or gain any experience.\n");
   write("Upon leaving the room you will be fully healed.\n");
   write("Commands:  summon <monster level> <number of monster>\n");
   write("     There is one obvious exit:  west\n");
}

clear_room() {
   object invob, next_invob;

   invob = first_inventory(this_object());
   while(invob) {
     next_invob = next_inventory(invob);
     if(invob->query_npc())
       destruct(invob);
     invob = next_invob;
   }
   return 1;
}

