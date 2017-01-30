#include "../DEFS.h"

/* defines */
#define SAVE        "players/dune/closed/guild/daemons/poolCoins"
#define HEAL_POOL   "players/dune/closed/guild/rooms/archives"

/* globals */
int credits;
static status loaded;


void saveDaemon()
{
  save_object(SAVE);
}


void loadDaemon()
{
  restore_object(SAVE);
}


void loadCheck()
{
  if (!loaded)
  {
    loadDaemon();
    loaded = 1;
  }
}


int depositCredits(int amount)
{
  /* 5% service charge */
  loadCheck(); 
  if (amount <= 0)      amount = 0;
  else if (amount < 40) amount -= 1;
  else                  amount = (amount * 95) / 100;
  credits += amount;
  saveDaemon();
  return amount;
}


int withdrawCredits(int amount)
{
  loadCheck(); 
  if (amount > credits) amount = credits;
  if (amount < 0)       amount = 0;
  credits -= amount;
  saveDaemon();
  return amount;
}


int query_credits() { loadCheck(); return credits; }


/* Still working on heal depositing.. Dune
   This is just a placeholder. Eventually the heal
   will be transformed into a different heal.
void depositHeal(object ob)
{
  move_object(ob, HEAL_POOL);
  tell_room(HEAL_POOL, 
    "A "+capitalize(ob->query_name())+
    " appears out of CyberSpace.\n");
}
*/
