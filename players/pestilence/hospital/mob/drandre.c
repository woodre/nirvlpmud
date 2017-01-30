#include "/players/pestilence/ansi.h"
inherit "obj/monster";
#define attacker attacker_ob
#define TP this_player()
#define TO this_object()
object club;
 
reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name(WHT+"Dr. Andre"+NORM); 
  set_alias("andre");
  set_alt_name("doctor andre");
  set_short(WHT+"Dr. Andre"+NORM);
  set_long("Dr. Andre is a balding middle aged man.  He is primarily a cosmetic surgeon who\n"+
  "thinks he is way cooler than he really is.  He has on pink scrubs, with a multi colored shirt\n"+
  "and pants, that almost make you sick upon sight of it.\n");
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
  load_chat("Dr. Andre says: Dr. Dre in the hizzzouse.\n");
add_spell("slash",
"#MN# pushes you away.#RET#Dr. Andre says: If you stop fighting I'll make a fantasy trade with you!\n",
"#MN# pushes #TN# away.#RET#Dr. Andre says: If #TN# stops fighting I'll make a fantasy trade with #TN#!\n",
 25,"20-55","other|magic",0);
add_spell("pillit",
"#MN# pulls out a bottle of pills and pops on in his mouth!\n",
"#MN# pulls out a bottle of pills and pops on in his mouth!\n",
 15,"10-35",0,0,"dogheal");
 
}


heart_beat(){
int z;
  ::heart_beat();
}

monster_died() {
  move_object(clone_object("/players/pestilence/Cahara/obj/bone.c"),
        this_object());
  tell_room(environment(this_object()),
        "Dr. Andre says: NOOOO now I will never win the Shiva again!\n");
return 0; }

dogheal( object target, object room, int damage ) {
int amt;
amt = random(20);
if(this_object()->query_hp() > 50) {
tell_room(environment(),
  "Rafi swallows a couple pills and seems re energized!\n"+
  NORM);
  heal_self(amt);
 set_hp_bonus( hp_bonus + amt );
return 1; }
}
