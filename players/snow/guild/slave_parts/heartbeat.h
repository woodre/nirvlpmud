/* HEART BEAT */
  heart_beat() {
  if(!environment()) { set_heart_beat(0); return 0; }
  if(!environment()->is_player()) { set_heart_beat(0); return 0; }
  if(liver) GOB->body_clean( ENV() );
  if(stomach) GOB->digest( ENV() );
  if(flash_time) flash_down();
  functional_xp();
  if(arms && ENV()->query_weapon()) grip_weapon(ENV()->query_weapon());
  beats++;
  return 1;
  }
/* FLASH RUNDOWN */
flash_down() {
    flash_time--;
    if(flash_time < 1) {
      tell_object(ENVTO, "Your eyes stop flashing light.\n");
      set_light(-10);
  } }
/* FUNCTIONAL XP */
functional_xp() {
  object att;
  att = ENVTO->query_attack();
  if(arms) {
    if(att) add_body_xp("arms", 5);
  }
  if(eyes) {
    add_body_xp("eyes", 1);
    if(att) add_body_xp("eyes", 1);
  }
  return 1; }
/* CYBORG WEAPON GRIP */
grip_weapon(object ob) {
  object wep, shadow;
  if(!ob) return;
  wep = ob;
  if(wep->query_wep_shadow()) return;
  shadow = clone_object("/players/snow/guild/objects/wepshad.c");
  shadow->start_wep_shadow(wep);
  TE(ENV(), "You grip the "+wep->short()+" firmly with your bionic arm.\n");
  add_body_xp("arms", 2);
  return 1; }
