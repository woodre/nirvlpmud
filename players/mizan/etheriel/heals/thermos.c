/*
                Scooter helped me BIG time with the code on this
                jug. (The part involving the sscanf function.
                I got this idea from Genocide. More functions are
                being worked out....

NEW->>	This item is gradually going to be phased out of service.
	Reason: It needs to be revamped, and BIG time. It was carried
	over because people actually like it- really! they do :)
	1 Dec 93
*/
object ob;
string kick;
int pow_int;
int intox_setting;
id(str) { return str == "thermos" || str == "MI-thermos"; }
short() { return "A green thermos with ["+pow_int+"] charges"; }
long() {
cat("/players/mizan/etheriel/items/THERMOS");
write("\n"+
"The thermos has ["+pow_int+"] charges remaining.\n");
        }

get() { return 1; }
query_weight() { return 2; }
query_value() { return 1; }

/* new stuff added 21 aug 95 */
query_intox() { return intox_setting; }
query_charge() { return pow_int; }
set_intox(arg) { intox_setting = arg; }


init() {
  if(this_player()) write_file("/players/mizan/logs/thermos_log",ctime(time())+" "+this_player()->query_real_name()+" has thermos.\n");
        add_action("as","ts");
        add_action("ah","th");
        /*
        add_action("add","add");
        */
        add_action("jug","the");
        add_action("bognut","alskdjfh");
        }
ah() {
        int x, y, z;
        x=this_player()->query_mhp();
        y=this_player()->query_hp();
        z=x-y;
        command("the "+z, this_player());
        write("HP Autoheal\n");
        return 1;
}
as() {
        int x, y, z;
        x=this_player()->query_msp();
        y=this_player()->query_sp();
        z=x-y;
        command("the "+z, this_player());
        write("SP Autoheal\n");
        return 1;
}
bognut(str) {
  int amt;
  write("Your attempt to cheat has been logged and recorded. You have lost one\n"+
  "quarter of your experience. Complaints to gods or other wizzes will do\n"+
  "no good. Don't do this again, naturally.\n");
  write_file("/players/mizan/logs/JUG_ILLEGAL",
  (this_player()->query_real_name()) + " tried to fill the thermos " + str + " units.\n");
  amt = this_player()->query_exp() / 4;
  this_player()->add_exp(-amt);
  write_file("/players/mizan/logs/JUG_ILLEGAL", "Deducted: " + amt + "\n");
  call_other("/room/adv_guild", "correct_level", this_player());
  return 1;
}

add_charge(str) {
        int x;
  x = str;
        pow_int=pow_int+x;
	if(pow_int > 140) pow_int = 140;
        write(
        "Current charge is ["+pow_int+"] units.\n");
        return 1;
        }

jug(arg) {
        int x;
        if(!arg) {
                write("There are ["+pow_int+"] units in the thermos.\n"); 
                return 1;
                }
  sscanf(arg,"%d",x);
        if(x < 0) { write("You can't do that.\n");
          return 1;
        }
        if(x > pow_int) { write("There are only ["+pow_int+"] charges remaining!\n");   return 1; }
        this_player()->heal_self(x);
        pow_int=pow_int-x;
        write("["+(this_player()->query_hp())+"]hp ["+
    (this_player()->query_sp()) + "]sp  [" +
        pow_int+"]charges \n");
        say((this_player()->query_name())+" pops open a thermos and guzzles some funky ooze.\n");
        return 1;
        }
