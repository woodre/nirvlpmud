/*
 vampire.c
*/

/*
  I set the vampire's hp up by 9000 to take care of the phony death.
  Now, if he falls below 9000 hp, it'll act like he died.
*/

#define INTERVAL_BETWEEN_HEALING	30
#define WEAPON_CLASS_OF_HANDS           (25)
#define ARMOR_CLASS_OF_BARE             10
#define KILL_NEUTRAL_ALIGNMENT		10
#define ADJ_ALIGNMENT(al)		((-al - KILL_NEUTRAL_ALIGNMENT)/4)
#define MAX_LIST			20
#define NAME_OF_GHOST			"luminous red mist"

inherit "players/angel/working_dir/mon/nooneelse_monster";

object obj, who, garlic, cross, where, vampire_corpse, vampire_enemy;

string str, find_item;

int hp_now, n, heal_amount, staked, death_time, resurrect_time;
int kill_flag, cross_present, counter;
int sent_to_redentry, sent_to_sunroom, sent_to_kitchen;
int hammer_present, stake_present, spell_damage;

reset(arg) {
  if (sizeof(explode(file_name(this_object()),"#"))==1) return;
  if (arg) return;
  ::reset(arg);

  set_short("A young man");
  set_long("He is an aristocratic, compelling young man who seems menacing.\n");
  set_name("barnabas");
  set_alias("man");
  set_race("vampire");
  set_alt_name("nooneelsevampire");
  set_level(19);
  set_hp(10100); /*1100*/
  set_wc(25);
  set_ac(17);
  set_ep(0);
  set_al(-700);
  set_whimpy(1);
  set_aggressive(0);
  set_spell_mess1("A red flame shoots from his eyes.");
  set_spell_mess2("A red flame shoots from his eyes.");
  set_spell_dam(25);
  set_chance(8);
  enable_commands();
  death_time=0;
  vampire_enemy=0;
  call_out("check_hit_points", 1);
  call_out("check_for_cross_or_garlic", 1);
}

/* if the vampire is low on hit points... */
check_hit_points() {
  call_out("check_hit_points", 1);
     if (!vampire_enemy) vampire_enemy=this_object()->query_attack();
     hp_now=this_object()->query_hp();
     n=random(100);
if (find_player("nooneelse"))
  if (!vampire_enemy || (!present(vampire_enemy) && counter>=3)) {
    counter=0;
       go_home();
       return;
     }
     if (hp_now <= 9000) {
       kill_this_vampire(); /* if hp <= 9000 act like it died. */
       return;
     }
     if (hp_now <= 9132 && n <= 20 && !sent_to_redentry) { /*132=12%*/
        say("\nHe yells: 'Vanish loathsome creature!'\n");
        call_other("players/nooneelse/redentry", "???", 0);
        tell_object(who,
                    "\nYou sense a change in your surroundings...\n\n");
        end_the_fight();
        move_object(vampire_enemy, "players/nooneelse/redentry");
        command("look", vampire_enemy);
        vampire_enemy=0;
        sent_to_redentry=1;
        return 0;
     }
     if (hp_now <= 9220 && 20 > random(100) && !sent_to_sunroom) { /*220=20%*/
        say("\nHe screams: 'Be gone mortal!'\n");
        call_other("players/nooneelse/red/sunroom", "???", 0);
        tell_object(vampire_enemy,
                    "You sense a change in your surroundings...\n\n");
        end_the_fight();
        move_object(vampire_enemy, "players/nooneelse/red/sunroom");
        command("look", vampire_enemy);
        vampire_enemy=0;
        sent_to_sunroom=1;
        return 0;
     }
     if (hp_now <= 9440 && 20 > random(100) && sent_to_kitchen) { /*440=40%*/
        say("\nHe shouts: 'Leave me alone mortal!'\n");
        call_other("players/nooneelse/red/kitchen", "???", 0);
        tell_object(vampire_enemy,
                    "You sense a change in your surroundings...\n\n");
        end_the_fight();
        move_object(vampire_enemy, "players/nooneelse/red/kitchen");
        command("look", vampire_enemy);
        vampire_enemy=0;
        sent_to_kitchen=1;
        return 0;
     }
     if (hp_now <= 9132) { /*132=12%*/
        counter++;
    say("\nHe hisses: 'You will pay for this outrage mortal!'  and dissolves\n"+
        "into a red mist which quickly fades away.\n\n");
        if (present(vampire_enemy)) run_away();
        return 0;
     }
}

run_away() {
  object here;
  int i, j;

  here = environment();
  i = 0;
  j = random(4);
  while(i<4 && here==environment()) {
    i += 1;
    j += 1;
    if (j > 4) j = 1;
    if (j == 1) command("east");
    if (j == 2) command("west");
    if (j == 3) command("north");
    if (j == 4) command("south");
  }
  if (here == environment())
    say(cap_name + " tried, but failed to run away.\n", this_object());
}

/* is there garlic present? */
/* is there a cross here? */
check_for_cross_or_garlic() {
  int fangs_present;
if (find_player("nooneelse"))
  call_out("check_for_cross_or_garlic", 1);
  find_item="garlic";
  cross_present=0;
  find_item="nooneelsecross";
  cross_present=look_for_something(find_item);
  hammer_present=0;
  find_item="hammer";
  hammer_present=look_for_something(find_item);
  stake_present=0;
  find_item="nooneelseoakstake";
  stake_present=look_for_something(find_item);
  find_item="vampire fangs";
  fangs_present=look_for_something(find_item);
  if (!cross_present ||
      !hammer_present ||
      !stake_present) {
    tell_room(environment(this_object()),
            "The man says:  Go away puny mortal!  You obviously don't have\n"+
            "               what it takes to even attempt to take me on.\n");
    vampire_enemy=0;
    strong_vampire();
    who=first_inventory(environment(this_object()));
    while (who) {
      obj=next_inventory(who);
      if (who != this_object() && living(who)) {
        call_other("/players/nooneelse/redentry", "???", 0);
        move_object(who, "/players/nooneelse/redentry");
        tell_object(who,"You sense a change in your surroundings...\n\n");
      }
      who=obj;
    }
    return 0;
  }
  weak_vampire();
  return 0;
}

strong_vampire() {
  set_wc(25);
  set_ac(10);
  spell_damage=25;
  heal_amount=10;
  return 0;
}

weak_vampire() {
  set_wc(16);
  set_ac(8);
  spell_damage=12;
  heal_amount=5;
  return 0;
}

/* go home after a few seconds. */
go_home() {
  say("He laughs at your puny efforts and leaves.\n");
  call_other("players/nooneelse/red/coffin_room", "???", 0);
  move_object(this_object(), "players/nooneelse/red/coffin_room");
  tell_room(environment(this_object()),
            "You feel a chill as a red haze fills the room.  The haze\n"+
            "dissipates to reveal, Barnabas.\n");
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
    if (who != this_object()) {
      if (find_item=="vampire fangs" &&
          present(find_item, who) &&
          present(find_item, who)->query_guild_exp()==669) {
        command("solve task", who);
        tell_object(who, "\nYou've found Barnabas and solved this task.\n\n");
      }
      if (living(who) && present(find_item, who)) return 1;
    }
    who=next_inventory(who);
  }
  return;
}

init_command(cmd) { command(cmd); }

set_random_pick(r) {random_pick=r; }

query_undead () { return 1; }

kill_this_vampire() {
  remove_call_out("check_hit_points");
  remove_call_out("check_for_cross_or_garlic");
/* make sure there's not another one laying around somewhere */
  vampire_corpse=present("corpse of vampire");
  if (vampire_corpse) destruct(vampire_corpse);
/* need my own special corpse for my vampires */
  vampire_corpse=clone_object("players/nooneelse/mon/vampire_corpse");
  vampire_corpse->set_enemy(vampire_enemy);
  move_object(vampire_corpse, environment(this_object()));
  say("Barnabas dies.\n");
  write("You killed Barnabas.\n");
  destruct(this_object());
  return 1;
}