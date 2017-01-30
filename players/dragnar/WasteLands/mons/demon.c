inherit "obj/monster";

#include <ansi.h>

#define LOG "/players/dragnar/WasteLands/log/MONS_DEATH"

/******************************************************************************
 * Program: demon.c
 * Path: /players/dragnar/WasteLands/mons
 * Type: Mob
 * Created: 1993 by Dragnar
 *
 * Purpose: A high level monster in the Wastelands area & part of the Wastelands
 *          quest. Many rooms of cult.c and cultmaster.c need to cleared to get
 *          to this mob. High WC/AC and high heal rate and very high spell
 *          damage. Has a special attack that steals up to 350 sps and heals
 *          mob with those sps. Will not make the player go negative. However
 *          if player goes negative so sps cannot be stolen it will then hit
 *          the player for that amount, very dangerous to mages.
 * History:
 *          09/18/2013 - Dragnar
 *            Updated stats, spells, & special attack.
 ******************************************************************************/
reset(arg){
  ::reset(arg);
  
  if(arg) return;
  
  set_name("demon");
  set_race("demon");
  set_alias("hell demon");
  set_short("A "+HIR+"Hell Demon"+NORM);
  set_long("You can't bear to look into his being.  The evil there will\n"+
"rob your soul.\n");
  set_level(29);
  set_hp(2200 + random(200));
  set_al(-1000);
  set_gender("creature");
  set_wc(80);
  set_ac(50);
  set_aggressive(1);
  set_dead_ob(this_object());
  set_hp_bonus( 600 );
  set_heal(50, 10);
  
  add_money(random(40000)+10000);
  
  set_armor_params("other|fire",0,100,0); /* No damage from fire */
  set_armor_params("other|ice",0,-100,0); /* Double damage from cold */
  
  add_spell("flame_spear",
    "#MN# fires a $HR$Spear of Flames$N$ at you!\n$HR$                                   `@@@z \n\
                                     ]@@L, \n\
                                      ~@@@z \n\
                                        @@@z \n\
                                        `-@@@_ \n\
                                          ~@@@_ \n\
                                           `@@@z \n"+
"                                            `-@@@_ \n\
                                              ]@@@_ \n\
                                               z@@@z \n\
                                                `]@@L, \n\
                                                  `@@@L \n\
                                                   `@@@z, \n"+
"                                                    `-@@@_ \n\
                                                      `@@@L \n\
                                                       `@@@L    ]e \n\
                                                         ~@@b_  a@b \n\
                                                          `@@@e]@@L \n\
                                                    -zzzz___@@@U@@@, \n"+
"                                                      '~-@@@@@@@@@@@ \n\
                                                         `~-@@@@@@@@L \n\
                                                            '~-@@@@@@, \n\
                                                               '~@@@@L  \n\
                                                                 `~@@@e \n\
                                                                    ~@@_ \n\
                                                                      ~@ $N$ \n",
  0, 10, "60-120","other|fire", 3 ); 
  
  add_spell("pet_flame", 0, "#TN# is $Y$engulfed in a ball of $HR$Flame$N$!\n", 50, "50-200", "other|fire", 4 );
  
  add_spell("room_flames",
    "#MN# waves its hand and the room is engulfed in flames! $HR$ \n\
                                       .                                         \n\
                    .;.                ;                                         \n\
                    7l.               :7                                         \n\
          ..      :tOL                G.::                       .               \n\
         ::      ;owR7              ;B; o:                       .;..            \n\
         7;..;  :7lbO.            7BB: I7.                        ...:7777;.     \n"+
"        .7l;;6;:7IAC.         .7AMMb  Iw;       :7;      .;;:         :77lOi   : \n\
         :Lwt0;lRW7        .tMBMG88 .ODw:      ;hABBGER8LI7:           O6ol6I; 0 \n\
          .GG70Mb.        :BMMOw8h;;DRD7      :MMBMBMRO7              .ACli706lA \n\
           ;MGHl           :8A0RG;7hWA;      ;MMR7;;::777l;. ;7:      .Rtlil0O0D \n\
            bB;              78MG7LHB;    : 7MM; .7:.;ll7ihRRGHMt      DhwLCRR7. \n\
.         .;;t                7BBRRM. ..   7BM;:.77;:;iCI7;70O6l   :7hBMBHWMB;   \n\
.          :Eb.    ;MH0:.   :7RDhWMH   ;: .BMBo;;ll;;;70hLt;;LD7;lhAEhWBHWWb;  : \n"+
"     ::.    hMA     0MMBEARHBMAL0hEE; :ow;oMAMA ;87:;;;iLObO77C8ItLt::ihGG;    o \n\
i7IhAl:    IABA.    ;GD8llOL8DOCO6CDA. :8oRhGMM;7O;;;;77IIwARowL6tOl..tAE:    ;B \n\
7LEG:     OWobB;77  .GoC:;7iI00OhbwCAW7;whOIOMBMGC777w6DH0:iHE06LC6O::lM;     7M \n\
7CE      DHwtLME7AMw7h7lo;;77tCwC88wOGEGRGClCMEAA000AGCL7   hBCLh88Al:tB    7;wB \n\
0b7     .MhCI0DH77BMAH0Ih;;;;wCl7owLLOODDb6GbMWAC0ORh       HMw0tRGMh;;G;;hM6lBG \n"+
"ER      .B6wIlOGw6MBDGMRD;::;IA;:;7lChDDRbbDDMMAOhRGAl      MAtI7CMAA;;CMBM67AHw \n\
WE      ;M06AAREGLhMAbDOw7  ::A87.;LDAEHAHDtLMMEhRDRAMH :L:lBh7IoOLMRL6HbHA  Eh0 \n\
RBI   .;MAl6MBbOA8hWE6l7ChIi;:WAhOWBbhARAEMAA0WWLC8hAEH7OBb8M8llLl7CB688GMA7;HAG \n\
6MBECGWMMbCMBH0tLEC8OItWEWEHWMBGBMBM08ioRMHho0bMACL68RDABBG8EAlliI77W8CwDMEbAADM \n\
0GBBMBMBMEA8l7LCLhWGt78Bb66OAOIGMAGM67;8Bhl78IOAME80L6bEBRG8OROl7l77EobhoD0GRotW \n"+
"7ChEHBAEAo;:::;7o8CBO;7Eo7iCCLtEBCoMAt0Ot77th8I8OGABHBEG8GDOL6Ow777OGGRMOoDAwowo \n\
;7oLbGRhh7:::. .;;lE08CO;.;::;:AM7LDh8o;;:loIhL7lltllw8w668O8LCol;iA67LbRAD0Ll:; \n\
:;;77lll7777;::;. Bt.70A07;:.;.BB;:777lO8hwItCA8ohO0lCotL0I0ow0w7iAHI;tADEBCww7B$N$ \n",
    0, 10, "100-160","other|fire", 3 ); 
  
  /** Moved to the chest   
	move_object(clone_object("/players/dragnar/WasteLands/obj/quest/mag4.c"), this_object());
  **/
}

monster_died() {
  say(HIBLK+"The Demon screams in RAGE!"+NORM+"\n");
  write_file(LOG, ctime(time())+" "+
    query_attack()->query_real_name()+" killed the Demon.\n");

}
heart_beat() {
  int amt, sps;
	object att;
  
	::heart_beat();

  amt = 50+random(300);
	att=(this_object()->query_attack());
  
  if(att && !random(10)) {
    tell_object(att, HIY+"The Demon draws power from your soul and you feel weakened."+NORM+"\n");
    sps = att->query_spell_point();
    
    if( sps < amt && sps > 0 )
      amt = sps;
    if( sps <= 0 )
      att->hit_player( amt, "other|fire" );
    else
      att->add_spell_point( -amt );
      
    this_object()->heal_self( amt );
	}
}
