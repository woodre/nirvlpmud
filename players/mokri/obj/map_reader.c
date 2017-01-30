#define MAP_DIR "/players/mokri/maps/"

inherit "/obj/treasure.c";
reset(int arg) {
   if(arg) return;
   set_id("reader");
   set_short("map reader");
   set_long("map reader. 'map_to blah' to find.\n"+
      "'map_to blah x' to find the x'th instance\n"+
      "of 'blah'. (i.e. map_to guard10 would find\n"+
      "the 10th instance of 'guard'.\n");
}

init()
{
   ::init();
   add_action("map_to","map_to");
}

int map_to(string str)
{
   string found_path, *all_maps, *tmp, *tmp2;
   int x, a, b, c, counts;
   
   if(!str)
      {
      write("Find directions to what critter?\n");
      return 1;
   }
   
   if(sscanf(str,"%s %d",str,counts) != 2) counts = 1;
   all_maps = get_dir(MAP_DIR);
   c = 0;
   for(x = 1; x < sizeof(all_maps); x+=2)
   {
      if(c < counts)
         {
         tmp = explode(read_file(MAP_DIR + all_maps[x]),"\n");
         for(a = 0; a < sizeof(tmp); a++)
         {
            tmp2 = explode(tmp[a],"^MY_DIR^");
            if(member(tmp2,str) != -1 && c != counts && found_path != tmp2[0])
               {
               found_path = tmp2[0];
               b = x - 1;
               c += 1;
             }
         }
       }
   }
   
   
   if(found_path && c == counts)
      {
      tmp = explode(read_file(MAP_DIR + all_maps[b]),"\n");
      write("Directions from: " + tmp[0]->short()+"\n");
      a = 0;
      for(x = 1; x < sizeof(tmp); x++)
      {
         tmp2 = explode(tmp[x],"^MY_DIR^");
         if(!a) write(capitalize(tmp2[1]) + "\n");
         if(tmp2[0] == found_path) a = 1;
      }
   }
   
   if(!found_path || c != counts)
      write("Not found in maps.\n");
   
   return 1;
}

get() { return 0; }
