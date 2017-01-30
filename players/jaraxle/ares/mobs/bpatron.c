#include "/players/jaraxle/ansi.h"

inherit "obj/monster.c";



int coins;

object gold;



string pgender;

int phght_ft,phght_in;

int pwght;

string paction,pchar,phair,peyes;



int vname;

string *var1;

string *var2;

string *var3;

string *var4;

string one,two,three;



reset(arg)  {

  ::reset(arg);

  if(arg) return;



var1 = ({ "silver", "gold", "skull", "crown", "jewel", "death", "red", "black",

          "green", "lord", "gem", "dark", "ring", "mage", "light", "sword", 

          "mace", "shield", "ram", "wolf", "gray", "war", "land" });

var2 = ({ "aern", "gal", "fer", "bel", "mel", "bal", "xal", "xaj", "zan",

          "zar", "zhul", "yor", "nar", "gon", "trel", "grul", "pret", "ban",

          "tor", "tan", "ten", "tul", "gol", "ghul", "dar", "dran", "drak",

          "dral", "del", "drel", "dul", "drul", "dhul", "dhol", "eral",

          "elan", "hrul", "han", "hol", "hop", "jus", "kil", "khaz", "khur",

          "zen" });

var3 = ({ "ton", "rak", "rik", "thas", "thor", "gor", "dros", "heim", "dor",

          "doria", "kith", "kin", "ing", "gon", "tor", "torin", "berg", 

          "ville", "side", "shand", "lay", "thas", "dalf", "drak", "nakh",

          "rol", "gnol", "myr", "lock", "loch", "moon", "gate", "leaf",

          "bow", "ice", "rim", "tooth" });

var4 = ({ "an", "a", "or", "o", "in", "il", "al", "ak", "ab", "ord", "arn",

          "urn", "ik" });

vname = random(100);

if(vname < 10){ one = var1[random(sizeof(var1))]; two = var3[random(sizeof(var3))]; }

else if(vname < 45){

  one = var2[random(sizeof(var2))]; two = var3[random(sizeof(var3))]; }

else if(vname < 65){ 

  one = var2[random(sizeof(var2))]; two = var4[random(sizeof(var4))]; }

else{

  one = var2[random(sizeof(var2))]; two = var4[random(sizeof(var4))];

  three = var3[random(sizeof(var3))]; }

if(one && two){  set_name(one+two); }

else if(one && two && three){ set_name(one+two+three); }

get_stats();



set_alt_name("patron");

set_aggressive(0);

set_heart_beat(1);





if(coins){  

gold = clone_object("obj/money");

gold->set_money(level * 43);

move_object(gold,this_object());

  }

}	



get_stats(){



if(random(100) < 20){ set_gender("female"); pgender = "she"; }

  else{ set_gender("male"); pgender = "he"; }

if(pgender == "he"){  

switch(random(100) + 1){

  case 50..1000: 

     set_race("human"); 

     phght_ft = 5 + random(2); 

     phght_in = random(12); 

     pwght = phght_ft * 30 + (phght_in * 6);

     break; 

  case 40..49: 

     set_race("dwarf"); 

     phght_ft = 4; 

     phght_in = random(7); 

     pwght = 160 + (phght_in * 10);

     break;

  case 20..39: 

     set_race("elf"); 

     phght_ft = 4 + random(2); 

     phght_in = 6 + random(3); 

     pwght = phght_ft * 20 + (phght_in * 6);

     break;

  case 10..19: 

     set_race("gnome"); 

     phght_ft = 3; 

     phght_in = random(7); 

     pwght = 40 + (phght_in * 2);

     break;

  case 1..9: 

     set_race("halfling"); 

     phght_ft = 3; 

     phght_in = random(5); 

     pwght = 30 + (phght_in * 3);

     break;

     }

  }

else{  

switch(random(100) + 1){

  case 50..1000: 

     set_race("human"); 

     phght_ft = 5; 

     phght_in = random(12); 

     pwght = phght_ft * 20 + (phght_in * 5);

     break; 

  case 40..49: 

     set_race("dwarf"); 

     phght_ft = 4; 

     phght_in = random(7); 

     pwght = 160 + (phght_in * 10);

     break;

  case 20..39: 

     set_race("elf"); 

     phght_ft = 4 + random(2); 

     phght_in = 6 + random(3); 

     pwght = phght_ft * 18 + (phght_in * 5);

     break;

  case 10..19: 

     set_race("gnome"); 

     phght_ft = 3; 

     phght_in = random(7); 

     pwght = 40 + (phght_in);

     break;

  case 1..9: 

     set_race("halfling"); 

     phght_ft = 3; 

     phght_in = random(5); 

     pwght = 30 + (phght_in * 2);

     break;

     }

   }

  switch(random(100) + 1){

   case 50..1000: set_al(-(random(1000))); break;

   case 10..49: set_al(0); break; 

   case 1..9: set_al(random(1000)); break;

   }

  switch(random(100) + 1){

   case 95..1000: paction = "passed out"; break;

   case 60..94: paction = "standing"; break;

   case 1..59: paction = "sitting"; break;

   }

  switch(random(100) + 1){

   case 98..100: pchar = "shady"; break;

   case 90..97: 

     if(pgender == "he") pchar = "handsome"; 

     else pchar = "pretty";

     break;

   case 70..89:

     pchar = "ugly";

     break;

   case 50..69:

     pchar = "rough";

     break; 

   case 40..49:

     pchar = "weary";

     break;

   case 30..39:

     pchar = "regular";

     break;

   case 20..29:

     pchar = "dirty";

     break;

   case 1..19:

     pchar = "normal";

     break;

     }

 switch(random(100) + 1){

   case 50..1000: phair = "brown"; break;

   case 30..49: phair = "black"; break;

   case 10..29: phair = "blonde"; break;

   case 1..9:   phair = "red"; break;

   }

switch(random(100) + 1){

   case 50..1000: peyes = "brown"; break;

   case 30..49: peyes = "grey"; break;

   case 20..29: peyes = "blue"; break;

   case 1..19: peyes = "green"; break;

   }

if(query_race() == "elf" && random(100) < 80){ peyes = "blue"; phair = "blonde"; }   



set_level(random(6) + 5);

set_hp(level * 15);

set_wc(4 + level);

set_ac(level - 1);

}



short(){ return capitalize(query_name())+" ("+BOLD+"Patron"+NORM+") ["+paction+"]"; } 



long(){

  write(

"This is a patron of the Dangerous Blade. "+capitalize(pgender)+" is a "+pchar+" looking\n"+

query_race()+" with "+phair+" hair and "+peyes+" eyes. "+capitalize(pgender)+""+

" is "+phght_ft+" feet "+phght_in+""+

" inches in\n"+

"height and weighs around "+pwght+" pounds. "+capitalize(query_name())+" is currently"+

" "+paction+".\n");  

return 1;

}



heart_beat(){

  ::heart_beat();



if(paction == "passed out" || paction == "sitting"){

 if(attacker_ob){

  paction = "standing";

  tell_room(environment(), query_name()+" jumps up and leaps into the fight!\n");

  }

 }

}

	   	      	     	   