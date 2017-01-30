inherit "/players/jenny/room";
#include "/players/jenny/define.h"
int stupidvariable;
realm() { return "NT"; }
reset(arg) {
    if(arg) return;
    set_light(1);
     set_search(BOLD+"You notice some nice pictures on the wall."+NORM);
long_desc=
"The hallway on the executive level is wider, and looks classier,\n"+      
"than the other hallways throughout the arena.  The floor is\n"+
"covered with a plush red carpet, and the cream colored walls are\n"+
"decorated with plenty of pictures.  There are offices to the north\n"+
"and south.\n";
items = ({
"offices","The owner's office is to the north and the general manager's\n"+
            "office is to the south",
"floor","The floor is covered with thick red carpet",
"carpet","The carpet is thick and dark red",
"walls","The cream colored walls are decorated with lots of pictures",
"pictures","Here you see pictures of Terry Sawchuk, Alex Delvecchio, Red\n"+
                 "Kelly, Marcel Pronovost, Norm Ullman and Vladimir Konstantinov",	
});

dest_dir = ({
"/players/jenny/wings/rooms/owneroffice","north",
"/players/jenny/wings/rooms/gmoffice","south",
"/players/jenny/wings/rooms/s1","west",
"/players/jenny/wings/rooms/s3","east",
});
}
short() {
return BOLD+WHT+"A Hallway"+NORM; }
init() { 
    ::init(); 
   this_player()->set_fight_area();
if(stupidvariable > 17) {command("look",TP);}
}
ghettocode1() {
stupidvariable = 18;
return 1;}
ghettocode2() {
stupidvariable = 0;
return 1;}
