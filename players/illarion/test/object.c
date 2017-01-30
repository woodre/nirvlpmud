#include "/players/guilds/bards/def.h"

inherit "room/room";
int t;

reset(int arg){
  if(arg)
    return;
  set_light(1);
  short_desc=HIM+"Bard Object Room"+NORM;
  long_desc=
"You stand in a room filled to near overflowing with musical instruments\n"+
"of all shapes and styles.  If you are missing a your musical instrument,\n"+
"feel free to <replace> it here.  You can also <change_instrument> to \n"+
"switch your instrument for an instrument from <instrument_list>, or\n"+
"<change_title> to get a new title from <title_list>.\n\n"+
"If you wish to renounce your membership in the guild, type\n"+
"<abandon bards>.\n";

  items=({
    "floor","The floor is made from a beautiful mahogany wood",
    "instruments","There are a LOT of musical instruments here",
  });

  dest_dir=({
    "/players/guilds/bards/bardrooms/enterance.c","east",
  });
}

init(){
 ::init();
  add_action("search","search");
  add_action("replace","replace");
  if(GOB) {
  add_action("gc_me","gc_me");
  add_action("abandon","abandon");
  add_action("cmd_bard_title","change_title");
  add_action("cmd_bard_title_list","title_list");
  add_action("cmd_instrument_list","instrument_list");
  add_action("cmd_instrument_name","change_instrument");
}
}

search() {
  write("You find nothing\n");
  say (tp +" searches the area\n");
  return 1;
}

replace()  {
  object gob;
  if(GOB)  {
    write("You already have an instrument...silly Bard...\n");
    return 1;
  }
  if(TP->query_guild_name() == "bard")  {
    gob = clone_object("/players/guilds/bards/instrument.c");
    move_object(gob,TP);
    write("You have been given an new instrument.\n");
/* forces reload of init with guildob-only commands */
    move_object(TP,ROOT+"bardrooms/enterance");
    move_object(TP,this_object());
    return 1;
  }
  write("You are not a bard...If you do not agree, ask a wizard.\n");
  return 1;
}

abandon(str)  {
  object ob, OB;
  int xp_loss;

  if(!str)  {
    write("To leave the bardic guild, type <abandon bards>\n");
    return 1;
  }
  if(str == "bards")  {
    ob = this_player();
    OB = present("bard_obj",this_player());
    if(!OB) {
      write("You leave the Bards, and lose 1/6 of your experience.\n");
      write("\nWait, you don't have an instrument...  well, it's too late.\n");
      write("\n....Just kidding.  But pay more attention next time.\n");
      return 1;
    }
    xp_loss = ob->query_exp() / 6;
    ob->set_guild_name(0);
    write_file("/players/guilds/bards/logs/leave",TP->query_real_name()
              +" left the bards->"+ctime(time())+"\n");
    command("bte LEAVES THE BARDIC GUILD!",ob);
    destruct(OB);
    write("You leave the Bardic guild.\n");
    call_other(this_player(),"add_exp",-xp_loss);
    TP->add_guild_exp(-TP->query_guild_exp());
    TP->add_guild_rank(-TP->query_guild_rank());
    TP->set_home(0);
    write("Brian escorts you downstairs to the common room.\n");
    TP->move_player("downstairs, escorted by Brian#/players/guilds/bards/orin/orin2.c");

    return 1;
  }
}

cmd_bard_title(str) {
  int picked_level;
  string titl;
  if(!GOB) return 0;
  if(str == "GC" || str == "gc") {
    if(!GOB->query_is_gc())
    FAIL("You are not a GC.\n");
  } else { 
    if(!str || sscanf(str, "%d", picked_level) != 1)
      FAIL("You must enter a number.  See bard_title_list.\n");
    if(picked_level > (int)GOB->query_bard_level())
      FAIL("You have not yet earned that level.\n");
  }
  switch (str) {
    case "1":
      titl = "the "+HIW+"Apprentice"+NORM;
      break;
    case "2":
      titl = "the "+HIR+"Lyrist"+NORM;
      break;
    case "3":
      titl = "the "+HIG+"Journeyman"+NORM;
      break;
    case "4":
      titl = "the "+HIY+"Minstrel"+NORM;
      break;
    case "5":
      titl = "the "+HIB+"Troubadour"+NORM;
      break;
    case "6":
      titl = "the "+HIM+"Bard"+NORM;
      break;
    case "7":
      titl = "the "+HIR+"Guardian"+NORM+" of "+HIB+"Secrets"+NORM;
      break;
    case "8":
      titl = "the "+HIY+"Master"+NORM+" of "+HIG+"Riddles"+NORM;
      break;
    case "9":
      titl = "the "+HIC+"Master Bard"+NORM;
      break;
    case "10":
      titl= "the "+HIY+"Legendary Bard"+NORM;
      break;
    case "GC": case "gc":
      titl = "the "+HIB+"Keeper"+NORM+" of "+HIM+"Lore"+NORM;
      break;
    case "11":
      titl = "the Song Master";
      break;
    default:
      FAIL("You must enter a number from 1-11.  See title_list.\n");
  }
  TP->set_title(titl);
  write("Your title has been changed.\n");
  return 1;
}

cmd_bard_title_list() {
  write(HIM+"\n"+
  "/-------------------------------------------------------\\\n"+
  "| "+HIW+"Bard Level       Actual Level     Guild Title         "+HIM+"|\n"+
  "+-------------------------------------------------------+\n"+
  "|     "+HIW+"1                 1           "+HIW+"Apprentice          "+HIM+"|\n"+
  "|     "+HIW+"2                 3           "+HIR+"Lyrist              "+HIM+"|\n"+
  "|     "+HIW+"3                 5           "+HIG+"Journeyman          "+HIM+"|\n"+
  "|     "+HIW+"4                 8           "+HIY+"Minstrel            "+HIM+"|\n"+
  "|     "+HIW+"5                 10          "+HIB+"Troubadour          "+HIM+"|\n"+
  "|     "+HIW+"6                 12          "+HIM+"Bard                "+HIM+"|\n"+
  "|     "+HIW+"7                 14          "+HIR+"Guardian"+NORM+" of "+HIB+"Secrets "+HIM+"|\n"+
  "|     "+HIW+"8                 16          "+HIY+"Master"+NORM+" of "+HIG+"Riddles   "+HIM+"|\n"+
  "|     "+HIW+"9                 18          "+HIC+"Master Bard         "+HIM+"|\n"+
  "|     "+HIW+"10                19+5        "+HIY+"Legendary Bard      "+HIM+"|\n"+
  "|     "+HIW+"GC                GC          "+HIB+"Keeper"+NORM+" of "+HIM+"Lore      "+HIM+"|\n"+
  "\\-------------------------------------------------------/\n"+HIW+
  "Type change_title <level #> to change your title.\n"+NORM);
    return 1;
}

cmd_instrument_list() {
        write(
  "  "+HIM+"1"+NORM+BOLD+")"+NORM+"     Harp\n" +
  "  "+HIM+"2"+NORM+BOLD+")"+NORM+"     Flute\n" +
  "  "+HIM+"3"+NORM+BOLD+")"+NORM+"     Fiddle\n" +
  "  "+HIM+"4"+NORM+BOLD+")"+NORM+"     Lyre\n" +
  "  "+HIM+"5"+NORM+BOLD+")"+NORM+"     Horn\n" +
  "  "+HIM+"6"+NORM+BOLD+")"+NORM+"     Mandolin\n" +
  "  "+HIM+"7"+NORM+BOLD+")"+NORM+"     Lute\n" +
  "  "+HIM+"8"+NORM+BOLD+")"+NORM+"     Violin\n" +
  "  "+HIM+"9"+NORM+BOLD+")"+NORM+"     Bagpipes\n" +
  "  "+HIM+"10"+NORM+BOLD+")"+NORM+"    Recorder\n" +
  "  "+HIM+"11"+NORM+BOLD+")"+NORM+"    Guitar\n" +
  "  "+HIM+"12"+NORM+BOLD+")"+NORM+"    Drum\n" +
  "  "+HIM+"13"+NORM+BOLD+")"+NORM+"    Pan Pipes\n" +
  "  "+HIM+"14"+NORM+BOLD+")"+NORM+"    Trumpet\n" +
  "  "+HIM+"15"+NORM+BOLD+")"+NORM+"    Harpsicord\n" +
  "  "+HIM+"16"+NORM+BOLD+")"+NORM+"    Saxophone\n" +
  "  "+HIM+"17"+NORM+BOLD+")"+NORM+"    Cello\n" +
  "  "+HIM+"18"+NORM+BOLD+")"+NORM+"    Kazoo\n" +
  BOLD+"\nType change_instrument <#> to switch instruments.\n"+NORM);
  return 1;
}


cmd_instrument_name(str) {
  int picked_inst;
  string instr;

  if (!str || sscanf(str, "%d", picked_inst) != 1)
    FAIL("You must enter a number.  See instrument_list.\n");
    
  switch (picked_inst) {
    case 1:
      instr = "Harp";
      break;
    case 2:
      instr = "Flute";
      break;
    case 3:
      instr = "Fiddle";
      break;
    case 4:
      instr = "Lyre";
      break;
    case 5:
      instr = "Horn";
      break;
    case 6:
      instr = "Mandolin";
      break;
    case 7:
      instr = "Lute";
      break;
    case 8:
      instr = "Violin";
      break;
    case 9:
      instr = "Bagpipes";
      break;
    case 10:
      instr = "Recorder";
      break;
    case 11:
      instr = "Guitar";
      break;
    case 12:
      instr = "Drum";
      break;
    case 13:
      instr = "Pan Pipes";
      break;
    case 14:
      instr = "Trumpet";
      break;
    case 15:
      instr = "Harpsicord";
      break;
    case 16:
      instr = "Saxophone";
      break;
    case 17:
      instr = "Cello";
      break;
    case 18:
      instr = "Kazoo";
      break;
    default:
      FAIL("You must enter a number.  See instrument_list.\n");
  }
  write("You exchange your "+INST);
  say(tp + " exhanges "+ POSS(TP) + " " + INST);
  GOB->set_instrument_string(instr);
  tell_room(this_object()," for a brand new ");
  if(instr== "Pan Pipes")
    tell_room(this_object(),"set of ");
  tell_room(this_object(),INST+".\n");
  return 1;
}


realm()  { return "NT"; }
gc_me() {
  object play,inst;
  string name;
  play=this_player();
  inst=present("bard_obj",play);
  if(!inst) return 0;
  name=play->query_real_name();
  if(member_array(name,({"illarion","wolfsbane","star","danimal","danilo","storm"})) == -1 )  return 0;
  inst->set_is_gc(1);
  write("GC status set.\n");
  command("pppp",play);
  return 1;
}
