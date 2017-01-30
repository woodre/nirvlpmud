#include "/players/coldwind/define.h"
inherit "obj/monster.c";
string person;
int a, b, c, play, run, fire;
reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;
   
set_name("fares");
set_alt_name("knight");
set_alias("arabian");
set_gender("male");
set_race("human");
set_short("A wounded knight ("+HIR+"Bleeding"+NORM+")");
set_long(
"  Fares appears to have some serious wounds on his chest and\n"+
"arms. He is dressed in one piece of white cloth that has been\n"+
"slashed and bloodstained. With sadness, Fares looks up to you\n"+
"and you feel he wants to tell you something. Ask him about his\n"+
"'story' if you got time.\n");
 
set_level(15);
set_hp(300);
set_al(1000);
set_ac(13);
set_wc(22);
set_aggressive(0);
set_chat_chance(7);
  load_chat("Fares looks outside the cave carefully to check the way out.\n");
  load_chat("Fares says: Shhh...I think Ashgan and the giants are up there.\n");
  load_chat("The knight whispers: if i can sneak up, maybe i can surprise Ashgan and kill her.\n");
 load_chat("The knight says: This evil must end!\n");
 load_chat("Fares asks: Are you here to help us?\n");

gold = clone_object("obj/money");
gold->set_money(1400 + random (150));
move_object(gold,this_object());
}
init(){
  ::init();
    add_action("sreward","return");
    add_action("sstory","story");
   add_action("evil_gone","inquire");
   add_action("ask","ask");
   add_action("yes_tell","tell");
}
yes_tell(string str){
if(str == "fares return"){
person = this_player();
  play = 1;
  call_out("talk",3,person);
  return 1; }
  }
ask(string str){
if(!str){ write("Ask who about what?\n"); return 1; }
if(str == "fares about story"){
 person = this_player();
  run = 1;
  call_out("speak",3,person);
  return 1; }
  }
sreward(){
  person = this_player();
  play = 1;
  call_out("talk",3,person);
  return 1; }
  
sstory(){
  person = this_player();
  run = 1;
  call_out("speak",3,person);
  return 1; }
  
  
  zhide(){
person = this_player();
  fire = 1;
  call_out("sniff",3,person);
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
  if(b < 20) call_out("speak",3,person);
  else {
  run = 0;
  b = 0;
  }
  return 1; }
  
  sniff(person){
  do_it();
  c += 1;
  if(c < 13) call_out("sniff",3,person);
  else {
  fire = 0;
  c = 0;
  }
  return 1; }

say_it(){
  string stuff;
   switch(a){
     case 0: stuff = " "; break;
     case 1: stuff = "Fares eyes you thinkfully for a moment..."; break;
     case 2: stuff = " "; break;
     case 3: stuff = "He sighs and sits down on the floor."; break;
     case 4: stuff = " "; break;    
     case 5: stuff = "Fares says: So you met my wife..."; break;
     case 6: stuff = " "; break;
     case 7: stuff = "The knight explains: Sorry, I can't go back. The villagers need my\n"+
	                 "help and i can't let them down even if my life was the price."; break;
     case 8: stuff = " "; break;
     case 9: stuff = "He thinks for a second before he continues: But if you are intrested\n"+
	                 "in the sword or what's best for the village, help me."; break;
     case 10: stuff = "Fares takes a deep breath."; break;
     case 11: stuff = " "; break;
     case 12: stuff = "Then he offers: I have a deal for you. If you can capture all the\n"+
	                  "evil souls as well as the crystal ball come to me. I will destroy \n"+
					  "them myself, and send you to my wife with a 'proof' once you 'inquire' it.\n"+
					  "That will calm her worries and the sword shall be yours."; break;
     case 13: stuff = " "; break;
     case 14: stuff = "He adds: Also if you come up through any of the apes or giants weapons,\n"+
	                  "you can sell those to my wife, Farha. We are always in need of weapons."; break;
     case 15: stuff = ""; break;
     case 16: stuff = "Fares looks up at you.."; break;
     case 17: stuff = "Then he says: I wish you the best of luck if you accept my offer! "; break; }
    tell_object(person,
    HIW+stuff+NORM+"\n");
    return 1; }

yell_it(){
  string yada;
   switch(b){
     case 0: yada = " "; break;
     case 1: yada = "The wounded knights thinks for a second before he sighs."; break;
     case 2: yada = " "; break;
     case 3: yada = "He eyes you thinkfully."; break;
     case 4: yada = " "; break; 
     case 5: yada = "Then he says: A year ago, Some of our arabian merchants went across the \n"+
	                "sea selling and buying, but as they return, they brought destruction to \n"+
					"the land... "; break;
     case 6: yada = " "; break;
     case 7: yada = "Fares continues: One of the merchants brought a small crystal ball to \n"+
	                "our village. We knew from the first sunrise that it was magical, but we \n"+
					"couldn't get rid of it. The ball floated around and spied on the \n"+ 
					"villagers."; break;
     case 8: yada = " "; break;
     case 9: yada = "The arabian stops and goes into deep thoughts"; break;
	 case 10: yada = " "; break;
     case 11: yada = "He shakes his head and continues: Few monthes after, A dark magician \n"+	
	                 "arrived to the lands coming from across the sea. The crystal ball obeyed \n"+	
					 "her, and together they were a great power, yet we managed to run her \n"+	
					 "away..."; break;
     case 12: yada = " "; break;
     case 13: yada = "Fares smirks and says: We thought she will never be back, and so she let\n"+	
	                 "us believe. After two seasons, the magician striked again, but this time \n"+	
					 "she came with armed apes and giants. They slaughtered our knights and\n"+	
					 "villagers and burned the tents. Within hours the war was over..."; break;
     case 14: yada = " "; break;
     case 15: yada = "The knight takes a deep breath and tries to control his feelings."; break;
	 case 16: yada = " "; break;
     case 17: yada = "He persists: And now, the villagers wander the desert searching for food. \n"+
	                 "Everytime we try to gather and start to fix the village, the giants \n"+
					 "strike.."; break;

     case 18: yada = "Fares offers: If you can help me detroy the evil, we should be able\n"+ 
	                 "to build the village again."; break; 
     case 19: yada = ""; break;  }
   tell_object(person,
   HIW+yada+NORM+"\n");
   return 1; } 
   
   
   do_it(){
  string things;
   switch(c){  
      case 0: things = "Fares hands you the hide thankfully and says: I hope this will work.."; break;
     case 1: things = " "; break;
     case 2: things = "The knight drops the souls on the floor at his feet and holds the\n"+
	  "crystal ball above his head."; break; 
	 case 3: things = "With all the strength left in him, Fares slams the ball into the ground,\n"+
	                 "shattering it into little pieces."; break;
   case 4: things = " "; break;
	case 5: things = "A moment of silence passes by slowly."; break;
	case 6: things = " "; break;
	case 7: things = " "; break;
	case 8: things = ""+NORM+BLU+"Thunder rumbles and lightning runs through the sky outside the cave."; break;
	case 9: things = " "; break;	
	case 10: things = "Suddenly, the souls bursts into flames, leaving no ashes as they\n"+
	                  "burn quietly."; break; 
	case 11: things = " "; break;
	case 12: things = "Fares smiles happliy and says: Thanks for you help, my friend. \n"+
	                  "Please give this hide to my wife, and don't forget to 'request' \n"+
					  "your 'reward' from her."; break;		}
	  tell_object(person,
    things+NORM+"\n");
	    return 1; }
		
		
evil_gone(string str){
if(str == "proof"){
 object one, two, three, four, five, six, seven,proof;
 
one = present("giant_soul_1", this_object());
two = present("giant_soul_2", this_object());
three = present("giant_soul_3", this_object());
four = present("giant_soul_4", this_object());
five = present("giant_soul_5", this_object());
six = present("giant_soul_6", this_object());
seven = present("ashgan's crystal ball", this_object());
proof = clone_object("/players/coldwind/desert/items/hide.c");

if(!this_player()->add_weight(proof->query_weight())) {
    write("Fares informs you: But you can't carry the hide...\n");
    destruct(proof);
    return 1; }  
if(one && two && three && four && five && six && seven){
 this_object()->add_weight(-(one->query_weight()));
 this_object()->add_weight(-(two->query_weight()));
 this_object()->add_weight(-(three->query_weight()));
 this_object()->add_weight(-(four->query_weight()));
 this_object()->add_weight(-(five->query_weight()));
 this_object()->add_weight(-(six->query_weight()));
 this_object()->add_weight(-(seven->query_weight()));
 destruct(one);
 destruct(two);
 destruct(three); 
 destruct(four);
 destruct(five);
 destruct(six); 
 destruct(seven);
 zhide(); 
move_object(clone_object("/players/coldwind/desert/items/hide.c"), this_player());
write_file("/players/coldwind/log/sword", this_player()->query_name() + " received a hide " + ctime()[4..15] + "\n");
return 1;
}
write("The knight looks at you.\n"+
      "Fares says: I will give you the proof when you give the crystall ball\n"+
     "and all the evilsouls. I always keep my word.\n");
return 1;
}
if(!str){ write("Inquire what?\n"); return 1; }
}
