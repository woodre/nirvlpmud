#define TP this_player()
#define TPN this_player()->query_name()
#include "/obj/user/junk_only.c"

string pie_type, kind, player_name;
object player_obj,yuk;
int random_nbr;

id(str) { return str=="pie" || str==pie_type;}

short() { return "A "+pie_type+" pie"; }

long() {
  write("A yummy "+pie_type+" pie.\n");
  write("You may eat this pie or throw it at someone.\n");
  write("Usage:   eat pie\n");
  write("         throw pie at <player>\n");
}

get() { return 1;}

query_weight() { return 1; }

init() {
  if (!pie_type) set_pie_type();
  add_action("eat",   "eat");
  add_action("throw", "throw");
}

eat(str) {
if(!id(str)) { write("Eat what?\n"); return 1; }
tell_room(environment(TP),
  capitalize(TP->query_name())+" eats a yummy "+pie_type+" pie.\n");
  write("You feel a little better.\n");
  TP->heal_self(1);
  destruct(this_object());
  return 1;
}

throw(str) {
if (!str || sscanf(str, "%s at %s", kind, player_name) != 2) return;
if (kind != "pie" && kind != pie_type) return;

player_obj = find_living(player_name);
if(!player_obj) { write("Not logged in!\n"); return 1; }

if(player_obj->query_real_name() == "eurale") {
  tell_room(environment(TP),
    capitalize(TPN)+" hits "+TP->query_objective()+
    "self in the face with a "+pie_type+" pie.\n");
  yuk = clone_object("/players/eurale/VAMPIRES/OBJ/pie_stuff.c");
  yuk->set_pie_type(pie_type);
  yuk->start_pie_stuff(pie_type);
  move_object(yuk,TP);
  destruct(this_object());
  return 1; }

if(player_obj->query_level() > 19) {
  write("no, no, no.... no wizzes!\n");
    return 1; }

player_name = capitalize(player_name);
  chan_msg("A "+pie_type+" pie sails through the sky at "+
           player_name+".\n");
  write("You fling a "+pie_type+" pie through the sky at "+
        player_name+".\n");
  tell_object(player_obj,"You are hit in the face with a "+pie_type+
                " pie.\n");
  write("Bullseye... the pie SPLATS on "+player_name+".\n");

  yuk = clone_object("/players/eurale/VAMPIRES/OBJ/pie_stuff.c");
  yuk->set_pie_type(pie_type);
  yuk->start_pie_stuff(pie_type);
  move_object(yuk, player_obj);
  destruct(this_object());
  return 1;
}

set_pie_type(str) {
if(str) { pie_type = str; return 1; }
random_nbr = random(5);
  if (random_nbr==0) pie_type="apple";
  if (random_nbr==1) pie_type="cherry";
  if (random_nbr==2) pie_type="blueberry";
  if (random_nbr==3) pie_type="chocolate cream";
  if (random_nbr==4) pie_type="lemon custard";
  return 1;
}
