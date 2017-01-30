/*
  Allow the person to levitate out of harm's way
*/

#include "/players/eurale/defs.h"

levitate(str) {
  string form_desc_stuff, str2, form_description;
  string new_form_description, form_owner_name;
  object levitate_obj, form_obj;

if(TPL < 15 || TPGEXP < 668) {
  write("You don't possess the skills necessary to levitate.\n");
  return 1; }

if(TPSP < 40) {
  write("You lack the energy to change form.\n"); return 1; }

if(TPBPTS < 60) {
  write("You lack the blood energy to levitate.\n");
  return 1; }

if(PFANGS->query_in_a_form()) {
  write("You cannot levitate while not human.\n");
  return 1; }

/* added by Maledicta to prevent levitating in his cave */
/* NT check by verte. No getting out of nonteleport rooms.
 */
if(ETP->no_hiding() || ETP->realm() == "NT"){ write("You cannot levitate here!\n"); return 1; }

if(PFANGS->query_levitating()) {
  write("You are already levitating.\n");
  return 1; }

write(HIR+"You feel your body levitate up into the air...\n"+NORM);
PFANGS->tell_my_room(
  HIR+capitalize(TPRN)+"'s body slowly levitates out of reach....\n"+NORM);

if(present("vampire fangs",TP)->query_wolf_obj()) {
  write("Your wolf howls and then trots away...\n");
  destruct(present("vampire fangs",TP)->query_wolf_obj());
  present("vampire fangs",TP)->set_wolf_obj(0);
  }

TP->clear_follow();
levitate_obj = clone_object("/players/eurale/VAMPIRES/NPC/levitate_form.c");
move_object(levitate_obj,ROOM);

form_owner_name = TPRN;
form_desc_stuff = form_owner_name+" "+form_description;
levitate_obj->set_form(TP,form_desc_stuff);
move_object(TP, levitate_obj);
present("vampire fangs",TP)->set_levitating(1);
TP->add_spell_point(-40);
PFANGS->add_BLOODPTS(-60);
return 1;
}
