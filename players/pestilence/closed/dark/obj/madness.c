inherit "obj/treasure";

#include <ansi.h>
#include "/players/pestilence/define.h"
#define MAX_TURNS 5
#define ETO environment(this_object())
#define ORIFICES ({"eye","ear","nose","mouth"})


int madness_count;
object room;
string possessive;
string objective;
string pronoun;
string tname;

reset(arg)  {
  if(arg) return;
  set_id("do_madness");
  set_weight(0);
  set_value(0);
  madness_count = 0;
  call_out("do_madness", 5, madness_count);
}

string random_orifice() {
  return ORIFICES[random(sizeof(ORIFICES))];
}

madness_message( int count ) {
  object room;

  room = environment( ETO );
  if( !room )
    return;

  possessive = ETO->query_possessive();
  objective = ETO->query_objective();
  pronoun = ETO->query_pronoun();
  tname = ETO->query_name();

  switch( count ) {
    case 1:
      tell_room( room, HIK+"\nBlack tentacles"+NORM+" wind themselves around "+tname+"'s legs, torso, and\n\
throat, constricting tightly. A throaty laugh echoes from the\n\
shadows and a pair of "+RED+" red eyes"+NORM+" flash briefly in the "+HIK+"darkness"+NORM+",\n\
threatening your sanity.\n\n");
      break;
    case 2:
      tell_room( room, "\n"+tname+" doubles over in pain, retching horribly. A "+GRY+"tentacle"+NORM+"\n\
writhes out from deep inside "+tname+"'s belly, covered with "+GRN+"bile"+NORM+"\n\
and "+YEL+"vomit"+NORM+". " );
      tell_room( room, tname+" heaves and chokes, clawing at "+possessive+" own face in\n\
desperation, leaving "+RED+"deep scratches"+NORM+" down "+possessive+" neck.\n\n");
      break;
    case 3:
      tell_room( room, "\nA "+HIG+"gaping maw"+NORM+" opens beneath "+tname+"'s feet, and "+pronoun+" is sucked in\n\
up to "+possessive+" knees. "+RED+"Blood gushes"+NORM+" gushes from "+possessive+" "+random_orifice()+" as the\n\
pressure builds and "+tname+" begins to "+HIW+"scream incoherently.\n\n"+NORM );
      break;
    case 4:
      tell_room( room, "\nA long ropelike "+GRY+"tentacle"+NORM+" squirms its way down "+tname+"'s\n\
torso and slides through gaps in "+possessive+" rib cage to wrap tightly\n\
around "+possessive+" "+HIR+"heart"+NORM+". It squeezes tightly and "+tname+"'s\n\
face turns a "+YEL+"sickly color.\n\n"+NORM);
      break;
    case 5:
      tell_room( room, "\nA cluster of "+GRY+"tentacles"+NORM+" erupts from the center of "+ tname+"'s\n\
forehead and wave wildly about. The tentacles are tipped with \n\
"+HIR+"blood"+NORM+" and "+GRY+"grey matter"+NORM+". "+tname+" shrieks in horror!\n\n" );
      break;
    default:
      tell_room( room, "\nA "+GRY+"tentacle"+NORM+" worms its way into "+tname+"'s " + random_orifice() + ". It comes out\n\
"+RED+"oozing"+NORM+" with "+HIR+"blood"+NORM+" and "+capitalize(tname)+" gibbers insanely.\n\n"); 
      break;
  }
}

int
do_madness( int count ) {
  if( !ETO )
    return 1;
  if( !living(ETO) )
    return 1;
  if( ETO->is_npc() || interactive(ETO) ) {
    madness_message( count );
    ETO->do_damage(({15 + random(40)}), ({"other|mental"}));
    if( madness_count < MAX_TURNS )
      call_out("do_madness", 5 + (count * 4), ++madness_count);
    else {
      if( environment(ETO) ) {
        tell_room( environment(ETO), ETO->query_name()+" recovers from the grip of Madness.\n");
      }
    }
    return 1;
  }
}

drop() { return 1; }
extra_look() {
  if( madness_count <= MAX_TURNS ) 
    return environment()->query_name()+" is suffering from "+HIR+" m A d N e S s"+NORM;
  return 0;
}
