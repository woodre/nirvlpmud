/*
  guild_rooms.c - checks everyone for membership
  and provides a sanctuary for vampires...
*/
asdfghjkl(){
    if (MY_PLAYER->query_stuffed()>0) MY_PLAYER->add_stuffed(-5);
    if (MY_PLAYER->query_soaked()>0) MY_PLAYER->add_soaked(-5);
    if (MY_PLAYER->query_intoxination()>0) MY_PLAYER->add_intoxination(-5);
    if (MY_HIT_POINTS < MY_PLAYER->query_mhp() ||
        MY_SPELL_POINTS < MY_PLAYER->query_msp())
      MY_PLAYER->heal_self(2);
    call_out("asdfghjkl",5);
}

check_membership(arg) {
  string str1, str2;
  if (!present("vampire fangs", arg) && !arg->am_i_a_servant()) {
    if (sscanf(file_name(arg), "%sobj/kid%s", str1, str2)==2) return 0;
    if (arg->is_pet()) return 0;
    tell_object(arg,
          "A large flaming demon appears, beats you up (injuring you) "+
          "and tosses you out, saying:\n"+
          "     Members only!\n");
    say("A large flaming demon appears, beats "+arg->query_name()+
        " up and tosses "+arg->query_objective()+
        " out, saying:\n     Members only!\n\n");
    if (arg->query_hp() > 10) arg->reduce_hit_point(5);
    call_other("players/nooneelse/blackentry", "???");
    move_object(arg, "players/nooneelse/blackentry");
    command("look", arg);
    return 1;
  }
  return;
}
