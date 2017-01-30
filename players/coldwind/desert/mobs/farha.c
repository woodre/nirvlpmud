#include "/players/coldwind/ansi.h"
inherit "obj/monster.c";
string person;
int a, b, play, run;
object sword;

reset(arg)  {
  ::reset(arg);
  if(arg) return;
   
set_name("farha");
set_alt_name("woman");
set_alias("magician");
set_race("human");
set_gender("female");
set_short(HIC+"Farha"+NORM+CYN+", the White Magician"+NORM);
set_long(
  "  Farha is a short woman in her late 20's or early 30's. She\n"+
  "is wearing a long green robe and big pack of a matching color.\n"+
  "In the pack, you see flasks and potions as well as a small\n"+
  "book. An emerald aura of kindness surrounds the white magician.\n"+
  "You can ask her about her 'story' if you have time.\n");
 
set_level(14);
set_hp(220);
set_al(1000);
set_ac(9);
set_wc(16);
set_aggressive(0);
set_chat_chance(7);
  load_chat("Farha looks outside through the window.\n");
  load_chat("The wife says: I hope he will be back soon.\n");
 load_chat("The magician asks: Would you like to sell me any weapons?\n");
 load_chat("Farha seems very worried!\n");
}

init(){
  ::init();
    add_action("story","story");
    add_action("offer","offer");
     add_action("ask","ask");
	 add_action("request","request");
	 add_action("sell","sell");
}
sell(str) {
if(!str) {
  write("Farha takes a peek at you.\n"+
        "She then asks, 'What would you like to sell?'\n");
  return 1; }
if(str == "ashgan's crystal ball") {
  write("Farha's face turns pale.\n"+
        "She caughs and says, 'You should destroy this crystal ball.'\n");
  return 1; }
    return (notify_fail("Farha says, 'Currently i'm trying to gather the giants and apes\n"+
	                    "weapons, if you come through one, please bring it to me and i will\n"+
						"reward you.'\n"), 0);

}
ask(str){
if(!str){ write("Ask who about what?\n"); return 1; }
if(str == "farha about story"){
 person = this_player();
  run = 1;
  call_out("talk",3,person);
  return 1; }
 else if(str == "farha about offer"){
person = this_player();
  run = 1;
  call_out("speak",3,person);
  return 1; }
  }

story(){
  person = this_player();
  play = 1;
  call_out("talk",3,person);
  return 1; }
  
offer(){
  person = this_player();
  run = 1;
  call_out("speak",3,person);
  return 1; }

talk(person){
  say_it();
  a += 1;
  if(a<18) call_out("talk",3,person);
  else { 
  play = 0;
  a = 0;
  }
  return 1; }

speak(person){
  yell_it();
  b += 1;
  if(b < 7) call_out("speak",3,person);
  else {
  run = 0;
  b = 0;
  }
  return 1; }

say_it(){
  string stuff;
   switch(a){
     case 0: stuff =  " "; break;
     case 1: stuff = "  Farha gives you a kind smile."; break;
     case 2: stuff = " "; break;
     case 3: stuff = "Farha says: I use to travel from one city to another to learn from the\n"+
	                 "masters of the white magic.  And one day, i passed by a small village\n"+
					 "nearby, while i was in my way to El-Basrah to learn from a great magician\n"+
					 "that lives there.."; break;
     case 4: stuff = " "; break;    
     case 5: stuff = " "; break;
     case 6: stuff = "She smiles then continues: In that village a met a wonderful knight\n"+
	                 "named Fares. I fell in love with him from the first sight."; break;
     case 7: stuff = ""; break;
     case 8: stuff = "Farha chuckles softly and says: The villagers liked me, but they\n"+
	                 "could not accept me among them as a magician."; break;
     case 9: stuff = " "; break;
     case 10: stuff = "The kind woman shakes her head before she says: So when Fares and i\n"+
	                  "got married, he brought me by the well and we build this shrine\n"+
					  "together."; break;
     case 11: stuff = " "; break;
     case 12: stuff = "She sighs: Everything was going well, till few of his friends came\n"+
                      "last night asking for his aid, for the village was under attack, and\n"+                
                      "I haven't seen him since."; break;
     case 13: stuff = "Farha goes into deep thoughts."; break;
     case 14: stuff = " "; break;
     case 15: stuff = "The white magician looks up to you with hope in her eyes and says:\n"+
                      "If you are brave enough to go into the village i have an offer for you"; break;
     case 16: stuff = "Then she continues: 'Ask' me about the 'offer' if you are intrested"; break;
	 case 17: stuff = " "; break; }
    tell_object(person,
    HIW+stuff+NORM+"\n");
    return 1; }

yell_it(){
  string yada;
   switch(b){
     case 0: yada = " "; break;
     case 1: yada = "Farha looks up at you with eyes that gleams with hope.."; break;
     case 2: yada = " "; break;
     case 3: yada = "She offers: If you would find my husband and tell him to "+HIB+"return"+HIW+",\n"+
	                "i shall reward you with a beautiful arbian sword."; break;
     case 4: yada = " "; break; 
     case 5: yada = "The woman explains: The sword will be great aid for you in any battle.\n"+
	                "Just return with my husband and 'request' for your 'reward'. It's that simple!"; break;
     case 6: yada = "  "; break;}
   tell_object(person,
   HIW+yada+NORM+"\n");
   return 1; } 


request(string str){
if(!str){ write("Farha looks puzzled as she asks: What are you requesting?\n"); return 1; }
if(str == "reward"){
 object one,sword;
 
one = present("Proof of Fares's Life", this_object());

sword = clone_object("/players/coldwind/desert/weapons/sword.c");
if (call_other(this_player(), "query_money", 0) < 6000) {
    write("You feel that this sword would be worth a lot and refuse to take it\n"+
	      "without paying the lady 6000 gold coins.\n");
    destruct(sword);
    return 1;
     }
if(!this_player()->add_weight(sword->query_weight())) {
    write("Farha informs you: You are carrying too much on you.\n");
    destruct(sword);
    return 1; }  
if(one){
 this_object()->add_weight(-(one->query_weight()));
 destruct(one);

write("Farha smiles happily as she checks the hide. She thanks you for you help\n"+
      "as she hands you a beautiful Arabian sword. You gauge the sword and feel it's\n"+
	  "worth a lot of gold, so you hand the lady 6000 gold coins and beg her to accept\n"+
	  "it and use it in rebuilding the village. The woman accept the coins and thank you\n"+
	  "again for your bravery and generousty.\n");
this_player()->add_money(-(6000));
move_object(sword, this_player());
write_file("/players/coldwind/log/sword", this_player()->query_name() + " received an Arabian Sword " + ctime()[4..15] + "\n");
return 1;
}


write("Farha asks: Reward for what?\n"+
      "She sighs: I don't even know if he is alive.\n");
return 1;
}
}
