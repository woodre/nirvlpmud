#include "/players/mythos/closed/guild/def.h"
inherit "obj/weapon.c";
reset(arg){
  ::reset(arg);
  if (arg) return;
  set_name("spear");
  set_alias("drafnor");
  set_short(HIR+"Ruby Spear"+NORM);
  set_long("A shaft of pure ruby gleams with an inner fire.\n"+
           "The Taormin lies within.....\n");
  set_read(HIB+"The SPEAR of DRAFNOR  "+NORM+RED+"- Horlach"+NORM);
  set_class(18);
  set_weight(4);
  set_value(100000);
}

init() {
  ::init();
  add_action("gget","get");
  add_action("gget","take");
  add_action("gget","grasp");
  add_action("slice","slice");
  add_action("slice","cut");
}

gget(str) {
  if(!str) return 0;
  if(id(str)) { tp->zap_object(tp); return 1;}
}

slice(str) {
  if(!str) return 0;
  if(id(str)) {
    if(tp->query_weapon() && (tp->query_weapon())->id("sword of banishment")) {
      move_object(clone_object("/players/mythos/closed/guild/task/hill/taor.c"),
        environment(this_object()));
      tell_room(environment(tp),capitalize(tpn)+
      " raises the accursed Blade of Betrayal\n"+
      "and slices the Spear of Drafnor!\n");
      tell_room(environment(tp),HIB+"\n\tLIGHTNING FLASHES!\n"+NORM);
      tell_room(environment(tp),BOLD+"\n\t\tTHUNDER ROARS!\n\n"+NORM);
      destruct(present("sword of banishment",tp));
      tp->set_wc(3);
      destruct(this_object());
      return 1;}
    tell_room(environment(tp),HIR+"\n\t\tFIRE LASHES OUT ENGULFING EVERYTHING!\n\n"+NORM);
    tp->zap_object(tp);
    return 1;}
}
