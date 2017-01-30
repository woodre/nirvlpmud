inherit "room/room";
object RealAttack;
object *Warriors;
int WarriorNum;

realm() { return "NT"; }

init() {
   ::init();
   if(this_player()->is_player())
      RealAttack = this_player();
   this_player()->set_fight_area();
   add_action("FakeMove","north");
   add_action("FakeMove","east");
   add_action("FakeMove","south");
   add_action("FakeMove","west");
}


reset(arg) {
   if(arg) return;
   set_light(1);
   /* short_desc=("Temple of mortal kombat"); */
/*   
   long_desc=
   "You stand in the middle of a platform.  Around the platform are many masters\n" +
   "of martial arts.  The old men seem to be pleased that a tounament is about\n" +
   "to begin.  The time has come, you have entered Mortal Kombat.\n" +
   "You must fight well or die.\n",
   dest_dir=
   ({
    });
*/  
   SNextWarrior();
   NextWarrior();
}

short(){
   string msg;
   if(present("scorpion",this_object()))
      msg = "Dark Forest";
   else
      msg = "Temple";
   return msg+" [Mortal Kombat] ";
}

long(){
   write(""+
"                                                            \n"+                        
"                                      %%%%%%%..^'*$e.              \n"+                        
"                               $% d$$$$$$$$$$$$$$$% '*$`           \n"+             
"                             %$$$ '$$$$$$$$$$$$$$$$$$%.'$c         \n"+                        
"                         %$$%   ''   ^'^**$$$$$$$$$$$$$%.^$:       \n"+                        
"                       %$$$'''           `!?$$$$$$$$$$$$$%.^       \n"+                        
"                     .$$                   ~!)$$$$$$$$$$$$$%       \n"+                        
"                    %$$                 **@b. `')).$$$$$$$$$$      \n"+                        
"                   %^'                           `$$$$$$$$$$$$.    \n"+                        
"                  %$%                      ..      '**$$$$$$$$$    \n"+                        
"                 :$$           .        .$$$$$%.    ..  ' `$$$$$   \n"+                        
"                 $$            $          ^*$$$$%   '      $$$$$$  \n"+                        
"                %$$            $%    .+$$$$+.'*$$$$.       $$$$$$  \n"+                        
"                $$$            $$$$$$$$$$$$$$$% '$$$$$  == $$$$$$$ \n"+                        
"                $$$            $$$$$$$$$$$$$$$$%   '$' * ?$$$$$$$$ \n"+                        
"                $$$            '$$$$$$$$$$$$$$$$$%,,...+$ $$$$$$$$  \n"+                       
"               '$$$             `$$$$$$$$$$$$$$$$$$$$$$$$ '$$$$$$$ \n"+                        
"                $$                  `''''''`       `'*$$$& $$$$$$%  \n"+                        
"                $  %$                                  '$$. '$$$$ \n"+                        
"                `$$$$`                                   '$. %%%$  \n"+                        
"                 $$$$$%                                   '$%. .%  \n"+                        
"                 `$$$$$`                                   '$$$$   \n"+                        
"                  $$$$$$                                    $$$'   \n"+                        
"                   $$$$$  %%                                $$,   \n"+            
"                    $$** <$$                                $'   \n"+             
"                     `$$$$$$%%$$$$%.                        '    \n"+             
"                      ^$$$$$$$$$$$$$%                             \n"+            
"                        `'*$$$$$$$$$                                \n"+          
"");
return;           
   if(present("scorpion",this_object())){
      write("You stand in a dark, silent forest.\n"+
      "There are hundreds of pine trees here all lined up in perfect rows.\n"+
      "You can hardly see a ray of sunlight through their thick canopy.\n"+
      "There are four obvious exits: north, east, west, south.\n");
   }
   else {
      write("You stand in the middle of a platform.  Around the platform are many masters\n" +
   "of martial arts.  The old men seem to be pleased that a tounament is about\n" +
   "to begin.  The time has come, you have entered Mortal Kombat.\n" +
   "You must fight well or die.\n");
   }
}

SNextWarrior(){
   if(!present("warrior",this_object())){
      Warriors = ({
            "/players/beck/MortalKombat/Kano.c",
            "/players/beck/MortalKombat/Sonya.c",
            "/players/beck/MortalKombat/JohnnieCage.c",
            "/players/beck/MortalKombat/Scorpion.c",
            "/players/beck/MortalKombat/Raiden.c",
            "/players/beck/MortalKombat/SubZero.c",
            "/players/beck/MortalKombat/LiuKang.c",
            "/players/beck/MortalKombat/Goro.c",
            "/players/beck/MortalKombat/ShangTsung.c",});
      WarriorNum = 9;
   }
}

NextWarrior(){
   call_out("NextWarrior2",20);
   return;
}

NextWarrior2(){
   if(WarriorNum > 1 && WarriorNum != 6){
      move_object(Warriors[0],this_object());
      tell_room(this_object(),present("warrior",this_object())->query_name()+
         " steps on to the platform and prepares for battle.\n");
      call_out("BeginFight",100); 
      Warriors -= ({ Warriors[0] });
      WarriorNum -= 1; 
   }
   else if(WarriorNum == 6){
      move_object(Warriors[0],this_object());
      tell_room(this_object(),
         "You are suddenly transported by an outside force to a huge forest.\n"+
         "Not a sound can be heard.\n"+
         "Suddenly out of the corner of your eye you spot a figure\n"+
         "running in between some of the trees.\n"+
         "");
      call_out("BeginFight",80);
      Warriors -= ({ Warriors[0] });
      WarriorNum -= 1;
   }
   else if(WarriorNum == 1){
      move_object(Warriors[0],this_object());
      tell_room(this_object(),
         "Shang Tsung appears from a cloud of smoke.\n"+
         "Shang Tsung says: You have killed my favorite Warrior.\n"+
         "I see you are worthy in combat, but you have never\n"+
         "faced a True Champion.\n"+
         "Prepare To DIE!\n"+
         "");
      call_out("BeginFight",10);
      Warriors -= ({Warriors[0] });
      WarriorNum -= 1;
   }
}

BeginFight(){
   if(!present("warrior",this_object())->query_attack()){
      tell_room(this_object(),"A Voice says: FIGHT!\n");
      present("warrior",this_object())->StartFight(RealAttack);
   }
}

Fight(){
   present("warrior",this_object())->StartFight(RealAttack);
}

query_NM(){
   if(present("raiden",this_object())){
      tell_room(this_object(),
         "Raiden's strong electric field interferes with your magic.\n"+
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
      Fight();
      return 1;
   }
   else {
      return 0;
   }
}
