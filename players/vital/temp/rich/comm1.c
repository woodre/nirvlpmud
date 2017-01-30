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
write( "To use the communicator type `read communicator on name'\n");
}

query_value() { return 2000; }


get() { return 1; }

query_weight() { return 3; }

init() {
    add_action("comm", "comm");
}

comm(str) {
string name,message;
    object ob;

    sscanf( str, "%s %s",name,message );
    write(name + message);
    if ( !id( name ) ) return 0;
    if ( message == 0 )
      {
      write ( "communicate to something.\n");
      return 0;
      }
    ob = find_player( name );
    write(ob);
     if (ob== 0){
      write("Nothing by that name is functioning at this time.\n");
      return 1;
     }
   if (present("communicator",this_player())) {
    write("fhgjh");
        tell_object(ob,this_player() + "tells you: " + message + "\n");
        return 1;
        }

reset(arg) {}
