#include "/players/pestilence/ansi.h"

main(str){
    int dam,myob;
    object ob, ob2, att, ob3;
    dam = 1;
    if(this_player()->query_guild_rank() < 7){ write("You cannot use this skill yet.\n"); return 1; }
    if (!str && !this_player()->query_attack()){
        write("You can be only enraged when fighting.\n");
        return 1;
    }
        else if(!str && this_player()->query_attack()){
                att = this_player()->query_attack();
        }

    else{ 
                att = present(str, environment(this_player())); 
        }
    if(this_player()->query_spell_dam()) return 1;
    if (present("enrage")) {
         write("Your already enraged.\n");
         return 1; }
    if(this_player()->query_sp() < 65){
        write("You do not have the spell points available for this spell.\n");
        return 1; 
    }
if(!(ob2 = present("enrage_check",this_player()))) {
  ob2 = clone_object("/players/pestilence/closed/dark/obj/enrage_check.c");
  move_object(ob2,this_player());
  ob3 = clone_object("/players/pestilence/closed/dark/obj/enrage.c");
  move_object(ob3,this_player());
}

  if(ob2->query_ac_times() == 1) {
  write("You can't enrage again yet.\n");

  return 1; }
  else ob2->add_ac_times(1);
  myob = present("dknight_ob", this_player());
    write("You become "+HIR+"ENRAGED"+NORM+" with hate.\n");
    say(this_player()->query_name() +" becomes "+HIR+"ENRAGED"+NORM+" with hate.\n");
    this_player()->set_spell_dam(dam);
    this_player()->add_spell_point(-60);
    return 1;
}
