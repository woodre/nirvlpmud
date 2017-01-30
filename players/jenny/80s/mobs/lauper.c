inherit "/obj/monster";
#include "/players/jenny/define.h"
int play;
id(str) { return str == "cyndi lauper" ||  str == "cyndi" || str == "lauper" || str == "singer" || str == "cindy" || str == "Cyndi Lauper"; } 
reset(arg)
{
   ::reset(arg);
    if (arg) return;
set_name("Cyndi Lauper");
    set_race("human");
set_gender("female");
    set_al(65+random(40));
    set_level(13);
    set_hp(190+random(10));
    set_wc(18);
    set_ac(9);
    set_short(MAG+"Cyndi "+YEL+"Lauper"+NORM);
    set_long(
      "Cyndi Lauper is a skinny little thing wearing too much makeup, and with long,\n"+
      "teased hair in assorted colors.  She was one of the most annoying singers in\n"+
      "the 80's.  Her biggest hit was 'girls just wanna have fun'.  She was also briefly\n"+
     "involved in professional wrestling as the manager of a female wrestler.  If you\n"+
     ""+BOLD+"pay "+NORM+"her 5 coins, she may sing a song for you.\n");
MOCO("/players/jenny/80s/items/juice.c"),this_object());
  gold=clone_object("obj/money");
  gold->set_money(90+random(20));
  move_object(gold,this_object());
}
init() {
::init();
add_action("music","pay");
}
music(arg) {
if(arg == "cyndi lauper" || arg == "cyndi" || arg == "lauper") {
if(this_player()->query_money() < 5) {
write(MAG+"Cyndi says: "+NORM+"But you aint got the money honey.\n");
return 1; }
if(play == 2) {write("She's already singing.  Don't try to confuse the poor girl.\n"); return 1; }
tell_room(ENVTP,BOLD+"Cyndi happily takes the 5 coins and picks up her microphone."+NORM+"\n");
TP->add_money(-5);
play = 2;

call_out("song",5);
call_out("song2",9);
call_out("song3",15);
call_out("song4",19);
call_out("song5",21);
call_out("song6",28);
call_out("song7",33);
call_out("song8",39);
call_out("song9",42);
call_out("song10",44); 
call_out("song11",47);
call_out("song12",49);
call_out("song13",51);
call_out("song14",53); 
call_out("song15",55);
call_out("song16",62);
call_out("song17",66);
call_out("song18",71); 
call_out("song19",76);
call_out("song20",80);
call_out("song21",82);
call_out("song22",85); 
call_out("song23",87);
call_out("song24",90);
call_out("song25",92);
call_out("song26",94); 
call_out("song27",96);
call_out("song28",101);
return 1; }}
song() {
tell_room(ENVTP,BOLD+"I come home in the morning light."+NORM+"\n");
return 1; }
song2() {
tell_room(ENVTP,BOLD+"My mother says when you gonna live your life right."+NORM+"\n");
return 1; }
song3() {
tell_room(ENVTP,BOLD+"Oh mother dear we're not the fortunate ones."+NORM+"\n");
return 1; }
song4() {
tell_room(ENVTP,BOLD+"And girls they want to have fun."+NORM+"\n");
return 1; }
song5() {
tell_room(ENVTP,BOLD+"Oh girls just want to have fun."+NORM+"\n");
return 1; }
song6() {
tell_room(ENVTP,BOLD+"The phone rings in the middle of the night."+NORM+"\n");
return 1; }
song7() {
tell_room(ENVTP,BOLD+"My father yells what you gonna do with your life."+NORM+"\n");
return 1; }
song8() {
tell_room(ENVTP,BOLD+"Oh daddy dear you know you're still number one."+NORM+"\n");
return 1; }
song9() {
tell_room(ENVTP,BOLD+"But girls they want to have fun."+NORM+"\n");
return 1; }
song10() {
tell_room(ENVTP,BOLD+"Oh girls just want to have--"+NORM+"\n");
return 1; }
song11() {
tell_room(ENVTP,BOLD+"That's all they really want."+NORM+"\n");
return 1; }
song12() {
tell_room(ENVTP,BOLD+"Some fun"+NORM+"\n");
return 1; }
song13() {
tell_room(ENVTP,BOLD+"When the working day is done"+NORM+"\n");
return 1;}
song14() {
tell_room(ENVTP,BOLD+"Girls-- they want to have fun."+NORM+"\n");
return 1;}
song15() {
tell_room(ENVTP,BOLD+"Oh girls just want to have fun."+NORM+"\n");
return 1;}
song16() {
tell_room(ENVTP,BOLD+"Some boys take a beautiful girl"+NORM+"\n");
return 1;}
song17() {
tell_room(ENVTP,BOLD+"And hide her away from the rest of the world."+NORM+"\n");
return 1;}
song18() {
tell_room(ENVTP,BOLD+"I want to be the one to walk in the sun."+NORM+"\n");
return 1;}
song19() {
tell_room(ENVTP,BOLD+"Oh girls they want to have fun."+NORM+"\n");
return 1;}
song20() {
tell_room(ENVTP,BOLD+"Oh girls just want to have"+NORM+"\n");
return 1;}
song21() {
tell_room(ENVTP,BOLD+"That's all they really want."+NORM+"\n");
return 1;}
song22() {
tell_room(ENVTP,BOLD+"Some fun"+NORM+"\n");
return 1;}
song23() {
tell_room(ENVTP,BOLD+"When the working day is done"+NORM+"\n");
return 1;}

song24() {
tell_room(ENVTP,BOLD+"Girls--they want to have fun."+NORM+"\n");
return 1;}
song25() {
tell_room(ENVTP,BOLD+"Oh girls just want to have fun,"+NORM+"\n");
return 1;}
song26() {
tell_room(ENVTP,BOLD+"They want to have fun,"+NORM+"\n");
return 1;}
song27() {
tell_room(ENVTP,BOLD+"They want to have fun..."+NORM+"\n");
return 1;}
song28() {
tell_room(ENVTP,MAG+BOLD+"Cindy smiles and says: "+NORM+BOLD+"I hope you liked my song."+NORM+"\n");
play = 1;
return 1; }
