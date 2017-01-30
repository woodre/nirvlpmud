/* This cantrip will create one of many small items */

conjure(str)  {

string M, M2;

  if(spell(-50,0,10,this_object()) == -1)  return 0;

  if(!INSTR->query_cantrip("C5"))  {
    write("You have not yet learned this cantrip.\n");
    return 1;
      }

  if(((TP->query_attrib("int")+TP->query_attrib("wil"))*2)+LEVEL<random(102) )
    { write("Your cantrip fails.\n"); 
      call_other(TP,"add_spell_point",-random(15)); 
      return 1; }
  
  if(!str || str != "rose" && str != "clip" && str != "scarf" && str != "dagger")  {
     write("You may <cantrip> <conjure> a <clip> a <dagger> a <rose> or a <scarf>\n");
     return 1;
        }
  
  COINS = 10 + random(40);

  if(TP->query_money() < COINS)  {
    write("You need a few coins to do that...\n");
    return 1;  
          }
 
  if(str == "clip")   {  M = "/players/saber/stuff/clip.c";
                      M2 = "skyp\n      Un pieantious vysial appyr ah clyp";  }
  if(str == "dagger") { M = "/players/saber/closed/bard/itm/w/sdagger.c";
                      M2 = "mystal\n      To mis ne vas appyr razour de cyrstial"; }
  if(str == "rose")   { M = "/players/saber/closed/bard/itm/rose.c";
                      M2 = "aboye\n      Forr a spycial appyr crymsion de luv"; }
  if(str == "scarf")  { M = "/players/saber/closed/bard/itm/scarf.c";
                      M2 = "mylk\n      De flayr, de corth, de mystry sylk";  }
   
  move_object(clone_object(M),TP);

  if(COLOR)  {
    write("\nYou whisper\n\n     "+BOLD+"\"Conjour thy tres wythyn de "+M2+""+NORM+"\".\n"+
    "\nThere is a puff of "+HIB+"blue smoke"+NORM+" as a "+str+" appears in your hand.\n\n");
    say("\n"+tp+" whispers\n\n     "+BOLD+"\"Conjour thy tres wythyn de "+M2+""+NORM+"\".\n"+
    "\nThere is a puff of "+HIB+"blue smoke"+NORM+" as a small object appears in "+tp+"'s hand.\n\n");
      }  else  {
    write("\nYou whisper\n\n     "+BOLD+"\"Conjour thy tres wythyn de "+M2+""+NORM+"\".\n"+
    "\nThere is a puff of blue smoke as a "+str+" appears in your hand.\n\n");
    say("\n"+tp+" whispers\n\n     "+BOLD+"\"Conjour thy tres wythyn de "+M2+""+NORM+"\".\n"+
    "\nThere is a puff of blue smoke as a small object appears in "+tp+"'s hand.\n\n");
            }
            
  call_other(TP, "add_spell_point", -15);
  call_other(TP, "add_money", - COINS);
   return 1;
        }       
