/*
  pie.c
*/

#include "/obj/user/junk_only.c"

string pie_type, thing, player_name;
object player_obj;
int random_nbr;

id(str) { return str=="pie" || str==pie_type;}

short() { return "A "+pie_type+" pie"; }

long() {
  write("A "+pie_type+" pie.\n");
  write("You may eat this pie or throw it at someone.\n");
  write("Usage:   eat pie\n");
  write("         throw pie at <player>\n");
}

get() { return 1;}

query_weight() { return 2; }

init() {
  if (!pie_type) set_pie_type();
  add_action("eat",   "eat");
  add_action("throw", "throw");
}

eat(str) {
  if (!id(str)) return;
  tell_room(environment(this_player()),
        this_player()->query_name()+" eats a "+pie_type+" pie.\n");
  write("You feel a little better.\n");
  call_other(this_player(),"heal_self",1);
  call_out("destit",0);
  return 1;
}

throw(str) {
  object pie_stuff_obj;
  if (!str || sscanf(str, "%s at %s", thing, player_name) != 2) return;
  if (thing != "pie" && thing != pie_type) return;
  player_obj=find_living(player_name);
  if (!player_obj) {
    write("No such living thing!\n");
    return 1;
  }
  if(player_obj->query_level() > 19) { write("no no no.. no wizes...\n"); destruct(this_object()); return 1;}
  player_name=capitalize(player_name);
  if (lower_case(player_name)=="nooneelse") {
/* try to hit me with my own pie? i don't think so :) */
    player_name=this_player()->query_name();
    player_obj=this_player();
    tell_room(environment(player_obj),
      player_name+" hits "+player_obj->query_objective()+
      "self in the face with a "+pie_type+" pie.\n");
    tell_object(player_obj,"You are hit in the face with a "+pie_type+
                " pie.  Nice shot!\n");
  }
  else {
    chan_msg("A "+pie_type+" pie sails across the sky.  It seems to be flying "+
             "at "+player_name+".\n");
    write("A "+pie_type+" pie sails across the sky.  It seems to be flying at "+
          player_name+".\n");
    tell_object(player_obj,"You are hit in the face with a "+pie_type+
                " pie.\n");
    write("OK.   You hit 'em.\n");
  }
  pie_stuff_obj=clone_object("/players/nooneelse/obj/pie_stuff");
  move_object(pie_stuff_obj, player_obj);
  pie_stuff_obj->start_pie_stuff(pie_type);
  destruct(this_object());
  return 1;
}

destit() {
  destruct(this_object());
  return 1;
}

set_pie_type(str) {
  if (str) {
    pie_type=str;
    return 1;
  }
  random_nbr=random(5);
  if (random_nbr==0) pie_type="apple";
  if (random_nbr==1) pie_type="cherry";
  if (random_nbr==2) pie_type="blueberry";
  if (random_nbr==3) pie_type="chocolate cream";
  if (random_nbr==4) pie_type="lemon custard";
  return 1;
}
