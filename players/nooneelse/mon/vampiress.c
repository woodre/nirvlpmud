/*
 vampiress.c
*/

/*
  I set the vampiress's hp up by 9000 to take care of the phony death.
  Now, if she falls below 9000 hp, it'll act like she died.
*/

#define INTERVAL_BETWEEN_HEALING	30
#define WEAPON_CLASS_OF_HANDS           (22)
#define ARMOR_CLASS_OF_BARE             7
#define KILL_NEUTRAL_ALIGNMENT		10
#define ADJ_ALIGNMENT(al)		((-al - KILL_NEUTRAL_ALIGNMENT)/4)
#define MAX_LIST			20
#define NAME_OF_GHOST			"luminous blue mist"

inherit "players/nooneelse/mon/nooneelse_monster";

object obj, who, garlic, cross, where, vampiress_corpse, vampiress_enemy;

string str, find_item;

int hp_now, n, heal_amount, garlic_present, staked, death_time, resurrect_time;
int random_pick, kill_flag, r, cross_present, counter, no_chase_em, caught_em;
int sent_to_redentry, sent_to_sunroom, sent_to_kitchen;


init() {
  ::init();

  set_heart_beat(1);
}


reset(arg) {
  if (sizeof(explode(file_name(this_object()),"#"))==1) return;
  if (arg) return;
  ::reset(arg);

  set_short("A young woman");
  set_long("She is an extremely attractive young woman who seems menacing.\n");
  set_name("carmilla");
  set_alias("woman");
  set_race("vampire");
  set_alt_name("nooneelsevampiress");
  set_level(15);
  set_hp(9900); /*900*/
  set_wc(22);
  set_ac(9);
  set_ep(0);
  set_al(-500);
  set_whimpy(1);
  set_aggressive(0);
  set_spell_mess1("A blue flame shoots from her eyes.");
  set_spell_mess2("A blue flame shoots from her eyes.");
  set_spell_dam(22);
  set_chance(8);
  enable_commands();
  set_heart_beat(1);
  death_time=0;
  no_chase_em=0;
  vampiress_enemy=0;
}

heart_beat() {
     ::heart_beat();

     check_hit_points();
     check_for_cross_or_garlic();
     chase_a_player();

/* did a player die?  if yes, add code to screw with him/her/it...
   change alignment, title, ? */

}


/* if the vampire is low on hit points... */
check_hit_points() {
     if (!vampiress_enemy) vampiress_enemy=this_object()->query_attack();
     hp_now=this_object()->query_hp();
     if (hp_now <= 9000) {
       kill_this_vampire(); /* if hp <= 9000 act like it died. */
       return;
     }
     n=random(100);
     if (hp_now <= 9108 && n <= 20 && !sent_to_redentry) { /*108=12%*/
        say("\nShe yells: 'Vanish loathsome creature!'\n");
        call_other("players/nooneelse/redentry", "???", 0);
        tell_object(vampiress_enemy,
                    "You sense a change in your surroundings...\n\n");
        end_the_fight();
        no_chase_em=1;
        move_object(vampiress_enemy, "players/nooneelse/redentry");
        command("look", vampiress_enemy);
        vampiress_enemy=0;
        sent_to_redentry=1;
        return 0;
     }
     if (hp_now <= 9180 && 20 > random(100) && !sent_to_sunroom) { /*180=20%*/
        say("\nShe screams: 'Be gone mortal!'\n");
        call_other("players/nooneelse/red/sunroom", "???", 0);
        tell_object(vampiress_enemy,
                    "You sense a change in your surroundings...\n\n");
        end_the_fight();
        no_chase_em=1;
        move_object(vampiress_enemy, "players/nooneelse/red/sunroom");
        command("look", vampiress_enemy);
        vampiress_enemy=0;
        sent_to_sunroom=1;
        return 0;
     }
     if (hp_now <= 9360 && 20 > random(100) && sent_to_kitchen) { /*360=40%*/
        say("\nShe shouts: 'Leave me alone mortal!'\n");
        call_other("players/nooneelse/red/kitchen", "???", 0);
        tell_object(vampiress_enemy,
                    "You sense a change in your surroundings...\n\n");
        end_the_fight();
        no_chase_em=1;
        move_object(vampiress_enemy, "players/nooneelse/red/kitchen");
        command("look", vampiress_enemy);
        vampiress_enemy=0;
        sent_to_kitchen=1;
        return 0;
     }
     if (hp_now <= 9108) { /*108=12%*/
        say("\nShe hisses: 'You will pay for this outrage mortal!'\n\n");
        run_away();
        no_chase_em=1;
        return 0;
     }
}

/* is there garlic present? */
/* is there a cross here? */
check_for_cross_or_garlic() {
  garlic_present=0;
  find_item="garlic";
  garlic_present=look_for_something(find_item);
  cross_present=0;
  find_item="cross";
  cross_present=look_for_something(find_item);
  if (!garlic_present && cross_present) {
    set_wc(13);
    set_ac(7);
    set_spell_dam(13);
    heal_amount=1;
  }
  if (garlic_present && !cross_present) {
    set_wc(18);
    set_ac(8);
    set_spell_dam(18);
    heal_amount=2;
  }
  if (garlic_present && cross_present) {
    set_wc(11);
    set_ac(6);
    set_spell_dam(11);
    heal_amount=0;
  }
  if (!garlic_present && !cross_present) {
    set_wc(25);
    set_ac(10);
    set_spell_dam(25);
    heal_amount=3;
  }
  heal_self(heal_amount);
}


/* is anyone still here?  if no, chase one... :) */
chase_a_player() {
  if (caught_em) {
    counter++;
    if (counter == 3) {
      no_chase_em=1;
      go_home();
      caught_em=0;
      counter=0;
      return;
    }
  }
  if (test_if_any_here() ||
      !vampiress_enemy ||
      no_chase_em ||
      environment(vampiress_enemy)=="players/nooneelse/red/cellar8")
    return;
  transfer(this_object(), environment(vampiress_enemy));
  end_the_fight();
  say("You hear a booming laugh and turn around to see the vampire leering "+
      "at you.\n");
  caught_em=1;
  counter=0;
}

/* go home after a few seconds. */
go_home() {
  say("She laughs at your puny efforts and leaves.\n");
  call_other("players/nooneelse/red/cellar8", "???", 0);
  move_object(this_object(), "players/nooneelse/red/cellar8");
}

/* make both stop fighting */
end_the_fight() {
  obj=first_inventory(environment(this_object()));
  while (obj) {
    obj->stop_fight();
    obj->stop_fight();
    obj->stop_hunter();
    obj=next_inventory(obj);
  }
}

look_for_something(find_item) {
  who=first_inventory(environment(this_object()));
  while (who) {
    if(who != this_object())
      if (living(who) && present(find_item, who)) return 1;
    who=next_inventory(who);
  }
  return;
}

init_command(cmd) { command(cmd); }

set_random_pick(r) {random_pick=r; }

query_undead() { return 1; }

kill_this_vampire() {
/* make sure there's not another one laying around somewhere */
  vampiress_corpse=present("corpse of vampiress");
  if (vampiress_corpse) destruct(vampiress_corpse);
/* need my own special corpse for my vampires */
  vampiress_corpse=clone_object("players/nooneelse/mon/vampiress_corpse");
  vampiress_corpse->set_enemy(vampiress_enemy);
  move_object(vampiress_corpse, environment(this_object()));
  say("Carmilla dies.\n");
  write("You killed Carmilla.\n");
  destruct(this_object());
  return 1;
}
