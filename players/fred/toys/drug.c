#include "/players/fred/ansi.h"
#define freak environment()
#define to this_object()
#define en environment()->query_name()
#define enp environment()->query_possessive()
int time;

id(str){ return str == "drug_fun"; }

reset() {
  time = 100;
  set_heart_beat(1); }

drop(){ return 1;}

heart_beat() {
  int t, r;
  r = random(300);
  t = random(200);
  time --;
  if(t < 10){ 
    woo();
      }
  if(t > 190){
    screwed();
     }
  if(r < 15){
    crapped();
     }
  if(time < 1){
    happy();
     } 
   }

woo() {
  int a;
  string A; 
  a = random(7);
   switch(a){
    case 0: A = "A voice tells you: Don't eat the green pills!"; break; 
    case 1: A = "You hear planes flying overhead. GET DOWN!"; break;
    case 2: A = "You hear dogs barking in the distance and understand them!"; break;
    case 3: A = "Your toes tell you: hey moron stop moving around so much."; break;
    case 4: A = "The voice of Bob Marley tells you: Psst, got any more of those pills man."; break;
    case 5: A = "Voices whisper: We'll get you yet!"; break;
    case 6: A = "You hear a squirrel yelling at you in German."; break; }

   tell_object(freak,
     "              "+A+"\n\n");
  }

screwed(){
  int b, q;
  string B, Q;
  q = random(5);
   switch(q){
    case 0: Q = "mumbles:"; break;
    case 1: Q = "screams:"; break;
    case 2: Q = "says:"; break;
    case 3: Q = "grumbles:"; break;
    case 4: Q = "yells:"; break; }
  b = random(8);
   switch(b){
    case 0: B = "I hate all of you! You guys SUCK!"; break;
    case 1: B = "Whoooa, look at all the colors."; break;
    case 2: B = "Did you see that size of that chicken!"; break;
    case 3: B = "Where the hell did my cow wander off to now."; break;
    case 4: B = "If I was as dumb as you I would ah, um, oh forget it."; break;
    case 5: B = "What the !%$# are you looking at!"; break;
    case 6: B = "God I love magical blue tacos."; break;
    case 7: B = "Ask me about microwaving cats for fun and profit!"; break; }

    tell_room(environment(environment()),
     en+" "+Q+" "+B+"\n"); }

extra_look(){
  return ""+capitalize(environment()->query_name())+" is hallucinating!";
}

crapped(){
  int c;
  string C;
  c = random(5);
   switch(c){
    case 0: tell_room(environment(environment()),
             en+" starts to hallucinate!\n");
            tell_object(freak,
            BOLD+HIY+"\n\n\n\n                     *******************"+NORM+"\n"+
            BOLD+HIY+"                   **                   **"+NORM+"\n"+
            BOLD+HIY+"                  **                     **"+NORM+"\n"+
            BOLD+HIY+"                 **"+NORM+BOLD+"      ***     ***"+HIY+"      **"+NORM+"\n"+   
            BOLD+HIY+"                **"+NORM+BOLD+"       * *     * *"+HIY+"       **"+NORM+"\n"+
            BOLD+HIY+"               **"+NORM+BOLD+"        ***     ***"+HIY+"        **"+NORM+"\n"+ 
            BOLD+HIY+"               **                           **"+NORM+"\n"+
            BOLD+HIY+"               **                           **"+NORM+"\n"+
            BOLD+HIY+"               **"+NORM+BOLD+"    **               **"+HIY+"    **"+NORM+"\n"+
            BOLD+HIY+"                **"+NORM+BOLD+"    **             **"+HIY+"    **"+NORM+"\n"+
            BOLD+HIY+"                 **"+NORM+BOLD+"     **         **"+HIY+"     **"+NORM+"\n"+
            BOLD+HIY+"                  **"+NORM+BOLD+"      *********"+HIY+"      **"+NORM+"\n"+
            BOLD+HIY+"                   **                   **"+NORM+"\n"+
            BOLD+HIY+"                     *******************"+NORM+"\n\n\n\n"); break;
    
    case 1: tell_room(environment(environment()),
             en+" starts to hallucinate!\n");
            tell_object(freak,
            BOLD+HIB+"\n\n\n\n              ||              _____              ||"+NORM+"\n"+                
            BOLD+GRN+"               ||         _____                 ||"+NORM+"\n"+
            BOLD+MAG+"              ||              _____              ||"+NORM+"\n"+
            BOLD+RED+"               ||                 _____         ||"+NORM+"\n"+
            BOLD+BLK+"              ||              _____              ||"+NORM+"\n"+ 
            BOLD+HIY+"               ||         _____                 ||"+NORM+"\n"+
            BOLD+CYN+"              ||              _____              ||"+NORM+"\n"+
            BOLD+HIB+"               ||                 _____         ||"+NORM+"\n"+
            BOLD+GRN+"              ||              _____              ||"+NORM+"\n"+ 
            BOLD+MAG+"               ||         _____                 ||"+NORM+"\n"+
            BOLD+RED+"              ||              _____              ||"+NORM+"\n"+
            BOLD+BLK+"               ||                 _____         ||"+NORM+"\n"+
            BOLD+HIY+"              ||          _____                  ||"+NORM+"\n"+
            BOLD+CYN+"               ||             _____             ||"+NORM+"\n"+
                BOLD+"              ||                  _____          ||"+NORM+"\n\n\n\n"); break;
                
    case 2: tell_room(environment(environment()),
             en+" starts to hallucinate!\n");
            tell_object(freak,                                                                         
                BOLD+"\n\n\n\n         ()()()()()()()()()()()()()()()()()()()"+NORM+"\n"+ 
            BOLD+HIB+"            _____        ______        _____"+NORM+"\n"+
            BOLD+HIY+"                    __            __"+NORM+"\n"+                       
            BOLD+GRN+"               __          __          __"+NORM+"\n"+
            BOLD+MAG+"                                         "+NORM+"\n"+
            BOLD+CYN+"                    __            __"+NORM+"\n"+         
            BOLD+BLK+"                           **"+NORM+"\n"+  
            BOLD+BLK+"                           **"+NORM+"\n"+
            BOLD+RED+"                    __"+BLK+"     **"+RED+"     __"+NORM+"\n"+                          
            BOLD+HIB+"                                                  "+NORM+"\n"+
            BOLD+HIY+"               __          __          __"+NORM+"\n"+
            BOLD+GRN+"                    __            __"+NORM+"\n"+                    
            BOLD+MAG+"            _____        ______        _____"+NORM+"\n\n"+ 
                BOLD+"         ()()()()()()()()()()()()()()()()()()()"+NORM+"\n\n\n\n"); break;  

    case 3: tell_room(environment(environment()),
             en+" starts to hallucinate!\n");
            tell_object(freak,  
              BOLD+"\n\n\n\n            o                     O                              "+NORM+"\n"+
              BOLD+"                                                                         "+NORM+"\n"+
              BOLD+"                                                                         "+NORM+"\n"+
              BOLD+"            O                                         o                  "+NORM+"\n"+ 
              BOLD+"                                        o                                "+NORM+"\n"+
              BOLD+"                                                                         "+NORM+"\n"+
              BOLD+"                          o                                              "+NORM+"\n"+
              BOLD+"                                                                         "+NORM+"\n"+
              BOLD+"                                                                         "+NORM+"\n"+
              BOLD+"               o                                O                        "+NORM+"\n"+
              BOLD+"                                  o                                      "+NORM+"\n"+
              BOLD+"                                                                         "+NORM+"\n"+
              BOLD+"                                                           O             "+NORM+"\n"+
              BOLD+"                         O                                               "+NORM+"\n"+ 
              BOLD+"                                                                         "+NORM+"\n"+
              BOLD+"                                                                         "+NORM+"\n"+
              BOLD+"                O                         o                              "+NORM+"\n"+
              BOLD+"                                                                         "+NORM+"\n"+
              BOLD+"          o                                                              "+NORM+"\n"+
              BOLD+"                               o                    O                    "+NORM+"\n\n\n\n"); break; 
    
    case 4: tell_room(environment(environment()),
             en+" starts to hallucinate!\n");
            tell_object(freak,
             BOLD+RED+"\n\n\n\n                       ****                    ****"+NORM+"\n"+
             BOLD+RED+"                       ****                    ****"+NORM+"\n"+ 
             BOLD+RED+"                       ****                    ****"+NORM+"\n"+
             BOLD+RED+"                       ****                    ****"+NORM+"\n"+
             BOLD+RED+"                       ****                    ****"+NORM+"\n"+
             BOLD+RED+"                       ****                    ****"+NORM+"\n"+
             BOLD+RED+"                       ****                    ****"+NORM+"\n"+
             BOLD+RED+"                       ****                    ****"+NORM+"\n"+
             BOLD+RED+"                       ****                    ****"+NORM+"\n"+
             BOLD+RED+"                       ****                    ****"+NORM+"\n"+
             BOLD+RED+"                       ****                    ****"+NORM+"\n"+
             BOLD+RED+"                       ****                    ****"+NORM+"\n"+
             BOLD+RED+"                        ****                  ****"+NORM+"\n"+
             BOLD+RED+"                         ****                ****"+NORM+"\n"+
             BOLD+RED+"                          ****              ****"+NORM+"\n"+
             BOLD+RED+"                           ****            ****"+NORM+"\n"+
             BOLD+RED+"                            ****          ****"+NORM+"\n"+
             BOLD+RED+"                             ****************"+NORM+"\n"+ 
             BOLD+RED+"                               ************"+NORM+"\n"+
             BOLD+RED+"                                 ********"+NORM+"\n\n\n\n"); break; }
    }
     
happy() {
  tell_room(environment(environment()),
  en+" looks relieved as the drugs wear off.\n");
  destruct(this_object()); 
  return 1; 
  }

