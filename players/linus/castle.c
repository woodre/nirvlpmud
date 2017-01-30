#define NAME "Linus"
#define DEST "/room/south/sforst10.c"
#include "/obj/lib/security/id.h"
#include "/players/linus/def.h"

/*
 * This is just the facade to a castle. If you want to enable the
 * "enter" command, move the player to a hall or something (which
 * you have to design yourself).
 * The predefined string DEST is where a player should come when he
 * leaves the castle.
 *
 * This file is loaded automatically from "init_file". We have to move
 * ourself to where we are supposed to be.
 */

id(str) { return str=="hank" || str=="hank the trader" || str=="hank_the_ugly_barter_dude"; }
short() { return "Hank the Trader"; }
long() {
 write("Tall and haggard looking, Hank isn't what you would call a handsome\n"+
       "man.  The left side of his face bears a large scar, and his left eye\n"+
       "is a pale grey color.  His thick beard and mustache show slivers of\n"+
       "grey, and a mop of thick brown hair falls past his shoulders. His\n"+
       "tattered clothes have seen better days, but are still sturdy enough\n"+
       "to provide protection from the elements.  Something about him beckons\n"+
       "you to 'ask' him for information.\n"+
       "Hank is in good shape.\n"); }
init() {
add_action("ask_for_information","ask");
add_action("follow_hank","follow");
add_action("attack_hank","kill");
add_action("attack_hank","attack");
add_action("attack_hank","fight");
add_action("attack_hank","hit");
add_action("attack_hank","kick");
add_action("attack_hank","punch");
add_action("poke_hank","poke");
add_action("tickle_hank","tickle");
add_action("sex_hank_wtf","sex");
add_action("sex_hank_wtf","grope");
add_action("sex_hank_wtf","fondle");
/* 11/15/05 Earwax: moved this from reset() ... no need for a callout
 * commencing at reset with no end.
 */
if (find_call_out("talk") == -1)
  call_out("talk",18);
}
attack_hank(str) {
 if(!str || str!="hank") { FAIL("Do what?\n"); return 0; }
 write("Hank gives you a stern look then grumbles: You don't wanna be messing with me!\n"); 
 say("Hank gives "+TPN+" a stern look then grumbles: You don't wanna be messing with me!\n");
 return 1;
}
tickle_hank(str) {
 if(!str || str!="hank") { FAIL("Do what?\n"); return 0; }
 write("Hank looks at you and grumbles: Don't tickle me.  You some sort of freak?!?\n");
 say("Hank looks at "+TPN+" and grumbles: Don't tickle me.  You some sort of freak?!?\n");
 return 1;
}
poke_hank(str) {
 if(!str || str!="hank") { FAIL("Do what?\n"); return 0; }
 write("Hank grumbles: Hey!  Just 'ask' for information.\n");
 say("Hank grumbles: Hey!  Just 'ask' for information.\n");
 return 1;
}
sex_hank_wtf(str) {
 if(!str || str!="hank") { FAIL("Do what?\n"); return 0; }
 if(TP->query_gender() == "male") {
  write("Hank stares at you in disbelief.  'I don't go for that sort of kinky stuff!\n"+
        "He then "+RED+"B A C K H A N D S"+NORM+" you across the face!\n");
  say("Hank stares at "+TPN+" in disbelief.  'I don't go for that sort of kinky stuff!\n"+
      "He then "+RED+"B A C K H A N D S"+NORM+" "+TPO+" across the face!\n");
 TP->hit_player(15);
 return 1;
}
if(TP->query_gender() == "female") {
 write("Hank blushes.  He then whispers to you: Sorry dear, my equipment quit on me long ago...\n"); 
 say("Hank blushes.  He then whispers something to "+TPN+"\n");
 return 1;
 }
}
ask_for_information(arg) {
  string x;
  if(!arg) { notify_fail("Ask whom?\n"); return 0; }
   if(sscanf(arg, "%shank%s",x,x)){
   write("Hank studies you for a moment, then grumbles: I met this fella once...\n"+
   "said he was a \"wizard\" or something.  He then pauses in thought...'Linus was\n"+
   "his name... started talking about all these dreams and plans that he had...'\n"+
   "Hank stares blankly for a moment...'Anyhow...this Linus fella asked me to do\n"+
   "him a favor.'  He then reaches into his pocket and pulls out a crumpled piece\n"+
   "of paper.  He smoothes it out the best he can and shows it to you.  On it are\n"+
   "the words:\n\n\n\                  "+GRN+"The hundred acre 'wood'"+NORM+"\n\n\n\n"+
   "Hank then adds: I can show you the way.  Just 'follow me to the <area>'.\n");
   return 1;
    }
  return(notify_fail("You can only \"ask hank\".\n"), 0);
  }
follow_hank(string str) {
 if(!str) { FAIL("Hank grumbles: Where do you wanna go?\n"); return 0; }
  if(str == "hank wood" || str == "hank to wood" || str == "hank" || str == "hank to the wood" || str == "wood") {
tell_room(environment(),"Hank grumbles: Follow me...\n");
TP->move_player("following Hank#/players/linus/Newbie/room/n1.c");
tell_object(TP,"Hank grumbles: Here we are.\n\n");
tell_object(TP,"Hank leans in close to you and whispers: Oh...one more thing...\n"+ 
  "There are critters that live in there.  I'll buy their parts off of ya.\n\n");
tell_object(TP,"All ya gotta do is bring the item to me and 'barter <item>'.\n");
tell_object(TP,"Hank glances around quickly, then wanders off.\n");
 return 1;
}
}
reset(arg) {
 if(arg) return;
 move_object(this_object(),DEST);
}

talk() {
 switch(random(4)) {
 case 0: say("Hank grumbles: Don't be staring at my eye.  Bear damn near killed me years ago!\n"); break;
 case 1: say("Hank grumbles: Go see the hundred acre wood.   Just 'ask' me how.\n");break;
 case 2: say("Hank surveys the area...\n");break;
 case 3: say("Hank pulls out a knife and starts cleaning his nails...\n");break;
 }
  /* 11/15/05 Earwax: don't replicate callout unless player present */
  if (present(PLAYERID, environment(this_object())))
    call_out("talk",1+random(10));
}
is_castle(){return 1;}
