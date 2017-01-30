#define MAP_DIR "/open/mokri/maps/"

inherit "/obj/treasure.c";
reset(int arg) {
   if(arg) return;
   set_id("kiosk");
   set_alias("map kiosk");
   set_short("A map kiosk");
   set_long("A tall, metallic box standing 6 feet tall.\n"+
      "It provides the following commands:\n"+
      "list_maps             Get a list of your maps\n"+
      "review_map [type] [x] Review map number [x] of type [type]. [type] may be\n"+
      "                      either 'personal' or 'stock'.\n"+
      "delete_map [x]        Delete map number [x]\n"+
      "get_mapper            Get a mapper bot to make a map. The cost is 100 coins.\n"+
      "map_to [critter] [x]  Get directions to 'critter' that is in one\n"+
      "                      of your maps, or a stock map. If optional\n"+
      "                      argument 'x' is given, finds the x-th instance\n"+
      "                      of that critter (example: 'map_to guard' would find\n"+
      "                      the first guard in the stock maps or your personal maps.\n"+
      "                      'map_to guard 3' would find the 3rd guard).\n"+
      "                      You may also map_to a room name to find directions to a particular room.\n"+
      "                      If using room name, you MUST include exits (same as it shows on\n"+
      "                      who2). Example 'map_to Humpbacked bridge [e,w]'.\n\n"+
      "NOTE: The mapper walks around at random, so review your maps as you make them.\n"+
      "      You may have to map an area a few times to get the map you want!\n");
}

init()
{
   ::init();
   add_action("map_to","map_to");
   add_action("list_maps","list_maps");
   add_action("delete_map","delete_map");
   add_action("get_mapper","get_mapper");
   add_action("review_map","review_map");
}

int review_map(string str)
{
   int map_num, x, a;
   string this_map, *map_list, *my_maps, *this_line;
   
   if(!str || sscanf(str,"%s %d",str,map_num) != 2 || (str != "personal" && str != "stock"))
      {
      write("Syntax: review_map [type] [map_number]. [type] may be 'personal' or 'stock'.\n");
      return 1;
   }
   
   map_list = ({ "_stock/" });
   map_list += ({ this_player()->query_real_name() + "/" });
   if(str == "stock") this_map = MAP_DIR + map_list[0];
   if(str == "personal") this_map = MAP_DIR + map_list[1];
   my_maps = get_dir(this_map);
   
   if(map_num < 1 || map_num > (sizeof(my_maps) / 2))
      {
      write("Invalid map number.\n");
      return 1;
   }
   
   map_list = explode(read_file(this_map + my_maps[(map_num * 2 - 1)]),"\n");
   for(x = 0; x < sizeof(map_list); x++)
   {
      this_line = explode(map_list[x],"^MY_DIR^");
      write(this_line[1] + "\n");
      for(a = 2; a < sizeof(this_line); a++)
      write("  " + this_line[a] + "\n");
      if(sizeof(this_line) == 2)
         write("  Empty.\n");
   }
   return 1;
}

int list_maps()
{
   int x, a;
   string this_map, *my_maps, *tmp, *map_list;
   
   map_list = ({ "_stock/" });
   map_list += ({ this_player()->query_real_name() + "/" });
   for(a = 0; a < sizeof(map_list); a++)
   {
      this_map = MAP_DIR + map_list[a];
      if(!a) write("Stock maps\n");
      if(a == 1) write("\nPersonal maps\n");
      if(file_size(this_map) != -2)
         {
         write("No maps on file.\n");
         return 1;
       }
      
      my_maps = get_dir(this_map);
      if(sizeof(my_maps) == 0)
         write("No maps on file.\n");
      
      for(x = 0; x < sizeof(my_maps); x+=2)
      {
         tmp = explode(read_file(this_map + my_maps[x]),"\n");
         write((x/2+1) + ". " + tmp[0]->short()+"\n");
       }
   }
   return 1;
}

int delete_map(string str)
{
   int x;
   string this_map, *my_maps;
   
   if(!str || sscanf(str,"%d",x) != 1)
      {
      write("Syntax: delete map [x], where '[x]' is a valid map number.\n");
      return 1;
   }
   
   x -= 1;
   
   this_map = MAP_DIR + this_player()->query_real_name() + "/";
   if(file_size(this_map) != -2)
      {
      write("Not a valid map number. Type 'list_maps' for valid numbers.\n");
      return 1;
   }
   
   my_maps = get_dir(this_map);
   x *= 2;
   if(x < 0 || x > sizeof(my_maps))
      {
      write("Not a valid map number. Type 'list_maps' for valid numbers.\n");
      return 1;
   }
   
   write("Map removed.\n");
   rm(this_map + my_maps[x]);
   rm(this_map + my_maps[(x+1)]);
   return 1;
}

int get_mapper()
{
   string this_map, *my_maps;
   this_map = MAP_DIR + this_player()->query_real_name() + "/";
   
   if(file_size(this_map) != -2)
      mkdir(this_map);
   my_maps = get_dir(this_map);
   if(sizeof(my_maps) >= 20)
      {
      write("You have already reached your 10 map limit.\n");
      return 1;
   }
   
   if(this_player()->query_money() < 100)
      {
      write("You do not have enough money.\n");
      return 1;
   }
   
   this_player()->add_money(-100);
   move_object(clone_object(MAP_DIR + "mapper"),this_player());
   write("You are given a mapper.\n"+
      "Go to the room where you would like mapping to begin, and type 'start_mapping'.\n");
   return 1;
}

int map_to(string str)
{
   string found_path, *all_maps, *tmp, *tmp2, *my_maps;
   int x, a, b, c, d, e, counts;
   
   if(!str)
      {
      write("Find directions to what critter?\n");
      return 1;
   }
   
   my_maps = ({ "_stock/" });
   my_maps += ({ this_player()->query_real_name() + "/" });
   tmp = explode(str," ");
   if(sscanf(tmp[sizeof(tmp)-1],"%d",counts) == 1)
      tmp -= ({ tmp[sizeof(tmp)-1] });
   else
      counts = 1;
   str = implode(tmp," ");
   c = 0;
   for(d = 0; d < sizeof(my_maps); d++)
   {
      if(file_size(MAP_DIR + my_maps[d]) == -2)
         {
         all_maps = get_dir(MAP_DIR + my_maps[d]);
         
         for(x = 1; x < sizeof(all_maps); x+=2)
         {
            if(c < counts)
               {
               tmp = explode(read_file(MAP_DIR + my_maps[d] + all_maps[x]),"\n");
               for(a = 0; a < sizeof(tmp); a++)
               {
                  tmp2 = explode(tmp[a],"^MY_DIR^");
                  if(member(tmp2,str) != -1 && c != counts && found_path != tmp2[0])
                     {
                     found_path = tmp2[0];
                     b = x - 1;
                     e = d;
                     c += 1;
                   }
               }
             }
         }
       }
   }
   
   all_maps = get_dir(MAP_DIR + my_maps[e]);
   if(found_path && c == counts)
      {
      tmp = explode(read_file(MAP_DIR + my_maps[e] + all_maps[b]),"\n");
      write("Directions from: " + tmp[0]->short()+"\n");
      a = 0;
      for(x = 1; x < sizeof(tmp); x++)
      {
         tmp2 = explode(tmp[x],"^MY_DIR^");
         if(!a) write(tmp2[1]+"\n");
         if(tmp2[0] == found_path) a = 1;
      }
   }
   
   if(!found_path || c != counts)
      write("Not found in maps.\n");
   
   return 1;
}

get() { return 0; }
