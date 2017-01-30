monster_died() {
tell_room(environment(this_object()),
  "As you smash the raptor with your final blow, one of its large,\n"+
  "bulging eyeballs pops out and lands at your feet.\n");
move_object(clone_object("players/eurale/Park/OBJ/eye1"),
        environment(this_object()));
return 0; }

