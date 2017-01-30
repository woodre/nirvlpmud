inherit "/players/jenny/room";
#include "/players/jenny/define.h"
realm() { return "NT"; }
reset(arg) {
    if(arg) return;
    set_light(1);
     set_listen(BOLD+"You can hear the heads moaning for water."+NORM+"\n");
     set_smell(BOLD+"You can smell that fresh country air."+NORM+"\n");
long_desc=
"You are standing in a garden, on the great planet of Potatoho.\n"+      
"This is a planet known for its great values.  Where after a\n"+
"days work, a man can go back home to his Becky Sue, and\n"+
"tend the garden.  Looking at this garden, you notice it is very\n"+
"different from the gardens of earth.  Humanoid heads are\n"+
"sticking out of the ground.  Apparently this is the way they\n"+
"grow their young in Potatoho.\n";

items = ({
"garden","This is a strange garden, with human heads growing up from the soil",
"heads","These heads are yearning for water",
});

dest_dir = ({
"/players/jenny/workroom","penalty box",
});
}
short() {
return BOLD+YEL+"Potatoho"+NORM; }
init() { 
    ::init(); 
   this_player()->set_fight_area();
}
