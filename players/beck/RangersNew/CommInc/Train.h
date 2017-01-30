static string skill;
static int skill_points;
static int skill_verb;
static string skill_wiz;
static string Teacher;


ABuildPoints(int num){
   BuildPoint += num;
   return;
}

RBuildPoints(int num){
   BuildPoint -= num;
   return;
}

ASkillPoints(int num){
   SkillPoint += num;
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
   if (per < random(100) ){ return; }
   Teacher = teacher;
   call_out("message",1);
   

   input_to("FinishTrainRanger");

   return;

}
message(){
tell_object(ENVOB,Teacher+" asks: Would you like to advance your skill in "+skill+"?\n");
   tell_object(ENVOB ,"Your current level is "+skill_points+".\n");
}

FinishTrainRanger(string ack){
   
   if(ack == "yes"){
      ASkillPoints(-1);
      skill_points += 1;
      AddSkill(skill, skill_points, skill_verb, skill_wiz);
      tell_object(ENVOB, "You have advanced your skill in "+skill+".\n");
   }
   else {
      tell_object(ENVOB, "You can advance that skill another time then.\n");
      return;
   }
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
   
