inherit "/obj/monster";

void reset(status arg) {
  ::reset(arg);

  if (arg)
    return;

  set_name ("A daddy-long-legs");
  set_short("Daddy-Long_legs");
  set_race("spider");
  set_long("\
This is a huge Daddy-Long-Legs.  He's not quite as tough as Spyder, but \
he's still to be feared.\n");
  set_level(5);
  set_ac(2);
  set_wc(22);
  set_hp(10000);
  set_gender("creature");
  set_al(0);
}

void attack_special() {
  object mon;

  /* This will move a mob that is aggressive to the person that's 
   * tanking the big mob himself into the room, and set him to attack
  */

  mon = clone_object("/open/fred/ferret.c");
  move_object(mon,environment(this_object()));
  tell_object(attacker_ob,"A big fat nasty cousin of Spyder just walked in!\nWho's your daddy now, bitch!\n");
  say("Another of Spyder's cousins just charged in here!\n", attacker_ob);
  mon->attacked_by(attacker_ob);
}


heart_beat(){
  ::heart_beat();

  if(!environment()) 
    return ;

  if (!attacker_ob) 
{
say("attacker_ob not found\n");
    return ;
}

  if ((random(100)) < 10) /* gives it a 10% chance of occuring */
    attack_special();
}
