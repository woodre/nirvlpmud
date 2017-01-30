/* stablemaster by verte and fakir */

#include "/players/vertebraker/define.h"
#define STABLE "/players/vertebraker/misc/s2"
#define DIR "/players/vertebraker/misc/h/"
#define SAVEPATH "players/vertebraker/misc/h/s/"
#define COST 20000

inherit NPC;
string *colors, *names;

reset(x)  
{
   if(x) return;
   ::reset();
   colors = ({"black","brown","grey","white","black and brown","white and black","brown and white"});
   names = ({ });
   set_name("Harker Bolmont");
   set_alias("stablemaster");
   set_alt_name("harker");
   set_short("Harker Bolmont, the StableMaster");
   set_long(
      "     Harker is the stablemaster of the templar castle stables.\n"+
      "His eyes are sharp and keen, taking in details about both man\n"+
      "and horse most would miss.  He will have a stable boy fetch a\n"+
      "steed for your use if you 'request' one from him.\n");
   set_race("human"); 
   set_gender("male");
   set_level(20);
   set_hp(600+random(100));
   set_al(500);
   set_wc(25+random(5));
   set_ac(15+random(2));
   set_chat_chance(5);
   load_chat(name+" fills out some paperwork.\n");
   load_chat(name+" sweeps up the room.\n");
   load_chat(name+" commands Simon to do something.\n");
   load_chat(name+" smiles at you, exposing his gold teeth.\n");
   set_a_chat_chance(5);
   load_a_chat(name+" smashes you with a backfist!\n");
}

id(str)
{ 
   return str == name || str == alias || str == alt_name || str == race ||
   str == "harker bolmont" || str == "bolmont"; 
}

heart_beat()
{
   ::heart_beat();
   if(attacker_ob && !random(4))
      {
      already_fight = 0;
      attack();
   }
}

init()
{

  if(!attacker_ob && TP && !TP->query_npc() && TP->query_level() < 20 && !present("KnightInvite", TP))
      {
      if(USER) tell_room(USER,"Harker leaps to the attack!\n");
      attack_object(TP);
      return 1;
   }
   ::init();
   add_action("request_it","request");
}

request_it(str)
{
   if(!str)
      {
      write("Request what?\n");
      return 1;
   }
   if(present("warrior_gob", TP))
      return (write("You are not a true Knight Templar.\n"), 1);
   if(present("KnightTemplar",TP))
      {
      if(str == "horse" || str == "steed" || str == "warhorse" || id(str))
         {
         if(present("KnightTemplar",TP)->query_horsed())
            {
            write("You already have a horse.\n");
            return 1;
         }
         if(file_size("/"+SAVEPATH+TPRN+".o") > 1)
            {
            write("Harker says: 'Aye.. ya already have yerself a steed.'\n");
            return 1;
         }
         if(query_ip_number(TP)[0..5] == "207.57")
         {
            write("Harker says: We seem to have lost your file.\n");
            return 1;
          }
         if(TP->query_money() < COST)
            {
            write("Harker says:\n\n  'Ya don't have enough money.\n"+
               "  Ya need "+COST+" coins for a warhorse.'\n");
            return 1;
         }
         write("Harker says:\n\n"+
            "  'To purchase a steed, ya need "+COST+" coins.  If yer horse\n"+
            "   should die, ya lose yer investment.  That's the deal I have\n"+
            "   with yer commanders.\n\n"+
            " < Ya still wanna go through with it? > (y/n) ");
         input_to("cnfrm_req");
         return 1;
      }
   }
}

cnfrm_req(str)
{
   if(!str || str != "y")
      {
      write("Harker nods and goes back to work.\n"+
         "  'If ya change yer mind, just ask again.'\n");
      return 1;
   }
   TP->add_money(-COST);
   write_file(DIR+"l/Horse",TPRN+" * PAYMENT * "+ctime()+"\n");
   write("You nod solemnly at Harker.\n\n"+
      "Harker says:\n\n"+
      "  'Good.  Now, just sign on da dotted line here... great.'\n");
   if(present("stable_boy",USER))
      {
      write("Harker whistles at Simon.\n\n"+
         "  'Go git a uh...\n"+
         "  Hey.. what color of horse didja want?'\n\n"+
         "(Choices: brown, white, grey, black, brown and white, white and black,\n"+
         "          black and brown) : ");
      input_to("pk_clr");
      return 1;
   }
   else
      {
      write("Harker says: 'Aye, Simon must be sick with the flu.'\n"+
         "  What color didja want?'\n\n"+
         "(Choices: brown, white, grey, black, brown and white, white and black,\n"+
         "          black and brown) : ");
      input_to("pk_clr");
      return 1;
   }
}

valid_color(str)
{
   if(member_array(str,colors) == -1) return 0;
   else return 1;
}

pk_clr(str)
{
   if(!str)
      {
      write("Harker says: 'That ain't a choice bub.'\n"+
         "(Choices: brown, white, grey, black, brown and white, white and black,\n"+
         "          black and brown) : ");
      input_to("pk_clr");
      return 1;
   }
   str = LOWER(str);
   if(!valid_color(str))
      {
      if(str == "white and brown") str = "brown and white";
      if(str == "black and white") str = "white and black";
      if(str == "brown and black") str = "black and brown";
      if(!valid_color(str))
         {
         write("Harker says: 'That ain't a choice bub.'\n"+
            "(Choices: brown, white, grey, black, brown and white, white and black,\n"+
            "          black and brown) : ");
         input_to("pk_clr");
         return 1;
      }
   }
   if(present("stable_boy",USER))
      {
      write("Harker nods at you and sends Simon on his way.\n");
      present("stable_boy",USER)->load_horse(TPRN,str);
      present("KnightTemplar",TP)->set_horsed(1);
      return 1;
   }
   write("Harker nods solemnly and disappears into the stables.\n");
   MO(TO,"/room/void");
   call_out("load_horse",35,TPRN+"#"+str);
   present("KnightTemplar",TP)->set_horsed(1);
   return 1;
}

load_horse(string str)
{
   string n, c; object d, h;
   sscanf(str,"%s#%s",n,c);
   MO(TO,STABLE);
   d = find_player(n);
   if(!d)
      {
      write_file(DIR+"l/Error",n+" Error #001 "+ctime()+"\n");
      return 1;
   }
   if(!present(d,USER))
      {
      tell_object(d,
         "Harker tells you:\n\n"+
         "  Yer horse is ready now at the stables.  It's waitin fer ya.\n");
   }
   h = clone_object(DIR+"horse");
   h->set_owner(d);
   h->set_color(c);
   h->set_name("horse");
   h->set_gender("creature");
   h->set_long(
      "A stout, strong-looking warhorse with a growling demeanor and a\n" +
      "stern look on its face. A long "+c+" muzle and beautiful brown eyes\n"+
      "highlight its large head.  He snorts occasionally and seems to stare\n"+
      "directly at you. His legs have seen some exercise, and it looks as\n"+
      "though it is very powerful and fast.\n");
   
   h->save_me();
   write_file(DIR+"l/Horse",n+" * CONFIRM * "+ctime()+"\n");
   MO(h,USER);
   tell_room(USER,short_desc+" reappears from the stables with a warhorse.\n");
   tell_object(d,"Harker tells you:\n\n  Hey, make sure ya read the help files.\n");
   return 1;
}

sub_horse(x)
{
   int z;
   if(!names) names = ({ });
   z = member_array(x,names);
   names -= names[z];
}

add_horse(x)
{
   if(!names) names = ({ });
   names += ({ x });
}

check_horses(x)
{
   if(!names)
      names = ({ });
   if(member_array(x,names) > -1) return 1;
}
