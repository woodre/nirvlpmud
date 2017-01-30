#include "/players/fakir/color.h"
inherit "obj/armor";
int x;
reset(arg) {
  if(arg) return;
  set_id("rok shell");
  set_alias("shell");
  set_short(REVERSE+BROWN+"Rok Shell"+OFF);
  set_long(
  "This is the still"+REVERSE+BROWN+" living "+OFF+"shell from the Ballindorok of the boarderlands.\n"+
  "Once worn, the shell will bond its life to yours and provide you with\n"+
  "exceptional protection from without.  Once removed, its essence will\n"+
  "depart, and the shell will die.  It will then be of no further use as\n"+
  "an armor.  Use the shell wisely, and you will prosper.\n");
  set_weight(3);
  set_type("armor");
  set_save_flag();
  set_ac(5);
  set_value(2550+random(1000)); }

wear(str) {
  if(!id(str)) return 0;
  if(worn) {
    notify_fail("The shell's "+REVERSE+BROWN+"life-force"+OFF+" is already protecting you!\n");
    return 0; }
  if(x) {
    notify_fail("Its"+BROWN+" life-force "+OFF+"is spent.  It will no longer protect you from harm.\n");
    return 0; }
  x=1;
  write("The shell's "+REVERSE+BROWN+"life-force"+OFF+" bonds with you and creates a living shield....\n");
  say("The shell's "+REVERSE+BROWN+"life-force"+OFF+" bonds with "+this_player()->query_name()+".....\n");
  ::wear(str);
  return 1; }

remove(str) {
  if(!id(str)) return 0;
  if(x) new_desc(); 
  if(!worn) {
    notify_fail("You are not wearing the shell!\n");
    return 0; }
  write("The "+BROWN+"life-force"+OFF+" dies and releases its bond with you...\n");
  say("The "+BROWN+"life-force"+OFF+" dies and releases its bond on "+this_player()->query_name()+".....\n");
  ::remove(str);
  return 1; }

drop() {
    if(x) new_desc();
    ::drop();  }
  
new_desc() {
    short_desc = BROWN+"Rok Shell"+OFF;
    long_desc = "With its"+BROWN+" life-force "+OFF+"spent, the once living shell of the Ballindorok\n"+
                "will no longer serve as an armor.  You might be able to fetch a fair\n"+

                "price for it at a shop or trading post.\n";
}
