
/* HEART BEAT */
heart_beat() {
  object me, myenv, ob;
  me = environment();
  if(!me || !me->is_player()) return;
  myenv = environment(me);
  if(!myenv) return;
  ob = present(GID, me);
  if(me->query_attack() && !brave) test_attack();
  if(me->query_level() < 20) test_stats();
  /*
  if(ob->query_mystic_exp() < 1500000) check_skills();
  if(ob->query_mystic_exp() > 1500000) refund();
  */
  if(sand_transfer && myenv->query_sandstorm()) sand_transference(me);
  if(spell_delay < 0) spell_delay = 2;
  if(spell_delay) 
  {
    spell_delay--;
    if(present("go_go", me))
    {
	    spell_delay -= 2;
            if(spell_delay < 0) spell_delay = 0;
           
    }
    if(!spell_delay) TE(me,
      BOLD+RED+"\n\tThe power of the Sands is again within you.\n\n"+OFF); 
  }
  beats++;
  if(!myenv->query_sandstorm()) check_sand();
  check_spatt();
  return 1;
  }

test_attack() {
  object me, it;
  string *mess;
  int damage;
  me = environment();
  it = environment()->query_attack();
  if(!me || !it) return;
  if(!environment(me)) return;
  if(!present(it, environment(me)) ) return;
  if(me->query_ghost()) return 1;
  if(!it->query_attack()) { it->attack_object(me); return 1; }
  if(it->query_attack() != me) {
    if(present("dervish_tattoo", it->query_attack())) {
      damage = me->hit_player( random( it->query_wc() ) );
      if(!damage) return 1;
        mess = it->query_message_hit(damage);
      TE(me, "You step into "+it->query_name()+"'s attack.\n");
      tell_room(environment(me),
        it->query_name()+" "+mess[1]+" "+me->query_name()+mess[0]+"\n");
      return 1; }
    tell_object(me, "You must lead the fight!\n");
    tell_object(environment(me),me->query_name()+
      " leaps forward to lead the fight!\n");
    if(it->query_hp() >= (it->query_mhp() / 10)) it->attack_object(me);
    return 1; }
  return 1; }

test_stats() {

/* Due to the raising of stats to 30 instead of 20
   I raised the current possible max str from 15 to
   20, and the max sta from 15 to 18.
   -Jaraxle [11/11/02] */

/* Changed so max sta is 20 and limited mag to 25
   [12-3-03]  Fred  */

  object me;
  int mystr, mysta, mymag;
  me = environment();
  if(!me) return;
  mymag = me->query_attrib("mag");
  mystr = me->query_attrib("str");
  mysta = me->query_attrib("sta");
  if(mystr > 20) {
    TE(me, BOLD+RED+"\nThe Sands take away your excess physical strength.\n"+OFF+OFF);
  me->set_attrib("str",20);
    me->save();
    me->reset(); }
  if(mysta > (14 + (int)me->query_total_level() / 10)) {
    TE(me, BOLD+RED+"\nThe Sands take away your excess endurance.\n"+OFF+OFF);
   me->set_attrib("sta", 14 + ((int)me->query_total_level() / 10));
    me->save();
    me->reset(); }
  if(mymag > 25) {
    TE(me, BOLD+RED+"\nThe Sands take away your excess magical powers.\n"+OFF+OFF);
  me->set_attrib("mag",25);
    me->save();
    me->reset(); }
  return 1; }
   

sand_transference(ob) {
  int myhp, mysp;
  myhp = ob->query_hp();
  mysp = ob->query_sp();
  if(mysp < 1) return;
  if(myhp == ob->query_mhp()) return;
  ob->add_spell_point(-1);
  if(random(3)) ob->add_hit_point(1);
  return 1; }

check_sand() {
  object me;
  me = environment();
  if(!me || !me->is_player() || me->query_level() > 19) return;
  if(me->is_testchar()) return;
  if(!me->query_interactive() || !environment(me)) return;
  if(me->query_ghost()) return 1;
  if(me->query_level() > 18 && sand_points > 10000) {
    if(!bravery) {
    toggle_bravery();
    tell_object(me,BOLD+"\n\tYour bravery has been rewarded!\n\n"+
         "\tLEAD is at your command!\n\n"+OFF);
    sand_points -= 9900;
    save_me();
    dervish_reset();
    }
  }
  if(sand_points < 1) {
    tell_object(me, "The sand takes your blood as its sacrifice.\n");
    me->add_hit_point(-10);
    sand_points += (21 - me->query_level())*10;
    if(me->query_hp() < 1) kill_me(me);
    return 1; }
  sand_points --;
  return 1; }

check_spatt() {
  if(spell_attacks > 3) {
  sand_points -= 100; }
  spell_attacks = 0;
  return 1; }

kill_me(ob) {
  object sand;
  sand=clone_object("/players/snow/dervish/objects/sands");
  TE(ob, BOLD+RED+"\n\n\tTHE SAND TAKES YOUR LIFE!\n\n"+OFF+OFF);
  sand_points += ob->query_level()*25;
/*
  sand->zap_object(ob); return 1; }
*/
  move_object(sand, environment(ob));
  ob->attacked_by(sand);
  ob->hit_player(100000, "other|snow");
  sand->emit_chan(ob);
  destruct(sand);
  return 1;
}

check_skills(){
 object me, myob;
 int amt, skills;
  me = this_player();
  myob = present(GID, me);
  amt = myob->query_mystic_exp();
  skills = myob->query_skill_pts();
  if((amt - (amt/skills)) > 150000){
    write("\n"+BOLD+RED+"The sands reward your for your dedication with a skill point!!\n"+OFF+OFF);
    myob->add_skill_pt(1);
    myob->add_skill_pts(1);
    myob->dervish_resett();
    return 1; 
  }
}

refund(){
  object me, myob;
  int amt;
  me = this_player();
  myob = present(GID, me);
  amt = myob->query_mystic_exp();
  amt = amt - 1500000;
  me->add_exp(amt);
  myob->add_mystic_exp(-amt);
  myob->dervish_resett();
  return 1; 
}
