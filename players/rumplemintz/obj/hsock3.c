inherit "/obj/treasure";

void reset(status arg) {
  ::reset(arg);
  if (arg)
    return;
  set_alias("sock");
  set_short("A Homey Sock");
  set_long(
"A Homey D Clown patented Bonking sock!\n"+
"If you think someone needs an 'I Don't Play Dat' just type 'bonk <person>'\n"+
"and it'll do the trick for ya!\n");
  set_value(150);
}

void init() {
  ::init();
  add_action("hit", "bonk");
}

status hit(string str) {
  object who, room;

  who = find_player(str);
  if (!who) {
    write("You can't bonk someone who isn't playin, stupid!\n");
    return 1;
  }
   if(who->query_level() > 200){
        write("Sorry, Wizards can play anytime they want.\n");
      return 1;
   }
   room=environment(who);
  tell_room(room, this_player()->query_real_name()+" says: " +
            this_player()->query_real_name()+" don't play Dat!\n");
  tell_room(room, this_player()->query_name()+" bonks " +
            who->query_name()+" on the head with the sock!\n");
  tell_object(who, "Damn!, I think "+this_player()->query_name() +
              " don't play Dat!\n");
  write("You just bonked "+str+" with a swift '" +
        this_player()->query_name()+" don't play Dat!'\n");
   return 1;
}
