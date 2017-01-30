enrage(str){
    int dam,bug,myob;
    object ob, ob2, att, ob3;
    dam = 1;
    if(environment() != this_player()) return;  
if(this_player()->query_guild_rank() < 7){ write("You cannot use this skill yet.\n"); return 1; }
    if (!str && !USER->query_attack()){
        write("You can be only enraged when fighting.\n");
        return 1;
    }
        else if(!str && USER->query_attack()){
                att = USER->query_attack();
        }

    else{ 
                att = present(str, environment(USER)); 
        }
    if(USER->query_spell_dam()) return 1;
    if (present("enrage")) {
         write("Your already enraged.\n");
         return 1; }
    if(USER->query_sp() < 35){
        write("You do not have the spell points available for this spell.\n");
        return 1; 
    }
if(!(ob2 = present("enrage_check",USER))) {
  ob2 = clone_object("/players/pestilence/closed/dark/obj/enrage_check.c");
  move_object(ob2,USER);
  ob3 = clone_object("/players/pestilence/closed/dark/enrage.c");
  move_object(ob3,USER);
}

  if(ob2->query_ac_times() == 1) {
  write("You can't enrage again yet.\n");

  return 1; }
  else ob2->add_ac_times(1);
  myob = present("dknight_ob", TP);
/*
  if(myob->query_spell_delay()) {
    write("You cannot cast a spell again so soon.\n"); return 1; }
*/
    write("You become "+HIR+"ENRAGED"+NORM+" with hate.\n");
    say(USER->query_name() +" becomes "+HIR+"ENRAGED"+NORM+" with hate.\n");
/*    bug = clone_object("/players/pestilence/closed/dark/mob/demon.c");
    move_object(bug, environment(this_player()));
    bug->attack_object(att); */
    USER->set_spell_dam(dam);
    USER->add_spell_point(-25);
    return 1;
}
