#define GOB present("prof_guild_object", this_player())
#define USER this_player()
#define DOC_DIR "/players/maledicta/closed/w/doc/assassin/"
#include "/players/maledicta/ansi.h"
inherit "obj/treasure";

reset(arg){
if(arg) return;
 set_id("book");
 set_alias("assassin_book");
 set_short(HIW+"The Bo"+NORM+BOLD+"ok of "+HIW+"Assassins"+NORM);
 set_long(
 "This is a large brown leather book with grey highlights around\n"+
 "the cover.  By using this book, a Warrior can expand on their\n"+
 "knowledge.  \n"+
 "You may do any of the following:\n"+
 "join   -  Become a member of the Assassin Profession.\n"+
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
		write("                      "+HIW+"{ Assassin }"+NORM+"\n");
		cat(DOC_DIR+"main.assassin");
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
	if(file_size(DOC_DIR+str+".assassin") == -1){
		write("Subject not found.\n");
		return 1;
	}
	write("                "+HIW+"{ Assassin "+capitalize(str)+" }"+NORM+"\n");
	cat(DOC_DIR+str+".assassin");
	write("                    "+HIW+"-+-    "+NORM+"\n");
	return 1;
}



join(){
  if(this_player()->query_ghost()) return;
  if(!GOB) return;
  if(GOB->query_assassin()){ 
     write("You already belong to this school!\n");
     return 1;
     }
  if(GOB->query_glvl() < 41){
     write("You are not advanced enough to choose a new school.\n");
     return 1; 
     }
  if(!GOB->query_skill_pts()){
     write("You need at least one skill point in order to join\n"+
           "the assassin school.\n");
     return 1;
     }
  GOB->add_skill_pts(-1);
  GOB->set_assassin(1);
write_file("/players/maledicta/closed/log/ASSASSIN",
this_player()->query_real_name()+" "+ctime(time())+".\n");
  GOB->silent_save();
  write("Welcome!  You are now a student of the Assassin Discipline.\n"+
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
          "edged    (advanced)     (5)        small    (advanced)    (5)\n\n"+
          HIW+"           __________________________________________"+NORM+"\n\n"+
          "xstrike                 (5)        xthrow                 (5)\n"+
          "study                   (5)        move silently          (1)\n"+
          "offhand    (advanced)   (5)        hide                   (3)\n"+
          "stealth                 (5)        backstab               (5)\n"+
          "riposte                 (5)        blindfight (advanced)  (1)\n"+
          "\n"+
          "For more information on a skill,\n"+
          "type: info\n");
    return 1;
    }
   if(!GOB->query_assassin()){ 
    write("You do not belong to the Assassin school.  In order to join it\n"+
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
else if(str == "small"){
/* Prereqs */
    if(GOB->query_skills(6) < 10){
       write("You needed small at level 10+ in order to raise this skill.\n");
       return 1;
       }
    if(GOB->query_skills(6) > 14){
       write("You have already maxed this ability.\n");
       return 1;
       }
    write("You train Small, raising it to level "+(GOB->query_skills(6) + 1)+".\n");
    GOB->add_skill_pts(-1);
    GOB->add_skills(6);
    GOB->silent_save();
    return 1;
    }
else if(str == "xstrike"){
    if(GOB->query_skills(16) < 5){
       write("You needed strike at level 5 in order to raise this skill.\n");
       return 1;
       }
    if(GOB->query_skills(103) > 4){
       write("You have already maxed this ability.\n");
       return 1;
       }
    write("You train xstrike, raising it\n"+
          "to level "+(GOB->query_skills(103) + 1)+".\n");
    GOB->add_skill_pts(-1);
    GOB->add_skills(103);
    GOB->silent_save();
    return 1;
    }
else if(str == "xthrow"){
    if(GOB->query_skills(15) < 5){
       write("You needed throw at level 5 in order to raise this skill.\n");
       return 1;
       }
    if(GOB->query_skills(116) > 4){
       write("You have already maxed this ability.\n");
       return 1;
       }
    write("You train xthrow, raising it\n"+
          "to level "+(GOB->query_skills(116) + 1)+".\n");
    GOB->add_skill_pts(-1);
    GOB->add_skills(116);
    GOB->silent_save();
    return 1;
    }
else if(str == "study"){
    if(USER->query_attrib("int") < 20){
       write("You must have an intelligence of 20.\n");
       return 1;
       }
    if(GOB->query_skills(101) > 4){
       write("You have already maxed this ability.\n");
       return 1;
       }
    write("You train study, raising it\n"+
          "to level "+(GOB->query_skills(101) + 1)+".\n");
    GOB->add_skill_pts(-1);
    GOB->add_skills(101);
    GOB->silent_save();
    return 1;
    }
else if(str == "move silently" || str == "move silent" || str == "move"){
    if(GOB->query_skills(113) < 1){
       write("You need hide in order to raise this skill.\n");
       return 1;
       }
    if(GOB->query_skills(115) > 0){
       write("You have already maxed this ability.\n");
       return 1;
       }
    write("You train move silently, raising it\n"+
          "to level "+(GOB->query_skills(115) + 1)+".\n");
    GOB->add_skill_pts(-1);
    GOB->add_skills(115);
    GOB->silent_save();
    return 1;
    }
else if(str == "stealth"){
    if(USER->query_attrib("ste") < 20){
       write("You need a stealth of at least 20.\n");
       return 1;
       }
    if(GOB->query_xste() > 8){
       write("You have already maxed Stealth.\n");
       return 1;
       }
    write("You train stealth.\n");
    GOB->add_skill_pts(-1);
    GOB->add_xste(2);
    GOB->silent_save();
    return 1;
    }

else if(str == "backstab"){
    if(GOB->query_skills(113) < 1){
       write("You need hide in order to raise this skill.\n");
       return 1;
       }
    if(GOB->query_skills(6) < 10){
       write("You needed small at level 10+ in order to raise this skill.\n");
       return 1;
       }
    if(GOB->query_skills(112) > 4){
       write("You have already maxed this ability.\n");
       return 1;
       }
    write("You train backstab, raising it\n"+
          "to level "+(GOB->query_skills(112) + 1)+".\n");
    GOB->add_skill_pts(-1);
    GOB->add_skills(112);
    GOB->silent_save();
    return 1;
    }
else if(str == "hide"){
    if(USER->query_attrib("ste") < 20){
       write("You need a stealth of at least 20.\n");
       return 1;
       }
    if(GOB->query_skills(113) > 2){
       write("You have already maxed this ability.\n");
       return 1;
       }
    write("You train hide, raising it\n"+
          "to level "+(GOB->query_skills(113) + 1)+".\n");
    GOB->add_skill_pts(-1);
    GOB->add_skills(113);
    GOB->silent_save();
    return 1;
    }

else if(str == "riposte"){
    if(GOB->query_skills(6) < 10){
       write("You needed small at level 10+ in order to raise this skill.\n");
       return 1;
       }
    if(GOB->query_skills(32) < 5){
       write("You needed offhand at level 5+ in order to raise this skill.\n");
       return 1;
       }
    if(GOB->query_skills(114) > 4){
       write("You have already maxed this ability.\n");
       return 1;
       }
    write("You train riposte, raising it\n"+
          "to level "+(GOB->query_skills(114) + 1)+".\n");
    GOB->add_skill_pts(-1);
    GOB->add_skills(114);
    GOB->silent_save();
    return 1;
    }
else if(str == "offhand"){
    if(GOB->query_skills(32) < 5){
       write("You needed offhand at level 5 in order to raise this skill.\n");
       return 1;
       }
    if(GOB->query_skills(32) > 9){
       write("You have already maxed this ability.\n");
       return 1;
       }
    write("You train offhand, raising it\n"+
          "to level "+(GOB->query_skills(32) + 1)+".\n");
    GOB->add_skill_pts(-1);
    GOB->add_skills(32);
    GOB->silent_save();
    return 1;
    }
else if(str == "blindfight"){
    if(GOB->query_skills(70) < 2){
       write("You needed blindfight at level 2 in order to raise this skill.\n");
       return 1;
       }
    if(GOB->query_skills(70) > 2){
       write("You have already maxed this ability.\n");
       return 1;
       }
    write("You train blindfight, raising it\n"+
          "to level "+(GOB->query_skills(32) + 1)+".\n");
    GOB->add_skill_pts(-1);
    GOB->add_skills(70);
    GOB->silent_save();
    return 1;
    }
else{
    write("The Book cannot train you in that.\n");
    return 1;
    }
return 1;
}
