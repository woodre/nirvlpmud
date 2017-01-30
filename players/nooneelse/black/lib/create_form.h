/*
  create_form.h
*/

#include "defs.h"

/* create one of the vampire's alternate forms */
create_form(str) {
  string new_form_desc_stuff, str2, form_description;
  string new_form_description, form_owner_name;
  object new_form_obj, form_obj;
  /* summon the wolf, if there is one */
  if (query_verb()=="wolf" && str=="come to me") {
    if (!MY_FANGS->query_wolf_obj()) {
      write("You don't have a wolf waiting anywhere.\n");
      return 1;
    }
    MY_FANGS->tell_my_room(MY_NAME_CAP+" whistles piercingly for a moment.");
    write("You get the mental image of the wolf coming in your direction.\n");
    MY_FANGS->query_wolf_obj()->summon_wolf();
    return 1;
  }
  if (!str || str != "form") return 0;
  if (MY_PLAYER->query_attack() &&
      environment(MY_PLAYER->query_attack())==MY_ROOM) {
    write("You can't change to "+query_verb()+" while in combat.\n");
    return 1;
  }
  if(MY_PLAYER->query_sp() < 40) {
    write("You lack the energy to change form.\n"); return 1; }
  new_form_description = query_verb();
  if (MY_FANGS->query_in_a_form() && MY_ROOM!=VAMPIRE_FORM) {
    form_owner_name=0;
    form_description=0;
    MY_FANGS->set_in_a_form(0);
  }
  if (MY_FANGS->query_in_a_form()) {
    write("Your "+form_description+" form seems to waiver for a moment, "+
          "then assumes the shape of a "+new_form_description+".\n");
    MY_FANGS->tell_my_room(
           "The "+form_description+
           " seems to waiver for a moment, then assumes the shape of a "+
           new_form_description+".");
  }
  else {
    write("Your body seems to waiver for a moment, "+
          "then assumes the shape of a "+new_form_description+".\n");
    MY_FANGS->tell_my_room(
         MY_NAME_CAP+"'s body seems to waiver for a moment, then assumes "+
         "the shape of a "+new_form_description+".");
  }
  form_description = new_form_description;
  new_form_obj = move_object(clone_object(VAMPIRE_FORM), MY_ROOM);

  form_owner_name = MY_NAME;
  MY_FANGS->set_form_description(query_verb());
  new_form_desc_stuff = form_owner_name+" "+form_description;
  new_form_obj->set_form(new_form_desc_stuff);
  move_object(MY_PLAYER, new_form_obj);
  if (form_obj) destruct(form_obj);
  form_obj = new_form_obj;
  MY_FANGS->set_in_a_form(1);
  MY_PLAYER->add_spell_point(-40);
  return 1;
}
