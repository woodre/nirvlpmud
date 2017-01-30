#include "/players/maledicta/ansi.h"

string composition;
int value1,value2,value3;
string craft;
string extra;
string mtype;
int worn;

reset(arg){
get_type();
get_craftworth();
get_composition();
get_extra();
}

get_craftworth(){
switch(random(20) + 1){
case 20..1000:
craft = "beautifully";
value2 = random(251) + 250;
break;
case 18..19:
craft = "masterfully";
value2 = random(201) + 200;
break;
case 15..17:
craft = "expertly";
value2 = random(151) + 150;
break;
case 11..14:
craft = "excellently";
value2 = random(81) + 80;
break;
case 5..10:
craft = "decently";
value2 = random(51) + 50;
break;
case 1..4:
craft = "poorly";
value2 = random(21) + 20;
break;
default:
craft = "poorly";
value2 = 1;
break;
}
}


get_composition(){
switch(random(20) + 1){
case 20:
composition = "gold";
value1 = random(51) + 50;
break;
case 18..19:
composition = "silver";
value1 = random(21) + 10;
break;
case 17:
composition = "platinum";
value1 = random(101) + 100;
break;
case 16:
composition = "emerald";
value1 = random(101) + 100;
break;
case 15:
composition = "diamond";
value1 = random(301) + 200;
break;
case 14:
composition = "sapphire";
value1 = random(151) + 80;
break;
case 13:
composition = "ruby";
value1 = random(101) + 100;
break;
case 12:
composition = "crystal";
value1 = random(31) + 20;
break;
case 10..11:
composition = "iron";
value1 = random(30);
break;
case 8..9:
composition = "ivory";
value1 = random(81) + 50;
break;
case 7:
composition = "onyx";
value1 = random(61) + 40;
break;
case 6:
composition = "topaz";
value1 = random(81) + 40;
break;
case 4..5:
composition = "copper";
value1 = random(25);
break;
case 3:
composition = "mithril";
value1 = random(501) + 500;
break;
case 2:
composition = "adamantium";
value1 = 1000;
break;
case 1:
composition = "bone";
value1 = random(11);
break;
default:
composition = "gold";
value1 = random(100);
break;
}
}


get_type(){
switch(random(20) + 1){
case 18..1000:
mtype = "ring";
break;
case 15..17:
mtype = "amulet";
break;
case 14:
mtype = "brooch";
break;
case 13:
mtype = "pendant";
break;
case 10..12:
mtype = "bracelet";
break;
case 8..9:
mtype = "necklace";
break;
case 7:
mtype = "earring";
break;
case 6:
mtype = "charm";
break;
case 3..5:
mtype = "armband";
break;
case 2: 
mtype = "headcrest";
break;
case 1:
mtype = "bracelet";
break;
default:
mtype = "ring";
break;
 }
}

get(){ return 1; }
drop(){ return 1; }

get_extra(){
if(random(100) > 30){
extra = 0;
return;
}
switch(random(10) + 1){
case 10..1000:
extra = "It has numerous runes etched into its surface.";
break;
case 9:
extra = "It has gold intertwined around it.\n";
break;
case 8:
extra = "It radiates a very dim light.\n";
break;
case 7:
extra = "It hums with a slight energy.\n";
break;
case 6:
extra = "It is outlined with a bright silver.\n";
break;
case 5:
extra = "It has a large sigil inscribed upon it.\n";
break;
case 4:
extra = "It glitters with a greenish light.\n";
break;
case 3:
extra = "It has a slight crack near its edge.\n";
break;
case 2:
extra = "It is slightly heavy.\n";
break;
case 1:
extra = "It is very lightweight.\n";
break;
default:
extra = "It is very light.\n";
break;
}
}

id(str){ return str == mtype; }

short() { 
if(this_player()->query_level() > 19 && worn){
  return capitalize(composition)+" "+capitalize(mtype)+" (worn) <DECORATION!> V:"+query_value()+"";
}
if(this_player()->query_level() > 19){
  return capitalize(composition)+" "+capitalize(mtype)+" <DECORATION!> V:"+query_value()+"";
}
if(worn){
  return capitalize(composition)+" "+capitalize(mtype)+" (worn)";
  }
  return capitalize(composition)+" "+capitalize(mtype)+"";
}  

long(){
write( 
short()+"\nThis is a "+craft+" crafted "+composition+" "+mtype+".\n");
if(extra){
write(extra);
}
write(
"The "+mtype+" can be worn as a decoration.\n");
}

query_value(){ return value1 + value2; }
query_save_flag(){ return 1; }
query_weight(){ return 1; }
query_composition(){ return composition; }
query_mtype(){ return mtype; }
query_crafted(){ return craft; }

init(){
   add_action("wearable", "wear");
   add_action("unwear", "unwear");
   }

unwear(str){
if(id(str) && worn){
write("You remove the "+str+".\n");
worn = 0;
return 1;
}
return;
}
   
wearable(str){
if(id(str) && !worn){
write("Ok.\n");
worn = 1;
return 1;
}	
return;
}

