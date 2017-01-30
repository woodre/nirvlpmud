inherit "/obj/mail_reader";
#include "../DEFS.h"
#define NAME "/players/snow/closed/cyber/ninjas/"


load_player() {
   loaded = 1;
   if (!restore_object(NAME + this_player()->query_real_name()) ||
         messages == "" || messages == 0) {
      arr_messages = 0;
      messages = "";
      return;
   }
   if (new_mail) {
      new_mail = 0;
      save_object(NAME + this_player()->query_real_name());
   }
   arr_messages = explode(messages, "\n**\n");
}


delete() {
   if (curr_mess > sizeof(arr_messages)/2 || curr_mess < 1) {
      write("Illegal message number " + curr_mess + "\n");
      return;
   }
   arr_messages = remove_element(arr_messages, curr_mess*2 - 2);
   arr_messages = remove_element(arr_messages, curr_mess * 2 - 2);
   if (sizeof(arr_messages) < 2)
      messages = "";
   else
      messages = implode(arr_messages, "\n**\n") + "\n**\n";
   new_mail = 0;
   save_object(NAME + this_player()->query_real_name());
   if (messages == "")
      arr_messages = 0;
   else
      arr_messages = explode(messages, "\n**\n");
}


get_cc(cc) {
   int n;
   object ob;
   string cc2, next_pern;
   
  if (sscanf(cc, "%s/%s", thingone,thingtwo) == 2) {
        write("Not a legal name, no carbon copy sent.\n");
        cc = "";
        }
   send_mail(new_dest, new_subject + "\n", new_message, cc);
   if (cc && cc != "") {
      cc2 = cc;
      cc = lower_case(cc2);
      cc2 = "(To: " + new_dest + ") " + cc;
      while (cc != "") {
         n = sscanf(cc,"%s,%s",next_pern,cc);
         if (n == 0) {
            next_pern = cc; /* cc held remaining line; do last person. */
            cc = "";         /* set cc to "" to leave loop after this    */
         }
         if(restore_object("ninjas/"+extract(next_pern,0,0)+"/"+next_pern))
         send_mail(next_pern, new_subject + "\n", new_message, cc2);
        if(!restore_object("ninjas/"+extract(next_pern,0,0)+"/"+next_pern))
         write("There is no "+FUNKYNAME+" named "+next_pern+".\n");
       }
   }
   if (is_reading)
      loop();
}

/*
* Send a complete mail. If the receiver is reading mail, be sure to
* tell his mail reader that new mail has arrived.
*/
send_mail(dest, subj, mess, cc) {
   if (cc != "")
      cc = "Cc: " + cc + "\n";
   notify_new_mail(dest, subj, this_player()->query_real_name());
   messages = "";
   restore_object(NAME + dest);
   if (messages == 0)
      messages = "";
   messages += this_player()->query_real_name() + "\n**\n" + subj + cc +
   "Date: " + extract(ctime(time()), 4, 15) + "\n\n" + mess + "\n**\n";
   new_mail = 1;
   save_object(NAME+dest+".o");
}

notify_new_mail(dest, subj, name) {
   object ob;
    if(ob = find_player(dest)) {
      if(IPOB) {
      tell_object(ob,"You have new mail from " +
         name + ", " + subj + "\n");
      ob = present("mailread", ob);
      if (ob)
         ob->invalidate();
   }
   write("Sending mail to " + capitalize(dest) + ".\n");
  }
}

remove(arg) {
   arr_messages = remove_element(arr_messages, arg*2 - 2);
   arr_messages = remove_element(arr_messages, arg * 2 - 2);
   if (sizeof(arr_messages) < 2)
      messages = "";
   else
      messages = implode(arr_messages, "\n**\n") + "\n**\n";
   new_mail = 0;
   save_object(NAME + this_player()->query_real_name());
   if (messages == "")
      arr_messages = 0;
   else
      arr_messages = explode(messages, "\n**\n");
}
chan_block() {
  if(!channel_block) {
      channel_block = 1;
      write("Channel Block on.\n");
      save_object(NAME + this_player()->query_real_name());
      return;
      }
  if(channel_block) {
     channel_block = 0;
     write("Channel Block off.\n");
     save_object(NAME + this_player()->query_real_name());
     return ;
     }
}
