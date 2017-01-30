/*  virt_room.c
*  Recode of wocket's caves
*  Rumplemintz
*/

inherit "/room/room.c";

#define PATH "/players/wocket/caves/NEWCAVES/"
#define LONG "/players/wocket/caves/NEWCAVES/long_desc.c"
#define MON "/players/wocket/caves/NPC/"
#define SINJAROOM "/players/wocket/caves/NEWCAVES/sinjaroom.c"
#include "/players/wocket/closed/ansi.h"

int northroom, southroom, eastroom, westroom;
int northexit, southexit, eastexit, westexit;
int sinjaroom, monsters;

void reset(status arg){
   if(arg) return;
   set_short(MAG+"Dark room"+NORM);
   dest_dir = (({ }));
   set_items(({
            "light", "It glows a soft violet",
            "mucus", "It covers just about everything.  The slimy substance emminates a soft violet light",
            "plants", "They are white and very fragile.  They seem to feed off of the darkness",
            "rocks", "They are loose particles that fell from the walls",
            "walls", "They are jagged with sharp rocks and covered in a slimy mucus",
            }));
   sinjaroom = 0;
}

void init(){
   if(this_player() && !this_player()->query_npc())
      if(monsters != 1){ this_object()->get_monsters(); }
   ::init();
   add_action("newexit", "north");
   add_action("newexit", "south");
   add_action("newexit", "east");
   add_action("newexit", "west");
}

status create_newroom(string str){
   object newroom;
   string dir1, dir2, dir3, dir4;
   sscanf(str,"%s %s %s %s", dir1, dir2, dir3, dir4);
   newroom = clone_object(PATH+"virt_room.c");
   newroom -> add_exit(file_name(this_object()), dir2);
   newroom -> set_direxit(dir2);
   newroom -> set_dirroom(dir2);
   if(LONG->query_roomcount() < 40 ){
      if(random(2)==1){
         newroom -> add_exit("",dir1);
         newroom -> set_direxit(dir1);
         LONG->add_roomcount(1);
      }
   }
   if(LONG->query_roomcount() < 40){
      if(random(2)==1){
         newroom -> add_exit("",dir3);
         newroom -> set_direxit(dir3);
         LONG->add_roomcount(1);
      }
   }
   if(LONG->query_roomcount() < 40){
      if(random(2)==1){
         newroom -> add_exit("",dir4);
         newroom -> set_direxit(dir4);
         LONG->add_roomcount(1);
      }
   }
   newroom -> set_long(LONG->get_long_desc());
   this_object()->add_exit(file_name(newroom), dir1);
   this_object()->set_dirroom(dir1);
   this_player()->move_player(dir1+"#"+file_name(newroom));
}

void get_monsters(){
   int i;
   i = random(100);
   monsters = 1;
   switch(i){
      case 0..5:
      move_object(clone_object(MON+"pojoui.c"), this_object());
      if(random(2) == 1) move_object(clone_object(MON+"plant.c"),this_object());
      break;
      case 6..20:
      move_object(clone_object(MON+"darknonge.c"), this_object());
      if(random(5) == 1){
         move_object(clone_object(MON+"snonge.c"),this_object());
         if(random(3) == 1)
            move_object(clone_object(MON+"snonge.c"),this_object());
          }
      break;
      case 21..75:
      if(random(3)==1)
         move_object(clone_object(MON+"plant.c"), this_object());
      if(random(5)==1)
         move_object(clone_object(MON+"lippard.c"),this_object());
      if(random(4)==1)
         move_object(clone_object(MON+"wiidjin.c"),this_object());
      if(random(4)==1)
         move_object(clone_object(MON+"sponge.c"),this_object());
      if(random(6)==1)
         move_object(clone_object(MON+"nyddle.c"),this_object());
      if(random(5)==1){
         move_object(clone_object(MON+"moleman.c"),this_object());
         if(random(3)==1)
            move_object(clone_object(MON+"moleman.c"),this_object());
          }
      break;
      case 76..90: break;
      default:
      if(random(50)==1)  move_object(clone_object(MON+"pojoui.c"),this_object());
      if(random(20)==1)  move_object(clone_object(MON+"lippard.c"),this_object());
      if(random(17)==1){  move_object(clone_object(MON+"snonge.c"),this_object());
         if(random(2)==1) move_object(clone_object(MON+"snonge.c"),this_object()); }
      if(random(15)==1)  move_object(clone_object(MON+"darknonge.c"),this_object());
      if(random(10)==1)  move_object(clone_object(MON+"wiidjin.c"),this_object());
      if(random(7)==1)  move_object(clone_object(MON+"sponge.c"),this_object());
      if(random(5)==1)  move_object(clone_object(MON+"moleman.c"),this_object());
      if(random(5)==1)  move_object(clone_object(MON+"moleman.c"),this_object());
      if(random(3)==1)  move_object(clone_object(MON+"plant.c"),this_object());
      break; 
   }
}


void set_direxit(string str){
   switch(str){
      case "north": northexit =1; break;
      case "south": southexit = 1; break;
      case "west": westexit = 1; break;
      case "east": eastexit = 1; break;
   }
}

void set_dirroom(string str){
   switch(str){
      case "north": northroom = 1; break;
      case "south": southroom = 1; break;
      case "east": eastroom = 1; break;
      case "west": westroom = 1; break;
   }
}

status newexit(){
   switch (query_verb()){
      case "north":
      if(!northexit) return 0;
      if(!northroom){
         if(random(10)==1 && sinjaroom == 0){
            SINJAROOM -> add_exit(file_name(this_object()), "south");
            northroom = 1;
            this_object()->add_exit(PATH+"sinjaroom.c", "north");
            this_player()->move_player("north#"+PATH+"sinjaroom.c");
            sinjaroom = 1;
            return 1;
         }
         create_newroom("north south east west");
         return 1;
        }
      break;
      case "south":
      if(!southexit) return 0;
      if(!southroom){
         create_newroom("south north east west");
         return 1;
        }
      break;
      case "east":
      if(!eastexit) return 0;
      if(!eastroom){
         create_newroom("east west north south");
         return 1;
        }
      break;
      case "west":
      if(!westexit) return 0;
      if(!westroom){
         create_newroom("west east north south");
         return 1;
        }
      break;
   }
}
