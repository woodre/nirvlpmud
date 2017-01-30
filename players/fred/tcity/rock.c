#include "/players/fred/ansi.h"
#include "/players/fred/defines.h"
inherit "/obj/treasure.c";
string newname;


id(str){
  return (str == "rock" || str == "pet rock" || str == newname);
  }

reset (arg) {
 short_desc = "A pet rock";
 long_desc = 
  "  A medium sized rock with an almost smooth glass-like finish to\n"+
  "it. It is the perfect pet for the poor or the ever popular idler.\n"+
  "You don't have to feed or walk it or anything! To see what you can\n"+
  "do with it just '"+BOLD+YEL+"gaze"+NORM+"' at it.\n";
 set_weight(1);
 set_value(50);
}

init(){
 ::init();
   add_action("riiiight", "gaze");
   add_action("yup_yup", "huggle");
   add_action("doobie_doo", "hug");
   add_action("boggle_choggle", "kiss");
   add_action("silly_wiz", "feed");
   add_action("dern_MAL", "pet");
   add_action("pets_gotta_have_names", "rname");
   add_action("cow_chow", "wrestle");
   add_action("la_vaca_dice_moooo", "toss");
   add_action("green_goodness", "giggle"); 
   add_action("birddy_poo", "scold");
   add_action("fudge_circle", "commend");
}

riiiight(str){
  if(str == "rock" || str == newname){
  write("You can 'huggle, hug, kiss, feed, pet, rname, wrestle, toss,\n"+
        "         giggle, scold, and commend' your new pet.\n");
  return 1; }
}

yup_yup(str){
  if(str == "rock"){
   write("You huggle your pet rock tightly!\n");
   say(ENN+" huggles "+POS+" pet rock tightly.\n");
   return 1; }
  if(str == newname){
   write("You huggle "+BOLD+BLK+CAP(newname)+NORM+" tightly!\n");
   say(ENN+" huggles "+POS+" pet rock tightly.\n");
   return 1; }
 }

doobie_doo(str){
  if(str == "rock"){
   write("You hug your pet rock making you feel warm and happy!\n");
   say(ENN+" hugs "+POS+" pet rock happily.\n");
   return 1; }
  if(str == newname){
   write("You hug "+BOLD+BLK+CAP(newname)+NORM+" making you feel warm and happy!\n");
   say(ENN+" hugs "+POS+" pet rock happily.\n");
   return 1; }
}

boggle_choggle(str){
  if(str == "rock"){
   write("You cover your pet rock with little kisses.\n");
   say(ENN+" repeatedly kisses a pet rock.\n");
   return 1; }
  if(str == newname){
   write("You cover "+BOLD+BLK+CAP(newname)+NORM+" with little kisses.\n");
   say(ENN+" repeatedly kisses a pet rock.\n");
   return 1; }
}

silly_wiz(str){
  if(str == "rock"){
   write("You offer your pet rock some food in hopes it will eat.\n");
   say(ENN+" foolishly offers "+POS+" pet rock some food.\n");
   return 1; }
  if(str == newname){
   write("You offer "+BOLD+BLK+CAP(newname)+NORM+" some food in hopes it will eat.\n");
   say(ENN+" foolishly offers "+POS+" pet rock some food.\n");
   return 1; }
}

dern_MAL(str){
  if(str == "rock"){
   write("You lovingly pet your pet rock.\n");
   say(ENN+" lovingly pets "+POS+" pet rock.\n");
   return 1; }
  if(str == newname){
   write("You lovingly pet "+BOLD+BLK+CAP(newname)+NORM+".\n");
   say(ENN+" lovingly pets "+POS+" pet rock.\n");
   return 1; }
}

pets_gotta_have_names(str){
  write("You look at your little pet rock and think to yourself.\n"+
        "You look like a "+BOLD+BLK+CAP(str)+NORM+". Yeah that's it! From now on your\n"+
        "name is going to be "+BOLD+BLK+CAP(str)+NORM+".\n");
  short_desc = "A pet rock named "+BOLD+BLK+CAP(str)+NORM+"";
  newname = str;
  return 1; }

cow_chow(str){
  if(str == "rock"){
   write("You roll around on the ground wrestling with your pet rock.\n");
   say(ENN+" rolls around on the ground wrstling with a pet rock.\n");
   return 1; }
  if(str == newname){
   write("You roll around on the ground wrestling with "+BOLD+BLK+CAP(newname)+NORM+".\n");
   say(ENN+" rolls around on the ground wrstling with a pet rock.\n");
   return 1; }
}

la_vaca_dice_moooo(str){
  if(str == "rock"){
   write("You playfully toss your pet rock back and forth in your hands.\n");
   say(ENN+" playfully tosses "+POS+" pet rock back and forth in "+POS+" hands.\n");
   return 1; }
  if(str == newname){
   write("You playfully toss "+BOLD+BLK+CAP(newname)+NORM+" back and forth in your hands.\n");
   say(ENN+" playfully tosses "+POS+" pet rock back and forth in "+POS+" hands.\n");
   return 1; }
}

green_goodness(str){
  if(str == "rock"){
   write("You giggle inanely at your pet rock.\n");
   say(ENN+" giggles inanely at "+POS+" pet rock.\n");
   return 1; }
  if(str == newname){
   write("You giggle inanely at "+BOLD+BLK+CAP(newname)+NORM+".\
n");
   say(ENN+" giggles inanely at "+POS+" pet rock.\n");
   return 1; }
}

birddy_poo(str){
  if(str == "rock"){
   write("You shake your finger at your pet rock and yell.\n"+
         "No! That's a bad pet rock! Bad!\n");
   say(ENN+" looks at "+POS+" pet rock and yells.\n"+
           "No! That's a bad pet rock! Bad!\n");
   return 1; }
  if(str == newname){
   write("You shake your finger at "+BOLD+BLK+CAP(newname)+NORM+" and yell.\n"+
         "No! That's a bad "+BOLD+BLK+CAP(newname)+NORM+"! Bad!\n");
   say(ENN+" looks at "+POS+" pet rock and yells.\n"+
           "No! That's a bad pet rock! Bad!\n");
   return 1; }
}

fudge_circle(str){
  if(str == "rock"){
   write("You smile happily at you pet rock and exclaim.\n"+
         "You're a good pet rock. Yes, Yes you are, aren't you.\n");
   say(ENN+" smiles at "+POS+" pet rock and exclaims.\n"+
           "You're a good pet rock. Yes, Yes you are, aren't you.\n");
   return 1; }
  if(str == newname){
   write("You smile happily at "+BOLD+BLK+CAP(newname)+NORM+" and exclaim.\n"+
         "You're a good pet rock. Yes, Yes you are, aren't you.\n");
   say(ENN+" smiles at "+POS+" pet rock and exclaims.\n"+
           "You're a good pet rock. Yes, Yes you are, aren't you.\n");
   return 1; }
}
