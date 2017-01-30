static string skill;
static int skill_points;
static int skill_verb;
static string skill_wiz;
static string Teacher;


ABuildPoints(int num){
   BuildPoint += num;
   SaveRanger();
   return;
}

RBuildPoints(int num){
   BuildPoint -= num;
   return;
}

ASkillPoints(int num){
   SkillPoint += num;
   SaveRanger();
   return;
}

RSkillPoints(int num){
   SkillPoint -= num;
   return;
}

QSkillPoints(){
   return SkillPoint;
}
QBuildPoints(){
   return BuildPoint;
}

TrainRangerSkill(string skill_name, int skill_verb_num, string skill_wiz_name, string teacher, int per){
   string file;
   skill = skill_name;
   skill_verb = skill_verb_num;
   skill_wiz = skill_wiz_name;
   

   if (QSkill(skill_name))
      skill_points = QuerySkillLevel(skill_name);
   else
      skill_points = 0;

   if ( QSkillPoints() == 0 ){
      return;
   }
   file = "/players/"+skill_wiz+"/Rangers/Commands/"+capitalize(skill)+".c";

   if (skill_points >= file->QMax()){
      return;
   }
   if (per < random(100) ){ return; }
   Teacher = teacher;
   call_out("message",1);
   
   if(ENVOB->is_kid()){
      return;
   }
   else {

      input_to("FinishTrainRanger");
   }

   return;

}
message(){
   object trainee;
   if(ENVOB){
      if(ENVOB->is_player()){
         tell_object(ENVOB,Teacher+" asks: Would you like to advance your skill in "+skill+"? (yes/no)\n");
         tell_object(ENVOB ,"Your current level is "+skill_points+".\n");
      }
      else if(ENVOB->is_kid()){
         tell_room(ENV(ENVOB), Teacher+" asks: Would "+ENVOB->query_name()+" like to advance their skill in "+skill+"? (yes/no)\n");
         tell_room(ENV(ENVOB) ,"Their current level is "+skill_points+".\n");
      }
      else
         return;
   }
   else
      return;
}


FinishTrainRanger(string ack){
   if(ack == "yes" && skill){
      ASkillPoints(-1);
      skill_points += 1;
      AddSkill(skill, skill_points, skill_verb, skill_wiz);
      SaveSkillsSaved();
      SaveRanger();
      if(ENVOB->is_kid()){
         tell_room(ENV(ENVOB), ENVOB->query_name()+" has advanced their skill in "+skill+".\n");
      }
      else
         tell_object(ENVOB, "You have advanced your skill in "+skill+".\n");
   }
   else {
      if(ENVOB->is_kid()){
         tell_room(ENV(ENVOB), ENVOB->query_name()+" can advance that skill another time then.\n");
      }
      else
         tell_object(ENVOB, "You can advance that skill another time then.\n");
      
   }
   skill = 0;
   return;
 
}

QNextSkillCost(){
   return NextSkillCost;
}

ConvertSkillPoint(){
   int rep;
   if(BuildPoint > NextSkillCost){
      while(BuildPoint > NextSkillCost){
         RBuildPoints(NextSkillCost);
         ASkillPoints(1);
         NextSkillCost = NextSkillCost * 104;
         NextSkillCost = NextSkillCost / 100;
         if(NextSkillCost > 1000000)
            NextSkillCost = 1000000;
         rep += 1;
      }
      write("You have added "+rep+" skill point(s), which you may use to advance any skill.\n");
      write("Your next skill will cost you "+NextSkillCost+".\n");
      return 1;
   }
   else {
      write("You have not invested enough to obtain the next skill point.\n");
      return 1;
   }
}

ReTrainRanger(string skill_name){
   if(QSkill(skill_name)){
      skill = skill_name;
      skill_points = QuerySkillLevel(skill_name);
      skill_verb = QuerySkillVerb(skill_name);
      skill_wiz = QuerySkillWiz(skill_name); 
      if(skill_points < 6){ 
         write("You must keep at least 5 skill points in every skill.\n");
         return 0;
      }
      skill_points -= 1;
      AddSkill(skill, skill_points, skill_verb, skill_wiz);
      SaveSkillsSaved();
      SaveRanger();
      ASkillPoints(1);
      return 1;
   }
   return 0;
}
