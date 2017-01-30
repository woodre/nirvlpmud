object saver;
string me;

id(str) { return str == "scroll" || str == "black scroll"; }

short() { return "A black scroll"; }

long() { 
   write("An old black scroll with writing on it.\n");
   write("It seems to say something about faking(feign) death.")
   ;
}

query_value() { return 250; }

get() { return 1; }

init() {
   add_action("read","read");
   add_action("feign","feign");
}

read() {
   write("This scroll allows the possessor to pass the death portal.\n");
   return 1;
}

feign(str) {
      me=this_player()->query_real_name();
   
   if(str == "death") {
      write("You concentrate on the words inscribed on the scroll.\n");
      say(capitalize(me)+" studies the scroll carefully.\n");
      call_out("initiate_death", 5);
      return 1;
   }
   write("Feign what?\n");
   return 1;
}

initiate_death() {
 object tunnel;
   tell_room(environment(find_player(me)),
      capitalize(me)+" is struck by a bolt of lightning!\n");
   find_player(me)->second_life(1);
   find_player(me)->set_dead(2);
/* white tunnel auto-destruct by verte. */
  if(tunnel=present("tunnel", environment(find_player(me))))
    destruct(tunnel);
   destruct(this_object());
   return 1;
}

