#include "std.h"
 int shield, notin;
init() {
  add_action("on"); add_verb("on");
  add_action("off"); add_verb("off");
  add_action("out"); add_verb("out");
   add_action("adv","adv");
  add_action("guild"); add_verb("guild");
  add_action("church","church");
  add_action("hotel","hotel");
  add_action("castle","castle");
  add_action("post"); add_verb("post");
  add_action("strip","strip");
  add_action("wizzes","wizzes");
add_action("setguild","setguild");
  set_light( 1);
  if(this_player()->query_real_name() != "emerson" && shield == 1) {
  write("You feel an electric shock and see a flash of green light as\n");
  write("you rebound off the defense shield.\n");

  if (notin == 1) {
  write("Emerson is not in or on another job right now, please leave a\n");
  write("message at the post office.\n");
  }
  this_player()->move_player("off the shields#room/church");
 }
}
static on() {
   shield = 1;
   write("shields activated.\n");
   return 1;
   }
static off() {
   if (call_other(this_player(), "query_real_name", 0) != "emerson") {
  write("You are not allowed to do that!!!!!!!\n");
    return 1;
    }
   shield = 0;
   notin = 0;
   write("shields deacivated.\n");
   return 1;
   }
out() {
   shield = 1;
   notin = 1;
   write("shields on, out message on.\n");
   return 1;
   }

 short() {
   return "Emerson's Mopar Heaven";
  }
 long() {
 write("shields are at " + shield + "   not in message is at " + notin + "\n");
 write(""+
   "This is Emerson's garage, which looks like a Mopar Heaven!\n" +
    "There are Mopars everywhere! Each in verious states of disrepair.\n" +
    "Maybe someday Emerson will get around to fixing them.\n");
write("Obvious exits are: Church, Post, Hotel, Guild, Castle, Adv.\n");
  }
adv() {
  call_other(this_player(), "move_player", "#room/adv_inner.c");
   return 1;
}
church() {
  call_other(this_player(), "move_player", "church#room/church.c");
  return 1;
  }
hotel() {
call_other(this_player(), "move_player", "hotel#players/boltar/hotel/hotel.c");
return 1;
}
setguild() {
this_player()->set_guild_name(0);
return 1;
}
guild() {
  call_other(this_player(), "move_player", "#players/hawkeye/closed/guild/guild_room.c");
  return 1;
 }
strip(str) {
object ob, target;
if (!str) return 0;

target = find_living(str);
if (str == "me") target = this_player();
if (str == "here") target = environment(this_player());
if (!target) {
write ("There is no such living creature.\n");
return 1;
}
write ("Inventory of ");
if (str == "here") write (target->short()+" : ");
if (str != "here") write (capitalize(target->query_real_name())+" : ");
write ("( "+file_name(target)+" )\n");
write ("\n");
   ob = first_inventory(target);
    while(ob) {
if (ob->short())
write (ob->short()+" : ("+file_name(ob)+")\n");

  else
write ("Invisible Object : ("+file_name(ob)+")\n");
  ob = next_inventory(ob);
    }
return 1;
}

wizzes() {
object list;
int i, level, invis ;
string name,ed,tab;
list = users();
write("Name"+"\t\t"+"Level"+"\t"+"Invis"+"\t"+"Edit\n");
for (i=0; i<sizeof(list);i++)
{
name = capitalize ( call_other(list[i],"query_real_name"));
level= list[i]->query_level();
invis = list[i]->query_invis();
if(invis>999){invis=999;
}
ed = " ";
if (in_editor(list[i]) )
{
ed = "Ed";
}
tab = "\t";
if (strlen(name)<8){tab="\t\t";
	}
   if (level>19)
  {
write (name +tab+level+"\t"+invis+"\t"+ed+"\n");
   }
  }
return 1;
}
castle() {
call_other(this_player(), "move_player", "castle#players/emerson/rooms/enter");
return 1;
}
post(){
  object mobj;
/*
   mobj = clone_object("/obj/mail_reader.c");
   move_object(mobj, this_player());
*/
move_object(this_player(), "room/post");
   return 1;
  }
