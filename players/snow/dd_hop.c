#define HOP "/players/snow/ITEMS/d_hop.c"
inherit "obj/treasure";
 
reset(arg)  {
  if(arg) return;
 
   set_id("hopper");
   set_short("A D-Hopper");
   set_long(
   "This a D-Hopper. In other words- it takes you where you want to go..\n"+
   "to check settings, type 'where'. After you type the command, you will \n"+
   "be instantly transported with a small sensation of movement. It's a\n"+
   "bit disorienting at first but the experienced D-Hopper quickly adjusts.\n"+
   "Good luck...\n");
   set_weight(0);
   set_value(0);
}
 
init()   {

if(this_player()->query_level() < 20) {destruct(this_object());}

  add_action("where", "where");
  add_action("hop","hop");
  add_action("geto","geto");
  }

where() {HOP->where(); return 1;}
hop(arg) {HOP->hop(arg); return 1;}
geto(arg) {HOP->geto (arg); return 1;}
