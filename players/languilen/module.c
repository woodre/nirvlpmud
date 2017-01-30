#include "/players/languilen/closed/ansi.h"
#define TPN this_player()->query_name()
#define TP this_player()
#define BASE "/players/languilen/"
#define DOORWAYS "two"
inherit "room/room";

reset(arg) {
     if(arg) return;
     set_light(1);

     short_desc = BLU+"]"+NORM+" Universal module "+BLU+"["+NORM+" ";
     long_desc =
"    This small octogonal chamber exists just outside the bounderies\n\
of time and the universe as you know it.  Pieces of things lie all about\n\
in disarray, as though a tornado had passed through.  The remnants of\n\
what might have been a chair lie in the center of the room. Whatever did\n\
this has long gone, but this place is not empty.  A benevolent presence\n\
can be felt here, almost as if the room itself were somehow sentient.\n\
Just to think about something causes the telepathic entity to respond.\n\
Of the eight surrounding walls, "+DOORWAYS+" glow blue, the rest are a dead\n\
ashen grey.\n";

     items = ({
     "pieces","Broken and unrecognizeable bits of mechanical equipment",
     "remnants","Oddly, the arms have been smashed completly off",
     "chair","Oddly, the arms have been smashed completly off",
     "presence","You can't see it, but you know that it's here",
     "entity","It can't be seen, but you know it's here",
     "walls","They are smooth and made of an unknown dull grey metal",
     });

     dest_dir = ({
          "/room/ruin","ruin",
          BASE+"fun/rooms/lobby.c","funhouse",
     });
}
init(){
     ::init();
     add_action("thinking","think");
     add_action("searching","search");
     add_action("fun_check","funhouse");
     this_player()->clear_fight_area();
}
thinking(str){
     if(!str){
        notify_fail("You must think about something!\n");
        return 0;
     }
     if(sscanf(str,"about %s",str)!= 1){
        notify_fail("Usage: think about <something>.\n");
        return 0;
     }
     if(str == "ruin"){
        write("A voice in your head says 'The desolate remains of a strange building in Nirvana.'\n");
        return 1;
     }
     if(str == "funhouse"){
        write("The funhouse is a place for the young only, -level 5 and under-. It's\n\
full of wonderfull games and amusements.\n");
        return 1;
     }
     if(str == "presence"){
        write("\
The voice in your head says 'Ahh, so you are curious about what i am\n\
then...  Though i am sentient, i am not what most would consider 'alive'.\n\
My embodiment is that which you see around you, but that is only a part\n\
of what i am.  Extensive damage has rendered most of my functions in-\n\
operable, but i was designed to travel and gather information.\n");
        return 1;
     }
     if(str == "damage"){
        write("The damage was caused by the enemies of my former companion who was\n\
killed in the attack.'\n");
        return 1;
     }
     if(str == "functions"){
        write("I used to be able to do many things.  Now, i'm afraid, all i can do is\n\
offer some information and "+DOORWAYS+" doorways for you to travel through.'\n");
        return 1;
     }
     if(str == "gather"||str == "information"){
        write("Most of my memory banks have been crippled but think about what you\n\
want to know about and i will answer if i can.\n");
        return 1;
     }
     write("There is no reply.\n");
     return 1;
}
searching(){
     write("You could search for hours and never find anything usefull, or if\n\
you did you probably wouldn't know it!\n");
     return 1;
}
fun_check(){
     if(TP->query_level()>5){
        write("You can't go in there!  The Funhouse is for newbies!\n");
        return 1;
     } else { return 0; }
}

