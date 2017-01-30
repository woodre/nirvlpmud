#include "/players/pestilence/ansi.h"
inherit "obj/monster";
#define attacker attacker_ob
#define TP this_player()
#define TO this_object()
object club;
 
reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name(YEL+"Rafi"+NORM); 
  set_alias("rafi");
  set_short(YEL+"Rafi"+NORM);
  set_long("This is Rafi aka Bro lo el Cuñadohas.  He is of latino descent, and is\n"+
  "extremely crazy!\n");
  set_race("human");
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
  load_chat("Rafi says: Do you want to see my toilet-kitchen?\n");
  load_chat("Rafi asks: Would you like a pocket dog?\n");
add_spell("slash",
"#MN# stabs you with a pocket dog!#RET#You are unsure if your in pain or this is a cruel joke.\n",
"#MN# stabs #TN# with a pocket dog!#RET##TN# is unsure if this is pain or just a cruel joke.\n",
 25,"20-55","other|magic",0);
add_spell("doggy",
"#MN# pulls another pocket dog, oddly enough from his pocket!\n",
"#MN# pulls another pocket dog, oddly enough from his pocket!\n",
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
        "Rafi falls to the ground and says: this can't be real!\n");
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
