/* Advance hall for the Druids - started Aug 10th 2002 */

#include "/players/daranath/guild/defs.h"
#include <ansi.h>
#define TP this_player()
#define ROOT "/players/daranath/druid/"

int num;

inherit "room/room";

reset(arg) {
if(!present("portal")) {
move_object(clone_object("/players/daranath/druid/obj/vine_portal.c"),this_object());
}
if(arg) return;

set_light(1);
short_desc = (HIG+"Druid's Grove"+NORM); 
long_desc= 
"A large grove of trees deep within the DarkenWood makes for the home\n"+
"to Nirvana's Druids. This area seems to be used as a training \n"+
"ground of some sort.\n"+
"type: <"+HIG+"druidhall"+NORM+"> for a list of commands here.\n";

items=({
"grove","Definently a grove of trees",
 });

  dest_dir=({
"/players/daranath/clearing/dwood21.c","leave",
  });
}

init() {
  ::init();
  if(present("druid_ob",tp)) {
add_action("advance_glvl","advance");
add_action("advance_cost","cost");
add_action("set_level","set_me");   /* will be removed later (obviously) */
add_action("add_touch","add_touch");  /* will also be removed later */
add_action("guildhall_help","druidhall");
add_action("set_skills","increase");
  }
}

set_skills(str) {
object ob;

ob = present("druid_ob",this_player());

if(!str) {write(GRN+"<< "+HIG+"Druidhall"+NORM+GRN+" >> "+NORM+"Which skill would you like to increase?\n");
return 1; }
  if(ob->query_skillpts() < 1) {
write(GRN+"<< "+HIG+"Druidhall"+NORM+GRN+" >> "+NORM+"You have no skill points to spend.\n");
return 1; }

if((str != "healing") && (str != "herbalism") && (str != "empathy") && (str != "plant") && (str != "elemental")){
write(GRN+"<< "+HIG+"Druidhall"+NORM+GRN+" >> "+NORM+"That is not a skill to increase. You may only\n");
write("                increase elemental, empathy, healing, herbalism or plant.\n");
return 1; }
  if(str == "healing"){
   if(ob->query_healskill() == 5){
write(GRN+"<< "+HIG+"Druidhall"+NORM+GRN+" >> "+NORM+"Your healing skill is at maximum.\n");
return 1; }
  ob->add_healskill(1);
}
  if(str == "herbalism"){
   if(ob->query_herbskill() == 5){
write(GRN+"<< "+HIG+"Druidhall"+NORM+GRN+" >> "+NORM+"Your herbalism skill is at maximum.\n");
return 1; }
  ob->add_herbskill(1);
}
  if(str == "elemental"){
   if(ob->query_eleskill() == 5){
write(GRN+"<< "+HIG+"Druidhall"+NORM+GRN+" >> "+NORM+"Your elemental skill is at maximum.\n");
return 1; }
  ob->add_eleskill(1);
}
  if(str == "empathy"){
   if(ob->query_empskill() == 5){
write(GRN+"<< "+HIG+"Druidhall"+NORM+GRN+" >> "+NORM+"Your empathy skill is at maximum.\n");
return 1; }
  ob->add_empskill(1);
}
  if(str == "plant"){
   if(ob->query_plantskill() == 5){
write(GRN+"<< "+HIG+"Druidhall"+NORM+GRN+" >> "+NORM+"Your plant skill is at maximum.\n");
return 1; }
  ob->add_plantskill(1);
}
write(GRN+"<< "+HIG+"Druidhall"+NORM+GRN+" >> "+NORM+"You have increased your "+str+" skill.\n");
  ob->add_skillpts(-1);
  ob->save_me();
return 1; 
}

set_level(str) {
  object ob;

num = str;
  ob = present("druid_ob",this_player());

/*  ob->change_glvl(num); */
  ob->add_glvl(1);
  ob->druid_save();
write("You have set your Druid guild level to "+num+".\n");
return 1; 
}

add_touch() {
object ob;

  ob = present("druid_ob",this_player());

  ob->add_touch(100);
  ob->druid_save();
write("You have added 100 touch pts.\n");
return 1;
}

guildhall_help(){
write(GRN+"<< --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- >>"+NORM+"\n");
write(YEL+"   --'--,--"+GRN+"<<"+HIR+"@"+NORM+HIG+"                 Druid Guildhall"+NORM+"                   "+HIR+"@"+NORM+GRN+">>"+YEL+"--,--'--"+NORM+"\n");
write(GRN+"<< --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- >>"+NORM+"\n");
write("   "+HIR+"Guildhall Commands"+NORM+"\n");
write("   cost - Check the cost of advancing to the next level.\n");
write("   advance - Actually advance to the next guild level.\n");
write("   increase - allows you to increase one of your skills, if you have a\n"+
      "              skill point to spend.\n");
write("\n");
write("   Plus, you can check the board and goto the church from the portal here.\n");
write(GRN+"<< --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- >>"+NORM+"\n");
write(YEL+"   --'--,--"+GRN+"<<"+HIR+"@"+NORM+HIG+"                 Druid Guildhall"+NORM+"                   "+HIR+"@"+NORM+GRN+">>"+YEL+"--,--'--"+NORM+"\n");
write(GRN+"<< --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- >>"+NORM+"\n");
return 1;
}

advance_cost() {
object ob;
int min_xp, c_xp, g_level;
int extra_xp, need_xp;
int c_touch, need_touch, amount;

ob = present("druid_ob",this_player());

  if((tp->query_level() > 20) && (tp->query_real_name() != "daranath")) {
  write("You have no need for this ability.\n");
  return 1; }
if(ob->query_glvl() > 39) {
write(GRN+"<< "+HIG+"Druidhall"+NORM+GRN+" >>"+NORM+" You cannot advance any further within the Druid sect.\n");
return 1;  }
  if(tp->query_extra_level()) 
    min_xp = call_other("/room/exlv_guild","get_next_exp",tp->query_extra_level()-1);
  else
    min_xp = call_other("/room/adv_guild","get_next_exp",tp->query_level()-1);
  c_xp = tp->query_exp();
  extra_xp = c_xp - min_xp;
 c_touch = ob->query_touch();
  g_level = ob->query_glvl();
  
  switch(g_level) {
case 1..4: need_xp = 10000; need_touch = 100; break;
case 5..9: need_xp = 15000; need_touch = 200; break;
case 10..14: need_xp = 25000; need_touch = 300; break;
case 15..19: need_xp = 50000; need_touch = 400; break;
case 20..24: need_xp = 75000; need_touch = 500; break;
case 25..29: need_xp = 100000; need_touch = 600;  break;
case 30..34: need_xp = 150000; need_touch = 700;  break;
case 35..39: need_xp = 200000; need_touch = 800;  break;
case 40: need_xp = 250000; need_touch = 1000;  break;
   }
   amount = need_xp - extra_xp;
if(amount > 0) write(GRN+"<< "+HIG+"Druidhall"+NORM+GRN+" >>"+NORM+" You need "+amount+" more exp to advance your Druid level.\n");
 else write(GRN+"<< "+HIG+"Druidhall"+NORM+GRN+" >>"+NORM+" You have enough exp to advance your Druid level.\n");
if(c_touch < need_touch) write("                Not enough touch of nature points.\n");
  else write("                Enough nature points.\n");
return 1; 
}

advance_glvl() {
object ob;
int min_xp, c_xp, g_level;
int extra_xp, need_xp;
int c_touch, need_touch;

ob = present("druid_ob",this_player());

if(ob->query_glvl() > 39) {
write(GRN+"<< "+HIG+"Druidhall"+NORM+GRN+" >>"+NORM+" You cannot advance any further within the Druid sect.\n");
return 1; }
  if(tp->query_extra_level()) 
    min_xp = call_other("/room/exlv_guild","get_next_exp",tp->query_extra_level()-1);
  else
    min_xp = call_other("/room/adv_guild","get_next_exp",tp->query_level()-1);
  c_xp = tp->query_exp();
  extra_xp = c_xp - min_xp;
  c_touch = ob->query_touch();
  g_level = ob->query_glvl();
  
  switch(g_level) {
case 1..4: need_xp = 10000; need_touch = 100; break;
case 5..9: need_xp = 15000; need_touch = 200; break;
case 10..13: need_xp = 25000; need_touch = 300; break;
case 15..19: need_xp = 50000; need_touch = 400; break;
case 20..24: need_xp = 75000; need_touch = 500; break;
case 25..29: need_xp = 100000; need_touch = 600;  break;
case 30..34: need_xp = 150000; need_touch = 700;  break;
case 35..39: need_xp = 200000; need_touch = 800;  break;
case 40: need_xp = 250000; need_touch = 1000;  break;
   }
   
   if(extra_xp < need_xp) {
write(GRN+"<< "+HIG+"Druidhall"+NORM+GRN+" >>"+NORM+" You need "+(need_xp - extra_xp)+" to advance your Druid level.\n");
   return 1; }
if(c_touch < need_touch) {write(GRN+"<< "+HIG+"Druidhall"+NORM+GRN+" >>"+NORM+" You need to work on your touch with Nature.\n"); return 1; }

if((ob->query_glvl() == 2) || (ob->query_glvl() == 5) || (ob->query_glvl() == 8) || (ob->query_glvl() == 11) || (ob->query_glvl() == 14) || (ob->query_glvl() == 17) || (ob->query_glvl() == 20) || (ob->query_glvl() == 23) || (ob->query_glvl() == 26) || (ob->query_glvl() == 29) || (ob->query_glvl() == 32) || (ob->query_glvl() == 35) || (ob->query_glvl() == 38) || (ob->query_glvl() == 39)) {
  ob->add_skillpts(1);
}
  tp->add_guild_exp(need_xp);
  tp->add_exp(-need_xp);
if(ob->query_animal_change() == 0) {
  ob->add_animal_change(1);
}
  ob->add_glvl(1);
  ob->save_me();
  tp->reset(1);
write(GRN+"<< "+HIG+"Druidhall"+NORM+GRN+" >>"+NORM+" You have advanced your Druid level.\n");
write("                       You can once again change your animal companion.\n");
   write_file("/players/daranath/druid/log/ADVANCE",ctime(time())+" "+tp->query_real_name()+"  level:"+
     (tp->query_level()+tp->query_extra_level())+"  To guildlevel:"+tp->query_guild_rank()+"\n");
   command("save",tp);
return 1; }

realm() {return "NT";}

