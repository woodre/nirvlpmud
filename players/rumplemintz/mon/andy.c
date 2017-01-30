/*
* Andy Samberg for I'm on a boat
*/

inherit "/obj/monster";

void reset(int arg){
   ::reset(arg);
   if(arg) return;
   set_name("Andy");
   set_alias("andy");
   set_alt_name("andy samberg");
   set_race("human");
   set_short("Andy Samberg");
   set_long("\
David Andrew Samberg is an American comedian,, actor, writer and a crunk \n\
rapper.  He is a member of the comedy troupe The Lonely island (along with \n\
Jorma Taccone and Akiva Schaffer) and a repertory player on Saturday Night \n\
Live.\n");
   set_level(11);
   set_al(-500);
   call_out("BOAT", 10);
}

BOAT(){
   say("Andy says: AHHH Shit!\n");
   call_out("B2", 1);
   return 1;
}
B2(){
   say("Andy says: Get your towels ready! It's about to go down.\n");
   call_out("B3", 1);
   return 1;
}
B3(){
   say("Andy says: Everybody in the place hit the fucking deck\n");
   call_out("B4", 1);
   return 1;
}
B4(){
   say("Andy says: But stay on your motherfucking toes\n");
   call_out("B5",1);
   return 1;
}
B5(){
   say("Andy says: We running this, let's go!\n");
   if(present("akiva", environment(this_object()))){
      call_out("B6", 2);
      return 1;
   } else {
      say("Andy says: Akiva?  God dammit, where's Akiva?\n");
      return 1;
   }
}
B6(){
   say("Lonely Island says: I'm on a boat!\n");
   if(present("tpain", environment(this_object()))){
      say("T-Pain sings: I'm on a booaat\n");
      call_out("B7", 2);
      return 1;
   } else {
      say("Andy says: Where the fuck is T-Pain?!?!\n");
      return 1;
   }
}
B7(){
   say("Lonely Island says: I'm on a boat!\n");
   say("T-Pain sings: I'm on a booaaat\n");
   call_out("B8",2);
   return 1;
}
B8(){
   say("Lonely Island says: Everybody look at me 'Cause I'm sailing on a boat!\n");
   say("T-Pain sings: Sailing on a boat\n");
   call_out("B9",2);
   return 1;
}
B9(){
   say("Lonely Island says: I'm on a boat!\n");
   say("T-Pain sings: I'm on a booaat\n");
   call_out("B10",2);
   return 1;
}
B10(){
   say("Lonely Island says: I'm on a boat!\n"); call_out("B11",1); return 1;
}
B11(){
   say("Lonely Island says: Take a good hard look at the motherfuckin boat!\n");
   say("T-Pain sings: Yeeeahhhh\n");
   call_out("B12",2);
   return 1;
}
B12(){
   say("Akiva says: I'm on a boat motherfucker, take a look at me\n");
   call_out("B13",2);
   return 1;
}
B13(){
   say("Akiva says: Straight flowing on a boat on the deep blue sea\n");
   call_out("B14",2);
   return 1;
}
B14(){
   say("Akiva says: Busting five knots, wind whipping out my coat\n");
   call_out("B15", 2);
   return 1;
}
B15(){
   say("Akiva says: You can't stop me motherfucker, 'cause I'm on a boat!\n");
   call_out("B16", 1);
   return 1;
}
B16(){
   say("Andy says: Take a picture, trick\n");
   say("T-Pain sings: Trick\n");
   call_out("B17", 1);
   return 1;
}
B17(){
   say("Andy says: I'm on a boat, bitch\n");
   say("T-Pain sings: Bitch\n");
   call_out("B18", 1);
   return 1;
}
B18(){
   say("Andy says: We drinking Santana champ 'cause it's so crisp\n");
   call_out("B19", 2);
   return 1;
}
B19(){
   say("Andy says: I got my swim trunks\n");
   call_out("B20", 1);
   return 1;
}
B20(){
   say("Andy says: and my flippie-floppies\n");
   call_out("B21", 1);
   return 1;
}
B21(){
   say("Andy says: I'm flippin burgers, you at Kinko's, straight flippin copies\n");
   call_out("B22", 2);
   return 1;
}
B22(){
   say("Akiva says: I'm riding on a dolphin\n");
   call_out("B23", 1);
   return 1;
}
B23(){
   say("Akiva says: doin flips and shit\n");
   call_out("B24", 1);
   return 1;
}
B24(){
   say("Akiva says: This dolphin's splashin\n");
   call_out("B25", 1);
   return 1;
}
B25(){
   say("Akiva says: gettin everybody all wet\n");
   call_out("B26", 1);
   return 1;
}
B26(){
   say("Akiva says: But this ain't Seaworld\n");
   call_out("B27", 1);
   return 1;
}
B27(){
   say("Akiva says: it's as real as it gets\n");
   call_out("B28", 1);
   return 1;
}
B28(){
   say("Akiva says: I'm on a boat motherfucker, don't you ever forget!\n");
   call_out("B29", 2);
   return 1;
}
B29(){
   say("Andy sings: I'm on a boat aaannnd\n");
   call_out("B30", 1);
   return 1;
}
B30(){
   say("Andy sings: It's goin fast aannnd\n");
   call_out("B31", 1);
   return 1;
}
B31(){
   say("Andy sings: I got a nautical themed, Pashmina Afghan\n");
   call_out("B32", 2);
   return 1;
}
B32(){
   say("Andy sings: I'm the king of the world\n");
   call_out("B33", 1);
   return 1;
}
B33(){
   say("Andy sings: on a boat like Leo\n");
   call_out("B34", 1);
   return 1;
}
B34(){
   say("Andy sings: If you're on the shore\n");
   call_out("B35", 1);
   return 1;
}
B35(){
   say("Andy sings: then you're sure not me-oh\n");
   call_out("B36", 3);
   return 1;
}
B36(){
   say("Andy says: Get the fuck up!\n");
   call_out("B37", 1);
   return 1;
}
B37(){
   say("Andy says: This boat is real!\n");
   call_out("B38", 2);
   return 1;
}
B38(){
   say("Akiva says: Fuck land, I'm on a boat motherfucker!\n");
   say("T-Pain sings: Motha fuckaaa\n");
   call_out("B40", 2);
   return 1;
}
B40(){
   say("Akiva says: Fuck trees, I climb buoys mother fucker!\n");
   say("T-Pain sings: Mutha fuckaaa\n");
   call_out("B42", 1);
   return 1;
}
B42(){
   say("Akiva says: I'm on the deck with my boys motherfucker!\n");
   say("T-Pain sings: Yeaeeaahhh\n");
   call_out("B44", 1);
   return 1;
}
B44(){
   say("Akiva says: This boat engine make noise, motherfucker!\n");
   call_out("B45", 1);
   return 1;
}
B45(){
   say("Andy says: Hey ma, if you could see me now\n");
   say("T-Pain sings: see me nooowww\n");
   call_out("B47", 1);
   return 1;
}
B47(){
   say("Andy says: Arms spread wide on the starboard bow\n");
   say("T-Pain sings: Starboard boowwww\n");
   call_out("B49", 1);
   return 1;
}
B49(){
   say("Andy says: Gonna fly this boat, to the moon somehow\n");
   say("T-Pain sings: Moon somehoowwww\n");
   call_out("B51", 1);
   return 1;
}
B51(){
   say("Andy says: Like Kevin Garnett\n");
   call_out("B52", 1);
   return 1;
}
B52(){
   say("Andy screams: Anything is possiblllllllllee\n");
   call_out("B53", 2);
   return 1;
}
B53(){
   say("T-Pain sings: Never thought I'd be on a booaatt\n");
   call_out("B54", 2);
   return 1;
}
B54(){
   say("T-Pain sings: It's a big blue watery road\n");
   call_out("B55", 1);
   return 1;
}
B55(){
   say("T-Pain sings: Po-sei-den looook at meeeee oh\n");
   call_out("B56", 2);
   return 1;
}
B56(){
   say("T-Pain sings: Never thought I'd see the daaayy\n");
   call_out("B57", 2);
   return 1;
}
B57(){
   say("T-Pain sings: When a big boat coming my waaayy\n");
   call_out("B58", 1);
   return 1;
}
B58(){
   say("T-Pain sings: Believe me when I saaayyy\n");
   call_out("B59", 1);
   return 1;
}
B59(){
   say("T-Pain sings: I fucked a meerrrrmaaaaaiiiidddd\n");
   call_out("B60", 1);
   return 1;
}
B60(){
   say("Lonely Island says: I'm on a boat!\n");
   call_out("B61", 2);
   return 1;
}
B61(){
   say("Lonely Island says: I'm on a boat!\n");
   call_out("B62", 2);
   return 1;
}
B62(){
   say("Lonely Island says: Everybody look at me 'cause I'm sailing on a boat!\n");
   call_out("B63", 1);
   return 1;
}
B63(){
   say("T-Pain sings: Yeeeeahhhhhh\n");
   call_out("B64", 1);
   return 1;
}
B64(){
   say("Lonely Island says: I'm on a boat!\n");
   call_out("B65", 2);
   return 1;
}
B65(){
   say("Lonely Island says: I'm on a boat!\n");
   call_out("B66", 2);
   return 1;
}
B66(){
   say("Lonely Island says: Take a good hard look at the motherfuckin boat!\n");
   call_out("B67", 2);
   return 1;
}
B67(){
   say("T-Pain sings: It's alllright\n");
   call_out("B68", 1);
   return 1;
}
B68(){
   say("T-Pain sings: It's alllright\n");
   call_out("B69", 1);
   return 1;
}
B69(){
   say("T-Pain sings: Yaaa-eee-yaaa-yaaaaaaa\n");
   call_out("BOAT", 300);
   return 1;
}
