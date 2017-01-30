#define USER environment()
#define USERN USER->query_name()
#define ATT USER->query_attack()
#define ATTN ATT->query_name()

#include "/players/maledicta/ansi.h"

id(str){
return str == "dwarven_might" || str == "generic_wc_bonus";
}

query_auto_load(){ return "/players/maledicta/closed/dwarf.c:"; }

drop(){ return 1; }
get(){ return 1; }
query_weight(){ return 0; }
query_value(){ return 0; }


init(){
 add_action("new_say", "say");
 }

new_say(string str){
string newstr;
string one, two;
string message;
newstr = str;
if(!newstr){
   write("Say what?\n");
   return 1;
   }      

newstr = strsub(newstr, 
({ "n't have", "n'ta", "nt have", "n'ta", }), 0);

newstr = strsub(newstr, 
({ "t", "'", "g", "'", "ts", "'s", "t's", "'s", "ing", "in'", "'t", "'", }), 2);
newstr = strsub(newstr, 
({"Except", "'Cept", "except", "'cept", "different", "diff'rent", "Different", "Diff'rent", }), 3);
newstr = strsub(newstr,
({ "of", "o'", "and", "an'", "them", "'em", "you'll", "yeh'll", "to", "ter", "different", "diff'rent",
   "only", "on'y", "for", "fer", "old", "ol'", "been", "bin", "my", "me", "cause", "cos", 
   "as", "'s", "will", "'ll", "hello", "lo'", "told", "tol'", "is", "'s", "do", "d'", 
   "Of", "O'", "And", "An'", "Them", "'Em", "You'll", "Yeh'll", "To", "Ter", "Different", "Diff'rent",
   "Only", "On'y", "For", "Fer", "Old", "Ol'", "Been", "Bin", "My", "Me", "Cause", "Cos", 
   "Hello", "Lo'", "Told", "Tol'", "Is", "'s", "Do", "d'", "You", "Yeh", "you", "yeh", 
   "Do", "D'", "do", "d'", "Except", "'Cept", "except", "'cept", "Yes", "Aye", "yes", "aye", }), 3);

newstr = strsub(newstr,
({ "your", "yer", "h", "'", "Your", "Yer", "H", "'", }), 1);

newstr = strsub(newstr,
({ "tt", "'", "s have", "s've", "you", "yeh", "You", "Yeh", "who would", "who'd", "where would", "where'd", 
   "when would", "when'd", "why would", "why'd", "what would", "what'd", "come on", "c'mon", 
   "Come on", "C'mon", "Don't know", "Dunno", "don't know", "dunno", "dont know", "dunno", 
   "Dont know", "Dunno", "?", ", eh?", "n't have", "n'ta", "nt have", "n'ta", }), 0); 

if (sscanf(str, "%s!!!", message)) {
  one = "yell";  
  two = "yells";
  } 
else if (sscanf(str, "%s!!", message)) {
  one = "yell";  
  two = "yells";
  } 
else if (sscanf(str, "%s!", message)) {
  one = "exclaim";
  two = "exclaims";  
  } 
else if (sscanf(str, "%s???", message)) {
  one = "wonder";
  two = "wonders";
  } 
else if (sscanf(str, "%s??", message)) {
  one = "wonder";
  two = "wonders";
  } 
else if (sscanf(str, "%s?", message)) {
  one = "ask";
  two = "asks";
  } 
else {
  one = "say";
  two = "says";
 }

     
tell_object(USER,
"You "+one+", \""+newstr+"\"\n\n");

tell_room(environment(USER),
USERN+" "+two+", \""+newstr+"\"\n\n", ({USER}));   

return 1;
  }

gen_wc_bonus(){
if(random(100) < 10){ 
USER->add_hit_point(random(6) + 1); 
tell_object(USER, "Your Dwarven stamina kicks in and you heal up...\n");
}
if(random(100) < 30){
 tell_object(USER, "Your muscles ripple as you tear into "+ATTN+"!\n");
 return 3;
 }
else if(random(100) < 10){
 tell_object(USER, "You see red as you blast "+ATTN+" with your weapon!\n");
 return 5;
 }      

return 0;
}