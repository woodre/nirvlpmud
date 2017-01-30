string *has_gone, *stuff;
object owner;

#define MAX_STEPS 100
#define MAP_DIR "/players/mokri/maps/"

inherit "/obj/treasure.c";
reset(int arg) {
   if(arg) return;
   set_id("mapper");
   set_short("mapper");
   set_long("mapper. testing. if you see me, please type 'finish_mapping' and tell mokri.\n");
}

int finish_me()
{
   string *files;
   int x, a;
   
   files = get_dir(MAP_DIR);
   a = sizeof(files);
   move_object(this_object(),environment(owner));
   
   for(x = 0; x < sizeof(has_gone); x++)
   write_file(MAP_DIR + a + ".map",has_gone[x]+"\n");
   for(x = 0; x < sizeof(stuff); x++)
   write_file(MAP_DIR + a + ".obj",stuff[x]+"\n");
   tell_object(owner,"MAPPING FINISHED. SELF DESTRUCTING.\n");
   destruct(this_object());
   return 1;
}

int map_places()
{
   object this;
   string tmp, *dirs, *tmp_dirs;
   int x, steps;
   
   for(steps = 0; steps < MAX_STEPS; steps++)
   {
      dirs = (string*)environment(this_object())->query_dest_dir();
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
            tmp = dirs[x];
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
   finish_me();
   return 1;
}

init()
{
   ::init();
   
   add_action("finish_mapping","finish_mapping");
   add_action("start_mapping","start_mapping");
}

int start_mapping()
{
   has_gone = ({ "/"+ file_name(environment(this_object())) });
   stuff = ({ });
   owner = this_player();
   map_places();
   return 1;
}

int finish_mapping()
{
   finish_me();
   return 1;
}

get() { return 0; }
