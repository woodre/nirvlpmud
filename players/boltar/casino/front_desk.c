#define MAX_GUESTS 300
#define STARTRMNUM 200
#define ENDRMNUM STARTRMNUM + MAX_GUESTS - 1
#define DAY_COST 600
#define MAX_BILL 20000
#define TIMECONSTANT 1032837262

string room_status,names;
static string a;
int full,done,guest_count;
int lastvisit;

init() {
#ifndef __LDMUD__ /* Rumplemintz */
      add_action("west"); add_verb("west");
#else
  add_action("west", "west");
#endif
      add_action("check_time","chktime");
#ifndef __LDMUD__ /* Rumplemintz */
      add_action("poke"); add_verb("fix");
      add_action("south"); add_verb("south");
      add_action("east"); add_verb("east");

      add_action("register"); add_verb("register");
#else
  add_action("poke", "fix");
  add_action("south", "south");
  add_action("east", "east");
  add_action("register", "register");
#endif
      add_action("check_out", "checkout");
      add_action("pay","pay");
      add_action("bill","bill");
      add_action("restore_key","newkey");

      add_action("look", "look");
      add_action("look", "l");
      add_action("look", "examine");
      add_action("look","read");
      add_action("look", "search");
      add_action("look", "move");
#ifndef __LDMUD__ /* Rumplemintz */
      add_action("look"); add_verb("look");
      add_action("look"); add_verb("l");
      add_action("look"); add_verb("examine");
      add_action("look"); add_verb("move");
#endif
      add_action("sit","sit");
}

reset(arg) { 
 int i,cl;
  if(arg) return;
  if(!done) {
    set_light(1);
    room_status = allocate(1000);
    names = allocate(1000);
    lastvisit = allocate(1000);
    restore_object("players/boltar/casino/front_desk");

    i = 0;
    if(!guest_count) guest_count = -1;
    while (i <= guest_count) {
      if (lastvisit[i]) {
        cl=time() - (lastvisit[i]+TIMECONSTANT);
        if (cl > 7776000 && names[i] != "boltar") {
           room_status[i] = "v";
        /*
           names[i] = 0;
        */
        }
      }
      i += 1;
    }
    done = 1;
    save_object("players/boltar/casino/front_desk");
  }
}

short() { return "Casa de Nirvana, front desk"; }

long() {
  write("You are in the opulent lobby of the Casa de Nirvana Hotel and\n"+
        "Casino. Marble pillars stretch high into the air, supporting\n"+
        "the vaulted ceiling sporting brightly colored frescoes vaguely\n"+
        "reminiscent of high Renaissance art and an enormous crystal\n"+
        "chandelier that scatters glittering light throughout the lobby.\n"+ 
        "The long mahogany counter is polished to a mirror finish which\n"+
        "reflects the tasteful sign hanging on the wall behind it. A\n"+
        "hotel employee in busies himself at the end of the counter,\n"+ 
        "ready to assist should you inquire. Scattered about the lobby\n"+ 
        "are several leather couches and mahogany tables, arranged into\n"+
        "intimate conversation groups. An inlaid gold panel above the\n"+ 
        "door to the west reads, 'Casino', while an identical panel\n"+ 
        "above the door to the east reads, 'Restaurant'. An eye-catching\n"+
        "playbill is posted beside the east door showcasing the nightly\n"+
        "live entertainment in the Theater. A curved grand staircase rises\n"+
        "from just west of the counter, eclipsing the discrete elevator\n"+
        "just to the east of the counter. A doorman watches the revolving\n"+
        "door to Lance Road toward the south.\n");
}

west() {
  call_other(this_player(),"move_player",
  "west#players/boltar/casino/hall1w1.c");
  return 1;
}
east() {
  call_other(this_player(),"move_player",
  "east#players/boltar/casino/hall1e1.c");
  return 1; 
}
south() {
  call_other(this_player(),"move_player",
  "south#room/lanceroad1.c");
  return 1; 
}

register(str) {
  string nme,jj,testx;
  int myroom,x,f,req,reqf;
  object cardkey;
  x=0;
  f=0;
  /* 08/31/06 Earwax: Addressing an issue */
  if ((int)this_player()->query_level() < 5 && (int)this_player()->query_age() < 3600)
  {
    write("You must be level 5 and an hour old to get a room.\n");
    log_file("CASA_SCAM", ctime()+": "+(string)this_player()->query_real_name()+" from IP "
    + query_ip_name(this_player())+" ("+query_ip_number(this_player())+")\n");
/*
    destruct(this_player());
*/
/*
  command("quit", this_player());
*/
    return 1;
  }
  if(str) {
    if(sscanf(str,"%d",req)!=1) {
      write("Use the room number to request a room.\n");
      return 1;
    }
    if(req > STARTRMNUM + MAX_GUESTS || req < STARTRMNUM) {
      write("We don't have such a room.\n");
      return 1;
    }
    req = req - STARTRMNUM;
    if(room_status[req] == "o") {
      write("Sorry that room is occupied by a guest.\n");
      return 1;
    }
    if(names[req])
    if(lower_case(names[req]) != this_player()->query_real_name()) {
      write("Sorry you weren't the previous occupant of that room.\n");
      return 1;
    }
    if(room_status[req] == "v") reqf = 1;
  }
  if(present("CasaNirvanaKey", this_player())) {
    write("You already have a room.\n");
    return 1;
  }
  if(!req)
    testx=check_by_name(this_player()->query_real_name());
  if(testx) { 
    write("You are listed as the occupant of room "+testx+".\n");
    write("Please restore the key for that room or re-register for it.\n");
    write("Commands:  newkey  _or_  register "+testx+".\n");
    return 1;
  }
  if (call_other(this_player(), "query_money", 0) < DAY_COST) {
    write("You must have enough money for at least one day!\n");
    return 1;
  }
  if (call_other("/players/boltar/hotel/hotel","check_if_guest",
      this_player()->query_real_name())) {
     write("You are currently registered at the Hotel of Time and Space.\n"+
           "If you want a room here, you will need to check out of your \n"+
           "room there.\n");
     return 1;
  }
  if (guest_count >= MAX_GUESTS ) {
    full = 1;
    guest_count = find_empty();
    if (guest_count == 0)
      guest_count = MAX_GUESTS + 1;
    }
  if (guest_count > MAX_GUESTS) {
    write ("Sorry, but the hotel is booked solid.\n");
    return 1;
  }
  call_other(this_player(), "add_money", -DAY_COST);
  if (full == 0 && reqf == 0) guest_count += 1;
  if(req && reqf) { reqf = guest_count; guest_count = req; }
  room_status[guest_count] = "o"; 
  names[guest_count] = this_player()->query_real_name();
  myroom = STARTRMNUM+guest_count;
  lastvisit[guest_count] = time()-TIMECONSTANT;
  write("It costs you " +DAY_COST+" gold coins.\n");
  write("You scribe your name into the book.\n");
  write("You are given a key for room number "+myroom+".\n");
  write("The desk worker points out the elevators and stairs to\n");
  write("side of the front desk.\n");
  write("\n");
  nme = call_other(this_player(), "query_name", 0);
  say(nme + " registers into the hotel.");
  say("\n");
  cardkey=clone_object("/players/boltar/casino/key");
  move_object(cardkey, this_player());
  call_other(cardkey,"set_room_num",myroom);
  call_other(cardkey,"set_lastv",lastvisit[guest_count]);
  this_player()->save_me();
  if (full == 1) guest_count = MAX_GUESTS;
  if (reqf > STARTRMNUM) guest_count = reqf;
  save_object("players/boltar/casino/front_desk");
  return 1;
}

find_empty() {
  int empty_rm,x; 
  string whoiam;
  x=0;
  while (x <= MAX_GUESTS + 1) {
     if (room_status[x] == "v") {
       empty_rm = x;
       x = MAX_GUESTS + 1;
     }
     x += 1;
  }
  if(whoiam=this_player()->query_real_name()+"vvvv") {
    x=0;
    while (x <= MAX_GUESTS + 1) {
      if(names[x])
      if(lower_case(names[x]) == whoiam) {
        empty_rm = x;
        x = MAX_GUESTS + 1;
      }
      x += 1;
    }
   }
  return empty_rm;
}

last_visit(arg_rm) {
   lastvisit[arg_rm - STARTRMNUM] = time() - TIMECONSTANT;
   save_object("players/boltar/casino/front_desk");
}

query_last_visit(arg_rm) {
  return lastvisit[arg_rm - STARTRMNUM];
}

cost(arg_rm) {
  int bill;
  bill=((time()-(TIMECONSTANT+lastvisit[arg_rm-STARTRMNUM]))/(24*3600))*DAY_COST;
  if(bill > MAX_BILL) bill = MAX_BILL;
  return bill;
}

query_room_status(arg_rm) {
  return room_status[arg_rm - STARTRMNUM];
}
pay() {
  int room_number,bill;
  object room_keyx;
  room_keyx = present("CasaNirvanaKey",this_player());
  if(!room_keyx) {
    write("You don't have a room key. Use the 'newkey' command if you lost it.\n");
    return 1;
  }
  room_number = room_keyx->query_room_number();
  bill = cost(room_number);
  if (room_status[room_number - STARTRMNUM] == "v") {
     write("Your room has expired for lack of use and payment.\n");
     write("Your card key vanishes.\n");
     destruct(present("CasaNirvanaKey",this_player()));
     return 1;
  }
  if(bill < 1) {
    write("Your room is all paid up.\n");
    return 1;
  }
  if (call_other(this_player(), "query_money", 0) < bill) {
    write("You do not have enough money, you cannot access your room\n");
    write("Until your outstanding debt of "+bill+" coins is paid.\n");
    return 1;
  }
  this_player()->add_money(0-bill);
  write("You pay your balance of "+bill+" coins.\n");
  last_visit(room_number);
  return 1;
}

bill() {
  int room_number,bill;
  if(!present("CasaNirvanaKey",this_player())) {
    write("You don't have a key.\n");
    return 1;
  }
  room_number = present("CasaNirvanaKey",this_player())->query_room_number();
  bill = cost(room_number);
  write("The front desk computer shows your bill to be "+bill+" coins.\n");
  return 1;
}

comp(rm,arg) {
  lastvisit[rm - STARTRMNUM] += arg;
}

sit(str) {
  string stra;
  if (str !="on chair" && str !="on sofa" && str !="on desk")
    return 0;
  write("You sit.\n");
  sscanf(str,"on %s",stra);
  tell_room(this_object(),this_player()->query_name()+" sits on a "+stra+".\n");
  return 1;
}

check_out() {
  int room_number,bill;
    object mykey;
  mykey = present("CasaNirvanaKey",this_player());
  if (!mykey) {
    write("You don't have a key to this motel.\n");
    return 1;
  }
  room_number = mykey->query_room_number();
  bill = cost(room_number);
  if (bill) {
    write("You must pay your outstanding bill of "+bill+" before you check out.\n");
    return 1;
  }
  lastvisit[room_number- STARTRMNUM] = 0;
  room_status[room_number- STARTRMNUM] = "v";
/*
  names[room_number- STARTRMNUM] = 0;
*/
  names[room_number- STARTRMNUM] = names[room_number- STARTRMNUM] +"vvvv";
  destruct(mykey);
  write ("You have been checked out of your room.\n");
  save_object("players/boltar/casino/front_desk");
  return 1;
  }

look(str) {
  if (!str) { return 0; }
  if (str=="at playbill" || str=="at eye-catching playbill") {
     call_other("/players/aingeal/casino/playbill","long",0);
     return 1;
  }
  if (str=="playbill" || str=="eye-catching playbill") {
    write("You need to be closer to read the playbill, just move to\n"+
          "the east.\n");
    return 1;
  }
  if (str == "at pillar" || str== "at pillars") {
    write("A pair of towering pillars stand on each side of the lobby,\n"+ 
          "the smooth, cool marble dully reflecting the light of the\n"+
          "chandelier. \n");
    return 1;
  }
  if (str == "at ceiling" || str=="at frescoes") {
    write("The lofty ceiling is crowded with decadent plaster artwork in\n"+
          "bright colors depicting frolicking cherubs.\n");
    return 1;
  }
  if (str == "at chandelier") {
    write("An enormous chandelier dominates the space between pillars in\n"+
          "the lobby, each twinkling droplet of crystal dancing in the\n"+
          "spray of light emanating from its center.\n"); 
    return 1;
  }
  if(str == "at table" || str == "at tables") {
    write("A large, highly polished rectangular table, with equally beautiful chairs.\n");
    return 1;
  }
  if (str== "at chair" || str=="at chairs") {
    write("Beautiful, hand crafted wood chairs with green fabric cusions.\n");
    return 1;
  }
  if (str== "at panel") {
    write("The tasteful gold panel posted above the door directs patrons\n"+
          "to what lies in the room beyond.\n");
    return 1;
  }
  if (str== "at stairs" || str=="at staircase") {
    write("A stately curved marble staircase framed by an intricate\n"+
          "wrought iron railing spills gracefully down from the second\n"+
          "story balcony leading to guests' rooms.\n");
    return 1;
  }
  if (str== "at elevator") {
    write("A modern elevator, artfully disguised as antique with mahogany\n"+
          "doors. There is a button on the wall to the side.\n");
    return 1;
  }
  if (str=="at doors" || str=="at door") {
    write("An oversized door of mahogany and frosted glass with brass\n"+
          "accents leads out from the lobby.\n");
    return 1;
  }
  if (str=="at doorman") {
    write("A young man in a navy blue bellhop uniform and pillbox hat\n"+
          "stands patiently beside the door to Lance Road, periodically\n"+ 
          "moving to hold the door for entering and departing patrons.\n");  
    return 1;
  }
  if (str=="at employee" || str=="at hotel employee") {
     write("A young man in a navy blue suit stands behind the counter\n"+
           "dealing with the buisness of the hotel.\n");
     return 1;
  }
  if (str== "at desk" || str=="at counter") {
    write("The counter is made of rich mahogany inlaid with a\n"+
          "gilt-stenciled vine pattern spanning its length. The wood is\n"+
          "polished to a mirror finish, darkly reflecting your image as\n"+
          "you gaze down at it. A sweet scent emanates from the sprawling\n"+
          "arrangement of live flowers that rests in the center of the\n"+
          "counter, their riotous color in sharp contrast to the subdued\n"+
          "hue of the wood. \n");
    return 1;
  }
  if(str=="at bill") {
    bill();
    return 1;
  }
  if (str== "at sign" || str=="sign") {
    write("A large brass sign engraved with black is set into the wall.\n"+
          "behind the counter. The sign reads: Welcome to Casa de Nirvana,\n"+
          "Hotel and Casino. Standard room rate is "+DAY_COST+" coins per day.\n"+
          "You may register, checkout, look at your bill, or pay your bill.\n");
    write("\nIf you have lost your key, newkey will generate a new one.\n");
    return 1;
  }
  if(str=="at book" || str=="book") {
    book();
    return 1;
  }
  if(a!="bb") if(sscanf(str,"at %s",a)!=1) {
    a="bb"; if(look("at "+str)) a="dd"; else a="cc";}
  if(a=="dd") { a="cc"; return 1;}
  return 0;
}
book() {
  int x;
  write("------------------GUEST REGISTER----------------\n");
  x=STARTRMNUM;
  while (x <= ENDRMNUM) {
    if (room_status[x-STARTRMNUM] == "o") {
      if(x<10) write(" ");
      write(x+"\t"+extract(ctime(TIMECONSTANT+lastvisit[x-STARTRMNUM]),3,10)+"\t");
     if(this_player()->query_level() > 30) {
        write(time() - (lastvisit[x-STARTRMNUM]+TIMECONSTANT)+"\t");
        write(cost(x)+"\t");
      }
      if(names[x-STARTRMNUM])
      write(capitalize(names[x-STARTRMNUM])+"\n");
      else write("Vacant.\n");
    }
    x += 1;
  }
  return 1;
}
restore_key() {
  object cardkey;
  int x,f;
  if(present("CasaNirvanaKey", this_player())) {
    write("You already have your key.\n");
    return 1;
  }
  x=STARTRMNUM;
  while (x <= ENDRMNUM) {
    if (room_status[x-STARTRMNUM] == "o") 
      if(lower_case(names[x-STARTRMNUM]) == this_player()->query_real_name()) {
        cardkey=clone_object("/players/boltar/casino/key");
        move_object(cardkey, this_player());
        call_other(cardkey,"set_room_num",x);
        this_player()->save_me();
        f = 1;
        write("You are handed a new card key for your room.\n");
      }
    x+=1;
  }
  if(!f) write("Sorry, your name is not in the register.\n");
  return 1;
}

fix_book_name(myroom,myname) {
   if(names[myroom-STARTRMNUM] == "RESERVED" ||
      names[myroom-STARTRMNUM] == "Vacant." ) 
    {
   names[myroom-STARTRMNUM] = myname;
   save_object("players/boltar/casino/front_desk");
   }
   if(names[myroom-STARTRMNUM]!=myname) {
      /*room has been recycled, tell key to destroy itself.*/
      return "DESTROY";
   }
   return 1;
}
check_if_guest(arg) {
  int x;
  x=STARTRMNUM;
  while (x <= ENDRMNUM) {
    if (room_status[x-STARTRMNUM] == "o") {
     if(names[x-STARTRMNUM]==arg) return 1;
    }
     x+=1;
  }
  return 0;
}
poke(arg) {
 int rmn;
 string nom;

  if(this_player()->query_real_name() != "boltar") return 0;
 sscanf(arg,"%d %s",rmn,nom);
 room_status[rmn-STARTRMNUM] = "o";
 names[rmn-STARTRMNUM] = nom;
 lastvisit[rmn-STARTRMNUM] = time() - TIMECONSTANT;
 write("Poked "+arg+"\n");
 return 1;
}
check_time(argg) { 
  int arg,cl;
  sscanf(argg,"%d",arg);
  if(this_player()->query_level() < 2000) return 0;
  cl=time() - (lastvisit[arg]+TIMECONSTANT);
  write(cl+"\n");
  return 1;
}
check_by_name(nom) {
int x,flagx;
  x=STARTRMNUM;
  while (x <= ENDRMNUM) {
    if(names[x-STARTRMNUM] == nom) {
      flagx = x;
      x = ENDRMNUM;
    }
       x+=1;
  }
return flagx;
}
