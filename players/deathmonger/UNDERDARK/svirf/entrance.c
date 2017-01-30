
#include "std.h"

int show;
reset(arg){
     if(!arg){
     set_light(1);
     extra_reset();
    }
}

object svirf;
object hammer;
extra_reset(){
     if(!present("svirfneblin")){
       svirf = clone_object("obj/monster");
       svirf->set_name("svirfneblin");
       svirf->set_short("A Svirfneblin Gnome guard");
call_other(svirf, "set_long",
      "Svirfneblin are the deep gnomes that live underground.  They are\n"+
      "masters at illusion and accomplished tricksters.  They are also a\n"+
      "decidedly good race and hate the minotaurs and  Druegars that often\n"+
      "share their domains.\n");
       svirf->set_level(12);
       svirf->set_hp(180);
       svirf->set_wc(16);
       svirf->set_ac(9);
       svirf->set_chat_chance(100);
       svirf->load_chat("Red Dragon smashed you with a bonecrushing sound!\n");
       svirf->load_chat("Red Dragon massacred you to small fragments.\n");
       svirf->load_chat("You missed.\n");
       svirf->load_chat("You tickled Red Dragon in the stomach.\n");
       hammer = clone_object("obj/weapon");
       hammer->set_name("hammer");
       hammer->set_short("A Svirfneblin mining hammer");
       hammer->set_weight(1);
       hammer->set_class(10);
       hammer->set_value(400);
       move_object(hammer, svirf);
        move_object(svirf, this_object());
       }
}

init(){
       add_action("down","down");
     add_action("north","north");
     add_action("not","west");
     add_action("not","east");
     add_action("not","south");
     add_action("kill","kill");
     add_action("show","show");
}

kill(str){
     if(str == "svirfneblin" || str == "guard");
        this_player()->attack_object(svirf);
        write("Since you have shown yourself unworthy of Myconid friendship\n");
        write("by attacking the friendly gnomes, the symbol disappears.\n");
        destruct(present("friend", this_player()));
        return 1;
     }

short(){ return "Svirfneblin entrance"; }
long(){
     write("You have stumbled upon a secret city of Svirfneblin gnomes!\n");
     write("As the inhabitants scurry for cover, the guard challenges you.\n");
     write("You ought to show your credentials to him.\n");
     write("There are four obvious exits: north, south, east, and west.\n");
}

down(){
     if(show == 1){
    call_other(this_player(), "move_player",
     "down#players/deathmonger/UNDERDARK/svirf/hq");
     return 1;
    }
    write("What?\n");
    return 1;
}
not(){
    write("You don't think the guards gonna let you among the women and\n");
    write("children, do you?\n");
return 1;
}
north(){ 
    call_other(this_player(), "move_player",
     "north#players/deathmonger/UNDERDARK/tunnel13");
return 1;
}

show(){
     write("You show your symbol to the guard.\n");
     write("The guard says: Welcome! Please use the down exit to talk\n");
     write("with our leader.\n");
     show = 1;
     return 1;
}
