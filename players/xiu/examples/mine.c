string owner;
int is_set;

inherit "/obj/treasure.c";
reset(int arg) {
   if(arg) return;
   set_id("cyberninja_landmine");
   set_long("There is no cyberninja_landmine here.\n");
}

void check_kill()
{
   int damage;
   if(is_set && this_player() && (int)this_player()->query_pl_k() && (string)this_player()->query_guild_name() != "cyberninja" && (int)this_player()->query_level() < 20)
      {
      say(this_player()->query_name() + " stepped on a landmine!\n");
      write("You stepped on a landmine.\n");
      if(!random(4))
         {
         write("Whew! It was a dud.\n");
         say("Nothing happens.\n");
         if(find_player(owner))
            tell_object(find_player(owner),"Landmine exploded.\nLocation: " + environment(this_object())->short() + "\nResult: DUD.\n");
         destruct(this_object());
         return;
      }
      
      damage = random(25) + 1;
      if(this_player()->query_hp() <= damage) damage = (int)this_player()->query_hp() - 1;
      this_player()->hit_player(damage,"fire");
      write("It blows up in your face!\n");
      "/bin/play/_monitor"->cmd_monitor();
      say("It blows up in " + this_player()->query_possessive() + " face!\n");
      if(find_player(owner))
         tell_object(find_player(owner),"Landmine exploded.\nLocation: " + environment(this_object())->short() + "\nResult: Direct hit.\n");
      destruct(this_object());
   }
   return;
}

init()
{
   ::init();
   
   check_kill();
}


query_owner() { return owner; }
query_is_set() { return is_set; }

set_owner(string ow) { owner = ow; }
set_is_set(int is) { is_set = is; }

int set_timer(int x)
{
   if(is_set) return 1;
   call_out("set_is_set",x,1);
   return 1;
}
