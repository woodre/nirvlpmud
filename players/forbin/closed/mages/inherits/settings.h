void set_school(int x, int y) { Schools[l] = y; }
void add_school(int x, int y) { Schools[l] += y; }
void sub_school(int x, int y) { Schools[l] -= y; }

int query_school(int x) {
  if(x >= 0 && x < 8) return Schools[x];
}

void set_school_bonus(int x, int y) { SchoolsBonus[x] = y; }
void add_school_bonus(int x, int y) { SchoolsBonus[x] += y; }
void sub_school_bonus(int x, int y) { SchoolsBonus[x] -= y; }

int query_school_bonus(int x) {
  if(x >= 0 && x < 8) return SchoolsBonus[x];
}

void set_attrib(int x, int y) { Attribs[x] = y; }
void add_attrib(int x, int y) { Attribs[x] += y; }
void sub_attrib(int x, int y) { Attribs[x] -= y; }

int query_attrib(int x) {
  if(x >= 0 && x < 4) return Attribs[x];
}

void set_attrib_bonus(int x, int y) { AttribsBonus[x] = y; }
void add_attrib_bonus(int x, int y) { AttribsBonus[x] += y; }
void sub_attrib_bonus(int x, int y) { AttribsBonus[x] -= y; }

int query_attrib_bonus(int x) {
  if(x >= 0 && x < 4) return AttribsBonus[x];
}

void set_school_exp(int x) { SchoolsXP = x; }
void add_school_exp(int x) { SchoolsXP += x; }
void sub_school_exp(int x) { SchoolsXP -= x; }
int query_school_exp() { return SchoolsXP; }

void set_attrib_exp(int x) { AttribsXP = x; }
void add_attrib_exp(int x) { AttribsXP += x; }
void sub_attrib_exp(int x) { AttribsXP -= x; }
int query_attrib_exp() { return AttribsXP; }

int query_hbeats() { return HBeats; }

int query_casting() { return Casting; }

string query_current_spell() { return CurrentSpell; }

void set_casting(int casting, string currentspell) {
  Casting = casting;
  CurrentSpell = CMD_DIR+"spell_"+currentspell+".c";
}

void clear_spell() {
  Casting = 0;
  CurrentSpell = ""; 
}
