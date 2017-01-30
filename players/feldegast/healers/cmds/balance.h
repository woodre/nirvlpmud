do_balance() {
  int diff;
  write(
"You close your eyes and concentrate upon achieving an equilibrium\n"+
"between your mind and your body.\n");
  say(TPN+" closes "+TP->query_possessive()+" eyes and concentrates.\n");
  diff=(TP->query_hp()-TP->query_sp())/2;
  TP->add_hit_point(-diff);
  if(diff>0)
    TP->add_spell_point(random(diff));
  else
    TP->add_spell_point(diff);
  write("HP: "+TP->query_hp()+"/"+TP->query_mhp()+"  SP: "+TP->query_sp()+"/"+TP->query_msp()+"  (");
  if(diff>=0) write("+");
  write(diff+")\n\n");
  return 1;
}
