id(str) { return str == "bed" || str == "brass bed"; }

short() {
   return "A Brass Bed";
}

long() {
   write("This is a king sized, four postered, brass bed.\n");
   write("The bed is covered with gleaming white silk sheets.\n");
   write("Tied to each of the four bed posts are silk scarves.\n");
}

init() {
   add_action("lay","lay");
   add_action("tie","tie");
   add_action("pull","pull");
   add_action("jump","jump");
   add_action("throw","throw");
}

lay(str) {
   string name;
   if(str == "on bed") {
   name = capitalize(this_player()->query_real_name());
   write("You climb up on to the bed and, and stretch out to relax.\n");
   say(name+" climbs up on the bed and relaxes.\n");
   return 1;
   }
}

tie(str) {
  object who;
   string name;
  who = find_player(str);
  name = capitalize(this_player()->query_real_name());
  if(who) {
    write("You push "+capitalize(str)+" to the bed, and tie him up with silk scarves.\n");
    say(name+" pushes you down and ties you to the bed!\n");
    return 1;
  }
}

jump() {
   string name;
   name = capitalize(this_player()->query_real_name());
   write("You jump up and down on the bed, giggling like a little kid.\n");
   say(name+" jumps up and down on the bed, giggling and laughing.\n");
   return 1;
}
pull(str) {
   object who;
   string name;
   who = find_player(str);
   name = capitalize(this_player()->query_real_name());
   if(who) {
      write("You pull "+capitalize(str)+" on to the bed, and you kiss passionately.\n");
      say(name+" pulls you on to the bed, and kisses you deeply.\n");
      return 1;
   }
}

get() {
   return 0;
}
