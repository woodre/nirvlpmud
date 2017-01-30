#define KEYS ({"Qui","Gui","Pou","Rin","Kar","Yvi","Adm","Ecu","Juk","Wza","Tik","Lih","Qza","Rog","Sza",})
string ThisKey;
catch_tell(str){
   string msg;
   int i;
   if(sscanf(str, "%smortal kombat%s", msg) || sscanf(str, "%smortal kombat", msg)){
      if(this_object()->query_name() == "Ueshiba"){
if(present("bloodscar",this_player())){
write("You are already entered in Mortal Kombat.\n"+
"If you entered the Old Tournament you can heal_scar\n"+
"That will allow you to to get an invitation to the new Tournament\n"+
"");
return 1;
}
         if(present("mkquest",this_player())){
            write("You must seek out the other warriors to enter.\n");
            return 1;
         }
         if(this_player()->query_level() < 19 ||
            this_player()->query_level() > 19){
            write("The master says: You do not qualify for the Tournament.\n");
            return 1;
         }
         else {
            move_object(clone_object("/players/beck/MortalKombat/QuestKey.c"), this_player());
            call_out("beginmsg",1,this_player());
            return 1;
         }
      }
      else {
         if(present("mkquest",this_player())){
            if(present("mkquest",this_player())->QQuestJourney(this_object()->query_name())){
               write("I have already given you part of the code.\n");
               return 1;
            }
            i = sizeof(KEYS);
            i = random(i);
            present("mkquest",this_player())->AQuestKey(KEYS[i]);
            present("mkquest",this_player())->AQuestJourney(this_object()->query_name());
            ThisKey = KEYS[i];
            call_out("keymsg",1,this_player());
            return 1;
         }
         else {
            return 1;
         }
      }
   }
   return 1;
}
        
beginmsg(ob){
   tell_object(ob,""+
      "Yes, I see you would like to enter the great Tournament.\n"+
      "This is a great responsibility, for the fate of Nirvana lies\n"+
      "within its outcome.  If you want to enter, you must seek out\n"+
      "the greatest warriors of Nirvana.  They can grant you the password\n"+
      "you will need to give to Shang Tsung in order to enter.\n"+
      "\nMorihei hands you a scroll.\n"+
      "Take this scroll as proof of your willingness to enter the \n"+
      "Tournament.\n"+
      "Good Luck!  You will need it.\n"+
      "");
}

keymsg(ob){
   tell_object(ob,""+
      this_object()->query_name()+" says:\n"+
      "So you want to enter the great Tournament of Mortal Kombat.\n"+
      "Well I can help you get in the Tournament.\n"+
      "I have entered the Tournament myself and will be fighting soon,\n"+
      "but we need all the help we can get to destroy Shang Tsung.\n"+
      "Another part of your Key Code is: "+ThisKey+"\n"+
      "Good Luck in the Tournament.\n"+
      "");
}


      
