object offwep, firstwep;
int spell_delay,combat,glvl;
int recruit;
int offwep_wc, query_pkk;

set_firstwep(ob){ firstwep=ob; }
query_firstwep(){return firstwep; }
remove_firstwep(){ firstwep = 0; }

set_offwep(ob) { offwep = ob; }
/*
query_offwep() { return offwep; }
*/
query_offwep() { 
  if(offwep) {
    if(( !offwep->query_offwielded()) || offwep->query_wielded_by() != environment())
      remove_offwep();
  }
  return offwep; 
}
remove_offwep(){ offwep = 0; }
query_combat_method() { return 3; }
set_offwep_wc(num) { offwep_wc = num; }
add_offwep_wc(num) { offwep_wc += num; }
query_offwep_wc(num) { return offwep_wc; }

string query_gmon1() { return "" +spell_delay; } 
add_spell_delay(num) { spell_delay += num; }
set_spell_delay(num) { spell_delay = num; }
query_spell_delay() { return spell_delay; }
add_recruit(num) { recruit += num; }
query_recruit(num) { return recruit; }
query_grank(num) { return combat; }
add_combat(num) { combat += num; }
query_combat(num) { return combat; }
add_glvl(num) { glvl += num; }
query_glvl(num) { return glvl; }
query_pkk() {return environment()->check_fight_area(); }
string query_gmon2() {return (this_player()->check_fight_area() ? HIR+"PK"+NORM : ""); }
string query_gmon3() {return (present("enrage_ob", this_player()) ? HIW+"Enraged"+NORM : ""); }
string query_gmon4() {return (!present("enrage_check", this_player()) ? "Now" : "Not Now"); }
