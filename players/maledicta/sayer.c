#define USER environment()
#define USERN USER->query_name()

inherit "obj/treasure";
#include "/players/maledicta/ansi.h"

reset(arg){
 set_id("sayer");
 set_short("sayer");
 set_long("heh");
 set_weight(0);
 set_value(0);
 }

init(){
 add_action("new_say", "say");
 }

new_say(string str){
string newstr;
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
   "Do", "D'", "do", "d'", "Except", "'Cept", "except", "'cept", }), 3);

newstr = strsub(newstr,
({ "your", "yer", "h", "'", "Your", "Yer", "H", "'", }), 1);

newstr = strsub(newstr,
({ "tt", "'", "s have", "s've", "you", "yeh", "You", "Yeh", "who would", "who'd", "where would", "where'd", 
   "when would", "when'd", "why would", "why'd", "what would", "what'd", "come on", "c'mon", 
   "Come on", "C'mon", "Don't know", "Dunno", "don't know", "dunno", "dont know", "dunno", 
   "Dont know", "Dunno", "?", ", eh?", "n't have", "n'ta", "nt have", "n'ta", }), 0); 

     
tell_object(USER,
"You say, \""+newstr+"\"\n\n");

tell_room(environment(USER),
USERN+" says, \""+newstr+"\"\n\n", ({USER}));   
return 1;
  }
