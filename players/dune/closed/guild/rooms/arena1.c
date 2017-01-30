/* Based on Feld's arena */
#include "/obj/clean.c"
#include "../DEFS.h"
#define FTELL(x) if(find_player("puppy")) tell_object(find_player("puppy"),x);

inherit "room/room";
inherit "/players/pestilence/closed/std/room";

reset(int arg) {
   if(arg) return;
   set_light(0);
   short_desc="The CyberNinja Arena";
   set_pk(1);
   long_desc=
write("     You are in a large metallic dome.  At one end rests the giant\nstatue of a kneeling ninja.  Its head reaches to the ceiling.\nA wide flat field stretches for hundreds of yards all around you.\n");
   
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
ROOMDIR + "/arena10.c", "down",
ROOMDIR + "/arena2.c", "east",
ROOMDIR + "/arena5.c", "southeast",
ROOMDIR + "/arena4.c", "south",
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
quit(str) {
   write("You may not quit from this location.\n");
   return 1;
}
