#include "/players/illarion/dfns.h"
inherit "obj/weapon";
int hidden;
#define FAIL(x) { notify_fail(x); return 0; }
/* Allows the weapon to be hidden.  Becomes visible if used to
   attack something. */

init() {
  ::init();
  add_action("cmd_hide","hide");
  add_action("cmd_draw","draw");
  if(this_player()->query_immortal()) {
    wield(name_of_weapon);
    cmd_hide(name_of_weapon);
  }
}
cmd_hide(string str) {
  if(!str || !id(str)) FAIL("Hide what?\n");
  if(!wielded) FAIL("You must be wielding it.\n");
  if(hidden) FAIL("It is already hidden.\n");
  write("You slip your "+name_of_weapon+" out of sight.\n");
  say(this_player()->query_name()+"'s "+name_of_weapon+" vanishes.\n");
  hidden=1;
  return 1;
}
cmd_draw(string str) {
  if(!str || !id(str)) FAIL("Draw what?\n");
  if(!hidden) FAIL("It isn't hidden.\n");
  write("You pull your "+name_of_weapon+" out.\n");
  write("A "+name_of_weapon+" appears in "+
            this_player()->query_name()+"'s hand.\n");
  hidden=0;
  return 1;
}
short() {
  if(wielded && hidden) return 0;
  hidden=0;
  return ::short();
}
query_message_hit(hit) {
  if(hidden) cmd_draw(name_of_weapon);
  return ::query_message_hit(hit);
}
wield(str) {
  int ret;
  ret=::wield(str);
  if(ret && wielded_by) {
    wielded_by->RegisterArmor(this_object(),({"physical",0,0,"parry_special"}));
  }
  return ret;
}

int parry_special(object owner) {
  if(!wielded_by || owner!=wielded_by) {
    owner->RemoveArmor(this_object());
    return 0;
  }
  if(TP && TP!=owner && random((int)owner->query_attrib("dex")) > random(100)) {
    tell_object(owner,format(
"With lightning speed, you use your "+name_of_weapon+" to parry "+TPN+"'s attack!"));
    tell_object(TP,format(
owner->query_name()+" parries your attack with "+POS(owner)+" "+name_of_weapon+"!"));
    tell_room(environment(owner),format(
owner->query_name()+" parries "+TPN+"'s attack with "+POS(owner)+" "+name_of_weapon+"!"),
      ({owner,TP}));
    return 10000;
  }
}
