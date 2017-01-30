#include "/players/jaraxle/define.h"
inherit "obj/monster.c";

reset(arg)  {
   object gold;
   ::reset(arg);
   if(arg) return;
   
   set_name("Carin");
   set_alias("carin");
   set_alt_name("maiden");
   set_race("human");
   set_short("Carin");
   set_long(
      "Carin is a young human girl of about sixteen.  Her hair is\n"+
      "a dirty blonde color and is tied back into pigtails.  She\n"+
      "is in charge of the fruits sold here, and can answer any\n"+
      "of your questions if you inquire about the fruit.\n");
   
   set_level(18);
   set_hp(500);
   set_al(0);
   set_wc(30);
   set_ac(45);
   set_aggressive(0);
   
   set_chat_chance(4);
   load_chat("Carin shifts some items behind the shelves.\n");
    load_chat("Carin dusts off the "+HIW+"sign"+NORM+".\n");
    load_chat("Carin dusts off the "+HIW+"sign"+NORM+".\n");
    load_chat("Carin dusts off the "+HIW+"sign"+NORM+".\n");
   
 set_chance(15);
   set_spell_dam(30+random(36));
   
   set_spell_mess1(
"\n\nCarin rakes your eyes with her sharp nails.\n");
   set_spell_mess2(
"\n\nCarin rakes your eyes with her sharp nails.\n");
   gold = clone_object("obj/money");
   gold->set_money(200+random(200));
   move_object(gold,this_object());
}

init() {
   ::init();
   add_action("buy_it","buy");
   add_action("ask_it","inquire");
}

buy_it(arg) {
   if(TP->query_money() < 400){
      write("Carin says: You do not have enough for that, I'm sorry.\n");
      return 1; }

   if(!TP->add_weight(1)){ write("Carin tells you: You cant carry this!\n"); return 1; }

   if(arg == "caocao" || arg == "caocao fruit"){
      TP->add_money(-400);
    tell_object(TP, "You buy a CaoCao fruit from Carin.\n");
     MOCO("/players/jaraxle/3rd/warrior/heals/caocao.c"),TP);
    tell_room(environment(TP), TPN+" buys fruit from Carin.\n");
      return 1; }

   if(arg == "teenom" || arg == "teenom fruit"){
      TP->add_money(-400);
      write("You buy a Teenom fruit from Carin.\n");
      MOCO("/players/jaraxle/3rd/warrior/heals/teenom.c"),TP);
      say(TPN+" buys fruit from Carin.\n");
      return 1; }

   if(arg == "amplee" || arg == "amplee fruit"){
     if(TP->query_money() < 2700){ write("Carin says: You do not have enough for that, I'm sorry.\n"); return 1; }
      TP->add_money(-2700); 
      write("You buy an "+BLK+BOLD+"Amp"+NORM+BOLD+"lee"+NORM+" fruit from Carin.\n");
      MOCO("/players/jaraxle/closed/heals/amplee.c"),TP);
      say(TPN+" buys fruit from Carin.\n");
      return 1; }

   if(arg == "ahqwa" || arg == "ahqwa fruit"){
     if(TP->query_money() < 1800){ write("Carin says: You do not have enough for that, I'm sorry.\n"); return 1; }

      TP->add_money(-1800); 
      write("You buy an "+HIB+"Ah"+HIC+"qwa"+NORM+" fruit from Carin.\n");
      MOCO("/players/jaraxle/closed/heals/ahqwa.c"),TP);
      say(TPN+" buys fruit from Carin.\n");
      return 1; }

   if(arg == "junju" || arg == "junju fruit"){
     if(TP->query_money() < 1800){ write("Carin says: You do not have enough for that, I'm sorry.\n"); return 1; }
      TP->add_money(-1800); 
      write("You buy "+HIG+"Jun"+HIY+"ju"+NORM+" fruit from Carin.\n");
      MOCO("/players/jaraxle/closed/heals/junju.c"),TP);
      say(TPN+" buys fruit from Carin.\n");
      return 1; }

   if(arg == "roht" || arg == "roht fruit"){
     if(TP->query_money() < 1200){ write("Carin says: You do not have enough"+
" for that, I'm sorry.\n"); return 1; }
      TP->add_money(-1200); 
write("You buy a "+RED+"Ro"+BOLD+BLK+"h"+NORM+RED+"t"+NORM+" fruit from Carin.\n");
      MOCO("/players/jaraxle/closed/heals/roht.c"),TP);
      say(TPN+" buys fruit from Carin.\n");
      return 1; }

   if(arg == "kool" || arg == "kool fruit"){
     if(TP->query_money() < 1800){ write("Carin says: You do not have enough"+
" for that, I'm sorry.\n"); return 1; }
      TP->add_money(-1800); 
write("You buy a "+HIR+"K"+HIW+"oo"+HIR+"l"+NORM+" fruit from Carin.\n");
      MOCO("/players/jaraxle/closed/heals/kool.c"),TP);
      say(TPN+" buys fruit from Carin.\n");
      return 1; }

   if(arg == "lychee" || arg == "lychee fruit"){
     if(TP->query_money() < 1800){ write("Carin says: You do not have enough"+
" for that, I'm sorry.\n"); return 1; }
      TP->add_money(-1800); 
write("You buy a "+HIC+"Ly"+BLK+BOLD+"ch"+HIC+"ee"+NORM+" fruit from Carin.\n");
      MOCO("/players/jaraxle/closed/heals/lychee.c"),TP);
      say(TPN+" buys fruit from Carin.\n");
      return 1; }
   write("Carin says: I do not have that.\n"); return 1; }

ask_it(arg){

if(arg == "caocao"){
write("Carin says,\n"+
      "Caocao fruit is normally used by smaller players.  There\n"+
      "is only enough of this fruit for 2 bites but it is very\n"+
      "affordable and for small players, easy on the food tox.\n");
return 1; }

if(arg == "teenom"){
write("Carin says,\n"+
      "Teenom fruit is normally used by smaller players.  There\n"+
      "is only enough of this fruit for 2 bites but it is very\n"+
      "affordable and for small players, easy on the soak tox.\n");
return 1; }

if(arg == "roht"){
write("Carin says,\n"+
      "Roht fruit is typcally used by players who are having a\n"+
      "difficult time with funds.  The fruit is almost rotten,\n"+
      "but still sweet and ok to eat.  The cost is reduced for\n"+
      "quick sale but since it is almost rotten it fills your\n"+
      "soak and stuff tox fairly quickly.\n");
return 1; }

if(arg == "kool"){
write("Carin says,\n"+
      "Kool fruit is a special fruit that has healing properties\n"+
      "specifically for mana.  The fruit has been artifically\n"+
      "grown to give more than the 'normal' amount of healing but\n"+
      "a little more toxing on your soak.\n");
return 1; }

if(arg == "lychee"){
write("Carin says,\n"+
      "Lychee fruit is a special fruit that has healing properties\n"+
      "specifically for health.  The fruit has been artifically\n"+
      "grown to give more than the 'normal' amount of healing but\n"+
      "a little more toxing on your food.\n");
return 1; }

if(arg == "junju"){
write("Carin says,\n"+
      "Junju fruit has been grown by the Warrior Maidens for ages.\n"+
      "The low toxing properties to your soak and food make it very\n"+
      "desireable for warriors who need health only healing at a\n"+
      "good price with a low tox.\n");
return 1; }

if(arg == "ahqwa"){
write("Carin says,\n"+
      "Ahqwa fruit has been grown by the Warrior Maidens for ages.\n"+
      "The low toxing properties to your soak and food make it very\n"+
      "desireable for warriors who need mana only healing at a\n"+
      "good price with a low tox.\n");
return 1; }

if(arg == "amplee"){
write("Carin says,\n"+
      "Amplee is a hydropnically, alchemist altered fruit grown in.\n"+
      "the basement of the Warrior Maiden's most protected Magi.\n"+
      "This fruit is the most prized of the clan, consisting of an\n"+
      "extremely low tox to your soak and food and a decent heal to\n"+
      "both healing and mana.\n");
return 1; }
write("Carin says: I can only give you information about the fruit on the sign.\n");
return 1; }