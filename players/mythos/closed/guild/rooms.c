#include "/room/clean.c"
#include "/players/mythos/closed/guild/def.h"
 int shield;
 string owner, desc;
 string one, two, three, four, five;
init() {
if(!present("zzzb")) { 
  move_object(clone_object("/players/mythos/closed/guild/zzzb.c"),this_object()); }
  if(pp) { pp->set_defence(0);}
  add_action("chamber","chamber");
  add_action("library","library");
  add_action("slib","library_annex");
  add_action("tokyo","tokyo");
  add_action("desert","desert");
  add_action("church","church");
  add_action("hotel","hotel");
  add_action("forbidden","forbidden");
  add_action("shop","shop");
  add_action("portal","portal");
  add_action("assembly","assembly");
  add_action("advance","advance");
  add_action("lockers","lockers");
  add_action("post","post");
  add_action("shrine","shrine");
  add_action("daycare","daycare");
  if(tpn == owner) {
  add_action("add_descrip","add_descrip"); 
  add_action("store","store");
  add_action("restore","restore");
  add_action("invite","invite");
  add_action("list","list");
  add_action("on","on");
  add_action("kesu","off");}
if(tpn != owner && shield == 1) {
write("You may not enter.\n");
  this_player()->move_player("off the shields#players/mythos/enterance.c");}
  if(pp) { move_object(clone_object("/players/mythos/closed/guild/rob.c"),tp); }
 }
 
reset(arg) {
  if(!present("guildboard")) {
  move_object(clone_object("/players/mythos/closed/guild/board.c"),this_object());
  }
  if(arg) return;
  set_light(1); 
  } 

static on() {
   shield = 1;
   write("shields activated.\n");
   return 1;}
   
static kesu() {
   if (tpn != owner) {
   write("You cannot do that.\n");
    return 1;}
   shield = 0;
   write("shields deactivated.\n");
   return 1;
   }

 short() { return HIB+capitalize(owner)+"'s room"+NORM;}
 
long() {
if(desc != "") { write(""+desc+"\n");}
else {
write("The owner <"+owner+"> may do the following:\n"+
      "    add_descrip  store  restore  invite  on  off\n"); }
 write("You may exit: assembly, chamber, church, hotel, library, library_annex,\n"+
 "              lockers, portal, post, shop, shrine, tokyo, daycare, advance.\n"+
 "              forbidden, desert\n");}
  
slib() {
if(!present(fear,tp)) {  write("You may not go that way.\n"); return 1;}
  call_other(this_player(), "move_player", "slib#players/mythos/closed/guild/seclib.c");
   return 1;   }
   
church() {
  call_other(this_player(), "move_player", "church#room/church.c");
  return 1;}
  
portal() {
tp->add_spell_point(-20);
call_other(this_player(), "move_player", "portal#players/saber/ryllian/portal.c");
 return 1;}
 
hotel() {
call_other(this_player(), "move_player", "hotel#players/boltar/hotel/hotel.c");
return 1;}

post(){
   call_other(this_player(), "move_player","post#room/post");
   return 1;}

desert() { 
   call_other(this_player(), "move_player","desert#players/mythos/droom/desert.c");
   return 1;}
  
   
chamber(){
   call_other(this_player(), "move_player", "chamber#players/mythos/enterance.c");
  return 1;}
  
shop(){
call_other(this_player(), "move_player", "shop#room/shop");
return 1;}

library() {
  call_other(this_player(),"move_player","library#players/mythos/lroom/hall.c");
return 1;}

assembly() {
  if(!present(fear,tp)) {  write("You may not go that way.\n"); return 1;}
  call_other(this_player(),"move_player","hall#players/mythos/closed/guild/assembly.c");
  return 1;}
  
shrine() {
    call_other(this_player(),"move_player","shrine#players/mythos/aroom/shrinear3.c");
return 1;}

lockers() { 
  call_other(this_player(),"move_player","lockers#players/catwoman/tl.c");
return 1;}

tokyo() {
  call_other(this_player(),"move_player","tokyo#players/mythos/mroom/narita.c");
return 1;}  

invite(str) {
string name;
object ob, invit;
  if(shield ==  1) { write("You must take the shields off.\n"); return 1;}
  if(!str) { write("Who do you wish to invite?\n"); return 1;}
  if(tsp < 55+random(5)) { write("You need more energy.\n"); return 1; }
  name = str;
  ob = find_player(name);
  if(ob && (environment(ob)->realm() != "NT") && !ob->query_invis()) {
  if(present("black_orb",ob)) { command("drop black_orb",ob);}
  invit = clone_object("/players/mythos/closed/guild/invite.c");
  invit->set_ask(tpn);
  move_object(invit,ob);
  write("You invite "+str+"\n");
  return 1;}
  write("That person is either not here or not in a teleportable place!\n");
return 1;}

add_descrip() {
write("Use ** to end the description and use @@ to cancel.\n"+
      "Understand that most screens are set to 80 chars in length.\n"); 
write(">> ");
desc = capitalize(owner)+"'s Room\n";
input_to("descrip");
return 1;}

descrip(str) {
  if(str == "**") {
  save_object("players/mythos/closed/guild/room/"+owner);
  write("Description done.\n");
  return 1;}
  if(str == "@@") { 
  desc = "";
  write("Description canceled.\n"); return 1;}
  desc += str;
  desc += "\n";
  write(">> ");
input_to("descrip");
return 1;}

set_descr(str) {
  desc = str; }

set_owner(str) { 
  owner = str; 
  save_object("players/mythos/closed/guild/room/"+owner);
  return 1;}

store() {
object ob;
string throw;
int area;
int l;
if(one && two && three && four && five) { write("No storage left.\n"); return 1;}
ob = all_inventory(this_object());
for(l=0;l<sizeof(ob);l++) {
if(!(ob[l]->query_gsave())) { 
  if(ob[l]->short()) {write(ob[l]->short()+"  [unsavable here]\n");} }
  else { 
  if(!(one)) { sscanf(object_name(ob[l]),"%s#%s",one); area = 1;}
  else { 
  if(!(two)) {sscanf(object_name(ob[l]),"%s#%s",two); area = 2;}
  else { 
  if(!(three)) {sscanf(object_name(ob[l]),"%s#%s",three); area = 3;}
  else { 
  if(!(four)) {sscanf(object_name(ob[l]),"%s#%s",four); area = 4;}
  else { 
  if(!(five)) {sscanf(object_name(ob[l]),"%s#%s",five); area = 5;}
  else { write("No storage left.\n"); return 1;} 
  }}}}
  ob[l]->save_thing("players/mythos/closed/guild/room/"+owner+area);
  save_object("players/mythos/closed/guild/room/"+owner);
  write(ob[l]->short()+BLU+"  <SAVED>\n"+NORM);
  destruct(ob[l]);
  } }
return 1;}

restore() {
object obs;
if(!one && !two) { write("Nothing to restore.\n"); return 1;}
if(one) {
obs = clone_object("/"+one+".c");
obs->restore_thing("players/mythos/closed/guild/room/"+owner+"1");
move_object(obs,this_object()); 
if(obs->weapon_class()) { obs->cleanup(); }
write(obs->short()+RED+" [restored]\n"+NORM);}
if(two) {
obs = clone_object("/"+two+".c");
obs->restore_thing("players/mythos/closed/guild/room/"+owner+"2");
move_object(obs,this_object()); 
if(obs->weapon_class()) { obs->cleanup(); }
write(obs->short()+RED+" [restored]\n"+NORM);}
if(three) {
obs = clone_object("/"+three+".c");
obs->restore_thing("players/mythos/closed/guild/room/"+owner+"3");
move_object(obs,this_object()); 
if(obs->weapon_class()) { obs->cleanup(); }
write(obs->short()+RED+" [restored]\n"+NORM);}
if(four) {
obs = clone_object("/"+four+".c");
obs->restore_thing("players/mythos/closed/guild/room/"+owner+"4");
move_object(obs,this_object()); 
if(obs->weapon_class()) { obs->cleanup(); }
write(obs->short()+RED+" [restored]\n"+NORM);}
if(five) {
obs = clone_object("/"+five+".c");
obs->restore_thing("players/mythos/closed/guild/room/"+owner+"5");
move_object(obs,this_object()); 
if(obs->weapon_class()) { obs->cleanup(); }
write(obs->short()+RED+" [restored]\n"+NORM);}
one = two = three = four = five = 0;
save_object("players/mythos/closed/guild/room/"+owner);
rm("/players/mythos/closed/guild/room/"+owner+"1.o");
rm("/players/mythos/closed/guild/room/"+owner+"2.o");
rm("/players/mythos/closed/guild/room/"+owner+"3.o");
rm("/players/mythos/closed/guild/room/"+owner+"4.o");
rm("/players/mythos/closed/guild/room/"+owner+"5.o");
return 1;}

list() {
if(!one && !two && !three && !four && !five) { 
write("Nothing to restore.\n"); return 1;}
write("Storage:\n");
write(one);
write("\n");
write(two);
write("\n");
write(three);
write("\n");
write(four);
write("\n");
write(five);
write("\n");
return 1;}

restore_owner(str) { 
  if(!restore_object(str)) { 
    desc = ""; one = two = three = four = five = 0; }
}

daycare() {
  this_player()->move_player("daycare#players/boltar/sprooms/daycare.c");
return 1;}

advance() {
  this_player()->move_player("advance#room/adv_guild.c");
return 1;}

forbidden() { 
  this_player()->move_player("forbidden#players/mythos/closed/guild/forest/rooms/hunter.c");
return 1;}
