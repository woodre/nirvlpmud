#include "/players/fakir/color.h"
#define tp this_player()->query_name()
inherit "obj/armor";
int x;
reset(arg) {
  if(arg) return;
  set_id("ring");
  set_short(BOLD+CYAN+"Angreal Wedding Ring"+OFF);
  set_long(
  "An ancient angreal ring, crafted in an age unknown...lost for many\n"+
  "turnings of the wheel within the dark, evil caverns of the Ways.  It\n"+
  "glows with power and magics long ago lost to the world of this age.\n"+
  "The ring has some engravings inside the band you might want to read.\n");
  set_weight(1);
  set_type("ring");
  set_save_flag();
  set_ac(2);
  set_params("magical",1,0,0);
  set_value(350+random(1000)); }

wear(str) {
  if(!id(str)) return 0;
  if(worn) {
    notify_fail("The ring's "+BOLD+CYAN+"magic"+OFF+" is already protecting you!\n");
    return 0; }
  if(x) {
    notify_fail("Its"+BOLD+CYAN+" magic "+OFF+"is spent.  It will no longer protect you from harm.\n");
    return 0; }
  x=1;
  write("The angreal ring "+BOLD+CYAN+"magically"+OFF+" bonds to your finger and you feel its power....\n");
  say("The angreal ring "+BOLD+WHITE+"magically"+OFF+" bonds to "+this_player()->query_name()+".....\n");
  ::wear(str);
  return 1; }

remove(str) {
  if(!id(str)) return 0;
  if(x) new_desc(); 
  if(!worn) {
    notify_fail("You are not wearing the angreal ring!\n");
    return 0; }
  write("The "+BOLD+CYAN+"Angreal Ring"+OFF+" releases its bond on you...\n");
  say("The "+BOLD+CYAN+"Angreal Ring"+OFF+" releases its bond on "+this_player()->query_name()+".....\n");
  ::remove(str);
  return 1; }

drop() {
    if(x) new_desc();
    ::drop();  }
  
new_desc() {
    short_desc ="Angreal Wedding Ring (Broken)";
    long_desc = "With its"+CYAN+" magic "+OFF+"broken, the angreal ring will no longer serve as a\n"+
                "protection.  You might be able to fetch a fair price for it at a\n"+
                "shop or trading post.\n";
}
init(){ 
  ::init(); 
add_action("read_engravings","read");
}
read_engravings(str)  {

if(str == "engravings")  {

  write(CYAN+"Beloved, once worn, this angreal shall protect thee evermore.  It\n"+
        "is crafted in love and bonded with magics...never remove it, nor\n"+
        "let it slip thy grasp, that its magics may always have life."+OFF+"\n");

  say(tp+" reads the engraving inside the ring's band.\n");

    return 1;   }
        }
