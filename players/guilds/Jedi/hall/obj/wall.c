inherit "obj/monster";
string dir_blocked;

reset(arg)
{
   ::reset(arg);
   if (arg) return;
   set_name("wall");
   set_alias("clan_wall_blocker_obj");
   set_level(1);
   set_wc(0);
   set_ac(0);
   set_al(0);
   set_hp(100);
   set_ep(0);
   set_short("A Wall");
   set_long("A large brick wall blocking your way.\n");
   set_dead_ob(this_object());
}

int monster_died()
{
  destruct(present("corpse",environment(this_object())));
  return 1;
}

int check_another_wall()
{
   object stuff;
   int is_here;
   is_here = 0;
   
   stuff = first_inventory(environment(this_object()));
   while(stuff && is_here == 0)
   {
     if(stuff != this_object() && (string)stuff->query_alias() == "clan_wall_blocker_obj")
       is_here = 1;
     stuff = next_inventory(stuff);
   }
   return is_here;
}
init()
{
object here;
int valid_member;
string died_msg;
::init();

here = environment(this_object());
died_msg = "";

if(here && !here->is_player())
{
  if(!dir_blocked || dir_blocked == "")
    died_msg = "A wall is set down, and promptly disappears, because it didn't have a valid direction to block.\n";
  
  if(died_msg == "")
  {
    valid_member =  member(here->query_dest_dir(),dir_blocked);
    if(valid_member && (valid_member == 1 || (sizeof(here->query_dest_dir()) % valid_member)))
    {
      if(check_another_wall() == 1)
       died_msg = "A wall is set down, and promptly disappears, because there is already a wall here.\n";
    }
    else
      died_msg = "A wall is set down, and promptly disappears, because it didn't have a valid direction to block.\n";
  }
  
  if(died_msg != "")
  {
    tell_room(here,died_msg);
    destruct(this_object());
    return 1;
  }
  else
    add_action("block_em",dir_blocked);
  }
}
  
int block_em()
{
  write("The wall blocks your exit.\n");
  say(this_player()->query_name()+" tries to leave, but runs into a wall.\n",this_player());
  return 1;
}

string query_dir_blocked() { return dir_blocked; }

set_dir_blocked(db) { dir_blocked = db; }

hit_player(dam1, type1, dam2, type2){
   return do_damage(({dam1,dam2}),({type1,type2}));
}

int query_block_attack() { return 1; }
