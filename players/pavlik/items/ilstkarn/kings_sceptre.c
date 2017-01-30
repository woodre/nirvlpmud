#include <ansi.h>
#define ME capitalize(this_player()->query_name())
#define IT capitalize(ob->query_name())
#define SCEP CYN+"the "+HIC+"Sceptre"+NORM+CYN+" of "+HIC+"Secezeran"+NORM

/*
 * This is a quest item that can only be gotten once per reboot.
 * The player must kill several powerful monsters and retrieve
 * 2 unique items before they can obtain this object.
 * It is a very powerful healing tool for a player, including a
 * single chance at resurrection.
 *
 * The powers are documented throughout this code.  Please read
 * carefully and email Pavlik if you have any questions.
 */

/* Current number of charges */
int charges;

/* Max number of charges the sceptre can have.  This value can
 * be reduced by some of the sceptres functions */
int MAX;

reset(arg){
  if(arg) return;
  charges = 4+random(5);	/* don't start at max charges */
  MAX = 10;
  call_out("recharge", 50);
}

id(str) {
  return str == "sceptre" || str == "kings_sceptre";
}

short() {
  return SCEP;
}

long(){
  int i;
  write(
  "A good and just King used to rule over the land with this mighty\n"+
  "Sceptre.  The golden rod is said to have cured the injured and\n"+
  "performed miracles on the dying.  The good king would wave this\n"+
  "godly sceptre over a man and cure him of all illness.  The long\n"+
  "golden shaft radiates warmth and light.\n");

  /* charge meter */
  write(HIC+"["+NORM);
  for(i=0; i<MAX; i++) {
    if(i < charges) write(HIC+"="+NORM);
    else write(CYN+"-"+NORM);
  }
  write(HIC+"]\n"+NORM);

  return;
}

get() {
  return 1;
}

query_weight() {
  return 2;
}

query_value() {
  return 50000;      /* make sure the items is dested by shops */
}

query_save_flag() {
  return 1;
}

query_charges(){ return charges; }

add_charges(i){ 
  charges += i;
  if(charges > MAX) {
    charges = MAX;
  }
  if(charges <= 0) {
    charges = 0;       /* if we drain all the charges then the MAX */
    MAX--;             /* points will drop */
  }
}

/*
 * The Sceptre will slowly recharge itself if it is being held by
 * a player.  No charges are regained if not held by a player
 */
recharge() {
  /* don't recharge if not being held by a player */
  if(!environment()->is_player()) {
    call_out("recharge", 180);
    return 1;
  }
  if(!random(6)) {
     add_charges(2);     /* chance for a super recharge */
  }
  else {
     add_charges(1);     /* otherwise add 1 charge */
  }
  if(environment()) tell_object(environment(),
  SCEP+" pulses with energy.\n");
  call_out("recharge", 180+random(540));  /* charge every 3-12 min */
  return 1;
}

init() {
  if(environment(this_object()) == this_player())
    add_action("wave_sceptre","wave");
}

/*
 * This is the main function.  The results depend on what
 * the sceptre is being waved at.
 */
wave_sceptre(str) {
  string who, tmp;
  object ob, crown;

  if(sscanf(str, "sceptre %s %s", tmp, who)==2) {
    ob = present(who, environment(this_player()));
    /*
     * If no such object then just emote.
     */
    if(!ob) {
      write("You wave the golden sceptre in the air.\n");
      say(ME+" waves a golden sceptre in the air.n");
      return 1;
    }

    /*
     * If not a living object then just emote.
     */
    if(!living(ob)) {
      write("You wave the golden sceptre over "+ob->short()+".\n");
      write("Nothing special seems to be happening...\n");
      say(ME+" waves a golden sceptre over "+ob->short()+".\n");
      return 1;
    }

    crown = present("kings_crown", this_player());
    /*
     * Item doesn't work without the King's Crown.
     */
    if(!crown || !crown->query_worn()) {
      write(" ... the Sceptre is nearly useless without the King's Crown ...\n");
      write("You wave the golden sceptre over "+IT+".\n");
      write("Nothing special seems to be happening...\n");
      say(ME+" waves a golden sceptre over "+IT+".\n");
      return 1;
    }

    /*
     * Doesn't do anything if all the charges have been used.
     */
    if(charges <= 0) {
      write(" ... the Sceptre is presently out of charges ...\n");
      write("You wave the golden sceptre over "+IT+".\n");
      write("Nothing special seems to be happening...\n");
      say(ME+" waves a golden sceptre over "+IT+".\n");
      return 1;
    }

    /*
     * If we are in combat with the object then cast a combat spell.
     */
    if(this_player()->query_attack() == ob) {
      write("You wave the golden sceptre over "+IT+".\n");
      say(ME+" waves a golden sceptre over "+IT+".\n");
      do_harm(ob);     /* see the do_harm fucntion below */
      return 1;
    }

    /*
     * If the object is a dead player then ressurrect him.
     */
    if(ob->query_ghost()) {
      do_ghost(ob);    /* see the do_ghost function below */
      return 1;
    }

    /*
     * Otherwise we heal the object thouroughly.
     */
    write("You wave the golden sceptre over "+IT+".\n");
    say(ME+" waves a golden sceptre over "+IT+".\n");
    tell_room(environment(this_player()),
    SCEP+" sheds a soft radiant light on "+IT+".\n"+
    "A soft aura of healing encompasses "+IT+"'s body.\n");
    tell_object(ob,
    "Your body feels rejuvanated by the magic of the golden sceptre.\n");
    ob->heal_self(50+random(200));
    add_charges(-2);
    return 1;
  }
}

/*
 * This function is called when the player is in combat with the
 * target.  Results are random, based on the players piety stat.
 * The stronger the results, the more charges used.
 */
do_harm(ob) {
  object obj;
  int i;

  i = random(call_other(this_player(), "query_attrib", "pie"));

  /* can't put the virus on the same target twice */
  if(i >= 17 && present("sceptre_virus", ob)) {
    i = random(17);
  }

  /*
   * Damage type spell - uses 1 charge.
   */
  if(i < 7) {
    tell_room(environment(this_player()),
    "The golden sceptre "+HIY+"blazes with light"+NORM+"!\n"+
    "A "+HIY+"beam of light"+NORM+" shoots from the Sceptre and strikes "+IT+"!\n");
    tell_room(environment(this_player()),
    IT+" is knocked to the ground!\n");
    ob->hit_player(20+random(30));
    add_charges(-1);
  }

  /*
   * Stat Alter type spell: affects either WC or AC. - Users 2 charges
   * There is possibilty for WC and AC to be effected, in which
   * case 4 charges are used.
   */
  else if(i < 13) {
    tell_room(environment(this_player()),
    "A ray of "+HIW+"pure light"+NORM+" streams forth from the Golden Sceptre!\n"+
    "The ray of light strikes "+IT+" and surrounds it in an "+HIW+"aura of Light"+NORM+"!\n");
    if(i == 12 || i < 10) {
      tell_room(environment(this_player()),
      IT+" is partially blinded by the brilliant aura.\n");
      ob->set_wc(ob->query_wc() - 1);
      add_charges(-2);
    }
    if(i > 9) {
      tell_room(environment(this_player()),
      IT+"'s defenses are weakened by the powerful aura of light.\n");
      ob->set_ac(ob->query_ac() - 1);
      add_charges(-2);
    }
  }

  /*
   * A more powerful damage type spell - 3 charges.
   */
  else if(i < 17) {
    tell_room(environment(this_player()),
    ME+" holds the golden sceptre up the sky.  An azure "+HIB+"Bolt of Lightning\n"+NORM+
    "streaks down from the sky!\n"+
    "The "+HIB+"lightning bolt"+NORM+" reflects through the Golden Sceptre and\n"+
    "strikes "+IT+" in the chest!\n");
    tell_room(environment(this_player()),
    IT+" is thrown across the room by the jolt!\n");
    ob->hit_player(50);
    add_charges(-3);
  } else {

    /*
     * Permantely affect target with a HP reducing disease.
     * See ~/items/ilstkarn/sceptre_virus.c for details.
     */
    tell_room(environment(this_player()),
    "A beam of light streams from the Sceptre and strikes "+IT+".\n"+
    IT+" is encompassed in a "+HIG+"sickly green aura"+NORM+".\n");
    write("You have infected "+IT+" with a deadly virus!\n");
    obj = clone_object("players/pavlik/items/ilstkarn/sceptre_virus");
    move_object(obj, ob);
    obj->start_virus(ob);
    add_charges(-4);
  }

  return 1;
}

/*
 * The Sceptre has the ability to resurrect a player from the
 * dead and restore the XP lost due to dying.  This function
 * can only be used once because of the amount of charges
 * needed and the reduction in MAX.
 */
do_ghost(ob) {
  if(!ob->is_player()) {
    write("You wave the golden sceptre over "+IT+".\n");
    write("The Sceptre will not work on "+IT+".\n");
    return 1;
  }
  if(charges < 8) {
    write("The Sceptre is not charged enough to cure "+IT+".\n");
    return 1;
  }
  write("You wave the golden sceptre over "+IT+".\n");
  say(ME+" waves a golden sceptre over "+IT+".\n");
  write(SCEP+" quivers in your hands!\n");
  tell_room(environment(this_player()),
  "The Golden Sceptre bathes "+IT+" in holy light!\n"+
  "A powerful surge of energy brings "+IT+" back to life!\n");
  tell_object(ob,
  "You are resurrected by the powerful magic of "+SCEP+".\n");
  ob->remove_ghost();
  ob->add_exp(ob->query_exp()/4);  /* Restore lost XP */
  add_charges(-(charges-1));       /* Uses all remaining charges */ 
  MAX -= 3;                        /* Lowers MAX by 3 */
  return 1;
}

