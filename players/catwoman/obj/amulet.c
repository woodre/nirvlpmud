int i, charges;
object targetloc;

id(str) { return str == "amulet"; }

reset(arg) {
   if(!arg) charges=random(4);
}

long() {
    write("The small magical amulet has some instructions engraved on it.\n");
    write("   1.  Go to the place you wish to return to\n");
    write("   2.  Type SET AMULET\n");
    write("   3.  Go off adventuring, and when you need to...\n");
    write("   4.  Type USE AMULET\\n");
    write("This will teleport you to the preset destination.\n");
    write("The amulet will run out of charges eventually.\n");
    if (i == 1) {
        write("Looking into the amulet you see:\n");
        call_other(targetloc, "long");
} }

short() { return "A small teleportation amulet"; }
query_value() { return 200; }
init() {
    add_action("use","use");
    add_action("set","set");
    add_action("stat","stat");
}

/* Spell point cost and check installed by Snow. 5/3/97 */
use(arg) {
  string realm, destrealm;
    if (!id(arg)) {
      return 0;
    } else {
       if (i != 1) {
          write("The amulet has not had a destination set.\n");
          return 1;
         } else {
           realm=call_other(environment(this_player()),"realm",0);
           destrealm=call_other(targetloc, "realm",0);
    if(this_player()->query_sp() < 40) {
      write("You do not have enough spell energy.\n"); return 1; }
           if ((realm == destrealm) && (realm != "NT")) {
             write("As you use the amulet everything shimmers away...\n");
               say(call_other(this_player(),"query_name") + "shimmers and fades\n");
             move_object(this_player(), targetloc);
             say(call_other(this_player(),"query_name")+" shimmers to solidity.\n");
             call_other(this_player(), "look",0);
    this_player()->add_spell_point(-40);
             if (charges == 1) {
             write("The amulet did not make it through the transport.\n");
             call_other(this_player(), "add_weight", -1);
             destruct(this_object());
             return 1;
             }
           charges = charges -1;
         } else {
             write("The amulet struggles to take you with it, but fails.\n");
             move_object(this_object(), targetloc);
             write("The amulet shimmers and fades.\n");
             call_other(this_player(),"add_weight", -1);
          }
          return 1;
} } }
set(arg) {
    if (!arg || arg != "amulet") {
     return 0;
    } else {
       write("You set the amulet's destination.\n");
       targetloc = environment(this_player());
       i = 1;
       }
       return 1;
    }
get () { return 1; }
query_weight() { return 1; }
stat(arg) {
    if(!arg || arg != "amulet" ||
        call_other(this_player(),"query_level",0)<50) return 0;
        write("Amulet stats:\ncharges:");
        write(charges);
        write("\ndestination:");
        write(targetloc);
        write("\n");
}

