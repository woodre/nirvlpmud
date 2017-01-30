 
string other;
int canpull, bucks;
 
short () { return "a wedding ring (worn)"; }
 
long () {
        write(
        "This is a wedding ring, symbol of holy matrimony between you and "+
        other+".\n");
 
   if (this_player() == environment()) {
      write("'spouse'      - like the tell command to your spouse\n");
      write("'pull spouse' - pull your spouse to you.\n");
      write("'toggle pull' - toggle the ability to be pulled.\n");
      write("          - currently set: ");
      if (canpull == 0) write("*off*\n");
      else write("*on*\n");
      write("'balance'     - list $$ in your accounts.\n");
      write("'deposit'     - deposit cash in your account.\n");
      write("'withdraw'    - withdraw cash from your account.\n");
      write("'love'        - 'love' your spouse! near or far, secretly\n");
      write("... and your spouse is notified when you leave the game.\n");
   }
}
 
set_other (str) {
        if (!find_player(lower_case(str))) return;
        other = lower_case(str);
}
 
query_other () { return other; }
 
extra_look () { return "This person is married to "+capitalize(other); }
 
get() { return 1; }
 
drop () { return 1; }
 
query_auto_load() { 
   return "players/astaroth/obj/wring:" + other + "," + canpull + "," + bucks; 
}
 
init_arg(str) { 
string s1;
int d, m;
   
   if (sscanf(str, "%s,%d", s1, d) != 2) {
      write("\nThere is a problem initializing your wedding ring!\n");
      write("Please notify Astaroth!!\n\n");
      canpull = 0;
      other = str;
   }
   other = s1; 
   canpull = d; 
   bucks = m;
}
 
id (str) { return str == "ring" || str == "wedding ring" || str == "ND"; }
 
 
tellto(str) {
object spouse;
 
   spouse = find_player(other);
   if (!spouse) 
      write("Your spouse is not logged on.\n");
   else 
      tell_object(spouse, this_player()->query_name()+": "+str+"\n");
   return 1;
}
 
leaving() {
object spouse;
 
   spouse = find_player(other);
   if (spouse) 
        tell_object(spouse, "Your spouse left the game!\n");
   return 0;
}
 
pull(str) {
object spouse, theirring;
 
   if (str != "spouse") return 0;
   spouse = find_player(other);
   if (!spouse) {
      write("You cannot pull your spouse to you - they are not logged in!\n");
      return 1;
   } 
   theirring = present("wedding ring", spouse);
   if (!theirring) {
      write("* Huh! - they have no wedding ring!\n");
      return 1;
   }
   if (!theirring->query_pull()) {
      write("Your spouse does not wish to be pulled!\n");
      return 1;
   }
   if (call_other(environment(this_player()), "query_realm", "NT") ||
         call_other(environment(spouse), "query_realm", "NF")) {
      write("You cannot seem to pull them!\n");
      return 1;
   }
 
 
   write("You pull your spouse to you ...\n");
   say(this_player()->query_name()+" yells: Honey, can you come here a sec?\n");
   tell_object(spouse, "Your spouse calls you ...\n");
   move_object(spouse, environment(this_player()));
   tell_room(environment(this_player()),
        spouse->query_name()+" appears in a flash and says: Yes dear?\n");
   return 1;
}
 
toggle(str) {
 
   if (str != "pull") return 0;
 
   if (canpull) {
      canpull = 0;
      write("- spouse can not pull you now.\n");
   } else {
      canpull = 1;
      write("- spouse can pull you now.\n");
   }
   return 1;
}
 
init() {
   add_action("love"); add_verb("love");
   add_action("toggle"); add_verb("toggle");
   add_action("tellto"); add_verb("spouse");
   add_action("pull"); add_verb("pull");
   add_action("leaving"); add_verb("quit");
   add_action("balance"); add_verb("balance");
   add_action("deposit"); add_verb("deposit");
   add_action("withdraw"); add_verb("withdraw");
}
 
query_pull() { return canpull; }
 
balance() {
int ret;
string acct;
 
 
        acct = lower_case(this_player()->query_name())  + ":" + other;
        ret = call_other("players/astaroth/bank/bankinfo", "query_account", acct);
        if (ret < 0) {
           acct = other + ":" + lower_case(this_player()->query_name());
           ret = call_other("players/astaroth/bank/bankinfo", "query_account", 
                acct);
        }
 
        if (ret < 0) {
           write("%% Error in your account, contact Astaroth.\n");
        } else {
           write("You have $" + ret + " in your joint account.\n");
        }
        return 1;
}
 
deposit(str) {
int amt;
int ret;
string acct;
 
   if (!str) { write("deposit <amt>\n"); return 1; }
   if (sscanf(str, "%d", amt) != 1) {
      write("Please use 'deposit X', where X is a positive number.\n");
      return 1;
   }
   if (amt < 0) {
      write("You cannot deposit a negative amount!\n");
      return 1;
   }
   if (amt > this_player()->query_money()) {
      write("You do not have that much to deposit!\n");
      return 1;
   }
 
   acct = lower_case(this_player()->query_name()) + ":" + other;
   ret = call_other("players/astaroth/bank/bankinfo", "deposit", acct, amt);
 
   if (ret == -2 ) {
      write("You are cannot, by Mud law, keep over $100K in your account.\n");
      return 1;
   }
 
   if (ret < 0) {
      acct = other + ":" + lower_case(this_player()->query_name());
      ret = call_other("players/astaroth/bank/bankinfo", "deposit", acct, amt);
   }
 
   if (ret == -2 ) {
      write("You are cannot, by Mud law, keep over $100K in your account.\n");
      return 1;
   }
 
   if (ret < 0)  {
      write("%% Error in depositing the cash.\n");
   } else {
      write("Deposited $"+amt+" into your account.\n");
      call_other(this_player(), "add_money", -ret);
      write("Done\n");
   }
   return 1;
}
 
withdraw(str) {
int amt;
int ret;
string acct;
 
 
   if (!str) { write("withdraw <amt>\n"); return 1; }
   if (sscanf(str, "%d", amt) != 1) {
      write("Please use 'withdraw X', where X is a positive number.\n");
      return 1;
   }
   if (amt < 0) {
      write("You cannot withdraw a negative amount!\n");
      return 1;
   }
 
   acct = lower_case(this_player()->query_name()) + ":" + other;
   ret = call_other("players/astaroth/bank/bankinfo", "withdraw", acct, amt);
   if (ret < 0) {
      acct = other + ":" + lower_case(this_player()->query_name());
      ret = call_other("players/astaroth/bank/bankinfo", "withdraw", acct, amt);
   }
   
   if (ret < 0)  {
      write("%% Error in withdrawing the cash.\n");
   } else {
      write("Withdrew $"+amt+" into your account.\n");
      call_other(this_player(), "add_money", ret);
      write("Done\n");
   }
   return 1;
}
 
love(str) {
 
   if (!str) { write("Love who?\n"); return 1; }
 
   if (lower_case(str) != other && lower_case(str) != "spouse") {
      write("What!... trying to love another!\n");
      if (find_player(other))
         tell_object( find_player(other), 
                "Your spouse tried to 'love' without you!\n");
      return 1;
   }
   if (!present(other, environment(this_player()))) {
      write("You love your spouse from a distance!\n");
      if (find_player(other))
         tell_object( find_player(other), 
                "You feel your spouse's love!\n");
      return 1;
   }
 
   write("You love your spouse ... and no one sees but you two!\n");
   if (find_player(other))
      tell_object( find_player(other), 
        "Your spouse loves you deeply and with much passion!\n");
   return 1;
}
 
set_o(str) {
   other = lower_case(str);
}
