inherit "/obj/weapon.c";
#include "/players/persephone/rooms.h"
reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_id("net");
    set_name("net");
    set_short("A Pirates Net");
    set_long("A cool looking net that you think might trip people up\n"+
             "however it looks pretty worn out and it has some writing on it that\n" +
             "you might want to read on a label.\n");
    set_class(12);
    set_weight(1);
    set_value(1000);
    set_hit_func(TOB);
    set_save_flag(0);
}
weapon_hit(attacker){
    if(attacker->id("drake")){
        say(CAPTPLNM + " throws the net over Sir Francis Drake stunning him\n");
        write("You throw the net over Sir Francis and he appears to choke\n");
        return 25;
    }
return;
}
init(){
  ::init();
    add_action("read","read");
    add_action("read","study");
}
read(str){
  if(str=="label"||str=="writing"){
    write("Property of the Storm family return to storm for a reward\n");
  return 1;
  }
  write("What do you want to read?!?!?\n");
return 1;
}
