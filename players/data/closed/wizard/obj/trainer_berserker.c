#define GOB present("prof_guild_object", this_player())
#define USER this_player()
#define DOC_DIR "/players/maledicta/closed/w/doc/berserker/"
#include "/players/maledicta/ansi.h"
inherit "obj/treasure";

int covered;

reset(arg){
if(arg) return;
 set_weight(10000);
 set_value(0);
 covered = 1;
 }

get(){ return 0; }

id(str){ return str == "book" || str == "pedestal" || str == "berserker_book"; }

short(){
if(covered){ return GRN+"a vine covered "+NORM+HIW+"pedestal"+NORM; }
else{ return HIB+"The Bo"+NORM+BLU+"ok of "+HIB+"Berserkers"+NORM; }
}

long(){
 if(covered){
  write("This is a vine covered pedestal.  You could\n"+
        "probably 'uncover' it.\n");
  return 1;
  }
 else{
 write(
 "This is a large brown leather book with blue highlights around\n"+
 "the cover.  By using this book, a Warrior can expand on their\n"+
 "knowledge.  \n"+
 "You may do any of the following:\n"+
 "join   -  Become a member of the Berserker Profession.\n"+
 "info   -  Get information on new powers offered.\n"+
 "train  -  Train a new skill.\n\n"+
 "Note: Choose carefully.\n");
 return 1;
 }
}

init(){
  add_action("train", "train");
  add_action("join", "join");
  add_action("info", "info");
  add_action("uncover", "uncover");
  }

uncover(str){ 
 if(!str){ write("Uncover what?\n");
           return 1;
           }
 if(str != "pedestal"){ write("uncover what?\n"); return 1; }
 write("You uncover the pedestal.\n");
 covered = 0;
 command("look", this_player());
 return 1;
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
		write("                      "+HIW+"{ Berserker }"+NORM+"\n");
		cat(DOC_DIR+"main.berserker");
		write("                      "+HIW+"   -+-    "+NORM+"\n");
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
	if(file_size(DOC_DIR+str+".berserker") == -1){
		write("Subject not found.\n");
		return 1;
	}
	write("                "+HIW+"{ Berserker "+capitalize(str)+" }"+NORM+"\n");
	cat(DOC_DIR+str+".berserker");
	write("                    "+HIW+" -+-    "+NORM+"\n");
	return 1;
}



join(){
  if(this_player()->query_ghost()) return;
  if(!GOB) return;
  if(GOB->query_berserker()){ 
     write("You already belong to this school!\n");
     return 1;
     }
  if(GOB->query_glvl() < 41){
     write("You are not advanced enough to choose a new school.\n");
     return 1; 
     }
  if(!GOB->query_skill_pts()){
     write("You need at least one skill point in order to join\n"+
           "the berserker school.\n");
     return 1;
     }
   if(USER->query_wimpy()){
     write("You must first unset your wimpy!\n");
     return 1;
     }
  GOB->add_skill_pts(-1);
  GOB->set_berserker(1);
write_file("/players/maledicta/closed/log/BERSERKER",
this_player()->query_real_name()+" "+ctime(time())+".\n");
  GOB->silent_save();
  write("Welcome!  You are now a student of the Berserker Discipline.\n"+
        "To see what skills are available, type 'train'.\n");
  return 1;
  }


train(str){

 if(!present("prof_guild_object", this_player())) return;
 if(this_player()->query_ghost()) return;
  if(GOB->query_glvl() < 41){
    write("You do not require the book to train your basic skills.\n");
    return 1;
    }
  if(!str){
    write("The book allows for training of the following abilities:\n\n"+
      HIW+"[SKILLS]             [Max Levels]  [SKILLS]            [Max Levels]"+NORM+"\n"+
          "edged    (advanced)     (5)        blunt    (advanced)    (5)\n"+
          "polearm  (advanced)     (5)        exotic   (advanced)    (5)\n"+
      HIW+"           __________________________________________"+NORM+"\n\n"+
          "xcharge                 (5)        rage                   (5)\n"+
          "frenzy                  (5)        tough                  (5)\n"+
          "stamina                 (5)        strength               (5)\n"+
          "\n\n"+
          "For more information on a skill,\n"+
          "type: info\n");
    return 1;
    }
   if(!GOB->query_berserker()){ 
    write("You do not belong to the Berserker school.  In order to join it\n"+
          "you must have a free skill point and type 'join'.\n");
    return 1;
    } 
  if(!GOB->query_skill_pts()){ 
    write("You have no skill points to spend.\n");
    return 1;
    }

 if(str == "edged"){
/* Prereqs */
    if(GOB->query_skills(2) < 10){
       write("You needed edged at level 10+ in order to raise this skill.\n");
       return 1;
       }
    if(GOB->query_skills(2) > 14){
       write("You have already maxed this ability.\n");
       return 1;
       }
    write("You train Edged, raising it to level "+(GOB->query_skills(2) + 1)+".\n");
    GOB->add_skill_pts(-1);
    GOB->add_skills(2);
    GOB->silent_save();
    return 1;
    }
else if(str == "blunt"){
/* Prereqs */
    if(GOB->query_skills(1) < 10){
       write("You needed blunt at level 10+ in order to raise this skill.\n");
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
       write("You needed polearm at level 10+ in order to raise this skill.\n");
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
else if(str == "exotic"){
/* Prereqs */
    if(GOB->query_skills(5) < 10){
       write("You needed exotic at level 10+ in order to raise this skill.\n");
       return 1;
       }
    if(GOB->query_skills(5) > 14){
       write("You have already maxed this ability.\n");
       return 1;
       }
    write("You train Exotic, raising it to level "+(GOB->query_skills(5) + 1)+".\n");
    GOB->add_skill_pts(-1);
    GOB->add_skills(5);
    GOB->silent_save();
    return 1;
    }
else if(str == "xcharge"){
    if(GOB->query_skills(19) < 5){
       write("You needed charge at level 5 in order to raise this skill.\n");
       return 1;
       }
    if(GOB->query_skills(123) > 4){
       write("You have already maxed this ability.\n");
       return 1;
       }
    write("You train xcharge, raising it\n"+
          "to level "+(GOB->query_skills(123) + 1)+".\n");
    GOB->add_skill_pts(-1);
    GOB->add_skills(123);
    GOB->silent_save();
    return 1;
    }
else if(str == "rage"){
    if(GOB->query_skills(19) < 5){
       write("You needed charge at level 5 in order to raise this skill.\n");
       return 1;
       }
    if(GOB->query_skills(120) > 4){
       write("You have already maxed this ability.\n");
       return 1;
       }
    write("You train rage, raising it\n"+
          "to level "+(GOB->query_skills(120) + 1)+".\n");
    GOB->add_skill_pts(-1);
    GOB->add_skills(120);
    GOB->silent_save();
    return 1;
    }
else if(str == "frenzy"){
    if(GOB->query_skills(19) < 5){
       write("You needed charge at level 5 in order to raise this skill.\n");
       return 1;
       }
    if(GOB->query_skills(124) > 4){
       write("You have already maxed this ability.\n");
       return 1;
       }
    write("You train frenzy, raising it\n"+
          "to level "+(GOB->query_skills(124) + 1)+".\n");
    GOB->add_skill_pts(-1);
    GOB->add_skills(124);
    GOB->silent_save();
    return 1;
    }
else if(str == "tough"){
    if(USER->query_attrib("sta") < 20){
       write("You need a stamina of at least 20.\n");
       return 1;
       }
    if(GOB->query_skills(121) > 4){
       write("You have already maxed this ability.\n");
       return 1;
       }
    write("You train tough, raising it\n"+
          "to level "+(GOB->query_skills(121) + 1)+".\n");
    GOB->add_skill_pts(-1);
    GOB->add_skills(121);
    GOB->silent_save();
    return 1;
    }
else if(str == "stamina"){
    if(USER->query_attrib("sta") < 20){
       write("You need a stamina of at least 20.\n");
       return 1;
       }
    if(GOB->query_xsta() > 4){
       write("You have already maxed Stamina.\n");
       return 1;
       }
    write("You train stamina.\n");
    GOB->add_skill_pts(-1);
    GOB->add_xsta(1);
    GOB->silent_save();
    return 1;
    }
else if(str == "strength"){
    if(USER->query_attrib("str") < 20){
       write("You need a strength of at least 20.\n");
       return 1;
       }
    if(GOB->query_xstr() > 8){
       write("You have already maxed Strength.\n");
       return 1;
       }
    write("You train strength.\n");
    GOB->add_skill_pts(-1);
    GOB->add_xstr(2);
    GOB->silent_save();
    return 1;
    }
else{
    write("The Book cannot train you in that.\n");
    return 1;
    }
return 1;
}
