string name;

id(str) {
   return (str=="cube");
}

short() {
   return "Cube of death";
}

long() {
   write("This cube is the cube of death.  It will, once, tell a player\n");
   write("of your choice that standard line about you die, you see your\n");
   write("own body, etc.  To use it, type \"die \" and the name of the\n");
   write("player you want to send the message to.  That player must be on\n");
   write("at the time that you use it.  This cube will disappear after one\n");
   write("usage.  Please be careful how you use it!\n");
}

init() {
   add_action("die","die");
}

die(str) {
   object who;

   who=find_player(str);
   name=capitalize(this_player()->query_real_name());
   if (!who) {
      write(str+" does not seem to be playing!\n");
      return 1;
   }
   tell_object(who,"\n\nYou die.\n");
   tell_object(who,"You have a strange feeling.\n");
   tell_object(who,"You can see your own dead body from above.\n\n");
tell_object(who,"\n\n\nSetting hit points to 1/3 max....\n");
   return 1;
}

get() {
   return 1;
}

query_value() {
   return 1000;
}
