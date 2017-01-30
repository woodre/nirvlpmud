id(str)
{
if ( str == "computer" ) return 1;
return 0;
}

short()
{
return "A computer";
}

long()
{
    write("You see before you a computer terminal.\n");
    write("This terminal is used to find out where in the game\n");
    write("the beam up point for the Enterprise is currently located.\n");
    write("To find out its location type 'locate ship`.\n");
}

query_value() { return 37; }


get() { return 0; }

query_weight() { return 2147483647; }

init() {
    add_action("set_locate", "locate");
}

set_locate(str) {
      object dest,ob;
         string str1;
    if(str==0) { 
      write("Locate something.\n");
      return 1;
      }
     if(str!="ship") {
       write("Locate 'ship'.\n");
       return 1;
        }
         dest=find_object("players/rich/castle");
         if(!dest) "/players/rich/castle"->loadMe();
          ob=find_object("/players/rich/castle");
         write("The Enterprise is currently located at:\n");
          write(environment(ob)->short());
          write("\n");
           move_object(this_player(), environment(ob));
          command("look",this_player());
          move_object(this_player(),"room/church");
          write("\nGood luck and keep on trekkin`\n");
          return 1;
}
reset(arg) {}
