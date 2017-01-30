#include "/players/snow/guild/def.h"

digest(object ob) {
  int food, drink;
  object pgob;
  pgob = present(GID, ob);
  food = ob->query_stuffed();
  drink = ob->query_soaked();
  if(food > 1) {
    if(pgob->query_stomach_level() < random(5)) {
    if(!random(4)) ob->add_stuffed(1); }
    else { ob->add_stuffed(-2); pgob->add_body_xp("stomach", 1); } }
  if(drink > 1) {
    if(pgob->query_stomach_level() < random(5)) {
    if(!random(4)) ob->add_soaked(1); pgob->add_body_xp("stomach", 1); }
    else { ob->add_soaked(-2); pgob->add_body_xp("stomach", 1); } }
  return 1; }
