	/* modified wiz_tool */

#define tp this_player()
#define tl tp->query_level()
#define tpn tp->query_real_name()
#define master "/obj/wiz_tool_master.c"
#define to this_object()
#define ep environment(to)
#define eep environment(ep)

id(str) { return str == "charisma" || str == "tool" || str == "wiztool" || str == "aura" || str == "dark_sight_object";}



   short() { return capitalize(ep->query_real_name())+"'s "+
          "charismatic aura"; }

   long() {write("gname(str)      : to reset guild name on player to nothing \n"+
                 "smeg            : yell Smeg off   test                     \n"+
                 "bop (str)       : unset guild status on testers            \n"+
                 "                        \n");

}  
drop() { destruct(to); return 1; }
get() { if(tl > 20) return 1;  else destruct(to); return 1;}


init() {
 

add_action("gname","gname");
add_action("smeg","smeg");
add_action("bop","bop");
}


gname(str) {
string who;
string what;
  if(!str) { return 0;}
  if(sscanf(str,"%s %s",who,what) != 2){ return 0;} 
  if(!find_player(who)) { write("Target is not in play.\n"); return 1; }
  find_player(who)->set_guild_name(what);
  write("You have set "+who+"'s guild name to "+what+"\n");
return 1; }


smeg() {
  write("You yell 'SMEG OFF' at the top of your lungs\n");
  return 1;

}

bop(str) {
  string who;
  if(!str) {return 0;}
  if(sscanf(str,"%s",who) != 1){ return 0;} 
  if(!find_player(who)) {write("Target is not in play.\n"); return 1;}
  find_player(who)->set_guild_name(0);
  find_player(who)->set_guild_file(0);
  write("You have removed "+who+" from the guild.\n");
  return 1;
  }








/*
*
g_name(str) { 
     exec write(find_player("bait")->set_guild("0")); 
    return 1; 
            }

exec write(find_player("blah")->set_guild("0")); 
*
*/

