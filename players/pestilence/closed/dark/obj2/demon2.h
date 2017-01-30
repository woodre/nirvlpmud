demon(str){
    int dam,bug,myob;
    object ob, att;
    dam = 1;
    if(environment() != this_player()) return;  
if(this_player()->query_guild_rank() < 6){ write("You can't use ability yet.\n"); return 1; }
    if (!str && !USER->query_attack()){
        write("Send demon to attack who???\n");
        return 1;
    }
        else if(!str && USER->query_attack()){
                att = USER->query_attack();
        }

    else{ 
                att = present(str, environment(USER)); 
        }
    if(USER->query_spell_dam()) return 1;
    if (present("demon_block")) {
         write("There is already a demon here fighting.");
         return 1; }
    if (!att){ 
        write("There is no "+str+" here to for the demon to attack"); 
        return 1; 
    }
    if(att->is_player()){
        write("You may not cast this spell at a player.\n");
        return 1; 
    }
    if(USER->query_sp() < 10){
        write("You do not have the spell points available for this spell.\n");
        return 1; 
    }
  myob = present("dknight_ob", TP);
  if(myob->query_spell_delay()) {
    write("You cannot cast a spell again so soon.\n"); return 1; }
    write("You send a demon to attack "+att->query_name()+" with a viscious attack.\n");
    say(USER->query_name() +" sends a demon to "+att->query_name()+" with a viscious attack.\n");
    bug = clone_object("/players/pestilence/closed/dark/mob/demon.c");
    move_object(bug, environment(this_player()));
    bug->attack_object(att);
    USER->set_spell_dam(dam);
    USER->add_spell_point(-25);
  myob->set_spell_delay(120);
    return 1;
}
