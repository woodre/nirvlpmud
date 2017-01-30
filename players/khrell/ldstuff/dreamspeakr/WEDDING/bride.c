#include "/players/dreamspeakr/closed/ansi.h"
#define PATH "/players/dreamspeakr/WEDDING/"

inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = HIR+"Bride's Dressing Room"+NORM;
long_desc =
    "\n"+
    "     A small sign hangs above the mirrored vanity sitting in \n"+
    "the corner.  Directly in front of the vanity, a comfortable \n"+
    "looking chair awaits the bride.  Lush red carpet lay underfoot\n"+
    "with decorations of golden cherubs.  \n"
;


items = ({
    "sign","Maybe you should read it",
    "mirror","A large framed mirror atop the vanity with small cherubs etched\n"+
             "into the corners of it with intriquite detail",
    "vanity","It appears to be made of solid gold, beautiful in every detail",
    "corner","There is a vanity sitting in it",
    "chair","A high backed chair covered in red velvet to make a comfortable \n"+
            "place to sit while getting ready for your big day",
    "carpet","Thick red carpet cushions your feet",
    "cherubs","Small children weaved into the carpet.  Golden in color and \n"+
              "carrying a bow and arrow",
    "decorations","Small golden cherubs decorate the floor beneath your feet",
});

dest_dir = ({
    PATH+"chapel.c","chapel",
});

}
init(){
    ::init();
    add_action("order");
    add_verb("rent");
    add_action("read");
    add_verb("read");
    add_action("sit"); add_verb("sit");
}
order(str)
{

    if (!str) {
       write("Order what ?\n");
       return 1;
    }
    if (str !="attire"){
       write("You can't buy that here!");
       return 1;
    }
    if (call_other(this_player(), "query_money", 0) < 2000) {
        write("That costs 2000 gold coins, which you don't have.\n");
	return 1;
    }
    call_other(this_player(), "add_money", - 2000);
    write("You pay 2000 gold for your wedding attire.\nA maid enters the room and lays your attire in the room for \nyour retrieval.\n");
    say(call_other(this_player(), "query_name", 0) + " orders her wedding attire.\n");
    if (str == "attire") {
          move_object(clone_object("/players/dreamspeakr/WEDDING/OBJ/wblue.c"), this_object());
          move_object(clone_object("/players/dreamspeakr/WEDDING/OBJ/wborrow.c"), this_object());
          move_object(clone_object("/players/dreamspeakr/WEDDING/OBJ/wbouquet.c"), this_object());
          move_object(clone_object("/players/dreamspeakr/WEDDING/OBJ/wdress.c"), this_object());
          move_object(clone_object("/players/dreamspeakr/WEDDING/OBJ/wnew.c"), this_object());
          move_object(clone_object("/players/dreamspeakr/WEDDING/OBJ/wold.c"), this_object());
          move_object(clone_object("/players/dreamspeakr/WEDDING/OBJ/wshoes.c"), this_object());
          move_object(clone_object("/players/dreamspeakr/WEDDING/OBJ/wveil.c"), this_object());
    }
    return 1;
}
read(str){
    if (!str) {
       write("What would you like to read?\n");
       return 1;
    }
    if (str == "sign") {
       write("\n");
       write(HIR+"  .:*"+HIW+"~"+HIR+"*:._.:*"+HIW+"~"+HIR+"*:._.:*"+HIW+"~"+HIR+"*:._.:*"+HIW+"~"+HIR+"*:._.:*"+HIW+"~"+HIR+"*:._.:*"+HIW+"~"+HIR+"*:._.:*"+HIW+"~"+HIR+"*:.\n"+NORM);
       write("\n");
       write(HIW+"     Congratulations on your up and coming marriage!  \n"+NORM);
       write(HIW+"     For your special moment with your loved one you  \n"+NORM);
       write(HIW+"     can '"+HIR+"rent"+HIW+"' a very nice '"+HIR+"attire"+HIW+"'.  There is a one \n"+NORM);
       write(HIW+"     time fee of 2000 coins in which you will find the \n"+NORM);
       write(HIW+"     following items:\n"+NORM);
       write("\n");
       write(HIW+"     A beautiful white wedding dress, lace veil, white  \n"+NORM);
       write(HIW+"     satin shoes, a bouquet of roses, something old, \n"+NORM);
       write(HIW+"     something new, something borrowed, something blue,\n"+NORM);
       write(HIW+"     and even a penny for your shoe.\n"+NORM);
       write("\n");
       write(HIW+"     Take the time to check these items out after your  \n"+NORM);
       write(HIW+"     purchase, as you might find that they have some \n"+NORM);
       write(HIW+"     special features that can be used to make your day \n"+NORM);
       write(HIW+"     more special!\n"+NORM);
       write("\n");
       write(HIW+"     When you leave the area these items will be returned\n"+NORM);
       write(HIW+"     for the next ceremony.\n"+NORM);
       write("\n");
       write(HIW+"     Once you are finished preparing for your ceremony \n"+NORM);
       write(HIW+"     please proceed to the chapel where Hera will guide \n"+NORM);
       write(HIW+"     you on your new path in life.\n"+NORM);
       write("\n");
       write(HIR+"  .:*"+HIW+"~"+HIR+"*:._.:*"+HIW+"~"+HIR+"*:._.:*"+HIW+"~"+HIR+"*:._.:*"+HIW+"~"+HIR+"*:._.:*"+HIW+"~"+HIR+"*:._.:*"+HIW+"~"+HIR+"*:._.:*"+HIW+"~"+HIR+"*:.\n"+NORM);
       return 1;
    }
}
sit(str){
  if(!str){
    return 0;
  }
  if(str == "chair"){
    write("You sit down in the chair, resting for a moment or two.\n");
    return 1;
  }
}
query_no_fight() { return 1; }

realm() { return "NT"; }
