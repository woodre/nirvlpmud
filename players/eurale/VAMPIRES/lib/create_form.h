/*
  create_form.h
*/

#include "/players/eurale/defs.h"

/* create one of the vampire's alternate forms */
create_form(str) {
  string new_form_desc_stuff, str2, form_description;
  string new_form_description, form_owner_name;
  object new_form_obj, form_obj;

  /* summon the wolf, if there is one */
if(query_verb() == "wolf" && str == "come to me") {
  if(!present("vampire fangs",TP)->query_wolf_obj()) {
    write("You don't have a wolf waiting anywhere.\n");
  return 1; }

FANGS->tell_my_room(
  capitalize(TPRN)+" whistles piercingly...\n");
write("You get the mental image of the wolf coming in your direction.\n");
present("vampire fangs",TP)->query_wolf_obj()->summon_wolf();
return 1; }

if(!str || str != "form") return 0;

if(TPL < 12 || TPGEXP < 667) {
  write("You don't possess the skills necessary to change forms.\n");
  return 1; }

if(TP->query_invis() > 0) {
  write("You must be visible to change vampire forms.\n");
  return 1; }

if(PFANGS->query_levitating()) {
  write("You cannot change forms while levitating.\n");
  return 1; }

if(TP->query_attack() && environment(TP->query_attack()) == ROOM) {
  write("You can't change to "+query_verb()+" while in combat.\n");
  return 1; }

if(TPSP < 40) {
  write("You lack the energy to change form.\n"); return 1; }

if(TPBPTS < 2) {
  write("You lack the blood energy to change forms.\n");
  return 1; }


new_form_description = query_verb();

if(present("vampire fangs",TP)->query_in_a_form()) {
  write("You are already in a form.\n");
  return 1; }

  write("Your body seems to waiver for a moment, "+
        "then assumes the shape of a "+new_form_description+".\n");
  FANGS->tell_my_room(
    capitalize(TPRN)+"'s body seems to waiver for a moment, then assumes "+
         "the shape of a "+new_form_description+".");

if(present("vampire fangs",TP)->query_wolf_obj()) {
  write("Your wolf looks around and then trots away...\n");
  destruct(present("vampire fangs",TP)->query_wolf_obj());
  present("vampire fangs",TP)->set_wolf_obj(0);
  return 1; }

command("drop all",TP);
form_description = new_form_description;
new_form_obj = move_object(clone_object(FORM), ROOM);

form_owner_name = TPRN;
present("vampire fangs",TP)->set_form_description(query_verb());
new_form_desc_stuff = form_owner_name+" "+form_description;
new_form_obj->set_form(TP,form_description);
move_object(TP, new_form_obj);
if(form_obj) destruct(form_obj);
form_obj = new_form_obj;
present("vampire fangs",TP)->set_in_a_form(1);
TP->add_spell_point(-40);
PFANGS->add_BLOODPTS(-2);
return 1;
}
