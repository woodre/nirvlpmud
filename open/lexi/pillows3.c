/*THIS IS JUST MY OWN LITTLE TOY THAT I CREATED USING MOUZAR'S KOOSH CODE*\
/* Thanks to Mizan and Jaraxle for assisting with random color */
#include "/obj/ansi.h"
#include "/bin/ghost.c"

#define tp this_player()
#define tpn this_player()->query_name()
#define cpn capitalize(str)
string color;

id(str) {return str == "pillow" || str == "pillow";  }
short() {return color+"A Pillow"+NORM; }
long() {write("A fluffy soft pillow made from the softest\n"+
              "of fabrics. Maybe you can 'bop <player>' and\n"+
              "start a pillow fight! Or type 'toss <player>'\n"+
              "to get the party started!\n"); return 1; }
get() {return 1;}
init() {
random_color();
 add_action("bop_pillow","bop");
 add_action("toss_pillow","toss");
}

bop_pillow(str) {
        object who;
        if (ghost() || !str) {
          write("You must specify someone to bop with your "+color+"pillow"+NORM+"!\n");
          return 1;
        }
        who = present(str, environment(tp));
     if(!who || !living(who) || who == this_player() || who->query_invis() > 0) {
           write("Who you want to bop with a "+color+"pillow"+NORM+"?!?!?!\n");
           return 1;}
     if(who->in_editor()) {
		   write("Try again later when this wizard isn't editing.\n");
           return 1;}
     if(who->query_tellblock()) {
		   write(cpn+" has tell blocking turned on. They might not want to be disturbed"+
					 "at the moment.\n");
        return 1;}
     if(who->query_level()<20 || who->query_real_name() == "mouzar" ||
       who->query_real_name() == "mishtar" || who->query_real_name() == "mizan" ||
       who->query_real_name() == "data" || who->query_real_name() == "arrina" ||
       who->query_real_name() == "wocket" || who->query_real_name() == "quicksilver" ||
who->query_real_name() == "jaraxle" || who->query_real_name() == "puppy" || 
who->query_real_name() == "sparkle"|| who->query_real_name() == "lexi") {
	say(tpn+" bops "+cpn+" over the head with a "+color+"pillow"+NORM+"!!\n", who);
	write("You bopped "+cpn+" over the head with a "+color+"pillow"+NORM+"!!\n");
	say(cpn+" has just been bopped with a "+color+"pillow"+NORM+"!!\n", who);
	return 1;}
		 else{
	write("You try to bop "+cpn+" with your "+color+"pillow"+NORM+" but it comes right back and smacks you in the face!!\n"+
		  HIR+"YOU CAN'T BOP WIZARDS!! Grumpy ones anyway.\n"+
		  "*grin*"+NORM+"\n");
	return 1;}
}

toss_pillow(str) {
        object who;
        if (ghost() || !str) {
          write("You must specify someone you want to toss the "+color+"pillow"+NORM+" at!\n");
          return 1;}
        who = present(str, environment(tp));
     if(!who || !living(who) || who == this_player() || who->query_invis() > 0) {
           write("Who you want to toss the "+color+"pillow"+NORM+" at?!?!?!\n");
           return 1;}
       if(who->in_editor()) {
          write("Try again later when this wizard isn't editing.\n");
          return 1;}
     if(who->query_tellblock()) {
			write(cpn+" has tell blocking turned on. They might not want to be disturbed"+
					  "at the moment.\n");
        return 1;}
     if(who->query_level()<20 || who->query_real_name() == "mouzar" ||
       who->query_real_name() == "mishtar" || who->query_real_name() == "mizan" ||
       who->query_real_name() == "data" || who->query_real_name() == "arrina" ||
       who->query_real_name() == "wocket" || who->query_real_name() == "quicksilver" ||
who->query_real_name() == "jaraxle" || who->query_real_name() == "puppy" || 
who->query_real_name() == "lexi" || who->query_real_name() == "sparkle") {
tell_object(who, tpn+" tosses a "+color+"pillow"+NORM+" at you!!\n");
	say(tpn+" tosses a "+color+"pillow"+NORM+" at "+cpn+"!!\n", who);
	write("You tossed a "+color+"pillow"+NORM+" at "+cpn+"!!\n");
	move_object(this_object(), who);
	say(cpn+" has just been tossed a "+color+"pillow"+NORM+"!!\n", who);
		return 1;}
	else{
	write("You toss the "+color+"pillow"+NORM+" but it comes right back and smacks you in the face!!\n"+
		  HIR+"YOU CAN'T BOP WIZARDS!! Grumpy ones anyway.\n"+
		  "*grin*"+NORM+"\n");
	return 1;}
}

random_color() {
        int ran;
        ran = 1+random(7);
	if(ran == 1) { color=RED; return 1; }
	if(ran == 2) { color=MAG; return 1; }
	if(ran == 3) { color=CYN; return 1; }
	if(ran == 4) { color=HIR; return 1; }
	if(ran == 5) { color=HIM; return 1; }
	if(ran == 6) { color=HIC; return 1; }
	if(ran == 7) { color=HIW; return 1; }
	return 1;
}
