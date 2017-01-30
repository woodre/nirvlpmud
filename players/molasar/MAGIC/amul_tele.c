
id(str) { return str == "amulet" || str == "amulet of telepathy"; }

get() { return 1; }

short() { return "An amulet of telepathy"; }

long() {
     write("This amulet allows you to think messages to other people.\n");
}

init() {
     add_action("think","think");
}

think(str) {
     object ob;
     string who, msg;

     if(!str || sscanf(str, "%s %s", who, msg) != 2) {
       write("Think what?\n");
       return 1;
     }
     ob = find_living(lower_case(who));
     if(!ob || ob->query_invis() > 0) {
       write(capitalize(who)+" is not in this realm of existence.\n");
       return 1;
     }
/* added by mizan */
  if(this_player()->query_invis()) {
    write("Your sensitive mind notices a wrongness in space [tm].\n");
    return 1;
  }
     if(ob->query_level() >= 21) {
       write("That persons magical persona blocks out your thoughts.\n");
       return 1;
     }
   if (ob->query_tellblock()){
      write("That person is currently blocking tells.\n");
       return 1;
        }
     write("You think to "+capitalize(who)+": "+msg+"\n");
     tell_object(ob, capitalize(this_player()->query_name())+
                " thinks to you: "+msg+"\n");
     return 1;
}

