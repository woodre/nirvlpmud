#include <ansi.h>

#define ORIFICES ({"eye","ear","nose","mouth"})

int active;
string possessive;
string objective;
string pronoun;
string name;

id(string str) {
   return str == "scroll" || str == "insanity" || str == "scroll of insanity";
}
short() {
	return "A scroll of disturbing things";
}

init() {
  add_action("read_scroll","read");
}

string random_orifice() {
  return ORIFICES[random(sizeof(ORIFICES))];
}

long() {


  write("You focus your will and "+GRY+"black tentacles"+NORM
    + " rise from the ground under "+name+ "'s feet and wind themselves around "+possessive+" legs, torso, and "
    + "throat, constricting tightly. A throaty laugh echoes from the shadows and a pair of "
    + RED+"dark red"+NORM+" eyes flash briefly in the "+GRY+"darkness"+NORM+", threatening your sanity.\n\n"

    + "A "+GRY+"tentacle"+NORM+" worms its way into "+name+"'s " + random_orifice() 
    + ". It comes out "+RED+"oozing"+NORM+" with "+HIR+"blood"+NORM+" and "+capitalize(name)+" gibbers insanely.\n\n"

    + "A cluster of "+GRY+"tentacles"+NORM+" erupts from the center of " 
    + name+"'s forehead and wave wildly about. The tentacles "
    + "are tipped with "+HIR+"blood"+NORM+" and "+GRY+"grey matter"
    + NORM+". "+name+" shrieks in horror!\n\n"

    + "NOTE: 'read scroll' for the last ones, I got too long for write() apparently."

  );
}

int read_scroll(string str) {
  if( !str || !id(str) )
    return 0;

  write(
    "A long ropelike "+GRY+"tentacle"+NORM+" squirms its way down " 
    + name+"'s torso and slides through gaps in "
    + ""+possessive+" rib cage to wrap tightly around " +possessive+" "
    + HIR+"heart"+NORM+". It squeezes tightly and " + name
    + "'s face turns a sickly "+HIW+"pale"+NORM+" color.\n\n"

    + "A "+HIG+"gaping maw"+NORM+" opens beneath "+name+"'s "
    + "feet, and "+pronoun+" is sucked in up to "+possessive+" knees. "+capitalize(pronoun)+" claws "+possessive+" way out "
    + "seconds before it closes around "+objective+". \n\n"

    + name+" doubles over in pain, retching horribly. A "+GRY+"tentacle "+NORM
    + "writhes out from deep inside "+name+"'s belly, covered with "+GRN+"bile "+NORM
    + "and "+YEL+"vomit"+NORM+". "+name+" heaves and chokes, clawing at "+possessive
    + " own face in desperation, leaving "+RED+"deep scratches"+NORM+" down his neck.\n\n"

    );
  return 1;
}


reset(arg){
  possessive = this_player()->query_possessive();
  objective = this_player()->query_objective();
  pronoun = this_player()->query_pronoun();
  name = this_player()->query_name();
  if(arg) return;
}

get() { return 1; }
drop() { return 0; }
query_weight() { return 0; }
query_value() { return 0; }
