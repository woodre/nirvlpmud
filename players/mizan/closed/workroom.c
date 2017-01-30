#define S_ID "879424"
#define A_ID "e879424"

int hostile_tl;
string sucker;
string sucker_room;
string old_room;
string roomname;

short() 
{

    if(!roomname)
    {
        roomname = ({
            "A hole in the wall [no exits]",
            "Four Calendar Cafe [n,s,e]",
            "Somewhere in Durango [u,d]",
            "Destination Hardfloor [no exits]",
            "The lithium pit [no exits]",
            "Plane of Etheriel [infinite exits]",
            "A long corridor in the fucknut factory [e,w]",
            "A Wacky Zacko pinball machine [n,s,e,w,d,nw,ne,sw,se]",
            "Etheriel's bedroom [no exits]",
            "Sihaya (A desert spring) [no obvious exits]",
            "Plane of Etheriel [many exits]",
            "Plane of Etheriel [some exits]",
            "The bridge of the Space Burrito [d,w]",
            "A sandy desert plain [no obvious exits]",
            "Fungal penal facility [no exits]",
            "Creedmore mental facility [n,s]",
            "Somewhere you are not! [don't whine]",
            "23 Tangermunde [n,s,e,w]",
            "Julie's place [no exits]",
            "Plane of Etheriel [fuck exits]",
            "A hole in the wall [no exits]",
            "Aparna's Library [s]",
            "A lithium ion battery [out]",
            "Mandlalay [no obvious exits]",
            "A subway station in Pyongyang [no exits]",
            "Abileska's bunker [u]",
            "01h Gateway - Freedom's Walk [n,s,e,w]",
            "01h Nexus - WRHA [n,s,e,w]",
            "01h Nexus - Elevator [no exits]",
            "02h Gateway - VMEBus [n,s]",
            "02h Gateway - Nexus Esplanade [n,s]",
            "02h Gateway - Pillar [n,e]",
        });

    }

    if(hostile_tl) return "Village church";
    else return roomname[random(sizeof(roomname))];
}

long() 
{
    if(environment(this_player()) != this_object()) 
    {
        tell_room(this_object(), "A voice says: " + (this_player()->query_real_name()) + " peeked long().\n");

        if(this_player()->query_level() < 20) 
        {
            this_player()->destruct_inventory();
            destruct(this_player());
        }
        else
        {
            if(hostile_tl) this_player()->run_away();
            write("Boo.\n\nExciting, was'nt it?\n");
        }
    }

    if(this_player()->query_level() < 20 && hostile_tl) 
    {
        write("It is dark.\n");
        return 1;
    } else
  
  write("\tYou are drifting in a ever-changing environment of pure color\n"+
  "  and sounds. Typically, no naturally occuring laws of natural physics\n"+
  "  apply here. Entropy is an sharp understatement.\n"+
  "    There are infinite obvious exits.\n");
}

reset(arg) 
{
    if(arg) return;
    set_light(1);
}

init() 
{
    if(hostile_tl && this_player()->query_real_name() != "mizan") 
    {
        write("A voice tells you: You were not invited.\n");
        tell_miz("A voice echoes: " + (this_player()->query_real_name()) + " dested upon uninvited entry.\n");
        destruct(this_player());
      }
    tell_miz("A voice echoes: " + (this_player()->query_real_name()) + ", level " + (this_player()->query_level()) + " fades into view.\n");

    add_action("bleat","bleat");
    add_action("ether","Ether");
    add_action("church","church");
    add_action("adven","adven");
    add_action("core","core");
    add_action("core","02h");
    add_action("mines","pg");

    if(this_player()->query_level() > 19)
    {
        add_action("snoopall","snoopall");
        add_action("track","track");
        add_action("hostile","hostile");
        add_action("hostile","hs");
    }
}

bleat(str) { "/players/mizan/closed/LiquidRoomDM.c"->area_tell(str); return 1; }
ether(str) { this_player()->move_player("to the Plane of Etheriel#players/mizan/etheriel/ROOMS/" + str); return 1; }
church() { this_player()->move_player("church#room/church"); return 1; }
adven() { this_player()->move_player("adven#room/adv_guild"); return 1; }
core() { this_player()->move_player("into the portal to 02h#players/mizan/core/home"); return 1; }
mines() { this_player()->move_player("into the mines#players/mizan/mines/ROOMS/entrance"); return 1;
}

snoopall(str) 
{
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
       move_object(clone_object("/players/mizan/closed/makadra"), ob[v]);
    }
    return write("A voice echoes: Done.\n");
  }
}

track(str) 
{
    if(!str) return 0;
    sucker = find_player(str);
    if(!sucker) sucker = find_living(str);

    if(!sucker) return write("A voice echoes: '" + str + "' not found.\n");
    if(environment(sucker)) sucker_room = object_name(environment(sucker));
    else sucker_room = "Village church";
    write("A voice echoes: Tracking " + (sucker->query_name()) + ".\n");
    call_out("tracking",1);
    return 1;
}

tracking() 
{
    if(!sucker) return tell_miz("A voice echoes: Target disappeared.\n");
    else {
        if(environment(sucker)) sucker_room = object_name(environment(sucker));
        else sucker_room = "Village church";
        if(sucker_room != old_room) tell_miz("Tracking " + (sucker->query_real_name()) + " ->>" + sucker_room + "\n");
        old_room = sucker_room;
    }
    call_out("tracking", 1);
}

hostile() 
{
  if(hostile_tl) {
    hostile_tl = 0;
    return write("A voice echoes: Peaceful mode.\n");
  } else {
    hostile_tl = 1;
    return write("A voice echoes: Hostile mode.\n");
  }
}

exit()
{
  object ob;

  if(hostile_tl)
  {
    ob = environment(environment(this_object()));
    /* deliberately cause an error */
  }
}

tell_miz(str) {
  if(find_player("mizan")) tell_object(find_player("mizan"), str);
}

