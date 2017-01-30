#include "/players/languilen/closed/ansi.h"
#include "../paths.h"
#define TPN this_player()->query_name()
#define TP this_player()
inherit "room/room";

int paid;
string cranee;

reset(arg) {
     if(arg) return;
     set_light(1);
     paid = 0;

     short_desc = "The Crane Game";
     long_desc =
"    There is a large boxlike object here standing almost six feet high.\n\
It has four legs on the bottom and the top is made of glass so you can\n\
see the toys inside.  There are strange rails running along the inside\n\
of the glass up at the top on which is suspended a small three pronged\n\
gadget.  The lower portion is solid and has some sort of panel with a\n\
stick and a slot about the size of a coin.\n";

     items = ({
     "glass","The smooth clear glass prevents you from getting to the toys inside",
     "rails","The rails have thin wires attached to pullies at the ends of them",
     "wires","The wires are attached to the gadget and run along the rails to the pullies",
     "gadget","The gadget's three prongs are curved inward resembling an inverted grappling\n\
hook.  It looks as if it could be moved along the rail by the wires and pullies",
     "panel","The panel has an upright stick mounted on it with arrows pointing in all\n"+
          "directions.  There is a small slot next to it about the size of a coin",
     "toys","Piled high inside the glass are all manner of stuffed toys.  You can see:\n\
A Huggly teddy bear   A pretty kitty cat  A sleek black panther\n\
A wackey monkey       A fuzzy koala bear  A big gorrilla\n\
A penguin             A girraffe          A furry ferret\n\
An elephant           A bunny             A floppy eared dog\n\
A harry rat           A lion              A fierce tiger\n\
A hoot owl            A HUGE "+ MAG +"pink panther"+NORM,
     "stick","This must be how you 'aim at <prize>'",
     "slot","the slot is marked 'insert' 25 'coins'",
     "legs","Short, sturdy legs that hold the crane game slightly off the ground",

});

dest_dir = ({ AREA+"gameroom.c","out", });

}
init(){
    ::init();
    add_action("insert_coins","insert");
    add_action("aim_crane","aim");
}
insert_coins(str){
    if(!str){
       notify_fail("What do you want to put in the slot?\n");
       return 0;
    }
    if( str != "coins" ){
       notify_fail("Only coins will fit in the slot!\n");
       return 0;
    }
    if(this_player()->query_money() <25) {
           notify_fail("You do not have enough money to play this game! \n");
           return 0;
        }
    if( paid ){
       if( present(lower_case(cranee)) ){
          write(cranee + " is already playing!  You'll have to wait...\n");
          return 1;
       }
       write("Someone seems to have left a credit in the machine!\n");
       cranee = (string)TPN;
       return 1;
    }
    write("You put the money in the machine and it starts to hum softly.\n");
    say( TPN + " puts some coins in the machine and it begins to hum softly.\n");
    TP->add_money(-25);
    paid = 1;
    cranee = (string)TPN;
    return 1;
}
aim_crane(str){
    object new;
    string toy;
    string *toys;
    string *pre_adj;
    toys = allocate(17);
    pre_adj = allocate(17);
    pre_adj = ({ "A HUGE", "A cuddly", "A wacky", "A sharply dressed", "An", "A harry", "A hoot", "A pretty kitty", "A fuzzy",
                 "A long necked", "A cotton tailed", "A cowardly","A sleek black", "A big", "A furry", "A floppy eared", "A fierce" });
    toys = ({ "pink panther", "bear", "monkey", "penguin", "elephant", "rat", "owl", "cat", "koala",
              "girraffe", "bunny", "lion", "panther", "gorrilla", "ferret", "dog", "tiger" });
    if( !paid || (string)TPN != cranee ){
       write("The machine won't work without putting money in it first!\n");
       return 1;
    }
    if( !str ){
       notify_fail("You must aim the crane at the toy you want!\n");
       return 0;
    }
    if( sscanf(str,"at %s",toy) == 1 ){
       if( member_array(toy, toys) < 0 ){
          write("That's not in the box!\n");
          return 1;
       }
       if( member_array(toy, toys) < 1 ){
          if( !random(20) ){
             new = clone_object("/obj/treasure.c");
             new->set_id(toy);
             new->set_name(toy);
             new->set_alias("toy");
             new->set_short( pre_adj[0] + " " + toy );
             new->set_long("This large stuffed toy is a funtastic prize.  It eminates a\n\
comforting, careing warmth that makes you feel good inside.\n\
It would make a great gift or you could keep it for yourself.\n");
             new->set_value(200);
             move_object(new,this_player());
             write("You grabbed the pink panther!!!\n");
             say( TPN + " tried for the " + toy + " and got it!\n");
             paid = 0;
             return 1;
          }
          write("You just missed the pink panther...sorry, try again!\n");
          say( TP->query_name() + " tried for the " + toy + " but missed.\n");
          paid = 0;
          return 1;
       }
       if( !random(5) ){
          new = clone_object("/obj/treasure.c");
          new->set_id(toy);
          new->set_name(toy);
          new->set_alias("toy");
          new->set_short( pre_adj[member_array(toy, toys)] + " " +toy );
          new->set_long("An amazingly adorable stuffed toy " +toy+ " that seems to emenate\n\
warmth and makes you feel good inside.\n\
It would make a great gift or you could keep it all to yourself.\n");
          new->set_value(50);
          move_object(new, this_player());
          write("Congratulations!  You got the "+toy+"!!!\n");
          say( TP->query_name() + " tried for the " + toy + " and got it!\n");
          paid = 0;
          return 1;
       }
       write("You just missed the "+toy+"...Try again.\n");
       say( TP->query_name() + " tried for the " + toy + " but missed.\n");
       paid = 0;
       return 1;
    }
    notify_fail("Usage: aim at <toy>.\n");
    return 0;
}
realm(){ return "NT"; }
