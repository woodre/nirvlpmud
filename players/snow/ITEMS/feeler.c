#define TP capitalize(this_player()->query_name())
#define tp this_player()
#define FEEL present("feeler", tp)
#include "/players/snow/closed/cyber/color.h"

id(str) { return str == "discreet emoter" || str == "feeler"; }
short() { return "A Discreet Emoter (Feeler)"; }
 
long() { write(
"***********************************************************************\n"+
  "This allows you to do an emote to a certain, special person.\n"+
  "For help with this object, type 'feelerhelp'.\n"+
  "*NEW* You can now follow people inside Zeus's special areas\n"+
  "with this device. 'feelfollow <who>' *NEW*\n"+
  "Any problems or suggestions mail Snow.\n"+
 
"***********************************************************************\n");
return 1;  }
 
emote_to(str)
{
       object ob;
       string who;
       string msg;
   if (!str || sscanf(str, "%s %s", who, msg) != 2) {
       write("Emote what ?\n");
        return 1;
}
ob = present(who,environment(tp));
  if (!ob) {
      write("That player is not in the room.\n");
       return 1;
}
if(ob->query_invis() > 19) {
  write("That player is not in the room.\n");
return 1;
   }
if(in_editor(ob)) {
  write(capitalize(who)+" is in editing right now, try again later.\n");
return 1;
   }
  if(ob->query_tellblock()) {
  write(capitalize(who)+" is blocking tells right now.\n");
return 1; }
tell_object(ob,"(Discreet) "+TP+" "+msg+ "\n");
write ("You secretly emote: '"+TP+" "+msg+"' to "+capitalize(who)+".\n");
return 1;
}
 
far_emote(str)  {
       object ob;
       string who;
       string msg;
   if (!str || sscanf(str, "%s %s", who, msg) != 2) {
       write("Emote what ?\n");
        return 1;
}
  if(this_player()->query_invis()) {
    write("Your invisible emotes go unnoticed.\n"); return 1; }
ob = find_living(lower_case(who));
  if (!ob) {
      write("That player is not on Nirvana.\n");
       return 1;
  }
if(ob->query_invis() > 19) {
  write("That player is not on Nirvana.\n");
return 1;
   }
if(present(who,environment(tp))) {
  write("That player is in the same room as you are... use 'emto'.\n");
return 1;
  }
if(in_editor(ob)) {
  write(capitalize(who)+" is in editing right now, try again later.\n");
return 1;
   }
if(this_player()->query_sp() < 0) { 
   write("You are too weak for that.\n");
   return 1;
}
  if(ob->query_tellblock()) {
  write(capitalize(who)+" is blocking tells right now.\n");
return 1; }
call_other(this_player(),"add_spell_point",-(random(4)+2));
tell_object(ob,"(FarEmote) "+TP+" "+msg+ "\n");
write ("You emote from afar: '"+TP+" "+msg+"' to "+capitalize(who)+".\n");
return 1;
}

feelfollow(string str) {
  object ob, envob;
  string maker;
  if(!str) { 
    if(objectp(FEEL->query_feelfollow())) {
      tell_object(FEEL->query_feelfollow(), (string)this_player()->query_name() + " is no longer feelfollowing you.\n");
      FEEL->set_feelfollow(0);
      write("Feelfollow turned off.\n");
      return 1; }
  else write("Feelfollow who?\n"); return 1; }
  ob = present(str, environment(this_player()));
  if(!ob) { write("No "+str+" here.\n"); return 1; }
  envob = environment(ob);
  if(ob->query_level() > 19) {
    write("You cannot follow such a godly being...\n");
    return 1; }
  maker = creator(envob);
  if(this_player()->query_real_name() == "snow") {
    write("Realm: "+maker+"\n"); }
  if(maker != "snow" && maker != "zeus") {
    write("You can't use this here.\n"); return 1; }
  FEEL->set_feelfollow(ob->query_real_name());
  FEEL->start_feelfollow();
  write("You will now follow "+str+" around "+capitalize(maker)+"'s realms.\n");
    /* Aug 2 2000 : Added by Verte */
  tell_object(ob, (string)this_player()->query_name() + " is now feelfollowing you.\n");
  return 1; }

dest_feel() {
object ob;
  write("You rid yourself of the feeler.\n");
ob = present("discreet emoter",tp);
destruct(ob);
return 1;
}
 
give_feeler(str) {
  object ob;
  if(!str) return (notify_fail("Feelto who?\n"), 0);
ob = find_living(lower_case(str));
  if(!ob) { write("That player is not on Nirvana at this time.\n");
              return 1;
             }
  if(ob->query_invis()) {
        write("That player is not on Nirvana at this time.\n");
    return 1; }
  if(ob->query_level() > 20) {
    write("You cannot give the Discreet Emoter to a wizard.\n");
return 1;
   }
  if(present("discreet emoter",ob)) {
    write("That player already has a Feeler!\n");
return 1;
  }
move_object(clone_object("/players/snow/ITEMS/dfeeler.c"),ob);
tell_object(ob,"You have just been awarded a Discreet Emoter!\n");
write("You have given "+capitalize(str)+" a Discreet Emoter!\n");
return 1;
}
 
feeler_users()  {
int b;
object ob;
object ob2;
ob = sort_list(users());
 
write("\n");
write("_______________________________________________________________________\n");
write("  Name           Level    Gender\n");
write("_______________________________________________________________________\n");
 
  for(b=0;b<sizeof(ob);b+=1)  {
  if(ob[b]->query_invis() == 0)  {
  if(present("discreet emoter",ob[b]))  {
write("  ");
write(pad(ob[b]->query_name(),15));
write(pad(ob[b]->query_level(),9));
write(pad(ob[b]->query_gender(),9));
write("\n");
      }
    }
  }
write("_______________________________________________________________________\n");
write("\n");
return 1;
}
 
 
sort_list(str)  {
int i,j,k;
object tmp;
  j = sizeof(str) - 1;
  for(i=0;i<j;i++)  {
   for(k=0;k<j;k++)  {
    if(str[i]->query_level() < str[i+1]->query_level())  {
     tmp=str[i];str[i]=str[i+1];str[i+1]=tmp;
  }  }  }
 return str;
   }

feeler_say(str) {
/* Feeler channel for Snow */
   object everyone, member;
   int i;
   if(!str) {
      write("Usage: feelsay <message>.\n");
      return;}
   everyone = users();
   for(i = 0; i < sizeof(everyone); i++) {
      member = present("feeler",everyone[i]);
      if(member) {
        tell_object(everyone[i],
    GREEN+"~~~"+END+" "+BOLD+str+END+"\n");
        }
      }
   return 1;
}
feeler_help() {
write(
"**********************************************************************\n");
write(
"These are the powers of the Discreet Emoter:\n"+
"\n"+
"'emto <person> <emote>' -Emotes to a player in the same room.\n"+
"'farem <person> <emote>' -Emotes to a player in a different room.\n"+
"                          (costs 2-5 spell points per use) \n"+
"'feelwho' -Shows the users who currently have a Discreet Emoter.\n"+
"'feelfollow <player>' -Follow a player inside Snow's realms\n"+
"'fglow'       - Light your feeler for 100 sp. \n"+
"'feelto' -Gives a player a Discreet Emoter.\n"+
"'no_feeler' -Destroys your Discreet Emoter.\n"+
"\n"+
"Try 'emto' on yourself to get some practice. Then have some fun!\n");
write(
"**********************************************************************\n");
return 1;
}
 
