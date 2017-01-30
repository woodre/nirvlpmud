#include "/players/jaraxle/ansi.h"
#include "/players/jaraxle/closed/guild/define.h"
#include "/players/jaraxle/closed/guild/obj/vars.h"
#include "/players/jaraxle/closed/guild/obj/spells.h"
#include "/players/jaraxle/closed/guild/obj/id.h"
#include "/players/jaraxle/closed/guild/obj/weapon.h"
#include "/players/jaraxle/closed/guild/obj/armor.h"
#include "/players/jaraxle/closed/guild/obj/hb.h"
#include "/players/jaraxle/closed/guild/geo_help.h"

reset(arg){
   write("Status Updated.\n");
   if(arg) return;
   set_heart_beat(1);
}

drop(){ return 1; }
get(){ return 1; }

query_weight(){ return 0; }
query_value(){ return 0; }
query_auto_load(){ return "/players/jaraxle/closed/guild/gob.c:"; }

init(){
   int i;
   string *f, cmd;
   if(!this_player()) return;
   if(!environment()) return;
   if(environment() != this_player()) return;
   glvl = 1;
   gxp = 0;
   skillpts = 1; 
   fire_element = 0;
   water_element = 0;
   wind_element = 0;
   earth_element = 0;
   cost_toggle = 1;
   delay = 0;
   restore_object(SAVE_PATH+NAME);
   if(USER->query_level() < 20){
      USER->set_guild_name("Elemental");
   }
   
   /* Guild AC Bonuses */
   this_player()->RegisterArmor(this_object(), ({ "physical", 0, 0, "armor_special" }));
   
   if(this_player()->query_level() < 20){
      add_action("nogo", "sonic", 2);
      add_action("nogo", "fireball", 2);
      add_action("nogo", "shock", 2);
      add_action("nogo", "missile", 2);
      add_action("nogo", "pose", 2);
      add_action("nogo", "invisible", 2);
      add_action("newquit", "quit");
      add_action("guild_update", "e_update");
      add_action("guild_update", "e_up");
      add_action("geo_help", "geo_help");
   }
   i = sizeof(f = files(POWER + "*.c"));
   while (i--) {
      sscanf(f[i], "%s.c", cmd);
      add_action("cmd_hook", cmd);
   }
}

list_powers(){
   int i;
   string *f;
   string cmd;
   i = sizeof(f = files(GEOHELP + "*.c"));

   while(i--){ sscanf(f[i], "%s.c", cmd);
      tell_object(USER, cmd+"\n"); } 
   return 1; }

nogo(){ return 0; }

newquit(){  saveme(1);  return;  }

guild_update(){
   write("Updating Geomancer status. . .\n");
   move_object(clone_object("/players/jaraxle/closed/guild/gob.c"),USER);
   destruct(this_object());
   return 1; }

saveme(i){ 
   if(!i){  save_object(SAVE_PATH+NAME); return; }
   write(HIB+"Saving Guild Object"+HIW+"...\n"+NORM);
   save_object(SAVE_PATH+NAME);
   write(HIB+"Done.\n"+NORM);
}

/* NO MINI-GUILDS */
mini_dest(str){
   tell_object(USER,
      "Do not rely on such weak things!\n");
   return;
}

/*  NO NON GUILD PETS */
call_pet(){
   if(previous_object()->is_pet()){
      tell_room(environment(USER),
         "Your pet refuses to follow you and leaves.\n");
      destruct(previous_object());
      return 1;
   }
   return 1;
}


/*  This is where all Commands are handled.  Calls a .c file directly,
and sends over a few variables.  */
mixed cmd_hook(string str)
{
   string go;
   go = POWER+query_verb()+".c";
   if(file_size(go) > 0)
      return (mixed) go->main(str, this_object(), this_player());
   return 0;
}



kill_check(ob) {
   object geo_kill;
   int this_kill;
   
   this_kill = (int)ob->calculate_evaluated_worth(environment());
   geo_kill = environment(this_object());
   
   tell_object(geo_kill, "Exp for Kill: "+HIW+this_kill+NORM); 
   add_expgain(this_kill);
   save_me();
}

