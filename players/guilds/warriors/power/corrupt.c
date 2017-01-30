#include "/players/guilds/warriors/sdefine.h"

main(string str, object gob, object player)
{ 
object woo;
object ob; 
int al;
if(USER->query_ghost()) return 1;
if(!str){
  tell_object(USER, "Corrupt who?\n");
  return 1;
  }
if(!GOB->check_align("evil")){
  tell_object(USER,
  "You are not evil!\n");
  return 1;
  }
woo = present(str, environment(USER));
if(!woo){
  tell_object(USER, "You do not see them present.\n");
  return 1;
  }
if(!living(woo) || woo->query_npc()){
  tell_object(USER,
  "This only works on players!\n");
  return 1;
  }
if(woo == USER){
  tell_object(USER, "Not on yourself!\n");
  return 1;
  }
if(USER->query_sp() < 100 && GOB->query_end() < 25){
  tell_object(USER,
  "You are lacking in spiritual strength.\n");
  return 1; 
  }
USER->add_spell_point(-100);
GOB->add_end(-25);
ob = clone_object("/players/guilds/warriors/OBJ/corrupt.c");  
ob->set_owner(USER->query_real_name()); 
ob->set_strength(GOB->query_skills(96)); 
move_object(ob, woo);
tell_object(USER,
HIW+"You place a hand on "+capitalize(str)+"'s shoulder...\n"+
HIR+"The power of corruption flows from you as you attempt to show\n"+
capitalize(str)+" the ways of evil.\n"+NORM+"");
tell_room(environment(USER),
USERN+"'s hands glow as "+USER->PRO+" touches "+capitalize(str)+".\n", ({USER}));
return 1;
}
