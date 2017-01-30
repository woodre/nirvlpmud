inherit "/players/jenny/room";
#include "/players/jenny/define.h"
int pooltime;
string daemote;
realm() { return "NT"; }
reset(arg) {
    if(arg) return;
    set_light(1);
     set_smell(BOLD+"The warm air has a heavy chlorine smell."+NORM);
     set_listen(BOLD+"The jet behind you is pushing water against your back\n"+
                                    "making a bubbling sound in your ear."+NORM);
     set_search(BOLD+"You dive down into the water and notice a drain."+NORM);
long_desc=
"The hot relaxing water of the whirlpool does a lot to soothe your\n"+      
"aches and pains.  The whirlpool is stainless steel, with steps and\n"+
"a railing leading down into it.  You can feel a bench going all the\n"+
"way around.  Powerful jets are positioned everywhere, making the\n"+
"water seem to bubble.\n";
items = ({
"water","The water is powerfully swirling around.  It seems like it's bubbling",
"whirlpool","This round stainless steel whirlpool can comfortably hold about\n"+
              "five people",
"steps","Two steps allow people to ease their way into the whirlpool",
"drain","A small grate in the bottom of the whirlpool, used to drain out the water",
"railing","There is a small stainless steel railing next to the steps",
"bench","You can't really see the bench, but can feel that it goes all the way\n"+
                "around, giving people a place to sit",
"jets","Powerful jets are positioned all around the whirlpool, both near the\n"+
           "surface, and down near the bottom",
});
dest_dir = ({
 "/players/jenny/wings/rooms/whp","out",
});
}
short() {
return BOLD+"Whirlpool"+NORM; }
init() { 
    ::init(); 
   this_player()->set_fight_area();
}
buttonpushed(){ 
call_out("thepool",15+random(10));
return 1;}
thepool() {
poolemotes();
pooltime += 1;
if(pooltime < 15) call_out("thepool",15+random(10));
else { tell_room("/players/jenny/wings/rooms/whirlpool.c",BOLD+"The whirlpool jets shut off."+NORM+"\n");
call_other("/players/jenny/wings/rooms/whp.c","resetit");
pooltime = 0;
return 1; }}
poolemotes() {
if(random(4) == 0) {daemote = "The hot soothing water of the whirlpool relaxes your muscles.";}
if(random(4) == 1) {daemote = "You feel comepletely relaxed";}
if(random(4) == 2) {daemote = "The whirlpool jets gently massage you.";}
if(random(4) == 3) {daemote = "You forget about your troubles as you relax in the whirlpool.";}
tell_room("/players/jenny/wings/rooms/whirlpool.c",BOLD+daemote+NORM+"\n");
if(random(12) < 5) {
int xx;
object obj;
obj = users();
for (xx = 0; xx < sizeof(obj); xx ++){
if(present(obj[xx], this_object())) {
obj[xx]->heal_self(random(3) + 1);
}} return 1; }}
