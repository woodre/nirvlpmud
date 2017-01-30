/* This cantrip will summon up a temporary object that will both serve as
   a light source and display dancing fire messages */

dance()  {

  if(spell(-50,0,10,this_object()) == -1)  return 0;
  
  if(!INSTR->query_cantrip("C6"))  {
    write("You have not yet learned this cantrip.\n");
    return 1;
      }

  if(present("dancing_lights", ENV))  {
    write("There is already a dancing lights cantrip active in this area.\n");
    return 1;
      }
  
  if(((TP->query_attrib("int")+TP->query_attrib("wil"))*2)+LEVEL<random(102) )
    { write("Your cantrip fails.\n"); 
      call_other(TP,"add_spell_point",-random(15)); 
      return 1; }
  
    move_object(clone_object("/players/saber/closed/bard/itm/dancing_lights.c"),
                ENV);
    
    if(COLOR)  {
      write("\nYou whistle a tune as you trace "+HIR+"crimson runes"+NORM+" of fire.\n"+
        "Three balls of "+HIR+"fire"+NORM+" form and begin to whirl.\n\n");
      say("\n"+tp+" begins to whistle as "+PRO+" traces "+HIR+"crimson runes"+NORM+" of fire.\n"+
        "Three balls of "+HIR+"liquid fire"+NORM+" form and begin to whirl.\n\n");
    }  else  {
      write("\nYou whistle a tune as you trace crimson runes of fire.\n"+
        "Three balls of fire form and begin to whirl.\n\n");
      say("\n"+tp+" begins to whistle as "+PRO+" traces crimson runes of fire.\n"+
        "Three balls of liquid fire form and begin to whirl.\n\n");
    }
              
  call_other(TP, "add_spell_point", -10);
  return 1;
        }
