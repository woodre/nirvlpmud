/* Thanks to Mizan and Jaraxle for assisting with random color */
#include "/obj/ansi.h"
#define cap_name capitalize(this_player()->query_name())
string color;

id(str) {return str == "koosh" || str == "kooshball";  }
short() {return color+"Kooshball"+NORM; }
long() {write("This is a koosh ball. It is made of thousands\n"+
              "of little rubbery tenticles.  Feels kinda wierd huh?\n"+
              "Try to juggle it!  Type 'koosh <player>' to toss it to\n"+
              "someone.\n"); return 1; }
get() {return 1;}
init() {
random_color();
 add_action("juggle_ball","juggle");
 add_action("toss_koosh","koosh");
}

juggle_ball(str) {
   if ((!str) || !id(str)) {
       return 0;
       }
   write("You skillfuly juggle the "+color+"koosh"+NORM+"!\n");
     say(cap_name+" deftly juggles a "+color+"koosh"+NORM+" like a pro!(only one???)\n");
     return 1;
         }

toss_koosh(str) {
        object who;
        object it;
        if (!str) {
          write("You must specify someone to "+color+"koosh"+NORM+"!\n");
          return 1;
        }
        it = lower_case(str);
        who = find_living(it);
     if(!who || !living(who) || who == this_player() || who->query_invis() > 0) {
           write("Who you want to "+color+"Koosh"+NORM+"?!?!?!\n");
           return 1;
        }
       if(who->in_editor()) {
          write("Try again later when this Wiz isn't editing.\n");
          return 1;
       }
     if(who->query_tellblock()) {
         write(capitalize(str)+" has tell blocking turned on.  You might\n"+
        "want to be disturbed at the moment.\n");
        return 1;
     }
       if(who->query_level()<20 || who->query_real_name() == "mouzar" ||
       who->query_real_name() == "mishtar" || who->query_real_name() == "mizan" ||
       who->query_real_name() == "data" || who->query_real_name() == "arrina" ||
       who->query_real_name() == "wocket" || who->query_real_name() == "quicksilver" ||
      who->query_real_name() == "jaraxle" || who->query_real_name() == "puppy"||
      who->query_real_name() == "lexi") {
          tell_object(who, cap_name + " tosses a "+color+"koosh"+NORM+" at you!!\n");
          say(cap_name +" tosses a "+color+"koosh"+NORM+" at "+capitalize(who->query_name())+"\n");
if(this_player()->query_real_name() == "wocket")
    tell_object(who,"You have been "+color+"kooshed"+NORM+" by a god among kooshers!\nYou have been "+color+"kooshed"+NORM+" by "+BOLD+"WOCKET"+NORM+"!\n");
          write("You "+color+"koosh"+NORM+" " + capitalize(str) +"!\n");
          move_object(this_object(), who);
          say(capitalize(who->query_name()) +" has just been "+color+"kooshed"+NORM+"!\n");
          return 1;
        } else {
          write("You toss the "+color+"koosh"+NORM+" but it comes right and smacks you\n"+
                "in the face!  "+HIR+"YOU CAN'T KOOSH WIZARDS!! Grumpy ones anyway."+
                "*grin*"+NORM+"\n");
        return 1;}
}

random_color() {
        int ran;
        ran = 1+random(14);
	if(ran == 1) { color=RED; return 1; }
	if(ran == 2) { color=GRN; return 1; }
	if(ran == 3) { color=YEL; return 1; }
	if(ran == 4) { color=BLU; return 1; }
	if(ran == 5) { color=MAG; return 1; }
	if(ran == 6) { color=CYN; return 1; }
	if(ran == 7) { color=WHT; return 1; }
	if(ran == 8) { color=HIR; return 1; }
	if(ran == 9) { color=HIG; return 1; }
	if(ran == 10) { color=HIY; return 1; }
	if(ran == 11) { color=HIB; return 1; }
	if(ran == 12) { color=HIM; return 1; }
	if(ran == 13) { color=HIC; return 1; }
	if(ran == 14) { color=HIW; return 1; }
	return 1;
}
