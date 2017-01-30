#define NUMBER_OF_ITEMS_HARD 3
#define NUMBER_OF_ITEMS_EASY 18
#define NUMBER_OF_ITEMS 21
int room_number,inv_no,done,shield,floor,seg;
int hit_val,miss_val;
string locker_arg;
string filename;
static string a;
int lighton;

reset(arg) {
  if(arg) return;
  shield = 1;
}
init() {
  int rmc;
  object keyc;

  add_action("look", "look");
  add_action("look", "l");
  add_action("look", "examine");
  add_action("look", "exa");
  add_action("look", "search");
#ifndef __LDMUD__ /* Rumplemintz */
  add_action("on"); add_verb("lock");
  add_action("restore"); add_verb("restore");
  add_action("store"); add_verb("store");
#else
  add_action("on", "lock");
  add_action("restore", "restore");
  add_action("store", "store");
#endif
  add_action("light_switch","switch");
#ifndef __LDMUD__ /* Rumplemintz */
  add_action("off"); add_verb("unlock");
  add_action("south"); add_verb("out");
#else
  add_action("off", "unlock");
  add_action("south", "out");
#endif
  add_action("junk","replace");
  add_action("list","list");
  
  if (this_player()->query_real_name() != "boltar")
    if (shield == 1) {
      if(this_player())
        keyc = present("CasaNirvanaKey",this_player());
      if(keyc) {
        rmc = keyc->query_room_number();
      }
      if(rmc != room_number) {
        write("Room "+room_number+" is locked.\n");
        write("You are transported to the the street below.\n");
        this_player()->move_player("after trying to enter the room#room/lanceroad1");
      }
    }
  }

static on() {
  shield = 1;
  write("Room locked.\n");
  return 1;
}
static off() {
  shield = 0;
  write("The room is unlocked.\n");
  write("Door will autolock in 5 minutes.\n");
  call_out("on",300);
  return 1;
}
query_lock() { return shield; }

short() {
    return "Casa de Nirvana room number "+room_number;
}
long() {
  if(!lighton) 
    write("The room is dark but for a faint glow from under the door.\n\n");
  write("You stand in one of the many identical guest rooms in the\nCasa "+ 
        "de Nirvana Hotel. (#"+room_number+") Muted beige walls accented\n"+
        "with a paisley cranberry and hunter green border compliment the\n"+
        "rich shades of the Persian rug covering the polished hardwood\n"+
        "floor. To one side of the room rests an overstuffed leather couch\n"+ 
        "of deep hunter green with a matching leather armchair, separated\n"+
        "by a marble-topped dark cherry coffee table graced by a large\n"+
        "Tiffany lamp. A four-poster bed of deep cherry dominates the far\n"+
        "corner of the room. The faint scent of sandalwood emanates from\n"+
        "two fat candles on the mantle over the fireplace. A discrete\n"+
        "brass sign hangs on the wall beside the door.\n"); 
  if (shield == 1) write ("The door is closed and locked.\n");
  if (shield == 0) write ("The door is unlocked and open.\n");
  write("The only exit is out.\n");
}

south() {
  if(shield) 
    write("You open door, and close it behind you making sure it is locked.\n");
  if(!shield) 
    write("You leave the room leaving it unlocked.\n");
  call_other(this_player(), "move_player",
  "out#players/boltar/casino/hall"+floor+"x"+seg);
  return 1;
}

set_room_number(rm){
  lighton = 1;
  room_number=rm;

  if(rm > 199 && rm < 226) { floor = 2; seg = 1; }
  if(rm > 225 && rm < 251) { floor = 2; seg = 2; }
  if(rm > 250 && rm < 276) { floor = 2; seg = 3; }
  if(rm > 275 && rm < 300) { floor = 2; seg = 4; }
  if(rm > 299 && rm < 326) { floor = 3; seg = 1; }
  if(rm > 325 && rm < 351) { floor = 3; seg = 2; }
  if(rm > 350 && rm < 376) { floor = 3; seg = 3; }
  if(rm > 375 && rm < 400) { floor = 3; seg = 4; }
  if(rm > 399 && rm < 426) { floor = 4; seg = 1; }
  if(rm > 425 && rm < 451) { floor = 4; seg = 2; }
  if(rm > 450 && rm < 476) { floor = 4; seg = 3; }
  if(rm > 475 && rm < 500) { floor = 4; seg = 4; }
  if(rm > 499 && rm < 526) { floor = 5; seg = 1; }
  if(rm > 525 && rm < 551) { floor = 5; seg = 2; }
  if(rm > 550 && rm < 576) { floor = 5; seg = 3; }
  if(rm > 575 && rm < 600) { floor = 5; seg = 4; }

  filename = allocate(30);
  hit_val = allocate(30);
  miss_val = allocate(30);
  locker_arg = allocate(30);
  restore_object("players/boltar/casino/rooms/"+room_number+"/master");
  if(lighton) set_light(1);
  if(!lighton) set_light(-1);
  done = 1;
  return 1;
}

store(){
  object all_stuff;
  int count,count_hard,count_easy;
  string sf,creator_name,first,filetmp,junk,livfl;

  all_stuff = allocate(30);
  all_stuff =all_inventory(this_object());
  count = 0;
  if (inv_no > 0) {
    write ("please do a 'restore' first.\n");
    return 1;
  }
  inv_no = 0;
  
  while (inv_no < NUMBER_OF_ITEMS && count < sizeof(all_stuff)) {
/*
    if (call_other(all_stuff[count], "query_save_flag",0))
*/
   if(all_stuff[count]->query_save_flag() && all_stuff[count]->query_save_flag() != 2)
      sf = "NOSAVE";
    if (sf != "NOSAVE"){
      filetmp=file_name(all_stuff[count]);
      creator_name=creator(all_stuff[count]);
      sscanf(filetmp, "%s/%s", first, junk);
      if (all_stuff[count]->generic_object() && 
          !all_stuff[count]->locker_arg()) 
          first = "OK";
      if (first != "players") {
        count_hard += 1;
        if (creator_name && creator_name !="boltar") {
          call_other(all_stuff[count], "save_thing",
            "players/"+creator_name+"/hoteltmp");
          sscanf(filetmp, "%s#%s", filename[inv_no],junk);
          destruct(all_stuff[count]);
          all_stuff[count] = clone_object(filename[inv_no]);
          call_other(all_stuff[count],
            "restore_thing","players/"+creator_name+"/hoteltmp");
          move_object(all_stuff[count], this_object());
        }
        if (count_hard < NUMBER_OF_ITEMS_HARD + 1) 
          if(call_other(all_stuff[count], 
            "save_thing","players/boltar/casino/rooms/"
            +room_number+"/"+count_hard)){

            filetmp = file_name(all_stuff[count]);
            sscanf(filetmp, "%s#%s", filename[inv_no], junk);
            write (call_other(all_stuff[count], "short", 0) +
                "SAVED, DIFFICULT ITEM #"+count_hard+".\n");
            destruct(all_stuff[count]);
            inv_no +=1;
          } else {
            write (call_other(all_stuff[count], "short", 0)+
                " NOT SAVED.");
            if(count_hard > NUMBER_OF_ITEMS_HARD - 1)
              write(" DIFFICULT ITEM LIMIT REACHED.");
            write("\n");
          }
      }
      if(first == "players") {
        count_easy += 1;
        if(living(all_stuff[count]) && !all_stuff[count]->living_save())
           livfl="NO";
        filetmp = file_name(all_stuff[count]);
        if(!livfl && count_easy < NUMBER_OF_ITEMS_EASY + 1){
          sscanf(filetmp, "%s#%s",filename[inv_no],junk);
          write (call_other(all_stuff[count], "short",0) + " SAVED.\n");
          hit_val[count] = all_stuff[count]->query_hits();
          miss_val[count] = all_stuff[count]->query_misses();
          locker_arg[count] = all_stuff[count]->locker_arg();
          destruct(all_stuff[count]);
          inv_no += 1;
        } else {
          if(livfl)
            write (call_other(all_stuff[count], "short",0) + " NOT SAVED.");
          else
            write (" EASY ITEM LIMIT REACHED.\n");
        }
      }
      count += 1;
      livfl = 0;
    }
    if(sf == "NOSAVE") {
      write(call_other(all_stuff[count], "short",0)+ 
           " NOT SAVED, item is non-storable .\n");
      count += 1;
      sf = 0;
    }
  }
  save_object("players/boltar/casino/rooms/"+room_number+"/master");
  return 1;
}

restore(){
  object thing;
  string b,err,first,junk;
  int count,count_hard,count_easy;
  count = 0;
  while (count < inv_no) {
    if (filename[count] == "none") {
       /*
      write("Nothing more to restore.\n");
      inv_no = 0;
      return 1;
      */
      write("Empty Location encountered.\n");
      filename[count]="players/boltar/things/hcookie";
      locker_arg[count] = 0;
    }
    /* going to error catching model -Bp
    thing = clone_object(filename[count]);
    */
    if ( err = catch(thing = clone_object(filename[count])) ) {
      log_file("casino_mangle", ctime()+" "+this_player()->query_real_name()+": "+filename[count]+"\n");
      write("Your item has been mangled beyond use.\n");
      write("However, you find a cookie.\n");
      thing = clone_object("/players/boltar/things/hcookie");
      filename[count]="players/boltar/things/hcookie";
      locker_arg[count] = 0;
    }
    if(thing) {
      sscanf(filename[count], "%s/%s", first, junk);
      if(thing->generic_object() && !thing->locker_arg())
        first = "OK";
      if (first != "players") {
        count_hard += 1;
        call_other(thing, "restore_thing", "players/boltar/casino/rooms/"+room_number+"/"+count_hard);
        move_object(thing, this_object());
        filename[count] = "none";
        write(call_other(thing, "short",0) + " RESTORED.\n");
      }
      if(first == "players") {
        count_easy += 1;
        move_object(thing, this_object());
        filename[count] = "none";
        thing->set_hits(hit_val[count]);
        thing->set_misses(miss_val[count]);
        if(locker_arg[count])
          thing->locker_init(locker_arg[count]);
        write(call_other(thing, "short",0) + " RESTORED.\n");
        locker_arg[count]=0; hit_val[count]=0; miss_val[count]=0;
      }
    }
    count +=1;
  }
  inv_no = 0;
  save_object("players/boltar/casino/rooms/"+room_number+"/master");
  return 1;
}

bleech() { return 1; }

clear() {
  inv_no = 0;
  write("Hotel room inventory cleared.\n");
  return 1;
}

list() {
  string bla,blb,blah;
  int y;
  while (y < inv_no) {
    write(y + " -- ");
    blah=filename[y]+"1@2#";
    while(blah != "FINISHED") {
      if(sscanf(blah,"%s/%s",bla,blb) == 2) {
        sscanf(blah,"%s/%s1@2#", bla,blb);
        blah=blb+"1@2#";
      } else blah="FINISHED";
    }
    if(this_player()->query_level() < 21) write(blb);
    else write(filename[y]);
    write("\n");
    y++;
  }
  return 1;
}

junk(str) {
  int jnum;
  sscanf(str, "%d", jnum);
  filename[jnum] = "/players/boltar/things/hcookie";
  write("Item #"+str+" has been replaced by a cookie.\n");
  return 1;
}

light_switch() {
 write("You flip the switch.\n");
 say(this_player()->query_name()+" reaches for the light switch\n");
 if(lighton) {
   set_light(-1);
   lighton = 0;
   say("The lights go out.\n");
   write("The lights go out.\n");
 }
 else {
   set_light(1);
   lighton = 1;
   say("The lights come on.\n");
   write("The lights come on.\n");
 }
 return 1;
}
look(str) {
  if (!str) return 0;
  if (str=="switch"||str=="light switch"||str=="at switch"||str=="at light switch") {
    write("An ordinary light switch. You can switch the lights on and off.\n");
    return 1;
  }
  if (str=="at sign" || str=="at brass sign" || str=="instructions" || str=="at instructions") {
    write("Casa de Nirvana Hotel and Casino\n");
    write("You can do the following in your room:\n");
    write("\n");
    write("lock\t\t Locks the door to prevent others from entering.\n");
    write("unlock\t\t Unlocks the door so others may enter.\n");
    write("store\t\t Put your items into storage.\n");
    write("restore\t\t Bring your items out of storage.\n");
    write("list\t\t Lists items in storage.\n");
    write("replace #\t Replaces item # in storage with a cookie. Use when an\n");
    write("         \t cannot be restored.\n");
    write("switch\t\t Turn the lights on or off.\n");
    write("\nThe Hotel is NOT responsible for any lost items.\n");
    return 1;
  }
  if (str=="at rug") {
    write("A plush Persian rug bordered in shades of cranberry and\n"+ 
    "hunter green covers most of the dark hardwood floor of the room.\n");
    return 1;
  }
  if (str=="at couch" || str=="at sofa") {
    write("A comfortable hunter green leather couch rests against the\n"+ 
           "wall of the room.\n");
    return 1;
  }
  if (str=="at chair" || str=="at armchair") {
    write("A roomy hunter green leather armchair sits across from the\n"+
          "matching couch.\n");
    return 1;
  }
  if (str=="at table") {
    write("Between the couch and the chair sits a small marble-topped\n"+
          "coffee table in dark cherry. A large Tiffany lamp in the\n"+ 
          "center of the table provides warm, muted light to that\n"+ 
          "corner of the room.\n");
    return 1;
  }
  if (str=="at lamp" || str=="at tiffany lamp" || str=="at Tiffany lamp"){
    write("A large Tiffany lamp rests the center of the coffee table,\n"+
          "providing warm, muted light to that corner of the room.\n");
    return 1;
  }
  if (str=="at bed") {
    write("The enormous four-poster bed in hand-carved cherry wood is\n"+
          "covered with freshly ironed white sheets and a warm-looking\n"+
          "comforter in hunter green.\n");
    return 1;
  }
  if (str=="at candles" || str=="at candle") {
    write("Poised on the edges of the mantle are two fat candles in brass\n"+
          "candleholders.  The faint smell of sandalwood wafts up from\n"+ 
          "the base of the dancing flames.\n");
    return 1;
  }
  if (str=="at mantle") {
    write("The fireplace mantle is carved in a simple design from cherry\n"+
          "wood, and polished to a high gloss that darkly reflects the\n"+
          "light of the room.\n");
    return 1;
  }
  if (str=="at fireplace") {
    write("A beige ceramic fireplace is tucked into one corner of the\n"+
          "room, a small fire dancing merrily in its hearth.\n");
    return 1;
  }
  if(a!="bb") if(sscanf(str,"at %s",a)!=1) {
    a="bb"; if(look("at "+str)) a="dd"; else a="cc";}
  if(a=="dd") { a="cc"; return 1;}
  return 0;
}
query_dont_clean_obs_here() { return 1; }
