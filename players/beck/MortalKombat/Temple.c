inherit "room/room";
#include "/players/beck/Defs.h"
#include "/players/beck/MortalKombat/MKSymbol.h"
mixed *fighters;
int Fatality;
string FatalName;
int InFight;
int rounds;
int descrip;
int InKombat;

realm() { return "NT"; }

MKArea(){ return 1; }

/******************************************************/
/* This initializes the MK temple area.               */
/* It will destruct any kids or pets that enter       */
/* It sets up the array for fighters 1 & 2            */
/* It will send anyone else who tries to enter back   */
/*    to the Village Church                           */
/* It will choose a random room description           */
/* When fighter 2 arrives it will begin the fight     */
/*    after 60 seconds                                */
/******************************************************/

init() {
   ::init();
   if(this_player()->is_pet() || this_player()->is_kid()){
      destruct(this_player());
      return;
   }
   if(!fighters){ 
      fighters = ({ this_player() , this_player()->query_name() , 0, 0});
      descrip = random(0);
   }
   else {
      if(fighters[2]){
         move_object(this_player(),"room/church");
         return;
      }
      else
         fighters[2] = this_player();
         fighters[3] = this_player()->query_name();
   }
   rounds = 0;
   WriteMKSymbol();
   CheckInventory(this_player());
   if(fighters[2])
      call_out("BeginKombat", 60);
   this_player()->set_fight_area();
   add_action("FakeMove","north");
   add_action("FakeMove","east");
   add_action("FakeMove","south");
   add_action("FakeMove","west");
   add_action("Quit","quit");
   add_action("Kill","kill");
}


reset(arg) {
   if(arg) return;
   set_light(1);
   enable_commands();
}

short(){
   string msg;
   if(present("scorpion",this_object()))
      msg = "Dark Forest";
   else if(!descrip)
      msg = "Temple";
   return msg+" ["+RED+"Mortal Kombat"+OFF+"] ";
}

/*******************************************************/
/* Allows the Temple to have several different room    */
/*    descriptions.  These are dependent on what NPC   */
/*    is fighting or a random number otherwise         */
/*******************************************************/

long(){
   if(present("scorpion",this_object())){
      write("You stand in a dark, silent forest.\n"+
         "There are hundreds of pine trees here all lined up in perfect rows.\n"+
         "You can hardly see a ray of sunlight through their thick canopy.\n"+
         "There are four obvious exits: north, east, west, south.\n");
   }
   else if(!descrip){
      write("You stand in the middle of a platform.  Around the platform are many masters\n" +
         "of martial arts.  The old men seem to be pleased that a tounament is about\n" +
         "to begin.  The time has come, you have entered Mortal Kombat.\n" +
         "You must fight well or die.\n");
   }
}


/********************************************************/
/* Forces opponents to attack each other.               */
/* This is done to start a match or to restart one      */
/*    if either of the fighters disconnects or uses a   */
/*    peace spell                                       */
/********************************************************/

BeginKombat(){
   if(present(fighters[0],this_object()) && present(fighters[2], this_object()))
      if(!present(fighters[0],this_object())->query_attack()){
         WriteFight();
         fighters[0]->attack_object(fighters[2]);
         /*need this in case fighter 2 dies from previous line */
         if(fighters[2]) 
            fighters[2]->attack_object(fighters[0]);
         InFight = 1;
         set_heart_beat(1);
      }
}


query_NM(){
   if(present("rayden",this_object())){
      tell_room(this_object(),
         "Rayden's strong electric field interferes with your magic.\n"+
         "");
      return 1;
   }
   else{
      return 0;
   }
}

FakeMove(){
   if(present("scorpion",this_object())){
      tell_room(this_object(),
      "You try and run away.\n"+
      "Suddenly Scorpion shouts: Come Here!\n"+
      "An animated chain with a spear appears right from his hand.\n"+
      "With blinding speed it shoots into your back.\n");
      tell_room(this_object(),
      "Scorpion pulls you back to him.\n"+
      "While you are stunned, Scorpion rocks you with a devastating uppercut.\n"+
      "\n");
      this_player()->hit_player(40+random(40));
      return 1;
   }
   else {
      return 0;
   }
}

FinishEm(str){
   FatalName = str;
   input_to("Fatality");
   call_out("CheckFatality",10);
   WriteFinish();
   Fatality = 1;
}

Fatality(str){
if(!Fatality){
      command(str,this_player());
return 1;
}
   if(FatalName == "Scorpion"){
      if(str == "block,up,up"){
         WriteWins();
         WriteFatality();
         Fatality = 0;
      }
   }
   if(FatalName == "Johnnie Cage"){
      if(str == "forward,forward,forward,high punch"){
         WriteWins();
         WriteFatality();
         
         Fatality = 0;
      }
   }
   if(FatalName == "Kano"){
      if(str == "back,back,low punch"){
         WriteWins();
         WriteFatality();
         
         Fatality = 0;
      }
   }
   if(FatalName == "Rayden"){
      if(str == "forward,back,back,back,high punch"){
         WriteWins();
         WriteFatality();
        
         Fatality = 0;
      }
   }
   if(FatalName == "Sonya"){
      if(str == "forward,forward,back,back,block"){
         WriteWins();
         WriteFatality();
         
         Fatality = 0;
      }
   }
   if(FatalName == "Sub-Zero"){
      if(str == "forward,down,forward,high punch"){
         WriteWins();
         WriteFatality();
         
         Fatality = 0;
      }
   }
   if(FatalName == "Liu Kang"){
      if(str == "block,spin toward"){
         WriteWins();
         WriteFatality();
         
         Fatality = 0;
      }
   }
   if(Fatality == 1){
      write("Nothing Happens.\n");
      input_to("Fatality");   
   }
   return 1;
}

CheckFatality(){
   if(Fatality == 1){
      WriteWins();
      Fatality = 0;
      tell_room(this_object(),"You didn't perform a fatality.\n");
      NextWarrior();
   }
   return;
}

WriteWins(){
}

WriteFatality(){
   tell_room(this_object(),
      "Fatality!\n"+
      "");
}

WriteFinish(){
   tell_room(this_object(),
      "Finish 'EM!\n"+
      "");
}

/******************************************************/
/* Checks that the fighters are in combat             */
/* If a player is disconnected, this will restart     */
/*    the fight as soon as they reconnect             */
/* If a fighter dies, or somehow leaves MK, it will   */
/*    declare a winner and move players to the church */
/******************************************************/

heart_beat(){
   if(InFight){
      if(fighters[0] && fighters[2]){
         if(present(fighters[0], this_object()) &&  present(fighters[2], this_object())){
            if(fighters[0]->query_ghost()){
               Victory(fighters[3], fighters[1]);Killed(fighters[2], fighters[0], fighters[1]);
               if(fighters[0]->is_player())
                  move_object(fighters[0],"room/church");
               if(fighters[2]->is_player())
                  move_object(fighters[2],"room/church");
               fighters = 0;
               CleanRoom();
               set_heart_beat(0);
            }
            else if(fighters[2]->query_ghost()){
               Victory(fighters[1], fighters[3]);Killed(fighters[0], fighters[2], fighters[3]);
               if(fighters[0]->is_player())
                  move_object(fighters[0],"room/church");
               if(fighters[2]->is_player())
                  move_object(fighters[2],"room/church");
               fighters = 0;
               CleanRoom();
               set_heart_beat(0);
            }
   /************************************************/
   /* Don't waste HB while someone is disconnected */
   /************************************************/
            else if(fighters[0]->is_player() && !fighters[0]->query_interactive())
               return;
            else if(fighters[2]->is_player() && !fighters[2]->query_interactive())
               return;
   /************************************************/
   /* Don't allow a monster to fight itself        */
   /************************************************/
            else if(fighters[0]->query_attack() == fighters[0])
               BeginKombat();
            else if(fighters[2]->query_attack() == fighters[2])
               BeginKombat();
   /************************************************/
   /* Don't allow the fight to stop (peace)        */
   /************************************************/
            else if(!fighters[0]->query_attack()){
               BeginKombat();
            }
            else
               rounds = rounds + 1;
         }
         else if(!present(fighters[0], this_object())){
            Victory(fighters[3], fighters[1]);Killed(fighters[2], fighters[0], fighters[1]);
            if(fighters[2]->is_player())
               move_object(fighters[2],"room/church");
            fighters = 0;
            CleanRoom();
            set_heart_beat(0);
         }
         else if(!present(fighters[2], this_object())){
            Victory(fighters[1], fighters[3]);Killed(fighters[0], fighters[2], fighters[3]);
            if(fighters[0]->is_player())
               move_object(fighters[0],"room/church");
            fighters = 0;
            CleanRoom();
            set_heart_beat(0);
         }
      }
      else if(!fighters[0]){
         Victory(fighters[3], fighters[1]);Killed(fighters[2], fighters[0], fighters[1]);
         if(fighters[2]->is_player())
            move_object(fighters[2],"room/church");
         fighters = 0;
         CleanRoom();
         set_heart_beat(0);
      }
      else if(!fighters[2]){
         Victory(fighters[1], fighters[3]); Killed(fighters[0], fighters[2], fighters[3]);
         if(fighters[0]->is_player())
            move_object(fighters[0],"room/church");
         fighters = 0;
         CleanRoom();
         set_heart_beat(0);
      }
   }
}

Killed(object ob, object ob2, string name){
if(rounds > 30)
   present("bloodscar",ob)->Killed(ob2, name);
}

/*********************************************************/
/* Informs the Mud of an MK Victory                      */
/*********************************************************/

Victory(string winner, string loser){
InKombat = 0;
InFight = 0;
   "obj/user/one_chan.c"->chan_msg(RED+"<"+YELLOW+"<"+OFF+winner+" has defeated "+loser+" in Mortal Kombat."+YELLOW+">"+OFF+RED+">"+OFF+"\n"+
         "","junk");
   log_file("beck.MortalKombat", winner+" defeated "+loser+" in "+rounds+" rounds   "+ctime(time())+"\n");
   tell_room(this_object(),"You are magically moved to the Village Church.\n");
}

/******************************************************/
/* Does not let a player quit the game while fighting */
/*    in Mortal Kombat                                */
/******************************************************/

Quit(){
   write("You are a sorry excuse for a warrior, thinking you can quit your way out of Mortal Kombat!\n");
   return 1;
}


/*********************************************************/
/* Shows MK fight in Angel Grove Youth Center            */
/*********************************************************/

catch_tell(str){
   tell_room("/players/beck/room/youth_center","<<"+RED+"MK"+OFF+">> "+str);
tell_room("/players/beck/workroom","<<MK>> "+str);
log_file("beck.MortalKombatFight", str);
}

/*********************************************************/
/* WriteFight()                                          */
/* Writes the word FIGHT across the screen in ascii text */ 
/*********************************************************/                                           

WriteFight(){
   tell_room(this_object(),"A Voice says: \n"+
      GREEN+
      " _____   __    _____   __   __  _______  __\n"+
      "|"+RED+"%%%%"+GREEN+"/  |"+RED+"%"+GREEN+"/  /"+RED+"%%%%%"+GREEN+"/  |"+RED+"%"+GREEN+"/  |"+RED+"%"+GREEN+"/ /"+RED+"%%%%%%"+GREEN+"| |"+RED+"%%"+GREEN+"/\n"+
      "");
   tell_room(this_object(),
      "|"+RED+"%"+GREEN+"|____ |"+RED+"%"+GREEN+"| /"+RED+"%"+GREEN+"/   __  |"+RED+"%"+GREEN+"|__|"+RED+"%"+GREEN+"|  ^^|"+RED+"%"+GREEN+"|^  |"+RED+"%"+GREEN+"|\n"+
      "|"+RED+"%%%%%"+GREEN+"/ |"+RED+"%"+GREEN+"| |"+RED+"%"+GREEN+"|  |"+RED+"%%"+GREEN+"| |"+RED+"%%%%%%"+GREEN+"|    |"+RED+"%"+GREEN+"|   |"+RED+"%"+GREEN+"|\n"+
      "");
   tell_room(this_object(),
      "|"+RED+"%"+GREEN+"|     |"+RED+"%"+GREEN+"| |"+RED+"%%"+GREEN+"\\__||  |"+RED+"%"+GREEN+"|^^|"+RED+"%"+GREEN+"|    |"+RED+"%"+GREEN+"|   /_|\n"+
      "|"+RED+"%"+GREEN+"|     |"+RED+"%"+GREEN+"|  \\"+RED+"%%%%%"+GREEN+"/  |"+RED+"%"+GREEN+"|  |"+RED+"%"+GREEN+"|    |"+RED+"%"+GREEN+"|   ___\n"+
      "");
   tell_room(this_object(),
      "|"+RED+"%"+GREEN+"|     |/    ^^^^^   |/    ^     |"+RED+"%"+GREEN+"|   |"+RED+"%"+GREEN+"/\n"+
      "|/                                |/     ^ \n"+
      "\n\n"+OFF+
      "");
   write("A Voice says: \n"+
"");
write(      GREEN+
      " _____   __    _____   __   __  _______  __\n"+
"");
write(
      "|"+RED+"%%%%"+GREEN+"/  |"+RED+"%"+GREEN+"/  /"+RED+"%%%%%"+GREEN+"/  |"+RED+"%"+GREEN+"/  |"+RED+"%"+GREEN+"/ /"+RED+"%%%%%%"+GREEN+"| |"+RED+"%%"+GREEN+"/\n"+
"");
write(
      "|"+RED+"%"+GREEN+"|____ |"+RED+"%"+GREEN+"| /"+RED+"%"+GREEN+"/   __  |"+RED+"%"+GREEN+"|__|"+RED+"%"+GREEN+"|  ^^|"+RED+"%"+GREEN+"|^  |"+RED+"%"+GREEN+"|\n"+
"");
write(      "|"+RED+"%%%%%"+GREEN+"/ |"+RED+"%"+GREEN+"| |"+RED+"%"+GREEN+"|  |"+RED+"%%"+GREEN+"| |"+RED+"%%%%%%"+GREEN+"|    |"+RED+"%"+GREEN+"|   |"+RED+"%"+GREEN+"|\n"+
"");
write(
      "|"+RED+"%"+GREEN+"|     |"+RED+"%"+GREEN+"| |"+RED+"%%"+GREEN+"\\__||  |"+RED+"%"+GREEN+"|^^|"+RED+"%"+GREEN+"|    |"+RED+"%"+GREEN+"|   /_|\n"+
"");
write(      "|"+RED+"%"+GREEN+"|     |"+RED+"%"+GREEN+"|  \\"+RED+"%%%%%"+GREEN+"/  |"+RED+"%"+GREEN+"|  |"+RED+"%"+GREEN+"|    |"+RED+"%"+GREEN+"|   ___\n"+
"");
write(
      "|"+RED+"%"+GREEN+"|     |/    ^^^^^   |/    ^     |"+RED+"%"+GREEN+"|   |"+RED+"%"+GREEN+"/\n"+
"");
write(      "|/                                |/     ^ \n"+
      "\n\n"+OFF+
      "");
}

/***************************************************/
/* Makes sure one fighter can not attack the other */
/*    during the first 60 seconds after entering   */
/*    the Temple.  It makes sure both fighters     */
/*    have time to ready themselves, plus adds a   */
/*    little surprise as to when the match starts  */
/***************************************************/

Kill(){
   if(!InFight){
      write("It is not honorable to attack an opponent before the match begins.\n");
      return 1;
   }
   else
      return;
}

query_no_fight(){
if(!InFight){
   write("It is not honorable to attack an opponent before the match begins.\n");
return 1;
}
else
return;
}
SInKombat(){ InKombat = 1; }
QInKombat(){ return InKombat; }

CheckInventory(object ob){
   int i; int j;
   object item, item2;
   item = all_inventory(ob);
   for(i=0; i<sizeof(item); i++){
      if(item[i]->can_put_and_get()){
            item2 = all_inventory(item[i]);
            for(j=0; j<sizeof(item2); j++){
               destruct(item2[j]);
            }
         if(item[i]->QRangerPack()){
            item[i]->RangerPack();
         }
         else{
            tell_object(ob,item[i]->query_name()+" has been removed from you.\n");
            destruct(item[i]);
         }
      }
   }
}
            
CleanRoom(){
   object item;
   int i;
   item = all_inventory(this_object());
   fighters = 0;
   InFight = 0;
   for(i=0;i<sizeof(item); i++){
      destruct(item[i]);
   }
}

exit(){
   this_player()->clear_fight_area();
}
