inherit "room/room";
int is_pk;
 
#include "/players/snow/closed/color.h"
reset(arg){

if(!present("obelisk")) {
move_object(clone_object("/players/snow/newbie/obelisk.c"),this_object());
   }
 

if(!random(2)) is_pk = 1;
 if(!arg){
 
 set_light(1);
  short_desc=(is_pk?RED:"")+"Nexus"+OFF;
 
 
items=({
"nexus","This is an interdimensional nexus",
"fire","Streaks of ice-blue fire flash across the blackness that is your\n"+
       "current world"
          });
 
  dest_dir=({
"/room/plane10","out",
"/players/snow/nature.c","nature",
"/players/snow/newbie/sculp_room.c","newbie",
"/players/snow/chaos/port.c","chaos",
"/players/snow/shadows/shadowgate","shadowgate",
"/players/snow/dark/rooms/r1","arena",
"/players/dune/closed/guild/rooms/entrance.c","cyber",
"/players/snow/closed/test/r1.c", "test",
      });
  }   }
 
init() {
   if(this_player())
  if(this_player()->is_player()) {
  if(query_ip_number(this_player()) == "134.129.239.13" && this_player()->query_real_name() != "budah") {
    move_object(this_player(),"/room/church"); return 1; }
  ::init();
  if(is_pk) { this_player()->set_fight_area();
    write(RED+"The vortex gleams a blood-red.\n"+OFF);
 }
  }
  add_action("clean_me","starlight");
  add_action("info_func","info");
   if(this_player())
  if(this_player()->query_level() > 30) add_action("checkpk","checkpk");
  add_action("cyber_guild","cyberninja");
  /*  Added by Fred 10-16-03    */ 
  add_action("derv_guild", "sands");
  add_action("derv_guild", "Sands");
}

exit() { if(this_player()) if(this_player()->is_player()) this_player()->clear_fight_area(); }

cyber_guild() {
  object ob;
  ob = this_player();
  if(ob->query_guild_name() == "cyberninja" || ob->query_level() > 9) {
    write("You move into the realm of CyberSpace.\n");
    this_player()->move_player("into cyberspace#players/dune/closed/guild/rooms/entrance");
  return 1; }
}

derv_guild(){
  object ob;
  ob = this_player();
  if(ob->query_guild_name() != "dervish"){
    write("You are not one with the sands!\n");
    return 1; }
  write("You embrace the "+BOLD+RED+"SandStorm"+OFF+" that is your home.\n");
  tell_room("/players/guilds/dervish/hall/hall.c",
    this_player()->query_name()+" enters the "+BOLD+RED+"SandStorm"+OFF+".\n");
  move_object(this_player(), "/players/guilds/dervish/hall/hall.c");
  command("look", this_player());
  
  return 1;
}

clean_me() {
  object bug, dis, poi;
bug = present("flu",this_player());
dis = present("disease",this_player());
poi = present("poison", this_player());
  if(this_player()->query_attack()) {
    this_player()->add_hit_point(-50); return 1; }
  write("You step into the pure light...\n");
  if(dis) {
    write("Starlight burns deep into your body, eradicating the disease!\n");
    destruct(dis);
  }
  if(bug) {
    write("Starlight flashes through you, cleansing your body!\n");
    destruct(bug);
  }
  if(poi) {
    write("Starlight works into your body and destroys a poison!\n");
    destruct(poi); }
/* Idiot players..
  write("Due to player abuse this will no longer restart your\n"+
   "heart beat. -Snow \n");
  return 1;
  this_player()->set_heart_beat(1);
  this_player()->heart_beat();
  call_other(this_player(),"reset",1);
 */
  this_player()->recalc_quest();
  this_player()->recalc_carry();
say(this_player()->query_name()+" stands in a beam of starlight!\n");
write("You step back from the cleansing light.\n");
return 1;
}
 
checkpk() {
  if(is_pk) {
    write("The Vortex is PK!\n"); return 1; }
  else write("The Vortex is not PK.\n");
  return 1; }

info_func(arg) {
  if(!arg) { notify_fail("Usage: info low   OR   info high.\n"); return 0; }
  if(arg == "low") { cat("/players/snow/LowMidDesc.txt"); return 1; }
  if(arg == "high") { cat("/players/snow/HighLevDesc.txt"); return 1; }
  notify_fail("Usage: info low   OR   info high.\n");
  return 0; }

long(str)
{
  long_desc=
  "You have reached an interdimensional nexus. Streaks of blue fire streak\n"+
  "across every horizon. Though it is cold as death in this nether-space,\n"+
  "you feel strangely unafraid. A beam of starlight burns with a pure light\n"+
  "through the space close to you. If you have a sickness or disease, if you\n"+
  "can't carry things, if you have lost your heartbeat, just type 'starlight'\n"+
  "and you should be cleansed and healed by the light.\n"+
  "To get more information about the various areas, type 'info low' or 'info high'.\n";
    if(this_player()->query_guild_name() == "dervish")
     long_desc += BOLD+"As a dervish you may also exit to the "+RED+"Sands"+OFF+".\n";
    ::long();
}
