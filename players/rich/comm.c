id(str)
{
if ( str == "communicator" ) return 1;
return 0;
}

short()
{
return "A communicator";
}

long()
{
write( "This is communicator, in fact, it once belonged to Mr. Spock....\n" );
write( "Aren't you lucky!\n" );
write( "To use the communicator type `comm name message'\n");
}

query_value() { return 37; }


get() { return 1; }

query_weight() { return 1; }

init() {
    add_action("comm", "comm");
}

comm(str) {
string name,message;
    object ob;

    sscanf( str, "%s %s",name,message );
    if (name==0) return 0;
    if ( message == 0 )
      {
      write ( "communicate to something.\n");
      return 0;
      }
    ob = find_player( name );
     if (ob== 0) {
      write("Nothing by that name is functioning at this time.\n");
      return 1;
     }
  if (present("communicator",ob)) {
       write("You open your communicator.\n");
       tell_object(ob,"Your communicator beeps insistently.\n");
       tell_object(ob,"You open your communicator.\n");
        tell_object(ob,call_other(this_player(),"query_name",0));
        tell_object(ob," tells you:");
        tell_object(ob,message);
        tell_object(ob,"\n");
        return 1;
         }
      if (!present("communicator",ob)) {
         write("That player doesn`t have a communicator on them.\n");
         return 1;
         }
return 1;
        }

reset(arg) {}
