inherit "obj/monster";
#define me		this_object()
reset(arg){
   object hat, suspenders, condom;
   ::reset(arg);
   if(arg) return;
   set_name("left-eye");
   set_race("human");
   set_short("Left-Eye");
   set_long(
   "    Left-Eye Lopez is chillin' with her homeys in this fly\n"+
   "fly establishment.  Though not nearly as fly-lookin' as her\n"+
   "friends, she can none-the-less turn heads.  She is maxin'\n"+
   "and relaxin' in her suspenders and has a whole stash of\n"+
   "condoms along her clothes.\n");
   set_level(19);
   set_hp(470);
   set_ac(19);
   set_wc(28);
   set_al(250);
   call_out("proud_me",10);
}
proud_me() {
   say("Left-Eye sings: You mic check 1-2, 1-2...\n");
   call_out("proud_2",2);
   return 1;
}
proud_2() {
   say("Left-Eye sings: WE IN THE HOUSE!!! \n");
   call_out("proud_3",2);
   return 1;
}
proud_3() {
   say("Left-Eye sings: 1992 TLC kickin off in your MUTHA..\n");
   call_out("proud_4",2);
   return 1;
}
proud_4() {
   say("Left-Eye sings: So ya best be duckin fast!\n");
   call_out("proud_5",2);
   return 1;
}
proud_5() {
   say("Left-Eye sings: Yo T-boz is ya being a boss?\n");
   call_out("proud_6",1);
   return 1;
}
proud_6() {
   say("Left-Eye sings: Chilli wassup wit dat sauce?\n");
   call_out("proud_7",2);
   return 1;
}
proud_7() {
   say("Left-Eye sings: Dis is it!\n");
   call_out("proud_8",2);
   return 1;
}
proud_8() {
   object ob;
   say("Left-Eye sings: Yo `T' step on that Shhhhhhhhhh..\n");
   if(present("t-boz", environment(me))){
      call_out("proud_9",2);
      return 1;
   }
   else {
      say("Left-Eye says: Where is that girl!\n");
      return 1;
   }
}
proud_9() {
   say("T-Boz sings: Thinkin short of what you got,\n");
   call_out("proud_10",1);
   return 1;
}
proud_10() {
   say("T-Boz sings: Better get it while its hot!\n");
   call_out("proud_11",1);
   return 1;
}
proud_11() {
   say("T-Boz sings: Ain't no better love than your own!\n");
   call_out("proud_12",1);
   return 1;
}
proud_12() {
   say("T-Boz sings: Unmistakin' urge to be sexin' with society,\n");
   call_out("proud_13",1);
   return 1;
}
proud_13() {
   say("T-Boz sings: How can you be happy alooone??\n");
   if(present("chilli", environment(me))){
      call_out("proud_14",2);
      return 1;
   }
   else {
      say("T-Boz says: Isn't that just like Chilli! Leavin' us hangin'!\n");
      return 1;
   }
   return 1;
}
proud_14() {
   say("Chilli sings: When I need 2 feel love\n");
   call_out("proud_15",1);
   return 1;
}
proud_15() {
   say("Chilli sings: Why wait for so long\n");
   call_out("proud_16",1);
   return 1;
}
proud_16() {
   say("Chilli sings: Cause I ain't too proud to beg\n");
   call_out("proud_17",1);
   return 1;
}
proud_17() {
   say("Chilli sings: For something I call my own!\n");
   call_out("proud_18",1);
   return 1;
}
proud_18() {
   say("Chilli sings: And I want to be touched,\n");
   call_out("proud_19",1);
   return 1;
}
proud_19() {
   say("Chilli sings: And feeling so much see cause\n");
   call_out("proud_20",1);
   return 1;
}
proud_20() {
   say("Chilli sings: Everybody needs some good...\n");
   call_out("proud_21",1);
   return 1;
}
proud_21() {
   say("Chilli sings: LOOVVIIN!!\n");
   if(present("left-eye", environment(me))){
      call_out("proud_22", 2);
      return 1;
   }
   else {
      say("Chilli says: Where's Left-Eye?\n");
      return 1;
   }
   return 1;
}
proud_22() {
   say("Left-Eye sior in the middle of the night!\n");
   call_out("proud_23",1);
   return 1;
}
proud_23() {
   say("Left-Eye sings:  If the lovin' is strong then he got it goin' on and\n");
   call_out("proud_24",1);
   return 1;
}
proud_24() {
   say("Left-Eye sings:  Two inches or a YARD rock hard or if its saggin'\n");
   call_out("proud_25",1);
   return 1;
}
proud_25() {
   say("Left-Eye sings:  So if it ain't like I'm braggin', just join the paddywagon cause..\n");
   call_out("proud_26",1);
   return 1;
}
proud_26() {
   say("Left-Eye sings: I ain't too proud, I ain't too proud to beg!\n");
   if(present("t-boz", environment(me))){
      return 1;
   }
   else {
      say("Left-Eye says: How can I sing without my posse?\n");
      return 1;
   }
} 
