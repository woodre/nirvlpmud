#ifndef ESC
#include <ansi.h>
#endif
/* Original code by Bastion (Bastian)
 * Modified by Wizardchild
 * and later by Feldegast
 * fake finger added by wocket
 * New attrib changes by Illarion on 10/30/02
 * New level presentation by Boltar 11/13/02
 * job titles verte 05
 * Adding levels back in - Rumplemintz
 */

#include "security.h"
#include "/obj/play/paths.h"

#define P(x) pad(x, -5)
 
string hostname, home, a, b;
string auto_load;
string old_last;
string name, called_from_ip, title, al_title, guild_name, mailaddr;
string clan_name;
string pretitle, lastime, cap_name;
int no_give, level, ex_lv, age;
int security_level;
int experience, money;
int strength, intelligence, stamina, will_power, piety, stealth, magic_aptitude;
int luck, charisma, dexterity;
int tlvl, player_killing;
int guild_rank, guild_exp;
string guild_file;
status privs;
string *FAKERS;
int i;

int display_age();
int print_stats();

int rfinger(string str) {
  string ownerNm;
  object who;

  if(str=="batarsis" || str=="Batarsis") {
    write("Batarsis the Bad (evil)\n");
    write("Level:          19+4 (23)\n");
    write("Guild name:     none\n");
    write("Clan name:      none\n");
    write("Player killer:   Yes\n");
    write("Last called at: ");
    if (find_living("batarsis")) write("Not logged off.\n");
    else write("Unknown\n");
    write("Age: "+(random(20)+8)+" days "+random(25)+" hours "+random(60)+
          " minutes "+random(60)+" seconds.\n");
    return 1;
  }
  old_last = name = called_from_ip = level = ex_lv = title = mailaddr = 0;
  guild_name = lastime = age = cap_name = al_title = clan_name = 0;

  if (!str) {
    write("You must enter a player's name.\n");
    return 1;
  }

  if (!restore_object("pfiles/" + str[0..0] + "/" + lower_case(str))) {  
    if (restore_object("players/inactive_saved/" + lower_case(str))) {
      write(BOLD + "------------" + HIW + "INACTIVE" + NORM + BOLD +
            "------------" + HIW + "INACTIVE" + NORM + BOLD +
            "------------\n" + NORM);
      write(BOLD + "-----" + NORM + "Reactivation possible after: " + HIW +
            ctime(no_give + 1296000) + NORM + "\n");
      write(BOLD + "----------------------------------------------------" +
            NORM + "\n");
    }
    if (restore_object("banish/" + lower_case(str))) {
      if (file_size("/banish/" + lower_case(str)) < 25) {
        FAKERS = ({ "sagan", "shardak", "gorhurtrix" });
        if (member(FAKERS, str) != -1) {
          cat("/open/fakefin/" + str + ".fin");
          return 1;
        }
      }
      return (write("That name is banished!\n"), 1);
    }
  }
  if (home && sscanf(home, "%spriso%s", a, b) ==2) 
    write(BOLD + "------------" + HIW + "PRISON" + NORM + BOLD +
          "--------------" + HIW + "PRISON" + NORM + BOLD +
          "------------" + NORM + "\n");
  if (level >= 21) {
    write(GRN + "____________________________________________________" + NORM +
          "\n");
    write(HIW + "         Nirvana Development Team Member" + NORM + "\n");
    write(GRN + "____________________________________________________" + NORM +
          "\n");
  }
  if (ownerNm = (string)TESTCHAR_D->query_owner(name)) {
    write(BOLD + "--------" + NORM + HIW + "TEST CHARACTER" + NORM + BOLD +
          "------" + HIW + "TEST CHARACTER" + NORM + BOLD + "--------" + NORM +
          "\n");
    write("           " + BOLD + "--" + NORM + " Property of " + HIW +
          upper_case(ownerNm) + " " + NORM + BOLD + "--" + NORM + "\n");
    write(BOLD + "--------------------------------------------------" + NORM +
          "\n");
  }

  if (!name) {
    write("No such player exists.\n");
    return 1;
  }

  privs = (int)this_player()->query_security_level();
  print_stats();
  if ((int)this_player()->query_security_level() < 6) {
    called_from_ip = hostname = "???";
  }
  return 1;
}
 
int print_stats() {
  string header;
  object bb;
  string pname;

  if (level == 20) {
    title="";
    if (pretitle) {
      pretitle="";
    }
  }
  header = (capitalize(name) + " " + title + NORM + " " +
           (security_level < 1 ? "" : "(" + al_title + ") "));
  if (pretitle)
    header = (pretitle + NORM + " " + capitalize(name) + " " + title + NORM +
             " " + (security_level < 1 ? "" : "(" + al_title + ") "));
  if (player_killing && !security_level)
    header = HIR + "[PK]" + NORM + " " + header;
  write(header + "\n");
  if(!security_level) {
    tlvl = level + ex_lv;
    write("Level: " + pad(level + (ex_lv ? "+" + ex_lv : ""), -9) +
          (ex_lv ? " (" + tlvl + ")" : "") + "\n");
    if (privs) {
      write("Experience:" + pad(experience, -9) +
            "  Money:" + pad(money, -14) + "\n");
    }
  }
  else {
    write("Role:  ");
    if (name=="illarion") {
      write(YEL + "Code Monkey\n" + NORM);
    }
    else if (name=="rumplemintz") {
      write(GRN + "LibShaker\n" + NORM);
    }
    else if(level == 90) {
      write(RED + "Inactive Administrator [90]\n" + NORM);
    }
    else if (security_level >= 10) {
      write(GRN + "Administrator [" + level + "]\n" + NORM);
    }
    else if(security_level >= 3) {
      write(GRN + "Developer [" + level + "]\n" + NORM);
    }
    else if(security_level == 1) {
      write(GRN + "Apprentice Developer [21]\n" + NORM);
    }
    else if(level == 20) {
      write(RED + "Inactive Developer [20]\n" + NORM);
    }
  }
  if (!guild_name) guild_name = "none";
  guild_name = lower_case(guild_name);
  guild_name = capitalize(guild_name);
  if (strlen(guild_name) > 8) write("Guild name:  " + guild_name + "\n");
  else write("Guild name: " + pad(guild_name, -8) + "\n");
  write("Clan name:    " + (clan_name ? capitalize(clan_name) : "none") + "\n");
  if (privs && !security_level) {
    write("Guild Rank:" + pad(guild_rank, -9) + "  Guild Exp:" +
          pad(guild_exp, -10) + "\n");
    write("Attributes:\n");
    write("Mag:" + P(magic_aptitude) + "  Sta:"+ P(stamina) +
          "  Str:" + P(strength) + "  Ste:" + P(stealth) +
          "  Dex:" + P(dexterity) + "\n" + "Int:" + P(intelligence) +
          "  Wil:" + P(will_power) + "  Pie:" + P(piety) + "  Luc:" + P(luck) +
          "  Cha:" + P(charisma) + "\n");
  }
  if (privs) {
    if (!mailaddr) mailaddr = "none";
      write("E-mail address: " + mailaddr + "\n"); 
    if ((int)this_player()->query_level() < 60)
      called_from_ip=hostname = "???";
    write("Last called from: " + hostname + " " + 
          ((hostname != called_from_ip) ? "(" + called_from_ip + ")" : "") +
          "\n");
  }
  bb = find_player(name);
  if ((bb && !bb->query_invis()) ||
      (bb && bb->query_invis() && bb->query_level() <
                                  this_player()->query_level())) {
    string vTest, vTest2;

    if (sscanf((string)bb->query_lastime(), "%s to %s", vTest, vTest2) == 2)
      write("Not logged off.\n");
    write("Logged on since: " + (string)bb->query_lastime() + ".\n");
  }
  else if (bb && bb->query_lastime())
    write("Last called at: " + bb->query_lastime() + "\n");
  else if (security_level && old_last)
    write("Last called at: " + old_last + "\n");
  else write("Last called at: " + lastime + "\n");
  display_age();

  if (valid_wizard(name)) {
    string *tc;

    if ((tc = (string*)TESTCHAR_D->query_testchars(name)) && sizeof(tc)) {
      int ca, cb;

      cb = sizeof(tc);
      write("Test Character" + (cb > 1 ? "s" : "") +": ");
      for (ca = 0; ca < (cb-1); ca ++)
        write(capitalize(tc[ca]) + ", ");
      write(capitalize(tc[cb-1]) + ".\n");
    }
  }
  pname = "/players/" + lower_case(name) + "/PLAN";
  if(security_level && this_player()->query_security_level() &&
     file_size(pname) >-1) {
    write("Plan:\n");
    cat(pname);
  }
  if ((int)this_player()->query_security_level() < 1) {
    if (file_size("/open/pub_plans/" + name + ".plan") > 0) write("Plan:\n");
    cat("/open/pub_plans/" + name + ".plan");
    return 1;
  }
  return 1;
}
 
int display_age() {
  int i;

  write("Age: ");
  i = age;
  if (i/43200) {
    write(i/43200 + " days ");
    i = i - (i/43200) * 43200;
  }
  if (i/1800) {
    write(i/1800 + " hours ");
    i = i - (i/1800) * 1800;
  }
  if (i/30) {
    write(i/30 + " minutes ");
    i = i - (i/30) * 30;
  }
  write(i*2 + " seconds.\n");
}

