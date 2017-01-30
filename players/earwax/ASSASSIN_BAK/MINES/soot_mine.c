/* this file modified 7/24/95 by Wizardchild
   moved to init() instead of heart_beat(), much more efficient, and
   does the same job
*/
id(str){ return str == "sootmine" || str == "mine"; }
string who;
object target, soot;
int set, armed;
get(){ return 0; }
value(){ return 300; }
query_value(){ return 600; }
 
init(){
/* added */
  if(target && this_player() == target)
    blow_up();
/* end added */
  add_action("set","set");
  add_action("unset","unset");
  add_action("drop","drop");
/*  set_heart_beat(1); */
}
 
 
set(str){
     target = find_player(str);
     if(!str){
       write("Usage: set <player>\n");
       return 1;
     }
   if(!target) { write("That person doenst exist.\n"); return 1; }
  if(target->query_invis()) { write("That person doenst exist.\n"); return 1; }
     if(set == 0){
     write("Land mine set for "+target->query_name()+".\n");
     set = 1;
     return 1;
     }
     if(set == 1){
       write("Land mine already set for someone.\n");
       return 1;
     }
}
short() {return "A land mine"; }
long(){
     write("This is a land mine.  To operate, here are the commands:\n");
     write("set <player>          sets which player will set off the mine.\n");
     write("unset                 unsets the mine.\n");
      write("drop mine             arms the mine and drops it in the room.\n");
     write("Remember that once dropped the mine cannot be picked up.\n");
     write("This particular mine does:\n");
     write("Covers set player with black soot.\n");
}
 
 
unset(){
     if(set == 0){
       write("Land mine has not been set.\n");
       return 1;
     }
     if(set == 1){
       write("Land mine disarmed.\n");
      set = 0;
       return 1;
     }
}
 
 
drop(str){
     if(str == "mine"){
     if(set == 0){
       write("You can't just go around dropping land mines randomly!\n");
       return 1;
     }
     if(set == 1){
       write("Land mine set and armed.\n");
      armed = 1;
       move_object(this_object(), environment(this_player()));
       return 1;
     }
}
}
/* removed 
heart_beat(){
     object victim, here;
     here = environment(this_object());
     if(set == 1 && armed == 1){
     victim = present(target, environment(this_object()));
     if(victim){
end removed */
blow_up() {
       tell_object(target, "You feel the force of a land mine blast!\n");
       tell_room(environment(this_object()), 
       capitalize(target->query_name())+" is blasted by a land mine!\n");
       soot = clone_object("players/deathmonger/ASSASSIN_BAK/MINES/soot");
       move_object(soot, target);
       tell_object(target, "You are covered in black soot.\n");
       destruct(this_object());
       return 1;
    }
/*  }
} */
