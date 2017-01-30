#include "/players/beck/Defs.h"
string *QuestKey;
string *QuestJourney;
id(str){ return str == "mkquest" || str == "invitation" || str == "scroll"; }
short(){ return "A scroll of invitation to Mortal Kombat"; }
long(){ write(""+
      "This scroll is your invitation to the great Tournament.\n"+
      "To enter the tournament, however, you will need to seek\n"+
      "out the great warriors of Nirvana and ask them about\n"+
      "Mortal Kombat.  They will issues you part of the key code\n"+
      "that is required to enter the Tournament.\n"+
      "When you have all the keys (20), seek out the Great Temple\n"+
      "and request that Shang Tsung let you enter the Tournament.\n"+
      "You may see your key code by typing 'Code'.\n"+
      "");
   return 1;
}
query_auto_load(){ return "/players/beck/MortalKombat/QuestKey:"; }
get(){ return 1; }
drop(){ return 1; }

init_arg(){
   if(restore_object("players/beck/MortalKombat/Save/"+TPRNAME)){
      write("Reviewing your quest progress...\n");
   }
}

init(){
   add_action("Code","Code");
   add_action("quit","quit");
}

quit(){
   save_object("players/beck/MortalKombat/Save/"+ENVOB->query_real_name());
   return;
} 

QQuestKey(){ return QuestKey; }
AQuestKey(str){
   if(!QuestKey)
      QuestKey = ({});
   QuestKey += ({ str });
   quit();
}

Code(){
   int i;
   if(!QuestKey){
      write("You have not obtained any of the keys yet.\n");
      return 1;
   }
   write("Your Key Code is:\n");
   for(i=0; i<sizeof(QuestKey); i++){
      write(QuestKey[i]+" ");
   }
   write("\n");
   return 1;
}      

AQuestJourney(str){
   if(!QuestJourney)
      QuestJourney = ({});
   QuestJourney += ({ str });
   quit();
}

QQuestJourney(name){
   if(!QuestJourney)
      QuestJourney = ({});
   if(member_array(name, QuestJourney) != -1){
      return 1;
   }
   else
      return 0;
}
Say(str){
   say(this_player()->query_name()+" says: "+str+"\n");
   write("You say: "+str+"\n");
   return 1;
}
QuestOver(){
   rm("/players/beck/MortalKombat/Save/"+environment(this_object())->query_real_name()+".o");
QuestJourney = 0;
QuestKey = 0;
quit();
}
