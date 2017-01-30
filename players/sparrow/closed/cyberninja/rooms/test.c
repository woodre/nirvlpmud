inherit "room/room";
inherit "/players/pestilence/closed/std/room";
/* Based on Feld's arena */
#include "/obj/clean.c"
#include "../DEFS.h"
#define FTELL(x) if(find_player("puppy")) tell_object(find_player("puppy"),x);
#define TPM this_player()->query_credit()
#define tp this_player()->query_name()


reset(int arg){
   if(arg) return;
   set_light(1);
   short_desc="The CyberNinja Arena";
   set_pk(1);
   long_desc=
write("     You are in a large metallic dome.  At one end rests the giant\nstatue of a kneeling ninja.  Its head reaches to the ceiling.\nA wide flat field stretches for hundreds of yards all around you.\n     Type 'register' for a list the services available to you.\n");
   
   items = ({
         "field","A large grassy field with blood stains",
         "blood","Blood stains admist the grass",
         "stain","Blood stains admist the grass",
         "stains","Blood stains admist the grass",
         "blood stains","Blood stains admist the grass",
         "grass","A large grassy field with blood stains",
         "doorway","A doorway to the east leading out of the arena",
         "door","A doorway to the east leading out of the arena",
});
   
dest_dir=({
ROOMDIR + "/arena5.c", "up",
ROOMDIR + "/arena23.c", "down",
ROOMDIR + "/arena10.c", "northwest",
ROOMDIR + "/arena11.c", "north",
ROOMDIR + "/arena12.c", "northeast",
ROOMDIR + "/arena15.c", "east",
ROOMDIR + "/arena18.c", "southeast",
ROOMDIR + "/arena17.c", "south",
ROOMDIR + "/arena16.c", "southwest",
ROOMDIR + "/arena13.c", "west",
ROOMDIR + "/arena.c", "surface",
});
   enable_commands(); /* So that it will receive catch_tells */
}

void catch_tell(string str) {
   object zombie;
   object attacker;
   string name;
   tell_room("/players/dune/closed/guild/rooms/stands","~COMBAT~"+str);
   if( sscanf(str,"%s died.",name)==1 ) {
      zombie=find_player(lower_case(name));
      if(zombie && zombie->query_hp() < 0) {
         attacker=(object)zombie->query_attack();
         if(attacker)
            write_file("/players/dune/closed/guild/tournaments/reports",ctime(time())+" "+name+" defeated by "+(string)attacker->query_name()+" [Cyber spar]\n");
         else
            write_file("/players/dune/closed/guild/tournaments/reports",ctime(time())+" "+name+" defeated by unknown causes. [Cyber spar]\n");
         call_out("handle_death",1,({ name, zombie }) );
      }
   }
}

void handle_death(mixed *info)
{
   object corpse;
   tell_room(this_object(),info[0]+" has been defeated.\nThe CyberDaemon engulfs "+info[0]+"'s motionless body and drags it elsewhere.\n");
   move_object(info[1],"/players/dune/closed/guild/rooms/morgue"); 
   command("resurect",info[1]);
   corpse=present("corpse",this_object());
   if(corpse) {
      move_object(corpse,environment(info[1]));
      command("get all from corpse",info[1]);
      destruct(corpse);
   } else FTELL("Corpse not found!\n");
}

void init() {
   ::init();
   add_action("quit","quit");
add_action("buy", "buy");
add_action("buy", "purchase");
add_action("register","register");
}

int query_spar_area() {
   return 1;
}
string realm() {
   return "NT";
}

int kill_players(string str)
{
   if(str=="spar") {
      write("This command is no longer necessary.\n");
      return 1;
   }
}

status register() {
  if(!TP || !environment(TP)) return 1;
  write( 
"Heals available for sale.....\n"+
"ITEM                     PRICE (in credits)\n"+
"________________________________________\n"+
"Biometric Solution           300\n"+
"Neurotic Solution            300\n"+
"Polymer Solution             300\n"+
"Power Cell                   800\n"+
"Liquid Circuit Cooler        3500\n"+
"________________________________________\n"+
"\n");
  return 1;
}

buy(str){
  int bal,value;
  string objectpath;

  bal = (int)IPTP->balance();
  if(!str){
    notify_fail("The CyberDaemon says: What would you like to buy?\n");
    return 0;
  }

  switch(str){
case "liquid curcuit cooler": value = 3500;  objectpath = "/players/dune/closed/guild/heals/cooler.c";
break;
case "power cell": value = 800;  objectpath = "/players/dune/closed/guild/heals/cell.c";
    break;
case "biometric solution": value = 300;  objectpath = "/players/dune/closed/guild/heals/bheal.c";
break;
case "polymer solution": value = 300;  objectpath = "/players/dune/closed/guild/heals/pheal.c";
break;
case "neurotic solution": value = 300;  objectpath = "/players/dune/closed/guild/heals/nheal.c";
  default: notify_fail("The CyberDaemon says: That is not available to buy.\n");
    return 0;
  }

  if(bal < value){
    notify_fail("The CyberDaemon says: You do not have the "+value+" credits for "+str+".\n");
    return 0;
  }

  write("You pay "+value+" credits for a "+str+".\n");
  write("The CyberDaemon hands you a "+str+".\n");
  IPTP->addToBalance(-value);
  move_object(clone_object(objectpath),this_player());
  return 1;
}

quit(str) {
   write("You may not quit from this location.\n");
   return 1;
}
