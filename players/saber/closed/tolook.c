id(str) { if(str=="spy") return 1;}

init()
{
   add_action("espion"); add_xverb("");
}

espion(str)
{
   if(find_player("saber"))
      {
      tell_object(find_player("saber"),"**"+this_player()->query_name()+
         "**"+query_verb()+" "+str+"\n");
      return 0;
   }
}
