#include "/players/francesco/univ/ansi.h"
inherit "obj/weapon";

reset(arg){
  ::reset(arg);
  if (arg) return;
  set_name("snowhoe");
  set_alias("polearm");
  set_alt_name("weapon");
  set_long("This thin snowhoe was used by Bjorn Daehlie in his fantastic \n"+
           "wins in the Olympics 1994 in Lillehammer.  With an adequate \n"+
           "skill, this snowhoe can be used like a foil in fencing, even\n"+
           "though it is not that dangerous.  Something can be 'view'ed on\n"+
           "its 'handle'.\n");
  set_type("polearm");
  set_class(15);  
  set_weight(1);
  set_value(5500);
  set_hit_func(this_object());
}

short(){
        if(this_object()->query_wielded()){
        return "A snowhoe wielded in right hand.\n"+
               "A snowhoe wielded in left hand"; }
        else { return "A pair of snowhoes"; }        
}  

two_handed(){ return 1; } 

id(str)    { return str=="snowhoe"; }

init() {
  ::init();
  add_action("trade","return");
  add_action("read","read");
  add_action("view","view");
}

weapon_hit(attacker){ 
 if(call_other(this_player(), "query_attrib", "pie") > random(60)){
   write("You swish the point of your snowhoe along your opponent's neck.\n"+
         "Yessssss!  It did the job!\n");
   this_player()->add_spell_point(2+random(5));
 return random(5)+4; }
  /* 
    33% chance of return, with concomintant healing and WC.
    It is better than the Trident of war in the healing.
    It is worse than the Trident of war in the WC.
    Overall, it should be a little better, since Bjorn 
    Daehlie is stronger than Issiac.
  */
}

count_misses(w) {return 1;}     /* further advantage, it doesnt wear out */
count_hit_made(w) {return 1;}


trade(str){            
if(environment() != this_player()) {notify_fail("You must get the snowhoe first.\n"); return 0;}
  if(!str) { notify_fail("What do you want to trade?\n"); return 0; }
    if(id(str)){
       if(!present("narrator",environment(this_player()))){
         write("The "+(str)+" cannot be traded in this room.\n");
       return 1;}
      write("The narrator replies:  'Thank you, thank you, I always\n"+
            "wanted to have a reminder of the great Bjorn Daehlie\n"+
            "and now I am very happy that you brought this snowhoe to\n"+
            "me.  Please, take these coins as a sincere mark of thanks.'\n");
      call_other(this_player(),"add_money",(5500));
      destruct(this_object());
    return 1;}
  notify_fail("That is not something you can trade here.\n");
  return 0;
}    

view(str) {       
if(environment() != this_player()) {notify_fail("You must get the snowhoe first.\n"); return 0;}
  if(!str) { notify_fail("What do you want to view?\n"); return 0; }
   if(str=="handle")  {write("On the handle there are some engravings to read.\n"); return 1;}
   notify_fail("What do you want to view?\n"); return 0; 
return 1;
}

read(str) {       
if(environment() != this_player()) {notify_fail("You must get the snowhoe first.\n"); return 0;}
  if(!str) { notify_fail("What do you want to read?\n"); return 0; }
   if(str=="engravings")  {write("'Return' it to Runi, the narrator.  \nHe will appreciate.\n\nSincerely, \nBjorn Daehlie\n"); return 1;}
   notify_fail("What do you want to read?\n"); return 0; 
return 1;
}
