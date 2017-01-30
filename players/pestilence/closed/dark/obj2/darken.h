darken(){
    int dam,bug,myob;
    object ob, att;
    if(environment() != this_player()) return;  
    if(USER->query_sp() < 10){
        write("You do not have the spell points available for this spell.\n");
        return 1; 
    }
if( environment() && environment(environment()) ){ 
if(!creator(environment(environment()))){ write("You cannot do that here.\n"); return 1; }   }
if(this_player()->query_guild_rank() < 20){ write("You can't use this spell yet.\n"); return 1; }
  myob = present("dknight_ob", TP);
/*
  if(myob->query_spell_delay()) {
    write("You cannot cast a spell again so soon.\n"); return 1; }
*/
    write("You send a darkness over the area.\n");
    say(USER->query_name() +" calls forth the power of "+HIK+"darkness"+NORM+".\n"+
        "Clouds fill the sky and it becomes very dark.\n");
    bug = clone_object("/players/pestilence/closed/dark/obj/darken.c");
    move_object(bug, environment(this_player()));
    USER->add_spell_point(-25);
/*
  myob->set_spell_delay(120);
*/
    return 1;
}
