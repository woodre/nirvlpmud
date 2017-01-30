id(str) { return str=="authcheck"; }
short() { return "A authentication checker"; }
long() { write("This object allows you to generate passwords to authenticate you to SQL\nGo to http://nirvana.panop.com/ to use it\n"); }
init() { add_action("authcheck","authcheck"); }
authcheck(str)
{
   int i,d;
   string s;

   if(this_player()->query_level() < 21)
   {
      write("Fuck off, non-wiz person!\n");
      return 1;
   }

   s = "";
   d = time()/(60*60*24)%(64*64); /* What is today? */
   for(i=0; d>0; i++)
   {
      if(d%2 == 1) s=set_bit(s,i);
      d = d/2;
   }
   write("Your passcode for the day is: "+extract(crypt(this_player()->query_real_name(),s),5,8)+"\n");
   return 1;
}
query_auto_load() { return "/players/sado/closed/authcheck.c:"; }
drop() { return 1; }
get() { return 1; }
