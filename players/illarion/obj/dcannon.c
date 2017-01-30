/* dcannon.c - a little toy for shooting items across the mud at players-
               an admitted rip-off of Mizan's catapult
 */

#include "/players/illarion/dfns.h"

object target;
object ammo;

status get() { return 0; }

status id(string str) { return str == "cannon" || str == "panel"; }

string short() { return "A trans-dimensional cannon"; }

void long(string str) {
  if(str == "cannon") {
    write("A long barrel of sleek steel set atop a slim steel post and base.\n"+
          "A small metal panel is set into the closed end of the barrel.\n");
    if(ammo)
      write("It's armed with: "+ammo->short()+"\n");
    if(target)
      write("It's aimed at: "+target->query_name()+"\n");
  } else if(str == "panel") {
    write("A set of instructions is printed on the panel:\n"+
          "      "+BLD("arm")+" the cannon with an object.\n"+
          "      "+BLD("aim")+" it at a player.\n"+
          "      "+BLD("fire")+" for big fun.\n");
  }
  return;
}

void init() {
  add_action("cmd_arm","arm");
  add_action("cmd_aim","aim");
  add_action("cmd_fire","fire");
}

status cmd_arm(string str) {
  object tmp_ammo;
  string file;
  if(!str) FAIL("Arm the cannon with what?\n");
  if(ammo) FAIL("Fire what you've got in there first.\n");
  if(sscanf(str,"file %s",file)) {
    tmp_ammo=clone_object(file);
  } else 
    tmp_ammo=present(str,TP);
  if(!tmp_ammo) tmp_ammo=present(str,environment(TP));
  if(!tmp_ammo) FAIL("You don't have that.\n");  
  ammo=tmp_ammo;
  move_object(ammo,this_object());
  write("Cannon loaded with "+ammo->short()+".\n");
  say(TPN+" loads the cannon with "+ammo->short()+".\n");
  return 1;
}

status cmd_aim(string str) {
  object tmp_target;
  if(!str) FAIL("Aim the cannon at whom?\n");
  tmp_target=find_player(str);
  if(!tmp_target) FAIL(capitalize(str)+" not found.\n");
  target=tmp_target;
  write("You target the cannon on "+target->query_name()+".\n");
  say(TPN +"sets the cannon's target.\n");
  return 1;
}

status cmd_fire() {
  object target_env;
  string name;
  if(!ammo) FAIL("No ammo found.\n");
  if(!target) FAIL("No target set.\n");
  target_env=environment(target);
  if(!target_env) FAIL("For some reason the cannon can't lock on.\n");
  write("You fire the cannon!\n");
  say(TPN+" fires the cannon\n");
  tell_room(environment(),(string)ammo->short()+
    " shoots out of the barrel of the cannon a short disance and vanishes!\n");
  if(target->query_invis()>18)
    name="Someone";
  else
    name=(string)target->query_name();
  emit_channel("junk",
    ammo->short()+" falls out of the sky and lands on "+name+"!\n");
  tell_object(target,
    ammo->short()+" appears directly overhead and falls onto your head.  OUCH!\n");
  tell_room(target_env,
    ammo->short()+" appears overhead and falls onto "+name+"'s head.\n",
    ({target}));
  if(transfer(ammo,target)!=0) {
    move_object(ammo,target_env);
    tell_room(target_env,"   The item falls to the ground.\n");
  } else {
    tell_object(target,"   The item tumbles into your inventory.\n");
    tell_room(target_env,"  The item tumbles into "+NAME(target)+"'s inventory.\n",({target}));
  }
  ammo=0;
  target=0;
  return 1;
}
can_put_and_get() { return 1; }
