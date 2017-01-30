

inherit "obj/armor";

reset(arg) {
     if(!arg)
     ::reset(arg);
     set_name("helmet");
     set_alias("helmet of telepathy");
     set_short("A helmet of telepathy");
     set_long("This helmet allows you to think messages to people.\n");
     set_type("helmet");
     set_ac(1);
     set_weight(1);
     set_value(400);
}

init() {
     add_action("think","think");
     add_action("wear","wear");
}

wear() {
      wear();
      return 1;
}

think(str) {
     object ob;
     string who, msg;

     if(!str || sscanf(str, "%s %s", who, msg) != 2) {
       write("Think what?\n");
       return 1;
     }
     ob = find_living(lower_case(who));
     if(!ob) {
       write(capitalize(who)+" is not in this realm of existence.\n");
       return 1;
     }
     write("You think to "+capitalize(who)+": "+msg+"\n");
     tell_object(ob, capitalize(this_player()->query_name())+
                " thinks to you: "+msg+"\n");
     return 1;
}

