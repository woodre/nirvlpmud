#include <ansi.h>
inherit "/obj/monster";
#define IT capitalize(ob->query_name())
#define WC 20
#define AC 30

/*
 * The Banshee is a high level monster that is not meant to be
 * killed.  If she is killed it will be by a large group of
 * high level players.  This monster roams my dungeon area,
 * interupting the progress of players and causing some minor
 * damage to all players in the area when she 'wails'.
 */

int num;

reset(arg) {
  string crap1, crap2;
  ::reset(arg);
  if(arg) return;
  set_name("Bescinnalae");
  set_alias("bescinnalae");
  set_short("A Wailing Spirit");
  set_long(
  "A horrible tortured spirit wavers before you.  Bescinnalae was once a\n"+
  "beautiful elven maiden.  Her stunning beauty and uncommon selflessness\n"+
  "was known throughout the realms...Until she fell under the wicked spell\n"+
  "of the Wizard Yunok.  Yunok twisted her soul and used its unblemished\n"+
  "purity for his wicked means.  When he was through with her, Yunok threw\n"+
  "the maiden into the dungeons of Arcynia.  Her restless spirit now\n"+
  "wanders the dungeous endlessly, searching for some hope of redemption.\n");
  set_race("banshee");
  set_gender("female");
  set_level(30);
  set_hp(5000);
  set_al(0);
  set_aggressive(1);
  set_a_chat_chance(45);
  load_a_chat("Banshee wails piteously.\n");
  load_a_chat("Bescinnalae's eyes stare into you, pleading for help.\n");
  load_a_chat("The Banshee sighs mournfully.\n");
  load_a_chat("Bescinnalae's soft sigh whispers unending agony.\n");
  load_a_chat("Banshee cries out in sorrow.\n");
  load_a_chat("You feel an overwhelming sense of sorrow and loss.\n");
  load_a_chat("The Banshee cries out in anguish.\n");
  set_dead_ob(this_object());

  /*
   * There can only be one of each of these items on the game at
   * any time.  If someone already has them then we will clone
   * more generic treasure in its place.
   */
  if(sscanf(object_name(this_object()), "%s#%s", crap1, crap2) == 2) {
    if(!find_object("players/pavlik/armor/ralston_necklace")) {
      move_object(clone_object("players/pavlik/armor/ralston_necklace"), this_object());
      init_command("wear necklace");
    }
    else {
      move_object(clone_object("players/pavlik/armor/shackles"), this_object());
      init_command("wear shackles");
    }
  
    if(!find_object("players/pavlik/armor/crystal_slippers")) {
      move_object(clone_object("players/pavlik/armor/crystal_slippers"), this_object());
      init_command("wear slippers");
    }
    else {
      move_object(clone_object("players/pavlik/armor/jade_bracelet"), this_object());
      init_command("wear bracelet");
    }
  }

  move_object(clone_object("players/pavlik/items/ilstkarn/syrian_ring"),
  this_object());
  init_command("wear ring");
  set_wc(WC);
  set_ac(AC);
  money = 500 + random(2000);
  if(!root()) call_out("random_move", 15);
  call_out("kombat", 10);
}

id(str) {
  return str == "Bescinnalae" || str == "bescinnalae" || str == "spirit"
  || str == "banshee" || str == "dungeon_banshee";
}

init() {
  ::init();
  if(this_player()->is_player()) {
    add_action("nope","south");
    add_action("nope","east");
    add_action("nope","west");
    add_action("nope","leave");
  }
}

/*
 * Keep the players from going any where when she is in the same
 * room.  Players will be forced to fight her until she moves.
 * Exception: the exit 'north' is not blocked.
 */
nope() {
  int x;

  if(this_player()->query_level() < 20) {
    write("The Banshee blocks your path!\n");
    return 1;
  }
}

/*
 * As usual, I don't like players being able to stop a fight.
 */
stop_fight() {
  if(this_player()->query_level() > 20) {
    ::stop_fight();
    return 1;
  }
  return;
}

/*
 * None of this heal_self crap
 */
heal_self(i) {
  if(i <= 0) {
    return;
  }
  else {
    ::heal_self(i);
  }
  return;
}

/*
 * This random move checks for valid exits.  We don't want to waste
 * any time trying to move where there is no exit.  Also checks for
 * valid directions so she doesn't wander where she's not supposed to.
 */
random_move() {
  string exits, fname, dir, tmp;
  int n, attempts;

  while(remove_call_out("random_move") != -1);
  call_out("random_move", 30);

 if(environment())
  {
  exits = environment()->query_dest_dir();
  if(!exits) exits = ({ });
  n = random(sizeof(exits));
  attempts = 1;

  /* make sure we find a valid exit */
  if(sizeof(exits) >= 2)
  while(attempts) {

    if(n % 2) {
      fname = exits[n-1];
      dir = exits[n];
    }
    else {
      fname = exits[n];
      dir = exits[n+1];
    }

    /* some exits are fake...dont go for them */
    if(sscanf(fname, "%s/null", tmp)==1) {
      n++;
      if(n > sizeof(exits)) n = 0;
    }
    else {
      attempts = 0;
    }

  }

  /* make sure we don't accidently leave the area */
  if(dir == "north" || dir == "south" || dir == "east" || dir == "west") {
    tell_room(environment(),
    "Bescinnalae "+MAG+"sighs softly"+NORM+", like a flower being crushed.\n"+
    "The Banshee glides silently "+dir+"ward.\n");
    move_object(this_object(), fname);
    tell_room(environment(),
    "A shiver runs down your spine as the restless Banshee enters.\n");
  }
 }


  return 1;
}

/*
 * This horrible miserable function gives the monster a chance to do
 * some unique functions and combat emotes.
 */
kombat() {
  int i;
  object ob;
  object fear;

  if(!environment()) {
    destruct(this_object());
    return 1;
  }

  /* Make sure our stats haven't been played with */
  set_ac(AC);
  set_wc(WC);

  if(random(12) == 2) {
    wail();
    call_out("kombat", 10);
    return 1;
  }

  ob = query_attack();
  i = random(16);

  if(!ob) {
    call_out("kombat", 25);
    return 1;
  }

  if(!present(ob, environment())) {
    call_out("kombat", 10);
    return 1;
  }

  if(i == 0) {
    tell_room(environment(),
    "Bescinnalae reaches out and "+HIW+"grasps"+NORM+" "+IT+" with a slender hand.\n"+
    IT+" gasps and recoils in pain!\n");
    tell_object(ob,
    "The banshee's cold touch "+HIW+"shocks"+NORM+" you painfully!\n");
    ob->hit_player(5+random(15));
  }
  else if(i == 2) {
    tell_room(environment(),
    "The Banshee strikes "+IT+" with a powerful lightning bolt!\n");
    ob->hit_player(10+random(30));
  }
  else if(i == 4) {
    tell_object(ob,
    "Bescinnalae reaches out and wraps her delicate fingers around your wrist.\n"+
    "You cry out in horror as the Banshee tries to "+MAG+"steal your soul!\n"+NORM);
    /*
     * Unlucky 13: Drop the Players Stamina ...Nasty!
     */
    if(!random(13)) {
      tell_object(ob,
      HIW+"Bescinnalae steals away part of your soul!!!\n"+NORM);
      ob->raise_stamina(-1);
    }
    else {
      tell_object(ob,
      "With a supreme effort of will you break free of the her grasp!\n");
    }
  }
  else if(i == 6) {
    tell_room(environment(),
    "The Banshee claws viscously at "+IT+"s face!\n");
    ob->hit_player(random(10));
  }
  else if(i == 9) {
    if(present("fear_obj", ob)){
      tell_room(environment(),
      "Bescinnalae "+HIR+"rains fire"+NORM+" down upon "+IT+"!\n");
      ob->hit_player(20);
    } else {
      tell_room(environment(),
      "Bescinnalae casts a spell of "+HIY+"FEAR"+NORM+" on "+IT+"!\n");
      tell_object(ob, HIW+"You drop to the floor and cower there helplessly!\n"+NORM);
      fear = clone_object("players/pavlik/items/fear");
      move_object(fear, ob);
      fear->do_fear();
    }
  }
  else if(i == 11) {
    tell_room(environment(),
    "Bescinnalae the Banshee leaps forward and "+HIW+"Screams!!!!\n"+NORM);
    if(!random(4)) {
      tell_object(ob, HIY+"You panic and drop something!!!\n"+NORM);
      tell_room(environment(), HIY+IT+" panics!!!\n"+NORM);
      command("drop armor", ob);
    }
  }
  else if(i == 12) {
    tell_room(environment(),
    "Banshee calls down the "+HIR+"wrath of dead souls"+NORM+" upon "+IT+"!\n");
    tell_object(ob,
    "A hoarde of haunting spirits assault your mind!\n");
    ob->hit_player(20+random(30));
  }
  else if(i == 14) {
    tell_room(environment(),
    "Bescinnalae brushes your cheek with a gentle touch.\n"+
    "A single tear rolls down her face.\n");
    this_object()->heal_self(10+random(30));
  }

  call_out("kombat", 3+random(6));

  return 1;
}

/*
 * This function will do some minor damage to all players in my
 * dungeon area.  The wailing will affect any player whos
 * environment returns cell or dungeon with query_ilstkarn()
 */
wail() {
  object ob;
  string tmp;
  int i;

  ob = users();
  for(i=0; i<sizeof(ob); i++) {
    if(!environment(ob[i]) || !(environment(ob[i])->query_ilstkarn())) {
      continue;
    }
    if(environment(ob[i]) == environment()) {
      tell_object(ob[i], "\n"+
      "Bescinnalae raises her slender arms and cries out in a horrible\n"+
      "agonizing song!  The bittersweet melody rends your soul and brings\n"+
      "unbearable pain to your mind.\n");
      tell_object(ob[i],
      "You try to cover your ears, but it is too late.\n\n");
      ob[i]->hit_player(random(25));
      continue;
    }
    if(sscanf(environment(ob[i])->query_ilstkarn(), "dung%s", tmp)==1 ||
    sscanf(environment(ob[i])->query_ilstkarn(), "cell%s", tmp)==1) {
      tell_object(ob[i], "\n"+
      "A horrible wailing echoes through the dungeons and pierces your\n"+
      "soul like a blade of cold steel.\n");
      tell_object(ob[i],
      "You try to cover your ears, but it is too late.\n\n");
      ob[i]->hit_player(10+random(10));
    }
  }

  /*
   * just to be safe lets always restart the random_move when this
   * function is called.
   */
   remove_call_out("random_move");
   call_out("random_move", 15);

  return 1;
}

monster_died() {
  tell_room(environment(),
  "Bescinnalae whispers softly: If only it were this easy...\n"+
  "The banshee's glowing form slowly disappears.\n"+
  "The lost echo of a song dies in your heart.\n");

  if(this_player()->query_real_name()) {
    write_file("/players/pavlik/ilstkarn/LOG",
    capitalize(this_player()->query_real_name())+" killed the Banshee. ["+ctime()+"]\n");
  }

  return 0;
}

