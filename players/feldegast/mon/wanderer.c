/*
A high-level monster for the Jal-Hab realm.
Nothing fancy, just a semi-big monster that uses some of my new monster
objects multi-spells, and has a few neat objects.
*/
#include "defs.h"

inherit MONSTER;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("wanderer");
  set_alt_name("nomad");
  set_short(HIY+"The Wanderer"+NORM);
  set_long(
"The Wanderer is a prominent figure in the legends of the Jal-Hab.  Some\n"+
"say that he is cursed to forever wander the sea of sands.  Others say that\n"+
"such wandering is a blessing.  Some say he was once a great Majiri magician,\n"+
"while others say he was the guard who prophecized the Lich King's downfall.\n"+
"The being before you sits comfortably upon a majestic steed.  From head to\n"+
"toe he is covered in fresh white silks.  Around his waist is a red sash from\n"+
"which his sheathe hangs.\n"
  );
  set_gender("male");
  set_race("spirit");
  set_level(22);
  set_wc(38);
  set_ac(20);
  set_hp(1200);
  set_al(-500);
  load_spell(25,20,0, /* Hit_player attack */
    YEL+"The Wanderer blasts you with wind and sand.\n"+NORM,
    YEL+"The Wanderer blasts #ATT# with wind and sand.\n"+NORM);
  load_spell(25,25,1, /* Spell point drain */
    MAG+"\nThe Wanderer places his hand upon your chest and steals some lifeforce.\n\n"+NORM,
    MAG+"\nThe Wanderer places his hand upon #ATT#'s chest and steals some lifeforce.\n\n"+NORM);
  load_spell(35,40,2, /* Heal_self attack */
    HIY+"\nThe Wanderer speaks a few words in a long dead tongue...\n"+NORM+
    HIM+"\tYou are bombarded with chaotic energy!\n\n"+NORM,
    HIY+"\nThe Wanderer speaks a few words in a long dead tongue...\n"+NORM+
    HIM+"\t#ATT# is bombarded with chaotic energy!\n\n"+NORM);
  move_object(clone_object(OBJ_PATH+"sheath.c"),this_object());
  move_object(clone_object(ARM_PATH+"wandereye.c"),this_object());
  move_object(clone_object(WEP_PATH+"fscimitar.c"),this_object());
  init_command("wear amulet");
  init_command("wield scimitar");
  set_wc(38);
  set_ac(20);
  set_dead_ob(this_object());
}
    
monster_died(ob) {
  write_file("/players/feldegast/log/monsters.log",ctime(time())+" "+TPRN+" killed Wanderer\n");
}
