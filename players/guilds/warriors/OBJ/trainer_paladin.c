#define GOB present("prof_guild_object", this_player())
#define DOC_DIR "/players/guilds/warriors/doc/paladin/"

#include <ansi.h>
inherit "obj/treasure";

reset(arg){
  if(arg) return;
  set_id("book");
  set_alias("monk_book");
  set_short(HIB+"The Bo"+NORM+BLU+"ok of "+HIB+"Paladins"+NORM);
  set_long(
"This is a large brown leather book with blue highlights around\n"+
"the cover.  By using this book, a Warrior can expand on their\n"+
"knowledge.  \n"+
"You may do any of the following:\n"+
"join   -  Become a member of the Paladin Profession.\n"+
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
  add_action("choose", "choose");
}

choose(str){
  if(!GOB->query_paladin()) return 0;
  if(!str){
    write("choose <good or evil>\n");
    return 1;
  }
  if(GOB->query_chosen_align()){
    write("You have already chosen!\n");
    return 1;
  }
  if(str == "good"){ 
    GOB->set_chosen_align("good"); 
    write("You choose to be a Good Paladin.\n");
    return 1;
  }
  else if(str == "evil"){
    GOB->set_chosen_align("evil"); 
    write("You choose to be an Evil Paladin.\n");
    return 1;
  }
  else{
    write("choose <good or evil>\n");
    return 1;
  }
  return 1;
}

info(str){
  string named,named2;
  int i;

  if(this_player()->query_ghost()) return;
  if(!GOB){
    write("You do not need to know of such things until you have joined.\n");
    return 1;
  }
  if(!str){
    write("                      "+HIB+"{ Paladin }"+NORM+"\n");
    cat(DOC_DIR+"main.paladin");
    write("                      "+HIB+"   -+-    "+NORM+"\n");
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
  if(file_size(DOC_DIR+str+".paladin") == -1){
    write("Subject not found.\n");
    return 1;
  }
  write("                "+HIB+"{ Paladin "+capitalize(str)+" }"+NORM+"\n");
  cat(DOC_DIR+str+".paladin");
  write("                    "+HIB+" -+-    "+NORM+"\n");
  return 1;
}

join(){
  if(this_player()->query_ghost()) return;
  if(!GOB) return;
  if(GOB->query_paladin()){ 
     write("You already belong to this school!\n");
     return 1;
  }
  if(GOB->query_glvl() < 40){
     write("You are not advanced enough to choose a new school.\n");
     return 1; 
  }
  if(!GOB->query_skill_pts()){
     write("You need at least one skill point in order to join\n"+
           "the paladin school.\n");
     return 1;
  }
  write_file("/players/guilds/warriors/logs/PALADIN",
             this_player()->query_real_name()+" on "+ctime(time())+"\n");
  GOB->add_skill_pts(-1);
  GOB->set_paladin(1);
  GOB->silent_save();
  write("Welcome!  You are now a student of the Paladin Discipline.\n"+
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
          HIR+"Prerequisite:"+NORM+"  holy studies\n\n"+
          HIW+"[SKILLS]             [Max Levels]  [SKILLS]            [Max Levels]"+NORM+"\n"+
          "edged    (advanced)     (5)        blunt    (advanced)    (5)\n"+
          "small    (advanced)     (5)        polearm  (advanced)    (5)\n"+
          "exotic   (advanced)     (5)\n\n"+
          HIG+"AURAS"+NORM+"\n"+
          "protection from 'evil'  (5)        protection from 'good' (5)\n"+
          "regeneration            (5)\n\n"+
          HIY+"POWERS (GOOD)                      "+HIR+"POWERS (EVIL)"+NORM+"\n"+
          "holy bolt               (5)        plague                 (5)\n"+  
          "release                 (1)        release                (1)\n"+ 
          "redeem                  (5)        corrupt                (5)\n\n"+
          HIM+"POWERS (BOTH)"+NORM+"\n"+
          "sacrifice               (5)        detect alignment       (1)\n"+
          "cleanse                 (1)        \n"+          
          "For more information on a skill,\n"+
          "type: info\n");
    return 1;
  }
  if(!GOB->query_chosen_align()){ 
    write("You must first choose your alignment.  By choosing your alignment\n"+
          "you will be forced to be good or evil, or your powers will fail.\n"+
          "Choose carefully.  'choose <good or evil>'\n");
    return 1;
  }
  if(!GOB->query_paladin()){ 
    write("You do not belong to the Paladin school.  In order to join it\n"+
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
  else if(str == "protection from evil" || str == "evil"){
    if(GOB->query_skills(150) < 1){
      write("You need Holy Studies in order to obtain this ability.\n");
      return 1;
    } 
    if(GOB->query_chosen_align() == "evil"){
      write("This can only be chosen by Good Paladins.\n");
      return 1;
    }  
    if(GOB->query_skills(91) > 4){
      write("You have already maxed this ability.\n");
      return 1;
    }
    write("You train Protection from Evil, raising it\n"+
          "to level "+(GOB->query_skills(91) + 1)+".\n");
    GOB->add_skill_pts(-1);
    GOB->add_skills(91);
    GOB->silent_save();
    return 1;
  }
  else if(str == "protection from good" || str == "good"){   
    if(GOB->query_chosen_align() == "good"){
      write("This can only be chosen by Evil Paladins.\n");
      return 1;
    }  
    if(GOB->query_skills(150) < 1){
      write("You need Holy Studies in order to obtain this ability.\n");
      return 1;
    }  
    if(GOB->query_skills(90) > 4){
      write("You have already maxed this ability.\n");
      return 1;
    }
    write("You train Protection from Good, raising it\n"+
          "to level "+(GOB->query_skills(90) + 1)+".\n");
    GOB->add_skill_pts(-1);
    GOB->add_skills(90);
    GOB->silent_save();
    return 1;
  }
  else if(str == "regeneration" || str == "regen"){   
    if(GOB->query_skills(150) < 1){
      write("You need Holy Studies in order to obtain this ability.\n");
      return 1;
    }   
    if(GOB->query_skills(92) > 4){
      write("You have already maxed this ability.\n");
      return 1;
    }
    write("You train Regeneration Aura, raising it\n"+
          "to level "+(GOB->query_skills(92) + 1)+".\n");
    GOB->add_skill_pts(-1);
    GOB->add_skills(92);
    GOB->silent_save();
    return 1;
  }
  else if(str == "holy bolt" || str == "holybolt"){   
  /* Prereqs */
    if(GOB->query_chosen_align() == "evil"){
      write("This can only be chosen by Good Paladins.\n");
      return 1;
    }  
    if(GOB->query_skills(150) < 1){
      write("You need Holy Studies in order to obtain this ability.\n");
      return 1;
    }   
    if(GOB->query_skills(50) < 4){
      write("You needed firstaid at level 4 in order to raise this skill.\n");
      return 1;
    }
    if(GOB->query_skills(93) > 4){
      write("You have already maxed this ability.\n");
      return 1;
    }
    write("You train Holy Bolt, raising it to level "+(GOB->query_skills(93) + 1)+".\n");
    GOB->add_skill_pts(-1);
    GOB->add_skills(93);
    GOB->silent_save();
    return 1;
  }
  else if(str == "plague"){   
  /* Prereqs */
    if(GOB->query_chosen_align() == "good"){
      write("This can only be chosen by Evil Paladins.\n");
      return 1;
    }  
    if(GOB->query_skills(150) < 1){
      write("You need Holy Studies in order to obtain this ability.\n");
      return 1;
    }   
    if(GOB->query_skills(50) < 4){
      write("You needed firstaid at level 4 in order to raise this skill.\n");
      return 1;
    }
    if(GOB->query_skills(99) > 4){
      write("You have already maxed this ability.\n");
      return 1;
    }
    write("You train Plague, raising it to level "+(GOB->query_skills(99) + 1)+".\n");
    GOB->add_skill_pts(-1);
    GOB->add_skills(99);
    GOB->silent_save();
    return 1;
  }
  else if(str == "release"){   
    if(GOB->query_skills(150) < 1){
      write("You need Holy Studies in order to obtain this ability.\n");
      return 1;
    }   
    if(GOB->query_skills(94) > 0){
      write("You have already maxed this ability.\n");
      return 1;
    }
    write("You train Release, raising it to level "+(GOB->query_skills(94) + 1)+".\n");
    GOB->add_skill_pts(-1);
    GOB->add_skills(94);
    GOB->silent_save();
    return 1;
  }
  else if(str == "redeem"){   
    if(GOB->query_chosen_align() == "evil"){
      write("This can only be chosen by Good Paladins.\n");
      return 1;
    }  
    if(GOB->query_skills(150) < 1){
      write("You need Holy Studies in order to obtain this ability.\n");
      return 1;
    }   
    if(GOB->query_skills(96) > 4){
      write("You have already maxed this ability.\n");
      return 1;
    }
    write("You train Redeem, raising it to level "+(GOB->query_skills(96) + 1)+".\n");
    GOB->add_skill_pts(-1);
    GOB->add_skills(96);
    GOB->silent_save();
    return 1;
  }
  else if(str == "corrupt"){   
    if(GOB->query_chosen_align() == "good"){
      write("This can only be chosen by Evil Paladins.\n");
      return 1;
    }  
    if(GOB->query_skills(150) < 1){
      write("You need Holy Studies in order to obtain this ability.\n");
      return 1;
    }   
    if(GOB->query_skills(98) > 4){
      write("You have already maxed this ability.\n");
      return 1;
    }
    write("You train Corrupt, raising it to level "+(GOB->query_skills(98) + 1)+".\n");
    GOB->add_skill_pts(-1);
    GOB->add_skills(98);
    GOB->silent_save();
    return 1;
  }
  else if(str == "sacrifice"){   
    if(GOB->query_skills(150) < 1){
      write("You need Holy Studies in order to obtain this ability.\n");
      return 1;
    }   
    if(GOB->query_skills(97) > 4){
      write("You have already maxed this ability.\n");
      return 1;
    }
    write("You train Sacrifice, raising it to level "+(GOB->query_skills(97) + 1)+".\n");
    GOB->add_skill_pts(-1);
    GOB->add_skills(97);
    GOB->silent_save();
    return 1;
  }
  else if(str == "detect"){   
    if(GOB->query_skills(150) < 1){
      write("You need Holy Studies in order to obtain this ability.\n");
      return 1;
    }   
    if(GOB->query_skills(89) > 0){
      write("You have already maxed this ability.\n");
      return 1;
    }
    write("You train Detect, raising it to level "+(GOB->query_skills(89) + 1)+".\n");
    GOB->add_skill_pts(-1);
    GOB->add_skills(89);
    GOB->silent_save();
    return 1;
  }
  else if(str == "cleanse"){   
    if(GOB->query_skills(150) < 1){
      write("You need Holy Studies in order to obtain this ability.\n");
      return 1;
    }   
    if(GOB->query_skills(95) > 0){
      write("You have already maxed this ability.\n");
      return 1;
    }
    write("You train Cleanse, raising it to level "+(GOB->query_skills(95) + 1)+".\n");
    GOB->add_skill_pts(-1);
    GOB->add_skills(95);
    GOB->silent_save();
    return 1;
  }
  else if(str == "holy studies"){   
    if(GOB->query_skills(150) > 0){
      write("You have already maxed this ability.\n");
      return 1;
    }
    write("You train in Holy Studies, raising it to level "+(GOB->query_skills(95) + 1)+".\n");
    GOB->add_skill_pts(-1);
    GOB->add_skills(150);
    GOB->silent_save();
    return 1;
  }
  else{
    write("The Book cannot train you in that.\n");
    return 1;
  }
  return 1;
}
