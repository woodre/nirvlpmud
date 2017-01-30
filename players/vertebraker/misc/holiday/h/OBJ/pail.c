#include "../std.h"

inherit "/obj/container";
string *mobs;

reset(x)
{
   mobs = ({ });
   if(x) return;
   set_name("pail");
   set_short("A jack-o-lantern pail "+BOLD+BLK+"("+HIR+"grinning"+BOLD+BLK+")"+NORM);
   set_long(
      "A cheap plastic pail, made in the shape of a grinning pumpking,\n"+
      "or jack-o-lantern.  It is a tacky orange color, with dark black\n"+
      "triangular eyes, and a wickedly weird mouth.\n"+
      "It can hold many things, from candy to weapons.\n"+
      "You can 'trickortreat' if you find somebody with a kind heart who has candy.\n");
   set_weight(1);
   max_weight = 10;
}


id(str)
{
   return str == "verte_halloween_pail" || str == "pail" || str == "jack-o-lantern"
   ||  str == "jack-o-lantern pail";
}

query_save_flag()
{
   return 1;
}

init()
{
   ::init();
   add_action("trick_or_treat","trickortreat");
}

trick_or_treat(str)
{
   string s;
   string one, two;
   object m;
   if(!present("costume",TP) || !present("costume",TP)->query_worn())
      {
      write("You must be wearing your costume!\n");
      return 1;
   }
   if(!str)
      {
      FAIL("Ask for a treat from who?\n");
      return 0;
   }
   m = present(str,ENV(TP));
   if(!m)
      {
      write("You don't see that here!\n");
      return 1;
   }
   if(!m->query_hp() && !sscanf(file_name(m),"%ssaber/food/%s",one,two))
      {
      write("That is not alive!\n");
      return 1;
   }
   if(m->query_alignment() < 0)
      {
      FAIL("  That might be a pretty bad move, trying to get candy from such\n"+
         "  an evil person.  Try someone good instead.\n");
      return 0;
   }
   if(member_array(m,mobs) != -1)
      {
      FAIL("  You've already asked for a treat from that one.\n");
      return 0;
   }
   s = m->QN;  if(!s) s = m->short();
   write("  You run up to "+s+" and yell:\n\n"+
      BOLD+"  T R I C K  -  O R  -  T R E A T !\n\n"+NORM+
      s+" smiles at you and tosses you a piece of candy.\n"+
      "You drop it within your pail.\n\n");
   TP->remote_say(TPN+" runs up to "+s+" and yells:\n\n"+
      BOLD+"  T R I C K  -  O R  -  T R E A T !\n\n"+NORM+
      s+" smiles at "+TPN+" and tosses "+objective(TP)+" a piece of candy.\n");
   MO(CO(PATH+"OBJ/candy"),TO);
   mobs += ({ m });
   return 1;
}
