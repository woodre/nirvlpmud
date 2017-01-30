/*
 cult_form.c
*/

#include "/players/eurale/defs.h"
inherit "obj/treasure";

string form_owner_name, form_description, str;
object master;

reset(arg) {
  if(arg) return;
set_id("mist");
set_light(-0);
enable_commands();
}

get() { return 0; }

init() {
  ::init();
add_action("say","say");
add_action("delevitate","delevitate");
add_action("look","look", 1);
}

delevitate() {
  if(TP != master) return;
  write(HIC+"You slowly drift back to the ground...\n"+NORM);
  FANGS->tell_my_room(
    capitalize(form_owner_name)+" slowly drifts to the ground.\n");
  present("vampire fangs",master)->stop_levitating();
  if (this_object() && environment(this_object()))
    move_object(this_player(), environment(this_object()));
  if (this_object()) destruct(this_object());
return 1;
}

look() {
  object this_room_obj, stuff_obj;
  if (environment(this_player()) != this_object()) return;
  write("You levitate above the room....\n\n");
  this_room_obj = environment(TO);
    if(TP->query_brief())
      write(this_room_obj->short()+"\n");
    else
      this_room_obj->long();
      stuff_obj = first_inventory(environment(this_object()));
      while(stuff_obj) {
      if(stuff_obj->short() && stuff_obj != TO) {
        write(capitalize(stuff_obj->short())+"\n");
      }
      stuff_obj = next_inventory(stuff_obj);
    }
return 1;
}

say(str) {
  if(TPRN != lower_case(form_owner_name)) return;
  if (!str) {
    write("What did you want to say?\n");
    return 1; }
  tell_room(environment(this_object()),
            capitalize(form_owner_name)+" says: "+str+"\n");
  return 1;
}

catch_tell(str) {
if(find_player(form_owner_name))
 tell_object(find_player(form_owner_name),str);
 return 1; }

realm() { return "NT"; }

set_form(object ob, string str) {
  string short_desc;
  master = ob;

form_owner_name = master->query_real_name();
form_description = str;
TO->set_short("A levitating mist");
TO->set_long("A levitating mist resembling "+
             capitalize(form_owner_name)+".\n");
TO->set_name("levitating mist");
TO->set_alias(form_owner_name);
return 1;
}
