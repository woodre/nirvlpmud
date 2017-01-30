/* fire_elemental.c
 * example of using damage types for offensive and defensive
 * capabilities in a monster.
 * Illarion (6-04)
 */
 
inherit "players/illarion/test/monster";
 
void reset(status arg) {
  ::reset(arg);
  if(arg) return;
  
  set_name("elemental");
  set_race("elemental");
  set_short("A fire elemental");
  set_long("A large, vaguely humanoid feature, but with no recognizable\n"+
           "features, and completely covered in flame, a fire elemental\n"+
           "is an almost mindless servant of the element of fire.\n");

  /* Monster level should be a general gauge of difficulty.  It does
     not affect experience */  
  set_level(15);
  set_hp(200);
  /* Physical Damage */
  set_wc(13);
  set_ac(5);
  /* Fire Damage */
  set_weapon_params("other|fire",5,0);
  /* Fire Reistance */
  set_armor_params("other|fire",0,50,0);
  /* Vulnerable to Ice */
  set_armor_params("other|ice",0,-50,0);
  /* Vulnerable to Water */
  set_armor_params("other|water",0,-50,0);
  set_corpse_name("ashes");
  set_corpse_short("A pile of smoking ashes");
  set_corpse_long("The smoking ashes left behind by a fire elemental.\n"+
"They may still contain some residual energy.\n");
  set_death_emote("#TN#'s final stroke reduces #MN# to a pile of $HK$ash#N#!");
}
