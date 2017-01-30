#include "/players/mythos/closed/ansi.h"
inherit "obj/weapon.c";

int wait;
reset(arg){
  ::reset(arg);
  if (arg) return;

  set_name("daikyu");
  set_alias("bow");
  set_short("Daikyu");
  set_long("This is a bow of great power.  It is made from\n"+
    "strong wood and strong gut string.  With it\n"+
    "comes a short sword to which you use when you\n"+
    "fight in close quarters.  To use the bow you\n"+
    "must have an arrow.  'fire arrow at <who>' will allow \n"+
    "you to fire an arrow.  Be steady with your aim.\n");
  set_class(16);
  set_weight(2);
  set_value(5000);
  set_hit_func(this_object());
wait = 0;
}

init() {
  ::init();
  add_action("fire","fire");
}

fire(str) {
int n;
string what, who;
object ob;
  sscanf(str,"%s"+" at "+"%s",what,who);
  if(!wielded || broke) {
    write("This weapon must be in shape and wielded to use!\n");
  return 1;}
  if(what != "arrow") {
    write("fire what?\n");
  return 1;}
  if(wait) { write("You ready the Daikyu.\n"); return 1; }
  else { call_out("waiting",5);
  }
  if(!(ob = present(who,environment(this_player())))) {
    write("That target is not here.\n");
  return 1;}
  if(!present("arrow",this_player())) {
    write("You do not have an arrow!");
    write("\n");
  return 1;}
  if(present("arrow",this_player())->weapon_class() != 1) { write("You need a true arrow!\n"); return 1;}
/* Added by Snow 12/99 */
  if(ob->is_player()) {
    write("You cannot fire at players.\n"); return 1; }
  if(call_other(this_player(),"query_attrib","ste") > random(30)) {
n=random(7);
    write("You take an arrow and set it to the bow.\n"+
    "You draw.....\n"+
    "You aim......\n");
    write("You fire an arrow at "+capitalize(who)+" causing damage!\n");
    say(capitalize(this_player()->query_real_name())+" fires an arrow at "+capitalize(who)+"!\n");
    tell_object(ob,RED+"You feel a sharp pain as an arrow pierces your side!\n"+NORM);
    call_other(ob,"heal_self",-1-random(5));
    destruct(present("arrow",this_player()));
    ob->attacked_by(this_player());
    this_player()->attack_player(ob);
  if(n<2) {
    move_object(clone_object("/players/mythos/awep/barrow.c"),ob);
  return 1;}
  if(n>1) {
    move_object(clone_object("/players/mythos/awep/arrow.c"),ob);
  return 1;}
return 1;}
  else {
n=random(7);
    write("You take an arrow and set it to the bow.\n"+
    "You draw.....\n"+
    "You aim.....\n"+
    "You fire....\n");
    write("You missed!\n");
    say(capitalize(this_player()->query_real_name())+" fires an arrow but misses everything!\n");
    if(n<2) {
      move_object(clone_object("/players/mythos/awep/barrow.c"),environment(this_player()));
    }
    if(n>1) {
    move_object(clone_object("/players/mythos/awep/arrow.c"),environment(this_player()));
    }
    destruct(present("arrow",this_player()));
  return 1;}
return 1;}

waiting() { wait = 1; return 1; }
