/*****
        mode 0 = idle
        mode 1 = got a marriage request, need to ask player1
        mode 2 = got ok from 1, need to ask player2
        mode 3 = got ok from 2, make and put rings on
 
 
 
        mode 0 = idle
        mode 1 = got a marriage request, need to ask player1
        mode 2 = waiting ...
        mode 3 = got ok from 1, need to ask player2
        mode 4 = waiting ...
        mode 5 = got ok from 2, make and put rings on
 
****/
 
inherit "obj/monster";
 
object obj1, obj2;                /* whos getting married */
string name1, name2;                /* their names */
string capname1, capname2;        /* their names */
int mode;                        /* what mode the preacher is in */
int catching;                        /* catching tells.... */
int flag;                        /* reset the mode flag */
 
 
 
reset(arg) {
 
   ::reset(arg);
   if (arg) return; 
 
   set_name("preacher");
   set_short("A preacher (good)");
   set_long("This is an old fire and brimstone preacher with a black hat "+
   "and string tie.\n");
   set_level(19);        /* so he can't get killed */
   set_ac(5000);
   set_wc(500);
 
   mode = 0;
}
 
 
 
 
 
catch_tell(arg) {
string s1, str;
 
   str = lower_case(arg);
 
   if (sscanf(str, "the preacher%s", s1) == 1) return;
   if (catching) return;
   catching = 1;
 
   remove_call_out("preacherwait");
 
   if (mode == 0) {
        if ((sscanf(str, "%s says: i want to marry %s\n", name1, name2) == 2) ||
         (sscanf(str, "%s says: I want to marry %s\n", name1, name2) == 2)) {
           obj1 = find_player(lower_case(name1));
           obj2 = present(lower_case(name2), environment());
 
           if (present("wedding ring", obj1) || present("wedding ring", obj2)){
              psay("says: I think I already see a wedding ring there folks.\n");
           } else if (!obj2) {
              psay("says: I do not see them here to marry!\n");
           } else {
              psay("nods\n");
              capname1 = obj1->query_name();
              capname2 = obj2->query_name();
              name1 = lower_case(name1);
              name2 = lower_case(name2);
              mode = 1;
           }
        }
   } else if (mode == 2) {
        if ((str ==  name1+" says: yes\n") ||
        (str == name1+" says: i do\n")) {
           psay("nods\n");
           mode = 3;
        }
        if (str ==  name1+" says: no\n") {
           psay("sighs and shakes his head.\n");
           psay("says: Maybe some other time, then.\n");
           mode = 0;
        }
   } else if (mode == 4) {
        if ((str == name2+" says: yes\n")  ||
        (str == name2+" says: I do\n")) {
           psay("nods\n");
           mode = 5;
        }
        if (str == name2+" says: no\n") {
           psay("sighs and shakes his head.\n");
           psay("says: Maybe some other time, then.\n");
           mode = 0;
        }
   } 
 
   catching = 0;
   call_out("preacherwait", 10+random(10), mode);
}
 
 
heart_beat() {
object ring1, ring2;
int ret;
 
   ::heart_beat();
 
   if (mode == 0) return;
 
   if (mode == 1) {
      psay("says to "+capname1+": Do you take "+capname2+
        " to be your partner?\n");
      tell_object(obj1, 
        "The preacher whispers: 'say yes',  'say I do', or 'say no' please.\n");
      mode = 2;
      call_out("preacherwait", 10+random(10), mode);
   } else
   if (mode == 3) {
      psay("says to "+capname2+": Do you take "+capname1+
        " to be your partner?\n");
      tell_object(obj2, 
        "The preacher whispers: 'say yes',  'say I do', or 'say no' please.\n");
      mode = 4;
      call_out("preacherwait", 10+random(10), mode);
   } else
   if (mode == 5) {
      psay("says: I give you these rings as a reminder of your love for "+
        "each other.\n");
      psay("says: A circle, unbroken, with no beginning or ending.\n");
      psay("places the rings.\n");
/* clone the rings .. and give them ... */
      ring1 = clone_object("players/astaroth/obj/wring");
      ring2 = clone_object("players/astaroth/obj/wring");
 
      ring1->set_other(name2);
      ring2->set_other(name1);
 
      move_object(ring1, obj1);
      move_object(ring2, obj2);
/* open bank account */
      ret = call_other("players/astaroth/bank/bankinfo",
        "open_account", name1+":"+name2);
 
      if (ret == -1) 
        psay("says: I couldn't open a bank account. Please let Astaroth know if you want one.\n");
 
      psay("says: You may now kiss each other.\n");
      log_file("weddings", name1+" married "+name2+"\n");
      shout("Wedding bells toll in the distance.\n");
      mode = 0;
   }
}
 
psay(str) {
   tell_room(environment(), "The preacher "+str);
}
 
 
preacherwait(num) {
 
   if (mode == 0) return;
   if (num != mode) return;
   tell_room(environment(), "The preacher looks impatient.\n");
 
   if (test_if_any_here()) {
      if (mode) {
         psay("clears his throat.\n");
         flag += 1;
      }
      if (flag >=5 ) {
         psay("says: Well ... You people figure out what you want to do and start over again.\n");
              mode = 0;
              flag = 0;
      }
   } else {
      psay("mumbles softly.\n");
      mode = 0;
      flag = 0;
   }
 
   call_out("preacherwait", 10+random(10), mode);
}
 
query_mode() { return mode; }
 
query_catch() { return catching; }
 
