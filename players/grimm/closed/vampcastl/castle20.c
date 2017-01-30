inherit "room/room";
int flag, timer, doneit;
reset(arg) {
   object vampire;
   vampire = present("vampire");
   if(present("vampire")) destruct(vampire);
   flag = 0;
if(arg)
   return;
short_desc="Chamber of Malachi";
long_desc="You have entered the sleeping chambers of Malachi.  Death is\n"+
          "certain at night!  The only exit from this his chambers seems to\n"+
          "be a hole in the ceiling.  Maybe you can climb out.\n";
set_light(1);
}
init() {
   object coffin;
   add_action("change","change");
   add_action("climb","climb");
   add_action("stake","stake");
   add_action("open","open");
   add_action("look","look");
   add_action("look","exa",1);
   add_action("look","la");
   add_action("look","l");
   add_action("kill","kill");
   add_action("timer","",1);
   ::init();
   if(!present("coffin")) {
      coffin = clone_object("players/grimm/object/coffin");
      move_object(coffin,this_object());
   }
}
timer() {
  if(timer && time() > timer && !doneit) {
    write("\n\nOh my God!  You've waited to long!  Malachi has awakened!\n");
    monster();
    doneit = 1;
  }
}
kill(str) {
   if(!str) return 0;
   if(str=="malachi"||str=="vampire") {
        write("You can't kill a powerful vampire that way!!\n");
      return 1; 
   }
   else return;
}
look(str) {
   if(!str) return;
   if(str=="in coffin"||str=="at vampire"||str=="at malachi"||str=="vampire"||str=="malachi") {
      if(!present("dayblade",this_player())) return;
      if(flag==0)  {write("The coffin is closed!\n");   return 1; }
      write("As you look into the coffin you can see the vampire.  You"+
            "\nshould hurry and destroy him before he awakens!\n");
      return 1; 
   }
   return;
}
monster() {
   object monster;
   if(!present("vampire")) {
         monster = clone_object("players/grimm/monster/malachi");
         move_object(monster,this_object());
   }
return 1; 
}
open(str) {
   if(!str) { write("Open what?\n");   return 1; }
   if(str!="coffin") return;
   if(flag>=1||present("vampire")) {
      write("The coffin is already open.\n");
      return 1;
   }
   if(present("dayblade",this_player())) {
      write("The light of the Dayblade lights the room and as you open the\n"+
            "coffin, you see the Vampire Malachi sleeping!\n");
      if(present("vamp cross",this_player())) {
        write("You feel the imense power of God in you as you look upon evil\n");
        write("You must hurry!  Even though you have the protection of\n"+
              "God,  Malachi will not sleep forever!\n");
        timer = time() + 150;
        flag = 1;
      }
      if(!present("vamp cross",this_player())) {
        write("You have no protection!!! Malachi awakes!!!\n");
        monster();
        flag = 2;
      }
      return 1; 
   }
   write("As you open the coffin, Malachi jumps out and attacks you!\n");
   monster();
   flag = 2;
return 1; 
}
stake(str) {
   object vampire;
   object vampwatch, cross,stake;
   if(!present("vamp stake",this_player())) {
      write("With what?\n");
   return 1; }
   if(!str) { write("Stake who?\n");  return 1; }
   if(str!="malachi") return 0;
   if(present("vampire")) {
      write("It is to late!! He has already awakened!!!!\n");
   return 1; }
   if(flag==1) {
      write("You have killed Malachi!!!\n");
      write("Your quest is over!!!!!  You have saved the town of Sacred Blood!\n");
      write_file("/players/grimm/closed/LOGS/malachi",capitalize(this_player()->query_real_name())+" just finished the damn quest.\nThe time is: "+ctime(time())+"\n-------------------------------\n");
      cross = present("vamp cross",this_player());
      stake = present("vamp stake",this_player());
      this_player()->set_quest("sage");
      destruct(cross);
      destruct(stake);
      cross = present("dayblade",this_player());
      destruct(cross);
      cross = present("vamp_jewel", this_player());
      destruct(cross);
   return 1; }
return ; 
}
night() {
  int i;
  i=ctime(time())[12]*10+ctime(time())[13];
  if(i==0||i==1)
    return 1;
  if(i==4||i==5)
    return 1;
  if(i==8||i==9)
    return 1;
  if(i==12||i==13)
    return 1;
  if(i==16||i==17)
    return 1;
  if(i==20||i==21)
    return 1;
  if(i==2||i==3)
    return 0;
  if(i==6||i==7)
    return 0;
  if(i==10||i==11)
    return 0;
  if(i==14||i==15)
    return 0;
  if(i==18||i==19)
    return 0;
  if(i==22||i==23)
    return 0;
}
climb() {
  write("You manage to reach the hole and climb out of Malachi secret exit!\n");
  this_player()->move_player("up into the hole#players/grimm/frst/forest12");
  return 1;
}
change() {
  write("As you try to change, Malachi over powers you and forces you back.\n");
  return 1;
}
realm() { return "NT"; }
