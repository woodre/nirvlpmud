
id(str) { return str == "bow" || str == "crossbow"; }

get() { return 1; }

short() { return "A crossbow"; }

long() {
     write("A device used to fire projectiles at monsters.\n");
}

query_value() { return 100; }
init() {
     add_action("shoot","shoot");
}

shoot(str) {
      string me, who;
      object ob;
      me = this_player()->query_name();
      ob = present("bolt", this_player());

     if(!str) {
       write("Shoot what?\n");
       return 1;
     }
     if(!ob) {
       write("You have no bolts!\n");
       return 1;
     }
     if(sscanf(str, "%s",who) != 1) {
       write("Shoot who?\n");
       return 1;
     }
     if(!present(find_living(who), environment(this_player()))) {
       write(capitalize(who)+" is not here!\n");
       return 1;
     }
     if(present("soul", find_living(who))) {
       write("You cannot attack other players!\n");
       return 1;
     }
     write("You fire an bolt at "+capitalize(who)+".\n");
     say(capitalize(me)+" fires an bolt at "+capitalize(who)+".\n");
     call_other(find_living(who), "hit_player", 2);
     call_other(find_living(who), "attack_object", this_player());
     destruct(ob);
     return 1;
}

