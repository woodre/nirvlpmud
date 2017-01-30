do_frep() {
  int hit_point;
  int max_hp;
  int spell_points,max_spell;
  int level;
  int intoxicated,stuffed,soaked;
  int infuse;

  hit_point=TP->query_hp();
  max_hp=TP->query_mhp();
  spell_points=TP->query_sp();
  max_spell=TP->query_msp();

  level=TP->query_level();
  intoxicated=TP->query_intoxination();
  stuffed=TP->query_stuffed();
  soaked=TP->query_soaked();
  write("You report: ");
  say(BOLD+TPN+BLK+"-=>");
  tell_room(environment(this_player()),
/* Cut and pasted from player.c */
    NORM+MAG+" HP: "+NORM+BOLD+hit_point+MAG+"/"+NORM+BOLD+max_hp+NORM+MAG+"   SP: "+
    NORM+BOLD+spell_points+MAG+"/"+NORM+BOLD+max_spell+"\n"+NORM);
/*  tell_room(environment(this_player()),
    NORM+CYN+"\t\tI:"+NORM+BOLD+intoxicated*100/(level+3)+HIB+"%  "+NORM+CYN+
    "F:"+NORM+BOLD+stuffed*100/(level*8)+HIB+"%  "+
    NORM+CYN+"S:"+NORM+BOLD+soaked*100/(level*8)+NORM+HIB+"%  "+NORM+
    NORM+CYN+"T:"+NORM+BOLD+infuse*100/(9*level/2)+HIB+"%"+NORM+"\n");*/
  return 1;
}
