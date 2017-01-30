#include "/players/dusan/ansi.h"

int qnum;          /* What question they are on. */
string *qa;           /* Questions answer array- stores answers */
string *questions; /* Questions */
int cor,wro;       /* Number right, number wrong */

drop(str){ 
write("You decide to throw out the test.\n"); 
destruct(this_object()); 
return 1; 
}
query_weight(){ return 0; }
query_value(){ return 0; }


reset(){
set_up_arrays();
}


id(str){ return str == "exam" || str == "newbie exam" || str == "booklet"; }
short(){ return "A Newbie Exam"; }
long(){ 
write(
"This is a thin booklet with the words "+HIB+"Newbie Exam"+NORM+" on it's\n"+
"cover. To start the exam, type: start\n"+
"To see what question you are on, type: question\n"+
"For a listing of number correct and wrong so far, 'review'\n"+
"To quit the exam early, type 'end'\n");
return 1;
}

init(){
if(!environment()) return;
if(this_player())
if(file_size("/players/dusan/newbie/finished/"+this_player()->query_real_name()+"") > 0){
 write("You have already completed the exam!\n");
 destruct(this_object()); 
 return 1;
 }

 add_action("start", "start");
 add_action("question", "question", 1);
 add_action("answer", "a");
 add_action("answer", "b");
 add_action("answer", "c");
 add_action("answer", "d");
 add_action("end_it", "end");
 add_action("review", "review");
 }

start(){
 if(file_size("/players/dusan/newbie/finished/"+this_player()->query_real_name()+"") > 0){
 write("You have already completed the exam!\n");
 destruct(this_object()); 
 return 1;
 }
 if(qnum > 0){ write("You have already begun!\n"); return 1; }

 write(HIR+"\n\n\nTo answer a question, simply type the letter of the answer.\n"+
       "a, b, c, or d"+NORM+"\n\n\n");
 question();
 return 1;
 }


end_it(){if( environment() != this_player()) return;
write("You decide to end the exam early.\n");
destruct(this_object());
return 1;
}

review(){if( environment() != this_player()) return;
write("You currently have "+cor+" correct, and "+wro+" wrong.\n"+
      "You are on question "+(qnum + 1)+" of "+sizeof(questions)+"\n");
return 1;
}

question(){ if(environment() != this_player()) return;
 write(HIG+"Question "+(qnum + 1)+":"+NORM+"\n");
 write(questions[qnum]+"\n");
 write("Answer ");
 return 1;
 }

answer(){ 
 if(environment() != this_player()) return;
 if(file_size("/players/dusan/newbie/finished/"+this_player()->query_real_name()+"") > 0){
 write("You have already completed the exam!\n");
 destruct(this_object()); 
 return 1;
 }
 if(qa[qnum] == query_verb()){
    write("\n\n"+HIG+"That is correct!"+NORM+"\n\n\n");
    cor += 1;
    qnum += 1;
    if(qnum >= sizeof(questions)){ end(); return 1; }
    else question();
    return 1;
    }
 else{
    write("\n\n"+HIR+"Sorry that is wrong..."+NORM+"\n");
    write("The correct answer was "+capitalize(qa[qnum])+".\n\n\n");
    wro += 1;
    qnum += 1;
    if(qnum >= sizeof(questions)){ end(); return 1; }
    else question();
    return 1;
    }
write("That is an invalid answer: a, b, c, or d\n");
return 1;
}

end(){ if(environment() != this_player()) return;
  write("You have completed the test!\n");
  write(HIB+"You scored a "+(cor*100/(sizeof(questions)))+"%"+NORM+"\n");
  write(cor+" correct and "+wro+" wrong.\n");
if(cor > 20){
  write("You have been awarded "+(cor * 50)+" coins and experience points!\n");
  environment()->add_exp(cor * 50);
  environment()->add_money(cor * 50);
  write_file("/players/dusan/newbie/finished/"+this_player()->query_real_name()+"",
  "Finished with "+cor+" correct, and "+wro+" wrong.\n");
  destruct(this_object());
  return 1;
  }
else{
  write("Please try again. :(\n");
 destruct(this_object());
 return 1;
  }
return 1;
}


set_up_arrays(){
questions = ({
"Who is the God of the mud? \n"+
"A: We don't have gods here!\n"+
"B: Vertebraker\n"+
"C: Boltar\n"+
"D: Sandman\n",	
"What does the 'i' command do?\n"+
"A: Makes you poke someone in the eye.\n"+
"B: Shows you what is in your inventory.\n"+
"C: Shows you who is logged on.\n"+
"D: None of the above.\n",
"What command lists all armors currently worn? \n"+
"A: i\n"+
"B: worn\n"+
"C: armors\n"+
"D: Both A and C\n",
"What do you wield? \n"+
"A: Weapons. \n"+
"B: Armor. \n"+
"C: Shields. \n"+
"D: Clothing. \n",
"What do you wear?\n"+
"A: Weapons.\n"+
"B: Armor.\n"+
"C: Clothing.\n"+
"D: B and C.\n",
"Which of these is an example of how to setup a do command?\n"+
"A: do w.w,w. w .\n"+
"B: do w,w,w,w,w .\n"+
"C: do w.w.w.w.w.w .\n"+
"D: do : w,w,w,w,w,w .\n",
"Which of these is an example of how to setup an alias?\n"+
"A: ab alias abracabra.\n"+
"B: ab abracabra alias.\n"+
"C: alias ab abracabra.\n"+
"D: alias ab, abracabra.\n",
"How do you report a bug?\n"+
"A: reportbug (string).\n"+
"B: bug (string).\n"+
"C: Shout hey I found a bug.\n"+
"D: Spamm tell a wizard that you found a bug.\n",
"What is the command to make a party?\n"+
"A: Create party.\n"+
"B: Form party.\n"+
"C: Party start.\n"+
"D: Addmem.\n",
"How old do you have to be to use gossip?\n"+
"A: 15 minutes old.\n"+
"B: 30 minutes old.\n"+
"C: 1 hour old.\n"+
"D: 1 day old.\n",
"What command auto wields and wears?\n"+
"A: Ready.\n"+
"B: Wear all.\n"+
"C: #.\n"+
"D: A and C.\n", 
"What does HP stand for?\n"+
"A: Hit points.\n"+ 
"B: Help points.\n"+
"C: Heal points.\n"+
"D: Endurance.\n",
"What does SP stand for? \n"+
"A: Stealth points. \n"+
"B: Skill points. \n"+
"C: Spell points. \n"+
"D: Special powers. \n",
"What are HPs?\n"+
"A: A measure of how healthy you are.\n"+
"B: A representation of how much damage you can take.\n"+
"C: The thing you pay attention to so you don't die in combat.\n"+
"D: All of the above.\n",
"What does the strength stat do?\n"+
"A: Makes you hit harder.\n"+
"B: Allows you to carry more.\n"+
"C: Allows you to use better armor.\n"+
"D: All of the above.\n",
"What does the stat stamina do?\n"+
"A: Allows you to tox more.\n"+
"B: Gives you more hitpoints.\n"+
"C: Lets you use weapons effectively longer.\n"+
"D: All of the above.\n",
"What does the stat magic aptitude do?\n"+
"A: Makes your spells do more damage.\n"+
"B: Makes your spells cost less.\n"+
"C: Gives you more maximium spellpoints.\n"+
"D: A and B.\n",
"What does the stat willpower do?\n"+
"A: Increases the base damage on spells.\n"+
"B: Is left up to individual wizards to assign.\n"+
"C: Allows you to cast 2 spells a round if above 20.\n"+
"D: A and C.\n",
"What does the stat luck do?\n"+
"A: Allows you to do more damage.\n"+
"B: Allows you to take less damage.\n"+
"C: Can enable you to avoid all damage from a single attack.\n"+
"D: All of the above.\n",
"What does the stat intelligence do?\n"+
"A: Adds to your max spellpoints.\n"+
"B: Left to individual wizards to assign.\n"+
"C: Adds to base spell damage.\n"+
"D: Gives you extra exp at the end of a battle.\n",
"What does the stealth stat do?\n"+
"A: Lets you enter the room without being seen.\n"+
"B: Lets you do extra damage on the first attack of combat.\n"+
"C: Lets you dodge damage in combat.\n"+
"D: Gives you a chance to avoid aggressive monsters.\n",
"What does the stat piety do?\n"+
"A: Allows you to pray for favors.\n"+
"B: Takes less exp when you pray for life.\n"+
"C: Gives you a small spell point regen.\n"+
"D: None of the above.\n",
"What does exp stand for?\n"+
"A: Experience points.\n"+
"B: How many monsters you killed.\n"+
"C: Knowledge gained in combat.\n"+
"D: All of the above.\n",
"How many normal levels are there?\n"+
"A: 19.\n"+
"B: 40.\n"+
"C: 100.\n"+
"D: 119.\n",
"How many extra levels are there?\n"+
"A: 21.\n"+
"B: 40.\n"+
"C: 70.\n"+
"D: 100.\n",
"What do levels give you?\n"+
"A: Extra sps, hps, toxes, carry and lets you hit harder.\n"+
"B: Extra sps, hps, toxes, carry and spells.\n"+
"C: Extra sps, hps, toxes, carry, spells, and lets you hit harder.\n"+
"D: None of the above.\n",
"What are Sps?\n"+
"A: A measure of how mentally drained you are.\n"+
"B: A representation of how spells tax you.\n"+
"C: What you spend to cast spells in combat.\n"+
"D: Both B and C.\n",
"What does 'I' stand for on your monitor?\n"+
"A: Inventory carry.\n"+
"B: Intoxication.\n"+
"C: Intelligence. \n"+
"D: None of the above\n",
"What does 'F' stand for on your monitor?\n"+
"A: Food.\n"+
"B: Soak.\n"+
"C: Fight. \n"+
"D: None of the above\n",
"What does 'S' stand for on your monitor?\n"+
"A: Food.\n"+
"B: Soak.\n"+
"C: Stuff. \n"+
"D: None of the above\n",
"What does 'T' stand for on your monitor?\n"+
"A: Transfer infusion.\n"+
"B: Teleport Points.\n"+
"C: Hit points of your opponent. \n"+
"D: None of the above\n",
"What do heals do?\n"+
"A: Tox you.\n"+
"B: Heal your HPS or SPS.\n"+
"C: Keep you from dying in combat.\n"+
"D: All of the above.\n",
"What does the %'s next to I(F, S, or T)on your monitor stand for?\n"+
"A: The amount of that particular type of healing you have absorbed.\n"+
"B: The amount of those types of heals you can carry.\n"+
"C: The total carry you have.\n"+
"D: None of the above.\n",
"Can you heal more than once per round?\n"+
"A: Yes.\n"+
"B: No.\n"+
"C: Sometimes.\n",
"Can you heal in combat?\n"+
"A: Yes.\n"+
"B: No. \n"+
"C: Sometimes. \n",
"What are the benefits of intoxication?\n"+
"A: You heal faster.\n"+
"B: You detox faster.\n"+
"C: Both A and B.\n"+
"D: None of the above. \n",
"What are the hinderances of intoxication?\n"+
"A: You hit poorly.\n"+
"B: You take damage poorly.\n"+
"C: Your spells do less damage.\n"+
"D: There are no hinderances.\n",
"How many 'normal' armor slots are there?\n"+
"A: 7\n"+
"B: 9\n"+
"C: 18\n"+
"D: 20\n",
"What level do you get the spell magic missile?\n"+
"A: 5\n"+
"B: 7\n"+
"C: 10\n"+
"D: 15\n",
"What level do you get the spell shock?\n"+
"A: 5\n"+
"B: 7\n"+
"C: 10\n"+
"D: 15\n",
"What level do you get the spell fireball?\n"+
"A: 5\n"+
"B: 7\n"+
"C: 10\n"+
"D: 15\n",
"What level do you get the spell sonic?\n"+
"A: 10\n"+
"B: 15\n"+
"C: 19\n"+
"D: 19+5\n",
"How do you start combat with a monster?\n"+
"A: Kill <monstername>.\n"+
"B: Fight <monstername>.\n"+
"C: Attack <monstername>.\n"+
"D: Murder <monstername>.\n",
"When you look at a weapon what description means it is about to break?\n"+
"A: Like new.\n"+
"B: A little worn.\n"+
"C: Somewhat worn.\n"+
"D: Well worn.\n",
"How do you keep a weapon sharp?\n"+
"A: Use it a lot.\n"+
"B: Use it very little.\n"+
"C: Let the weapon heal.\n"+
"D: Use a honing stone or find a smith which can sharpen it.\n",
"What level do you get the spell invisible?\n"+
"A: 5\n"+
"B: 10\n"+
"C: 15\n"+
"D: 19\n",
"What does AHP stand for on your combat monitor?\n"+
"A: Attackers hit points.\n"+
"B: Average hit points.\n"+
"C: Your average damage.\n"+
"D: None of the above.\n",
"When casting a combat spell(missile, shock, fireball, and sonic) you can also cast by just using: \n"+
"A: The first letter.\n"+
"B: The first 2 letters.\n"+
"C: The first 3 letters.\n"+
"D: You cant abreviate game spells. \n",
"At what level can you set your own title? \n"+
"A: 19\n"+
"B: 10\n"+
"C: 15\n"+
"D: 19+22\n",
"What is the proper way to set a pretitle? \n"+
"A: set my pretitle (Nirvana Junkie)\n"+
"B: pretitle (Nirvana Junkie)\n"+
"C: &pretitle set (Nirvana Junkie)\n"+
"D: You can't set your pretitle!\n",

});

qa = ({
"c", "b", "d", "a", "d", "b", "c", "b", "b", "c", "d", "a", "c", "d", "b", "b", "c", "b", "d", "b", "d", "d", "a", "a", "d", "b", "d", "b", "a", "b", "a", "d", "a", "a", "a", "a", "a", "c", "a", "c", "d", "d", "a", "d", "d", "c", "a", "b", "d", "b"
});
}
