/* Commands for the Skills Mapping */

void AddSkill (string skill_name, int skill_level, int skill_verb, string skill_wiz){
   string verb;
   if(Skills == 0){ 
      Skills = ([ ]);
   }

   Skills[skill_name] = ({ skill_level , skill_verb , skill_wiz });
   if(skill_verb == 1){
      add_action("RangerPower",skill_name);
   }
   if(skill_verb == 7){
      add_action("RangerPower",skill_name);
   }
   verb = "/players/"+skill_wiz+"/Rangers/Commands/"+capitalize(skill_name)+".c";
   verb->RangerInit();
}

QSkill(string skill_name){
   string *skills;

   if(Skills == 0){ 
      Skills = ([ ]); 
   }
   
   skills = keys(Skills);

   if(member_array(skill_name, skills) != -1 )
      return 1;
   else
      return 0;
}
   

QuerySkillLevel (string skill_name){
   string *skills;
   
   if(Skills == 0){ 
      Skills = ([ ]); 
   }

   if(!(skills = Skills[skill_name])){
      return 0;
   }
   skills = Skills[skill_name];

   return skills[0];
}

QuerySkillVerb (string skill_name){
   string *skills;
   
   if(Skills == 0){ 
      Skills = ([ ]); 
   }

   if(!(skills = Skills[skill_name])){
      return 0;
   }
   skills = Skills[skill_name];

   return skills[1];
}

QuerySkillWiz (string skill_name){
   string *skills;
   int hidcheck;
   
   if(Skills == 0){ 
      Skills = ([ ]); 
   }

   if(!(skills = Skills[skill_name])){
      hidcheck = member_array(skill_name, HiddenSkills);
      if(hidcheck != -1)
         return HiddenSkills[hidcheck + 1];
      return 0;
   }
   skills = Skills[skill_name];

   return skills[2];
}  



void RestoreSkillsSaved(){
   int i;
   string verb;
   
   GeneralSkills = ({});
   OffSkills = ({});
   DefSkills = ({});

   if(!SkillsSaved){
      SkillsSaved = ({});
   }

   Skills = ([ ]);

   if(!QNextSkillCost())
      NextSkillCost = 100;

   for (i=0;i<sizeof(SkillsSaved); i++){
      
      AddSkill(SkillsSaved[i], SkillsSaved[i+1], SkillsSaved[i+2], SkillsSaved[i+3]);

         if (SkillsSaved[i+2] == 1)
            add_action("RangerPower",SkillsSaved[i]);
         
         else if (SkillsSaved[i+2] == 2)
            GeneralSkills += ({ SkillsSaved[i] }); 

         else if (SkillsSaved[i+2] == 3)
            OffSkills += ({ SkillsSaved[i] });

         else if (SkillsSaved[i+2] == 4)
            DefSkills += ({ SkillsSaved[i] });

         else if (SkillsSaved[i+2] == 5){
            OffSkills += ({ SkillsSaved[i] });
            DefSkills += ({ SkillsSaved[i] });
         }
         else if (SkillsSaved[i+2] == 7){
            add_action("RangerPower",SkillsSaved[i]);
            DefSkills += ({ SkillsSaved[i] });
         }
      
      verb = "/players/"+SkillsSaved[i+3]+"/Rangers/Commands/"+capitalize(SkillsSaved[i])+".c";
      verb->RangerInit();
      i=i+3;

   }
}



void SaveSkillsSaved(){
   int i;
   string *skills;

   if(Skills ==0){
      Skills = ([ ]);
   }
   
   skills = keys(Skills);

   SkillsSaved = ({ });

   for(i=0; i<sizeof(skills); i++){
      SkillsSaved += ({ skills[i] });
      SkillsSaved += Skills[skills[i]];
   }
}


ShowSkills(){

   string *skills;
   int i;
   string verb;

   skills = keys(Skills);
   write("SKILLS\n");
   write(justify("Name:",15));
  
   write(justify("Level:",10));
  
   write(justify("Usable:",8));
   write(justify("Max:",5));
   write(justify("Help:",6));
   write(justify("Wiz:",12));
   write("\n");
   write("________________________________________________\n");
   for(i=0; i<sizeof(skills); i++){
      write(justify(capitalize(skills[i]),15));
      
      write(justify(QuerySkillLevel(skills[i]),10));
      
      write(justify(QuerySkillVerb(skills[i]) == 1 ? "Yes" : "No" , 8));
      verb = "/players/"+QuerySkillWiz(skills[i])+"/Rangers/Commands/"+capitalize(skills[i])+".c";
      write(justify(verb->QMax(), 5));
      write(justify(verb->QRangerInfo() == 1 ? "Yes" : "No" , 6));
      write(justify(capitalize(QuerySkillWiz(skills[i])), 12));
      write("\n");
   }
   for(i=0; i<sizeof(HiddenSkills); i++){
      write(justify(capitalize(HiddenSkills[i]),15));
      
      write(justify("-",10));
      
      write(justify("Yes",8));

      verb = "/players/"+HiddenSkills[i+1]+"/Rangers/Commands/"+capitalize(HiddenSkills[i])+".c";
      write(justify("-", 5));
      write(justify(verb->QRangerInfo() == 1 ? "Yes" : "No" , 6));
      write(justify(capitalize(HiddenSkills[i+1]),12));
      write("\n");
      i=i+1;
   }
   for(i=0; i<sizeof(SKILLS); i++){
      write(justify(capitalize(SKILLS[i]),15));
      
      write(justify("-",10));
      
      write(justify("Yes",8));

      verb = "/players/vital/Rangers/Commands/"+capitalize(SKILLS[i])+".c";
      write(justify("-", 5));
      write(justify(verb->QRangerInfo() == 1 ? "Yes" : "No" , 6));
      write(justify("Beck",12));
      write("\n");
   }
   write("\n");
   write("Unused Skill Points: "+QSkillPoints()+"\n");
   write("Build Points: "+QBuildPoints()+"\n");
   write("Next Skill Point: "+QNextSkillCost()+"\n");
   return 1;
 
}

AHiddenSkill(string name, string wizard, int verb){
  if(member_array(name, HiddenSkills) == -1){
     HiddenSkills += ({name, wizard});
     if(verb == 7){
        DefSkills += ({ name });
        add_action("RangerPower", name);
     }
     else if(verb == 6){
        OffSkills += ({ name });
        add_action("RangerPower", name);
     }
     else if(verb == 8){
        DefSkills += ({ name });
        OffSkills += ({ name });
        add_action("RangerPower", name);
     }
     else
        add_action("RangerPower", name);
  }
}

string
query_date()
{
  string stamp, date;
  stamp = ctime();
  date = stamp[4..10]+stamp[20..23];
  return date;
}

string
query_ranger_leadership()
{
  switch(this_object()->QuerySkillLevel("leadership"))
  {
    case 20:      RangerLeadership = "Team Leader"; break;
    case 15..19:  RangerLeadership = "Recruiter"; break;
    case 10..14:  RangerLeadership = "Moderator"; break;
    case 5..9:    RangerLeadership = "Trainer"; break;
    default:      RangerLeadership = "None";
  }
/*   if(this_object()->QuerySkillLevel("leadership") < 21) RangerLeadership = "Team Leader"; */
/*   if(this_object()->QuerySkillLevel("leadership") < 20) RangerLeadership = "Recruiter"; */
/*   if(this_object()->QuerySkillLevel("leadership") < 15) RangerLeadership = "Moderator"; */
/*   if(this_object()->QuerySkillLevel("leadership") < 10) RangerLeadership = "Trainer"; */
/*   if(this_object()->QuerySkillLevel("leadership") <  5) RangerLeadership = "None"; */
  return RangerLeadership;
}

string
query_ranger_type()
{
  switch(this_object()->QuerySkillLevel("morph"))
  {
    case 190..200:  RangerType = "Mystic Force"; break;
    case 170..189:  RangerType = "S.P.D."; break;
    case 150..169:  RangerType = "Dino Thunder"; break;
    case 130..149:  RangerType = "Ninja Storm"; break;
    case 110..129:  RangerType = "Wild Force"; break;
    case 100..109:  RangerType = "Time Force"; break;
    case   90..99:  RangerType = "Lightspeed"; break;
    case   80..89:  RangerType = "Rescue"; break;
    case   70..79:  RangerType = "Galaxy"; break;
    case   60..69:  RangerType = "Space"; break;
    case   50..59:  RangerType = "Turbo"; break;
    case   40..49:  RangerType = "Zeo"; break;
    case   30..39:  RangerType = "Ninja"; break;
    case   20..29:  RangerType = "Thunder"; break;
    case   10..19:  RangerType = "Dino"; break;
    default: RangerType = "Initiate";
  }
/*   if(this_object()->QuerySkillLevel("morph") < 201) RangerType = "Mystic Force"; */
/*   if(this_object()->QuerySkillLevel("morph") < 160) RangerType = "S.P.D."; */
/*   if(this_object()->QuerySkillLevel("morph") < 150) RangerType = "Dino Thunder"; */
/*   if(this_object()->QuerySkillLevel("morph") < 140) RangerType = "Ninja Storm"; */
/*   if(this_object()->QuerySkillLevel("morph") < 130) RangerType = "Wild Force"; */
/*   if(this_object()->QuerySkillLevel("morph") < 120) RangerType = "Time Force"; */
/*   if(this_object()->QuerySkillLevel("morph") < 100) RangerType = "Lightspeed"; */
/*   if(this_object()->QuerySkillLevel("morph") <  90) RangerType = "Rescue"; */
/*   if(this_object()->QuerySkillLevel("morph") <  80) RangerType = "Galaxy"; */
/*   if(this_object()->QuerySkillLevel("morph") <  70) RangerType = "Space"; */
/*   if(this_object()->QuerySkillLevel("morph") <  60) RangerType = "Turbo"; */
/*   if(this_object()->QuerySkillLevel("morph") <  50) RangerType = "Zeo"; */
/*   if(this_object()->QuerySkillLevel("morph") <  40) RangerType = "Ninja"; */
/*   if(this_object()->QuerySkillLevel("morph") <  30) RangerType = "Thunder"; */
/*   if(this_object()->QuerySkillLevel("morph") <  20) RangerType = "Dino"; */
/*   if(this_object()->QuerySkillLevel("morph") <  10) RangerType = "Initiate"; */
  return RangerType;
}

string
query_ranger_belt()
{
  switch(this_object()->QuerySkillLevel("combat"))
  {
    case    100:  RangerBelt = "Black (8)"; break;
    case     99:  RangerBelt = "Black (7)"; break;
    case     98:  RangerBelt = "Black (6)"; break;
    case     97:  RangerBelt = "Black (5)"; break;
    case     96:  RangerBelt = "Black (4)"; break;
    case 94..95:  RangerBelt = "Black (3)"; break;
    case 92..93:  RangerBelt = "Black (2)"; break;
    case 90..91:  RangerBelt = "Black (1)"; break;
    case 80..89:  RangerBelt = "Black"; break;
    case 70..79:  RangerBelt = "Brown"; break;
    case 60..69:  RangerBelt = "Purple"; break;
    case 50..59:  RangerBelt = "Blue"; break;
    case 40..49:  RangerBelt = "Green"; break;
    case 30..39:  RangerBelt = "Red"; break;
    case 20..29:  RangerBelt = "Orange"; break;
    case 10..19:  RangerBelt = "Yellow"; break;
    case   3..9:  RangerBelt = "White"; break;
    default:      RangerBelt = "None";
  }
/*   if(this_object()->QuerySkillLevel("combat") < 101) RangerBelt = "Black (8)"; */
/*   if(this_object()->QuerySkillLevel("combat") <  99) RangerBelt = "Black (7)"; */
/*   if(this_object()->QuerySkillLevel("combat") <  98) RangerBelt = "Black (6)"; */
/*   if(this_object()->QuerySkillLevel("combat") <  97) RangerBelt = "Black (5)"; */
/*   if(this_object()->QuerySkillLevel("combat") <  96) RangerBelt = "Black (4)"; */
/*   if(this_object()->QuerySkillLevel("combat") <  94) RangerBelt = "Black (3)"; */
/*   if(this_object()->QuerySkillLevel("combat") <  92) RangerBelt = "Black (2)"; */
/*   if(this_object()->QuerySkillLevel("combat") <  90) RangerBelt = "Black"; */
/*   if(this_object()->QuerySkillLevel("combat") <  79) RangerBelt = "Brown"; */
/*   if(this_object()->QuerySkillLevel("combat") <  69) RangerBelt = "Purple"; */
/*   if(this_object()->QuerySkillLevel("combat") <  59) RangerBelt = "Blue"; */
/*   if(this_object()->QuerySkillLevel("combat") <  49) RangerBelt = "Green"; */
/*   if(this_object()->QuerySkillLevel("combat") <  39) RangerBelt = "Red"; */
/*   if(this_object()->QuerySkillLevel("combat") <  29) RangerBelt = "Orange"; */
/*   if(this_object()->QuerySkillLevel("combat") <  19) RangerBelt = "Yellow"; */
/*   if(this_object()->QuerySkillLevel("combat") <   9) RangerBelt = "White"; */
/*   if(this_object()->QuerySkillLevel("combat") <   3) RangerBelt = "None"; */
  return RangerBelt;
}
