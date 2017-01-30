#define S_ID "8322"
/* copied from boltar, some alterations done for personal use -Bp */

int hostile_tl;
string sucker;
string sucker_room;
string old_room;

short() {
  string shr;
  shr = allocate(21);
  shr[0]="Elvis land [no exits]";
  shr[1]="Engineering One [n,s,w]";
  shr[2]="Orbit [u,d]";
  shr[3]="Destination Hardfloor [no exits]";
  shr[4]="The NDF wind tunnel [small exits]";
  shr[5]="Bridgepit [infinite exits]";
  shr[6]="A long empty hallway [e,w]";
  shr[7]="A Wacky Zacko pinball machine [n,s,e,w,d,nw,ne,sw,se]";
  shr[8]="A 1970 Galaxie 500XL [l,r,u]";
  shr[9]="A 1969 Mach 1 [l,r]";
  shr[10]="An empty room [no exits]";
  shr[11]="A room full of junk [hidden exits]";
  shr[12]="The bridge of the Space Burrito [d,w]";
  shr[13]="A sandy desert plain [no obvious exits]";
  shr[14]="Fungal penal facility [no exits]";
  shr[15]="Creedmore mental facility [n,s]";
  shr[16]="Somewhere you are not! [don't whine]";
  shr[17]="23 Tangermunde [n,s,e,w]";
  shr[18]="Julie's place [no exits]";
  shr[19]="Plane of Etheriel [fuck exits]";
  shr[19]="A hole in the wall [no exits]";
  if(hostile_tl) return "Village church";
  else return shr[random(20)];
}

long() {
  if(environment(this_player()) != this_object()) {
    tell_room(this_object(), "A voice says: " + (this_player()->query_real_name()) + " attempted a peek of long(). Eliminated.\n");
    if(this_player()->query_level() < 20) {
      this_player()->destruct_inventory();
      destruct(this_player());
    } else {
      if(hostile_tl) this_player()->run_away();
      write("Boo.\n\nExciting, was'nt it?\n");
    }
  }
  if(this_player()->query_level() < 20 && hostile_tl) {
    write("It is dark.\n");
    return 1;
  } else
  write("\tYou are drifting in a ever-changing environment of pure color\n"+
  "  and sounds. Typically, no naturally occuring laws of natural physics\n"+
  "  apply here. Entropy is an sharp understatement.\n"+
  "    There are infinite obvious exits.\n");
}

reset(arg) {
}

init() {
  if(hostile_tl && this_player()->query_real_name() != "boltar") {
    write("A voice tells you: You were not invited.\n");
    tell_miz("A voice echoes: " + (this_player()->query_real_name()) + " dested upon uninvited entry.\n");
    destruct(this_player());
  }
  tell_miz("A voice echoes: " + (this_player()->query_real_name()) + ", level " + (this_player()->query_level()) + " fades into view.\n");
    add_action("bleat","bleat");
  add_action("church","church");
  add_action("adven","adven");
  add_action("snoopall","snoopall");
  add_action("track","track");
  add_action("hostile","hostile");
  add_action("hostile","hs");
  add_action("snall_con", "sa");
}

bleat(str) { return "/players/boltar/closed/LiquidRoomDM.c"->area_tell(str); }
church() { return this_player()->move_player("church#room/church"); }
adven() { return this_player()->move_player("adven#room/adv_guild"); }

snoopall(str) {
  object ob;
  int v;
  ob=users();
  if(str && str == "stop") {
    for(v=0; v<sizeof(ob); v++) {
      object of;
      of=present(S_ID, ob[v]);
      if(of) destruct(of);
    }
    return write("A voice echoes: Ok.\n");
  } else {
    for(v=0; v<sizeof(ob); v++) {
      object oc;
      oc=present(S_ID, ob[v]);
      if(!oc && ob[v]->query_level() < 21)
       move_object(clone_object("/players/boltar/closed/makadra"), ob[v]);
    }
    return write("A voice echoes: Done.\n");
  }
}

track(str) {
  if(!str) return 0;
  sucker = find_player(str);
  if(!sucker) return write("A voice echoes: '" + str + "' not found.\n");
  if(environment(sucker)) sucker_room = file_name(environment(sucker));
  else sucker_room = "Village church";
  write("A voice echoes: Tracking " + (sucker->query_name()) + ".\n");
  call_out("tracking",1);
}

tracking() {
  if(!sucker) return tell_miz("A voice echoes: Target disappeared.\n");
  else {
    if(environment(sucker)) sucker_room = file_name(environment(sucker));
    else sucker_room = "Village church";
    if(sucker_room != old_room) tell_miz("Tracking " + (sucker->query_real_name()) + " ->>" + sucker_room + "\n");
    old_room = sucker_room;
  }
  call_out("tracking", 1);
}

hostile() {
  if(hostile_tl) {
    hostile_tl = 0;
    return write("A voice echoes: Peaceful mode.\n");
  } else {
    hostile_tl = 1;
    return write("A voice echoes: Hostile mode.\n");
  }
}

tell_miz(str) {
  if(find_player("boltar")) tell_object(find_player("boltar"), str);
}

snall_con(str) {
object pof;
     pof=find_player(str);
write("---->"+str+"\n");
   if(str && pof) {
     object of;
     of=present(S_ID,find_player(str));
     if(!of) move_object(clone_object("/players/boltar/closed/makadra.c"), pof);
     else
      destruct(of);
}
return 1;
}
