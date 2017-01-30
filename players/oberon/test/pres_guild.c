inherit "room/room";
/******************************************************************************
 * Program: pres_guild.c
 * Path: /room
 * Type: Room
 * Created: Apr 08, 2014 by Dragnar
 *
 * Purpose: Room that advances players prestige levels.
 * 
 * History:
 *          04/08/2014 - Gnar
 *            Created
 *          09/30/2016 - Gnar - Updated to be able to handle multiple prestige guilds.
 ******************************************************************************/

#include <ansi.h>
#include "/obj/player/prestige.h"

#define HOLOGRAM "/room/pres_hologram.c"
#define BANKD    "/players/earwax/bank/bankd.c"

reset(arg) {
          
  if(arg) return;
  
  short_desc = "The prestige adventurers' guild";
  set_light(1);
  items=({
    "floor","A beautiful marble floor with "+GRN+"swirl patterns"+NORM,
    "patterns","A circular pattern that swirls in a clockwise direction",
    "marble","&floor&",
    "walls","The walls are made from delicate wood paneling imported from foreign lands",
    "wall","&walls&",
    "artwork","An oil painting of a grand wizard hangs on the wall",
    "painting", "It looks like it was from the renaissance",
    "light", "Silver with engravings embedded with gemstones",
    "gemstones","Mostly "+RED+"garnets"+NORM+" with a few "+BLU+"sapphires"+NORM,
    "gemstone","&gemstones&",
    "light fixture","&light&",
    "fixture","&light&",
    "silver","&light&",
    "garnet",RED+"Blood red, the gem refracts the light and makes the room glitter"+NORM,
    "sapphire",BLU+"A deep blue, the gems glitter and sparkle in the light of the room"+NORM,
    "garnets","&garnet&",
    "sapphires","&sapphire&",
    "sign", "In large fancy calligraphy script the sign says: 'Advance', 'Raise',\n\
                                                 'Restore', 'Reset'\n\
There is further script on the sign that you could 'read'",
    "guards","A pair of guards with extra fine equipment. Their armor shines and\n\
their deadly spears are held at the ready. With their straight\n\
backs and serious expressions these guys are not to be messed with",
  });
  dest_dir=({
    "/room/exlv_guild","down",
  });
  long_desc=
"This is the prestigious room at the top of the Adventurers' Tower.\n\
The most dedicated and brave of the Nirvana players can come here\n\
to advance their level of prestige. The room is opulently decorated\n\
to match the glory of the players that may enter this guild hall. The\n\
floor is made of marble, the walls have expensive artwork displayed,\n\
and the light fixtures are made with pure silver. An elegant sign\n\
that is as beautiful as the artwork is displayed on the north wall.\n";

  if(!present("hologram", this_object()))
    move_object(clone_object(HOLOGRAM), this_object());
}

init() {
        ::init();
#if 1
  add_action("Advance","advance");
  add_action("RestoreGuild", "restore");
  add_action("Raise", "raise");
  add_action("Read", "read" );
  add_action("Reset", "reset" );
#endif
  if( this_player() && this_player()->query_level() < 20 ) {
    if( !this_player()->query_prestige_level() && this_player()->query_extra_level() < REQ_EXLEV ) {
      write("A guard appears out of nowhere and roughly escorts you down the stairs.\n");
      say(this_player()->query_name()+" is roughly escorted to the stairs by a guard.\n");
      this_player()->move_player("down the stairs#room/exlv_guild");
      this_player()->clear_follow();
    }
  }
}

Read( string str ) {
  if( !str || ( str != "sign" && str != "script" ) ) {
    return 0;
  }
  
  write("\t"+HIBLK+pad("Advance",8)+"- Dedicate yourself to the next level of prestige.\n\
\t"+pad("Raise",8)+"- Raise one of your prestige skills.\n\
\t"+pad("Restore",8)+"- Restore your guild status previously earned.\n\
\t"+pad("Reset",8)+"- Reset your prestige skills...at a cost."+NORM+"\n\
\nFor more information do 'help prestige'.\n");
  return 1;
}

Reset() {
  int i, x, size, coins;
  object who;
  who = this_player();

  if( !who ) {
    return 1;
  }
  coins = REQUIRED_GOLD( who->query_prestige_level() );
  if( who->query_bank_balance() < coins ) {
    write("You don't have the required funds ("+comma_number(coins)+") to reset your skills.\n");
    return 1;
  }

  who->add_bank_balance( -coins );

  for( i=0, size=sizeof( VALID_PRES_SKILL ); i < size; i++ ) {
    x = who->query_prestige_skill( VALID_PRES_SKILL[i]  );
    who->set_prestige_skill( VALID_PRES_SKILL[i], 0 );
    who->add_prestige_skillpt( x );
  }

  log_file("PRESTIGE", ctime() + " " +this_player()->query_name()+" reset prestige points.\n");
  write("You have successfully reset your prestige skills.\n");
  return 1;
}  

dest_guild_object( object player, string path ) {
  /********************************************************
   * Not currently used. It needs to be updated to account
   * for a guild_file that includes .c
   ********************************************************/
  int i, size;
  string ob_path, junk;
  object *inv;
  
  if( !player || !path )
    return 0;
    
  write("Guild File: " +path+"\n");
  
  inv = all_inventory( player );
  for( i=0, size = sizeof(inv); i < size; i++ ) {
    ob_path = basename( inv[i] );
    write("\t\tItem: "+ inv[i]->short()+" path: "+ob_path+"\n");
    if( ob_path == path ) {
      destruct( inv[i] );
      return 1;
    }
  }
  return 0;
}

Raise( string str ) {
  int i, size, cur_skill, cur_level;
  
  if( str ) str = lower_case(str);
  
  if( !str || member( VALID_PRES_SKILL, str ) < 0 ) {

    write("Which prestige skill would you like to raise?\n");
    write("You can choose ");
    for( i=0, size=sizeof( VALID_PRES_SKILL ); i < size; i++ ) {
      write( VALID_PRES_SKILL[i] );
      if( i != size -1 )
        write( ", " );
      else
        write( "\n" );
    }
    return 1;
  }
  
  if( !this_player()->query_prestige_skillpt() ) {
    write("You currently have no skill points available.\n");
    return 1;
  }
  
  cur_skill = this_player()->query_prestige_skill( str );
  cur_level = this_player()->query_prestige_level();
  write("Lev: " + cur_level +" Skill: " + cur_skill+"\n");
  if( cur_skill + 1 > ( cur_level / 4 + 1 ) ) {
    write("You may not raise "+str+" until you obtain more prestige.\n");
    return 1;
  }
  
  this_player()->add_prestige_skill( str, 1 );
  this_player()->add_prestige_skillpt( -1 );
  write( "You advance your prestige skill "+str+".\n");
  return 1;
  
}

#if 0
RestoreGuild() {
  if( this_player()->query_level() < REQ_LEV ) {
    write("You do not meet the level requirement ("+REQ_LEV+") to restore your guild.\n");
    return 1;
  }
  
  if(this_player()->query_bank_balance() < GUILD_REQ_GOLD ) {
    write("You do not have the funds to cover the required fee of "+comma_number(GUILD_REQ_GOLD)+".\n");
    return 1;
  }
  
  if( !this_player()->query_prestige_guild( "file" ) ) {
    write("You do not have a guild to restore.\n");
    return 1;
  }
  
  if( this_player()->query_guild_file() || this_player()->query_guild_name() ) {
    write("You already belong to a guild.\n");
    return 1;
  }
  
  this_player()->add_bank_balance( -GUILD_REQ_GOLD );
  this_player()->restore_prestige_guild();
  this_player()->save_me();
  write("You pay the fee and restore your guild status.\n");
  return 1;
}
#endif

RestoreGuild( string gname ) {
  int siz;
  string *gnames;
  
  gnames = this_player()->query_prestige_guilds();
  siz = sizeof( gnames );

  if( !gnames ) {
    write("You do not have a guild to restore.\n");
    return 1;
  }

  if( siz > 1 && !gname ) {
    write("You must provide which guild to restore: \n" );
    while( siz-- ) {
      write("\t\t"+gnames[siz]+"\n");
    }
    return 1;
  }

	if(!member(gname, gnames)) {
		write("'"+gname+"' is not a valid option.\nType 'restore' for valid options.\n");
		return 1;
	}

  if( this_player()->query_level() < REQ_LEV ) {
    write("You do not meet the level requirement ("+REQ_LEV+") to restore your guild.\n");
    return 1;
  }
  
  if(this_player()->query_bank_balance() < GUILD_REQ_GOLD ) {
    write("You do not have the funds to cover the required fee of "+comma_number(GUILD_REQ_GOLD)+".\n");
    return 1;
  }

  if( this_player()->query_guild_file() || this_player()->query_guild_name() ) {
    write("You already belong to a guild.\n");
    return 1;
  }

  if( !gname ) {
    gname = gnames[0];
  }
  
  log_file("PRESTIGE", ctime() + " " +this_player()->query_name()+" restored "+gname+" guild.\n");
  this_player()->add_bank_balance( -GUILD_REQ_GOLD );
  this_player()->restore_prestige_guild( gname );
  this_player()->save_me();
  write("You pay the fee and restore your "+gname+" guild status.\n");
  return 1;
}

Advance() {
  write("Are you sure you wish to proceed with advancing your prestige?\n\
Your character will be reset, including level and stats.\n\
You also will be forced to "+RED+BLINK+"QUIT"+NORM+" as part of advancing!\n\
\nDo you still wish to continue?  Y/N: ");
  input_to( "Advance_To" );
  return 1;
}

Advance_To( string str ) {
  int req_gold;
  string gpath;
  
  if( !str || lower_case(str) != "y" ) {
    write("Try 'help prestige' for additional information.\n");
    return 1;
  }
    
  if( this_player()->query_level() > REQ_LEV ) {
     write("Not wise.\n");
     return 1;
   }
   
   if( this_player()->query_level() < REQ_LEV ) {
     write("You do not meet the level requirement ("+REQ_LEV+") for prestige.\n");
     return 1;
   }
   
   if( this_player()->query_extra_level() < REQ_EXLEV ) {
     write("You do not meet the extra level requirement ("+REQ_EXLEV+") for prestige.\n");
     return 1;
   }
   
   if( this_player()->query_exp() < REQ_XP )
   {
     write("You do not meet the experience requirement ("+comma_number(REQ_XP)+") for prestige.\n");
     return 1;
   }
   
   req_gold = REQUIRED_GOLD( this_player()->query_prestige_level() );
   
   if(this_player()->query_bank_balance() < req_gold ) {
    write("You do not have the funds to cover the required fee of "+comma_number(req_gold)+".\n");
    return 1;
  }
  
   
  this_player()->add_prestige_level( 1 );
  this_player()->set_al_title("neutral");
  /** Level/Experience **/
  this_player()->transfer_prestige_xp();
  /** Guild halls reset titles as well as levels **/
  call_other( "/room/adv_guild", "correct_level", this_player() );
  call_other( "/room/exlv_guild", "correct_extra_level", this_player() );

  this_player()->add_prestige_skillpt( 1 );
  /** chance of a bonus skill point with max QP's **/
  if( this_player()->query_quest_point() > random( 700 ) ) {
    this_player()->add_prestige_skillpt( 1 );
    write(HIBLK+"Your honor gained while questing has granted you a bonus prestige skill
point!\n"+NORM);
    return 1;
  }
  
  /** Reset Gold/Bank balance **/
  this_player()->add_bank_balance( -req_gold );
  this_player()->add_bank_balance( this_player()->query_money() );
  BANKD->clear_withdrawable_amount( this_player()->query_real_name() );
  this_player()->add_money( -this_player()->query_money() );

  /** Reset PK **/
  this_player()->set_pl_k(0);
  
  /** Quests **/
  this_player()->transfer_prestige_qp();
  
  /** Reset Stats **/
  this_player()->set_attrib("cha",5);
  this_player()->set_attrib("int",5);
  this_player()->set_attrib("mag",5);
  this_player()->set_attrib("sta",5);
  this_player()->set_attrib("str",5);
  this_player()->set_attrib("dex",5);
  this_player()->set_attrib("luc",5);
  this_player()->set_attrib("pie",5);
  this_player()->set_attrib("ste",5);
  this_player()->set_attrib("wil",5);

  /** Reset Max Stats **/
  this_player()->rec_attrib_max("cha",5);
  this_player()->rec_attrib_max("int",5);
  this_player()->rec_attrib_max("mag",5);
  this_player()->rec_attrib_max("sta",5);
  this_player()->rec_attrib_max("str",5);
  this_player()->rec_attrib_max("dex",5);
  this_player()->rec_attrib_max("luc",5);
  this_player()->rec_attrib_max("pie",5);
  this_player()->rec_attrib_max("ste",5);
  this_player()->rec_attrib_max("wil",5);
  /** Deal with guild **/
  gpath = this_player()->query_guild_file();
  if( gpath ) {
    this_player()->set_prestige_guild();
    /*****************************************************
     * Removed, forcing player to quit instead
    dest_guild_object( this_player(), gpath );
    ******************************************************/
  }
  
  if( !this_player()->is_testchar() ) {
    call_other("/room/exlv_guild", "nirvana_msg", 
      "The clouds part as an "+YEL+"ancient light"+NORM+" floods into "+this_player()->query_name()+"
and\n\
a great "+HIBLK+"thunder of applause"+NORM+" resounds from the elders of Nirvana.\n\
"+this_player()->query_name()+" has been blessed for their prestige!\n" );
    
    present("the nirvana hologram of prestige", 
            this_object())->encode_hologram(this_player());
  }
  
  write("The clouds part as an "+YEL+"ancient light"+NORM+" floods into your body and you\n\
shake as the elders of nirvana bless you with the power of prestige.\n");
  
  this_player()->quit();  
  return 1;
  
}

query_limited_shadow() { return 1; }

query_drop_castle() { return 1; }