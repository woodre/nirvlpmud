inherit "room/room";
int mirrorflag,chordflag;
int bedflag,searchflag;
realm() { return "NT"; }
reset(arg) {
if(arg)
   return;
short_desc="Castle Bedroom";
long_desc="Walking into the bedroom your body feels as though it is being\n"+
          "probed.  You feel very weak because of the intense evil being\n"+
          "poured into your soul.  In the corner of the room is a large\n"+
          "bed and on the north wall hangs a large mirror.  A cord that\n"+
          "turns the light on and off also hangs here.\n",
items=({"bed","This is a regular bed with blood red sheets",
        "cord","It is a long cord that controls the lights",
        "mirror","This is a strange looking mirror.  It almost calls to you!"});
dest_dir=({"players/grimm/closed/vampcastl/castle17","west"});
set_light(1);
}
init() {
   add_action("itbreak","break");
   add_action("enter","enter");
   add_action("pull","pull");
   add_action("south","south");
   add_action("down","down");
   add_action("move","move");
   add_action("move","push");
   add_action("west","west");
   add_action("search","search");
   return 0;
}
west() {
  this_player()->move_player("west#/players/grimm/closed/vampcastl/castle17");
  return 1;
}
pull(str) {
   if(!str) {
      write("Pull what?\n");
   return 1; }
   if(str!="cord") return;
   if(chordflag ==0) {
   write("As the lights dim a passage to the south opens up!\n");
   chordflag=1; 
   return 1; }
   if(chordflag==1) {
      write("When you pull the cord the light comes on.\n");
      chordflag = 0;
   return 1; }
}
south() {
   if(!chordflag) return 0;
   this_player()->move_player("south into darkness#players/grimm/closed/vampcastl/castle19");
   monster();
   chordflag = 0;
   bedflag = 0;
   searchflag = 0;
   mirrorflag = 0;
return 1; 
}
monster() {
   object monster;
   if(!present("werewolf")) {
   monster = clone_object("players/grimm/monster/werewolf");
   move_object(monster,this_object());
   }
}
itbreak(str) {
   if (!str) {
      write("Break what?\n");
   return 1; }
   if(str!="mirror") return 0;
   if(mirrorflag==0) {
   write("CRASH!!!!!!!!!\n");
   write("As the glass falls you notice a passage behind the broken mirror!!\n");
   write("Looking deeper into the passage you see a huge werewolf coming towards you!!\n");
   monster();
   mirrorflag=1;
   return 1; }
   if(mirrorflag==1) { 
      write("It is already broken!\n");
   return 1; }
}
enter(str) {
   if(!str) { write("Enter what?\n"); return 1; }
   if(str!="mirror") return 0;
   if(present("werewolf")) {
      write("The werewolf says:  I'll protect my master at any cost!!\n");
   return 1; }
   if(mirrorflag==1&&chordflag==1) {
      write("As you enter the mirror you feel as though there is no turning\n"+
            "back.\n");
      this_player()->move_player("into the mirror#players/grimm/closed/vampcastl/castle22");
      mirrorflag = 0 ;  chordflag = 0;
      searchflag = 0 ;  bedflag = 0;
   return 1; }
   if(mirrorflag==1) {
      write("You will surely die....Vampire Killer!!!\n");
      this_player()->move_player("into the mirror#players/grimm/closed/vampcastl/castle21");
      mirrorflag = 0;    chordflag = 0;
   return 1; }
   write("You bump into the mirror as you try to walk through it.\n");
   mirrorflag = 0;
return 1;
}
move(arg) {
  int x;
  if(!arg) return;
  if(arg=="bed") {
    x = random(100);
    if(x>80) {
      write("You use all your strength to push bed up to the wall.\n");
      bedflag = 1;
      return 1;
    }
    write("You try to push the bed but i think it is too heavy.\n");
    return 1;
  }
}
search() {
   if(bedflag)  {
     write("You find a secret passage leading down!!\n");
     searchflag = 1;
     return 1;
   }
   write("You search around for a while, but don't find anything interesting.\n");
   return 1;
}
down() {
  if(!searchflag) return;
  write("You enter the secret passage way...Beware!!\n");
  this_player()->move_player("into the passage#players/grimm/closed/vampcastl/castle27");
  searchflag = 0;
  bedflag = 0;
  return 1;
}
