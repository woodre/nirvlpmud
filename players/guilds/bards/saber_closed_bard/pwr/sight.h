/*
 *  True Speak: Sight
 *
 *    Scout - peek a direction
 *
 *  v3.0 by Saber / Geoffrey Z.
 *
 */

sight(str)  {
string SIGHT, SIGHT2, THERE, F1, F2, F3, F4, F5, COMMAND, short_str;
object TARG, MUSIC, MUSIC_ENV, POOL;
int n, v;

  if(!str)  {
    write("Sight: < scout > < travel > < scry > < true >\n");
    return 1;
        }

  if(sscanf(str, "%s %s", SIGHT, SIGHT2) < 2)  { sscanf(str, "%s", SIGHT); }

        
 /*  Peek to nearby room.  */

if(SIGHT == "scout")  {
          
  if(spell(-50,9,10) == -1)  return 0;

  if(!(INSTR->query_know_spell("sight_scout")))  {
    write("You have not yet learned the words of scouting.\n");
    return 1;
      }
  
  if(!SIGHT2)  {
    write("What direction do you want to scout?\n");
    write("Syntax: si scout < dir >\n");
    return 1;
      }

  if(SIGHT2 != "n"    && SIGHT2 != "north"      &&
     SIGHT2 != "e"    && SIGHT2 != "east"       &&
     SIGHT2 != "s"    && SIGHT2 != "south"      &&
     SIGHT2 != "w"    && SIGHT2 != "west"       &&
     SIGHT2 != "ne"   && SIGHT2 != "northeast"  &&
     SIGHT2 != "nw"   && SIGHT2 != "northwest"  &&
     SIGHT2 != "se"   && SIGHT2 != "southeast"  &&
     SIGHT2 != "sw"   && SIGHT2 != "southwest"  &&
     SIGHT2 != "u"    && SIGHT2 != "up"         &&
     SIGHT2 != "d"    && SIGHT2 != "down"       &&
     SIGHT2 != "in"   && SIGHT2 != "out"        &&
     SIGHT2 != "exit" && SIGHT2 != "enter")  {
     
     write("You can scout:\n"+
           "n, e, s, w, ne, nw, se, sw, u, d, in, out, exit and enter.\n");
     return 1;
      }

    write("\nYou play a tune upon your "+INST+" as you sing\n\n"+
          "    \""+BOLD+"Soun ski meso nuhi lahepo repapo"+NORM+"\"\n");
          
    say("\n"+tp+" plays a tune upon "+POSS+" "+INST+" as "+PRO+" sings\n\n"+
          "    \""+BOLD+"Soun ski meso nuhi lahepo repapo"+NORM+"\"\n");

  if(COLOR)  {
    tell_room(ENV,
      "\nNotes of "+HIR+"pulsing music"+NORM+" solidify and dance about the room.\n");
      }  else  {
    tell_room(ENV,
      "\nNotes of pulsing music solidify and dance about the room.\n");      
      }

  if(10 + (TP->query_attrib("wil") * 4) + ((1 + BLVL) / 6) < random(100) )  {
    write("\nThe music escapes your hold!\n\n");
    say("\nA note of music flies off into the sky.\n\n");
    call_other(TP,"add_spell_point",-10); 
    return 1; 
      }
  
  MUSIC = clone_object("/players/saber/closed/bard/itm/music.c");
  
  command(SIGHT2, MUSIC);
  
  if(present("music_note", ENV))  {
    write("Your music can not move to the "+SIGHT2+".\n");
    return 1;
      }
  
  write("\n"+BOLD+"You see music:"+NORM+"\n\n");
  
  THERE = call_other(environment(MUSIC),"long");
  MUSIC_ENV = first_inventory(environment(MUSIC));
  
   while(MUSIC_ENV)  {
     short_str = call_other(MUSIC_ENV, "short");
     if(short_str)  {  write(short_str+".\n");  }
     MUSIC_ENV = next_inventory(MUSIC_ENV);
        }

  write("\n\n");
  
  destruct(MUSIC);
  call_other(TP, "add_spell_points", -10);
  return 1;
  
        }

 
 /*  Peek to several nearby rooms.  */

if(SIGHT == "travel")  {
          
  if(spell(-50,9,25) == -1)  return 0;

  if(!INSTR->query_know_spell("sight_travel"))  {
    write("You have not yet learned the words of traveling.\n");
    return 1;
      }
  
  if(!SIGHT2)  {
    write("What directions do you want to travel?\n");
    write("Syntax: si travel < dir > < dir > < etc >\n");
    return 1;
      }

  F1 = F2 = F3 = F4 = F5 = "";
  
  if(sscanf(str, "%s,%s,%s,%s,%s", F1, F2, F3, F4, F5) == 5) {
    COMMAND = ({F1,F2,F3,F4,F5});
    move_music();
    return 1;
       }
    
  if(sscanf(str, "%s,%s,%s,%s", F1, F2, F3, F4) == 4) {
    COMMAND = ({F1,F2,F3,F4});
    move_music();
    return 1;
       }
    
  if(sscanf(str, "%s,%s,%s", F1, F2, F3) == 3) {
    COMMAND = ({F1,F2,F3});
    move_music();
    return 1;
       }
       
  if(sscanf(str, "%s,%s", F1, F2) == 2) {
    COMMAND = ({F1,F2});
    move_music();
    return 1;
       }
       
  if(sscanf(str, "%s", F1) == 1) {
    COMMAND = ({F1});
    move_music();
    return 1;
       }


    write("\nYou play a tune upon your "+INST+" as you sing\n"+
          "    \""+BOLD+"Soun ski meso nuhi lahepo repapo"+NORM+"\"\n"+
          "    \""+BOLD+"Gudo ski repapo paco ski ripo meli"+NORM+"\"\n");
          
    say("\n"+tp+" plays a tune upon "+POSS+" "+INST+" as "+PRO+" sings\n"+
          "    \""+BOLD+"Soun ski meso nuhi lahepo repapo"+NORM+"\"\n"+
          "    \""+BOLD+"Gudo ski repapo paco ski ripo meli"+NORM+"\"\n");

  if(COLOR)  {
    tell_room(ENV,
      "\nNotes of "+HIR+"pulsing music"+NORM+" solidify and dance about the room.\n");
      }  else  {
    tell_room(ENV,
      "\nNotes of pulsing music solidify and dance about the room.\n");      
      }

  if(10 + (TP->query_attrib("wil") * 4) + ((1 + BLVL) / 6) < random(100) )  {
    write("\nThe music escapes your hold!\n\n");
    say("\nA note of music flies off into the sky.\n\n");
    call_other(TP,"add_spell_point",-25); 
    return 1; 
      }
  
  MUSIC = clone_object("/players/saber/closed/bard/itm/music.c");
  
  write("\n"+BOLD+"You see music:"+NORM+"\n\n");

  for(v=0; v<sizeof(COMMAND); v++) {
 
   command(COMMAND[v],MUSIC);  
  
   THERE = call_other(environment(MUSIC),"long");
   MUSIC_ENV = first_inventory(environment(MUSIC));
  
    while(MUSIC_ENV)  {
     short_str = call_other(MUSIC_ENV, "short");
     if(short_str)  {  write(short_str+".\n");  }
     MUSIC_ENV = next_inventory(MUSIC_ENV);
        }

   write(BOLD+"*\n");
  
        }
  
  destruct(MUSIC);
  call_other(TP, "add_spell_points", -25);
  return 1;
  
        }
  
  
  /* Look to a different room */
  
  if(SIGHT == "scry")  {

  if(!INSTR->query_know_spell("sight_scry"))  {
    write("You have not yet learned the words for scrying.\n");
    return 1;
      }
  
  if(present("reflect_pool", ENV))  {
    write("There is already a reflecting pool here.\n");
    return 1;
        }
  
  if(spell(-50,12,40) == -1)  return 0;

  write("\n"+
    "You play a canticle upon your "+INST+" as you sing\n\n");

  say("\n"+
    tp+" plays a canticle upon "+POSS+" "+INST+" as "+PRO+" sings\n\n");
 
  tell_room(ENV,
       "     \""+BOLD+"Gu ski meso nuda jako soli"+NORM+"\"\n"+
       "     \""+BOLD+"Dakoli ski meli nuda jako crysea"+NORM+"\"\n");

  tell_room(ENV, 
          "\nA small cloud of silver mist comes forth from "+BOLD+"chaos"+NORM+".\n"+
          "\nIt begins to rain.\n\n"+
          "A "+BOLD+"dark pool"+NORM+" of water forms upon the ground.\n\n");
   
  if(10 + (TP->query_attrib("wil") * 4) + ((1 + BLVL) / 6) < random(100) )  {
    write("\nThe pool "+BOLD+"shimmers"+NORM+" and fades away.\n\n");
    say("\n"+tp+"'s pool "+BOLD+"shimmers"+NORM+" and fades away.\n\n");
    call_other(TP,"add_spell_point",-40); 
    return 1; 
      }
      
   POOL = clone_object("/players/saber/closed/bard/itm/reflect.c");
   move_object(POOL, ENV);
   
   call_other(TP,"add_spell_point",-40);
   return 1;
        }
        
        
  /* Gives player true sight */
  
  if(SIGHT == "true")  {

  if(!INSTR->query_know_spell("sight_true"))  {
    write("You have not yet learned the words for true sight.\n");
    return 1;
      }
  
  if(present("true_sight", TP))  {
    write("You already have true sight.\n");
    return 1;
        }
  
  if(spell(-50,14,30) == -1)  return 0;

  write("\n"+"You sing\n\n");

  say("\n"+tp+" sings\n\n");
 
  tell_room(ENV,
       "     \""+BOLD+"Dakoli ski meso mo li liyo soli"+NORM+"\"\n"+
       "     \""+BOLD+"Dakoli ski meya noko rufa juun toli"+NORM+"\"\n\n");

 if(COLOR)  {
     write("Your eyes "+HIB+"glow blue"+NORM+" with true sight!\n");
     say(tp+"'s eyes begin to "+HIB+"glow"+NORM+" a "+HIB+"dark blue"+NORM+"!\n");

       }  else  {

     write("Your eyes glow blue with true sight!\n");
     say(tp+"'s eyes begin to glow a dark blue!\n");
      }
   
  if(10 + (TP->query_attrib("wil") * 4) + ((1 + BLVL) / 6) < random(100) )  {
    write("\nYour true sight fades away.\n\n");
    say("\n"+tp+"'s eyes stop glowing.\n\n");
    call_other(TP,"add_spell_point",-30); 
    return 1; 
      }
      
   POOL = clone_object("/players/saber/closed/bard/itm/ts.c");
   move_object(POOL, TP);
   
   call_other(TP,"add_spell_point",-30);
   return 1;
        }

         
  command("li", TP);
  return 1;
       }


move_music() {
  
  for(v=0; v<sizeof(COMMAND); v++) {
    
  if((COMMAND[v]) != "n"     && 
     (COMMAND[v]) != "e"     && 
     (COMMAND[v]) != "s"     && 
     (COMMAND[v]) != "w"     &&
     (COMMAND[v]) != "u"     && 
     (COMMAND[v]) != "d"     && 
     (COMMAND[v]) != "ne"    && 
     (COMMAND[v]) != "nw"    &&
     (COMMAND[v]) != "se"    && 
     (COMMAND[v]) != "sw"    && 
     (COMMAND[v]) != "in"    && 
     (COMMAND[v]) != "out"   && 
     (COMMAND[v]) != "exit"  && 
     (COMMAND[v]) != "enter" && 
     (COMMAND[v]) != "") {

      write("You can travel "+COMMAND[v]+".\n");
      return 1;
        }
        }
        }
