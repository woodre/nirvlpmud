
string thing_file;
string thing_name;

id(str) { return (str=="machine" || str=="vender" || str=="vending machine"); }

short() { return "A \""+ thing_name + "\" vending machine"; }

long() {
     write("You see a vending machine. \"Press button\" to receive a " +
           thing_name + ".\n");
     write("\nAnother fine product brought to you by Bastion the archmage.\n");
     return 1;
}

reset(arg) {
     if(!arg) {
          thing_file=0;
          thing_name="<empty>";
     }
     return 1;
}

set_thing_file(ob) { thing_file=ob; }
set_thing_name(str) { thing_name=str; }

init() {
     add_action("press_button","press");
     add_action("press_button","push");
}

press_button(str) {
     object ob;
     if(!str || str!="button")
          return 0;
  if(thing_file) {
     ob=clone_object(thing_file);
     move_object(ob,this_player());
}
     write("You receive a " + thing_name + ".\n");
     say(this_player()->query_name() + " pushes the button and receives a " +
         thing_name + ".\n");
     return 1;
}
