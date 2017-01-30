
#define notify_fail(A) write(A+"\n"); return 1;

inherit "/room/room";

string name, hitlist;
int level, num_members, *bounties, logon;

justify(str, len){ return extract(str+"                           ",0,len-1); }

reset(arg){
   short_desc = "Bounty Hunters' Guild";
   long_desc =
   "The subdued room has small groups of bounty hunters gathered around\n"+
   "tables telling tall tales about their adventures.\n";
   items = ({ "frog", "A green frog" });
   dest_dir = ({ "room/church", "south" });
   set_light(1);
   hitlist = ({ });  bounties = ({ });
}

init(){
   add_action("start_mark", "bounty");
   add_action("hitlist", "hitlist");
   add_action("delete", "delete");
   ::init();
}

string whostr, amt;

start_mark(){
   write("Welcome to the Bounty Poster.\n");
   write("Whom would you like to post a bounty on? ");
   input_to("start_mark2");
   return 1;
}

start_mark2(str){
   object who;
   if(!str){ notify_fail("Ok, no bounty for now."); }
   whostr = str;
   who = find_player(str);
   if(!who){
      write("That player is not logged on.  Do you want to add to the bounty?[y/n] ");
      input_to("choose_bounty");
      return 1;
   }
   logon = 1;
   if(who->query_level() > 19){  whostr = 0;
      notify_fail("Kill a wizard.  Yeah, right."); }
   write("Ok, how much bounty will you post for "+capitalize(str)+"? ");
   input_to("add_bounty");
   return 1;
}

choose_bounty(str){
   if(str == "y" || str == "yes"){
      write("Ok, how much bounty will you post for "+capitalize(whostr)+"? ");
      input_to("add_bounty");
      return 1;
   }
   else {
      whostr = 0; logon = 0;
      return 1;
   }
}

add_bounty(str){
   object who;
   int ret;
   if(!str){ whostr = 0; logon = 0; return 1; }
   if(!sscanf(str, "%d", amt) == 1){ whostr = 0; amt=0; logon=0; return 1; }
   if(!amt || amt < 1){ whostr = 0; amt = 0; logon=0;
      notify_fail("We don't accept Monopoly money."); }
   who = find_player(whostr);
   if(!who && logon){ whostr = 0; amt = 0; logon = 0;
      notify_fail("Sorry, your target just quit.  Cannot continue.\n"); }
   ret = add_hitlist(whostr, amt);
   if(ret == -1){ whostr = 0; amt = 0; logon =0;
      notify_fail("No one by that name has ever visited Nirvana."); }
   if(ret == -2){ whostr = 0; amt = 0; logon=0;
      notify_fail("You really want that wizard dead, don't you?"); }
   else {
      write("Ok: "+capitalize(whostr)+", "+amt+".  Have a nice day.\n");
      if(logon){
         if(!present("deathscalp", who)){
            object scalp;
            scalp = clone_object("players/deathmonger/ASSASSIN/scalp");
            scalp->set_who(whostr);
            move_object(scalp, who);
            tell_object(who, "You have just been marked for death.\n");
         }
      }
   }
   whostr = 0;logon = 0;
   amt = 0;
   return 1;
}

add_hitlist(string str, int stf){
   /* if you don't understand this, go out and shoot someone */
      /* That's what I did. */
   int i, j, tmp;
   string temp;
   name = 0; level = 0;
   restore_object("players/deathmonger/ASSASSIN/hitlist");
   if(!hitlist || member_array(str, hitlist) == -1){
      /* a new member! */
      restore_object("players/"+str);
      if(!name){
         return -1;
      }
      if(level > 19) return -2;
      hitlist += ({ str });
      bounties += ({ stf });
      num_members++;
   }
   else {
      /* old member, add to their bounty */
      for(i=0; i < sizeof(hitlist); i++) if(hitlist[i] == str) break;
      write("\ni is: "+i+"\n");
      bounties[i] += stf;
   }
   /* sort by total bounty. I'll use an evil bubble sort */
   for(i=1; i < sizeof(bounties); i++){
      for(j=sizeof(bounties)-1; j >= i; j--){
         if(bounties[j-1] < bounties[j]){
            tmp = bounties[j-1];
            temp = hitlist[j-1];
            bounties[j-1] = bounties[j];
            hitlist[j-1] = hitlist[j];
            bounties[j] = tmp;
            hitlist[j] = temp;
          }
       }
   }
   save_object("players/deathmonger/hitlist");
   return 1;
}

delete(str){
   int ret;
   ret = remove_hitlist(str);
   if(ret == -1){ notify_fail(capitalize(str)+" is not on the hitlist."); }
   else {
      write("You delete "+capitalize(str)+" from the hitlist.\n");
   }
   return 1;
}

remove_hitlist(str){
   string templist;
   int i;
   restore_object("players/deathmonger/hitlist");
   if(!member_array(str, hitlist)) return -1;
   hitlist = filter_array(hitlist, "removal", this_object(), str);
   save_object("players/deathmonger/hitlist");
   return 1;
}

removal(n, str){
   if(n != str) return 1;
   else {
      int i;
      for(i=0; i < sizeof(hitlist); i++) if(hitlist[i] == str) break;
      bounties = filter_array(bounties, "removal2", this_object(), i);
      return 0;
   }
}

removal2(int bounty, int index){
   if(bounty == bounties[index]) return 0;
   else return 1;
}

hitlist(){
   int i, halfway, is_odd;
   if(!hitlist) return -1;
   restore_object("players/deathmonger/hitlist");
   write("----------=========] Hitlist for "+
      ctime(time())+"[=========-----------\n");
   halfway = sizeof(hitlist)/2;
   if(sizeof(hitlist) > halfway*2) is_odd = 1;
   write("Name:         Bounty:     Name:         Bounty:\n");
   for(i=0;i < halfway;i++){
      write(justify(capitalize(hitlist[i]), 14)+justify(bounties[i], 12)+
            justify(capitalize(hitlist[halfway+i]), 14)+
            justify(bounties[halfway+i], 8)+
            "\n");
   }
   if(is_odd){
      write("                          "+
         justify(capitalize(hitlist[sizeof(hitlist)-1]), 14)+
            justify(bounties[sizeof(hitlist)-1], 12)+
            "\n");
   }
   return 1;
}

