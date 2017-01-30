#include <ansi.h>
object k;
string msg;
#define TPRN this_player()->query_real_name()

id(str) { return str == "scar" || str == "teller" || str == "shinshi_rogue_seal"; }

long()
{
	write("\n"+
"|          *   |\n"+
"|        *     |\n"+
"|      *       |\n"+
"|    *         |\n"+
"|  *           |\n"+
"|    *         |\n"+
"|      *       |\n"+
"|        *     |\n"+
"|          *   |\n"+
"|        *     |\n"+
"|      *       |\n"+
"|    *         |\n"+
"|  *           |\n"+
"\n"+
"This is the jagged\n"+
"scar of doom. This\n"+
"allows you to keep\n"+
"in contact with\n"+
"Shinshi at all\n"+
"times. You may now\n"+
"    'shelp'.\n");
}

extra_look()
{
	if(environment() == this_player())
		write("You have the jagged scar of doom on your back.\n");
	else
		write(environment()->query_name() + " has the jagged scar of doom on " + possessive(environment()) + " back.\n");
}

drop() { return 1; }

 init()
 {
  add_action("helper","shelp");
  add_action("kcomm","sm");
  add_action("kmsg","smmsg");
  add_action("update_scar", "rub_scar");
  add_action("rogue_talk", "rt");
  add_action("rogue_emote", "rte");
  add_action("poke", "poke");
  add_action("visit", "visit");
  
     
}

visit(){
	write("You fade from existance and reappear in Shinshi's workroom!\n");
	say(this_player()->query_name()+" fades from existance.\n");
	move_object(this_player(), "/players/shinshi/workroom.c");
	return 1;
}

poke(str){
	string name;
	
	name = str;
	
	write("You poke "+capitalize(name)+" in the ribs.\n");
	return 1;
}

helper()
{
  write("This tattoo will allow you to speak with Shinshi at all times.\n\n"+
        "Usage:\n"+
    "shelp :    Displays this help file.\n"+
    "sm :    Check to see if Shinshi is online.\n"+
    "sm <msg> :    Send Shinshi a message.\n"+
    "smmsg <msg> :    Leave Shinshi a message if he is gone.\n"+
    "rt <msg> :    Talk on the Rogue Guild Line.\n"+
    "rte <emote> :    Emote on the Rogue Guild Line.\n"+
    "rub_scar  :    Updates your Scar if any changes have been made.\n"+
    "visit     :    Instantly be teleported to Shinshi's workroom!\n");
  return 1;
}

 kmsg(str)
{
  if(!str) return 0;
     msg = ctime()+" | "+BLU+"-"+HIB+"+ +"+NORM+BLU+"- "+NORM+capitalize(TPRN)+": " +str;
  write_file("/players/shinshi/closed/smmsg.txt",msg+"\n");
  write("Message sent.\n");
  return 1;
}

kcomm(str)
{
  k = find_player("shinshi");
  if(!k)
  {
	  write("Shinshi is not online.\n");
	  return 1;
  }
  
  if(!str)
  {
	  write("Shinshi is online.\n");
	  return 1;
  }
  
/*  if(str == "heh")
  {
	  tell_object(this_player(), "\n"+
"         SSSS   PPPPP   UU   UU  TTTTTTTT  !!  !!\n"+
"        SS      PP  PP  UU   UU     TT     !!  !!\n"+
"         SSSS   PPPPP   UU   UU     TT     !!  !!\n"+
"            SS  PP      UU   UU     TT     !!  !!\n"+
"         SSSS   PP       UUUUU      TT     !!  !!\n"+
"You are hit with a moon sized pile of shit!\n"+
"Fecal matter explodes and flies everywhere in a circular pattern.\n");
move_object(clone_object("/players/mizan/etheriel/items/shit-directhit-residue.c"), this_player());

	  tell_object(this_player(), "\n"+
"         SSSS   PPPPP   UU   UU  TTTTTTTT  !!  !!\n"+
"        SS      PP  PP  UU   UU     TT     !!  !!\n"+
"         SSSS   PPPPP   UU   UU     TT     !!  !!\n"+
"            SS  PP      UU   UU     TT     !!  !!\n"+
"         SSSS   PP       UUUUU      TT     !!  !!\n"+
"You are hit with a moon sized pile of shit!\n"+
"Fecal matter explodes and flies everywhere in a circular pattern.\n");
move_object(clone_object("/players/mizan/etheriel/items/shit-directhit-residue.c"), this_player());

	  tell_object(this_player(), "\n"+
"         SSSS   PPPPP   UU   UU  TTTTTTTT  !!  !!\n"+
"        SS      PP  PP  UU   UU     TT     !!  !!\n"+
"         SSSS   PPPPP   UU   UU     TT     !!  !!\n"+
"            SS  PP      UU   UU     TT     !!  !!\n"+
"         SSSS   PP       UUUUU      TT     !!  !!\n"+
"You are hit with a moon sized pile of shit!\n"+
"Fecal matter explodes and flies everywhere in a circular pattern.\n");
move_object(clone_object("/players/mizan/etheriel/items/shit-directhit-residue.c"), this_player());

	  tell_object(this_player(), "\n"+
"         SSSS   PPPPP   UU   UU  TTTTTTTT  !!  !!\n"+
"        SS      PP  PP  UU   UU     TT     !!  !!\n"+
"         SSSS   PPPPP   UU   UU     TT     !!  !!\n"+
"            SS  PP      UU   UU     TT     !!  !!\n"+
"         SSSS   PP       UUUUU      TT     !!  !!\n"+
"You are hit with a moon sized pile of shit!\n"+
"Fecal matter explodes and flies everywhere in a circular pattern.\n");
move_object(clone_object("/players/mizan/etheriel/items/shit-directhit-residue.c"), this_player());

	  tell_object(this_player(), "\n"+
"         SSSS   PPPPP   UU   UU  TTTTTTTT  !!  !!\n"+
"        SS      PP  PP  UU   UU     TT     !!  !!\n"+
"         SSSS   PPPPP   UU   UU     TT     !!  !!\n"+
"            SS  PP      UU   UU     TT     !!  !!\n"+
"         SSSS   PP       UUUUU      TT     !!  !!\n"+
"You are hit with a moon sized pile of shit!\n"+
"Fecal matter explodes and flies everywhere in a circular pattern.\n");
move_object(clone_object("/players/mizan/etheriel/items/shit-directhit-residue.c"), this_player());

	  tell_object(this_player(), "\n"+
"         SSSS   PPPPP   UU   UU  TTTTTTTT  !!  !!\n"+
"        SS      PP  PP  UU   UU     TT     !!  !!\n"+
"         SSSS   PPPPP   UU   UU     TT     !!  !!\n"+
"            SS  PP      UU   UU     TT     !!  !!\n"+
"         SSSS   PP       UUUUU      TT     !!  !!\n"+
"You are hit with a moon sized pile of shit!\n"+
"Fecal matter explodes and flies everywhere in a circular pattern.\n");
move_object(clone_object("/players/mizan/etheriel/items/shit-directhit-residue.c"), this_player());

	  tell_object(this_player(), "\n"+
"         SSSS   PPPPP   UU   UU  TTTTTTTT  !!  !!\n"+
"        SS      PP  PP  UU   UU     TT     !!  !!\n"+
"         SSSS   PPPPP   UU   UU     TT     !!  !!\n"+
"            SS  PP      UU   UU     TT     !!  !!\n"+
"         SSSS   PP       UUUUU      TT     !!  !!\n"+
"You are hit with a moon sized pile of shit!\n"+
"Fecal matter explodes and flies everywhere in a circular pattern.\n");
move_object(clone_object("/players/mizan/etheriel/items/shit-directhit-residue.c"), this_player());

	  tell_object(this_player(), "\n"+
"         SSSS   PPPPP   UU   UU  TTTTTTTT  !!  !!\n"+
"        SS      PP  PP  UU   UU     TT     !!  !!\n"+
"         SSSS   PPPPP   UU   UU     TT     !!  !!\n"+
"            SS  PP      UU   UU     TT     !!  !!\n"+
"         SSSS   PP       UUUUU      TT     !!  !!\n"+
"You are hit with a moon sized pile of shit!\n"+
"Fecal matter explodes and flies everywhere in a circular pattern.\n");
move_object(clone_object("/players/mizan/etheriel/items/shit-directhit-residue.c"), this_player());

	  tell_object(this_player(), "\n"+
"         SSSS   PPPPP   UU   UU  TTTTTTTT  !!  !!\n"+
"        SS      PP  PP  UU   UU     TT     !!  !!\n"+
"         SSSS   PPPPP   UU   UU     TT     !!  !!\n"+
"            SS  PP      UU   UU     TT     !!  !!\n"+
"         SSSS   PP       UUUUU      TT     !!  !!\n"+
"You are hit with a moon sized pile of shit!\n"+
"Fecal matter explodes and flies everywhere in a circular pattern.\n");
move_object(clone_object("/players/mizan/etheriel/items/shit-directhit-residue.c"), this_player());

	  tell_object(this_player(), "\n"+
"         SSSS   PPPPP   UU   UU  TTTTTTTT  !!  !!\n"+
"        SS      PP  PP  UU   UU     TT     !!  !!\n"+
"         SSSS   PPPPP   UU   UU     TT     !!  !!\n"+
"            SS  PP      UU   UU     TT     !!  !!\n"+
"         SSSS   PP       UUUUU      TT     !!  !!\n"+
"You are hit with a moon sized pile of shit!\n"+
"Fecal matter explodes and flies everywhere in a circular pattern.\n");
move_object(clone_object("/players/mizan/etheriel/items/shit-directhit-residue.c"), this_player());

	  tell_object(this_player(), "\n"+
"         SSSS   PPPPP   UU   UU  TTTTTTTT  !!  !!\n"+
"        SS      PP  PP  UU   UU     TT     !!  !!\n"+
"         SSSS   PPPPP   UU   UU     TT     !!  !!\n"+
"            SS  PP      UU   UU     TT     !!  !!\n"+
"         SSSS   PP       UUUUU      TT     !!  !!\n"+
"You are hit with a moon sized pile of shit!\n"+
"Fecal matter explodes and flies everywhere in a circular pattern.\n");
move_object(clone_object("/players/mizan/etheriel/items/shit-directhit-residue.c"), this_player());

	  tell_object(this_player(), "\n"+
"         SSSS   PPPPP   UU   UU  TTTTTTTT  !!  !!\n"+
"        SS      PP  PP  UU   UU     TT     !!  !!\n"+
"         SSSS   PPPPP   UU   UU     TT     !!  !!\n"+
"            SS  PP      UU   UU     TT     !!  !!\n"+
"         SSSS   PP       UUUUU      TT     !!  !!\n"+
"You are hit with a moon sized pile of shit!\n"+
"Fecal matter explodes and flies everywhere in a circular pattern.\n");
move_object(clone_object("/players/mizan/etheriel/items/shit-directhit-residue.c"), this_player());
	  return 1;
  }*/
  msg = BLU+"-"+HIB+"+ +"+NORM+BLU+"- "+NORM+capitalize(TPRN)+": " +str;
  tell_object(k,msg+"\n");
  write(msg+"\n");
  return 1;
}

int update_scar(string str)
{
   object ob;
   ob = clone_object("/players/shinshi/closed/teller.c");
   
   destruct(this_object());
   move_object(ob, this_player());
   write("Your scar has been updated.\n");
   return 1;
}

rogue_talk(str){
	mixed ob;
	ob = "/players/shinshi/closed/rogue/objects/chatob.c";
	
	if(!ob){
		write("The guild line is currently down.\n");
		return 1;
	}
	if(!str){
		write("What would you like to emote to your fellow Rogues?\n");
		return 1;
	}
	
	ob->tell(str);
	return 1;
}

rogue_emote(str){
	mixed ob;
	ob = "/players/shinshi/closed/rogue/objects/chatob.c";
	
	if(!ob){
		write("The guild line is currently down.\n");
		return 1;
	}
	if(!str){
		write("What would you like to emote to your fellow Rogues?\n");
		return 1;
	}
	
	ob->emote(str);
	return 1;
}
