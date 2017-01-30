/*
Cloak of Shadows
Creator - Data
Date - 
shadows set item, documentation in /players/data/closed/miniquests/set/shadows/readme.txt
*/

#include "/players/data/defs.h"
#include "/players/data/ansi.h"
inherit "obj/armour.c";
string hood_toggle;
int hood;
string backup_title, backup_pretitle, backup_name, backup_cname;
query_btitle() { return backup_title; }
query_bpretitle() { return backup_pretitle; }
query_bname() { return backup_name; }
query_bcname() { return backup_cname; }
query_hood() { return hood_toggle; }
/*this is so that the player's title, pretitle and name are backed up so that
when they remove, drop, or put the hood down everything is put back the way its
supposed to be */

btitle() {
    return backup_title;
}
set_btitle(str) {
    backup_title = str;
}
bpretitle() {
    return backup_pretitle;
}
set_bpretitle(str) {
    backup_pretitle = str;
}
bname() {
    return backup_name;
}
set_bname(str) {
    backup_name = str;
}
bcname() {
    return backup_cname;
}
set_bcname(str) {
    backup_cname = str;
}
reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("cloak of shadows");
   set_alias("cloak");
   set_short(HIM+"C"+BLK+"loak of "+HIM+"S"+BLK+"hadows"+NORM);
   set_long(
      "A piece of armor with a great rent, you wonder what could make such a tear in such a fine piece of equipment.\n"
   );
   set_ac(3);
   set_type("cloak");  /* armor,helmet,boots,ring,amulet,shield,misc  */
   set_weight(2);
   set_value(200000);
   set_btitle("");
   set_bpretitle("");
   set_bname("");
   set_bcname("");
}

init() {
  add_action("hood_toggle", "hood");
  add_action("wear", "wear");
  add_action("remove", "remove");
  add_action("drop", "drop");
}

string short() {
  string shrt;
  shrt=short_desc;

    if(worn)
    	     shrt+=BLK+" ("+HIM+"worn"+BLK+")"+NORM;
    if(hood)
    return shrt+BLK+"{"+HIM+"~"+BLK+"}"+NORM;
    return shrt+" ";
  return shrt;
}

hood_toggle(str)
{
if(!str){
write("Syntax: hood up or down?\n");
return 1;
   }
if(str == "up"){
write("You flip the hood up to hide your face.\n");
hood = 1;
set_btitle(this_player()->query_title());
set_bpretitle(this_player()->query_pretitle());
set_bname(this_player()->query_name());
set_bcname(this_player()->query_cap_name());
this_player()->set_name("figure");
this_player()->set_cap_name("Figure");
this_player()->set_pretitle(BLK+"a "+HIM+"D"+BLK+"ark");
this_player()->set_title(HIM+"C"+BLK"loaked in "+HIM+"S"+BLK+"hadows"+NORM);
 return 1;    
  }  

if(str == "down"){
write("You flip your hood down so people can recognize you.\n");
 hood = 0; 
this_player()->set_name(query_bname());
this_player()->set_cap_name(query_bcname());
this_player()->set_pretitle(query_bpretitle());
this_player()->set_title(query_btitle());
return 1; 
}
} 

