object offwep, firstwep;
int combat,glvl,shadows,recon,infantry,bomb;
int grank, pclass;
int recruit, target;
int skills, prof, ass;
int offwep_wc;
int light_on;


add_spell_delay(num) { spell_delay += num; }
set_spell_delay(num) { spell_delay = num; }
query_spell_delay() { return spell_delay; }
add_combat(num) { combat += num; }
query_combat(num) { return combat; }
add_glvl(num) { glvl += num; }
query_glvl(num) { return glvl; }
set_grank(string x){ grank = x; }
query_grank(){ return grank; }
set_offwep(ob) { offwep = ob; }
query_offwep() { return offwep; }
remove_offwep() { offwep = 0; }
set_target(string x){ target = x; }
query_target(){ return target; }
query_skills(num) { return skills; }
add_skills(num) { recon += num; }
set_prof(string x) { prof = x; }
query_prof() { return prof; }
set_shadows(num) { shadows = num; }
add_shadows(num) { shadows += num; }
query_shadows(num) { return shadows; }
add_recon(num) { recon += num; }
query_recon(num) { return recon; }
add_infantry(num) { infantry += num; }
query_infantry(num) { return infantry; }
add_bomb(num) { bomb += num; }
query_bomb(num) { return bomb; }
set_pclass(string x){ pclass = x; }
query_pclass(){ return pclass; }
void set_light_on(int num)     { light_on = num;        }
int query_light_on()           { return light_on;       }
void do_light(int new)         { if(new > 4) new = 4;
                                 if(new < -2) new = -2;
                                 set_light(new);        }
