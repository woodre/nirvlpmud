inherit "/obj/monster";
#include "/players/dragnar/closed/color.h"
#define LOG "/players/dragnar/logs/MONS_DEATH"

#include "/players/beck/MortalKombat/MKQuestNPC.c"
reset(arg){
   object gold, scar,armor,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("master Ninja");
   set_race("ninja");
   set_alias("ninja");
   set_short("A Master Ninja");
	set_long("This is the master ninja warrior.  He is the keeper of the skills\n" +
	"of the ancients.  Since his birth he has been trained to be a pure\n" +
	"Ninja and keep the secret of the forest safe.  You will only be able\n"+
   "to get the secret by killing him.\n");
   set_level(21);
   set_hp(1400);
   set_al(-random(1000));
   set_wc(30);
   set_ac(17);
   set_gender("male");
	set_heart_beat(2);
   set_chance(15);
set_spell_dam(60);
	set_spell_mess1("The Ninja calls upon the ancients to slam his foe to the ground.\n");
	set_spell_mess2("Ninja sends the power of the ancients to weaken your soul.\n");
	set_a_chat_chance(20);
   set_chat_chance(5);
	load_chat("Ninja whispers: You will not gain the power of passage from me.\n");
	load_a_chat("Ninja says: I have bled more and seen victory.\n");
   gold=clone_object("obj/money");
   gold->set_money(random(1000)+500);
   move_object(gold,this_object());
	armor=clone_object("players/dragnar/armor/suit.c");
	weapon=clone_object("players/dragnar/weapons/sword.c");
   move_object(armor, this_object());
	move_object(weapon, this_object ());
   set_dead_ob(this_object());
   scar=clone_object("players/dragnar/MKScar/scar.c");
   move_object(scar, this_object());
}
heart_beat() {
	object att;
	::heart_beat();
	att=(this_object()->query_attack());
  if(!att) return;
   if(!random(4)) {
      this_object()->heal_self(random(10));
   }
}
monster_died() {
  object key;
  write_file(LOG, ctime(time())+" "+
    query_attack()->query_real_name()+" killed Master Ninja.\n");
   say("\n");
   say("Ninja cries out: You are a strong warrior.\n"+
"You are worthy of the power of knowledge.  You may enter the ice\n"+
"caves here and venture into the darkness.  But beware, there are\n"+
"many hideous creatures that were once human waiting for you.  They protect\n");

say("secrets that are hidden within.  I am only here to protect you from\n"+
"the danger, but you have proven your worth.  Go now and find the portal\n"+
"of the past and save this wasteland.\n\n");
key = clone_object("/players/dragnar/WasteLands/obj/quest/mag3.c");
move_object(key, this_object());
return 0; }
