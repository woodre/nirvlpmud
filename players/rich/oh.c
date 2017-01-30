id(str)
{
if ( str == "tricorder" ) return 1;
return 0;
}

short()
{
return "A tricorder";
}

long()
{
write( "This is tricorder, in fact, it once belonged to Mr. Spock....\n" );
write( "Aren't you lucky!\n" );
}

query_value() { return 20000; }


get() { return 1; }

query_weight() { return 3; }

init() {
    add_action("read", "read");
}

read(str) {
string me, onword, objectname;
    object ob;

    sscanf( str, "%s %s %s", me, onword, objectname );
    if ( !id( me ) ) return 0;
    if ( onword != "on" )
      {
      write( "read tricorder ON something.\n" );
      return 0;
      }
    if ( objectname == 0 )
      {
      write ( "read tricorder on SOMETHING.\n" );
      return 0;
      }
    ob = find_living( objectname );
     if (ob== 0){
      write("Nothing by that name is functioning at this time.\n");
      return 1;
     }
    write( call_other( ob, "query_name", 0 ) + "\n");
    write("Level:\t" + call_other( ob, "query_level", 0) + "\n");
    write("HP:\t" + call_other( ob, "query_hp", 0) + "\n");
    write("MAX HP:\t" + call_other( ob, "query_max_hp", 0) + "\n");
   write( "AC:\t" + call_other(  ob, "query_ac", 0  ) + "\n");
    write("WC:\t" + call_other(  ob, "query_wc", 0 ) + "\n");
   write("Inv:\t" + call_other(  ob, "can_put_and_get",0) + "\n");
    return 1;
}

reset(arg) {}
