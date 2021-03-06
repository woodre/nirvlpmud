#include "std_old.h"
#include "/players/jaraxle/ansi.h"
#define NUMBER_OF_ITEMS 3
int inv_no,done,shield, notin;
int lighton;
int hit_val,miss_val;
string filename,long_dsc,owner_name;

init() {
  if (!done) {
    owner_name="nobody";
    done = 1;
  }
  add_action("on"); add_verb("lock");
  add_action("invite","invite");
  add_action("restore"); add_verb("restore");
  add_action("store"); add_verb("store");
  add_action("off"); add_verb("unlock");
  add_action("south"); add_verb("south");
  add_action("add_to_long"); add_xverb("@");
  add_action("clear_long"); add_verb("clear");
  add_action("junk","replace");
  add_action("list","list");
  add_action("light_switch","switch");
     add_action("look", "look");
     add_action("look", "l");
     add_action("look", "examine");
     add_action("look", "search");
  if (this_player()->query_real_name() != "boltar")
  if (this_player()->query_real_name() != owner_name && shield == 1) {
    write(capitalize(owner_name) + " has the room locked.\n");
    write("You are transported to the lobby.\n");
  this_player()->move_player("after tring to enter the room#players/boltar/templar/private");
  }
  }
static on() {
  shield = 1;
  write("Room locked.\n");
  return 1;
}
static off() {
  if (call_other(this_player(), "query_real_name", 0) != owner_name) {
    write("You are not allowed to do that!\n");
    return 1;
  }
  shield = 0;
  write("The room is unlocked.\n");
   return 1;
}

short() {
  return capitalize(owner_name) + "'s Templar room ["+GRN+"Fortress Stone"+NORM+"]";
}
long() {
  if (!long_dsc) {
    write("You are in " + capitalize(owner_name) +"'s Templar room.\n");
    write ("Use 'clear' to clear room description.\n");
    write ("Use '@desc' to add a line to room description.\n");
  }
  if(long_dsc) write (long_dsc);
  if (shield == 1) write ("The door is locked to others.\n");
  if (shield == 0 ) write ("The door is unlocked.\n");
  write("The only exit is south.\n");
}

south() {
  call_other(this_player(), "move_player", "south#players/boltar/templar/private.c");
  return 1;
}
set_owner(str){
  set_light( 1);
  owner_name = str;
  done = 1;
  filename = allocate(30);
  hit_val = allocate(30);
  miss_val = allocate(30);
  restore_object("players/boltar/templar/room/" + owner_name);
  save_object("players/boltar/templar/room/" + owner_name);
  return 1;
}
add_to_long(str){
  if (call_other(this_player(), "query_real_name", 0) != owner_name) {
     return 0;
}
if (!long_dsc) long_dsc = "";
  long_dsc = long_dsc + str;
  long_dsc = format(long_dsc, 78);
  save_object("players/boltar/templar/room/" + owner_name);
  return 1;
}
clear_long(){
  if (call_other(this_player(), "query_real_name", 0) != owner_name) {
     return 0;
  }
  long_dsc = "";
  return 1;
}
store(){
  object all_stuff;
  int count;
  string sf,creator_name,first,filetmp,junk;
  string livfl;
  if(this_player()->query_real_name() != owner_name){
    write("Only the owner of the room may store objects.\n");
    return 1;
  }
  all_stuff = allocate(30);
  all_stuff =all_inventory(this_object());
  count = 0;
  if (inv_no > 0) {
    write ("please do a 'restore' first.\n");
    return 1;
  }
  inv_no = 0;
  while (inv_no < NUMBER_OF_ITEMS && count < sizeof(all_stuff)) {
  if (call_other(all_stuff[count], "query_save_flag",0))
    sf = "NOSAVE";
  if (!call_other(all_stuff[count], "query_save_flag", 0)){
    filetmp=file_name(all_stuff[count]);
    sscanf(filetmp, "%s/%s", first, junk);
    if(all_stuff[count]->generic_object())
      first = "OK";
    if (first != "players") {
      if (creator(all_stuff[count]) && creator(all_stuff[count])!="boltar") {
        call_other(all_stuff[count], "save_thing",
          "players/"+creator(all_stuff[count])+"/hoteltmp");
        creator_name=creator(all_stuff[count]);
        sscanf(filetmp, "%s#%s", filename[inv_no],junk);
        destruct(all_stuff[count]);
        all_stuff[count] = clone_object(filename[inv_no]);
        call_other(all_stuff[count], "restore_thing","players/"+creator_name+"/hoteltmp");
        move_object(all_stuff[count], this_object());
      }
      if (call_other(all_stuff[count], "save_thing","players/boltar/templar/room/q"+owner_name + inv_no)){
        filetmp = file_name(all_stuff[count]);
        sscanf(filetmp, "%s#%s", filename[inv_no], junk);
        write (call_other(all_stuff[count], "short", 0) + " SAVED.\n");
        destruct(all_stuff[count]);
        inv_no +=1;
      } else {
        write (call_other(all_stuff[count], "short", 0)+" NOT SAVED.\n");
      }
    }
    if (first == "players") {
      if(living(all_stuff[count]) && !all_stuff[count]->living_save())
        livfl="NO";
      filetmp = file_name(all_stuff[count]);
      if (!livfl){
        sscanf(filetmp, "%s#%s",filename[inv_no],junk);
        write (call_other(all_stuff[count], "short",0) + " SAVED.\n");
        hit_val[count] = all_stuff[count]->query_hits();
        miss_val[count] = all_stuff[count]->query_misses();
        destruct(all_stuff[count]);
        inv_no += 1;
      }
    }
    count += 1;
  }
  if (sf == "NOSAVE") {
    write(call_other(all_stuff[count], "short",0)+ " NOT SAVED, this object is non-storable .\n");
    count += 1;
    sf = "SAVE";
  }
  }
  save_object("players/boltar/templar/room/"+owner_name);
  return 1;
}
restore(){
   object thing;
   string a,b;
   int count;
   string first,junk;
   if(this_player()->query_real_name() != owner_name){
     write("Only the owner of the room may restore objects.\n");
     return 1;
   }
   count = 0;
     while (count < inv_no) {
     if (filename[count] == "none") {
       write("Nothing more to restore.\n");
        inv_no = 0;
         return 1;
        }
/*
      if(file_size("/"+filename[count]+".c") < 1)
    {
        write(filename[count] + "\n");
       write("The object stored is no longer avialible for restoration.\n");
       write("A watch is being substituted.\n");
          filename[count]="players/boltar/things/watch";
       }
    */
     if(sscanf(filename[count], "%slancer%s", a,b) == 2) {
        filename[count]=a+"cyrex"+b;
     }
       thing = clone_object(filename[count]);
     if(thing) {
        sscanf(filename[count], "%s/%s", first, junk);
/*
     if(extract(filename[count], 0, 27) == "players/boltar/things/sarmor")
*/
     if(thing->generic_object())
      {
     first = "OK";
     }
        if (first != "players")
      call_other(thing, "restore_thing", "players/boltar/templar/room/q"+owner_name + count);
       move_object(thing, this_object());
       filename[count] = "none";
       write(call_other(thing, "short",0) + " RESTORED.\n");
       }
      if(first == "players") {
        thing->set_hits(hit_val[count]);
        thing->set_misses(miss_val[count]);
       }
       count +=1;
      }
    inv_no = 0;
    save_object("players/boltar/templar/room/"+owner_name);
    return 1;
  }
/*
invite(str) {
object guest;
    guest=find_player(str);
  if(!guest)
   {
   write(str+" is not currently logged in.\n");
   return 1;
   }
  if(file_name(environment(guest)) != "players/boltar/templar/private")
    {
   write(str+" is not in the lobby.\n");
   return 1;
   }
  if (shield == 1)
   {
    write("You must unlock the door first.\n");
    return 1;
   }
  move_object(guest,this_object());
    tell_room("/players/boltar/templar/private.c", guest->query_name() + " is pushed into the portal by an unseen force.\n");
   write(str+" has been allowed to enter.\n");
   tell_object(guest, " you are pushed into the portal by some unseen force.\n");
   write(str + " arrives.\n");
   return 1;
}
*/
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
invite(str) {
object guest;
object blah;
  if(!str) return 0;
    guest=find_player(str);
    if(guest == this_player()) { 
      write("Yourself?\n");
      return 1;
    }
  if(!guest)
   {
   write(str+" is not currently logged in.\n");
   return 1;
   }
  if(guest->query_level() > 20) {
    write("You cannot invite wizards.\n");
    return 1;
  }
  if (shield == 1)
   {
    write("You must unlock the door first.\n");
    return 1;
   }
   if(present("summons",guest)) {
     write(capitalize(str)+" already has a summons.\n");
     return 1;
   }
  if(this_player()->query_real_name() != owner_name) {
   write("You are not the owner of this room.\n");
   return 1;
  }
  tell_object(guest, this_player()->query_name()+" has invited you to a "+
  "private room in Templar Castle.\nIf you wish to accept type accept, the"+
  " summons can be disposed of by droping it.\n");
  blah=clone_object("/players/boltar/templar/summons");
  blah->set_room(this_object());
  move_object(blah,guest);
  write("You invite "+str+"\n");
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
  if (str == "instructions" || str == "at instructions") {
    write("You can do the following in your room:\n");
    write("\n");
    write("lock\t\t Locks the door to prevent others from entering.\n");
    write("unlock\t\t Unlocks the door so others may enter.\n");
    write("invite <name>\t Bring <name> from the lobby to your room.\n");
    write("store\t\t Put your items into storage.\n");
    write("restore\t\t Bring your items out of storage.\n");
    write("list\t\t Lists items in storage.\n");
    write("replace #\t Replaces item # in storage with a cookie. Use when an\n");
    write("         \t cannot be restored.\n");
    write("switch\t\t Turn the lights on or off.\n");
    write("@<descline>\t Adds <descline> to the description of the room.\n");
    write("clear\t\t Clears the room description.\n");
    return 1;
  }
  return 0;
}
