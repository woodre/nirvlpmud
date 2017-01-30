#include "/players/pavlik/guild/mages/macs2"
#include "/players/pavlik/guild/mages/rooms/ROOMS"
#include "/players/pavlik/guild/mages/rooms/GUILD_COSTS"
int min_exp;
inherit "room/room";
reset(arg) {
  if(!arg) {
set_light(1);
short_desc="Calador's Chambers";
long_desc=
"You have entered the chambers of Calador the Archmage.  The walls\n"+
"are covered with bookshelves, each of which is filled with volume\n"+
"upon volume of books.  Each book is filled with untold power of\n"+
"the arcane arts.  Calador oversees the training of every Mage\n"+
"within the guild, and he takes his work very seriously.  The center\n"+
"of the room is occupied by Calador's work table.  Several beakers\n"+
"filled with boiling liquids bubble quietly on the table top.\n"+
"There is a scroll unfurled on the desktop as well.  The hallway\n"+
"is to the south and Calador's private chambers are behind a curtain\n"+
"in the north wall.\n";

items=({
"scroll",
"A scroll lies unfurled on the work table.\n"+
"On it are the words 'aziar eim oyish'",
"walls",
"Every wall is completely occupied by Calador's bookshelves",
"bookshelves",
"Bookshelves of finely crated wood occupy every wall in this\n"+
"chamber.  Endless rows of books fill each shelf, there are far\n"+
"too many books to count.  Each tome holds unknown powers of the\n"+
"arcane arts",
"books",
"There must be millions of books stacked neatly on the bookshelves\n"+
"of this chamber.  Each book is carefully protected by magic so\n"+
"that not even the dust would disturb them.  You scan the titles\n"+
"of the books but you are unable to recognize the writing",
"table",
"Calador's work table occupies the center of the room.  The table\n"+
"appears to be made from some sort of marble.  Deep colorations\n"+
"swirl within the depths of the stone.  There are several potions\n"+
"and an unfurled scroll on the table top",
"potions",
"Several potions bubble and smoke on the work table of Calador.\n"+
"As tempting as it might be, you know better than to touch them",
"curtain",
"A red curtain stands between you and Calador's private chambers",
});

dest_dir=({
  "/players/pavlik/guild/mages/rooms/ante_room", "south",
  "/players/pavlik/no_way_in_hell", "north",
});

   }
}

query_mguild(){ return "Calador's"; }

init() {
  ::init();
  add_action("guild_move","gm");
  add_action("speak_it","aziar");
  add_action("summon_master","'aziar");
  add_action("summon_master","say");
  add_action("advance","advance");
  add_action("north","north");
  add_action("how_much","cost");
  add_action("advance_help","??");
  mage_check();
}

north(){
  if(tp->query_real_name() == "vertebraker"){
    move_object(tp, "players/vertebraker/workroom");
    write("You go through the curtain.\n");
    say(ME+" goes through the red curtain.\n");
    return 1;
    }
  write(
  "You carefully walk through the piles of books towards the\n"+
  "back of the room.  As you near the heavy red curtain you\n"+
  "begin to feel very very warm.  As you reach out to move the\n"+
  "curtain aside it bursts into flame!  A huge fire elemental\n"+
  "leaps from the red cloth and hurls you back across the room.\n"+
  "Snickering mischeviously the Elemental melts back into the\n"+
  "curtain.\n");
  say(ME+" tried to go through the curtain, but failed.\n");
  return 1;
}

advance(){
  int exp, next_exp, rank, x;
  string tmp, msg;

  if(!present("calador", this_object())){
    write("There is noone here to help you.\n");
    return 1;
    }

  if(present("calador", this_object())->query_BUSY()){
    write("Calador says:\n"+
    "  'Just a moment, Magi.  I am instructing another pupil.'\n");
    return 1;
  }

  rank = tp->query_guild_rank();
  exp = tp->query_guild_exp();

  if(rank >= 71){
    write("Calador says:\n"+
    "  'I have taught you all that I can.  You must seek a higher'\n"+
    "  'power if you wish to advance further.'\n");
    return 1;
  }

  next_exp = rank_costs(rank + 1);

  if(exp - next_exp < 0){
    write("Caldor says:\n"+
    "  'You are not ready to advance yet, Mage.  You must aquire more'\n"+
    "  'experience before I will instruct you.  Come back later and we'\n"+
    "  'will complete your training.'\n");
    return 1;
  }

  /* Calador cannot train us as Master of an Order
   * This must be done by another high-ranking player.
   * if(rank == 9 || rank == 19 || rank == 29 || rank == 39 || 
   */
  if(rank == 19 || rank == 29 || rank == 39 ||
  rank == 49 || rank == 59 || rank == 70) {
    if(rank+1 == 10) tmp = "Earth";
    else if(rank+1 == 20) tmp = "Air";
    else if(rank+1== 30) tmp = "Fire";
    else if(rank+1 == 40) tmp = "Dragons";
    else if(rank+1 == 50) tmp = "Storms";
    else if(rank+1 == 60) tmp = "Stars";
    else if(rank+1 == 71) tmp = "Time";

    write("Calador says:\n"+
    "  'You are ready to become a Master of "+tmp+".'\n"+
    "  'I cannot teach you this.  You must be trained by another Mage.'\n");

    /* ignore this if we are council member */
    if(PAV->is_gc(tp)) {
      write("Council Member ... ok.\n");
    }
    else {
    return 1;
    }
  }

  /* Mages must have a 2nd sponsor before advancing past rank 20 */
/* TEMPORARILY COMMENTED OUT....6/1/97
  if(rank+1 == 21) {
    if(!sponsor_check()) return 1;
  }
*/

  if((rank+1 > 60) && (tp->query_level() < 18)){
    write("You must be level 18 before you can advance in the Order of Time.\n");
  return 1;
  }
  else if((rank+1 > 50) && (tp->query_level() < 16)){
    write("You must be level 16 before you can advance in the Order of Stars.\n");
  return 1;
  }
  else if((rank+1 > 40) && (tp->query_level() < 14)){
    write("You must be level 14 before you can advance in the Order of Storms.\n");
  return 1;
  }
  else if((rank+1 > 30) && (tp->query_level() < 12)){
    write("You must be level 12 before you can advance in the Order of Dragons.\n");
  return 1;
  }
  else if((rank+1 > 20) && (tp->query_level() < 10)){
    write("You must be level 10 before you can be admittted to the Order of Fire.\n");
  return 1;
  }
  else if((rank+1 > 10) && (tp->query_level() < 7)){
    write("You must be level 7 before you can advance in the Order of Air.\n");
  return 1;
  }

  tp->add_guild_rank(1);
  command("gtitle", tp);

  /* give neat message to the player */
  display_message();

  /* if it is time, add a new spell */
  learn_spell();

  /* always gain a training session or two */
  gain_trains();

  /* tell the other members of the guild */
  if(!PAV->is_gc(tp)) tell_members();

  return 1;
}

how_much(){
  int cost, much;
  cost = rank_costs(tp->query_guild_rank() + 1);
  much = cost - tp->query_guild_exp();
  write(
  "Calador tells you: You must have "+cost+" guild exp to advance to your next rank.\n");
  if(much < 1)
  write("Calador tells you: You are ready to advance now.\n");
  else
  write("Calador tells you: You need "+much+" more guild exp to advance.\n");
  return 1;
}

advance_help(){
  if(!present("calador", this_object())){
    write("Noone is here to help you.\n");
    return 1;
  }

  write("Calador says:\n"+
  "  'I am here to help train the Magi.  Come to me when you are ready'\n"+
  "  'to advance in the guild.  If you seek to become the Master of your'\n"+
  "  'your order you must be trained by another Mage.'\n"+
  "  'If you are worthy, I will teach you a new spell.'\n"+
  "  commands are:\n"+
  "        advance  - advance a guild rank.\n"+
  "        cost     - query cost to advance to next guild rank.\n"+
  "\n");
  return 1;
}

tell_members() {
   object ob, mob, monk;
    int i;
   ob = users();
    for(i = 0; i < sizeof(ob); i++) {
    mob = present("mageobj", ob[i]);
  if(mob && mob->query_muffled() == 0) {
  tell_object(ob[i],
   "[*Calador*]: "+capitalize(ME)+" just advanced in the Guild!\n");
     }
   }
   return 1;
}

speak_it(){
  write("You have the feeling you should try to speak\n"+
  "these words aloud.\n");
  return 1;
}

summon_master(str){
  object obj;

  if(str == "aziar eim oyish" || str == "eim oyish"){

    write("You say: aziar eim oyish\n");
    say(ME+" says: aziar eim oyish\n");

    if(present("calador", this_object())){
      tell_room(this_object(),
      "Calador says: I am already here, are you blind?\n");
      return 1;
      }
  tell_room(this_object(),
  "The ground begins to shake slightly under your feet.  The slight\n"+
  "tremble becomes a giant quaking.  Towers of stacked books topple\n"+
  "to the floor.  You grab onto a nearby bookshelf to keep from\n");
  tell_room(this_object(),
  "falling over.  A myraid of brilliant colors explodes over the room.\n");
  tell_room(this_object(),
  "    Calador says: Yes?  Can I help you?  ('??' for commands)\n");
  obj = clone_object("players/pavlik/guild/mages/rooms/npc/calador");
  move_object(obj, this_object());
  return 1;
  }
}

sponsor_check(){
  string spon, trash;
  string who1, who2;
  sscanf(guild->query_sponsor(), "%s+%s", spon, trash);
  sscanf(spon, "%s#%s", who1, who2);

  if(!who2 || who2 == "0") {
    write(
    "Calador says:  You will need to seek the sponsorship of a\n"+
    "               Senior Mage before you can advance.  Take care\n"+
    "               of this obligation and return to me.\n");
    return 0;
  }

  if(who1 == who2) {
    write(
    "Calador says: "+capitalize(who1)+" cannot be the one to sponsor your\n"+
    "              again.  Find another Senior Mage to sponsor you.\n");
    return 0;
  }
  
  return 1;
}
 
display_message() {
  int x;
  x = random(4);

  if(x == 0) 
  write("Calador says:\n"+
  "  'If you wish to wield the powers of magic you must pay'\n"+
  "  'attention to details.  If you allow the slightest'\n"+
  "  'inconsistency your magic will fail.'\n");
  else if(x == 1)
  write("Calador says:\n"+
  "  'Magic is a tool and tools are only as effective as the'\n"+
  "  'the person who uses it.  You are an artisan and magic'\n"+
  "  'is your medium.'\n");
  else if(x == 2)
  write("Calador says:\n"+
  "  'You must be able to exert your will of your magic.  These'\n"+
  "  'powers know no master.  If you let your emotions weaken'\n"+
  "  'your resolve the magic may escape your control.'\n");
  else if(x == 3)
  write("Calador says:\n"+
  "  'Patience is the key.  You are an evolution of power.  Feel'\n"+
  "  'the change within you and take hold!\n");

  write("Calador says: Congratulations Mage.  You have advanced.\n");
}

learn_spell() {
  int rnk, amt, mod;

  rnk = tp->query_guild_rank();
  mod = 0;

/* chances for 1st level spells */
  if(rnk == 1) mod = 2;
  if(rnk == 2 || rnk == 4 || rnk == 6 || rnk == 8) mod = 1;
/* chances for 2nd level spells */
  if(rnk == 11 | rnk == 12 || rnk == 15 || rnk == 17 || rnk == 18) mod = 2;
/* chances for 3rd level spells */
  if(rnk == 21 || rnk == 23 || rnk == 24 || rnk == 27 || rnk == 28) mod = 2;
/* chances for 4th level spells */
  if(rnk == 32 || rnk == 33 || rnk == 36 || rnk == 39) mod = 3;
/* chances for 5th level spells */
  if(rnk == 41 || rnk == 45 || rnk == 48) mod = 3;
/* chances for 6th level spells */
  if(rnk == 52 || rnk == 55 || rnk == 56) mod = 3;
/* chances for 7th level spells */
  if(rnk == 61 || rnk == 63 || rnk == 65) mod = 3;

  if(mod == 0) return 1;

  amt = mod + random(guild->query_power()) / 10;
  if(rnk > 10 && amt > (rnk/10+3)) amt = rnk/10 + 3;
  guild->add_new_spells(amt);

  write("You recieve "+HIC+amt+" new "+NORM+" spell ");
  if(amt == 1) write ("chance.\n");
  else write ("chances.\n");
}

gain_trains() {
  int amt, x;

  amt = 1 + random(guild->query_intelligence()) / 12;
  if(tp->query_guild_rank() == 1) amt += 5;
  if(tp->query_guild_rank() == 2) amt += 1;
  if(tp->query_guild_rank() > 2 && tp->query_guild_rank() < 6) amt += 1;
  if(amt > 3 && tp->query_guild_rank() > 5) amt = 3 + random(2);
  guild->add_training_sessions(amt);

  write("You recieve "+HIC+amt+NORM+" training ");
  if(amt == 1) write("session.\n"); else write("sessions.\n");

  return 1;
}
 
