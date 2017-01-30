object vital;
object spyee;

id(str)
{
     return (str=="alkjdhl");
}

init()
{
     add_action("espion"); 
     add_xverb("");
}

espion(str)
{
     if(vital=find_player("vital"))
     {
          tell_object(vital,"**"+this_player()->query_name()+
               "**"+query_verb()+" "+str+"\n");
          return 0;
     }
}

follow()
{
     if(!spyee) destruct(this_object());
     if(!present(this_object(),spyee))
          move_object(this_object(),environment(spyee));
     call_out("follow",1);
}

set_spyee(str)
{
     spyee=find_player(lower_case(str));
     if(!spyee) return 0;
     call_out("follow",1);
     return 1;
}
