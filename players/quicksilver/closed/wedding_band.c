#include "/players/quicksilver/closed/color.h"

string myself, spouse, short_descr, long_descr, entrance_msg, exit_msg,
       inscription, temp_inscription;

init()
{
  if(!query_ip_number(this_player())) return; 
  if((myself!="someone")&&this_player()->query_real_name()!=myself&&this_player()->query_real_name()!=spouse) 
     destruct(this_object());
  add_action("help_ring","help");
  add_action("update_ring","update_ring");
  add_action("restore_ring","restore_ring");
  add_action("teleport_to","go");
  add_action("teleport","bring");
  add_action("set_entrance","set_enter");
  add_action("set_exit","set_exit");
  add_action("start_inscribe","inscribe");
  add_action("chat","ring");
  add_action("read_inscription","read");
  /*
  add_action("add_message","note");
  add_action("view_messages","view");
  */
  add_action("q","quit");
  chat(entrance_msg+".",1);
  if(find_player(spouse)) write(BOLD+BLU+"{ring}: "+NOSTYLE+capitalize(spouse)+" is logged in!\n");
  else write(BOLD+BLU+"{ring}: "+NOSTYLE+capitalize(spouse)+" is not logged in.\n");
}

reset(arg) {
   if(arg) return;
/*     myself=this_player()->query_real_name(); */
     spouse="someone?";
     short_descr="A wedding band";
     long_descr="A non-descript wedding band.\n";
     entrance_msg="joins you in the game.";
     exit_msg="left the game.";
     if(this_player())
       restore_object("players/quicksilver/closed/etc/rings/"+this_player()->query_real_name());
}

query_auto_load() {
  return "/players/quicksilver/closed/wedding_band.c:";
}

query_spouse() {
   if(environment(this_object())->query_real_name()=="mackenzie") return "Quicksilver"; else return "Mackenzie";
}

get() { return 1; }
drop() { return 1; }
id(str) { return str=="ring"||str=="wedding ring"||str=="wedding band"||str=="qs_wedband"; }
short() { return short_descr+" "+BOLD+BLU+"{"+capitalize(spouse)+"}"+NOSTYLE; }
long() { write(long_descr);
         if(inscription) write("\nThere is an inscription on the ring.\n");
         else write("\n");
         write("-- Type 'help ring' for a list of commands.\n");}

update_ring() {
   move_object(clone_object("players/quicksilver/closed/wedding_band"), 
               environment(this_object()));
   destruct(this_object());
   return 1;
}

restore_ring() {
   object sp, ring;
   
   sp=find_player(spouse);
   if(!sp) {
      write("You are unable to restore the ring unless your loved one is logged in.\n");
      return 1;
   }
   if(present("qs_wedband", sp)) {
      write("Your loved one already has a ring.\n");
      return 1;
   }
   ring=clone_object("players/quicksilver/closed/wedding_band");
   move_object(ring, sp);
   ring->set_myself(spouse);
   write("You have restored your loved one's ring.\n");
   tell_object(sp, "Your loved one has restored your ring.\n");
   return 1;
}

teleport(str) {
   object oldroom;
   
   if(str!=spouse) {
      write("That person is not your spouse.\n");
      return 1;
   }
   if(!find_player(spouse)) {
      write("Your loved one is not logged in.\n");
      return 1;
   }
   if(environment(this_player())->realm()=="NT"||environment(find_player(spouse))->realm()=="NT") {
      write("A warping of space prevents you from bringing your loved one.\n");
      return 1;
   }
   oldroom=environment(find_player(spouse));
   move_object(find_player(spouse), environment(find_player(myself)));
   say(capitalize(spouse)+" shimmers into solidity.\n",find_player(myself));
   tell_room(oldroom, capitalize(spouse)+" fades from view.\n");
   write("Your loved one shimmers into solidity.\n");
   tell_object(find_player(spouse), "Your loved one summons you.\n");
   this_player()->add_spell_point(-50);
   return 1;
}

teleport_to(str) {
   if(str!=spouse) {
      write("That person is not your spouse.\n");
      return 1;
   }
   if(!find_player(spouse)) {
      write("Your loved one is not logged in.\n");
      return 1;
   }
   if(this_player()->query_spell_point() <= 50) {
      write("You need at least 50 spell points.\n");
      return 1;
   }
   if(environment(this_player())->realm()=="NT"||environment(find_player(spouse))->realm()=="NT") {
      write("A warping of space prevents you from joining your loved one.\n");
      return 1;
   }
   say(capitalize(myself)+" fades from view.\n");
   move_object(environment(this_object()), environment(find_player(spouse)));
   tell_object(find_player(spouse), "Your loved one shimmers into solidity.\n");
   say(capitalize(myself)+" shimmers into solidity.\n",find_player(spouse));
   write("You appear before your beloved.\n");
   this_player()->add_spell_point(-50);
   return 1;
}

set_spouse(str) {
   spouse=str;
   save_object("players/quicksilver/closed/etc/rings/"+myself);
}

set_myself(str) {
   myself=str;
   restore_object("players/quicksilver/closed/etc/rings/"+myself);
}

set_inscription(str) {
   inscription=str;
   save_object("players/quicksilver/closed/etc/rings/"+myself);
}

set_short(str) {
   short_descr=str;
   save_object("players/quicksilver/closed/etc/rings/"+myself);
}

set_long(str) {
   long_descr=str;
   save_object("players/quicksilver/closed/etc/rings/"+myself);
}

set_entrance(str) {
   if(str) {
     entrance_msg=str;
	 long_descr="   This platinum wedding band, with its muted celtic knotwork etchings, binds\ntogether three unique stones.\n   Held within a heart-shaped bezel, the center stone is--quite naturally--a\ndiamond.  The diamond, modest yet brilliant, is deep cut.  As light falls\nupon it, the fire for which the stone is famous dances within.\n   The brilliance of the diamond also falls radiantly upon two black opals,\nseated on either side.  Both contain strong hints of blue-green hue.  But as\nthe refracted light cast from the diamond dances across the surface of the\nopals, deep reds with fiery orange accents emerge.\n   The complex nature of this ring is bound together in a unique fashion, rife\nwith intricate meaning.  The clear, yet radiant, diamond would appear to\nrepresent the purity and clarity of a marriage bond, while the opals signify\nthe ever-changing complexity of the relationship.";
	 save_object("players/quicksilver/closed/etc/rings/"+myself);
   }
   write("When you login, your spouse will see:\n");
   write(BOLD+BLU+(((str[0]==58)||(str[0]==64)) ? "{ring}" : (capitalize(this_player()->query_real_name())+" {ring}"))+
	     ": "+NOSTYLE+((str[0]==58) ? (capitalize(this_player()->query_real_name())+" ") : "")+(((str[0]==58)||(str[0]==64)) ? str[1..strlen(str)] : str)+"\n");
   return 1;
}

set_exit(str) {
   if(str) {
     exit_msg=str;
	 save_object("players/quicksilver/closed/etc/rings/"+myself);
   }
   write("When you logout, your spouse will see:\n");
   write(BOLD+BLU+(((str[0]==58)||(str[0]==64)) ? "{ring}" : (capitalize(this_player()->query_real_name())+" {ring}"))+
	     ": "+NOSTYLE+((str[0]==58) ? (capitalize(this_player()->query_real_name())+" ") : "")+(((str[0]==58)||(str[0]==64)) ? str[1..strlen(str)] : str)+"\n");
   return 1;
}

get_inscription(str) {
    if (str == "**") {
        return;
    }
    temp_inscription = temp_inscription + str + "\n";
    write("]");
    input_to("get_inscription");
}

start_inscribe() {
   object sp, ring;
      
   sp=find_player(spouse);
   if(!sp) {
      write("You are unable to inscribe your loved one's ring unless they are logged in.\n");
      return 1;
   }
   ring=present("qs_wedband", sp);
   if(!ring) {
      write("Your loved one doesn't seem to have a ring.  Try 'restore_ring' first.\n");
      return 1;
   }
   temp_inscription="";
   write("Type inscription, and terminate with '**'.\n");
   write("]");
   input_to("get_inscription");
   return 1;
}

do_inscribe() {
   object sp, ring;
      
   sp=find_player(spouse);
   if(!sp) {
      write("You are unable to inscribe your loved one's ring unless they are logged in.\nIf you'd like to save what you've written, cut and paste the following:\n"+temp_inscription);
      return 1;
   }
   ring=present("qs_wedband", sp);
   if(!ring) {
      write("Your loved one doesn't seem to have a ring, but did when you started.\nAutorestoring...\n");
      restore_ring();
   }
   ring->set_inscription(temp_inscription);
   write("You inscribe the following on your loved one's ring:\n"+temp_inscription);
   tell_object(sp, "Your ring feels warm for a brief moment.\nYour spouse has engraved an inscription on it that you can 'read'.\n");
   return 1;
}

help_ring(str) {
   if(str!="ring") return 0;
   write(BOLD+BLU+"Your wedding ring has the following commands:"+NOSTYLE+"\n");
   write("ring [message]       -\tSend a message to your loved one\n");
   write("                      \t  ring :[message] to emote\n");
   write("                      \t  ring @[message] to echo\n");
   /* write("note [message] -\tLeave a note for your loved one\n");
   write("view           -\tView notes left by you and your loved one\n"); */
   write("go [spouse]          -\tTeleport to your loved one\n");
   write("bring [spouse]       -\tTeleport your loved one to you\n");
   write("set_enter [message]* -\tSet a login message\n");
   write("set_exit [message]*  -\tSet a logout message\n");
   write("inscribe             -\tCreate an inscription on your loved one's ring\n");
   write("restore_ring         -\tRestore your loved one's ring\n");
   write("update_ring          -\tUpdate your ring (try if ring is bugged)\n");
   write("   * note: message may be an emote or an echo (see format for 'ring')\n");
   return 1;
}

read_inscription(str) {
   if(str!="inscription") return 0;
   write(BOLD+BLU+"The inscription reads:"+NOSTYLE+"\n"+inscription);
   return 1;
}

/* rewrite...no orb
view_messages() {
   object stuff,orb;
   int i;
  
  stuff=all_inventory("players/quicksilver/workroom");
  for(i = 0; i <sizeof(stuff); i++)
        {
           if(stuff[i]->id("qsorb")) {
              orb=stuff[i];
              break;
           }
        }
           
   write(orb->print_msg());
   return 1;
}

add_message(str) {
   object stuff,orb;
   int i;
   string temp;
   
  stuff=all_inventory("players/quicksilver/workroom");
  for(i = 0; i <sizeof(stuff); i++)
        {
           if(stuff[i]->id("qsorb")) {
              orb=stuff[i];
              break;
           }
        }
           
   if(!str) {
      notify_fail("You must specify a message to add.\nUsage: note [message]\n");
      return 0;
   }
   orb->add_msg(str);
   chat("@Your ring radiates warmly for a brief second.");
   return 1;
}
*/

chat(str,is_enter) {
	if(find_player(spouse)) tell_object(find_player(spouse),BOLD+BLU+(((str[0]==58)||(str[0]==64)) ? "{ring}" : (capitalize(this_player()->query_real_name())+" {ring}"))+
	": "+NOSTYLE+((str[0]==58) ? (capitalize(this_player()->query_real_name())+" ") : "")+(((str[0]==58)||(str[0]==64)) ? str[1..strlen(str)] : str)+"\n");
	if(is_enter) return;
	write(BOLD+BLU+(((str[0]==58)||(str[0]==64)) ? "{ring}" : (capitalize(this_player()->query_real_name())+" {ring}"))+
	": "+NOSTYLE+((str[0]==58) ? (capitalize(this_player()->query_real_name())+" ") : "")+(((str[0]==58)||(str[0]==64)) ? str[1..strlen(str)] : str)+"\n");
	return 1;
}

q() {
  chat(exit_msg);
  return 0;
}
