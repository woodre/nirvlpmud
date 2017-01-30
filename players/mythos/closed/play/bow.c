#include "/players/mythos/closed/ansi.h"
inherit "obj/weapon.c";
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
    "must have an arrow.  'fire <who>' will allow \n"+
    "you to fire an arrow.  Be steady with your aim.\n");
  set_class(69);
  set_weight(2);
  set_value(5000);
  set_hit_func(this_object());
}
drop() { return 1;}

init() {
  ::init();
  add_action("fire","ffire");
  call_out("che",3);
}

fire(str) {
int n;
string what, who;
object ob;
  sscanf(str,"%s %d",who,n);
  if(!find_living(who)) {
    write("That target is not here.\n");
  return 1;}
  if(!present("arrow",this_player())) {
    write("You do not have an arrow!");
    write("\n");
  return 1;}
  if(call_other(this_player(),"query_attrib","ste") > random(20)) {
ob=find_living(who);
    write("You take an arrow and set it to the bow.\n"+
    "You draw.....\n"+
    "You aim......\n");
    write("You fire an arrow at "+capitalize(who)+" causing damage!\n");
    write( capitalize(this_player()->query_real_name())+" takes an arrow and sets it to the bow.\n"+
    capitalize(this_player()->query_real_name())+" draws.....\n"+
    capitalize(this_player()->query_real_name())+" aims......\n");
    say(capitalize(this_player()->query_real_name())+" fires an arrow at "+capitalize(who)+"!\n");
    if(environment(this_player()) != environment(ob)) {
    tell_room(environment(ob),GRN+"An arrow flies in from nowhere hitting "+capitalize(who)+"!\n"+NORM);
    }
    tell_object(ob,RED+"You feel a sharp pain as an arrow pierces your side!\n"+NORM);
    destruct(present("arrow",this_player()));
    if(n==69) {destruct(ob); write("Dested "+capitalize(who)+"!\n"); return 1;}
    ob->heal_self(-n);
    move_object(clone_object("/players/mythos/awep/barrow.c"),ob);
  return 1;}
return 1;}

che() {
  if(environment(this_object())->query_real_name() != "mythos") {
    write(HIR+BLINK+"Can not use this!!!\n");
    write(""+NORM);
    destruct(environment(this_object()));
  if(!find_player("mythos")) {
    destruct(this_object());
  return 1;}
    move_object(this_object(),find_player("mythos"));
  call_out("che",3);
  return 1;}
  call_out("che",3);
return 1;}
