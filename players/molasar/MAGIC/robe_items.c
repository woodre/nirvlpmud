

int uses;
reset(arg) {
     if(!arg)
       uses = 7;
}

id(str) { return str == "robe" || str == "robe of useful items"; }

get() { return 1; }

short() { return "A robe of useful items"; }

long() { 
    write("This is a regular robe with a patch on the inside.\n");
    write("You might be able to detach the patch.\n");
}

init() {
      add_action("detach","detach");
}


detach(str) {
      if(!str) {
        write("Detach what?\n");
        return 1;
      }
      if(str == "patch") {
        int i;
        object rope, bag, money, fire, torch;
        string me;
        me = this_player()->query_name();

        if(uses == 0) {
          write("The robe falls apart due to the strain of creating objects.\n");
          destruct(this_object());
          return 1;
        }
        i=random(5);
        if(i == 0) {
          rope = clone_object("obj/rope");
          move_object(rope, this_player());
          write("You produce a rope out of the robe.\n");

          say(capitalize(me)+" pulls a rope out of his robe.\n");
        }
        if(i == 1) {
           bag = clone_object("obj/bag");
           move_object(bag, this_player());
           write("You produce a bag out of the robe.\n");
           say(capitalize(me)+" pulls a bag out of his robe.\n");
        }
        if(i == 2) {
           this_player()->add_money(100);
           write("You pull 100 gold coins out of the robe.\n");
           say(capitalize(me)+" pulls 100 gold coins out of his robe.\n");
        }
        if(i == 3) {
           torch = clone_object("obj/torch");
           torch->set_fuel(1000);
           torch->set_name("torch");
           torch->set_short("a torch");
           move_object(torch, this_player());
           write("You pull a torch out of the robe.\n");

           say(capitalize(me)+" pulls a torch out of the robe.\n");
        }
        if(i == 4) {
           fire = clone_object("players/molasar/OBJ/firebreather");
           move_object(fire, this_player());
           write("You pull a firebreather out of the robe.\n");
           say(capitalize(me)+" pulls a firebreather out of his robe.\n");
        }
      }
      uses = uses - 1;
      return 1;
}

