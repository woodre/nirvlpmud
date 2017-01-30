/*
 * LiquidRoomDM.c Version 1.1
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

#define HOME_R "/players/mizan/workroom"
#define ROOMDIR "players/mizan/etheriel/ROOMS/"

int wormholes;
int tunnels;
int area_tells;

id(str) { return str == "pump"; }

short() { return "The LiquidRoom Pump [Version 1.1]"; }

long() {
  write("This is the LiquidRoom Pump, which handles all of the liquid\n"+
	"functions and wormhole teleports in Mizan's area.\n"+
        "A service sticker on it reads:\n"+
        "Semi-guild functions _not_ supported on this version.\n"+
	"(Channel tracking, garbling, and nicknames).\n"+
	"[Version 1.1]\n");
  if(wormholes) {
    write("The LCD display labelled 'Total jumps executed' reads [" + wormholes + "].\n");
  }
  if(tunnels) {
    write("The LCD display labelled 'Total wormholes formed' reads [" + tunnels + "].\n");
  }
  if(area_tells) {
    write("The LCD display labelled 'Total area echoes' reads [" + area_tells + "].\n");
  }
}

reset(arg) {
  if(arg) return 0;
  move_object(this_object(), HOME_R);
}

area_tell(str) {
  object ob;
  string temp;
  int v;
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
  } else {
    temp = (this_player()->query_name()) + " bleats: " + str + "\n";
  }
  ob=users();
  for(v=0; v<sizeof(ob); v++) {
    string oc,od;
    if(environment(ob[v])) {
      oc=environment(ob[v])->short();
              if(sscanf(oc, "Plane of Etherie%s", od) == 1) {
        tell_object(ob[v], temp);
      }
    }
  }
  area_tells=area_tells + 1;
  return 1;
}

area_tell_people() {
  object ob;
  int v;
  string temp;
temp = " ";
  ob=users();
  for(v=0; v<sizeof(ob); v++) {
    string oc,od;
    if(environment(ob[v])) {
        oc=environment(ob[v])->short();
        if(sscanf(oc, "Plane of Etherie%s", od) == 1 ) {
          temp = temp + capitalize(this_player()->query_real_name());
        }
    }
  }
  temp = "Players currently in the Plane of Etheriel:" + temp + ", ";
  temp = format(temp, 70);
  write(temp + "\n");
  return 1;
}

jumpto(str) {
  object ob;
  string test1;
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
  if(sscanf(file_name(environment(ob)), "players/mizan/etheriel/ROOM%s", test1) != 1) {
    write("You try, but fail.\n");
    return 1;
  }
  if(this_player()->query_sp() < 30) {
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
  this_player()->add_spell_point(-30);
  write("You tear a rip into the fabric of the ether-muck and dive in.\n");
  tell_room(environment(this_player()),
  (this_player()->query_name()) + " tears open a hole in the ether-muck and dives in.\n");
  move_object(this_player(), environment(ob));
  write("You arrive next to " + (ob->query_name()) + ".\n");
  tell_room(environment(this_player()),
  (this_player()->query_name()) + " pops in through a wormhole.\n");
  wormholes=wormholes + 1;
  return 1;
}

wormhole(str) {
  object ob;
  object oc;
  string lacerta,right_here;
  if(!str) {
    write("Build a tunnel to where?\n");
    return 1;
  }
  if(this_player()->query_sp() < 15) {
    write("You feel too mentally drained to do that right now.\n");
    return 1;
  }
  lacerta = ROOMDIR + str;
  right_here = file_name(environment(this_player()));
    if(file_size(lacerta) < 100) {
    write("You are not too sure how to build a tunnel to reach there.\n");
    return 1;
  }
  if(lacerta == file_name(environment(this_player()))) {
    write("That would not require a tunnel.\n");
    return 1;
  }
  if(present("liquid-tunnel", environment(this_player()))) {
    write("There is already a tunnel here.\n");
    return 1;
  }
  ob=clone_object("players/mizan/closed/liquid-tunnel.c");
  ob->set_terminus(str);
     move_object(ob, lacerta);
  move_object(ob, environment(this_player()));
  this_player()->add_sp(-15);
  write("You concentrate intensely... and the path to " + str + " is revealed!\n");
  tell_room(environment(this_player()),
   (this_player()->query_name()) + " thinks real hard and a tunnel appears.\n");
  return 1;
}

