
/*
 * MEETING CHAMBER (4/30/94)
 * Players must battle the spirit of Lord Ariand here.
 * To find the jar the woman must be unshackled in 
 * /players/molasar/rowan/drake/mansion/cell2
 */

realm() { return "NT"; }

int guard, jar, found;

reset(arg) {
   if(!arg) 
     set_light(1);
   guard = 0;
   jar = 0;
   found = 0;
}

short() { return "The Audience Chamber of Drakeshore"; }

id(str) { return str == "throne"; }

long(str) {
   if(str == "throne") {
     write("The throne is a marvellous example of master craftsmanship.\n");
     write("It is carved entirely out of marble. Near the head of the\n");
     write("throne, carved also out of marble, is a large eagle with\n");
     write("it's wings spread.\n");
     if(jar && !found) {
      object spirit;
      write("As you look over the throne you find a small jar in a hidden\n");
      write("compartment. Unfortunately you lose your grasp of it and\n");
      write("it falls to the ground shattering.\n");
      spirit = clone_object("players/molasar/rowan/drake/obj/spirit");
      move_object(spirit, this_object());
      spirit->attack_object(this_player());
      found = 1;
     }
     return 1;
   }
   write("You have entered the audience chamber of the Gorvernor's Manse.\n");
   write("Like the Great Hall, this room is almost entirely bare. The\n");
   write("only furnishing in the room is the throne which rests on a\n");
   write("platform next to the northern wall.\n");
   write("     There is one obvious exit:  south\n");
}

init() {
   add_action("south","south");
}

south() {
   this_player()->move_player("south#"+
                              "players/molasar/rowan/drake/mansion/gr_hall");
   return 1;
}

/*
 * Stuff called from other rooms
 */

set_guard(g) { guard = g; }
query_guard() { return guard; }

set_jar(j) { jar = j; }

