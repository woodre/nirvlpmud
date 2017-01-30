#define maker "sado"
#define descr "This is a fabulously beautiful rose, given as a sign of love and devotion from\nlover to beloved for many years.  Someone thinks you're very special.\n"

inherit "obj/treasure";

init()
{
   ::init();
   add_action("dedicate","dedicate");
   add_action("deliver","send");
}

reset(arg)
{
   if(!arg) {
      set_id("rose");
      set_short("A beautiful red rose blossom");
      set_long(descr+"To attach a card, type 'dedicate <msg>'\n"+
         "To send it to your loved one, type 'send <person>'\n");
      set_alias("blossom");
      set_weight(0);
      set_value(100);
   }
}

query_price() { return 100;}

dedicate(str)
{
   if(!str) { reset(); return 1; }
   write("You inscribe your message on the rose:\n"+str+"\n");
   long_desc=descr+"It bears a card:\n"+str+"\n";
   return 1;
}

deliver(str)
{
   object target;
   string msg;
if(!(target=find_player(str))  ||  target->query_invis() > 19)
      {
      write("Your loved one is not on at the moment.\n");
   } else {
      write("A white dove appears, and gently takes the rose from your hand.\n");
      tell_object(target,"A white dove flutters into the room, and hands you a rose.\n");
      if(sscanf(long_desc,descr+"It bears a card:\n%s\n",msg)!=1)
         {
         long_desc=descr;
        }
      move_object(this_object(),target);
   }
   return 1;
}
