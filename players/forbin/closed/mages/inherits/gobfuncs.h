check_schools() {
  int x, y, z;
  x = sizeof(SchoolsCosts);
  y = SchoolsLvl;
  z = 0;
  for(y = SchoolsLvl; y < x; y++) {
    if(SchoolsXP > (SchoolsCosts[y] * 1000)) {
      SchoolsPts += 10;
      SchoolsLvl++;
      if(!z) {
        tell_object(environment(this_object()),
         GCL+"Your magicial abilities have increased.\n"+NORM);
        z = 1;
        save_gob();
      }
    }
    else return;
  }
}

mixed show_schools_percentage() {
 int a, b, percent;
 if(SchoolsLvl < sizeof(SchoolsCosts)) {
   a = SchoolsXP - (SchoolsCosts[SchoolsLvl] * 1000);
   b = (SchoolsCosts[SchoolsLvl + 1] * 1000) - (SchoolsCosts[SchoolsLvl] * 1000);
   percent = ((a / b) * 100);
   return percent;
 }
 else
  return "MAX";  
}

check_attributes() {
  int x, y, z;
  x = sizeof(AttribsCosts);
  y = AttribsLvl;
  z = 0;
  for(y = AttribsLvl; y < x; y++) {
    if(AttribsXP > (AttribsCosts[y] * 1000)) {
      AttribsPts += 10;
      AttribsLvl++;
      if(!z) {
        tell_object(environment(this_object()),
         GCL+"Your attributes have increased.\n"+NORM);
        z = 1;
        save_gob();
      }
    }
    else return;
  }
}

int show_attributes_percentage() {
 int a, b, percent;
 if(AttribsLvl < sizeof(AttribsCosts)) {
   a = AttribsXP - (AttribsCosts[AttribsLvl] * 1000);
   b = (AttribsCosts[AttribsLvl + 1] * 1000) - (AttribsCosts[AttribsLvl] * 1000);
   percent = ((a / b) * 100);
   return percent;
 }
 else
  return 100;  
}

advance_checks() {
  /* Increased magicical aptitude - max of 100 mag */
  if(environment(this_object())->query_attrib("mag") < (SchoolsLvl + 30) {
    if(environment(this_object())->query_attrib("mag") > 29) {
      environment(this_object())->set_attrib("mag", (SchoolsLvl + 30));
    }
  }
}

void save_gob() {
  object e;
  if((e = environment()) && !e->query_npc()) {
    LearnedSpellsSave = deconstruct_mapping(LearnedSpells);
    save_object(SAVE_PATH + (string)e->query_real_name());
  }
}           

void backup_gob() {
  object e;
  if((e = environment()) && !e->query_npc()) {
    LearnedSpellsSave = deconstruct_mapping(LearnedSpells);
    save_object(SAVE_BAK + (string)e->query_real_name());
  }
}

int restore_gob() {
  int result;
  object e;
  if((e = environment()) && !e->query_npc()) {
    result = restore_object(SAVE_PATH + (string)e->query_real_name());
    LearnedSpells = reconstruct_mapping(LearnedSpellsSave);
    return result;
  }
}

update_gob() {                                             
  object new;
  save_object(SAVE_PATH + environment(this_object())->query_real_name());
  new = clone_object(GUILD_FILE);
  new->no_login_msg();
  move_object(new, environment());
  destruct(this_object());
}

guild_quit() { 
  ingame = 0; 
  CHAN_DAEMON->logout(environment(this_object()));
  environment(this_object())->set_guild_name("bloodfist");
  advance_checks();
  save_gob();
  return 0; 
}