#include "/players/jaraxle/define.h"
inherit "obj/monster.c";

object gold;
int RECAL, IDEN, PURI, RTOME, ITOME, PTOME, r, i, p;
reset(arg)  {
   RTOME = 9;
   ITOME = 15;
    PTOME = 15;
   r = random(11);
   i = random(11);
   p = random(11);
 switch(p){
      case 0: PURI = 5;
      break;
      case 1..2: PURI = 8;
      break;
      case 3..4: PURI = 10;
      break;
      case 5..6: PURI = 13;
      break;
      case 7..8: PURI = 18;
      break;
      case 9..10: PURI = 21;
      break;
   }
   switch(r){
      case 0: RECAL = 5;
      break;
      case 1..2: RECAL = 8;
      break;
      case 3..4: RECAL = 10;
      break;
      case 5..6: RECAL = 13;
      break;
      case 7..8: RECAL = 18;
      break;
      case 9..10: RECAL = 21;
      break;
   }
   switch(i){
      case 0: IDEN = 6;
      break;
      case 1..2: IDEN = 11;
      break;
      case 3..4: IDEN = 13;
      break;
      case 5..6: IDEN = 17;
      break;
      case 7..8: IDEN = 20;
      break;
      case 9..10: IDEN = 24;
      break;
   }
   ::reset(arg);
   if(arg) return;
   
   set_name("cristofer");
   set_alias("cris");
   set_alt_name("scholar");
   set_race("human");
  set_gender("male");
   set_short("Cristofer, the Scholar");
  set_long("Cristofer is a slender man of about six feet in height. He is fairly\n"+
    "thin with long blonde hair that is tied back with a black ribbon.\n"+
    "His deep blue eyes pierce through a pair of thin spectacles which\n"+
    "rest on the tip of his nose. He seems very young to be a man of such\n"+
    "intelligence. Cristofer sells scrolls,  which he has learned from\n"+
    "reading the many books in the library.\n"+
    " \n"+
    "You may "+GRN+"<"+NORM+"ask Cristofer about"+GRN+">"+NORM+" the "+GRN+"<"+NORM+"scrolls"+GRN+">"+NORM+" he has ready to travel\n"+ 
    "for you to "+GRN+"buy"+NORM+". You may also "+GRN+"<"+NORM+"ask Cristofer about"+GRN+">"+NORM+" each scroll type\n"+
    "to see how many he has prepared thus far.\n"+
    " \n"+
    "Cristofer now has learned the skill of writing Tomes. You can  "+GRN+"<"+NORM+"ask\n"+
    "Cristofer about tomes"+GRN+">"+NORM+" and he will tell you what he has available.\n\n");
   set_level(17);
   set_hp(450);
   set_al(1500);
   set_wc(25);
   set_ac(20);
   set_aggressive(0);
   set_chat_chance(4);
   load_chat("Cristofer turns the page of a book he is reading.\n");
   load_chat("Cristofer smiles at you.\n");
   load_chat("Cristofer scribbles something into a parchment.\n");
   load_chat("Cristofer raises his head up and looks around the room.\n");
   load_chat("Cristofer adjusts his spectacles.\n");
   load_chat("Cristofer scratches his head intently.\n");
   MOCO("/players/jaraxle/templar/invite.c"),TO);
   MOCO("/players/boltar/templar/templar.c"),TO);
   gold = clone_object("obj/money");
   gold->set_money(200+random(200));
   move_object(gold,this_object());
}

init() {
   
   ::init();
   
   add_action("help_me","kill");
   add_action("buy_it","buy");
   add_action("ask_me","ask");
   add_action("no_talk","say");
   add_action("no_talk"); add_xverb("'");
   add_action("no_talk","emote says:");
}


help_me(cri){
   if(cri == "cristofer" || cri == "cris" || cri == "scholar" || cri == "human"){
      command("ahelp",TO);
   }
}

no_talk(){
   if(TP->query_level() < 20){
      write("Cristofer whispers, 'Shhh.. please be quiet.'\n");
      return 1; }
}

ask_me(arg){
   if(!present("KnightInvite", this_player()) && this_player()->query_level() < 20){
      tell_object(this_player(),
         "Cristofer says, 'I'm sorry, I will not associate with the likes of you.'\n"); 
      return 1;
   }

   if(arg == "about tomes" || arg == "cristofer about tomes" || arg == "scholar about tomes" || arg == "Cristofer about tomes" || arg == "Cris about tomes" || arg == "cris about tomes"){
write("Cristofer says, 'Tomes can hold multiple pages of scrolls for easy transport.'\n"+
                                 "\t\t'I have the following tomes available : Tome of "+HIY+"Recall"+NORM+",  Tome'\n"+
                                 "\t\t'of "+HIC+"Identify"+NORM+", and Tome of "+HIB+"Purification"+NORM+".  Each tome comes with'\n"+
                                 "\t\t'one spell placed within its pages.  The Tome of "+HIY+"Recall"+NORM+" will'\n"+
 "\t\t'cost "+HIB+"100sp"+NORM+" and "+HIY+"100 coins"+NORM+".  The Tome of "+HIC+"Identify"+NORM+" will cost'\n"+
                                 "\t\t'"+HIY+"200 coins"+NORM+", Tome of "+HIB+"Purification"+NORM+" will cost "+HIY+"1750 coins"+NORM+".'\n"+
                                 "\t\t'You may "+HIG+"<"+HIW+"buy identify_tome"+HIG+">"+NORM+", "+HIG+"<"+HIW+"recall_tome"+HIG+">"+NORM+", or "+HIG+"<"+HIW+"purification_tome"+HIG+">"+NORM+".'\n");
 write("\nCristofer continues, 'I have "+HIG+"("+HIW+RTOME+HIG+")"+NORM+" Tome of "+HIY+"Recall"+NORM+","+HIG+"("+HIW+ITOME+HIG+")"+NORM+" Tome of "+HIC+"Identify"+NORM+", and\n\t\t "+HIG+"("+HIW+PTOME+HIG+")"+NORM+" Tome of "+HIB+"Purification"+NORM+" available.'\n\n");
  return 1; }
   if(arg == "about scrolls" || arg == "cristofer about scrolls" || arg == "scholar about scrolls" || arg == "Cristofer about scrolls" || arg == "Cris about scrolls" || arg == "cris about scrolls"){
      write("\nCristofer says, 'I have "+HIC+"Scrolls of Identify"+NORM+", "+HIY+"Recall"+NORM+", and "+HIB+"Purification"+NORM+" available.'\n"+
                             "\t\t'"+HIC+"Scrolls of Identify"+NORM+" will give you information on'\n"+
                              "		'any item.  "+HIY+"Scrolls of Recall"+NORM+" will bring you back'\n"+
                              "		'to the library from anywhere on the mud which'\n"+
                            "\t\t'is not locked by "+HIM+"magic"+NORM+".'\n"+
                            "\t\t'"+HIB+"Scrolls of Purification"+NORM+" will cleanse your body of poisons.'\n");
      return 1; }

   if(arg == "about identify" || arg == "cristofer about scroll of identify" || arg == "cristofer about identify" || arg == "scholar about identify" || arg == "scholar about scroll of identify" || arg == "cris about identify" || arg == "cris about scroll of identify"){
       write("Cristofer says, 'I have "+HIW+"("+HIC+""+IDEN+""+HIW+")"+HIC+" Scroll of Identify"+NORM+" and "+HIW+"("+HIC+""+ITOME+""+HIW+") Tome of"+HIC+" Identify"+NORM+" written at this time.'\n"); 
      return 1; }

   if(arg == "about recall" || arg == "cristofer about scroll of recall" || arg == "cristofer about recall" || arg == "scholar about recall" || arg == "scholar about scroll of recall" || arg == "cris about recall" || arg == "cris about scroll of recall"){
      write("Cristofer says, 'I have "+HIW+"("+HIY+""+RECAL+""+HIW+") "+HIY+"Scroll of Recall"+NORM+" and "+HIW+"("+HIY+""+RTOME+""+HIW+") Tome "+HIY+"of Recall"+NORM+" written at this time.'\n");
      return 1; }

 if(arg == "about purification" || arg == "cristofer about scroll of purification" || arg == "cristofer about purify" || arg == "scholar about purification" || arg == "scholar about scroll of purification" || arg == "cris about purification" || arg == "cris about scroll of purification"){
      write("Cristofer says, 'I have "+HIW+"("+HIB+""+PURI+""+HIW+") "+NORM+"Scroll of "+HIB+"Purification"+NORM+" and "+HIW+"("+HIB+""+PTOME+""+HIW+") Tome of "+HIB+"Purification"+NORM+" written at this time.'\n");
return 1; }
   write("You may "+HIG+"<"+HIW+"ask Cristofer about"+HIG+"> "+HIB+"["+HIY+"recall"+HIB+"]"+NORM+", "+HIB+"["+HIC+"identify"+HIB+"]"+NORM+", "+HIB+"["+HIW+"tomes"+HIB+"]"+NORM+", and "+HIB+"["+HIW+"scrolls"+HIB+"]"+NORM+"\n");
   return 1; }

buy_it(arg) {
   if(!present("KnightInvite", this_player()) && this_player()->query_level() < 20){
      tell_object(this_player(),
         "Cristofer says, 'I'm sorry, I will not associate with the likes of you.'\n"); 
      return 1;
   }
   
   if(!TP->add_weight(1)){ write("Cristofer says, 'You cannot carry this!'\n"); return 1; }
   if(arg == "identify" || arg == "scroll of identify"){
      if(IDEN <= 0){ write("Cristofer says, 'I'm sorry I am out of "+HIC+"Scroll of Identify"+NORM+".'\n"); return 1; }
      if(TP->query_money() < 100){ write("Cristofer says, 'You do not have enough coins to purchase this scroll.'\n"); return 1; }
      TP->add_money(-100);
      write("Cristofer hands you a Scroll of Identify.\n");
      say(TPN+" buys a scroll from Cristofer.\n");
      MOCO("/players/jaraxle/templar/items/identify.c"),TP);
      IDEN -= 1;
      return 1; }
   
 if(arg == "purification" || arg == "scroll of purification"){
      if(IDEN <= 0){ write("Cristofer says, 'I'm sorry I am out of "+HIB+"Scroll of Purification"+NORM+".'\n"); return 1; }
      if(TP->query_money() < 1500){ write("Cristofer says, 'You do not have enough coins to purchase this scroll.'\n"); return 1; }
      TP->add_money(-1500);
      write("Cristofer hands you a Scroll of Purification.\n");
      say(TPN+" buys a scroll from Cristofer.\n");
      MOCO("/players/jaraxle/templar/items/purify.c"),TP);
      PURI -= 1;
      return 1; }
   
if(arg == "purification_tome"){
    if(ITOME <= 0){ write("Cristofer says, 'I'm sorry I am out of Tome of "+HIB+"Purification"+NORM+".'\n"); return 1; }
     if(TP->query_money() < 1750){ write("Cristofer says, 'You do not have enough coins to purchase this tome.'\n"); return 1; }
      TP->add_money(-1750);
    write("Cristofer hands you a Tome of "+HIB+"Purification"+NORM+".\n");
      PTOME -=1;
    write("Cristofer tells you: I now have "+PTOME+" left.\n");
    say(TPN+" buys a Tome from Cristofer.\n");
     MOCO("/players/jaraxle/templar/items/p_tome.c"),TP);
return 1; }

if(arg == "identify_tome"){
    if(ITOME <= 0){ write("Cristofer says, 'I'm sorry I am out of Tome of "+HIC+"Identify"+NORM+".'\n"); return 1; }
     if(TP->query_money() < 200){ write("Cristofer says, 'You do not have enough coins to purchase this tome.'\n"); return 1; }
      TP->add_money(-200);
    write("Cristofer hands you a Tome of "+HIC+"Identify"+NORM+".\n");
      ITOME -=1;
    write("Cristofer tells you: I now have "+ITOME+" left.\n");
    say(TPN+" buys a Tome from Cristofer.\n");
     MOCO("/players/jaraxle/templar/items/i_tome.c"),TP);
return 1; }

if(arg == "recall_tome"){
if(RTOME <= 0){ write("Cristofer says, 'I'm sorry I am out of Tome of "+HIY+"Recall"+NORM+".'\n"); return 1; }
     if(TP->query_money() < 100){ write("Cristofer says, 'You do not have enough "+HIY+"coins"+NORM+" to purchase this tome.'\n"); return 1; }
     if(TP->query_sp() < 100){ write("Cristofer says, 'You do not have enough "+HIB+"mana"+NORM+" to purchase this tome.'\n"); return 1; }
      TP->add_money(-100);
      TP->add_spell_point(-100);
    command("mon",TP);
    write("Cristofer hands you a Tome of "+HIY+"Recall"+NORM+".\n");
RTOME -=1;
    write("Cristofer tells you: I now have "+RTOME+" Tome available.\n");
    say(TPN+" buys a Tome from Cristofer.\n");
     MOCO("/players/jaraxle/templar/items/r_tome.c"),TP);
return 1; }

   if(arg == "scroll of recall" || arg == "recall"){
      if(this_player()->query_sp() < 100){
         write("Cristofer says, 'You do not have the spell points to pay for this scroll.'\n");
         return 1; }
    if(RECAL <= 0){ write("Cristofer says, 'I'm sorry I am out of "+HIY+"Scroll of Recall"+NORM+".'\n"); return 1; }
      write("Cristofer carefully places the scroll in your hand.\n"+
         "... as the scroll passes it "+HIB+"glows a bright blue"+NORM+", exchanging\n"+
         "    your energy into the scroll.\n");
      say(TPN+" buys a scroll from Cristofer.\n");
     MOCO("/players/jaraxle/templar/items/recall.c"),TP);
      this_player()->add_spell_point(-100);
RECAL -= 1;
      return 1;
   }   
   write("Cristofer asks, 'Buy what?'\n");
   return 1; }
