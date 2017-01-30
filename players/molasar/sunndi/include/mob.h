

/*
 * Alignment adjust routines. These are used to adjust the Sunndi and player alignment
 * when the mob is killed.
 *
 */

int alignment_adjust;

void set_alignment_adjust(int adj);
int query_alignment_adjust();

void set_alignment_adjust(int adj) {
   alignment_adjust = adj;
}

int query_alignment_adjust() {
   return alignment_adjust;
}


/*
 * Override the death string to adjust Sunndi and player alignment.
 *
 * Wrap the external function calls in a catch(). If there's no catch
 * and the external call fails, we're in a bad state. Player heartbeat
 * will break and the monster will never die until destroyed by a Wizard.
 *
 */

death(string str) {
   string err;

   if (attacker_ob) {
      if (err = catch(sunndi_add_player_alignment((string)attacker_ob->query_real_name(), 
         this_object()->query_alignment_adjust()))) {
         catch(log_debug("ERROR: mob/guard.c death()/sunndi_add_player_alignment(): Attacker = " 
            + attacker_ob->query_real_name() + " Error = " + err));
      }
      if (err = catch(sunndi_add_alignment(this_object()->query_alignment_adjust()))) {
         catch(log_debug("ERROR: mob/guard.c death()/sunndi_add_alignment(): Attacker = " 
            + attacker_ob->query_real_name() + " Error = " + err));
      }
   }

   ::death(str);

}


/*
monster_died(object obj) {

  object attacker;
  attacker = (object)obj->query_attack();

  log_debug("Attacker: " + attacker->query_real_name() + "\n");

  if (attacker)
    log_debug(attacker->query_real_name() + " killed " + obj->query_name() + ". AL Adj: " 
       + obj->query_alignment_adjust());

}

*/
