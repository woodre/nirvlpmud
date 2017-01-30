#include "/players/guilds/bards/def.h"

status main(string str) {
  object ob;
   int al;
   string aln;
  if (spell(-100, 3, 5) == -1)
    return 0;
  if (!str)
    FAIL("You need a target for the Song of Balance.\n");
  ob = present(str, environment(TP));
  if(!ob)
    FAIL("Your target is not here.\n");
  if (!living(ob))
    FAIL("You must choose a living target.\n");
    
  say(tp + " gazes at " + NAME(ob) + " and " +
    PRON(TP) + " plays an haunting series of fifths upon " +
    POSS(TP) + " " + INST + ".\n");
  write("You gaze at " + NAME(ob) + " and play the Song of Balance.\n");

  al = (int)ob->query_alignment();
  if(al == 0){ aln = "Neutral"; }
  else if(al > 0){
    switch(al){
      default:         aln = HIW+"White Lord"+NORM; break;
      case 321..639:   aln = WHT+"Paladin"+NORM;    break;
      case 161..320:   aln = HIY+"Crusader"+NORM;   break;
      case 81..160:    aln = YEL+"Good"+NORM;       break;
      case 41..80:     aln = HIG+"Honorable"+NORM;  break;
      case 1..40:      aln = "Neutral";    break;
     }
   }
  else if(al < 0){
    al = - al;     
     switch(al){
     default:         aln = HIR+"Lord of Evil"+NORM;    break;
     case 321..639:   aln = RED+"Black Knight"+NORM;    break;
     case 161..320:   aln = HIB+"Infamous"+NORM;        break;
     case 81..160:    aln = BLU+"Evil"+NORM;            break;
     case 41..80:     aln = GRN+"Malicious"+NORM;       break;
     case 1..40:      aln = "Neutral";    break;
     }
   } 

  write(NAME(ob) + "'s soul glows... " +
       PRON(ob)+" has an alignment of "+ aln + ".\n");

  call_other(TP, "add_spell_point", -5);
  return 1;
}
