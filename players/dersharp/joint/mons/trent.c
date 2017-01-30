inherit "obj/monster";
reset(arg){
   object nails;
   ::reset(arg);
   if(arg) return;
   set_name("trent");
   set_race("human");
   set_alias("reznor");
   set_short("Trent Reznor");
   set_long(
   "    This is a man that has a somber look upon his brow.  He is\n"+
   "surrounded by sequencing equipment, synthesizers, and mixers.\n"+
   "He doesn't even notice you enter as he is writing another of\n"+
   "his kick ass songs.  He is after all the creator of Nine Inch\n"+
   "Nails!  As such he probably will kick your butt.\n");
   set_level(18);
   set_hp(450);
   set_ac(13);
   set_wc(27);
   set_al(-500);
}
catch_tell(str) {
   string a, b, c;
   if(sscanf(str, "%ssing%snine%s", a, b, c) == 3) {
   call_out("sing_intro", 3);
   return 1;
   }
}
sing_intro() {
    say("Trent says:  You want a song ehh?\n");
   call_out("sing_me", 4);
   return 1;
}
sing_me() {
   say("Trent sings: You gave me the reason.\n");
   call_out("sing_2",2);
   return 1;
}
sing_2() {
   say("Trent sings: You gave me control.\n");
   call_out("sing_3",2);
   return 1;
}
sing_3() {
   say("Trent sings: I gave you my purity.\n");
   call_out("sing_4",2);
   return 1;
}
sing_4() {
   say("Trent sings: And my purity you stole!\n");
   call_out("sing_5",1);
   return 1;
}
sing_5() {
   say("Trent sings: Did you think I wouldn't recognize\n");
   call_out("sing_6",1);
   return 1;
}
sing_6() {
   say("Trent sings: This compromise!\n");
   call_out("sing_7",1);

   return 1;
}
sing_7() {
   say("Trent sings: Am I just too stupid to realize!\n");
   call_out("sing_8",1);
   return 1;
}
sing_8() {
/* Leaving this in, cause it's funny, but adding correct lyrics below */
/* Rumplemintz
   say("Trent sings: Da da da and soul and sweat,\n");
*/
   say("Trent sings: Stale incense, old sweat,\n");
   call_out("sing_9",1);
   return 1;
}
sing_9() {
   say("Trent sings: and LIES LIES LIES!\n");
   call_out("sing_10",2);
   return 1;
}
sing_10() {
   say("Trent sings: It comes down to this!\n");
   call_out("sing_11",1);
   return 1;
}
sing_11() {
   say("Trent sings: Your kiss!\n");
   call_out("sing_12",1);
   return 1;
}
sing_12() {
   say("Trent sings: Your fist!\n");
   call_out("sing_13",1);
   return 1;
}
sing_13() {
   say("Trent sings: And the strain, it gets under my skin!\n");
   call_out("sing_14",1);
   return 1;
}
sing_14() {
   say("Trent sings: Taken WITHIN!\n");
   call_out("sing_15",1);
   return 1;
}
sing_15() {
   say("Trent sings: The extent to my skin!\n");
/*
   call_out("sing_me",20);
*/
   call_out("sing_16",1);
   return 1;
}
sing_16() {
   say("Trent sings: You give me the anger.\n");
   call_out("sing_17",1);
   return 1;
}
sing_17() {
   say("Trent sings: You give me the nerve.\n");
   call_out("sing_18",1);
   return 1;
}
sing_18() {
   say("Trent sings: Carry out my sentence.\n");
   call_out("sing_19",1);
   return 1;
}
sing_19() {
   say("Trent sings: Will I get what I deserve.\n");
   call_out("sing_20", 1);
   return 1;
}
sing_20() {
   say("Trent sings: I'm just an effigy to be defaced,\n");
   call_out("sing_21", 1);
   return 1;
}
sing_21() {
   say("Trent sings: To be disgraced,\n");
   call_out("sing_22", 1);
   return 1;
}
sing_22() {
   say("Trent sings: Your need for me has been replaced.\n");
   call_out("sing_23", 1);
   return 1;
}
sing_23() {
   say("Trent sings: And if I can't have everything, well then just give me a taste.\n");
   call_out("sing_24", 1);
   return 1;
}
sing_24() {
   say("Trent sings: It comes down to this!\n");
   call_out("sing_25", 1);
   return 1;
}
sing_25() {
   say("Trent sings: Your kiss!\n");
   call_out("sing_26", 1);
   return 1;
}
sing_26() {
   say("Trent sings: Your fist!\n");
   call_out("sing_27", 1);
   return 1;
}
sing_27() {
   say("Trent sings: And your strain, it gets under my skin!\n");
   call_out("sing_28", 1);
   return 1;
}
sing_28() {
   say("Trent sings: Within!\n");
   call_out("sing_29", 1);
   return 1;
}
sing_29() {
   say("Trent sings: Take in!\n");
   call_out("sing_30", 1);
   return 1;
}
sing_30() {
   say("Trent sings: The extent of my sin!\n");
   call_out("sing_31", 1);
   return 1;
}
sing_31() {
   say("Trent sings: You give me the reason.\n");
   call_out("sing_32", 1);
   return 1;
}
sing_32() {
   say("Trent sings: You give me control.\n");
   call_out("sing_33", 1);
   return 1;
}
sing_33() {
   say("Trent sings: I gave you my purity,\n");
   call_out("sing_34", 1);
   return 1;
}
sing_34() {
   say("Trent sings: My purity you stole.\n");
   call_out("sing_35", 1);
   return 1;
}
sing_35() {
   say("Trent sings: Did you think I wouldn't recognize,\n");
   call_out("sing_36", 1);
   return 1;
}
sing_36() {
   say("Trent sings: this compromise?\n");
   call_out("sing_37", 1);
   return 1;
}
sing_37() {
   say("Trent sings: Am I just too stupid to realize?\n");
   call_out("sing_38", 1);
   return 1;
}
sing_38() {
   say("Trent sings: Stale incense, old sweat,\n");
   call_out("sing_39", 1);
   return 1;
}
sing_39() {
   say("Trent sings: and LIES, LIES, LIES!\n");
   call_out("sing_40", 1);
   return 1;
}
sing_40() {
   say("Trent sings: It comes down to this!\n");
   call_out("sing_41", 1);
   return 1;
}
sing_41() {
   say("Trent sings: Your kiss!\n");
   call_out("sing_42", 1);
   return 1;
}
sing_42() {
   say("Trent sings: Your fist!\n");
   call_out("sing_43", 1);
   return 1;
}
sing_43() {
   say("Trent sings: And your strain, it gets under my skin!\n");
   call_out("sing_44", 1);
   return 1;
}
sing_44() {
   say("Trent sings: Within!\n");
   call_out("sing_45", 1);
   return 1;
}
sing_45() {
   say("Trent sings: TAKE IN!\n");
   call_out("sing_46", 1);
   return 1;
}
sing_46() {
   say("Trent sings: for my sin! It comes down to this!\n");
   call_out("sing_47", 1);
   return 1;
}
sing_47() {
   say("Trent sings: Your kiss!\n");
   call_out("sing_48", 1);
   return 1;
}
sing_48() {
   say("Trent sings: Your fist!\n");
   call_out("sing_49", 1);
   return 1;
}
sing_49() {
   say("Trent sings: And your strain, it comes under my skin!\n");
   call_out("sing_50", 1);
   return 1;
}
sing_50() {
   say("Trent sings: Within!\n");
   call_out("sing_51", 1);
   return 1;
}
sing_51() {
   say("Trent sings: TAKE IN!\n");
   call_out("sing_52", 1);
   return 1;
}
sing_52() {
   say("Trent sings: The extent to my sin!\n");
   return 1;
}
