#include <ansi.h>
inherit "obj/monster";

#define LOG "/players/dragnar/logs/MONS_DEATH"

	object gold, key;

reset(arg){
   ::reset(arg);
   if(arg) return;
   set_name("demon");
   set_race("demon");
   set_alias("demon");
	set_short("A demon from hell");
	set_long("You can't bear to look into his being.  The evil there will\n"+
"rob your soul.\n");
   set_level(20);
   set_hp(1300);
   set_al(-1000);
   set_gender("creature");
   set_wc(40);
   set_ac(17);
	set_aggressive(1);
   set_dead_ob(this_object());
    gold = clone_object("obj/money");
	gold->set_money(random(1000)+4500);
   move_object(gold,this_object());
/*  removed from demon 4/3/97  -Eurale
	key=clone_object("/players/dragnar/mag4.c");
	move_object(key, this_object());
*/
}

monster_died() {
  say("The Demon screams in RAGE!\n");
  write_file(LOG, ctime(time())+" "+
    query_attack()->query_real_name()+" killed the Demon.\n");

}
heart_beat() {
   int amt;
	object att;
	::heart_beat();

   amt = random(300);
	att=(this_object()->query_attack());
   if(att && !random(10)) {
      if(att->query_spell_point() > amt) {
      att->add_spell_point(-amt);
	   tell_object(att, "The demon reaches for your soul.\n");
   }
      else {
         att->hit_player(amt/2);
         tell_object(att, "The demon summons flames from the underworld.\n");
         tell_room(environment(), HIR+"Flames erupt from the demon and engulf the room!"+NORM+"\n");
      }
	}
}
