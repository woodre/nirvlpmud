/*
  hunt_control.c - scavenger hunt control room
*/

#include "/obj/user/junk_only.c"

inherit "room/room";

int GRAND_HUNT_PRIZE, NBR_ENTRANTS, NBR_POSSIBLE_ITEMS;
int NBR_ITEMS_PER_LIST; /* this must be changed in hunt_list too! */
int PAUSE_BEFORE_1ST_HUNT, PAUSE_BETWEEN_HUNTS;
int hunt_in_progress, current_entrant_nbr;
int *current_item_nbrs;
int *current_item_values;
string time_hunt_started;
string *list_of_items;
string *current_items;
string *current_clues;
string *list_of_entrants;

query_nbr_entrants() { return NBR_ENTRANTS; }
query_nbr_items_per_list() { return NBR_ITEMS_PER_LIST; }
query_nbr_possible_items() { return NBR_POSSIBLE_ITEMS; }
query_pause_before_1st_hunt() { return PAUSE_BEFORE_1ST_HUNT; }
query_pause_between_hunts() { return PAUSE_BETWEEN_HUNTS; }
query_current_item(arg) { return current_items[arg]; }
query_current_clue(arg) { return current_clues[arg]; }

reset(arg) {
  int i;
  set_light(1);
  short_desc="Scavenger Hunt Control Room";
  dest_dir=
    ({
      "players/nooneelse/hunt/entry_hall", "down",
    });
  if (hunt_in_progress) return 0;
  GRAND_HUNT_PRIZE=1000;
  NBR_ENTRANTS=30;
  NBR_POSSIBLE_ITEMS=15;
  NBR_ITEMS_PER_LIST=10;
  PAUSE_BEFORE_1ST_HUNT=5;
  PAUSE_BETWEEN_HUNTS=3600;
  list_of_items=allocate(NBR_POSSIBLE_ITEMS);
  current_item_nbrs=allocate(NBR_ITEMS_PER_LIST);
  current_items=allocate(NBR_ITEMS_PER_LIST);
  current_clues=allocate(NBR_ITEMS_PER_LIST);
  current_item_values=allocate(NBR_ITEMS_PER_LIST);
  list_of_entrants=allocate(NBR_ENTRANTS);
  /* load the table with the potiential items */
  for (i=0; i<NBR_POSSIBLE_ITEMS; i++) list_of_items[i]=" ";
  load_items();
  call_out("start_a_hunt", PAUSE_BEFORE_1ST_HUNT);
}

long(str) {
  int i, entrant_found;
  write(
    "Scavenger Hunt Control Room\n"+
    "This is where you bring the items on your scavenger hunt list.\n"+
    "You can bring them in in any order.  The first player to bring\n"+
    "in all the items on their list will be declared the winner and\n"+
    "be awarded with the value of the current hunt "+GRAND_HUNT_PRIZE+
    " gold!\n\n");
  if (hunt_in_progress) {
    write("The current hunt started at: "+time_hunt_started+"\n"+
          "It is currently:             "+ctime(time())+"\n\n");
    entrant_found=0;
    for (i=0; i<NBR_ENTRANTS; i++) {
      if (list_of_entrants[i] != " ") {
        if (!entrant_found) {
          entrant_found=1;
          write("Current entrants are: ");
        }
        write(capitalize(list_of_entrants[i])+" ");
      }
    }
  }
  write("\n\n");
  write(
    "Instructions:  To enter the scavenger hunt, type 'enter hunt'.\n"+
    "               If you somehow lose your list, type 'replace list'.\n"+
    "               You will be given a list of items to find.  When\n"+
    "               you find them, bring them to this room and type\n"+
    "               'check <item name>' to have it marked on your list.\n\n"+
    "               NOTE: The item will be destroyed as it's checked off\n"+
    "                     on your list.  Also, if you have more than one\n"+
    "                     item that are on the list, they all will be marked\n"+
    "                     at the same time.\n");
}

start_a_hunt() {
  int i, j, k, l, item_value;
  string list_entry, item_entry, item_name, item_clue;
  if (hunt_in_progress) {
    call_out("start_a_hunt", PAUSE_BETWEEN_HUNTS);
    return 1;
  }
  GRAND_HUNT_PRIZE=0;
  hunt_in_progress=1;
  time_hunt_started=ctime(time());
  /* randomly select the items for the current list */
  for (i=0; i<NBR_ITEMS_PER_LIST; i++) current_item_nbrs[i]=0;
  i=0;
  k=0;
  while (i<NBR_ITEMS_PER_LIST) {
    k=0;
    while(k==0) {
      l=random(NBR_POSSIBLE_ITEMS);
      if (l==0) l=1;
      for (j=0; j<NBR_ITEMS_PER_LIST; j++) if (current_item_nbrs[j]==l) k=9;
      if (k==0) k=1;
      if (k==9) k=0;
    }
    current_item_nbrs[i]=l;
    sscanf(list_of_items[current_item_nbrs[i]],
           "%s#%s#%d", item_name, item_clue, item_value);
    current_items[i]=item_name;
    current_clues[i]=item_clue;
    current_item_values[i]=item_value;
    GRAND_HUNT_PRIZE=GRAND_HUNT_PRIZE+item_value;
    i++;
  }
  if (GRAND_HUNT_PRIZE < 1000) GRAND_HUNT_PRIZE=1000;
  for (i=0; i<NBR_ENTRANTS; i++) list_of_entrants[i]=" ";
  /* tell all players that a new hunt is starting */
  chan_msg("\n\n\nBong!  Bong!  Bong!  Come one, come all!  Enter the next\n"+
           "Grand Scavenger Hunt!!!\n\n\n"+
           "Hurry to the Rainbow Inn Scavenger Hunt Control Room and get your "+
           " list!\n\n\n");
}

init() {
  ::init();

  add_action("enter_hunt",   "enter");
  add_action("replace_list", "replace");
  add_action("check_item",   "check");
  add_action("dump_stuff",   "dump");
}

enter_hunt(str) {
  int i, entrant_found;
  object list;
  if (!str || str != "hunt") return 0;
  if (present("scavenger hunt list", this_player())) {
    write("But, you are already entered!\n");
    return 1;
  }
  entrant_found=0;
  for (i=0; i<NBR_ENTRANTS; i++) {
    if (list_of_entrants[i]==this_player()->query_name()) entrant_found=1;
  }
  if (entrant_found) {
    write("But, you're already entered in this hunt.\n");
    return 1;
  }
  if (current_entrant_nbr < NBR_ENTRANTS) {
    list_of_entrants[current_entrant_nbr]=this_player()->query_name();
    current_entrant_nbr++;
  }
  else {
    write("Sorry, the limit of "+NBR_ENTRANTS+
          " entrants has already been met.\n"+
          "Try again in the next hunt.\n");
    return 1;
  }
  list=clone_object("/players/nooneelse/hunt/hunt_list");
  list->set_owner_of_list(lower_case(this_player()->query_name()));
  move_object(list, this_player());
  write("One of the judges enters the room and hands you a list of items,\n"+
        "smiles, says 'Good luck' and leaves.\n");
  say(this_player()->query_name()+
      " decides to enter the scavenger hunt and is given a list of items.\n",
      this_player());
  return 1;
}

replace_list(str) {
  int i, entrant_found;
  object list;
  if (!str || str != "list") return 0;
  if (present("scavenger hunt list", this_player())) {
    write("But, you already have one!\n");
    return 1;
  }
  entrant_found=0;
  for (i=0; i<NBR_ENTRANTS; i++) {
    if (list_of_entrants[i] != this_player()->query_name()) entrant_found=1;
  }
  if (!entrant_found) {
    write("But, you aren't entered in this hunt.\n");
    return 1;
  }
  list=clone_object("/players/nooneelse/hunt/hunt_list");
  list->set_owner_of_list(lower_case(this_player()->query_name()));
  move_object(list, this_player());
  write("One of the judges enters the room and hands you a list of items,\n"+
        "smiles, says 'Good luck' and leaves.\n");
  say(this_player()->query_name()+
      " gets a replacement list for the scavenger hunt.\n", this_player());
  return 1;
}

check_item(item_name) {
  string player_name;
  int item_found, mark_item_return, i;
  object list_obj, item_obj, who_obj_array, money_obj;
  if (!item_name) return 0;
  item_obj=present(item_name, this_player());
  if (!item_obj) {
    write("You don't have a '"+item_name+"'.\n");
    return 1;
  }
  list_obj=present("scavenger hunt list", this_player());
  if (!list_obj) {
    write("You don't have a scavenger hunt list.\n");
    return 1;
  }
  if (list_obj->query_owner_of_list() !=
      lower_case(this_player()->query_name())) {
    write("This isn't your list, it's "+list_obj->query_owner_of_list()+
          "'s.\n");
    return 1;
  }
  i=1;
  item_found=0;
  for (i=0; i<NBR_ITEMS_PER_LIST; i++) {
    if (item_name==current_items[i] || item_obj->id(item_name)) {
      item_found=1;
      break;
    }
  }
  if (item_found) {
    mark_item_return=list_obj->mark_item(item_name);
    if (mark_item_return==0)
      write("'"+item_name+"' is not on the list.\n");
    if (mark_item_return==1 || mark_item_return==9) {
      write("Ok, '"+item_name+"' has been marked.  Congratulations!\n");
      destruct(item_obj);
    }
    /* have they finished the hunt? */
    if (mark_item_return==9) {
      who_obj_array=users();
      for (i = 0; i < sizeof(who_obj_array); i++) {
        list_obj=present("scavenger hunt list", who_obj_array[i]);
        if (list_obj) destruct(list_obj);
      }
      player_name=this_player()->query_name()+"#"+ctime(time())+"\n";
      "/players/nooneelse/hunt/entry_hall"->add_player(player_name);
      money_obj=clone_object("/obj/money");
      money_obj->set_money(GRAND_HUNT_PRIZE);
      move_object(money_obj, environment(this_player()));
      write(
        "\nCongratulations!  You've completed the Great Scavenger Hunt!\n\n"+
        "Your prize ($"+GRAND_HUNT_PRIZE+
        " gold) is sitting on the ground in front of you!\n\n");
      chan_msg("\n\n\nBong!  Bong!  Bong!  "+
               "The Grand Scavenger Hunt is now over!!!\n\n\n"+
               "Congratulations to "+this_player()->query_name()+"!!!!\n\n\n");
      hunt_in_progress=0;
      for (i=0; i<NBR_ENTRANTS; i++) list_of_entrants[i]=" ";
      call_out("start_a_hunt", PAUSE_BETWEEN_HUNTS);
    }
  }
  else {
    write("'"+item_name+"' isn't on your list.\n");
  }
  return 1;
}

burn_list(entrant_name) {
  int i, entrant_found;
  object list;
  if (!entrant_name) return 0;
  for (i=0; i<NBR_ENTRANTS; i++) {
    if (list_of_entrants[i]==entrant_name) list_of_entrants[i]=" ";
  }
  for (i=0; i<NBR_ENTRANTS; i++) {
    if (list_of_entrants[i]==" " && i<NBR_ENTRANTS-1) {
      list_of_entrants[i]=list_of_entrants[i+1];
      list_of_entrants[i+1]=" ";
    }
  }
  return 1;
}

int dump_stuff() {
  int i, total_value;
  if (this_player()->query_level() < 32) return 0;
  write("\n\nList of possible items\n");
  for (i=0; i<NBR_POSSIBLE_ITEMS; i++)
    if (list_of_items[i] != " ") write(i+"\t'"+list_of_items[i]+"'\n");
  write("\n\nItem numbers selected\n");
  total_value=0;
  for (i=0; i<NBR_ITEMS_PER_LIST; i++) {
    write(current_item_nbrs[i]+"\t"+current_items[i]+"#"+
          current_clues[i]+"#"+current_item_values[i]+"\n");
    total_value=total_value+current_item_values[i];
  }
  write("Total value of this hunt: "+total_value+"\n");
  return 1;
}

load_items() {
  list_of_items[0]="dummy item#item 0 will never be on the list#0";
  list_of_items[1]="bag#It's most useful when full.#100";
  list_of_items[2]="crown#It makes you look like royalty.#300";
  list_of_items[3]="fortune cookie#This cookie is worth a fortune.#50";
  list_of_items[4]="gloves#Digit clothes.#350";
  list_of_items[5]="light#A magic form of the torch.#150";
  list_of_items[6]="jacket#It helps when you are chilly.#200";
  list_of_items[7]="key#You need one of these to get past some doors.#200";
  list_of_items[8]="knife#You can use it to spread butter.#75";
  list_of_items[9]="newspaper#Read this to see what's new.#50";
  list_of_items[10]="rope#You can climb with it or catch things with it.#500";
  list_of_items[11]="stick#A cheap version of a torch.#350";
  list_of_items[12]=
    "water glass#You can quench your parched throat with it.#500";
  list_of_items[13]="axe#Chop chop.#100";
  list_of_items[14]="trash#Smelly garbage.#25";
/*
  NOTE:  If you add or subtract items, you must change NBR_POSSIBLE_ITEMS
         in hunt_common.c
*/
}
