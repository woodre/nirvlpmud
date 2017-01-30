/*
 * Ascension, by Dune and Snow
 * Monster summoning control file
 * To add a new monster:
 *    1) increase NUM_HELPERS
 *    2) add monster to #define index, depending upon monster strength
 *    3) add monster to summon_chance, giving each being a chance %
 *    4) add monster to clone_spirit_helper, adding clone and room msg
 */
#include "../def.h"

/* total number of monsters in index */
#define NUM_HELPERS     2

/* Monster Index: higher index goes to stronger monsters */
#define KIRIN           0
#define TITAN           1

int number_of_helpers() { return NUM_HELPERS; }


int summon_chance(int helper, string being, string skin) {
  /* calling function loops through monster index, checking
     for the below summoning chances on each monster, beginning
     with monster index 0; if check succeeds, calling function calls 
     clone_spirit_helper and exits loop */
  int deva, planetar, solar, mod;
  switch(helper) {
    /* devas: clone lower monsters easier, higher monsters harder
       solars: clone lower monsters harder, higher monsters easier
       chance to clone monsters generally increases from deva to solar */
    case KIRIN: deva=5;   planetar=10;  solar=15;  break;
    case TITAN: deva=45;  planetar=35;  solar=25;  break;
    default   : deva=100; planetar=100; solar=100; break;
    }
  /* easier to clone monsters from silver to platinum skin type */
  mod = 0;
  if(skin == "gold")     mod = 5;
  if(skin == "platinum") mod = 10;

  if(being == "Deva")     return (deva - mod);
  if(being == "Planetar") return (planetar - mod);
  return (solar - mod);
  }


clone_spirit_helper(int helper, object ob) {
  /* this function clones the actual monster
     note: the clone variable should be set to 1 if a monster is
           to be cloned; if the clone variable is 0, the alternative
           effect should be written in the corresponding case statement
           (i.e. strengthen already existing monster instead of cloning
                 a new one) */
  string msg, helpname;
  status clone;
  object help;
  clone = 0;
  switch(helper) {
    case KIRIN: clone = 1;  helpname = "kirin";
                msg = "A Ki-Rin comes out to help "+OPN+".\n";
                break;
    case TITAN: clone = 1;  helpname = "titan";
                msg = "A big Titan comes to help "+OPN+".\n";
                break;
    }
    if(clone) {
      help = clone_object(SUMMONDIR+helpname+".c");
      move_object(help, environment(ob));
      help->set_owner(ORN);
      help->reset(0);
      }
    tell_room(environment(ob), "\n"+msg+"\n");
}
