/* AUTOLOAD */
/*
query_auto_load() { return "/players/snow/dervish/gob.c:"; }
*/
    
/* DROP AND GET */
drop () { return 1; }  /* undroppable */
get() { return 1; }    /* ungettable */

/* COMBAT FUNCTIONS */
query_combat_method() { return 3; }
set_offwep(ob) { offwep = ob; }
query_offwep() { return offwep; }
set_firstwep(ob) { firstwep = ob; }
query_firstwep() { return firstwep; }
remove_offwep() { offwep = 0; }
remove_firstwep() { firstwep = 0; }

/* SAND TRANSFER */
query_transfer() { return sand_transfer; }
set_transfer(num) { sand_transfer = num; }

/* SPELL DELAY */

add_spell_delay(num) { spell_delay += num; }
set_spell_delay(num) { spell_delay = num; }
query_spell_delay() { return spell_delay; }

/* MYSTIC EXP */

add_mystic_exp(num) { mystic_exp += num; }
query_mystic_exp() { return mystic_exp; }
set_mystic_exp(num) { mystic_exp = num; }

/* MYSTIC PERCENTAGE */

set_mystic_percent(num) { mystic_percent = num; }
query_mystic_percent() { return mystic_percent; }

/* PARRY SKILL */

set_parry(num) { parry = num; }
add_parry(num) { parry += num; }
query_parry() { return parry; }

/* OFFWIELD PARRY SKILL */

set_offparry(num) { offparry = num; }
add_offparry(num) { offparry += num; }
query_offparry() { return offparry; }

/* SKILL POINTS */

add_skill_pt(num) { skill_pt += num; }
set_skill_pt(num) { skill_pt = num; }
query_skill_pt() { return skill_pt; }
add_skill_pts(num) { skill_pts += num; }
set_skill_pts(num) {skill_pts = num; }
query_skill_pts() { return skill_pts; }


/* SAND POINTS */

query_sand_points() { return sand_points; }
add_sand_points(num) { sand_points += num; }
delete_sand_points(num)
{
  sand_points -= num;
 if(sand_points<=0)
  sand_points=0;
}
set_sand_points(num) { if(TP && check_me(TP)) sand_points = num; }

/* BRAVERY */
query_bravery() { return bravery; }
toggle_bravery() { bravery = !bravery; }
query_brave() { return brave; }
toggle_brave() { brave = !brave; }

check_me(ob) {
  if(ob->query_real_name() == "snow") return 1;
  if(ob == environment()) return 1;
  else return 0; }

