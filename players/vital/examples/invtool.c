#pragma combine_strings

inherit "obj/treasure";


void reset(int arg) {
  if(arg) return;
  set_id("tool");
  set_short("A full inventory tool");
  set_long("This tool can be used to view the full inventory of a\n"+
           "player, including all containers.\n"+
           "Syntax:  INV <who> (caps needed)\n");
}

void init() {
   if(this_player()->query_level() >=21)
      add_action("cmd_INV","INV");
   return;
}
void full_inventory(object ob,string indent) {  
   object *inv;
   int size,x;
   string sh;
   if(!indent) indent="";
   inv=all_inventory(ob);
   size=sizeof(inv);
   sh=(string)ob->short();
   write(indent+(sh?sh:"INVIS")+"  <"+file_name(ob)+">\n");
   if(!size)
      return;
   else
      for(x=0;x<size;x++)
         full_inventory(inv[x],indent+"    ");
   return;
}
int cmd_INV(string str) {
   object who;
   if(!str) {
      notify_fail("INV who?\n");
      return 0;
   }
   who=find_player(str);
   if(!who) {
      notify_fail("There is no "+str+" online.\n");
      return 0;
   }
   full_inventory(who,"");
   return 1;
}
