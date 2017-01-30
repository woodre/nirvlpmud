id(str)
{
if ( str == "stars" ) return 1;
return 0;
}

short()
{
return "4-stars";
}

long()
{
write( "These are very magical stars, you should give them a try...\n");
write(" syntax: read stars on <player>\n");
}

query_value() { return 2000; }
query_save_flag(){return 1;}

get() { return 1; }

query_weight() { return 3; }

init() {
add_action("read","read");
}

read(str) {
string me, onword, objectname;
    object ob;

    sscanf( str, "%s %s %s", me, onword, objectname );
    if ( !id( me ) ) return 0;
    if ( onword != "on" )
      {
      write( "read stars ON something.\n" );
      return 0;
      }
    if ( objectname == 0 )
      {
      write ( "read stars on SOMETHING.\n" );
      return 0;
      }
    ob = find_living( objectname );
      if(!ob) { /* Added by Feldegast 12/12/00 */
       write("There's nothing out there by that name.\n");
       return 1;
       }
     if ((ob->query_level())>20) {
      write("Sorry no definite readings can be obtained at this time.\n");
      return 1;
  }
     if (ob== 0){
      write("Nothing by that name is functioning at this time.\n");
      return 1;
     }
    write( call_other( ob, "query_name", 0 ) + "\n");
/*
    write("Level:\t" + call_other( ob, "query_level", 0) + "\n");
    write("MAX HP:\t" + call_other( ob, "query_mhp", 0) + "\n");
   write( "AC:\t" + call_other(  ob, "query_ac", 0  ) + "\n");
    write("WC:\t" + call_other(  ob, "query_wc", 0 ) + "\n");
*/
      write("Has a ");
     if(ob->query_level() > this_player()->query_level())
     write("higher");
     else write("lower");
     write(" level than you.\n");
      write("Has a ");
     if(ob->query_mhp() > this_player()->query_mhp())
     write("more");
     else write("less");
     write(" total hit points than you.\n");
      write("Has a ");
     if(ob->query_wc() > this_player()->query_wc())
     write("better");
     else write("worse");
     write(" weapon than you.\n");
      write("Has ");
     if(ob->query_ac() > this_player()->query_ac())
     write("better");
     else write("worse");
     write(" armor than you.\n");
destruct(this_object());
write("\n");
write("The Stars Shake and disappear!!.\n");
    return 1;
}

reset(arg) {}
