#include "/players/maledicta/ansi.h"
inherit "obj/monster.c";
object attacked;
#define attacked (this_object()->query_attack())


reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("archangel");
set_alt_name("death");
set_alias("archangel of death");
set_race("unknown");
set_short(""+BOLD+""+RED+"Archangel "+BLK+"of Death"+NORM+"");
set_long(
  "  You stand before a being of great power. On its hands are large dark\n"+
  "steel gloves, wicked spikes capping the knuckles and fingers. Great wings\n"+
  "spring from its back, their appearance that of a bat. You look carefully\n"+
  "at its face and see that it is jet black with eyes of pure white. Its\n"+
  "entire body is covered with a black robe which is decorated with magical\n"+
  "runes of protection. This being carries the stench of death with it.\n");

set_level(20);
set_heal(5,3);
set_hp(650);
set_al(-random(1000));
set_wc(28);
set_wc_bonus(5);
set_hp_bonus(5);
set_ac(18);
set_aggressive(0);
set_dead_ob(this_object());
set_chat_chance(5);
  load_chat("The stench of death fills the room.\n");
  load_chat("Death looks down at you and sneers.\n");
set_a_chat_chance(15);
  load_a_chat("Death says: The longer you fight me, the stronger I get!\n");
  load_a_chat("Archangel of Death cackles maniacally!\n");
set_heart_beat(2);
set_chance(20);
set_spell_dam(20);

set_spell_mess1(
"Archangel of death lashes out with his armored fists, driving them into his foe!\n");
set_spell_mess2(
""+BOLD+""+RED+"You cry out in pain as Archangel of Death drives his fists into you!"+NORM+"\n");
}

init(){
  ::init();
  if(this_player()->query_level() < 15){
  write("\n\n\nDeath looks down at you and says: Foolish little mortal, I would not\n"+
              "be here if I were you. You WILL die.\n");
  return 1;
  }            	
}
heart_beat() {
   ::heart_beat();

   if(attacked && (random(100) < 20) && !(attacked->query_ghost())){
   tell_room(environment(this_object()),
   BOLD+BLK+"Archangel of Death feeds upon "+attacked->query_name()+"!"+NORM+"\n");
   tell_object(attacked, 
   HIM+"You feel the life drain from your body as Death touches you!"+NORM+"\n");
      	this_object()->heal_self(20);
        attacked->hit_player(20);
    
        }
}
	
monster_died() {
  object corpse;
  corpse = present("corpse", environment()); 
  tell_object(attacked,
  "You defeat Death and watch as his material form disintegrates into\n"+
  "a fine mist, soon evaporating into nothing.\n"+
  "Death's gloves fall to the ground, their steel armor ringing\n"+
  "loudly as they strike.\n");	
  move_object(clone_object("/players/maledicta/ruins/weapons/gloves.c"),
      environment(this_object()));
 if(corpse)
    destruct(corpse);
return 1; }
