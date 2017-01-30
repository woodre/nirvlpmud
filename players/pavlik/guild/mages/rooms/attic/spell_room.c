#include "/players/pavlik/guild/mages/macs"
#include "/players/pavlik/guild/mages/rooms/GUILD_COSTS"
#include "/players/pavlik/guild/mages/rooms/ROOMS"
inherit "room/room";
  string seated;
reset(arg) {
  if(!arg) {
set_light(1);
short_desc="Yshir's Chambers";
long_desc=
"You are in the main room of Yshir's chambers.  You hear quiet\n"+
"classical music playing in the backround.  The walls are decorated\n"+
"with a wide variety of classical art works.  The only furniture\n"+
"in the room are two soft plush chairs and a baby grand piano in\n"+
"northwest corner.  You realize that the piano is from where the\n"+
"music is emanating, although noone is seated on its bench.\n";

items=({
"wall",
"The walls are decorated with a tastleful collection of classical\n"+
"art works, each of which is priceless",
"chairs",
"There are two soft plush chairs in the center of the room",
"chair",
"There are two soft plush chairs in the center of the room",
"piano",
"The piano is a sleek black baby grand.  The piano plays along\n"+
"quietly, even though there is noone seated at its bench.  There\n"+
"is some sheet music on top of the instrument",
"sheet music",
"Several sheets of music are spread across the top of the piano.\n"+
"There is some writing at the top of the last page:\n"+
"  Hello friend, welcome to my quarters.  If you need my\n"+
"  assistance with training in your spell abilities,\n"+
"  please have a seat, and I will be with you in a\n"+
"  moment.                  -  Yshir",
});


dest_dir=({
 "/players/pavlik/guild/mages/rooms/masters_hall", "south",
 "/players/pavlik/guild/mages/rooms/BLAH", "north",
});

seated = "no_one";
   }
}

query_mguild(){ return "Yshir's"; }

init(){
 ::init();
  if(!present(seated, this_object())) seated = "no_one";
  mage_check();
  add_action("guild_move2","gm");
  add_action("guild_move","GM");
  add_action("sit_down","sit");
  add_action("raise","cost");
  add_action("raise","raise");
  add_action("wake","wake");
  add_action("north","north");
  add_action("east","east");
  add_action("play_piano","play");
  add_action("chair_help","??");
}

sit_down(){
  if(!present(seated, this_object()))
    seated = "no_one";
  if(seated != "no_one"){
    write("The chair already occupied by "+seated+".\n");
    return 1;
    }
  write(
  "You sit down in the soft chair and quickly notice how comfortable\n"+
  "it is.  The piano starts to play slow soothing music and you are\n"+
  "soon fast asleep.\n"+
  "A vision comes to you in your dreams ... a stunningly beautiful\n"+
  "woman in blue-gold robes approaches you.\n"+
  "Yshir says: Welcome Mage, how may I help you?\n"+
  "          type '??' for commands.\n");
  seated = this_player()->query_real_name();
  say(
  ME+" sits down in the chair and immediately falls asleep.\n");
  return 1;
}

guild_move2(str){
  if(rlname == seated){
    write("You can't do that.  You are fast asleep!\n");
    return 1;
    }
  command("GM "+str, tp);
  return 1;
}

chair_help(){
  if(rlname != seated){
  write("What?\n"); return 1; }
  write("Some ideas come to, as if from a dream ......... \n"+
  "   raise <schl> <#>     - raise a school stat # pts.\n"+
  "   cost <schl> <#>      - query cost to raise school # pts.\n"+
  "   wake                 - leave the chair.\n"+
  "     exa: raise ench 10 _or_ cost illu 15\n"+
  "You snore peacefully.\n");
  say(ME+" snores peacefully.\n");
  return 1;
}

wake(){
  if(rlname != seated){
    write("You are not sitting down.\n");
    return 1;
    }
  write(
  "You blink your sleepy eyes a couple times and slowly wake up.\n"+
  "You force yourself up out of the chair and go back to work.\n");
  say(ME+" gets up from the chair.\n");
  seated = "no_one";
  return 1;
}

play_piano(str){
  if(str == "piano"){
   write(
   "You carefully sit yourself at the piano and admire the magnificent\n"+
   "instrument.  You begin to play, tentativly at first, but the keys\n"+
   "work magic under your fingers and your brilliant music soon fills\n"+
   "the room!\n");
   say(ME+" makes wonderful music at the piano.\n");
   return 1;
   }
}

raise(str){
  int many, minxp;
  int count, cost, total;
  string school, myverb;
  if(rlname != seated){
    write("You must be seated first.\n");
    return 1;
    }
  myverb = query_verb();
  if(sscanf(str, "%s %d", school, many)!=2){
    school = str;
    many = 1;
    }
  if(many > 20){
    write(
    "Yshir says: Sorry, I can only teach you 20 points at a time.\n");
    return 1;
    }
  count = 0; total = 0; cost = 0;
  while(count < many){
  if(school == "conjuration" || school == "conj") 
    total = total + school_costs(guild->query_conjuration() + 1);
  else if(school == "enchantment" || school == "ench") 
    total = total + school_costs(guild->query_enchantment() + 1);
  else if(school == "evocation" || school == "evoc")
    total = total + school_costs(guild->query_evocation() + 1);
  else if(school == "illusion" || school == "illu") 
    total = total + school_costs(guild->query_illusion() + 1);
  else if(school == "necromancy" || school == "necr")
    total = total + school_costs(guild->query_necromancy() + 1);
  else {
    write("Yshir says: I do not understand what you mean.\n");
    count = many + 5;
    }
  if((cost == 69) && (myverb == "raise"))
    count = many + 5;
  count++;
  }
  if(total == 0) return 1;
  if(myverb == "cost"){
    write(
    "Yshir says: You will need "+total+" experience points to raise your "+school+
    " "+many+" points.\n");
    return 1;
    }
  if(cost == 69){
    write(
    "Yshir says: You must advance in rank before I may teach you more.\n");
    return 1;
    }
  minxp = rank_costs(tp->query_guild_rank());
  if(tp->query_guild_exp() - minxp < total){
    write(
    "Yshir says: I'm terribly sorry, but you are not ready to\n"+
    "            advance this skill yet.\n");
    return 1;
    }
  write(
  "Yshir says: I can teach you what you need to know.\n"+
  "Yshir teaches you "+HIC+many+NORM+" points of "+HIC+school+NORM+"\n"+
  "It costs you "+CYN+total+NORM+" guild experience.\n");
  write("\n");
  tp->add_guild_exp(-total);
  if(school == "conjuration" || school == "conj")
    guild->raise_conjuration(many);
  if(school == "enchantment" || school == "ench")
    guild->raise_enchantment(many);
  if(school == "evocation" || school == "evoc")
    guild->raise_evocation(many);
  if(school == "illusion" || school == "illu")
    guild->raise_illusion(many);
  if(school == "necromancy" || school == "necr")
    guild->raise_necromancy(many);
  return 1;
}

north(){
  if(rlname == seated){
    write("You can't do that!\n");
    write("Your still asleep on the chair.\n");
    return 1;
    }
  write(
  "You take a few steps towards the north door and the piano\n"+
  "suddenly plays a few menacing chords.\n"+
  "You think better of the idea and leave the north door alone.\n");
  return 1;
}

east(){
  if(rlname == seated){
    write("You can't do that!\n");
    write("Your still asleep on the chair.\n");
    return 1;
    }
  say(ME+" leaves east.\n");
  move_object(tp, "players/pavlik/guild/mages/rooms/ante_room");
  command("look", tp);
  say(ME+" arrives.\n");
  return 1;
}
