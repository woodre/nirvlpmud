dportal(){
    int dam,bug,myob;
    object ob, att;
    if(environment() != this_player()) return;  
    if(USER->query_sp() < 200){
        write("You do not have the spell points available for this spell.\n");
        return 1; 
    }
if(this_player()->query_guild_rank() < 10){ write("You must be guild level 10 for this spell.\n"); return 1; }
if(present("dknight_ob",this_player())->query_recruit() > 2){ write("You have already recuited three people.\n"); return 1; }
  myob = present("dknight_ob", TP);

    write("You summon a "+HIK+"DARK "+HIW+"Portal"+NORM+".\n");
    say(USER->query_name() +" calls forth the power of "+HIK+"darkness"+NORM+".\n"+
        "Something happens.\n");
  write_file("/players/pestilence/closed/dark/log/dportal",ctime(time())+" "+this_player()->query_name()+" opened the dark portal.\n");
    bug = clone_object("/players/pestilence/closed/dark/OBJ/dportal.c");
    move_object(bug, environment(this_player()));
    USER->add_spell_point(-195);

    return 1;
}
