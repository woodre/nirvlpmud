/*
  cause_fear.h
*/

#include "/players/eurale/defs.h"

/* -------- Fear ---------- */
cause_fear(str) {
  object target_obj;

if(!str) {
  write("You must specify who you want to frighten.\n");
  write("Use: fear <who>\n");
  return 1; }

if(TPL < 17) {
  write("You have not attained a high enough level to cast this yet.\n");
  return 1; }

if(TPGEXP < 669) {
  write("Your vampire level is too low to cast this.\n");
  return 1; }

if(TP->query_attrib("wil") < 18) {
  write("You don't have the skills to do that yet.\n");
  return 1; }

if(TPSP < 25) {
  write("You lack the magic to do that!\n");
  return 1; }

target_obj = find_player(str);

if(!target_obj) {
  write(capitalize(str)+" is not curently logged on.\n");
  return 1; }

if(target_obj->query_invis() < TP->query_level() &&
    !present(target_obj,ROOM)) {
    write(capitalize(str)+" is not in the room.\n");
  return 1; }

if(!target_obj->query_npc() && target_obj->query_level() > 19) {
  write("Don't be foolish... NO wizards!\n");
  return 1; }

if(target_obj->query_exl() > TP->query_exl()) {
  write("You are not of sufficient power to cause fear in this target.\n");
  return 1; }
else if(target_obj->query_level() > TP->query_level()) {
  write("The target is too powerful to fear,\n");
  return 1;}

if(!target_obj->query_wimpy()) {
  write(capitalize(str)+" withstands your "+HIR+"FEARSOME GLARE"+
       NORM+"!\n");
  return 1; }

write("You "+HIR+"GLARE"+NORM+" at "+capitalize(str)+" and they "+
      HIR+"PANIC"+NORM+"!\n");
tell_object(target_obj,
  capitalize(TPRN)+HIR+" GLARES "+NORM+"at you and you "+HIR+
  "RUN IN PANIC"+NORM+"!\n");
target_obj->run_away();

write_file("/players/eurale/VAMPIRES/lib/FEAR",ctime(time())+"  "+
  capitalize(TPRN)+" cast FEAR on : "+
  capitalize(target_obj->query_real_name())+" ["+
  environment(target_obj)->short()+"]\n");
TP->add_spell_point(-25);
PFANGS->add_BLOODPTS(-2);
return 1;
}
