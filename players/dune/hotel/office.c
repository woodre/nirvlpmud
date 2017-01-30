/* 
 * Hotel core code, by Dune at Nirvana (6/18/97)
 * This hotel builds itself upon every reboot:
 *   depending upon desired hotel dimensions (def.h),
 *   all room/floor files are dynamically created
 * Provides method of renting and checking out of hotel
 */


inherit "room/room";
#include "def.h"
#include "discount.h"

status open;           /* determines if hotel has been setup yet */
string* registry;      /* keeps track of guest names & room#'s */
string* schedule;      /* keeps track of checkout dates */

id(str) { return str == "hotel_office"; }

init() {
  add_action("rent","rent");
  add_action("check_price","price");
  add_action("date","date");
  add_action("checkout","checkout");
  add_action("setup","open_hotel");
  if(this_player()->query_real_name() == MANAGER) {
    /* hotel wiz overseer has special commands */
    add_action("restore_me","restore_hotel");
    add_action("save_me","save_hotel");
    }
  ::init();
}

reset(arg){
  /* The hotel NPC is a decorative feature. Players may
   * only perform actions if the NPC is there to service them. */
  if(!present(NPCID))
    move_object(clone_object(PATH+"clerk.c"), this_object());

  if(!arg){
  set_light(1);
  short_desc=HOTELNAME;
  long_desc=
"     Welcome to "+HOTELNAME+"!\n"+
"Marble columns, blue water fountains, and red carpets\n"+
"decorate the wide royal lounge. To one side lies the\n"+
"reception desk, where you may take advantage of guest\n"+
"services. This hotel has "+ROOMS+" rooms and "+(ROOMS/ROOMSPERFLOOR)+
" stories.\nIt is currently being managed by "+capitalize(MANAGER)+". "+
"\nA wooden sign and golden plaque rest upon the wall.\n";

  items=({
    "sign", HOTELNAME+" provides the following services.\n"+
            "-------------------------------------------\n"+
            "rent  <day>      rent until day specified\n"+
            "price <day>      inquire about price for specified stay\n"+
            "date             learn the current date\n"+
            "checkout         officially check out of your room\n"+
            "open_hotel       informs clerk to open hotel (if not open yet)\n"+
            "-------------------------------------------",
    "plaque","This hotel brought to you by Dune",
    });

  dest_dir=({
    HOTELEXIT,           "out",
    ROOMPATH+"floor1.c", "rooms",
    });
  }   }


setup() {
  /* builds hotel from ground up
   * plans are inspected: variables are restored
   * floors are built with rooms connected to them */
  int i, j, count, daynum, todaynum, floor, size;
  string fname, today, npcname;
  string* tmp_registry;
  string* tmp_schedule;
  check_npc(); /* disable this command if NPC not present */
  npcname = capitalize(present(NPCID)->query_name());
  if( (!open) || (file_size(ROOMPATH+"floor1.c") < 0) ||
      ((ROOMPATH+"floor1.c")->query_floor() != 1) ) {
    write(npcname+" opens the hotel.\n");
    say(npcname+" opens the hotel.\n");
    open = 1; }
  else {
    write(npcname+" says: The hotel is already open.\n");
    return 1; }
  count = 1;
  restore_me();
  /* tmp vars make it possible to change the ROOMS and
   * ROOMSPERFLOOR definitions without having to clear the info
   * stored in registry and schedule */
  tmp_registry = allocate(ROOMS);  /* clear and allocate */
  tmp_schedule = allocate(ROOMS);  /* clear and allocate */
  size = sizeof(registry);         /* get old size of past vars */
  if(size > ROOMS) size = ROOMS;   /* use smaller amount */

  /* fill correct-sized array w/ old vars (which might be incorrct size) */
  for(i = 0; i < size; i++) {
    tmp_registry[i] = registry[i];
    tmp_schedule[i] = schedule[i];
    }
  registry = allocate(ROOMS);      /* clear and allocate */
  schedule = allocate(ROOMS);      /* clear and allocate */
  /* copy correct-sized array contents into saveable arrays */
  for(i = 0; i < size; i++) {
    registry[i] = tmp_registry[i];
    schedule[i] = tmp_schedule[i];
    }

  /* for each floor, build each room per floor
   * then build each floor and iterate to next floor */
  for(i = 0; i < (ROOMS/ROOMSPERFLOOR); i++) {
    for(j = 0; j < ROOMSPERFLOOR; j++) {
      fname = ROOMPATH+"room"+count+".c";
      rm(fname);  /* delete old room code */
      write_file(fname, read_file(ROOMPATH+"std_room.c"));
      fname->restore_me(registry[count-1], i+1); /* restore room vars */
      count++;
      }
    fname = ROOMPATH+"floor"+(i+1)+".c";
    rm(fname);    /* delete old room code */
    write_file(fname, read_file(ROOMPATH+"std_floor.c"));
    fname->setup_floor(i+1); /* restore floor vars, set up exits */
    }

  /* auto-checkout guests who were supposed to check out by today */
  today = query_today();
  todaynum = get_day_num(today);
  for(i = 0; i <  ROOMS; i++) {
    if(schedule[i]) {
      daynum = get_day_num(schedule[i]);
      if((todaynum - daynum) == 1) {
        /* today is the day after guest's last day of stay */
        rm(FULLSAVEPATH+registry[i]+".o"); /* remove guest's data */
        fname = ROOMPATH+"room"+(i+1)+".c";
        floor = fname->query_floor();
        fname->restore_me(registry[i], floor); /* clean guest's room */
        registry[i] = 0; /* officially check out guest */
        schedule[i] = 0;
        }
      }
    }
  save_me();
  return 1;
}


checkout() {
  /* method for guests to check out of hotel */
  int i, floor, matches, refund, remaining;
  string guestname, fname, day, today, npcname;
  check_npc(); /* disable this command if NPC not present */
  npcname = capitalize(present(NPCID)->query_name());
  guestname = this_player()->query_real_name();
  matches = 0;
  for(i = 0; i < ROOMS; i++) {
    if(registry[i] == guestname) {
      /* guest found (player is in hotel registry) */
      today = query_today();
      day = schedule[i];
      remaining = query_distance(today, day);
      remaining -= 1;
      refund = (remaining * RATE);
      refund = (refund * REFUNDPERCENT)/100;
      rm(FULLSAVEPATH+guestname+".o");
      fname = ROOMPATH+"room"+(i+1)+".c";
      floor = fname->query_floor();
      fname->restore_me(guestname, floor); /* clean room */
      registry[i] = 0;
      schedule[i] = 0;
      matches++;
      }
    }
  if(!matches) {
    write(npcname+" says: You are not registered with us.\n");
    return 1; }
  if(refund) {
    /* guests who check out at least one day earlier get refund */
    this_player()->add_money(refund);
    this_player()->save_me();
    write(npcname+" says: Your refund for checking out early is "+
           refund+" coins.\n");
    }
  write(npcname+" says: Thank you for your service.\n"+
        "You are all checked out.\n");
  say(TPN+" checks out of "+HOTELNAME+".\n");
  save_me();
  return 1;
}


rent(string day) {
  /* method to obtain a hotel room */
  string today, name, npcname;
  int cost, stay, daynum, todaynum, room;
  check_npc(); /* disable this command if NPC not present */
  npcname = capitalize(present(NPCID)->query_name());
  if(!day) {
    write(npcname+" says: You must specify your last day of stay.\n");
    return 1; }
  if(!query_vacancy()) {
    write(npcname+" says: No vacancies, sorry.\n");
    say(npcname+" says: No vacancies, sorry.\n");
    return 1; }
  name = this_player()->query_real_name();
  if(member_array(name, registry) == 0) {
    write(npcname+" says: You are already registered with us.\n");
    return 1; }
  day = lower_case(day);
  if(!(day = day_of_week(day))) {
    write(npcname+" says: The days of the week are:\n"+
          "Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday.\n");
    return 1; }
  today = query_today();
  daynum = get_day_num(day);
  todaynum = get_day_num(today);
  if((todaynum - daynum) == 1) {
    /* max length of stay is 6 days (including day of sign up)
     * this is because the day after last day of stay is the
     *   day of checkout, which means that if the guest signs
     *   up to stay 7 days (including day of signup) then guest's
     *   room is cleared. Reason for this is that 7 days means
     *   the same as yesterday, which means that today is check
     *   out day. */
    write(npcname+" says: Sorry, your last day of stay may not be "+
           capitalize(day)+".\n");
    return 1; }
  stay = query_distance(today, day);
  cost = RATE * stay;
  if(SALE) cost = discount(cost);
  if((this_player()->query_money()) < cost) {
    write(npcname+" says: You do not have "+cost+" coins!\n");
    return 1; }
  this_player()->add_money(-cost);
  this_player()->save_me();
  write("You give the clerk "+cost+" coins.\n");
  room = reserve_room(this_player()->query_real_name(), day);
  write(npcname+" says: You have room "+room+".\n");
  write(npcname+" says: On behalf of "+HOTELNAME+", thank you!\n");
  say(TPN+" checks into "+HOTELNAME+".\n");
  save_me();
  return 1;
}


check_price(string day) {
  /* method to check price before renting a room */
  string today, npcname;
  int cost, stay, daynum, todaynum;
  check_npc(); /* disable this command if NPC not present */
  npcname = capitalize(present(NPCID)->query_name());
  if(!day) {
    write(npcname+" says: You must specify your last day of stay.\n");
    return 1; }
  day = lower_case(day);
  if(!(day = day_of_week(day))) {
    write(npcname+" says: The days of the week are:\n"+
          "Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday.\n");
    return 1; }
  today = query_today();
  daynum = get_day_num(day);
  todaynum = get_day_num(today);
  if((todaynum - daynum) == 1) {
    write(npcname+" says: Sorry, your last day of stay may not be "+
           capitalize(day)+"day.\n");
    return 1; }
  stay = query_distance(today, day);
  cost = RATE * stay;
  if(SALE) {
    /* see discount.h for sale functions */
    write(npcname+" says: We have a special discount!\n");
    write(npcname+" says: Your charge would normally be "+cost+".\n");
    cost = discount(cost);
    write(npcname+" says: But we'll charge you only "+cost+"!\n");
    }
  else write(npcname+" says: To stay until "+capitalize(day)+
             ", your cost would be "+cost+" coins.\n");
  if((this_player()->query_money()) < cost) {
    write(npcname+" says: By the way, you do not have enough money.\n");
    return 1; }
  return 1;
}


date() {
  /* Command to find time on church clock */
  call_other("/room/church.c","long","clock");
  write("\nToday's Date: "+ctime(time())+"\n");
  return 1;
}


status query_vacancy() {
  int i;
  for(i = 0; i < ROOMS; i++) {
    if(registry[i] == 0) return 1;
    }
  return 0;
}


string day_of_week(string day) {
  string str;
  if(sscanf(day, "mo%s", str)) return "monday";
  if(sscanf(day, "tu%s", str)) return "tuesday";
  if(sscanf(day, "we%s", str)) return "wednesday";
  if(sscanf(day, "th%s", str)) return "thursday";
  if(sscanf(day, "fr%s", str)) return "friday";
  if(sscanf(day, "sa%s", str)) return "saturday";
  if(sscanf(day, "su%s", str)) return "sunday";
  return 0;
}


string query_today() {
  /* finds what day of week today is */
  string date, today, junk;
  date = ctime(time());
  sscanf(date, "%s %s", today, junk);
  today = lower_case(today);
  today = day_of_week(today);
  return today;
}


int get_day_num(string day) {
  /* enumerates days of the week for distance purposes */
  switch(day) {
    case "monday":    return 1;
    case "tuesday":   return 2;
    case "wednesday": return 3;
    case "thursday":  return 4;
    case "friday":    return 5;
    case "saturday":  return 6;
    case "sunday":    return 7;
    }
  return 0;
}


int query_distance(string today, string day) {
  int todaynum, daynum, diff;
  todaynum = get_day_num(today);
  daynum = get_day_num(day);
  if(daynum >= todaynum) diff = daynum - todaynum;
  else diff = (7 - todaynum) + daynum;
  return (diff + 1);
}


int reserve_room(string guestname, string day) {
  int i;
  string roomfile;
  for(i = 0; i < ROOMS; i++) {
    if(!registry[i]) {
      registry[i] = guestname;
      schedule[i] = day;
      break;
      }
    }
  roomfile = ROOMPATH+"room"+(i+1)+".c";
  roomfile->prepare(guestname);
  return (i+1);
}


save_me() {
  (PATH+"hotel_safe.c")->store(registry, schedule);
  return 1;
}


restore_me() {
  int x;
  x = (PATH+"hotel_safe.c")->restore_safe();
  registry = (PATH+"hotel_safe.c")->get_registry();
  schedule = (PATH+"hotel_safe.c")->get_schedule();
  return x;
}
