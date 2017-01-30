#define MAX_GUESTS 25
#define STARTRMNUM 1
#define DAY_COST 300
#define TIMECONSTANT 1032837262

string room_status;
int full,done,guest_count;
int lastvisit;
string names,tv;

init() {
  int v;
#ifndef __LDMUD__ /* Rumplemintz */
      add_action("west"); add_verb("west");
      add_action("east"); add_verb("east");

      add_action("register"); add_verb("register");
#else
  add_action("west", "west");
  add_action("east", "east");
  add_action("register", "register");
#endif
      add_action("check_out", "checkout");

      add_action("look", "look");
      add_action("look", "l");
      add_action("look", "examine");
      add_action("look","read");
      add_action("look", "search");
#ifndef __LDMUD__ /* Rumplemintz */
      add_action("look"); add_verb("look");
      add_action("look"); add_verb("l");
      add_action("look"); add_verb("examine");
      add_action("look"); add_verb("move");
#else
  add_action("look", "move");
#endif
      add_action("sit","sit");
      v=random(8);
      if(v==0) tv = "The Untouchables";
      if(v==1) tv = "The Jerry Springer Show";
      if(v==2) tv = "Star Trek";
      if(v==3) tv = "the local news";
      if(v==4) tv = "The Roadrunner cartoon";
      if(v==5) tv = "Bay Watch";
      if(v==6) tv = "the A-Team";
      if(v==7) tv = "Real Sex 39";
}

reset(arg) {
 int i,cl;
   if(arg) return;
  if(!done) {
    set_light(1);
    room_status = allocate(30);
    lastvisit = allocate(30);
    names = allocate(30);

    i = 0;
    if(!guest_count) guest_count = -1;
    while (i <= guest_count) {
      if (lastvisit[i]) {
        cl=time() - (lastvisit[i]+TIMECONSTANT);
        if (cl > 2592000) {
           room_status[i] = "v";
        }
      }
      i += 1;
    }
    done = 1;
  }
}

short() { return "One Night Stand Motel, Office"; }

long() {
   write("This is the plain, worn, and run down office of the One Night\n"+
        "Stand Motel. The simple wooden counter supports an old black and\n"+
        "television set tuned to "+tv+". The man who runs \n"+
        "this place must be hiding in the back room. If you register he'll\n"+ 
        "probably turn up. Paying customers are a rarity these days. On\n"+ 
        "the wall is a movie poster from 'Some Like It Hot'. The plaster\n"+
        "walls clearly haven't been painted in decades and are rather\n"+ 
        "dirty. To the east is a hallway to the rooms. There is a sign\n"+
        "on the wall behind the counter.\n");
}   
west() {
  call_other(this_player(),"move_player",
  "west#room/southroad1.c");
  return 1;
}
east() {
  call_other(this_player(),"move_player",
  "east#players/boltar/motel/hall.c");
  return 1; 
}

register(str) {
  string nme,jj;
  int myroom,x,f;
  object cardkey;
  x=0;
  f=0;
  if(present("MotelKey", this_player())) {
    write("You already have a room.\n");
    return 1;
  }
  if (call_other(this_player(), "query_money", 0) < DAY_COST) {
    write("You must have enough money for at least one half day!\n");
    return 1;
  }
  if (guest_count >= MAX_GUESTS ) {
    full = 1;
    guest_count = find_empty();
    if (guest_count == 0)
      guest_count = MAX_GUESTS + 1;
    }
  if (guest_count > MAX_GUESTS) {
    write ("Sorry, but the motel is booked solid.\n");
    return 1;
  }
  call_other(this_player(), "add_money", -DAY_COST);
  if (full == 0) guest_count += 1;
  room_status[guest_count] = "o"; 
  myroom = STARTRMNUM+guest_count;
  lastvisit[guest_count] = time()-TIMECONSTANT;
  write("It costs you " +DAY_COST+" gold coins.\n");
  write("You scribe your name into the book.\n");
  write("You are given a key for room number "+myroom+".\n");
  write("\n");
  nme = call_other(this_player(), "query_name", 0);
  say(nme + " registers into the motel.");
  say("\n");
  cardkey=clone_object("/players/boltar/motel/key");
  move_object(cardkey, this_player());
  call_other(cardkey,"set_room_num",myroom);
  call_other(cardkey,"set_lastv",lastvisit[guest_count]);
  names[guest_count] = this_player()->query_real_name();
  this_player()->save_me();
  if (full == 1) guest_count = MAX_GUESTS;
  return 1;
}

find_empty() {
  int empty_rm,x; 
  x=0;
  while (x <= MAX_GUESTS + 1) {
     if (room_status[x] == "v") {
       empty_rm = x;
       x = MAX_GUESTS + 1;
     }
     x += 1;
  }
  return empty_rm;
}

last_visit(arg_rm) {
   lastvisit[arg_rm - STARTRMNUM] = time() - TIMECONSTANT;
}

query_last_visit(arg_rm) {
  return lastvisit[arg_rm - STARTRMNUM];
}
query_guest_name(arg_rm) {
    return names[arg_rm - STARTRMNUM];
}

cost(arg_rm) {
  int bill;
  bill=((time()-(TIMECONSTANT+lastvisit[arg_rm-STARTRMNUM]))/(24*3600))*DAY_COST;
  return bill;
}

query_room_status(arg_rm) {
  return room_status[arg_rm - STARTRMNUM];
}

pay() {
  int room_number,bill;
  room_number = present("MotelKey",this_player())->query_room_number();
  bill = cost(room_number);
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
  room_number = present("MotelKey",this_player())->query_room_number();
  bill = cost(room_number);
  write("The front desk computer shows your bill to be "+bill+" coins.\n");
  return 1;
}

comp(rm,arg) {
  lastvisit[rm - STARTRMNUM] += arg;
}

sit(str) {
  string stra;
  if (str !="on chair" && str !="on sofa" && str !="on counter")
    return 0;
  write("You sit.\n");
  sscanf(str,"on %s",stra);
  tell_room(this_object(),this_player()->query_name()+" sits on a "+stra+".\n");
  return 1;
}

check_out() {
  int room_number,bill;
  object mykey;
  mykey = present("MotelKey",this_player());
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
  names[room_number- STARTRMNUM] = 0;
  destruct(mykey);
  write ("You have been checked out of your room.\n");
  return 1;
  }

look(str) {
  if (!str) { return 0; }
  if (str == "at tv" || str== "at television") {
    write("A beat up black and white TV with a manual tunner. The soft\n"+
          "glow adds to the light in the room. The tv is tunned to \n"+
          tv+" \n");
    return 1;
  }
  if (str == "at hall") {
    write("The hall to the east is barely lit by a 60 watt bulb and \n"+
          "leads to the rooms.\n");
    return 1;
  }
  if (str == "at counter") {
    write("A beat up wooden counter.\n");
    return 1;
  }
  if(str == "at table" || str == "at tables") {
    write("A large,worn rectangular table.\n");
    return 1;
  }
  if(str=="at book" || str=="book") {
    book();
    return 1;
  }
  if (str== "at chair" || str=="at chairs") {
    write("Beat up and partly broken wooden chairs.\n");
    return 1;
  }
  if (str=="at doors" || str=="at door") {
    write("Old wooden door with peeling white paint.\n");
    return 1;
  }
  if (str=="at employee") {
     write("A scruffy man barely making ends meet in this business.\n");
     return 1;
  }
  if (str== "at sign") {
    write("A large old hand-made sign hangs on the wall behind the\n"+
          "counter. The sign reads: MOTEL,\n"+
          "Standard room rate is "+DAY_COST+" coins per half day .\n"+
          "Must be paid in advance.\n");
    return 1;
  }
  return 0;
}
query_vac() { 
    if(full) return 0;
    return 1;
   }

book() {
  int x;
  write("------------------GUEST REGISTER----------------\n");
  x=STARTRMNUM;
  while (x <= MAX_GUESTS + 1) {
    if (room_status[x-STARTRMNUM] == "o") {
      if(x<10) write(" ");
      write(x+"\t"+extract(ctime(TIMECONSTANT+lastvisit[x-STARTRMNUM]),3,10)+"\t");
      if(names[x-STARTRMNUM])
      write(capitalize(names[x-STARTRMNUM])+"\n");
      else write("Vacant.\n");
    }
    x += 1;
  }
  return 1;
}
