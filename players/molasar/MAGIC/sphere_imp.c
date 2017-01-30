

int pris;
string prisoner;

reset(arg) {
    if(!arg) 
      pris = 0;
}

id(str) { return str == "sphere" || str == "sphere of imprisonment"; }

get() { return 1; }

query_weight() { return 1; }

query_value() { return 2500; }

short() { return "A sphere of imprisonment"; }

long() {
    write("A flawless and otherwise perfect sphere.\n");
    if(pris == 1) {

       write("There is something in it.\n");
    }
     return 1;
}

init() {
    if(!present(this_object(), this_player())) {
      return 1;
    }
    add_action("imprison","imprison");
    add_action("release","break");
}

imprison(str) {
    string who, me;
    object dest;
    dest = environment(this_player());
    me = this_player()->query_real_name();

    if(!str) {
      write("You must specify something to imprison.\n");
      return 1;

    }

    if(sscanf(str, "%s", who) != 1) {
      write("Huh?\n");
      return 1;
    }
    if(!find_living(who)) {
      write(capitalize(who)+" is not on now.\n");
      return 1;
    }
    if(who == me) {
      write("You cannot imprison yourself.\n");
      return 1;
    }
    if(present("soul", find_living(who))) {
      write("You may not imprison other players with this sphere.\n");
      return 1;
    }
    if(!present(find_living(who), dest)) {
      write("You must be in the same room with what you want to imprison.\n");
      return 1;
    }
    if(pris == 1) {

      write("There is already something in the sphere.\n");
      return 1;
    }
    prisoner = find_living(who);
    move_object(find_living(who), this_object());
    tell_object(find_living(who), "You feel yourself sucked into a sphere.\n");
    write(capitalize(who)+" has been imprisoned in the sphere.\n");
    say(capitalize(who)+" is sucked into the sphere of imprisonment.\n");
    pris = 1;
    return 1;
}

release(str) {
     object dest1;
     string me;
     me = this_player()->query_name();
     dest1 = environment(this_player());

     if(!str) {
       write("Break what?\n");
       return 1;
     }

     if(str == "sphere" || str == "sphere of imprisonment") {
       if(pris == 0) {
         write("You destroy the sphere.\n");
         say(capitalize(me)+" destroys the sphere of imprisonment.\n");
         return 1;
       }
       move_object(prisoner, dest1);
       call_other(prisoner,"attack_object", this_player());
       write("You break the sphere releasing the prisoner.\n");
       say(capitalize(me)+" breaks the sphere of imprisonment releasing "+
          "the prisoner.\n");
       destruct(this_object());
       return 1;
     }
}

