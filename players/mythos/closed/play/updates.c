#define ROOM tell_room(environment(this_object())
string file;
int TRIGGER;
int response,what,cycle,click;
string whos;
string meow;

id(str) { return str == "updater"; }

  short() { return "Updater ["+click+"/"+TRIGGER+"] <"+(click * 100 / TRIGGER)+"%>    * "+(click - TRIGGER)+" *"; }

query_prevent_shadow() { return 1; }
long() { write("An Updater\n"+
               "Use: sweep <state>\n"+
               "To update rooms in Hunter's Forest- state 'hunt'\n"+
               "To update the Hunter's castle- state 'castle'\n"+
               "To update the Tower and clearing- state 'tower'\n"+
               "To update the hut and village areas- state 'hut'\n"+
               "To update the Forest- state 'forest'\n"+
               "To update the library- state 'library'\n"+
               "To update Juliana's- state 'juliana'\n"+
               "To update Tokyo not including Juliana's- state 'tokyo'\n"+
               "To update monsters- state 'mon'\n"+
               "To update all areas- state 'all'\n"+
                       "'clickset #' sets the clicks\n"+
                 "'trigger #' sets the cycle\n"+
               "You may see how many clicks and how many more till\n"+
               "next autoset by typing 'click_check'\n"+
               "");
       }

drop() { return 0; }

get() { return 0; }

init() {
   if(member_array(this_player()->query_real_name(),meow) == -1) return 1;
  add_action("sweep","sweep");
  add_action("click_check","click_check");
   add_action("clickset","clickset");
   add_action("trig","trigger");
  this_object()->ghetto();
}


reset(arg) { if(arg) return; response = 0;
 whos = 0; what = 0; cycle = 0; click = 0;
   TRIGGER = 1200;
   meow = allocate(10);
   meow[0] = "mythos"; meow[1] = "daranath"; meow[2] = "arrina";
  meow[3] = "priest"; meow[4] = "meshitsukai"; meow[5] = "servant";
  meow[6] = "braxana"; meow[7] = "boltar"; meow[8] = "mizan";
  meow[9] = "lilith";
/*
 call_out("ch",3);
*/
 set_heart_beat(1);
}

clickset(str) {
int moo;
    if(!str) return 0;
   sscanf(str,"%d",moo);
    if(moo > TRIGGER) moo = TRIGGER - 1;
    if(moo < 1) moo = 1;
   click = moo;
  write(short()+"\n");
return 1; }

trig(str) {
  int mo;
  if(!str) { TRIGGER = 1200; write(short()+"\n"); return 1; }
   sscanf(str,"%d",mo);
   if(mo < 1) mo = 1;  if(mo > 2400) mo = 2400;
   TRIGGER = mo;
   write(short()+"\n");
return 1; }
/*
ch() { if(!environment(this_object())) { destruct(this_object()); return 1; }
*/
ch() {write("BBBAHAHHAHAHA!!");
call_out("test",1); return 1; }
test() {
object ob;
int h;
if (!environment()) return 1;
ob = all_inventory(environment(this_object()));
for(h=0;h<sizeof(ob);h++) {
  if(ob[h]->id("updater") && ob[h] != this_object()) {
    destruct(this_object());
  }
}
return 1; }

ghetto() {
  while(remove_call_out("ch") != -1);
  call_out("ch", 3);
}

query_level() { return 1000; }

sweep(str) {
int h;
  if(this_player() && this_player()->query_level() < 100 &&
     !(this_player()->query_real_name() == "mythos") &&
     !(this_player()->query_real_name() == "daranath") &&
     !(this_player()->query_real_name() == "braxana") &&
     !(this_player()->query_real_name() == "meshitsukai") &&
     !(this_player()->query_real_name() == "servant") &&
     !(this_player()->query_real_name() == "priest") ) {
     write("U can not use this.\n");
     return 1;}
  if(!str) return;
  h = 0;
  if(str == "hunt") {
    while(h < 16) {
      switch(h) {
        case 0: file = "closed/guild/forest/rooms/hunter"; break;
        case 1: file = "closed/guild/forest/rooms/hunter2"; break;
        case 2: file = "closed/guild/forest/rooms/hunter3"; break;
        case 3: file = "closed/guild/forest/rooms/hunter4"; break;
        case 4: file = "closed/guild/forest/rooms/hunter5"; break;
        case 5: file = "closed/guild/forest/rooms/hunter6"; break;
        case 6: file = "closed/guild/forest/rooms/hunter7"; break;
        case 7: file = "closed/guild/forest/rooms/hunter8"; break;
        case 8: file = "closed/guild/forest/rooms/hunter9"; break;
        case 9: file = "closed/guild/forest/rooms/hunter10"; break;
        case 10: file = "closed/guild/forest/rooms/hunter11"; break;
        case 11: file = "closed/guild/forest/rooms/hunter12"; break;
        case 12: file = "closed/guild/forest/rooms/hunter13"; break;
        case 13: file = "closed/guild/forest/rooms/hunter14"; break;
        case 14: file = "closed/guild/forest/rooms/hunter15"; break;
        case 15: file = "closed/guild/forest/rooms/huntera"; break;
      }
    swept(file);
    h = h + 1;
   }
/*
  write("Hunter's Forest done.\n");
*/
  }
  if(str == "mon" || str == "monsters" || str == "monster" || str == "mons") {
    while(h < 24) {
    switch(h) {
        case 0: file = "amon/Bfox"; break;
        case 1: file = "amon/priest"; break;
        case 2: file = "amon/messenger"; break;
        case 3: file = "amon/forest/aizen"; break;
        case 4: file = "amon/forest/ashura"; break;
        case 5: file = "amon/forest/benkei"; break;
        case 6: file = "amon/forest/darks"; break;
        case 7: file = "amon/forest/fudo"; break;
        case 8: file = "amon/forest/fuji"; break;
        case 9: file = "amon/forest/hinotori"; break;
        case 10: file = "amon/forest/kirin"; break;
        case 11: file = "amon/forest/masakado"; break;
        case 12: file = "amon/forest/orochi"; break;
        case 13: file = "amon/forest/pool"; break;
        case 14: file = "amon/forest/raiden"; break;
        case 15: file = "amon/forest/ryo2"; break;
        case 16: file = "amon/forest/ryo3"; break;
        case 17: file = "amon/forest/ryo4"; break;
        case 18: file = "amon/forest/ryu"; break;
        case 19: file = "amon/forest/snake"; break;
        case 20: file = "amon/forest/sound"; break;
        case 21: file = "amon/forest/tengu"; break;
        case 22: file = "amon/forest/unicorn"; break;
        case 23: file = "amon/forest/yoshitsune"; break;
      }
    swept(file);
    h = h + 1;
   }
/*
  write("Monsters done.\n");
*/
  }
  if(str == "castle") {
    while(h < 7) {
      switch(h) {
        case 0: file = "closed/guild/forest/rooms/castle"; break;
        case 1: file = "closed/guild/forest/rooms/castle2"; break;
        case 2: file = "closed/guild/forest/rooms/castle3"; break;
        case 3: file = "closed/guild/forest/rooms/castle4"; break;
        case 4: file = "closed/guild/forest/rooms/castle5"; break;
        case 5: file = "closed/guild/forest/rooms/castle6"; break;
        case 6: file = "closed/guild/forest/rooms/castle7"; break;
      }
      swept(file);
      h = h + 1;
    }
/*
    write("Hunter's castle done.\n");
*/
   }
   if(str == "hut") {
    while(h < 26) {
      switch(h) {
        case 0: file = "aroom/boy1"; break;
        case 1: file = "aroom/boy2"; break;
        case 2: file = "aroom/cat1"; break;
        case 3: file = "aroom/cat2"; break;
        case 4: file = "aroom/dream"; break;
        case 5: file = "aroom/hut"; break;
        case 6: file = "aroom/smithy"; break;
        case 7: file = "aroom/path1"; break;
        case 8: file = "aroom/path2"; break;
        case 9: file = "aroom/phut"; break;
        case 10: file = "aroom/rice"; break;
        case 11: file = "aroom/pice2"; break;
        case 12: file = "aroom/ricev"; break;
        case 13: file = "aroom/shrinear5"; break;
        case 14: file = "aroom/shrinear"; break;
        case 15: file = "aroom/shrinear2"; break;
        case 16: file = "aroom/shrinear3"; break;
        case 17: file = "aroom/shrinear4"; break;
        case 18: file = "aroom/pub1"; break;
        case 19: file = "aroom/puba"; break;
        case 20: file = "aroom/vil1"; break;
        case 21: file = "aroom/vil2"; break;
        case 22: file = "aroom/village"; break;
        case 23: file = "aroom/village2"; break;
        case 24: file = "aroom/woman1"; break;
        case 25: file = "aroom/woman2"; break;
      }
    swept(file);
    h = h + 1;
   }
/*
  write("Hut done.\n");
*/
  }
  if(str == "tower") {
    while(h < 15) {
      switch(h) {
        case 0: file = "aroom/forest/pathway"; break;
        case 1: file = "aroom/forest/pathway2"; break;
        case 2: file = "aroom/forest/pathway3"; break;
        case 3: file = "aroom/forest/pathway4"; break;
        case 4: file = "aroom/forest/around"; break;
        case 5: file = "aroom/forest/bridge"; break;
        case 6: file = "aroom/forest/bridge2"; break;
        case 7: file = "aroom/forest/tower"; break;
        case 8: file = "aroom/forest/tower2"; break;
        case 9: file = "aroom/forest/tower3"; break;
        case 10: file = "aroom/forest/tower4"; break;
        case 11: file = "aroom/forest/towerh"; break;
        case 12: file = "aroom/forest/clear"; break;
        case 13: file = "aroom/forest/pool"; break;
        case 14: file = "aroom/forest/dark"; break;
      }
    swept(file);
    h = h + 1;
   }
/*
  write("Tower done.\n");
*/
  }
  if(str == "forest") {
    while(h < 12) {
      switch(h) {
        case 0: file = "aroom/forest/forest"; break;
        case 1: file = "aroom/forest/forest2"; break;
        case 2: file = "aroom/forest/forest3"; break;
        case 3: file = "aroom/forest/forest4"; break;
        case 4: file = "aroom/forest/forest5"; break;
        case 5: file = "aroom/forest/forest6"; break;
        case 6: file = "aroom/forest/forest7"; break;
        case 7: file = "aroom/forest/forest8"; break;
        case 8: file = "aroom/forest/forest9"; break;
        case 9: file = "aroom/forest/foresto"; break;
        case 10: file = "aroom/forest/forestr"; break;
        case 11: file = "aroom/forest/forestr2"; break;
      }
    swept(file);
    h = h + 1;
   }
/*
  write("Forest done.\n");
*/
  }
  if(str == "library") {
    while(h < 10) {
      switch(h) {
        case 0: file = "lroom/library"; break;
        case 1: file = "lroom/guild"; break;
        case 2: file = "lroom/hall"; break;
        case 3: file = "lroom/h"; break;
        case 4: file = "lroom/land"; break;
        case 5: file = "lroom/library2"; break;
        case 6: file = "lroom/library3"; break;
        case 7: file = "lroom/misc"; break;
        case 8: file = "lroom/ppl"; break;
        case 9: file = "lroom/pun"; break;
      }
    swept(file);
    h = h + 1;
   }
/*
  write("Library done.\n");
*/
  }
  if(str == "juliana") {
    while(h < 7) {
      switch(h) {
        case 0: file = "mroom/juliana"; break;
        case 1: file = "mroom/juliana0"; break;
        case 2: file = "mroom/juliana1"; break;
        case 3: file = "mroom/juliana2"; break;
        case 4: file = "mroom/juliana3"; break;
        case 5: file = "mroom/juliana4"; break;
        case 6: file = "mroom/juliana5"; break;
      }
    swept(file);
    h = h + 1;
   }
/*
  write("Juliana's Tokyo done.\n");
*/
  }
  if(str == "tokyo") {
    while(h < 20) {
      switch(h) {
        case 0: file = "mroom/akihabara"; break;
        case 1: file = "mroom/akihabara2"; break;
        case 2: file = "mroom/ginza"; break;
        case 3: file = "mroom/ginza2"; break;
        case 4: file = "mroom/grass"; break;
        case 5: file = "mroom/ikebukuro"; break;
        case 6: file = "mroom/masakado"; break;
        case 7: file = "mroom/med"; break;
        case 8: file = "mroom/rehab"; break;
        case 9: file = "mroom/narita"; break;
        case 10: file = "mroom/roppongi"; break;
        case 11: file = "mroom/roppongi2"; break;
        case 12: file = "mroom/shinjuku"; break;
        case 13: file = "mroom/tokyo"; break;
        case 14: file = "mroom/ttower"; break;
        case 15: file = "mroom/ttower2"; break;
        case 16: file = "mroom/ttower3"; break;
        case 17: file = "mroom/ttower4"; break;
        case 18: file = "mroom/ttower5"; break;
        case 19: file = "mroom/ttower6"; break;
      }
    swept(file);
    h = h + 1;
   }
/*
  write("Tokyo done.\n");
*/
  }
  if(str == "all") {
  response = 1;
  what = 1;
    swept("enterance");
    swept("reg");
    swept("portal");
    sweep("hunt");
    sweep("tower");
    sweep("castle");
    sweep("hut");
    sweep("forest");
    sweep("library");
    sweep("juliana");
    sweep("tokyo");
    sweep("mon");
    click = 0;
/*
  write("~mythos/closed/play/updates.c: ALL done.\n");
*/
  what = 0;
  response = 0;
  }
return 1;}

swept(str) {
object ob, inv;
int kid_cnt;
int i, j, k, qz;
  int bb;
  ob = find_object("/players/mythos/"+str+".c");
  if(!ob) {
  if(!response)
    ROOM,"/players/mythos/"+str+" is not loaded.\n");
  return 1;}
  j = qz = 0;
  k = bb = 0;
  inv = all_inventory(ob);
  for(i=0;i<sizeof(inv);i++) {
    if(inv[i]->is_player() && !inv[i]->id("masakado") ||
       inv[i]->id("horlach_minion")) j = 1;
    if(inv[i]->fellow_monster()) qz = 1;
    if(inv[i]->is_kid()) kid_cnt ++;
    if(living(inv[i])) k = k + 1;
  /* added corpse check verte */
    if(inv[i]->id("magic box") || inv[i]->id("corpse")) { bb += 1; }
  }
  if(j) {
    ROOM,"Player is in /players/mythos/"+str+"\n");
    ROOM,k+" living in the room.\n");
  return 1;}
  if(qz) {
      ROOM,"Mizan Bot is in /players/mythos/"+str+"\n");
      ROOM,k+" living in the room.\n");
  return 1;}
  if(kid_cnt) { ROOM, "Kid in /players/mythos/"+str+"\n");
    ROOM, bb+" Boxes in room.\n");  return 1; }
  if(bb) {
    ROOM,"Magic Box in /players/mythos/"+str+"\n");
    ROOM,bb+" Boxes in room.\n");
  return 1; }
  destruct(ob);
  ROOM,"/players/mythos/"+str+" has been updated.\n");
    if(k)
  ROOM,k+" living were in the room.\n");
return 1;}

heart_beat() {
click = click + 1;
if(click > TRIGGER) {
  cycle = 1;
  this_object()->sweep("all");
  if(find_player("mythos")) { tell_object(find_player("mythos")," ** Updater speaks: Cleaned, Sir.\n"); }
  cycle = 0;
  click = 0; }
  /*
  call_out("hb",3);
  return 1;  */
}

click_check() {
  write(click+" has gone by\n"+
        (TRIGGER - click)+" left to go till next set.\n");
return 1; }
