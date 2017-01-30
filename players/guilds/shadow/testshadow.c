#include "/players/guilds/shadow/shadow_lib/color.h"
#include "/players/guilds/shadow/cpdefine.h"
#include "/players/guilds/shadow/help.h"
#include "/players/guilds/shadow/cost.h"
#define SAVEPATH "players/guilds/shadow/shadows/"



 /* #######       VARIABLES       ####### */


  /*# general #*/

int muffled, summon, i, heal_count;
string short, command_str, rep_tell;

 /*## monitor ##*/

  /*monitor_count counts in the heart_beat*/
  /*to match the variable 'monitor'. When*/
  /*matched, shadow_monitor() is executed.*/

int monitor, monitor_count;
object at_ob;

  /*## shadow points, shadow level, experience points, etc ##*/

int shpoints, shlevel, shxp, point_select, max_shp;

   /*## spell variables ##*/

object servant, follow, pearl;
int shlevel, shxp, point_select, max_shp, drain_damage, spell_time;


 
id(string str) { return str == "mark"||str == "shadow-mark"||
   str == "guild_object"; }
short() { short = ESC+"[1m"+"A Mark of the Shadows"+ESC+"[0m";  
      return short;
}
long() {
   write("This is the Mark of the Shadow Guild.\nType 'info help'"+
         " to see a list of help topics.\n");
}
drop() { return 1; }
get() { return 1; }
value() { return 0; }
weight() { return 0; }
query_auto_load() {
   return THIS_FILE+":"+monitor+"#"+point_select+"#"+shlevel+
                 "#"+shxp+"#"+drain_damage;
}

init_arg(str) {
    sscanf(str,"%d#%d#%d#%d#%d",monitor, point_select,
   shlevel, shxp, drain_damage);
}

update_arg(str) {
       sscanf(str,"%d#%d#%d#%d#%d#%d#",monitor,
        point_select, shlevel, shxp, shpoints, drain_damage);
   return 1;
}

query_update_arg() {
     return monitor+"#"+point_select+"#"+shlevel+"#"+shxp+"#"+
          shpoints+"#"+drain_damage;
}

reset(arg) {
   

   write_file(PATH+"logs/clone",ctime(time())+"\n");
   if(!arg) {

      set_light(1);
      monitor = 0;
      summon = 0;
      command_str = 0;
      drain_damage = 5;
      i = 0;
      follow = 0;
      shlevel = 1;
      heal_count = 0;
      servant = 0;
      shpoints = 7;
      monitor_count = 0;
      at_ob = 0;
      set_heart_beat(1);
      call_out("lost_mark",1);

   }
}

heart_beat() {
   object tmproom;
   heal_count += 1;
   if(heal_count > 5) {
      if(shpoints < max_shp) shpoints+=1;
      heal_count = 0;
   }
   if(monitor > 0) {
      if(!(monitor_count % monitor)) {
         shadow_monitor();
         monitor_count = 0;
      }
      monitor_count++;
   }
    if(monitor < 0 &&( ENVTO->query_attack()||(servant&&
           servant->query_attack())))
      shadow_monitor();
   if(follow&&!present(follow, ENV(ENVTO))) {
      TEOWN("You follow "+CAP(follow->query_real_name())+".\n");
      tmproom = ENV(ENVTO);
      tell_room(ENV(follow), CAP(ENVTO->query_name())+" arrives, "+
        "following "+CAP(follow->query_name())+".\n");
      move_object(ENVTO, ENV(follow));
      tell_room(tmproom, CAP(ENVTO->query_name())+" leaves, follow"+
          "ing "+CAP(follow->query_name())+".\n");
      command("look", ENVTO);
   }
}

init() {

   if(TP->query_real_name() == "renee"||TP->query_real_name() == "moria") {
      write("You are no longer a shadow due to your pking other shadows.\n"+
      "If you have any problems with this, please mail Blue.\n");
      TP->add_guild_rank(-TP->query_guild_rank());
      TP->set_guild_name("0");
      TP->add_guild_exp(-TP->query_guild_exp());
      TP->set_al_title(" ");
      destruct(TO);
      return 1;
   }
   /*# standard functions #*/
   
   add_action("muffle_me","muffle");
   add_action("repeat_tell","te");
   add_action("catch_the_tell","tell");
   add_action("catch_repeat"); add_xverb("");
   add_action("do_repeat","r");
   add_action("update_me","update");
   add_action("guild_talk","sh");
   add_action("guild_emote","she");
   add_action("shadow_speak","shay");
   add_action("shadow_inventory","shi");
   add_action("other_who","ow");
   add_action("guild_who","shw");
   add_action("set_my_title","title");
   add_action("set_my_pretitle","pretitle");
   add_action("do_emote","emote");
   add_action("do_emote","m");
   add_action("end_game","quit");
   add_action("pk_who","pk");
   add_action("shadow_monitor","mon");
   add_action("select_point_toggle","toggle");
   add_action("transfer_da_points","transfer");
   add_action("guild_stat","sc");
   add_action("drain_damage","dd");
   add_action("set_shadow_monitor","shp");
   add_action("help_subject","info");
   /*
   add_action("toggle_summon","allow");
   */
   add_action("follow_player", "follow");
      add_action("stop_follow","unfollow");
   add_action("do_command","r");
   add_action("get_time", "time");

   /*# commander functions #*/

      if(shlevel > 12 || CN == "Blue") {
     
      add_action("add_shadow_shxp","<>addshxp");
      add_action("remove_mark","<>remove");
      add_action("comander_who","<>w");
      add_action("promote_shadow","<>promote");
      add_action("commander_emote","ce");
      add_action("commander_talk","ct");
      add_action("give_mark","<>mark");
   }
   

   /*# spells #*/

   add_action("drop_trail","trail");
   add_action("follow_trail","track");
   add_action("set_back","back");
   add_action("set_next","forward");
   add_action("forge_something","forge");
   add_action("empty_corpse","empty");
   add_action("drain_monster","drain");
   add_action("death","death");
   add_action("chain_fireball","chain");
   add_action("make_pearl","pearl");
   /*
   add_action("fade_to_player","fade");
   add_action("summon_player","summon");
  */
   add_action("back_to_guild", "guild");
   add_action("cure_me","cure");
   add_action("stealth","stealth");
   add_action("calm_room","calm");
   add_action("peace_monster","peace");
   add_action("scan_monster","scan");

}


 /*####                    UTILITIES              ####*/


query_possesive() {
   if(TP->query_gender()=="male") return "his";
     else if(TP->query_gender()=="female") return "her";
   return "its";
}

query_max_shp() {
   max_shp = (shlevel *7);
   return max_shp;
}

query_shlevel() {
   return shlevel;
}

query_shadow_xp() {
   return shxp;
}

query_muffled() {
   return muffled;
}


level_check(level) {
   if(level > shlevel) {
      return 0;
   }
   return 1;
}

query_carry() {
   int strength;
   strength = TP->query_attribute("str");
   if(this_player()->query_level()==1) 
      return (this_player()->query_level() + 6 + strength/2);
  else return (this_player()->query_level()+6+strength/5);
}

query_summon() {
   return summon;
}

promote_me(num) {
   int tmp_shxp;
   tmp_shxp = shxp;
   if(shlevel + num > 12 && TP->query_real_name() != "guilds") return 0;
   shlevel += num;
   if(shlevel < 13)
   shxp = call_other(BLACK_ORB, "cost_at_level",shlevel);
   shpoints = query_max_shp();
   ENVTO->add_guild_rank(num);
   ENVTO->add_guild_exp(-GXP);
   ENVTO->add_guild_exp(shxp);
   return 1;
}

add_shxp_me(num) {
   shxp += num;
   return 1;
}

set_shxp_me(num) {
   shxp = num;
   return 1;
}

query_shpoints() {
   return shpoints;
}

set_shpoints(num) {
   shpoints = num;
}

end() {
   destruct(TO);
   return 1;
}

time_check() {
   if(shlevel > 11) return 1;
   if(time() - spell_time < 3) {
      write("It is too soon since your last attack.\n");
      return 0;
   }
   return 1;
}

drain_damage(str) {
   int num;
   if(sscanf(str, "%d", num) !=1) return;
   if(5*shlevel < num) {
      write("You may set your drain damage at up to five times you shadow\n"+
            "level.\n");
      return 1;
   }
   drain_damage = num;
   write("Drain damage now set at "+num+".\n");
   return 1;
}

end_game() {
   if(present("pearl_obejct",TP)) pearl->end_game();
   guild_echo("\n<>"+CN+"<> has left the game.\n");
   save_object(SAVEPATH + TP->query_real_name());
}

save_me_now() {
   save_object(SAVEPATH + TP->query_real_name());
}

lost_mark() {
   int tmp;
   string cn;
   cn = CAP(ENVTO->query_real_name());
   if(ENVTO->query_guild_name()=="shadow") {
      TEOWN("Restoring shadow mark...\n");
      shxp = ENVTO->query_guild_exp();
      shlevel = ENVTO->query_guild_rank();
   } else {
         write_file(PATH+"logs/NEW",cn+" joined the "+
       "shadows at "+ctime(time())+"\n\n");
      shlevel = 1;
      tmp = ENVTO->query_guild_rank();
      shxp = 1;
      ENVTO->add_guild_rank(1 - tmp);
      tmp = ENVTO->query_guild_exp();
      if(tmp == 1234) destruct(TO);   /* should not happen */
      ENVTO->add_guild_exp(1 - tmp);
      guild_echo("<<-->>"+BOLD+cn+NOSTYLE+" has just joined the Shadow Guil"+
           "d!!!\n");
   }
   ENVTO->set_guild_name("shadow");
   ENVTO->set_al_title(BOLD+"<SHADOW>"+NOSTYLE);
   if(shpoints > MSHP) shpoints = MSHP;
   TEOWN("Done.\n");
   return 1;
}


 /*####                 STANDARD                        ####*/


set_shadow_monitor(string num) {
   if(num == "attack") {
      monitor = -1;
      write("Monitor set to attack.\n");
      return 1;
   }
   if(!num) {
      monitor = 0;
      write("Monitor off.\n");
      return 1;
   }
   if (!num || !sscanf(num,"%d",monitor)) {
      write("Usage: shp <number>.  If number is '0', monitor is off.\n");
      return 1;
   }
   if(!monitor || monitor == 0) {
  monitor = 0;
      write("Monitor is off.\n");
      return 1;
   }
   write("Monitor time set to "+monitor+".\n");
   monitor_count = 0;
   return 1;
}

shadow_monitor() {
   object at_ob;
   int mhp, hp;
   if(ENVTO->query_attack()) TEOWN(BOLD);
    TEOWN("<hp: " + HP +"/" + MHP + "> <");
    if(ENVTO->query_attack()) TEOWN(NOSTYLE);
   TEOWN("sp: " + SP + "/" + MSP + "> <");
   TEOWN("shp: " + shpoints + "/" + MSHP + "> ");
   if(ENVTO->query_soaked()) {
      TEOWN("<int: "+ENVTO->query_soaked()+"/"+ LEVEL * 8 + ">");
   }
   if(ENVTO->query_stuffed()) {
    TEOWN("<food: " + ENVTO->query_stuffed() + "/" + LEVEL *8 + ">");
   }
   if(ENVTO->query_attack()) {
      at_ob = ENVTO->query_attack();
      if(at_ob) {
         hp = at_ob->query_hp();
         mhp=at_ob->query_mhp();
         if(mhp&&hp) {
            TEOWN("<at:");
           if(hp < (mhp/10) ) {
               TEOWN("vbs>\n"); 
             } else if(hp < (mhp/5) ) { TEOWN("bs>");
             } else if(hp < (mhp/2) ) { TEOWN("swh>");
            } else if(hp < (mhp - 20) ) { TEOWN( "slh> ");
            } else TEOWN("gs>");
         }
      }
   }
   if(servant) {
      if(servant&&servant->query_attack()) TEOWN(BOLD);
      TEOWN("<serv: "+servant->query_hp()+"/300>");
      if(servant&&servant->query_attack()) TEOWN(NOSTYLE);
   }
   TEOWN("\n");
   return 1;
}



   /*####   shadow points are points that can be used       #### */
   /*####   for shadow spells, or transfered ( at a variable  ####*/
   /*####   rate) for spell points.                            ####*/

  /*## sets which points to be drained first.      ##*/
  /*## 1 means sp first, 0 means sh points first ##*/

select_point_toggle() {
   if(point_select == 1) {
      write("Ok, shadow points will be drained first.\n");
      point_select = 0;
      return 1;
   } 
   write("Ok, spell points will be drained first.\n");
   point_select = 1;
   return 1;
}

less_sp(pts) {
    TP->add_spell_point((pts *(-1)));
   return 1;
}

less_shp(pts) {
   shpoints -= pts;
   return 1;
}

add_shadow_point(pts) {
   shpoints  += pts;
   if(shpoints > MSHP) shpoints = MSHP;
   return 1;
}

less_pts(pts) {
   int temp_spell, temp_shadow;
   temp_spell = SP;
   temp_shadow = shpoints;
   if(shlevel > 13) return 1;
   if(pts > (SP + shpoints)) {
      write("You do not have enough spell or shadow points.\n");
      return 0;
   }
   if(point_select == 1) {
      if(pts > SP) {
         less_sp(SP);
         less_shp(pts-temp_spell);
         return 1;
      }
      less_sp(pts);
      return 1;
   }
   if(point_select == 0) {
      if(pts > shpoints) {
         less_shp(shpoints);
         less_sp(pts-temp_shadow);
         return 1;
      }

      less_shp(pts);
      return 1;
   }
   return 0;
}

transfer_da_points(str) {
   int num;
   string kind;
   if(!str||sscanf(str,"%d %s", num, kind)!=2) {
      write("Usage is: transfer <amount> <shp or sp>\n");
      return 1;
   }
   if(kind=="sp") {
      transfer_spell_to_shadow(num);
      return 1;
   }
   if(kind=="shp") {
      transfer_shadow_to_spell(num);
      return 1;
   }
}

transfer_shadow_to_spell(int amt) {
   int add, ratio;
      if(amt < 0) {
      write("YOU MAY NOT TRANSFER NEGATIVE POINTS!!!\n");
      write_file(PATH+"logs/negative", CN+ " tried to transfer neg. points @"+
            " "+ctime(time())+".\n");
      return 1;
   }
   if(amt > shpoints) {
      write("You do not have that many shadow points.\n");
      return 1;
   }
   if((SP+amt) > MSP) amt = (MSP - SP);
   shpoints -= amt;
   ratio = 1000*shlevel/(shlevel + 2);
   add = amt*ratio;
  TP->add_spell_point(add/1000);
   write("Done.\n");
   shadow_monitor();
   return 1;
}

transfer_spell_to_shadow(int amt) {
   int add, ratio;
   if(amt < 0) {
      write("YOU MAY NOT TRANSFER NEGATIVE POINTS!!!\n");
      write_file(PATH+"logs/negative", CN+ " tried to transfer neg. points @"+
            " "+ctime(time())+".\n");
      return 1;
   }
   if(amt > SP) {
      write("You do not have that many spell points.\n");
      return 1;
   }
   if((amt + shpoints) > max_shp) amt = (max_shp - shpoints);
   less_sp(amt);
   ratio = 1000 *shlevel/(shlevel + 2);
   add = amt*ratio;
   shpoints += add/1000;
   write("Done.\n");
   return 1;
}

guild_stat() {
   write(ENVTO->short()+"\n");
  
   write("--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--\n");
   write("<>Level: "+LEVEL+"\t\t\t<>Extra Level: "+
             ENVTO->query_extra_level()+"\n");
   write("<>Hit Points: "+HP+"/"+MHP+"\t\t<>Experience: "+
            ENVTO->query_exp()+"\n");
   write("<>Spell Points: "+SP+"/"+MSP+"\t\t<>Shadow Experience: "+shxp+"\n");
   write("<>Shadow Points: "+shpoints+"\t\t<>Shadow level: "+shlevel+"\n");
   write("<>Gold: "+TP->query_money()+"\t\t\t<>Quest points: "+
       ENVTO->query_quest_point()+"\n");
   write("Unspent XPs: "+
   call_other(BLACK_ORB, "get_free"));
   write("\n\n");
   if(muffled) write("You are muffled.\n");
      else write("You have no servant.\n");
   if(point_select == 1) write("Spell points being drained first.\n");
      else write("Shadow points being drained first.\n");
   /*
    if(summon) write("Allowing summons.\n");
       else write("Not allowing summons.\n");
 */
   write("Drain doing "+drain_damage+" points of damage.\n");
   return 1;
}

catch_repeat(str) {
   if(str && str != "r") command_str = str;
}

do_repeat(str) {
   if(!str) {
      if(!command_str || command_str == "r") {
         write("Nothing to repeat. You must enter a command before"+
             " you can repeat it.\n");
         return 1;
      } else {
         write("Repeating '"+command_str+"'.\n");
          if(!command(command_str, TP)) {
           write("That function cannot be repeated.\n");
            return 1;
         }
         return 1;
      }
   }
}

catch_the_tell(str) {
   string arg;
   if(str) {
      arg = explode(str," ");
      if(find_player(arg[0])) rep_tell = arg[0];
   }
}

tell_player(object player, string str) {
   int invis;
   invis = call_other(TP, "query_invis", 0);
   if(TP->query_ghost()) {
        write("You fail.\n");
        return 1;
    }
    if (SP < 0) {
        write("You are low on power.\n");
        return 1;
    }
   if(LEVEL < 20 && !less_pts(5)) return 1;
   if(!str) {
      write("Tell what?\n");
      return 1;
   }
    if (interactive(player)) {
        if (player->query_invis() >= 100) {
            write("No player with that name.\n");
            return 1;
        }
        if (in_editor(player)&& LEVEL < 40) {
            write("That person is editing. Please try again later.\n");
            return 1;
        }
    }
   if(invis > 0 && invis < 39) {
      write("You must become visable before you can tell"+
          " anyone something.\n");
      return 1;
   }
   str = format(str, 60);
   tell_object(player, CN + " tells you: " + str + "\n");
    write("Ok.\n");
    write("You tell "+player->query_name()+ " " + str);
    return 1;
}

repeat_tell(str) {
   string tmp_tell;
   if(!str) return;
   if(!rep_tell) return;
   tmp_tell = rep_tell+" "+str;
   if(!find_player(rep_tell)) {
      write("That player is no longer on the game.\n");
      return 1;
   }
   tell_player(find_player(rep_tell), str);
   return 1;
}

shadow_speak(str) {
   object ob;
   ob = first_inventory(ENVTP);
   while(ob) {
      if(present("shadow-mark",ob)&& ob != TP) 
          tell_object(ob, CN+" shadow speaks: "+str+"\n");
      else if(ob != TP) tell_object(ob, "You hear a quiet whisper"+
               " behind your back.\n");
      ob = next_inventory(ob);
   }
   write("You shadow speak: "+str+"\n");
   return 1;
}

guild_all() {
  guild_who(1,1000);
  return 1;
}

muffle_me(str) {
   if(str) return;
   if(muffled) {
      write("Turning shadow channel on.\n");
      muffled = 0;
      return 1;
   }
   write("Turning shadow channel OFF.\n");
   muffled = 1;
   return 1;
}

update_me(str) {
  object ob;
   if(str) return;
   save_me_now();
   write("Saved guild scores.\n");
   ob = clone_object("/players/guilds/shadow/shadow.c");
   write("Created new object.\n");
   ob->set_servant(servant);
   write("Set servant.\n");
   ob->update_arg(query_update_arg());
   write("Sent update arg.\n");
   move_object(ob, TP);
   write("Moved new object.\n");
   write("Shadow mark restored.\n");
  destruct(TO);
  return 1;
}

guild_who() {
   object *pepl, mark;
   int i, n;
    write("--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--\n");
   pepl = users();
   n = 0;
   i = 0;
   while(n < sizeof(pepl)) {
       mark = present("shadow-mark", pepl[n]);      
       if( mark &&  !(pepl[n]->query_invis()&&
              pepl[n]->query_level() > LEVEL)&&ENV(pepl[n])) {
         write(CAP(pepl[n]->query_name()));
         if(strlen(pepl[n]->query_name()) < 8) write("\t");
         write("\t"+mark->query_shlevel());
         write("\t"+environment(pepl[n])->short()+"\n");
         i += 1;  
      }
      n += 1;
   }
   write("--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--\n");
   write(i+" shadows logged on.\n");
   return 1;
}

other_who() {
   object *pepl;
   int i, n, tmp, z, x, size;
   string tmp_env, env, guild;
   n = 0;
   x = 0;
   z = 0;
   pepl = users();
    write("Name\tGuild\t\tLocation\n");
   write("--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--\n");
   write("\n");
   while(n < sizeof(pepl)) {
        if(!(pepl[n]->query_invis()&&pepl[n]->query_level() > LEVEL)&&
             pepl[n]->query_name()&&ENV(pepl[n])) {
         write(pepl[n]->query_name());
         if(strlen(pepl[n]->query_name()) < 8) write("\t");
         write("\t");
         guild = pepl[n]->query_guild_name();
         if(!guild) {
            if(present("mrobe",pepl[n])) guild = "monk";
            else if(present("fangs", pepl[n])) guild = "vampire";
            else if(present("license",pepl[n])) guild = "assassin";
            else if(present("seal",pepl[n])) guild = "mason";
            else if(present("robes", pepl[n])) guild = "cleric";
            else if(present("books", pepl[n])) guild = "mage";
         }
         if(!guild) guild = "None";
         if(guild == "shadow") guild = "SHADOW";
         if(guild == "alchemists") guild = "alchem";
         write(CAP(guild)+"\t");
         env=environment(pepl[n])->short();
         if(!env) env = "None.";
          if(strlen(env) > 25) {
              tmp_env = explode(env, " ");
             write("\t");
              size = sizeof(tmp_env);
               while( x < size && z + strlen(tmp_env[x]) < 35) {
               write(tmp_env[x]+" ");
               z+= strlen(tmp_env[x]);
                x+=1;
            }
             z = 0;
             x = 0;
             write("\n");
          } else { write("\t"+env+"\n");
         }
         i += 1;  
      }
      n += 1;
   }
   write("\n");
   write("--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--\n");
   write(i+" visible users on.\n");
   return 1;
}

pk_who() {
   object *pepl;
   int n, i, size;
   pepl = users();
   write("Name\t\tLocation\n");
   write("--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--\n");
   write("\n");
   size = sizeof(pepl);
   while(n < size) {
      if(!(pepl[n]->query_invis()&&pepl[n]->query_level() > LEVEL)&& 
            pepl[n]->query_pl_k()&&pepl[n]->query_level() < 20&&ENV(pepl[n])){
         write(CAP(pepl[n]->query_name())+"\t\t");
          write(ENV(pepl[n])->short()+"\n");
         i+=1;
      }
      n+=1;
    }
   write("\n");
   write("--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--\n");
   write(i+" visible player killers on.\n");
   return 1;
}

guild_echo(str) {
   int n;
   object *pepl;
   object mark;
   pepl = users();
   n = 0;
   while(n < sizeof(pepl)) {
      mark = present("shadow-mark",pepl[n]);
      if(mark && !mark->query_muffled()) {
         tell_object(pepl[n], str);
      }
      n += 1;
   }
   return 1;
}

guild_talk(str) {
   string message;
   message = "<"+CAP(TP->query_real_name())+">: " +str+"\n";
   guild_echo(message);
   return 1;
}

guild_emote(str) {
   string emote;
   emote = "<>: "+CAP(TP->query_real_name())+ " "+str+"\n";
   guild_echo(emote);
   return 1;
}

shadow_inventory() {
   object ob;
   int len, weight;
   write("--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--\n");
   ob = first_inventory(this_player());
   while(ob) {
      if(ob->short()) {
         write(ob->short());
         len = 40 - strlen(ob->short());
         while(len > 0) {
            write(" ");
            len -= 1;
         }
         write("\t"+ob->query_weight()+"\n");
         weight += ob->query_weight();
      }
      ob = next_inventory(ob);
   }
   write("--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--\n");
   write("Total carried weight:"+weight);
   if(LEVEL + 6 == 1) write("/"+(STRENGTH/2+LEVEL)+"\n");
      else write("/"+(STRENGTH/5+LEVEL + 6)+"\n");
   return 1;
}



toggle_summon() {
   if(summon == 0) {
      write("Allowing summons.\n");
      summon = 1;
      return 1;
   } else {
      summon = 0;
      write("NOT allowing summons.\n");
      return 1;
   }
}

set_my_pretitle(str) {
   if(!str) str = " ";
   TP->set_pretitle(str);
   write("Pretitle is now '"+str+"'.\n");
   return 1;
}

set_my_title(str) {
   if(!str) str = " ";
   TP->set_title(str);
   write("Title is now '"+str+"'.\n");
   return 1;
}

do_emote(str) {
   if(!str) {
      write("Emote what?\n");
      return 1;
   }
   write("You emote:\n");
   tell_room(ENVTP, CN+" "+str+"\n");
   return 1;
}

 /*####                     SPELLS                                ####*/


forge_something(str) {
   if(str =="sword") {
      if(!level_check(4)) return;
      if(!less_pts(SWORDCOST)) return 1;
      make_forge(str, SWORDCOST);
      return 1;
   }
   if(str == "dagger") {
      if(!less_pts(DAGGERCOST)) return 1;
      make_forge(str, DAGGERCOST);
      return 1;
   }
   if(str == "blade") {
      if(!level_check(9)) return;
      if(!less_pts(BLADECOST)) return 1;
      make_forge(str, BLADECOST);
      return 1;
   }
   if(str == "chainmail") {
      if(!level_check(4)) return;
      if(!less_pts(CHAINCOST)) return 1;
      make_forge(str, CHAINCOST);
      return 1;
   }
    write("Usage: 'forge <weapon>' or 'forge chainmail'.\n");
   return 1;
}

make_forge(string str, int cost) {
   object ob;
   ob = clone_object(PATH+"forge/"+str+".c");
   if(!ob) {
      write("That is not a choice.  Type 'info forge' for more info.\n");
      return 1;
   }
   move_object(ob, TP);
   write("You reach into the darkness....something solid forms.\n");
   write("You pull a "+str+" out of the shadows.\n");
   say("The room goes dark...."+CN+" pulls "+ob->short()+" from the dark"+
       "ness.\n");
   return 1;
}

drop_trail(str) {
   object trail;
   if(!level_check(2)) return;
   if(str) return;
   if(!less_pts(2)) {
      write("You do not have enough spell/shadow points to do that.\n");
      return 1;
   }
    trail = clone_object(PATH+"trail_mark.c");
   move_object(trail, ENVTP);
   trail->set_owner(TP);
   write("You drop a trail marker.  Don't forget to set the directi"+
                 "ons!\n");
   say(CN+" dropped a trail marker.\n");
   return 1;
}

set_back(string str) {
   object trail;
   int found;
   if(!level_check(2)) return;
   if(!str) {
      write("Which way should you go to get to the previous room?");
      input_to("set_back");
      return 1;
   }
   trail = trail_search();
   if(!trail) {
      write("You do not have a trail marker in this room.\n");
      return 1;
   }
   if(!less_pts(1)) {
      write("You need at least one spell point to set the trail marker.\n");
      return 1;
   }
   trail->set_reverse(str);
   write("Back direction is "+str+".\n");
   return 1;
}

set_next(string str) {
   object trail;
   if(!level_check(2)) return;
   if(!(trail = present("trail_mark", ENVTP))) {
      write("There is no trail marker here.\n");
      return 1;
   }
   if(!str) {
      write("Which way should you go to get to the next room?");
      input_to("set_next");
      return 1;
   }
   trail = trail_search();
   if(!trail) {
      write("You do not have a trail marker in this room.\n");
      return 1;
   }
   if(!less_pts(1)) {
      write("You need at least one spell point to set the trail marker.\n");
   }
   trail->set_forward(str);
   write("Forward direction is "+str+".\n");
   return 1;
}      
      
trail_search() {
   object trail;
   trail = first_inventory(ENVTP);
   while(trail) {
      if(trail->query_owner() == TP) {
      return trail;
      } else {
      trail = next_inventory(trail);
      }
   }
   return 0;
}

follow_trail(str) {
   int num;
   object trail, env;
   string direction;
   if(!level_check(2)) return;
   if(!str) return;
   trail = trail_search();
   if(!trail) {
      write("You do not have a trail marker in this room.");
      return 1;
   }
   if(sscanf(str, "%s %d", direction, num)!=2 || !(direction == "forward"||
   direction == "back")) {
      write("Usage: 'trail' to drop trail, 'trail <back or forward>"+
         " <number> to move back or forward\non the trail.  If no number"+
         " the trail will be followed as far as possible.\n");
      write(" followed as far as possible.\n");
      return 1;
   }
  while( num ) {
      env = ENVTP;
      
      if(!less_pts(3)) {
         write("Trail broken.\n");
         return 1;
      }
      if(!(trail->move_me(direction))) {
         write("Direction failed.\nTrail broken.\n");
         return 1;
      }
      if(env == ENVTP) {
         write("Loop found.\n");
         write("Trail broken.\n");
         return 1;
      }
      trail = trail_search();
      if(!trail) {
         write("Trail ended.\n");
         return 1;
      }
      num -= 1;
      }
   write("Trail finished.\n");
   return 1;
}


empty_corpse(str) {
   int heal;
   object corpse;
   if(str) return;
   if(!level_check(1)) return;
   corpse = present("corpse", ENVTP);
   if(!corpse) {
      write("There is no corpse here.\n");
      return 1;
   }
   heal = corpse->heal_value();
      if(!heal) heal = 15;
   destruct(present("corpse",ENVTP));
   TP->heal_self(heal);
   write("You empty the corpse of its remaining energy.\n");
   say(CN+" lets "+ query_possesive()+" shadow fall over the corpse.\n");
   tell_room(ENVTP,"It shrivels into dust and scatters.\n");
   return 1;
}

chain_fireball() {
   int n, cost;
   object ob, tmp;
   if(!level_check(9)) return;
   ob = first_inventory(ENVTP);
   n = 0;
   if(!time_check()) return 1;
   while(ob) {
       if(!ob->is_player()&&living(ob)&&!ob->query_pet()) {
         n+=1;
      }
      ob = next_inventory(ob);
   }
   if(n < 2) cost = 5;
      else if(n<6) cost = 4;
      else cost = 3;
   if(n==0) {
      write("There is nothing in here you can attack.\n");
      return 1;
   }
   n = 0;
   ob = first_inventory(ENVTP);
   while(ob&&less_pts(shlevel*cost)) {
      tmp = next_inventory(ob);
        if(!ob->is_player()&&living(ob)&&!ob->query_pet()) {
         if(n == 0) {
            say(CN+" raises "+query_possesive()+" hands into the air.\n");
            say("Dark purple fire pours out!!!\n");
            write("Fire shoots out of your finger tips!\n");
         }
         n+=1;
         tell_room(ENVTP, ob->short() +" is completely enveloped"+
              " by purple fire!!!\n");
         ob->hit_player(shlevel * 5);
         if(ob) ob->attack_object(TP);
      }
      ob = tmp;
   }
   spell_time = time();
   return 1;
}

drain_monster(str) {
   object att;
   if(!str) str = 0;
   if(!time_check()) return 1;
   att = get_attacker_object(str);
   if(!att)  
      return 1;
   if(!less_pts(drain_damage)) return 1;
   write("You reach out to "+att->short()+" and drain its energy.\n");
   say(CN +" reaches out to "+att->short() +" and drains its energy.\n");
   att->hit_player(drain_damage);
   spell_time = time();
   if(att&&!att->query_attack()) att->attack_object(TP);
   return 1;
}

death(str) {
   object att;
   if(!str) str = 0;
   if(!level_check(12)) return;
   if(!time_check()) return 1;
   att = get_attacker_object(str);
   if(!att) return 1;
   if(!less_pts(70)) return 1;
   write("Ok.\n");
   tell_room(ENVTP, att->short() +" is surrounded by darkness!\n");
   tell_room(ENVTP, "You hear a hideous scream.\n");
   att->hit_player(85);
   TP->hit_player(15);
   spell_time = time();
   if(att&&!att->query_attack()) att->attack_object(TP);
   return 1;
}

get_attacker_object(string str) {
   object att;
   if(!str&&!TP->query_attack()) {
      write("What are you going to attack?\n");
      return 0;
   }
   if(!str || str == "0") att = TP->query_attack();
      else att = present(str, ENVTP);
   if(!att) {
      write("There is no "+str+" here.\n");
      return 0;
   }
   if(!living(att)) {
      write("That is not a living thing!\n");
      return 0;
   }
   if(!att->query_npc()) {
      write("You cannot use guild spells on players.\n");
      return 0;
   }
   if( TP->query_attack() && att != TP->query_attack()) {
      write("You are already attacking something else.\n");
      return 0;
   }
   return att;
}

make_pearl() {
   if(!level_check(1)) return 1;
   if(present("pearl", TP)) {
      write("You already have a pearl.\n");
      return 1;
   }
   if(present("pearl_object",TP)) {
      write("You already have a servant!\n");
      return 1;
   }
   if(!less_pts(SERVANTCOST)) return 1;
   pearl = clone_object(PEARL);
   move_object(pearl, TP);
   pearl->set_master_name(TP->query_real_name());
   pearl->set_shadow_mark(TO);
   tell_room(ENVTP, "A mist gathers.\n");
   tell_room(ENVTP, "It solidifies into a small black pearl.\n");
   say(CN+" picks up the pearl and tucks it away.\n");
   write("You take the pearl and tuck it away.\n");
   return 1;
}

set_servant(ob) {
   servant = ob;
   return 1;
}

get_servant(string str) {
   int what;
   if(!level_check(6)) return;
   if(!str) return;
   if(!present(str, servant)) {
      write("Your servant doesn't have a "+str+".\n"); 
      return 1;
   }
   what = servant->give_object(str);
   if(what == 0) {
      write("Your servant happily serves you.\n");
      say("A servant hands something to "+CN+".\n");
      return 1;
   }
   if(what == 1) {
      write("You can't carry that much.\n");
      return 1;
   }
}

give_servant(string str) {
   object ob;
   if(!level_check(6)) return;
   if(!str) return;
   if(!servant) {
      write("You have no servant.\n");
      return 1;
   }
   ob = present(str, TP);
   if(!ob) {
      write("You do not have a "+str+".\n");
      return 1;
   }
   if(first_inventory(ob)) {
      write("You must empty that container first.\n");
      return 1;
   }
   if(servant->query_holding() + ob->query_weight() > 12) {
      write("Your servant cannot hold that much.\n");
      return 1;
   }
   move_object(ob, servant);
   servant->add_hold(ob->query_weight());
   TP->recalc_carry();
   write("You give your servant a "+str+".\n");
   say(CN +" gives "+query_possesive()+" servant "+ob->short()+"\n");
   return 1;
}

name_servant(str) {
   if(!str||str == " ") {
      return;
   }
   if(!level_check(6)) return;
   if(!servant) return 0;
   servant->name_servant(str);
   write("Ok, you name your servant "+str+".\n");
   return 1;
}

 /*
dismiss_servant(str) {
   if(!level_check(6)) return;
   if(!str || str !="servant") return;
   if(!servant) {
      write("You do not have a servant.\n");
      return 1;
   }
   if(file_name(ENV(servant)) == PATH+"rooms/servant_store") {
      write("Your servant was already dismissed.\n");
      return 1;
   }
   if(!less_pts(SERVCALLCOST)) return 1;
   servant_hp = servant->query_hp();
   move_object(servant, PATH+"rooms/servant_store.c");
   servant->unheart();
   write("Your servant disapears into the shadows.\n");
   say("A shadow servant disappears into the darkness.\n");
   has_servant = 0;
   return 1;
}
 */

 /*
call_servant() {
   if(!level_check(6)) return;
    if(servant&&present(servant, ENVTP)) {
      write("You already have a servant.\n");
      return 1;
   }
      if(!find_servant()&&!servant_hp) {
      write("You do not have a servant to call.  Type "+
             "'info servant' for more help.\n");
      return 1;
   }
   if(!less_pts(SERVCALLCOST)) return 1;
   if(!servant) {
      if(!find_servant()) {
         servant = clone_object(PATH+"servant.c");
         servant->set_hp(servant_hp);
      }
   }
   move_object(servant, ENVTP);
   servant->set_master(TP);
   servant->set_master_name(TP->query_real_name());
   write("Your servant appears from the shadows.\n");
   say("A shadow servant materializes.\n");
   has_servant = 1;
   return 1;
}
 */

find_servant() {
   object ob, room;
   room = find_object(PATH+"rooms/servant_store.c");
   if(!room) return 0;
   ob = first_inventory(room);
   while(ob) {
         if(ob->query_master_name()==TP->query_real_name()) {
         servant = ob;
         return 1;
      }
      ob = next_inventory(ob);
   }
   return 0;
}

 /*
add_servant(str) {
   int num, heal;
   if(!level_check(6)) return;
   if(!servant) {
      write("You do not have a servant.\n");
      return 1;
   }
   if(!str||sscanf(str, "%d",num) != 1) {
      write("Usage: 'add <num>'.\n");
      return 1;
   }
   if(num < 0) {
      write("YOU CANNOT ADD NEGATIVE POINTS.\n");
      write_file(PATH+"logs/negative",CN+" tried to add neg. points @ "+
          ctime(time())+".\n");
      return 1;
   }
   if(!less_pts(num)) return 1;
   heal = servant->query_hp() + (num*3)/4;
   servant->set_hit_points(heal);
   servant_hp = servant->query_hp();
   write("Your servant is at "+
      servant_hp+"/"+servant->query_mhp()+".\n");
   return 1;
}
 */
   
fade_to_player(str) {
   object player;
   int cost;
   string who;
   if(!level_check(6)) return;
   if(sscanf(str, "to %s",who) != 1) {
      write("Usage: 'fade to <player>'.\n");
      return 1;
   }
   player = find_player(who);
   if(!player) {
      write("That player is not on the game.\n");
      return 1;
   }
   if(present("shadow-mark",player)) {
      cost = GUILD_FADE;
      if(!level_check(7)) return;
   }
      else cost = FADE;
   if(ENVTP->realm()=="NT"||ENV(player)->realm()=="NT") {
      write("Your shadow begins to fade, but cannot disappear.\n");
      return 1;
   }
   if(!less_pts(cost)) return 1; 
   say(CN +" begins to fade away into darkness.\n");
   move_object(TP, ENV(player));
   say("Darkness forms.\nFrom the darkness, "+CN+" materializes.\n");
   write("You fade into darkness....\n");
   command("look", TP);
   return 1;
}

summon_player(str) {
   object player;
   if(!level_check(10)) return;
   if(!str) return;
   player = find_player(str);
   if(!player) {
      write("That player is not on the game right now.\n");
      return 1;
   }
   if(!present("shadow-mark", TP)) {
      write("You can only summon shadows.\n");
      return 1;
   }
   if(!query_summon()||!(present("shadow-mark", player)->query_summon())) {
      write("You both must be allowing summons to summon someone.\n");
      return 1;
   }
   if(ENVTP->realm()=="NT"||ENV(player)->realm()=="NT") {
      write("You feel there presence, but they cannot be moved.\n");
      tell_object(player, "You feel a shadow trying to summon you, but "+
             "they fail.\n");
      return 1;
   }
   if(!less_pts(SUMMON_COST)) return 1;
   write("You find "+CAP(str)+"'s presence and bring it to you.\n");
   say(CAP(player->query_name())+" materializes next to "+CN+".\n");
   move_object(player, ENVTP);
   tell_object(player, "You are summoned by "+CN+".\n");
   command("look", player);
   return 1;
}

back_to_guild() {
   if(!level_check(4)) return;
   if(ENVTP->realm() == "NT") {
      write("You begin to disappear, but something near you is "+
           "blocking you.\n");
      return 1;
   }
   if(!less_pts(GUILD_COST)) return 1;
   say("A flood of darkness fills the room.\n");
   say(CN +" goes dim and then disappears.\n");
    TP->move_player("guild#"+PATH+"rooms/meeting.c");
   write("You are back in safety.\n");
   say(CN +" appears in a flash of darkness.\n");
   return 1;
}

stealth(str) {
   string dest, room;
   int n;
   if(!level_check(7)) return;
   if(!less_pts(STEALTHCOST)) return 1;
   room = 0;
   if(!str) return;
   dest = ENVTP->query_dest_dir();
   if(!dest) {
      write("Something inherent to the room stops you.\n");
      return 1;
   }
   while(n < sizeof(dest)) {
      if(str == dest[n]) {
         room = dest[n-1];
         break;
      }
      n+=1;
   }
   if(!room) {
      write("That is not a possible exit.\n");
      return 1;
   }
   peace_room(room);
   stealth_check("leaves"+str);
   move_object(TP, room);
   write("You fade into the shadows....");
   command("look", TP);
   stealth_check("enters");
   return 1;
}

peace_room(room) {
   object ob;
   ob = first_inventory(room);
   if(!ob) return 1;
   while(ob) {
      ob->set_aggressive(0);
      ob = next_inventory(ob);
   }
   return 1;
}

stealth_check(str) {
   object ob;
   int my_stealth;
   my_stealth = (TP->query_attrib("ste") + shlevel)/2 + random(10);
   ob = first_inventory(ENVTP);
   while(ob) {
       if((ob->is_player()&&ob->query_attrib("ste") > my_stealth&&
            ob!=TP)||ob->query_level()>19) {
         if(str == "enters") tell_object(ob, CN+" quietly materializes in"+
                   " the room from the shadows.\n");
            else tell_object(ob, CN+" quietly fades into the shadows "+
                    "and leaves.\n");
         if(ob->query_invis() < LEVEL) write(CAP(ob->query_name())+
                " saw you.\n");
      }
      ob = next_inventory(ob);
   }
   return 1;
}

follow_player(str) {
   object temp;
   if(!level_check(3)) return;
   if(!str) {
     write("Usage: 'follow <player name>'.\n");
      return 1;
   }
   if(str == "stop") {
      follow = 0;
      write("You are following no one.\n");
      return 1;
   }
   if(!present(str, ENVTP)) {
     write("The player must be present to follow them.\n");
      return 1;
   }
   temp = present(str, ENVTP);
   if(temp->query_level() > 19) {
      write("You may not follow wizards.\n");
      return 1;
   }
   if(!less_pts(FOLLOWCOST)) return 1;
   follow=temp;
   tell_object(temp, "You are being follow by "+CN+".\n");
   write("Now following "+CAP(temp->query_real_name())+".\n");
   return 1;
}

stop_follow() {
   if(!follow) {
      write("You are not following anyone.\n");
      return 1;
   }
   follow = 0;
   write("Follow is now OFF.\n");
   return 1;
}

calm_room() {
   object ob;
   int n;
   if(!level_check(5)) return;
   if(ENVTP->realm() == "NT") {
      wrie("Something in the room is blocking you!!!\n");
      return 1;
   }
   if(!less_pts(CALMCOST)) return 1;
   ob = first_inventory(ENVTP);
   while(ob) {
      if(ob->query_attack()) {
         (ob->query_attack())->stop_fight();
         ob->stop_fight();
      }
      ob = next_inventory(ob);
   }
   write("You raise your hands to stop all fighting in this room.\n");
   say(CN+" raises "+POS+" hands and stops all the fighting in the room.\n");
   ob = first_inventory(ENVTP);
   while(ob) {
      if(ob->is_living()) {
         ob->stop_fight();
      }
      ob = next_inventory(ob);
   }
   return 1;
}

peace_monster(str) {
   object monster;
   if(!str) return;
   if(!level_check(9)) return;
   monster = present(str, ENVTP);
   if(!monster) {
     write("Can't find a "+str+" here.\n");
      return 1;
   }
   if(ENVTP->realm()=="NT") {
      write("Something in the room is blocking you.\n");
      return 1;
   }
   if(!monster->query_aggressive()) {
      write("That monster isn't aggressive.\n");
      return 1;
   }
   if(!less_pts(PEACECOST)) return 1;
   monster->set_aggtressive(0);
   write(monster->short() +" is no longer aggressive.\n");
   return 1;
}


cure_me(str) {
   int num;
   if(!level_check(3)) return;
   if(!str) {
      write("Usage: 'cure <num>'.\n");
      return 1;
   }
   if(sscanf(str,"%d", num)!=1) {
      write("Usage: 'cure <num>'.\n");
      return 1;
   }
   if(num < 0) {
      write("YOU CANNOT HEAL NEGATIVE NUMBERS!!!\n");
      write_file(PATH+"logs/negative", CN +" tried to cure neg. points @ "+
         ctime(time())+".\n");
      return 1;
   }
   if((HP + num/2)> MHP) num = 2*(MHP-HP);
   if(!less_pts(num)) return 1;
   TP->add_hit_point(num/2);
   write("Done.\n");
   return 1;
}

 /*##            COMMANDER STUFF               ##*/

give_mark(str) {
   object per, mark;
   per = find_player(str);
   if(!per) {
      notify_fail("Cannot find '"+str+"'.\n");
      return 0;
   }
   if(present("shadow-mark", per)) {
      write("That person already has a mark.\n");
      return 1;
   }
   if(per->query_guild_name() == "shadow" && per->query_guild_exp() != "1234") {
      do_mark(per);
      return 1;
   }
   if(per->query_guild_exp()) {
      write("That person still has traces of a previous guild in their pla"+
         "yer file.\nHave them talk to Blue or mail Sandman.\n");
      return 1;
   }
   do_mark(per);
   return 1;
}

do_mark(per) {
   object mark;
   mark = clone_object(THIS_FILE);
   move_object(mark, per);
   mark->lost_mark();
   if(TP != per) {
      write(CAP(per->query_name()) +" now has a Mark of the Shadows.\n");
   }
   tell_object(per, "You now have a Mark of the Shadows.\n");
   write_file(PATH+"logs/mark",CN+" gave a mark to "+per->query_name()+
            " at "+ctime(time())+"\n\n");
   return 1;
}


commander_echo(str) {
   object *people;
   object mark;
   int n, size;
   n = 0;
   people = users();
   size = sizeof(people);
   while(n < size) {
       mark = present("shadow-mark", people[n]);
      if( mark && mark->query_shlevel() > 12)
         tell_object(people[n], str);
      n+=1;
   }
   return 1;
}

commander_talk(str) {
   if(!level_check(13)) return 1;
   if(!str) {
     write("Usage: 'ch <message>'.\n");
     return 1;
   }
   commander_echo("<c>"+CAP(TP->query_real_name())+"<>: "+str+".\n");
   return 1;
}

commander_emote(str) {
   if(!level_check(13)) return 1;
   if(!str) {
      write("Usage: 'ce <message>'.\n");
      return 1;
   }
    commander_echo("<c>"+CAP(TP->query_real_name())+" "+str+".\n");
   return 1;
}
promote_shadow(str) {
   object shadow_ob, player;
   int num;
   string per;
   if(sscanf(str, "%s %d", per, num) != 2) {
      write("Usage: promote <person> <levels>.\n");
      return 1;
   }
   player = find_player(per);
   if(!player) {
      write("Cannot locate "+per+".\n");
      return 1;
   }
   shadow_ob = present("shadow-mark", player);
   if(!shadow_ob) {
      write("That person is not a shadow.\n");
      return 1;
   }
   if(!shadow_ob->promote_me(num)) {
      write("You must promote between the levels of 1 and 12.\n");
      return 1;
   }
   write("Done.\n");
   if(num > 0)
   tell_object(environment(shadow_ob), "You have been "+
        "promoted by "+CN+".\n");
   if(num == 0)
      tell_object(player, "Your experience has been corrected.\n");
   write_file(PATH+"logs/promote",CN+" promoted "+
          CAP(player->query_name())+" "+num+"\("+
          shadow_ob->query_shlevel()+"\)\n");
   return 1;
}

remove_mark(str) {
   object shadow;
   if(!str) return 0;
   if(str == "guilds") {
      write("You fail to banish your leader.\n");
      write_file(PATH+"logs/revoke",CN+"attempted to revoke Blue at "+
           ctime(time())+"\n\n");
     return 1;
   }
   shadow = find_player(str);
   if(!shadow) {
      write("Cannot find "+str+" on the game.\n");
      return 1;
   }
  if(!present("shadow-mark",shadow)) {
      write("That player is not a shadow.\n");
      return 1;
   }
   present("shadow-mark", shadow)->end();
   write_file(PATH+"logs/revoke", CN+" revoked "+shadow->query_name()+" on "+
      ctime(time())+"\n\n");
   write("You revoked "+CAP(shadow->query_name())+" from the shadow guild.\n");
   return 1;
}

add_shadow_shxp(str) {
   int num, tmp_shxp;
   object player, mark;
   string who;
   if(!str) return 0;
   if(sscanf(str, "%s %d", who, num)!=2) {
      write("Usage: '<>addshxp <number>'.\n");
      return 1;
   }
   player = find_player(who);
   if(!player) {
      write("That player is not on the game.\n");
      return 1;
   }
   mark = present("shadow-mark", player);
   if(!mark) {
      write("That player is not a shadow.\n");
      return 1;
   }
   write(CAP(player->query_name()) +"'s shadow experience being changed.\n");
   tmp_shxp = mark->query_shadow_xp();
   write("Old shxp: "+tmp_shxp+"\n");
   mark->add_shxp_me(num); 
   write("New shxp: "+mark->query_shadow_xp() +"\n");
   write_file(PATH+"logs/add_shxp",CN+" added "+num+" to "+
            CAP(player->query_name())+" on "+ctime(time())+"\n"+
            "      "+tmp_shxp+" to "+ player->query_shadow_shxp()+"\n");
   write("Please mail Blue explaining the situation.....\n");
   return 1;
}

commander_who() {
   object *pepl, mark;
   int i, n;
   n = 0;
   pepl = users();
   write("<>Commander who....<>\n");
   write("Name\t\Shadow-level/Level\tShadow-xp\n");
   write("--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--\n");
   while(n < sizeof(pepl)) {
      mark = present("shadow-mark", pepl[n]);
       if( mark &&  !(pepl[n]->query_invis()&&
                    pepl[n]->query_level() > LEVEL)) {
         write(CAP(pepl[n]->query_name()));
      if(strlen(pepl[n]->query_name()) < 8) write("\t");
         write("\t"+mark->query_shlevel()+"/"+pepl[n]->query_level());
      write("\t"+mark->query_shadow_xp());
       i += 1;  
      }
      n += 1;
   }
   write("--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--\n");
   write(i+" shadows logged on.\n");
   return 1;
}


scan_monster(str) {
   object monster;
   int tmp_hp, tmp_mhp;
   if(!level_check(4)) return 1;
   if(!str) {
      write("Usage: 'scan <monster>'.\n");
      return 1;
   }
   monster = present(str, environment(this_player()));
   if(!monster) {
      write("That is not here!\n");
      return 1;
   }
   if(!living(monster)) {
      write("That is not alive.\n");
      return 1;
   }
   tmp_hp = monster->query_hp();
   tmp_mhp = monster->query_mhp();
   if(!less_pts(SCANCOST)) return 1;
   write(monster->short() +" is at "+(tmp_hp * 100)/tmp_mhp +"% hit points.\n");
   return 1;
}

do_command(str) {
   string com_;
   int number;
   if(!str) return;
   if(sscanf(str, "%s %d", com_, number)!= 2) {
      write("Usage: 'do <command> <number of times>'.\n");
      return 1;
   }
   if(number > 10) {
      write("The number cannot be greater than 10.\n");
      return 1;
   }
   while(number > 0) {
      command(com_, TP);
      number -= 1;
   }
   return 1;
}

get_time() {
   call_other("/room/church.c","look","clock");
   return 1;
}
