#include "/players/plasma/define.h"
main(str) {
   int i;
   object player;
   string path, sother;
   
   if(!str) player = ENV(TP);
   if(str && sscanf(str,"%s %s",str,sother));
   if(!player) player = find_player(str);
   if(player && sother) player = present(sother,player);
   if(!player) player = present(str,TP);
   if(!player) player = present(str,ENV(TP));
   if(!player) {
      write("No object to show.\n");
      return 1; }
   player = first_inventory(player);
   if(!player) {
      write("Inventory of object is empty.\n");
      return 1; }
   write("-------  "); write(environment(player)); write("  --------\n");
   write(environment(player)->short() + "\n");
   write("____________________________________\n");
   while(player) {
      i += 1;
      if(i < 10) write(i + ":  ");
      else write(i + ": ");
      write(player);
      write(": ");
      player->short();
      write("\n");
      player = next_inventory(player);
   }
   return 1; }
