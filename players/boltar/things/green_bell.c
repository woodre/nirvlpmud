#include "/obj/clean.c"

short() {
      return "An old ship's bell on a pole";
}

query_value() {
        return 0;
}

long() {
    write("This appears to be an old ship's bell from the HMS Agamemnon.\n"); 
    write("It is quite well made and appears to be kept in good\n"+
          "condition. How it got here is a mystery. A small plaque\n"+
          "says: Placed here by the neighborhood watch in honor of\n"+
          "our favorite Admiral. It seems one could 'ring' this bell.\n");
}

init() {
       add_action("ring","ring");
}

id(str) {
    return str == "bell" || str == "ship's bell";
}
drop() {
   write("The whistle breaks as it hits the ground.\n");
   destruct(this_object());
   return 1;
}

ring(str) {
  object cop;
    if (str && !id(str))
        return 0;
    if(present("peace keeper",environment(this_player()))) {
       write("You ring the bell and the peace keeper looks at you funny.\n");
       say(this_player()->query_name()+" rings the bell.\n");
    return 1;
   }
    write ("You ring the bell..\n");
    write("The sound carries.....\n");
    say(this_player()->query_name()+" rings the bell.\n");
    cop = find_living("peace keeper");
    if (!cop) {
      write("No one nearby to hear it.\n");
      return 1;
    }
    move_object(cop, environment(this_player()));
    say("A town guard has been summoned.\n");
    write("A town guard has been summoned.\n");
    return 1;
}

get() {
        write("It is secured to the ground\n");
        return 0;
}

