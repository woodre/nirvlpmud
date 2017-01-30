#include "/players/pestilence/ansi.h"
inherit "obj/monster";
#define attacker attacker_ob
#define TP this_player()
#define TO this_object()
object club;
 
reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name(WHT+"Dr. Feelgood"+NORM); 
  set_alias("feelgood");
  set_alt_name("doctor feelgood");
  set_short(WHT+"Dr. Feelgood"+NORM);
  set_long("This is the doctor that took care of the rock band Motley Crue.  He appears\n"+
  "to be an atypical doctor.  His long hair and rock star looks, sets him apart from others.\n");
  set_race("doctor");
  set_gender("male");
  set_level(20);
  set_wc(30);
  set_ac(19);
  set_hp(550);
  set_heal(10,10);
  add_money(0);
  set_aggressive(0);
  set_dead_ob(this_object());
  set_al(200);
  load_chat("Dr Feelgood says: Smokin' in the boys room!!\n");
add_spell("slash",
"#MN# screams a Motley Crue song soo loudly, your ears "+RED+"burst"+NORM+" causing you to crumble in pain.\n",
"#MN# screams a Motley Crue song soo loudly, #TN#'s ears "+RED+"burst"+NORM+" causing #TN# to crumble in pain.\n",
 25,"30-55","other|magic",0);
 
}


heart_beat(){
int z;
  ::heart_beat();
}

monster_died() {
  move_object(clone_object("/players/pestilence/Cahara/obj/bone.c"),
        this_object());
  tell_room(environment(this_object()),
        "Dr. Feelgood says: Home sweet home!\n");
return 0; }

dogheal( object target, object room, int damage ) {
int amt;
amt = random(20);
if(this_object()->query_hp() > 50) {
tell_room(environment(),
  "Rafi swallows the pocket dog whole!\n"+
  NORM);
  heal_self(amt);
 set_hp_bonus( hp_bonus + amt );
return 1; }
}
