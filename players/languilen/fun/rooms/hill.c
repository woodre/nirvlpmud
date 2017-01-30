#include "/players/languilen/closed/ansi.h"
#include "../paths.h"
#define TPN this_player()->query_name()
#define TP this_player()
inherit "room/room";

int x, given;

reset(arg) {
     if(arg) return;
     set_light(1);

     x = 0;
     short_desc = "Funhouse Hill";
     long_desc =
"    There are flashing lights whistles and bells going off all over\n\
the place.  Here the tile has been replaced by thickly cushioned shag\n\
carpet that has been raised up in the center to form a sort of hill.\n\
Suspended from the ceiling is a large sign.  Directly west stands the\n\
dunk tank and off to the east is the game room.\n";

   items = ({
      "lights","Strobes of all different colors flash from above",
      "tiles","The tiles are a checkered pattern and look a bit used but not warn",
      "carpet","The carpet is thick enough to pad a fall",
      "hill","A five foot high hill of carpet with a button up at the top",
      "button","This small button is used to summon a challenger",
      "sign","The sign above the hill is large and easily read", 
   });

   dest_dir = ({
	AREA+"gameroom.c","east",
        AREA+"tank.c","west",
   });
}
init(){
     ::init();
     add_action("pushed","push");
     add_action("read_sign","read");
     add_action("listening","listen");
}
read_sign(str){
     if(!str || str != "sign"){
        notify_fail("Are you trying to 'read' the 'sign'?\n");
        return 0;
     }
     write(HIG+"\n\
                          \\o/\n\
                           | \n\
                          |^|"+NORM+"\n");
     write("\
                        KING OF THE HILL!!!.\n\
                 Push the button on the hill to accept\n\
           a challenge.  You must take on all challengers plus\n\
       the present champion to gain the title of KING OF THE HILL!\n\n");
     return 1;
}


pushed(str){
     int tmp, i;
     object new, king;
     if(!str || str != "button"){
        notify_fail("Did you want to 'push' the 'button'?\n");
        return 0;
     }
     if(present("kid",environment(TP))){
        write("The kid stops you from pressing the button.\n");
        say("The kid stops "+TPN+" from pressing the button.\n");
        return 1;
     }
     if(x==0 || x==1 || x==2){
        tmp=1;
     } else { tmp = x/3; }
     if(x > 15){
        if(!given){
           king = clone_object(MON+"king.c");
           move_object( king,this_object() );
           given = 1;
           return 1;
        }
        write("There are no more challengers.  Try again later.\n");
        return 1;
     }
     i = TP->query_level();
     if(i>5) i = 5;
     new = clone_object("/obj/monster.c");
     new->set_name("kid");
     new->set_alias("big kid");
     new->set_race("human");
     new->set_short("A Big Kid");
     new->set_long("This would-be king of the hill is a stout youngster with\n"+
                   "the devil in his eye.  Watch out or he will claim your title!\n");
     new->set_level(i+tmp);
     new->set_hp( (i+tmp) * 15 );
     new->set_al(-50);
     new->set_wc(10+tmp);
     new->set_ac(5+tmp);
     new->set_aggressive(0);
     new->set_chat_chance(5);
     new->load_chat("The kid says 'I wanna' be king!'\n");
     new->set_a_chat_chance(8);
     new->load_a_chat("The kid says 'I'm gonna knock you off of this hill!'\n");
     if(TP->query_level() > 4){
        new->set_chance(8);
        new->set_spell_dam(10);
        new->set_spell_mess1("The kid SLAMS both of his hands into your chest knocking your breath away!\n");
        new->set_spell_mess2("The kid SLAMS his attacker backwards.\n");
     }
     if(TP->query_level()+tmp < 3){ new->add_money((i+tmp) * 30); }
     else { new->add_money((i+tmp-1) * 50); }
     x++;
     move_object(new, this_object());
     write("You push the button and a challenger steps up.\n");
     say(TPN+" pushes the button and challenger steps up.\n");
     return 1;
}

listening(){
     write("Shrill whistles and clamouring bells make hearing much else a chore.\n");
     return 1;
}

realm(){ return "NT"; }
