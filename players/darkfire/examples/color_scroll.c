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


  write(""

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
