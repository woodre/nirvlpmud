object monster;
int h;

start_heal_shadow(who) {
monster = who;
shadow(monster, 1);
return 1;}

stop_shadow_me() {
shadow(monster, 0);
return 1;}

heal_self(h) {
  if (!h)
    return;
  if(monster->query_mhp() < monster->query_hp() + h) {
     h = monster->query_mhp() - monster->query_hp(); }
  monster->set_hp(monster->query_hp() + h);
  if(monster->query_hp() < 1) monster->set_hp(1);
}
