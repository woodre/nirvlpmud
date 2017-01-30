guild_update() {
    if (USER->query_attack()){
        write("You can't update while fighting.\n");
        return 1;
    }
  move_object(clone_object("/players/pestilence/closed/destroyer/gob.c"),tp);
  write(""+
HIW+">"+HIR+"A"+HIW+"."+HIR+"o"+HIW+"."+HIR+"P"+HIW+"<"+NORM+" Guild Status Updated.\n");
  destruct(this_object());
return 1; }
