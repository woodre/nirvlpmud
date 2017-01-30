/*  Forbin | Create date:  sep2002.03 | Last mod:  sep2002.03  */

#include "/players/forbin/define.h"
inherit "/players/forbin/closed/std/room.c";

int shield;

reset(arg) 
{
  if(!present("display")) { move_object(clone_object("/players/cosmo/hslist/svds_new.c"), this_object()); }
  if(arg) return;

  short_desc = "A Dark Room";
  long_desc =  "\n";
  set_light(1);
  add_property("NT");
}

short() { return HIR+"Ey"+HIW+"e o"+HIK+"f th"+HIW+"e St"+HIR+"orm "+HIW+":: "+HBBLU+HIY+"RBC Center"+NORM+NORM; }
 
init() 
{
  ::init();
  if(this_player()->query_real_name() == "forbin") 
  {
    add_action("shield_on", "on");
    add_action("shield_off", "off");
    add_action("scry", "scry");
    add_action("gaze", "gaze");
    add_action("cha", "chamber");
    add_action("hot", "hotel");
    add_action("inn", "inner");
    add_action("loc", "lockers");
    add_action("mot", "motel");
    add_action("pos", "post");
    add_action("sho", "shop");
    add_action("war", "warp");
    add_action("pestilence_workroom", "pesty");
    add_action("backup_login", "cloneall");
  }
  add_action("chu", "church");
  add_action("fen", "fence");
  add_action("gre", "green");
  add_action("bf", "gbf");
  add_action("no_dest", "destruct", 4);
  if(this_player()->query_real_name() != "forbin" && shield == 1) 
  {
    write(HIY+"Forbin is either busy working, or away at this time.\n"+
          "Try sending him a "+HIW+"tell"+HIY+" or leaving a "+HIW+"mudmail"+HIY+".\n"+NORM);
    if(find_player("forbin") && (string)this_player()->query_real_name() != "forbin")
    {
      tell_object(find_player("forbin"), BLINK+HIY+(string)this_player()->query_real_name()+" just tried to enter your workroom.\n"+NORM);
    }
    tell_room("/room/vill_green.c", capitalize(this_player()->query_real_name())+" falls from the sky and lands hard!  "+HIW+"><>< "+HIR+"CRUNCH"+HIW+" ><><"+NORM+"\n");
    move_object(this_player(), "/room/vill_green");
  }
}

/* ----- SHIELD ON AND OFF FUNCTIONS ------------------------------ */
shield_on() 
{
  write(HIY+"Shields are now "+HIW+"activated"+HIY+"!\n"+NORM);
  shield = 1;
    return 1; 
}

shield_off() 
{
  write(HIY+"Shields are now "+HIW+"deactivated"+HIY+"!\n"+NORM);
  shield = 0;
    return 1; 
}

/* ----- CAN'T DEST ME FOO! --------------------------------------- */
no_dest(str)
{
  if(str == "forbin") 
  {
    tell_object(find_player("forbin"),HIG+"Your "+HIW+"dest"+HIG+" field flashes.\n"+
               "Attempt to dest by:  "+this_player()->query_real_name()+"\n"+NORM);
      return 1;
  }
}

/* ----- RESTORES OR CLONES LOGIN LOADS --------------------------- */
backup_login()
{
  if(present("fortool", this_player())) 
  { 
    destruct("fortool", this_player());      
    move_object(clone_object("/players/forbin/closed/wiztool/fortool.c"), this_player());
  }
  else move_object(clone_object("/players/forbin/closed/wiztool/fortool.c"), this_player());
  if(present("mailread", this_player())) 
  { 
    destruct("mailread", this_player());      
    move_object(clone_object("/obj/mail_reader"), this_player());
  }
  else move_object(clone_object("/obj/mail_reader"), this_player()); 
    return 1;
}

/* ----- USED TO VIEW A PLAYER'S INVENTORY ------------------------ */
scry(string str) 
{
  object person,ob,special;
  if(!str) { write("Usage: "+HIW+"scry "+HIY+"<"+HIW+"living"+HIY+">"+NORM+"\n"); return 1; }
  person = find_player(str);
  if(!person) person=find_living(str);
  if(!person) { write(HIY+str+" can not be found.\n"+NORM); return 1; }
  write("Concentrating, you close your eyes and see: \n");
  person->long();
  special=first_inventory(person);
  while(special) 
  {
    string extra_str;
    extra_str=special->extra_look();
    if(extra_str) write(extra_str+".\n");
    special=next_inventory(special);
  }
  write(capitalize(person->query_pronoun())+" is carrying: \n");
  ob = first_inventory(person);
  while (ob)
  {
    string sh;
    sh = call_other(ob, "short");
    if (sh)
    write(sh + ".\n");
    ob = next_inventory(ob);
  }
    return 1;
}

/* ----- USED TO VIEW A PLAYER'S LOCATION ------------------------- */
gaze(string str) 
{
  object person;
  object ob;
  if(!str) { write("Usage: "+HIW+"gaze "+HIY+"<"+HIW+"living"+HIY+">"+NORM+"\n"); return 1; }
  person=find_player(str);
  if(!person) person=find_living(str);
  if(!person) { write(HIY+str+" can not be found.\n"+NORM); return 1; }
  write("Concentrating, you close your eyes and see: \n");
  environment(person)->long();
  ob = first_inventory(environment(person));
  while (ob) 
  {
    string sh;
    sh=ob->short();
    if(sh) write(sh + ".\n");
    ob=next_inventory(ob);
  }
    return 1;
}


/* ----- EXIT LOCATIONS ------------------------------------------- */
 bf() { this_player()->move_player("emcampment#/players/fred/closed/bloodfist/r/armory.c"); return 1; }
cha() { this_player()->move_player("chamber#/players/mythos/enterance"); return 1; }
chu() { this_player()->move_player("church#room/church.c"); return 1; }
fen() { this_player()->move_player("chainlink fence#room/south/sforst4.c"); return 1; }
gre() { this_player()->move_player("green#room/vill_green.c"); return 1; }
hot() { this_player()->move_player("hotel#players/boltar/hotel/hotel.c"); return 1; }
inn() { this_player()->move_player("inner#room/adv_inner.c"); return 1; }
kea() { this_player()->move_player("keats#players/forbin/hyperion/keats/RMS/kcircle_main.c"); return 1; }
loc() { this_player()->move_player("lockers#players/catwoman/tl.c"); return 1; }
mot() { this_player()->move_player("motel#players/boltar/hotel/motel.c"); return 1; }
pos() { this_player()->move_player("post office#room/post.c"); return 1; }
sho() { this_player()->move_player("shop#room/shop.c"); return 1; }
war() { this_player()->move_player("warp#players/eurale/RMS/warp.c"); return 1; }
pestilence_workroom() { this_player()->move_player("to the workroom of Pestilence#players/pestilence/workroom.c"); return 1; }
