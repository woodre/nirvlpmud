/*
 * LiquidRoomDM.c Version 1.2
 *
 * I didnt expect that LiquidRoom.c would get along so well with
 * RandomRoom.c  The initial liquid room configuration system was
 * scrapped because of its complexity (but more so its memory draw).
 *
 * This is not just a compromise, but a happy union of sorts *boggle*
 *
 * Wormholes and jumptos are fully supported in this version.
 *
 * Communications work, but nicknames and semi-guildlike functions have
 * to be streamlined to work in this code.
 *
 * Indexing will not be supported as yet, but will be as soon as a I
 * figure out how to port it to the RandomRoomDM.c
 *
 */

#define HOME "/players/mizan/core/02h/room04.c"
#define ROOMDIR "players/mizan/etheriel/ROOMS/"
#define LISTENING_ROOM "/players/mizan/core/02h/room02.c"

string reset_time;
int wormholes;
int tunnels;
int randoms;
int area_tells;
int thinktos;
int pushing;

id(str) { return str == "pump"; }

short() { return "The LiquidRoom pump [Version 1.2]"; }

long() {
  write("This is the LiquidRoom pump, which handles all of the liquid\n"+
	"functions and wormhole teleports in Mizan's area.\n"+
        "A service sticker on it reads:\n"+
        "Some semi-guild functions _not_ supported on this version.\n"+
	"(Channel tracking, garbling, and nicknames).\n"+
	"[Version 1.2]\n");
  if(tunnels) {
    write("The LCD display labelled 'Total wormholes formed' reads [" + tunnels + "].\n");
  }
  if(thinktos) {
    write("The LCD display labelled 'Total thinktos called' reads [" + thinktos + "].\n");
  }
  if(wormholes) {
    write("The LCD display labelled 'Total jumps executed' reads [" + wormholes + "].\n");
  }
  if(pushing) {
    write("The LCD display labelled 'Total objects pushed' reads [" + pushing + "].\n");
  }
  if(area_tells) {
    write("The LCD display labelled 'Total bleats echoed' reads [" + area_tells + "].\n");
  }
  if(randoms) {
    write("The LCD display labelled 'Total randoms called' reads [" + randoms + "].\n");
  }
  if(reset_time) {
    write("The pump last experienced a reset at " + reset_time + ".\n");
  }
}

reset(arg) {
  reset_time = ctime();
  if(arg) return 0;
  move_object(this_object(), HOME);
}

randoms() 
{
    string rand;
    if(this_player()->query_sp() < 8) 
    {
        write("You are too tired to do that right now.\n");
        return 1;
    }
    write("You set yourself adrift in the current and arrive elsewhere...\n");
    rand=call_other("/players/mizan/closed/RandomRoomDM", "one_random", 0);
    this_player()->add_spell_point(-8);
    this_player()->move_player("with the current#players/mizan/etheriel/ROOMS/" + rand);
    tell_room(LISTENING_ROOM, "LiquidRoomDM.c reports: " + this_player()->query_name() + " drifts random '" + rand + "'.\n");

    return 1;
}


/* 03/13/06 Earwax: Commenting this out, keeps bugging, clashing
 * with a wizard's workroom short, and this is unnecessary anyways.
 */
bleat(str) 
{
/*
    object ob;
    int v;
    ob=users();

    for(v=0; v<sizeof(ob); v++) 
    {
        string oc,od;
        if(ob[v]) if(ob[v]->query_level() > 0)
        if(ob[v] && environment(ob[v])) 
        { 
            oc=environment(ob[v])->short();
            if(oc && sscanf(oc, "Plane of Etherie%s", od) == 1 || ob[v]->query_real_name() == "mizan") 
            {
                tell_object(ob[v], str);
            }
        }
    }
*/

    /* update the listening post too */
    tell_room(LISTENING_ROOM, "LiquidRoomDM.c reports: '" + str + "'\n");

}

area_tell(str) 
{
  object ob;
  string temp,a,b;
  int v;
  a=environment(this_player())->short();
  if(sscanf(a, "Plane of Etherie%s", b) != 1) {
    write("You fail.\n");
    return 1;
  } 
  if(!str) {
    write("You must give a message.\n");
    return 1;
  }
  if(str == "list") {
    area_tell_people();
    return 1;
  }
  if(sscanf(str, ":%s", temp) == 1) {
    temp = "(bleat) " + (this_player()->query_name()) + " " + temp + "\n";
    temp = format(temp, 70);
  } else {
    temp = (this_player()->query_name()) + " bleats: " + str + "\n";
    temp = format(temp, 70);
  }
  ob=users();
  for(v=0; v<sizeof(ob); v++) {
    string oc,od;
    if(ob[v] && environment(ob[v])) { 
      oc=environment(ob[v])->short();
        if(sscanf(oc, "Plane of Etherie%s", od) == 1 ||
         ob[v]->query_real_name() == "mizan") {
        tell_object(ob[v], temp);
      }
    }
  }
  area_tells=area_tells + 1;
 /*
  write_file("/players/mizan/logs/BLEATS",temp);
 */
  return 1;
}

area_tell_people() {
  object ob;
  string temp,a,b;
  int v;
  a=environment(this_player())->short();
  if(sscanf(a, "Plane of Etherie%s", b) != 1) {
    write("You fail.\n");
    return 1;
  } 
  ob=users();
  temp = " ";
  for(v=0; v<sizeof(ob); v++) {
    string oc,od;
    if(environment(ob[v])) {
      oc=environment(ob[v])->short();
             if(sscanf(oc, "Plane of Etherie%s", od) == 1 &&
             !ob[v]->query_invis()) {
              temp = temp + capitalize(ob[v]->query_real_name()) + ", ";
        }
    }
  }
  temp = "Players currently in the Plane of Etheriel:" + temp;
  temp = format(temp, 70);
  write(temp + "\n");
  return 1;
}

jumpto(str) {
  object ob,oc;
  string test1,a,b;
  a=environment(this_player())->short();
  if(sscanf(a, "Plane of Etherie%s", b) != 1) {
    write("You fail.\n");
    return 1;
  } 
  ob=find_player(str);
  if(!ob) {
    write("'" + str + "' is not logged in.\n");
    return 1;
  }
  if(!environment(ob)) {
    write("You fail.\n");
    return 1;
  }
  if(creator(environment(ob)) != "mizan") {
    write("Your sensitive mind notices a wrongness in space [tm].\n");
    return 1;
  }
  if(sscanf(object_name(environment(ob)), "players/mizan/etheriel/ROOM%s", test1) != 1) {
    write("You try, but fail.\n");
    return 1;
  }
  if(this_player()->query_sp() < 55) {
    write("You mind is too cluttered to attempt this.\n");
    return 1; 
  }
  if(ob->query_attack()) {
    write("Something going on in the area is preventing entry.\n");
    return 1;
  }
  if(this_player()->query_attack()) {
    write("You are too busy fighting to do this.\n");
    return 1;
  }
  this_player()->add_spell_point(-55);
  write("You tear a rip into the fabric of the ether-muck and dive in.\n");
  tell_room(environment(this_player()),
  (this_player()->query_name()) + " tears open a hole in the ether-muck and dives in.\n");
  move_object(this_player(), environment(ob));
  write("You arrive next to " + (ob->query_name()) + ".\n");
  tell_room(environment(this_player()),
  (this_player()->query_name()) + " pops in through a wormhole.\n");

    tell_room(LISTENING_ROOM, "LiquidRoomDM.c reports: " + this_player()->query_name() + " triggers jumpto '" + str + "'.\n");

  wormholes=wormholes + 1;
  return 1;
}

wormhole(str) {
  object ob,oc;
  string over_there,right_here,temp,a,b,c;
  c=environment(this_player())->short();
  if(sscanf(c, "Plane of Etherie%s", b) != 1) {
    write("You fail.\n");
    return 1;
  } 
  if(!str) {
    write("Build a tunnel to where?\n");
    return 1;
  }
  if(this_player()->query_sp() < 15) {
    write("You feel too mentally drained to do that right now.\n");
    return 1;
  }
  over_there = ROOMDIR + str;
  right_here = object_name(environment(this_player()));
  if(!find_object(over_there)) {
/*
  if(!file_size(over_there) < 1) {
 */
    write("You are not too sure how to build a tunnel to reach there.\n");
    return 1;
  }
  if(over_there == object_name(environment(this_player()))) {
    write("That would not require a tunnel.\n");
    return 1;
  }
  if(present("liquid-tunnel", environment(this_player()))) {
    write("There is already a tunnel here.\n");
    return 1;
  }
  if(sscanf(right_here, "%sayers/mizan/etheriel/ROOMS/%s", a, temp) != 2) {
    write("You make the wormhole, but it collapses on itself in failure.\n");
    say((this_player()->query_name()) + " tries to make a wormhole but it died.\n");
    return 1;
  }
  ob=clone_object("players/mizan/closed/liquid-tunnel.c");
  ob->set_terminus(str);
  move_object(ob, right_here);
  this_player()->add_spell_point(-15);
  write("You concentrate intensely... and the path to " + str + " is revealed!\n");
  tell_room(environment(this_player()),
   (this_player()->query_name()) + " thinks real hard and a tunnel appears.\n");
  tell_room(find_object(over_there),
   "The ether-muck bubbles and bloops around you.\n");

    tell_room(LISTENING_ROOM, "LiquidRoomDM.c reports: " + this_player()->query_name() + " creates wormhole to destination '" + str + "'.\n");
  
  return 1;
}

thinkto(str) {
  object ob;
  string placename,temp2;
  if(!str) return 0;
  if(this_player()->query_sp() < 8) {
    write("You are too mentally drained to do this right now.\n");
    return 1;
  }
  ob=find_player(str);
   if(!find_player(str)) {
/* WALDO modifications */
    if(str == "waldo" || str == "Waldo") {
      write("Something tells you: Find Waldo? Eek.\n");
      return 1;
   }
/* WALDO end... */
     if(!(ob=find_living(str))) {
      write("You could not locate " + str + ".\n");
      return 1;
    }
  }
    if(!environment(ob)) {
    write("You cannot determine the exact whereabouts of " + str + ".\n");
    tell_room(environment(this_player()),
    (this_player()->query_name()) + " is left in a steep bogglement.\n");
    return 1; }
  placename = object_name(environment(ob));
  if(sscanf(placename, "players/mizan/etheriel/ROOMS/%s", temp2) != 1) {
    write("You cannot determine the exact whereabouts of " + str + ".\n");
    tell_room(environment(this_player()),
    (this_player()->query_name()) + " is left in a steep bogglement.\n");
    return 1;
  }
  thinktos = thinktos + 1;
  this_player()->add_spell_point(-8);
  tell_room(environment(this_player()),
  (this_player()->query_name()) + " goes into a brief contemplative trance.\n");

  tell_room(LISTENING_ROOM, "LiquidRoomDM.c reports: " + this_player()->query_name() + " triggers thinkto '" + str + "'.\n");
  write("Your inner voice tells you: Go '" + temp2 + "'.\n");
  return 1;
}

stir_room(str) {
  object room;
  string placename;
  if(this_player()->query_sp() < 20) {
    write("You feel too weak to do that.\n");
    return 1;
  }
  if(!str) {
    placename = object_name(environment(this_player()));
  } else {
    placename = "players/mizan/etheriel/ROOMS/" + str;
  }
  if(!find_object(placename)) {
    write("You concentrate intently but cannot seem to stir up location " + str + ".\n");
    return 1;
  }
  room=find_object(placename);
  if(room->query_zokko()) {
    write("The ether-muck is much too thick for you to stir up.\n");
  return 1;
  }
  write("You stir up the ether-muck.\n");
  tell_room(room, "The ether-muck around you swirls and dilates.\n");
  call_other(placename, "exit_shuffle");
  if(!str) { call_other(placename, "init"); }

  tell_room(LISTENING_ROOM, "LiquidRoomDM.c reports: " + this_player()->query_name() + " stirs room.\n");
  
  call_other(this_player(), "look");
  this_player()->add_spell_point(-20);
  return 1;
}

push(str) {
  object ob;
  string vict,dest,placename;
  string test1;
  int i;
  if(!str) return 0;
  if(sscanf(str, "%s %s", vict, dest) != 2) return 0;
  ob=present(vict, environment(this_player()));
  placename = "/players/mizan/etheriel/ROOMS/" + dest;
  if(!ob) {
    return 0;
  }
  if(!find_object(placename)) {
    write("You are not too sure how to push something there.\n");
    return 1;
  }
  if(vict == "tunnel" || vict == "wormhole") {
    write("You try, but pushing a matter-less object is kind of... difficult.\n");
    return 1;
  }
  if(vict == "tiamat" || vict == "hydra" || vict == "dragon") {
    write("Something tells you: You've GOT to be kidding, man...\n");
    return 1;
  }
    if(dest == "spoogle" || dest == "linna") {
    write("You try, but for some reason, you fail.\n");
    return 1;
  }
  if(!living(ob)) {
    test1 = object_name(environment(this_player()));
    if(test1 == "players/mizan/etheriel/ROOMS/spoogle" ||
      test1 == "players/mizan/etheriel/ROOMS/linna") {
      write("The damn thing refuses to move.\n");
      return 1;
    }
    if(this_player()->query_sp() < 5) {
      write("You try, but you're too mentally drained to move " + vict + ".\n");
      return 1;
    }
    write("You push " + (ob->short()) + " towards " + dest + ".\n");
    tell_room(environment(this_player()),
    (this_player()->query_name()) + " pushes " + (ob->short()) + " towards " + dest + ".\n");
    move_object(ob, placename);
    tell_room(find_object(placename), (ob->short()) + " drifts into view.\n");

    
    this_player()->add_spell_point(-5);
    return 1;
  }
 /*
  test1=object_name(ob);
  if(test1 == "players/mizan/closed/tiamat5") {
    write("Doh! Are you nuts?\n");
    return 1;
  }
 */
 if(living(ob)) {
  i=ob->query_level() - 1;
  if(this_player()->query_level() < i) {
    write("You are not strong enough to push " + vict + ".\n");
    return 1;
  }
  if(this_player()->query_sp() < i) {
    write("You try, but you're too mentally tired to move " + vict + ".\n");
    return 1;
  }
  write("You push " + (ob->short()) + " towards " + dest + ".\n");
    tell_room(LISTENING_ROOM, "LiquidRoomDM.c reports: " + this_player()->query_name() + " pushes '" + ob->short() + "' to '" + dest + "'.\n");
  tell_room(environment(this_player()),
  (this_player()->query_name()) + " pushes " + (ob->short()) + " towards " + dest + ".\n");
  move_object(ob, placename);
  tell_room(find_object(placename), (ob->short()) + " drifts into view.\n");
  this_player()->add_spell_point(-(5 + i));
  pushing = pushing + 1;
  return 1;
  }
 return 1;
}

