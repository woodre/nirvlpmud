set_karate_level(arg){ karate_level = arg; return 1; }
query_karate_level(){ return karate_level; }
set_old_title(str){ old_title = str; }
query_old_title(){ return old_title; }
set_old_pretitle(str){ old_pretitle = str; }
query_old_pretitle(){ return old_pretitle; }
set_ranger_color(str){ ranger_color = str; }
query_ranger_color(){ return ranger_color; }
set_ranger_ansi(str){ ranger_ansi = str; }
query_ranger_ansi(){ return ranger_ansi; }
set_ranger_weapon(str){ ranger_weapon = str; }
query_ranger_weapon(){ return ranger_weapon; }
set_ranger_animal(str){ ranger_animal = str; }
query_ranger_animal(){ return ranger_animal; }
set_ranger_thunderzord(str){ ranger_thunderzord = str; }
query_ranger_thunderzord(str){ return ranger_thunderzord; }
add_skill_practice(arg){
   skill_practice += arg;
   if(skill_practice < 0){
      skill_practice = 0;
   }
   return 1;
}
morph_on() { morphed = 1; return 1;}
morph_off() {morphed = 0; return 1;}
query_morphed(){ return morphed;}
set_strength(arg){ strength = arg; return 1; }
set_speed(arg){ speed = arg; return 1; }
set_endurance(arg){ endurance = arg; return 1; }
query_strength(){ return strength; }
query_speed(){ return speed; }
query_endurance(){ return endurance; }
muff_on(){
   if(muffles == 1){
      muffles = 0;
      write("Your guild channel muffle is ON.\n");
      return 1;
   }
   muffles = 1;
   write("Your guild channel muffle is OFF.\n");
   return 1;
}
query_muff(){ return muffles; }
set_skills(arg){ skills = ({ arg }); return 1; }
see_offense(){
   int k;
   write("Offensive skills:\n");
   for(k=0; k<sizeof(offense); k++){
      write(justify(offense[k],20));
      write("\n");
   }
   return 1;
}
see_defense(){
   int k;
   write("Defensive skills:\n");
   for(k=0; k<sizeof(defense); k++){
      write(justify(defense[k],20));
      write("\n");
   }
   return 1;
}
add_skill(arg){
   int i;
   for(i=0; i<sizeof(skills); i++){
      if(skills[i] == arg){
         return 0;
       }
   }
   skills += ({ arg });
   return 1;
}
check_offense(str){
   if(member_array(str,offense) != -1){
      return 1;
   }
   return 0;
}
check_defense(str){
   if(member_array(str, defense) !=-1){
      return 1;
   }
   return 0;
}
check_skills(str){
   if(member_array(str, skills) != -1){
      return 1;
   }
   return 0;
}
set_defense(arg){ defense = ({ arg }); return 1; }
add_defense(arg){
   int i;
   for(i=0;i<sizeof(defense); i++){
      if(defense[i] == arg){
         return 0;
       }}
   defense += ({ arg });
   return 1;
}
query_defense(){
   int i;
   int j;
   int n;
   int m;
   string skill;
   n = 0;
   for(i=0; i<sizeof(defense); i++){
      n = n + 1;
   }
   m = random(n);
   for(j=0; j<sizeof(defense); j++){
      if(j == m){
         skill = defense[j];
       }
   }
   set_defense_pro(skill, query_defense_pro(skill)+1);
   return skill;
}
set_offense(arg){ offense = ({ arg }); return 1; }
add_offense(arg){
   int i;
   for(i=0;i<sizeof(offense); i++){
      if(offense[i] == arg){
         return 0;
       }}
   offense += ({ arg });
   return 1;
}
query_offense(){
   int i;
   int j;
   int n;
   int m;
   string skill;
   n = 0;
   for(i=0; i<sizeof(offense); i++){
      n = n + 1;
   }
   m = random(n);
   for(j=0; j<sizeof(offense); j++){
      if(j == m){
         skill = offense[j];
       }
   }
   set_offense_pro(skill, query_offense_pro(skill)+1);
   return skill;
}
set_need_megazord(arg){ need_megazord = arg; }
query_need_megazord(){ return need_megazord; }
set_has_thunderzord(arg){ has_thunderzord = arg; }
query_has_thunderzord(){ return has_thunderzord; }
set_has_battlezord(arg){ has_battlezord = arg; }
query_has_battlezord(){ return has_battlezord; }
