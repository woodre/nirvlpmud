#include "/players/illarion/dfns.h"
inherit "/players/illarion/obj/clothes.c";

int dodge_skill;
int block_skill;

reset(arg) {
  if(arg) return;

  dodge_skill=35;
  block_skill=25;

  set_id("belt");
  set_short("A blackbelt in martial arts");
  set_long("This is a test object.\n");
}

status cmd_wear(string str) {
  int ret;
  ret= ::cmd_wear(str);
  if(worn_by)
    worn_by->RegisterArmor(this_object(),({"physical",5,0,"belt_special"}));
    worn_by->RegisterArmor(this_object(),({"physical",0,0,"belt_special2"}));
  return ret;
}

int belt_special(object owner) {
  int dodge_roll,block_roll,dodge_fail,block_fail;
  dodge_roll=random(dodge_skill+owner->query_attrib("dex"));
  block_roll=random(block_skill+owner->query_attrib("wil"));
  dodge_fail=random(50);
  block_fail=random(50);
  if(!worn_by || worn_by != owner) {
    tell_object(owner,"Belt Removed.\n");
    owner->RemoveArmor(this_object());
  }
  if(dodge_roll>=dodge_fail) {
    tell_object(owner,dodge_roll+" beats "+dodge_fail+"\n");
    tell_object(owner,
"With blinding speed, you dodge out of the way!\n");
    return 10000;  /* no physical damage */
  } else if(block_roll >= block_fail) {
    tell_object(owner,block_roll+" beats "+block_fail+"\n");
    tell_object(owner,
"You manage to block a part of the incoming attack's fury!\n");
    return 4000+random(2001);  /* 40-60% reduction */
  }
  return 0;
}
int belt_special2(object owner) {
  tell_object(owner,"special 2 called.\n");
}
