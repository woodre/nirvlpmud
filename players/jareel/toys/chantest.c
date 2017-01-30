send(str) {
   string history; /* added by verte */
   object list;
   object AURA;
   int i;
   string myname;
   if (!str) { write("Send what?\n"); return 1; }
   list = users();
return 1;
}

/* $ history patch by verte $ */
if(str == "history" || str == "-h")
{
        history = "/obj/user/chistory"->query_history("Nirvana Legends");
write(history+"\n");
        return 1;
}
/* $ end history patch by verte $ */
/* $ color by verte */

str = "/players/vertebraker/closed/std/color"->filter_msg(str);

/* $ end color by verte */
str += "\n";
"/obj/user/chistory"->add_history("Nirvana Legends",
esc+"[0m"+esc+"[0m"+esc+"[32m"+""+BLU+"("+NORM+HIW+"Legend"+BLU+") "+NORM+HIW+this_player()->query_name()+esc+"[0m: "+str);
myname = capitalize((string)this_player()->query_real_name());
   for(i=0; i<sizeof(list); i++) {
      AURA = present("Nirvana Legends",list[i]);
      if (AURA && !AURA->query_block()) {
          tell_object(list[i], esc+"[0m"+esc+"[0m"+esc+"[32m"+
          "("+HIW+"Legend"+NORM+BLU+") "+myname+esc+"[0m: "+
            str+"\n");
       }
   }
    return 1;
}

