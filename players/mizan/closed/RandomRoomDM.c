/* RandomRoomDM version 6.3 (Daemon-Machine)
 *
 * Some routines CPU intensive in order to preserve RAM ...sorry
 */

#define PATH "players/mizan/etheriel/ROOMS/"
#define LIQUID_R "players/mizan/closed/LiquidRoomDM.c"
#define CUBE_R "players/mizan/closed/borg-cube.c"
#define HOME "/players/mizan/core/02h/room04.c"
#define SAVE_FILE "players/mizan/closed/RDM_STATS"
#define LISTENING_ROOM "/players/mizan/core/02h/room02.c"

#define TORNADO "players/mizan/etheriel/tornado.c"
#define SURGE "players/mizan/etheriel/environs/exploder.c"

static string room;
static string dest_dir,itime,atime;
static string lastboot3_txt,lastboot2_txt,lastboot1_txt;
static string report_txt,dc_text;

int incept_time;
int saved_reboots_total,saved_reboots_plyr;
int saved_panic_r_total,saved_calls_total,saved_calls_single;
int panic_div;

static int reboots_total,reboots_plyr;
static int panic_reboots_total,calls_total,calls_single,panic_cnt;

static string dst_flag;
static int rooms_folded,zokked_objs,dested_objs,plyrs_prsnt;
static int cntr,room_total,percent_ld;

id(str) { return str == "machine" || str == "MI8040596r"; }

reset(arg) 
{
  if(!arg) {
/*
      call_other("/players/mizan/closed/HighLevelGuard.c","???");
      call_other("/players/mizan/closed/LowLevelGuard.c","???");
      call_other("/players/mizan/closed/NewbieGuard.c","???");
 */
    itime=ctime();
    if(!restore_object(SAVE_FILE)) {
      tell_room(HOME, "The machine says: Save file non-existent. New one created.\n");
      incept_time = ctime();
      panic_div = 800;
      var_init();
      save_object(SAVE_FILE);
    }
  }
  if(arg) atime = ctime();
  move_object(this_object(), HOME);
  call_other("/players/mizan/castle.c", "???");
  if(find_call_out("self_reset") < 1) call_out("self_reset", 4000);
}

init() {
  if(this_player()->query_level() > 19) {
    add_action("manual_reset","reset");
    add_action("display_reports","read");
    add_action("display_stats","review");
    add_action("locate_cube","find");
    add_action("set_panic_div","set_panic");
  }
}

set_exits() {
  string temp_dir,temp;
  int room_counter,random_counter;
  if(!room) var_init();
  room_counter = 0; random_counter = 0;
  temp_dir = allocate(sizeof(room));

  while(room_counter < sizeof(room)) {
    int pool_size;
    temp = room[room_counter];
    pool_size = sizeof(room[room_counter]);
    temp_dir[room_counter] = temp[random(pool_size)];
    room_counter++;
  }

  saved_calls_total ++;  calls_total ++;  panic_cnt ++;
/*
  if(panic_cnt > (panic_div / sizeof(users()))) {
 */
  if(panic_cnt > 50) {
    panic_cnt = 0;
    panic_reset();
  }
  if(1 == random(15)) save_object(SAVE_FILE);
  return temp_dir;
}

one_random() {
  string temp;
  if(!room) var_init();
  saved_calls_single += 1;  calls_single += 1;
  temp = room[random(sizeof(room))];
  return temp[random(sizeof(temp))];
}

get_id(arg) {
  object ob;
  string temp,temp2;
  ob = arg;
  if(sscanf(object_name(ob), "%slayers/mizan/etheriel/ROOMS/%s", temp, temp2) != 2) return "nowhere";
  return temp2;
}

var_init(str) {
  string temp_room;
  int i,r;
  if(!str && room) return 0;
/* set room pool size */
  temp_room = allocate(4);
  room = allocate(4);

/* These are the room names-filenames (about 200) but only 44
 * are picked from these and used till reboot.
 *
 * About half of the rooms use a randomly generated descriptor,
 * so dont rely of the long() of the room for reference.
 */

  temp_room[0]=({
    "slushie","wog","wumple","mango","edible",
    "panic","olive","noobo","onam","julibee",
    "suzuka","rhubarb","storo","buildo","prickle",
    "goo","pakka","syrup","spottle","canuck",
    "spork","yipyap","bjork","vasto","bognut",
    "valis","pitch","yello","griffo",
    "squid","squelsh","gwok","beered","pungle",
    "white","stretcho","pongle","oozie","blinko",
    "tunnel","zimmo","fall","poofle","shehal",
  });
  temp_room[1]=({
    "drimple","glowbo","itchy","cico","lemon",
    "fungus","ploozer","very","nullo","heavy",
    "pulso","zoknog","seefeel","questo","hicco",
    "gweeple","rail","sheep","zognut",
    "starsi","beh","pwei","spunko","fraisa",
    "burrow","red","yellow","bleak","fish",
    "noika","lunar","fungle","boski","stupid",
    "egaw","athol","gnoma","zoomer","gaggle",
    "kona","floatboat","kissed","dahdeh","heap",
    "bonkle","brose","howhow","fatso",
  });
  temp_room[2]=({
    "inog","wuzzy","duk","woogle","beano",
    "zok","noggle","mog","fiord","locki",
    "trix","brain","flubble","wizzle","frungle",
    "mrug","zebra","pago","loafy",
    "hydra","drowsy","slowbo","flowie","fearie",
    "foobar","grimple","pizza",
    "moo","splog","miggle","pliny","nuck",
    "zukie","bingle","bongle","blasto","osco",
    "croco","lush","trollo","spuck","gribble",
    "eep","bockle","toaster","spiggle",
  });
  temp_room[3]=({
    "dingledup","zoomer","orange","blue","green",
    "squish","dorha","eastwest","ginet","purple",
    "kango","dryer","quicko","gumbo","somewhat",
    "doofo","brownie","polar",
    "lora","neog","wombat","amelia","zoo",
    "zoogle","goffle","floogle","slooble","bongo",
    "rolog","gleef","norvar","nozzle","fraser",
    "mine","bloo","ham","niall","thwop",
    "droggo","bog","dingbung","junko","bockle",
    "chalnom","banana","prito",
  });


  while(i < sizeof(temp_room)) {
    string temp_origin_pool,temp_pool;
    temp_origin_pool = allocate(sizeof(temp_room[i]));
    temp_origin_pool = temp_room[i];
    temp_pool = allocate(7);
    r = 0;

/* POOL SIZE IS 9 
 * designate exits for temp_pool 
 */
    while(r < 7) {
      temp_pool[r] = temp_origin_pool[random(sizeof(temp_origin_pool))];
      r++;
    }

/* Spoogle must be first exit */
    if(i == 0) temp_pool[0] == "spoogle";
    room[i] = temp_pool;
    i++;
  }
}

short() { return "The RandomRoom machine [Version 6.3]"; }

long() {
  int plint;
  plint = percent_loaded();
  write("This is the RandomRoom machine, which generates random exits\n"+
   "for Mizan's area. It is sleek and compact, and completely encased\n"+
   "in a small grey cabinet. This is the third significant upgrade\n"+
   "of the 6.x series.\n"+
   "A bright red sticker on the casing reads:\n"+
   "To locate the Borg cube, type 'find cube'.\n"+
   "To adjust the panic divisor, type 'set_panic <arg>'.\n"+
   "To reset the entire castle, type 'reset castle'.\n"+
   "To read a report of the past four resets, type 'read report'.\n"+
   "Vectoring unsupported (removed from Nirvana version).\n");

  write("RReset / TRReset [" + calls_total+" / " + saved_calls_total + "t]\n"+
  "SReq   / TSReq   [" + calls_single+ " / " + saved_calls_single +"t]\n"+
  "RBoot  / TRBoot  [" + reboots_total +" / " + saved_reboots_total +"t].\n"+
  "MRBoot / TMRBoot [" + reboots_plyr+ " / " + saved_reboots_plyr +"t].\n"+
  "TPRBoot          [" + panic_reboots_total +"].\n");
  write("CPercent loaded  [");
  if(!plint) write("unloaded].\n");
    else write(plint + "% loaded].\n");
  if(panic_cnt)  write("Panic stats [" + panic_cnt + " curr / " +
    (panic_div / sizeof(users())) + " room / " + panic_div + "f] (same dscr)\n");
  if(incept_time) write("\nSAVE_FILE incept time was " + incept_time + ".\n");
  if(itime) write("The machine was switched on at " + itime + ".\n");
  if(atime) write("The machine experienced a reset at " + atime + ".\n");
  dump_call_out("self_reset");
  write(dc_text);
}

locate_cube(str) {
  string nug,nug1,nug2;
  if(!str || str != "cube") return 0;
  nug=CUBE_R->query_where_the_heck();
  if(!nug) {
    write("The Borg cube is not loaded.\n");
    return 1;
  }
  if(sscanf(nug, "%slayers/mizan/etheriel/ROOMS/%s", nug1, nug2) != 2) {
    write("The machine beeps: WARNING!\n"+
    "The Borg cube is outside the jello in [" + nug + "]!\n");
    return 1;
  }
  write("The machine beeps: Borg cube last sighted near " + nug2 + ".\n");
  return 1;
}

self_reset() {
  object ob,thingy;
  string temp,tempdir;
  int i;
  group_nuke();
  tell_room(HOME,
  "The machine beeps: 'Castle reboot performed at " + ctime() + ".\n");
  if(1 == random(2)) {
    if(1==random(2)) {
      thingy=clone_object(SURGE);
      temp = "(bleat) Tide report: A current surge was detected near '";
    } else {
      thingy=clone_object(TORNADO);
       temp = "(bleat) A tornado has touched down near '";
    }
    tempdir = one_random();
    move_object(thingy, "/" + PATH + tempdir);
    temp = temp + tempdir + "'.\n";
    call_other(LIQUID_R, "bleat", temp);
  }
  if(find_call_out("self_reset") >1) remove_call_out("self_reset");
  call_out("self_reset", 4000);
  return 1;
}

panic_reset() {
  object ob;
  object thingy;
  int i;
  panic_cnt = 0;
  group_nuke();
  panic_reboots_total ++; saved_panic_r_total ++;
  if(find_call_out("self_reset") >1) remove_call_out("self_reset");
  call_out("self_reset", 4000);
}

static manual_reset(str) {
  object ob;
  int i;
  if(!str || this_player()->query_level() < 20 || str != "castle") return 0;
  reboots_plyr ++;
  panic_cnt = 0;
  group_nuke("loud");
  return 1;
}

static group_nuke(str) {
  int counter,counter2;
  percent_ld = percent_loaded();
  rooms_folded=0; zokked_objs=0;
  dested_objs=0; plyrs_prsnt=0;
  while(counter < (sizeof(room))) {
    string temp;
    temp = room[counter];
    if(str) write("\nWorking ");
    while(counter2 < (sizeof(temp))) {
      flexboot(PATH + temp[counter2]);
      if(str) write(".");
      counter2 ++;
    }
    if(str) write("\n[Machine]: " + (counter + 1) +" of " + sizeof(room) + " room blocks destructed.\n");
    counter ++;
  }
  reboots_total ++; saved_reboots_total ++;
  compile_report();
}

flexboot(str) {
  object thingo;
  object bs1,bs3,bs5;
  string rnamea;
  if(str == PATH + "spoogle") return 0;
  if(str == PATH + "spuck") return 0;
  dst_flag=0;
  thingo=find_object(str);
  if(!thingo) return 1;
  bs1=first_inventory(thingo);

/* First sweep to check for players */

  while(bs1) {
    object bs2;
    string filnamea,filtesta,filtestb;
    bs2=bs1;
    bs1=next_inventory(bs1);

/* Don't touch this room if a player is present */

  filnamea = object_name(bs2);

   if(living(bs2)) {
     if(bs2->is_player() || bs2->is_kid() || !bs2->query_npc() || bs2->is_pet() ||
       sscanf(filnamea, "%sbj/player%s", filtesta, filtestb) == 2 ||
       sscanf(filnamea, "%sbj/disco%s", filtesta, filtestb) == 2) {
         dst_flag="AAAAAUGH! DONT HIT THIS ROOM!";
         count_plyrs_prsnt();
     }
   }

/* Second sweep to dest the living objects only... */

  if(!dst_flag) {
    bs3=first_inventory(thingo);
    while(bs3) {
      object bs4;
      bs4=bs3;
      bs3=next_inventory(bs3);
      if(living(bs4) && !query_ip_number(bs4)) {
        destruct(bs4);
        count_dested_objs();
      }
    }
  }
/* Last sweep dests everything else in room, and what the monster
 * was carrying and updates it */

  if(!dst_flag) {
    while(bs5) {
      object bs6;
      bs6=bs5;
      bs5=next_inventory(bs5);
      rnamea=object_name(bs6);
  if(!living(bs6)) {
      destruct(bs6);
      count_dested_objs();
      if(find_object(rnamea)) {
        destruct(find_object(object_name(bs6)));
        count_zokked_objs();
      }
    }
  }
      destruct(thingo);
      if(this_player()) /* Needed,errors to debug.log -B */
      if(this_player()->query_level() > 19) write("X");
      count_rooms_folded();
    } else {if(this_player())if(this_player()->query_level() > 19) write("O"); }
  }
  return 1;
}

dump_call_out(str) {
  int i;
  int foo;
  if((i = find_call_out(str)) >= 0) {
    dc_text = ("Countdown to next self reboot: [" + i + "] heartbeats ");
    foo=i/60;
    if((i-foo) == 0) dc_text = dc_text + ("(" + foo + " minutes).\n");
    else dc_text = dc_text + ("(" + foo + " minutes, " + (i-(foo * 60)) + " seconds).\n");
  }
}

query_reboot_time() {
  dump_call_out("self_reset");
  return dc_text;
}

count_rooms_folded() { rooms_folded ++; }
count_zokked_objs() { zokked_objs ++; }
count_dested_objs() { dested_objs ++; }
count_plyrs_prsnt() { plyrs_prsnt ++; }

compile_report() {
  lastboot3_txt = lastboot2_txt;
  lastboot2_txt = lastboot1_txt;
  lastboot1_txt = report_txt;
  report_txt = "[Report for incremental reboot at " + ctime() + "]\n\n" +
  "Rooms destructed\t [" + rooms_folded + "]\n" +
  "Objects dested       \t [" + dested_objs + "]\n" +
  "Objects updated\t [" + dested_objs + "]\n" +
  "Players inside\t [" + plyrs_prsnt + "]\n" +
  "Players total\t [" + sizeof(users()) + "]\n" +
  "Percent loaded: [" + percent_ld + "]\n\n";
/*
  call_other(LIQUID_R, "bleat", "A pressure wave gently collides into you.\n");
 */
  return 1;
}

static display_reports(str) {
  if(!str || str != "report") return 0;
  if(!report_txt) {
    write("There are no reports to show!\n");
    return 1;
  }
  if(lastboot3_txt) write(lastboot3_txt);
  if(lastboot2_txt) write(lastboot2_txt);
  if(lastboot1_txt) write(lastboot1_txt);
  write("Current: " + report_txt);
  return 1;
}

percent_loaded() {
  int i;
  negate_cntr();
  negate_room_cntr();
  while(i < sizeof(room)) {
    string temp;
    int x;
    temp = room[i];
    while(x < sizeof(temp)) {
      if(find_object(PATH + temp[x])) add_cntr();
      add_room_cntr();
      x++;
    }
  i++;
  }
  if(cntr) return (cntr * 100) / room_total;
  else return 0;
}

add_cntr() { cntr++; }
negate_cntr() { cntr = 0; }
add_room_cntr() { room_total ++; }
negate_room_cntr() { room_total = 0; }

long_display(arg,id_n,d_dir) {
  object ob,room;
  string lngfrm,id_name,dest_dir;
  int i;
  id_name = id_n;
  dest_dir = d_dir;
  room = arg;
  if(arg) if(this_player()) if(environment(this_player())) if(environment(room))
  if(environment(this_player()) == environment(room)) {
    ob = first_inventory(room);
    lngfrm = "    Destination " + id_name + " contains:\n";
    while(ob) {
      lngfrm = lngfrm + (ob->short()) + ".\n";
      ob = next_inventory(ob);
    }
    return lngfrm;
  }
  if(!dest_dir) return "No obvious exits.\n";
  else {
    i = 0;
    if(sizeof(dest_dir) == 1) lngfrm = "There is one obvious exit:";
    else
      lngfrm = "There are " + convert_number(sizeof(dest_dir)) + " obvious exits:";
      while(i < sizeof(dest_dir)) {
        lngfrm = lngfrm + " " + dest_dir[i];
        i += 1;
          if (i == sizeof(dest_dir) - 1) lngfrm = lngfrm + " and";
          else
            if (i < sizeof(dest_dir)) lngfrm = lngfrm + ",";
      }
    lngfrm = lngfrm + ".";
    lngfrm = format(lngfrm, 70);
    return lngfrm + "\n";
  }
}

convert_number(n) {
  string numbers;
  numbers = call_other("room/room", "query_numbers");
  if (n > 9) {
    if(n == 10) return "ten";
    if(n == 11) return "eleven";
    if(n == 12) return "twelve";
    if(n > 12 && n < 18) return "many";
    if(n > 18 && n == 18) {
      if(1 == random(3)) return "a fuckload of";
      else if(1 == random(3)) return "a hell of a lot of";
      else return "too damn many";
    }
  } else {
  return numbers[n];
  }
}


