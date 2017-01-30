/* a handheld 'Vortex' in which one may darken the room by one.
   There seems to be a ton of items that do the oppiset.*/
inherit "/obj/treasure.c";
#define tp this_player()->query_name()
#include "/players/sami/mdefine.h"

int LIGHT;
reset(arg)
{   if (arg) return;
LIGHT = 0;
   SetMultipleIds( ({ "vortex", "dtorch_vortex", }) );
   set_short("Mechanical "+MAG+"Vortex"+NORM+"");
   set_long("Gears and wires twisted in some kind of garbled manner. Light seems to glisten\n"+
     "on its sleek surface. An inscription reads : Created by the Dark one in the\n"+
     "palace of the Underworld to eradicate the light. Simply "+BOLD+HIK+"expand"+NORM+" and "+BOLD+HIY+"compress"+NORM+" \n"+
     "the vortex. carful not to "+HIR+"crush"+NORM+" the vortex.\n");
	 set_weight(1);/*To be sold in shop for 15,000 coins.*/
   set_value(100);
   set_light(0);   }

init()
{  
   if( present("dtorch_vortex 2") ) {
     call_out("crush_vortex", 1, "vortex");
   }

   add_action("expand_vortex", "expand");
   add_action("compress_vortex","compress"); 
#if 0
   add_action("no_give","give");
   add_action("prevent_insert","bag");
   add_action("no_drop","drop");	
#endif
   add_action("crush_vortex","crush");
   }

/*function to darken room*/
expand_vortex(str)  {
if(str == "vortex") {
if(LIGHT == -1){
  write("The shadows have already been expanded.\n");
  return 1;
}
if( this_player()->query_spell_point() < 100 ) {
  write("You lack the energy required to expand the vortex.\n");
  return 1;
}
write("The "+MAG+"vortex"+NORM+" releases"+HIK+" shadows"+NORM+" to engulf your surroundings.\n");
say(tp+" forces the"+MAG+"vortex"+NORM+" to expand.\n");
set_light(-2);
LIGHT = -1;
TPRSP(-100);
    return 1;   }
}
/*function to restore the light*/
compress_vortex(str)  {
if(str == "vortex")  {
if(LIGHT == 0) {
  write("The shadows remain trapped in the "+MAG+"vortex"+NORM+".\n"); return 1; }
write("The shadows "+HIY+"recede"+NORM+" back into the "+MAG+"vortex"+NORM+".\n");
say(tp+" extinguishes the torch.\n");
set_light(2);
LIGHT = 0;
  return 1;
}
}
#if 0
no_drop(str) {
        if(str == "vortex")
        {
		
                write("This item is too precious to discard.\n");
				
                return 1;
        }
        
        if(str == "miniature vortex")
        {
                write("This item is too precious to discard.\n");
                return 1;
        }
}
#endif
give() { return 0; }/*to insure no give, no drop, no bag*/
bag()  { return 1; }
drop() { return 1; }
#if 0
prevent_insert()
{
  write("You don't want to ruin the vortex.\n");
  return 1;
}
no_give(str)
{
  string pre, post;
        if(str == "vortex")
        {
                write("This item is too precious to give away.\n");
                return 1;
        }
        
        if(str == "miniature vortex")
        {
                write("This item is too precious to give away.\n");
				destruct(this_object());
                return 1;
        }
  if (sscanf(str, "%s to %s", pre, post) == 2) {
    write("You cannot give your "+MAG+"vortex"+NORM+" to " + post + "!\n");
    return 1;
  }
}
#endif

crush_vortex(str)
{
  object ob;

  if( !str || str != "vortex" ) {
    return 0;
  }
  if( this_player() )
    ob = this_player();
  else
    ob = environment();

  if(ob && (str == "vortex" || str == "miniature vortex") )
  {
    tell_object(ob, "The vortex crumbles to dust in your hands, slipping through your fingers.\n");
    destruct(this_object());
    this_player()->add_money(2500 + random(500));
    return 1;
  }
}
		
