#define HP this_player()->query_hp()
#define SP this_player()->query_sp()
#define ME this_player()
inherit "obj/treasure";
   int x;
   string mode;
reset(arg) {
 if(arg) return;
   mode = "hptosp";
   set_short("A Juggler's Pin");
    set_alias("pin");
   set_long("This is a magical juggler's pin.  It allows you to\n"+
     "juggle your Hit points to Spell points or visa versa.\n"+
     "For instructions, type: info pin.  \n");
   set_weight(2);
    set_value(2500);
}
 id(str) { return str == "pin" || str == "juggle"; }

init() {
 ::init();
   add_action("mode","mode");
 add_action("juggle","juggle");
  add_action("info", "info");
 add_action("check","check");
}

mode() {
 if(mode == "hptosp") {
    mode = "sptohp";
write("You are now set to juggle Spell points into Hit points.\n");
      return 1;
           }
 if(mode == "sptohp") {
   mode = "hptosp";
 write("You are now set to juggle Hit points to Spell Points.\n");
           return 1;
   }
}
juggle(str) {
   if(!str) {
  write("You must specify how much you would like to Juggle.\n");
       return 1;
     }
   sscanf(str, "%d", x);

  if(mode == "hptosp") {
       if(x > HP) {
 write("You dont have "+str+" Hit points!\n");
           return 1;
              }
  if(x < 1) {
  write("You cannot juggle that!\n");
    return 1;
    }
    this_player()->add_hit_point(-x);
    this_player()->add_spell_point(x);
   this_player()->add_hit_point(-random(5));
write("You juggle "+str+" of your Hit points into Spell points.\n");
        return 1;
    }
  if(mode == "sptohp") {
      if(x > SP) {
write("You don't have "+str+" Spell points!\n");
             return 1;
           }
   if(x < 1) {
  write("You cannot juggle that!\n");
       return 1;
        }
    this_player()->add_hit_point(x);
     this_player()->add_spell_point(-x);
   this_player()->add_spell_point(-random(5));
 write("You juggle "+str+" of you Spell points into Hit points.\n");
        return 1;
  }
}
check(str) {
 if(!str == "pin") {
     return 0;
       }
  if(str == "pin") {
   if(mode == "hptosp") {
     write("You are currently set to juggle Hit points to Spell points.\n");
         return 1;
           }
  if(mode == "sptohp") {
    write("You are currently set to juggle Spell Points to Hit points.\n");
          return 1;
           }
  }
}
info(str) {
  if(str == "pin") {
 write("\nThis is a magical Juggler's pin! It can juggle your Hit points\n"+
    "to Spell points, or Spell points to Hit points.  A small amount of\n"+
    "energy will be lost in the transferrence.\n"+
    "The commands of the Jugglers pin are: \n"+
    "         mode            -set the mode of the pin (either HP to SP\n"+
    "                          or SP to HP).\n"+
    "         check pin       -see what setting the pin is currently on.\n"+
    "         info pin        -this menu.\n"+
    "         juggle (amt)    -Will juggle on power to the other.\n\n"+
    "   remember, some energy will be lost in the juggling of HP/SP\n\n");
    return 1;
   }
}
