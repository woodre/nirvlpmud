#define GOB present("prof_guild_object", this_player())
#define DOC_DIR "/players/guilds/warriors/doc/monk/"
#include <ansi.h>
inherit "obj/treasure";

reset(arg){
if(arg) return;
 set_id("book");
 set_alias("monk_book");
 set_short(HIW+"The Bo"+NORM+BOLD+"ok of "+HIW+"Monks"+NORM);
 set_long(
 "This is a large brown leather book with green highlights around\n"+
 "the cover.  By using this book, a Warrior can expand on their\n"+
 "knowledge.  \n"+
 "You may do any of the following:\n"+
 "join   -  Become a member of the Monk profession.\n"+
 "info   -  Get information on new powers offered.\n"+
 "train  -  Train a new skill.\n\n"+
 "Note: Choose carefully.\n");
 set_weight(10000);
 set_value(0);
 }

get(){ return 0; }

init(){
  add_action("train", "train");
  add_action("join", "join");
  add_action("info", "info");
  }

info(str){
   string named,named2;
	int i;

  if(this_player()->query_ghost()) return;
  if(!GOB){
     write("You do not need to know of such things until you have\n"+
           "joined.\n");
     return 1;
     }
	if(!str){
		write("                      "+HIM+"{ Monk }"+NORM+"\n");
		cat(DOC_DIR+"main.monk");
		write("                      "+HIM+"   -+-    "+NORM+"\n");
		return 1;
	}
	named = lower_case(str);
	named2 = strlen(named);
	i=0;
	while(i < named2) {
		if (str[i] < 'a' || str[i] > 'z'){
			if(str[i] != "_"){
				write("Subject not found.\n");
				return 1;
			}
		}
		i += 1;
	}
	if(file_size(DOC_DIR+str+".monk") == -1){
		write("Subject not found.\n");
		return 1;
	}
	write("                "+HIM+"{ Monk "+capitalize(str)+" }"+NORM+"\n");
	cat(DOC_DIR+str+".monk");
	write("                      "+HIM+" -+-    "+NORM+"\n");
	return 1;
}



join(){
  if(this_player()->query_ghost()) return;
  if(!GOB) return;
  if(GOB->query_monk()){ 
     write("You already belong to this school!\n");
     return 1;
     }
  if(GOB->query_glvl() < 40){
     write("You are not advanced enough to choose a new school.\n");
     return 1; 
     }
  if(!GOB->query_skill_pts()){
     write("You need at least one skill point in order to join\n"+
           "the monk school.\n");
     return 1;
     }
  GOB->add_skill_pts(-1);
  GOB->set_monk(1);
  write_file("/players/guilds/warriors/logs/MONK",
  this_player()->query_real_name()+" "+ctime(time())+".\n");
  GOB->silent_save();
  write("Welcome!  You are now a student of the Monk Discipline.\n"+
        "To see what skills are available, type 'train'.\n");
  return 1;
  }


train(str){

 if(!present("prof_guild_object", this_player())) return;
 if(this_player()->query_ghost()) return;
  if(GOB->query_glvl() < 40){
    write("You do not require the book to train your basic skills.\n");
    return 1;
    }
  if(!str){
    write("The book allows for training of the following abilities:\n"+
          "[SKILLS]             [Max Levels]\n"+
          "handtohand              (5)\n"+
          "dodge    (advanced)     (5)\n"+
          "blunt    (advanced)     (5)\n"+
          "polearm  (advanced)     (5)\n"+
          "xpunch                  (5)\n"+
          "xkick                   (5)\n"+
          "touch                   (5)\n"+
          "meditation              (5)\n"+
          "[DISCIPLINES]\n"+
          "blood                   (1)\n"+ 
          "time                    (1)\n"+
          "mind                    (1)\n\n"+
          "For more information on a discipline or skill,\n"+
          "type: info\n");
    return 1;
    }
  if(!GOB->query_monk()){ 
    write("You do not belong to the Monk school.  In order to join it\n"+
          "you must have a free skill point and type 'join'.\n");
    return 1;
    } 
  if(!GOB->query_skill_pts()){ 
    write("You have no skill points to spend.\n");
    return 1;
    }

 if(str == "handtohand" || str == "hand-to-hand"){
/* Prereqs */
    if(GOB->query_skills(17) < 4){
       write("You needed punch at level 4+ in order to raise this skill.\n");
       return 1;
       }
    if(GOB->query_skills(18) < 4){
       write("You needed kick at level 4+ in order to raise this skill.\n");
       return 1;
       }
    if(GOB->query_skills(80) > 4){
       write("You have already maxed this ability.\n");
       return 1;
       }
    write("You train Hand-to-Hand, raising it to level "+(GOB->query_skills(80) + 1)+".\n");
    GOB->add_skill_pts(-1);
    GOB->add_skills(80);
    GOB->silent_save();
    return 1;
    }
else if(str == "dodge"){   
/* Prereqs */
     if(GOB->query_skills(30) < 5){
       write("You needed dodge at level 5 in order to raise this skill.\n");
       return 1;
       }
     if(GOB->query_skills(60) < 1){
       write("You needed run in order to raise this skill.\n");
       return 1;
       }
     if(GOB->query_skills(30) > 9){
       write("You have already maxed this ability.\n");
       return 1;
       }
    write("You train Dodge, raising it to level "+(GOB->query_skills(30) + 1)+".\n");
    GOB->add_skill_pts(-1);
    GOB->add_skills(30);
    GOB->silent_save();
    return 1;
    }
else if(str == "blunt"){   
/* Prereqs */
     if(GOB->query_skills(1) < 10){
       write("You needed blunt at level 10 in order to raise this skill.\n");
       return 1;
       }
     if(GOB->query_skills(1) > 14){
       write("You have already maxed this ability.\n");
       return 1;
       }
    write("You train Blunt, raising it to level "+(GOB->query_skills(1) + 1)+".\n");
    GOB->add_skill_pts(-1);
    GOB->add_skills(1);
    GOB->silent_save();
    return 1;
    }
else if(str == "polearm"){   
/* Prereqs */
    if(GOB->query_skills(3) < 10){
       write("You needed Polearm at level 10 in order to raise this skill.\n");
       return 1;
       }
     if(GOB->query_skills(3) > 14){
       write("You have already maxed this ability.\n");
       return 1;
       }
    write("You train Polearm, raising it to level "+(GOB->query_skills(3) + 1)+".\n");
    GOB->add_skill_pts(-1);
    GOB->add_skills(3);
    GOB->silent_save();
    return 1;
    }
else if(str == "touch"){   
/* Prereqs */
    if(GOB->query_skills(80) < 1){
       write("You need Hand-to-Hand in order to raise this skill.\n");
       return 1;
       }
    if(GOB->query_skills(81) > 4){
       write("You have already maxed this ability.\n");
       return 1;
       }
    write("You train Touch, raising it to level "+(GOB->query_skills(81) + 1)+".\n");
    GOB->add_skill_pts(-1);
    GOB->add_skills(81);
    GOB->silent_save();
    return 1;
    }
else if(str == "xpunch"){   
/* Prereqs */
    if(GOB->query_skills(17) < 5){
       write("You need punch at level 5 in order to raise this skill.\n");
       return 1;
       }
    if(GOB->query_skills(21) > 4){
       write("You have already maxed this ability.\n");
       return 1;
       }
    write("You train XPunch, raising it to level "+(GOB->query_skills(21) + 1)+".\n");
    GOB->add_skill_pts(-1);
    GOB->add_skills(21);
    GOB->silent_save();
    return 1;
    }
else if(str == "xkick"){   
/* Prereqs */
    if(GOB->query_skills(18) < 1){
       write("You need kick at level 5 in order to raise this skill.\n");
       return 1;
       }
    if(GOB->query_skills(22) > 4){
       write("You have already maxed this ability.\n");
       return 1;
       }
    write("You train XKick, raising it to level "+(GOB->query_skills(22) + 1)+".\n");
    GOB->add_skill_pts(-1);
    GOB->add_skills(22);
    GOB->silent_save();
    return 1;
    }
else if(str == "meditation" || str == "meditate"){
    if(GOB->query_skills(85) > 4){
       write("You have already maxed this ability.\n");
       return 1;
       }
    write("You train Meditation, raising it to level "+(GOB->query_skills(85) + 1)+".\n");
    GOB->add_skill_pts(-1);
    GOB->add_skills(85);
    GOB->silent_save();
    return 1;
    }
else if(str == "blood"){   
/* Prereqs */
    if(GOB->query_skills(85) < 3){
       write("You need Meditation at 3+ in order to raise this skill.\n");
       return 1;
       }
    if(GOB->query_blood()){
       write("You have already maxed this ability.\n");
       return 1;
       }
    write("You train in the Blood Discipline.\n");
    GOB->add_skill_pts(-1);
    GOB->set_blood(1);
    GOB->silent_save();
    return 1;
    }
else if(str == "time"){   
/* Prereqs */
    if(GOB->query_skills(85) < 3){
       write("You need Meditation at 3+ in order to raise this skill.\n");
       return 1;
       }
    if(GOB->query_time()){
       write("You have already maxed this ability.\n");
       return 1;
       }
    write("You train in the Time Discipline.\n");
    GOB->add_skill_pts(-1);
    GOB->set_time(1);
    GOB->silent_save();
    return 1;
    }
else if(str == "mind"){   
/* Prereqs */
    if(GOB->query_skills(85) < 3){
       write("You need Meditation at 3+ in order to raise this skill.\n");
       return 1;
       }
    if(GOB->query_mind()){
       write("You have already maxed this ability.\n");
       return 1;
       }
    write("You train in the Mind Discipline.\n");
    GOB->add_skill_pts(-1);
    GOB->set_mind(1);
    GOB->silent_save();
    return 1;
    }
else{
    write("The Book cannot train you in that.\n");
    return 1;
    }
return 1;
}
