#include "/players/guilds/bards/def.h"
#include "/players/guilds/bards/lib/ansi_pad.h"

status main(string str) {
  object ob;
  status room;
  string AAA, CCC, EEE, WIMP;
  int health, wc, DDD, ac;
  int al;
  string aln;
  string *ratings;
  ratings = ({ BLU+"Low",            
               HIB+"Below Average",  
               GRN+"Average",        
               HIG+"Above Average",  
               HIY+"High",           
               RED+"Very High",      
               HIR+"Extreme" });     
  

  if (spell(-185, 4, 30) == -1)
    return 0;
  if (!str) {
    ob=ENV;
    room=1;
  } else {
    ob = present(str, environment(TP));
    if (!ob)
      FAIL("Your target is not here.\n");
    if ((ob->query_level()) > 19 && ob->is_player())
      FAIL("Your mind can not grasp the knowledge of " + NAME(ob) + ".\n");
  }
  write("You play the Song of Knowledge...\n");
  say(tp +" plays a complex song on "+POSS(TP)+ " " +INST+".\n");
  if(room) {
    write("You send your magic out into your surroundings, seeking knowledge.\n");
    if((string)ob->realm()=="NT")
      write("You cannot use teleportation magic here.\n");
    if((string)ob->realm()=="LA")
      write("Following is not allowed here.\n");
    if(ob->query_no_fight())
      write("Strong magic prevents fighting here.\n");
    if(ob->query_property("fight_area") || TP->query_fight_area())
      write("Other denizens of the Realms may attack you freely here.\n");
    if(ob->query_property("spar_area") || TP->query_spar_area())
      write("This is an area for practice fights between denizens of the Realms.\n");
    write("Your knowledge-seeking magic returns to you.\n");
  } else {
    if (ob->query_wimpy()) {
      WIMP = "yes";
    } else {
      WIMP = "no";
    }
  
    al = (int)ob->query_alignment();
    if(al >= 0){
      switch(al){
       default:         aln = "White Lord"; break;
       case 321..639:   aln = "Paladin";    break;
       case 161..320:   aln = "Crusader";   break;
       case 81..160:    aln = "Good";       break;
       case 41..80:     aln = "Honorable";  break;
       case 0..40:      aln = "Neutral";    break;
       }
     }
    if(al < 0){
      al = - al;     
     switch(al){
       default:         aln = "Lord of Evil"; break;
       case 321..639:   aln = "Black Knight";    break;
       case 161..320:   aln = "Infamous";   break;
       case 81..160:    aln = "Evil";       break;
       case 41..80:     aln = "Malicious";  break;
       case 1..40:      aln = "Neutral";    break;
       }
    } 
    
  
    write(HIM+"/---------------------------------------------------------------------\\\n");
    write("|               " + NORM + ansi_pad(""+ob->short(), 52) +HIM+ "  |\n");
    write(
    "+----------------------------------+----------------------------------+\n");
    write("|  "+HIW+" Race:       " +NORM+ pad(""+ob->query_race(), 19) +
          HIM+"|"+HIW+" Is wimpy:    " +NORM+ pad(WIMP, 18) + HIM+"  |\n");
    write("|   "+HIW+"Level:      " +NORM+ pad(""+ob->query_level(), 19) +
          HIM+"|"+HIW+" Extra_level: " +NORM+ pad(""+ob->query_extra_level(), 18) +
          HIM+"  |\n");
    write("|   "+HIW+"Gender:     " + NORM+pad(""+ob->query_gender_string(), 19) +
          HIM+"|"+HIW+" Alignment:   " + NORM+pad(aln, 18) + HIM+"  |\n");
    write(
    "+----------------------------------+----------------------------------+\n");
    wc = (int)ob->query_wc();
    wc = (wc/5)*5;
    wc += (wc/5) - random (wc*2/5);
    write("|  "+HIW+"Weapon: "+SCALE->show_scale(wc,60,54)+HIM+"   |\n");
    ac = (int)ob->query_ac();
    ac = (ac/5)*5;
    ac += (ac/5) - random (ac*2/5);
    write("|  "+HIW+"Armor:  "+SCALE->show_scale(ac,30,54)+ HIM+"   |\n");
    write(
    "|                                                                     |\n");
    write("|  "+HIW+"Health: " + SCALE->show_scale(ob->query_hp(),ob->query_mhp(),54)+HIM+"   |\n");
    write("\\---------------------------------------------------------------------/\n"+NORM);
  }
  
  call_other(TP, "add_spell_point", -30);
  return 1;
}
