#define GOB present("prof_guild_object", this_player())
#define USER this_player()
#define DOC_DIR "/players/guilds/warriors/doc/knight/"
#include <ansi.h>
inherit "obj/treasure";

reset(arg){
if(arg) return;
 set_id("book");
 set_alias("knight_book");
 set_short(HIR+"The Bo"+NORM+RED+"ok of "+HIR+"Knights"+NORM);
 set_long(
 "This is a large brown leather book with red highlights around\n"+
 "the cover.  By using this book, a Warrior can expand on their\n"+
 "knowledge.  \n"+
 "You may do any of the following:\n"+
 "join   -  Become a member of the Knight Profession.\n"+
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
		write("                      "+HIW+"{ Knight }"+NORM+"\n");
		cat(DOC_DIR+"main.knight");
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
	if(file_size(DOC_DIR+str+".knight") == -1){
		write("Subject not found.\n");
		return 1;
	}
	write("                "+HIW+"{ Knight "+capitalize(str)+" }"+NORM+"\n");
	cat(DOC_DIR+str+".knight");
	write("                    "+HIW+" -+-    "+NORM+"\n");
	return 1;
}



join(){
  if(this_player()->query_ghost()) return;
  if(!GOB) return;
  if(GOB->query_knight()){ 
     write("You already belong to this school!\n");
     return 1;
     }
  if(GOB->query_glvl() < 40){
     write("You are not advanced enough to choose a new school.\n");
     return 1; 
     }
  if(!GOB->query_skill_pts()){
     write("You need at least one skill point in order to join\n"+
           "the knight school.\n");
     return 1;
     }
  GOB->add_skill_pts(-1);
  GOB->set_knight(1);
write_file("/players/guilds/warriors/logs/KNIGHT",
this_player()->query_real_name()+" "+ctime(time())+".\n");
  GOB->silent_save();
  write("Welcome!  You are now a student of the Knight Discipline.\n"+
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
    write("The book allows for training of the following abilities:\n\n"+
      HIW+"[SKILLS]             [Max Levels]  [SKILLS]            [Max Levels]"+NORM+"\n"+
          "edged    (advanced)     (5)        blunt    (advanced)    (5)\n"+
          "small    (advanced)     (5)        polearm  (advanced)    (5)\n"+
          "exotic   (advanced)     (5)                                  \n"+
          HIW+"           __________________________________________"+NORM+"\n\n"+
          "xstrike                 (5)        xbash                  (5)\n"+
          "study                   (5)        defend                 (1)\n"+
          "block    (advanced)     (5)        battle command         (5)\n"+
          "stamina                 (5)        \n\n"+
          "For more information on a skill,\n"+
          "type: info\n");
    return 1;
    }
   if(!GOB->query_knight()){ 
    write("You do not belong to the Knight school.  In order to join it\n"+
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
else if(str == "xbash"){
    if(GOB->query_skills(20) < 5){
       write("You needed bash at level 5 in order to raise this skill.\n");
       return 1;
       }
    if(GOB->query_skills(102) > 4){
       write("You have already maxed this ability.\n");
       return 1;
       }
    write("You train xbash, raising it\n"+
          "to level "+(GOB->query_skills(102) + 1)+".\n");
    GOB->add_skill_pts(-1);
    GOB->add_skills(102);
    GOB->silent_save();
    return 1;
    }
else if(str == "study"){
    if(USER->query_attrib("int") < 30 || USER->query_attrib("wil") < 30){
       write("You must have an intelligence and willpower of 30.\n");
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
else if(str == "defend"){
    if(GOB->query_skills(100) > 0){
       write("You have already maxed this ability.\n");
       return 1;
       }
    write("You train defend, raising it\n"+
          "to level "+(GOB->query_skills(100) + 1)+".\n");
    GOB->add_skill_pts(-1);
    GOB->add_skills(100);
    GOB->silent_save();
    return 1;
    }
else if(str == "stamina"){
    if(USER->query_attrib("sta") < 30){
       write("You need a stamina of at least 30.\n");
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
else if(str == "block"){
    if(GOB->query_skills(33) < 5){
       write("You needed block at level 5 in order to raise this skill.\n");
       return 1;
       }
    if(GOB->query_skills(33) > 9){
       write("You have already maxed this ability.\n");
       return 1;
       }
    write("You train block, raising it\n"+
          "to level "+(GOB->query_skills(33) + 1)+".\n");
    GOB->add_skill_pts(-1);
    GOB->add_skills(33);
    GOB->silent_save();
    return 1;
    }
else if(str == "battle command"){
    if(GOB->query_skills(104) > 4){
       write("You have already maxed this ability.\n");
       return 1;
       }
    write("You train battle command, raising it\n"+
          "to level "+(GOB->query_skills(104) + 1)+".\n");
    GOB->add_skill_pts(-1);
    GOB->add_skills(104);
    GOB->silent_save();
    return 1;
    }
else{
    write("The Book cannot train you in that.\n");
    return 1;
    }
return 1;
}
