#include "/players/snow/guild/def.h"

body_clean(object ob) {
  object one, two, three;
  object pgob;
  int alc;
  one = present("poison", ob);
  two = present("disease", ob);
  alc = ob->query_intoxination();
  pgob = present("cyborg_slave", ob);
  if(one) {
    if(pgob->query_liver_lev() < random(3)) {
      if(!random(5)) {
      TE(ob, "Your body is wracked with pain!\n");
      ob->hit_player(random(15)); pgob->add_body_xp("liver", 10); } }
    else { pgob->add_body_xp("liver", 10);    destruct(one); }
  }
  if(two) {
    if(pgob->query_liver_lev() < random(4)) {
      if(!random(5)) {
      TE(ob, "You feel extremely sick.\n");
      ob->hit_player(random(20)); pgob->add_body_xp("liver", 1); } }
    else { pgob->add_body_xp("liver", 10); destruct(two); }
  }
  if(alc > 1) {
    if(pgob->query_liver_lev() < random(3)) {
      TE(ob, "You feel sick.\n"); pgob->add_body_xp("liver", 1); }
    else  { pgob->add_body_xp("liver", 1); ob->add_intoxination(-2); }
  }
  return 1;
}
