#include "/players/guilds/warriors/sdefine.h"

main(string str, object gob, object player)
{ 
object woo;
object ob; 
if(USER->query_ghost()) return 1;
if(!str){
  tell_object(USER, "Redeem who?\n");
  return 1;
  }
if(USER->query_alignment() <= 40){
  tell_object(USER,
  "You are not good!\n");
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
ob = clone_object("/players/guilds/warriors/OBJ/checker.c");  
ob->set_owner(USER->query_real_name()); 
ob->set_strength(GOB->query_skills(96)); 
move_object(ob, woo);
tell_object(USER,
HIW+"You place a hand on "+capitalize(str)+"'s shoulder...\n"+
HIB+"The power of redemption flows from you as you attempt to show\n"+
capitalize(str)+" the true path.\n"+NORM+"");
tell_room(environment(USER),
USERN+"'s hands glow as "+USER->PRO+" touches "+capitalize(str)+".\n", ({USER}));
return 1;
}
