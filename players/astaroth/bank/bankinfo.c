/*
        in the format (name1:name2:amount)
*/
 
string accounts;
 
 
query_account(str) {
string s1, s2;
int amt;
 
   restore_object("players/astaroth/bank/accounts");
 
   if (sscanf(accounts, "%s(" + str + ":%d)%s", s1, amt, s2) != 3)
      return -1;
   else
      return amt;
}
 
 
deposit(str, d) {
int sum, amt;
string s1, s2;
 
   if (!str) return -1;
   if (!d) return -1;
 
   if (d < 0) return -1;                        /* just can't trust folks */
   if (query_account(str) < 0) return -1;       /* has no account  == -1 */
 
   restore_object("players/astaroth/bank/accounts");
   if (sscanf(accounts, "%s(" + str + ":%d)%s", s1, amt, s2) != 3)
        return -1;
 
   sum = amt + d;
   if (sum > 100000) return -2;
   accounts = s1 + "(" + str + ":" + sum + ")" + s2;
   save_object("players/astaroth/bank/accounts");
   return d;
}
 
withdraw(str, d) {
int sum, amt;
string s1, s2;
 
   if (!str) return -1;
   if (!d) return -1;
   if (d < 0) return -1;                        /* just can't trust folks */
   if (query_account(str) < d) return -1;       /* just can't trust folks */
 
   restore_object("players/astaroth/bank/accounts");
   if (sscanf(accounts, "%s(" + str + ":%d)%s", s1, amt, s2) != 3)
        return -1;
 
   sum = amt - d;
   accounts = s1 + "(" + str + ":" + sum + ")" + s2;
   save_object("players/astaroth/bank/accounts");
   return d;
}
 
open_account(str) {
 
   if (!str) return -1;
   if (query_account(str) >= 0) {
      return -1;
   }
 
   restore_object("players/astaroth/bank/accounts");
   accounts = accounts + "(" + str + ":0)";
   save_object("players/astaroth/bank/accounts");
   return 0;
}
 
fudge() {
 
   accounts = "";
   save_object("players/astaroth/bank/accounts");
   return 1;
}
