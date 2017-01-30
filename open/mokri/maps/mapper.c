string *has_gone, *stuff;
object owner;

#define MAX_STEPS 70
#define MAP_DIR "/open/mokri/maps/"

inherit "/obj/treasure.c";
reset(int arg) {
   if(arg) return;
   set_id("mapper");
   set_short("A mapper");
   set_long("A small, metallic disk approximately 1 foot in diameter. It hovers\n"+
      "three feet in the air, awaiting the order to 'start_mapping'.\n");
   set_value(10);
}

int finish_me(string str)
{
   string this_dir, this_file, *files;
   int x, a;
   
   if(!this_player() || !find_player(this_player()->query_real_name()))
      {
      destruct(this_object());
      return 1;
   }
   
   if(!str || str != "_stock") str = (string)this_player()->query_real_name();
   if(str != (string)this_player()->query_real_name() && (int)this_player()->query_level() < 20)
      str = (string)this_player()->query_real_name();
   this_dir = MAP_DIR + str + "/";
   if(file_size(this_dir) != -2) mkdir(this_dir);
   files = get_dir(this_dir);
   if(sizeof(files) >= 20)
      {
      tell_object(owner,"ALREADY AT 10 MAP LIMIT. SELF DESTRUCING.\n");
      destruct(this_object());
      return 1;
   }
   x = 0;
   while(file_size(this_dir + x + ".map") > 0 && sizeof(files) >= x)
   x++;
   a = x;
   move_object(this_object(),environment(owner));
   write_file(this_dir + a + ".map","");
   for(x = 0; x < sizeof(has_gone); x++)
   write_file(this_dir + a + ".map",call_other("/open/mokri/funcs/strings","strip_ansi",has_gone[x])+"\n");
   write_file(this_dir + a + ".obj","");
   for(x = 0; x < sizeof(stuff); x++)
   write_file(this_dir + a + ".obj",call_other("/open/mokri/funcs/strings","strip_ansi",stuff[x])+"\n");
   tell_object(owner,"MAPPING FINISHED. SELF DESTRUCTING.\n");
   destruct(this_object());
   return 1;
}

int map_places(string str)
{
   object this;
   string tmp, *dirs, *tmp_dirs;
   int x, steps;
   
   for(steps = 0; steps < MAX_STEPS; steps++)
   {
      dirs = (string*)environment(this_object())->query_dest_dir();
      if(dirs)
         {
         x = random(sizeof(dirs));
         
         while((x % 2))
         x = random(sizeof(dirs));
         
         if(extract(dirs[x],0,0) != "/") dirs[x] = "/" + dirs[x];
         
         if(!catch(tmp_dirs = (string*)dirs[x]->query_dest_dir()))
            {
            if(sizeof(tmp_dirs))
               {
               has_gone += ({ dirs[x] + "^MY_DIR^" + dirs[(x+1)] });
               move_object(this_object(),dirs[x]);
               this = first_inventory(environment(this_object()));
               tmp = dirs[x] + "^MY_DIR^" + environment(this_object())->short();
               while(this)
               {
                  if(this->is_npc() && this->query_name())
                     tmp += "^MY_DIR^" + lower_case((string)this->query_name());
                  this = next_inventory(this);
               }
               stuff += ({ tmp });
            }
         }
       }
   }
   finish_me(str);
   return 1;
}

init()
{
   ::init();
   
   add_action("finish_mapping","finish_mapping");
   add_action("start_mapping","start_mapping");
}

int start_mapping(string str)
{
   string this_dir, *files;
   this_dir = MAP_DIR + this_player()->query_real_name() + "/";
   if(file_size(this_dir) != -2) mkdir(this_dir);
   files = get_dir(this_dir);
   if(sizeof(files) >= 20)
      {
      write("ALREADY AT 10 MAP LIMIT.\n");
      return 1;
   }
   move_object(this_object(),environment(this_player()));
   has_gone = ({ "/"+ object_name(environment(this_object())) });
   stuff = ({ });
   owner = this_player();
   map_places(str);
   return 1;
}

int finish_mapping()
{
   finish_me((string)this_player()->query_real_name());
   return 1;
}
