/* This should be included in the monster.
 * check_self() should be called from heart_beat()
 */

/* This redefines the heal_self function to limit damage
 * taken by heal_self spells to a maximum of 10. All normal healing
 * remains unaffected.
 */
heal_self(arg) {
  if(arg < 0) {
    if(arg < -10) arg = -10; }
  ::heal_self(arg); }

/* The check_self function is placed in the monster's
 * heart_beat function. It is of course called every heart_beat.
 */
check_self() {
/* This first part checks to see if the monster is fighting itself.
 * If the monster is fighting itself, it stops fighting and
 * heals itself 1000.
 */
  if(this_object()->query_attack() == this_object()) {
    this_object()->stop_fight();
    this_object()->stop_fight(); this_object()->stop_hunted();
    this_object()->heal_self(1000); }

/* This next function checks to see if the monster's wc has fallen
 * below 20. If it has, the monster's wc gets bumped to 75.
 * This is a vindictive function and can be modified as seen fit.
 */
  if(this_object()->query_wc() < 20) this_object()->set_wc(75);

/* The next little function sets the monster's heal every heartbeat
 * to 1 hp/hb. This can be modified to whatever the monster's
 * normal heal_rate is, as it is a constant setting.
 */
  this_object()->set_heal(1,1);

/* The following function is, unfortunately, directed at a specific
 * dark mage guild power - symbol fear. When that spell is not around,
 * this function will be obsolete.
 */
  if(query_attack() && present("fear_link", query_attack()) )
    destruct(present("fear_link", query_attack()));
  return; }

/* The query_limited_shadow function causes no shadows, except
 * those specifically defined in the obj/shadow_master, to work on
 * this monster. Attack shadows are confined at this time to the
 * dark mage guild but may become more prevalent as people learn
 * how to use them.
 */
query_limited_shadow() { return 1; }
