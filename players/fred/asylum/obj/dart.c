inherit "/obj/treasure";
#include <ansi.h>
#define tp this_player()
#define tpn this_player()->query_name()

reset (arg) {
  set_id("dart");
  set_alias("tranquilizer");
  set_short(BOLD+RED+"Tranquilizer"+NORM+" Dart");
  set_long(
 "  A small tranquilizer dart that you can use to drug your\n"+
 "opponent to leave it incapacitated for a short time. For more\n"+
 "information "+GRN+"< dart_help >"+NORM+".\n");
  set_value(1300);
  set_weight(1);
  }

init(){
  ::init();
   add_action("dartem","drug");
   add_action("helpem","dart_help"); 
 }

helpem(){
  write("To us this dart simply 'drug target'.\n");
  return 1;
 } 

dartem(string str){
object loser, junk, comp;
 if(str){
  loser = present(str, environment(tp));
 }
 else{
  loser = this_player()->query_attack();
 }
 if(!loser){
  tell_object(tp, "You do not see "+str+" here.\n");
  return 1;
 }
 if(loser->is_living() && !loser->query_npc()){
  write("You cannot use darts on players!\n");
  return 1;
 }
if(loser->query_npc() && living(loser)){
  if(loser->tranqed()){ 
   tell_object(tp, "You cannot dart "+loser->query_name()+" again!\n"); 
   return 1; 
  }
tell_room(environment(tp),
capitalize(tpn)+" throws a tranquilizer dart at "+BOLD+RED+loser->query_name()+NORM+"!\n", ({tp}));
tell_object(tp,
"\nYou throw a tranquilizer dart at "+BOLD+RED+loser->query_name()+NORM+"!\n");            
  junk = clone_object("/players/fred/asylum/obj/drugs.c");
  junk->set_time(5 + tp->query_level());
  junk->dart_loser(loser);
  destruct(this_object());
  this_player()->recalc_carry();
  return 1;
  }
 return 1;
}
