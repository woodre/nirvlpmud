#include "/players/vertebraker/define.h"

/* moves the boy back to the wrong room
#define STABLE "/players/vertebraker/misc/s2"
*/
#define STABLE "/players/jaraxle/templar/rooms/s2"
#define DIR "/players/vertebraker/misc/h/"
#define SAVEPATH "players/vertebraker/misc/h/s/"

inherit NPC;

reset(x) 
{
   if(x) return;
   ::reset();
   set_name("simon");
   set_alias("stable_boy");
   set_race("human");
   set_short("Simon, the boy");
   set_long(
      "     Simon works in the castle stables under the direction of\n"+
      "Master Bolmont.  His straw colored hair is somewhat a mess, and\n"+
      "his piercing blue eyes seem to gaze dreamily into your soul.\n"+
      "His ability with horses is legendary even for one so young.  It\n"+
      "is said he has never been seen to leave the confines of the stable.\n"+
      "He can 'retrieve' a horse for you if you wish, or you can 'discharge'\n"+
      "your horse back to his care until you wish to ride again.\n");
   set_gender("male");
   set_level(10);
   set_hp(150);
   set_al(900);
   set_wc(14);
   set_ac(8);
   set_chat_chance(5);
   load_chat("Simon bounces a ball against the wall.\n");
   load_chat("Simon says: Maybe I should go check on the horses.\n");
   load_chat("Simon moves some hay around.\n");
}

init()
{
   ::init();
   add_action("discharge_it","discharge");
   add_action("retrieve_it","retrieve");
}

discharge_it()
{
   int x; object *inv; object h, k;
   k = present("KnightTemplar",TP);
   if(!k || present("warrior_gob", TP))
      {
      write("Simon says: You're not a knight!\n");
      return 1;
   }
   inv = all_inventory(USER);
   for(x=0;x<sizeof(inv);x++)
   if(inv[x]->query_owner() == TP && inv[x]->id("warhorse"))
      h = inv[x];
   if(!h)
      {
      write("Your horse is not here.\n");
      return 1;
   }
   if(TP->query_mounted() == h) command("dismount horse",TP);
   write("  You release your horse into the loving custody\n"+
      "  of Simon.  He gratefully takes the reins and leads\n"+
      "  "+h->QN+" into the stables.\n");
   k->set_horsed(0);
   h->save_me();
   /* Changed from /room/void.c - Feldegast 2/15/01 */
   move_object(h, "/players/vertebraker/misc/h/storage");
   destruct(h);
   return 1;
}

retrieve_it()
{
   object h, k;
   k = present("KnightTemplar",TP);
   if(!k || present("warrior_gob", TP))
      {
      write("Simon says: You aren't a Knight!\n");
      return 1;
   }
   if(query_ip_number(TP)[0..5] == "207.57")
   {
      write("Simon says: Oh.. You seem to have been banned.\n");
      return 1;
   }
   if(file_size("/"+SAVEPATH+TPRN+".o") < 1)
      {
      write("Simon says: You must a request a horse from the StableMaster first.\n");
      return 1;
   }
   if(k->query_horsed())
      {
      write("Simon says: You already have a horse.\n");
      return 1;
   }
   k->set_horsed(1);
   write("Simon nods at you, and walks into the stables.\n\n");
   h = clone_object(DIR+"horse");
   h->set_owner(TP);
   h->restore_me();
      h->set_long(
      "A stout, strong-looking warhorse with a growling demeanor and a\n" +
      "stern look on its face. A long muzzle and beautiful brown eyes\n"+
      "highlight its large head.  He snorts occasionally and seems to stare\n"+
      "directly at you. His legs have seen some exercise, and it looks as\n"+
      "though it is very powerful and fast.\n");
   MO(h,USER);
   write("Simon reappears holding "+h->QN+"'s reins in his hand.\n");
   write("Harker says: 'there will be a 300 coin fee for saddling up.'\n");
   if(TP->query_money() < 300)
      {
      write("Harker says: 'ya don't have enuff.  simon, take it back.'\n"+
         "Simon nods and leads it back into the stables.\n");
      MO(h,"/room/void");
      destruct(h);
      return 1;
   }
   TP->add_money(-300);
   write("Harker takes your money happily.\n");
   return 1;
}

load_horse(string x, string y)
{
   tell_room(USER,"Simon scampers out of the room.\n");
   call_out("return_with_horse",20,x+"#"+y);
   MO(TO,"/room/void");
   return 1;
}

return_with_horse(string str)
{
   string x,y; object d, h;
   sscanf(str,"%s#%s",x,y);
   MO(TO,STABLE);
   d = find_player(x);
   if(!d)
      {
      write_file(DIR+"l/Error",TPRN+" Error #001 "+ctime()+"\n");
      return 1;
   }
   if(!present(d,USER))
      tell_object(d,
      "Harker tells you:\n\n"+
      "  Yer horse is ready now at the stables.  It's waitin fer ya.\n");
   h = clone_object(DIR+"horse");
   h->set_color(y);
   h->set_owner(d);
   h->set_name("horse");
   h->set_gender("creature");
   h->set_long(
      "A stout, strong-looking warhorse with a growling demeanor and a\n" +
      "stern look on its face. A long "+y+" muzzle and beautiful brown eyes\n"+
      "highlight its large head.  He snorts occasionally and seems to stare\n"+
      "directly at you. His legs have seen some exercise, and it looks as\n"+
      "though it is very powerful and fast.\n");
   h->save_me();
   MO(h,USER);
   write_file(DIR+"l/Horse",x+" ** CONFIRM ** "+ctime()+"\n");
   tell_room(USER,"Simon returns with a warhorse.\n");
   tell_object(d,"Harker tells you:\n\n  Read the help files, will ya?\n");
   return 1;
}
