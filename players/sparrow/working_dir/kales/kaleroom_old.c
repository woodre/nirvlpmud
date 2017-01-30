#include "/sys/ansi.h"
inherit "room/room";
int blah;

/* GLOBALS */
object Master;   /* Master Object, actually entrance.c - Sparrow */

reset(arg) {
  if(arg) return;
  /* Creature cloning is taken care of by master object - Sparrow */
  set_light(1);
  short_desc = ""+HIR+"Ka"+NORM+YEL+"le"+HIY+"id"+HIG+"os"+HIB+"co"+HIM+"pe"+NORM+"" ;
  long_desc = random_long();
  items = ({
    "toy","Both kids and adults enjoy to play with the kaleidoscope",
    "tube","It is usually made of plastic or hard paper",
    "mirrors","The mirrors reflect the light in infinite positions",
    "pattern","The combo of shapes and colors you get when you look through the peephole",
    "peephole","A small orifice at one end of the kaleidoscope",
  });
  blah=random(5);
  /* I like round percentages, changed chance of loading exit to entrance from 16.7%
     to 20% - Sparrow
  */
  if(blah == 0) {
    dest_dir = ({
      "/players/francesco/kale/rooms/kaleroom.c",HIR+"north"+NORM,
      "/players/francesco/kale/rooms/kaleroom.c",HIC+"east"+NORM,
      "/players/francesco/kale/rooms/kaleroom.c",HIM+"south"+NORM,
      "/players/francesco/kale/rooms/kaleroom.c",HIY+"west"+NORM,
      "/players/francesco/kale/rooms/entrance.c","out"
    });
  }
  else {
    dest_dir = ({
      "/players/francesco/kale/rooms/kaleroom.c",HIR+"north"+NORM,
      "/players/francesco/kale/rooms/kaleroom.c",HIC+"east"+NORM,
      "/players/francesco/kale/rooms/kaleroom.c",HIM+"south"+NORM,
      "/players/francesco/kale/rooms/kaleroom.c",HIY+"west"+NORM
    });
  }
}

init() {
    ::init();
    add_action("random_move","north");
    add_action("random_move","east");
    add_action("random_move","south");
    add_action("random_move","west");
}

int
random_move() {
   /* Pass movement handling to the master object - Sparrow */
   Master->move_me(this_player());
   return 1;
} 

/* Consolidated 50 rooms into 1 master room, this function has all of the long
   descriptions from the original 50 rooms and pulls one at random at time of
   cloning. Also cleaned up unneeded ""+ at begining of lines - Sparrow
*/
string
random_long() {
string *longdesc;
int descsize;
string ldesc;
longdesc = ({
  HIW+" "+HIB+"  T"+HIW+"h"+HIB+"e k"+HIW+"a"+HIB+"lei"+HIW+"d"+HIB+"osc"+HIW+"o"+HIB+"pe "+HIW+"i"+HIB+"s a"+HIR+"n optical toy consisting of a tube"+NORM+"\n"+
  HIB+"co"+HIW+"n"+HIB+"tai"+HIW+"n"+HIB+"ing"+HIW+" "+HIB+"two"+HIW+" "+HIB+"pla"+HIW+"n"+HIB+"e m"+HIW+"i"+HIB+"rr"+HIW+"ors placed at an angle of 60 degrees."+NORM+"\n"+
  HIB+""+HIW+"T"+HIB+"hey"+HIW+" "+HIB+"are"+HIW+" "+HIB+"mou"+HIW+"n"+HIB+"ted"+HIW+" "+HIB+"so "+HIW+"t"+HIB+"hat"+HIW+" "+HIR+"a symmetrical pattern produced by"+NORM+"\n"+
  HIB+"mu"+HIW+"l"+HIB+"tip"+HIW+"l"+HIB+"e r"+HIW+"e"+HIB+"fle"+HIW+"c"+HIB+"tio"+HIW+"n"+HIB+" ca"+HIW+"n"+HIB+" b"+HIW+"e observed through a peephole at"+NORM+" \n"+
  HIB+""+HIW+"o"+HIB+"ne "+HIW+"e"+HIB+"nd "+HIW+"o"+HIB+"f t"+HIW+"h"+HIB+"e k"+HIW+"a"+HIB+"lei"+HIW+"d"+HIB+"osc"+HIW+"o"+HIR+"pe itself.  However, this happens"+NORM+" \n"+
  HIW+"only when objects (such as pieces of coloured glass) at the"+NORM+"\n"+
  HIR+"other end are suitably illuminated.  When the two mirrors are"+NORM+"\n"+
  HIW+"rotated or shifted one against the other, the pattern will"+NORM+"\n"+
  HIR+"change, thus producing an almost endless combination of shapes"+NORM+"\n"+
  HIW+"and colors."+NORM+"\n",
  HIG+"   The kaleidoscope"+HIW+" is an optical toy c"+HIR+"onsisting of a tube\n"+
  HIG+"containing two plan"+HIW+"e mirrors placed at "+HIR+"an angle of 60 degrees.\n"+
  HIG+"They are mounted so"+HIW+" that a symmetrical "+HIR+"pattern produced by\n"+
  HIG+"multiple reflection"+HIW+" can be observed thr"+HIR+"ough a peephole at \n"+
  HIG+"one end of the kale"+HIW+"idoscope itself.  Ho"+HIR+"wever, this happens \n"+
  HIG+"only when objects ("+HIW+"such as pieces of co"+HIR+"loured glass) at the\n"+
  HIG+"other end are suita"+HIW+"bly illuminated.  Wh"+HIR+"en the two mirrors are\n"+
  HIG+"rotated or shifted "+HIW+"one against the othe"+HIR+"r, the pattern will\n"+
  HIG+"change, thus produc"+HIW+"ing an almost endles"+HIR+"s combination of shapes\n"+
  HIG+"and colors."+NORM+"\n",
  "   "+YEL+"The "+NORM+"kaleidoscope is"+YEL+" an opti"+NORM+"cal toy consist"+YEL+"ing of a "+NORM+"tube\n"+
  YEL+"contain"+NORM+"ing two plane m"+YEL+"irrors p"+NORM+"laced at an ang"+YEL+"le of 60 "+NORM+"degrees.\n"+
  YEL+"They ar"+NORM+"e mounted so th"+YEL+"at a sym"+NORM+"metrical patter"+YEL+"n produce"+NORM+"d by\n"+
  YEL+"multipl"+NORM+"e reflection ca"+YEL+"n be obs"+NORM+"erved through a"+YEL+" peephole"+NORM+" at \n"+
  YEL+"one end"+NORM+" of the kaleido"+YEL+"scope it"+NORM+"self.  However,"+YEL+" this hap"+NORM+"pens \n"+
  YEL+"only wh"+NORM+"en objects (suc"+YEL+"h as pie"+NORM+"ces of coloured"+YEL+" glass) a"+NORM+"t the\n"+
  YEL+"other e"+NORM+"nd are suitably"+YEL+" illumin"+NORM+"ated.  When the"+YEL+" two mirr"+NORM+"ors are\n"+
  YEL+"rotated"+NORM+" or shifted one"+YEL+" against"+NORM+" the other, the"+YEL+" pattern "+NORM+"will\n"+
  YEL+"change,"+NORM+" thus producing"+YEL+" an almo"+NORM+"st endless comb"+YEL+"ination o"+NORM+"f shapes\n"+
  YEL+"and col"+NORM+"ors.\n",
  "   "+HIC+"The "+NORM+"kaleidoscope is"+HIC+" an opti"+NORM+"cal toy consist"+HIC+"ing of a "+NORM+"tube\n"+
  HIC+"contain"+NORM+"ing two plane m"+HIC+"irrors p"+NORM+"laced at an ang"+HIC+"le of 60 "+NORM+"degrees.\n"+
  HIC+"They ar"+NORM+"e mounted so th"+HIC+"at a sym"+NORM+"metrical patter"+HIC+"n produce"+NORM+"d by\n"+
  HIC+"multipl"+NORM+"e reflection ca"+HIC+"n be obs"+NORM+"erved through a"+HIC+" peephole"+NORM+" at \n"+
  HIC+"one end"+NORM+" of the kaleido"+HIC+"scope it"+NORM+"self.  However,"+HIC+" this hap"+NORM+"pens \n"+
  HIC+"only wh"+NORM+"en objects (suc"+HIC+"h as pie"+NORM+"ces of coloured"+HIC+" glass) a"+NORM+"t the\n"+
  HIC+"other e"+NORM+"nd are suitably"+HIC+" illumin"+NORM+"ated.  When the"+HIC+" two mirr"+NORM+"ors are\n"+
  HIC+"rotated"+NORM+" or shifted one"+HIC+" against"+NORM+" the other, the"+HIC+" pattern "+NORM+"will\n"+
  HIC+"change,"+NORM+" thus producing"+HIC+" an almo"+NORM+"st endless comb"+HIC+"ination o"+NORM+"f shapes\n"+
  HIC+"and col"+NORM+"ors.\n",
  "   "+HIR+"The "+NORM+"kaleidoscope is"+HIR+" an opti"+NORM+"cal toy consisti"+HIR+"ng of a "+NORM+"tube\n"+
  HIR+"contain"+NORM+"ing two plane m"+HIR+"irrors p"+NORM+"laced at an ange"+HIR+"e of 60 "+NORM+"degrees.\n"+
  HIR+"They ar"+NORM+"e mounted so th"+HIR+"at a sym"+NORM+"metrical pattern"+HIR+" produce"+NORM+"d by\n"+
  HIR+"multipl"+NORM+"e reflection ca"+HIR+"n be obs"+NORM+"erved through a "+HIR+"peephole"+NORM+" at \n"+
  HIR+"one end"+NORM+" of the kaleido"+HIR+"scope it"+NORM+"self.  However, "+HIR+"this hap"+NORM+"pens \n"+
  HIR+"only wh"+NORM+"en objects (suc"+HIR+"h as pie"+NORM+"ces of coloured "+HIR+"glass) a"+NORM+"t the\n"+
  HIR+"other e"+NORM+"nd are suitably"+HIR+" illumin"+NORM+"ated.  When the "+HIR+"two mirr"+NORM+"ors are\n"+
  HIR+"rotated"+NORM+" or shifted one"+HIR+" against"+NORM+" the other, the "+HIR+"pattern "+NORM+"will\n"+
  HIR+"change,"+NORM+" thus producing"+HIR+" an almo"+NORM+"st endless combi"+HIR+"nation o"+NORM+"f shapes\n"+
  HIR+"and col"+NORM+"ors.\n",
  "   "+HIY+"The "+NORM+"kaleidoscope is"+HIY+" an opti"+NORM+"cal toy consisti"+HIY+"ng of a "+NORM+"tube\n"+
  HIY+"contain"+NORM+"ing two plane m"+HIY+"irrors p"+NORM+"laced at an angl"+HIY+"e of 60 "+NORM+"degrees.\n"+     
  HIY+"They ar"+NORM+"e mounted so th"+HIY+"at a sym"+NORM+"metrical pattern"+HIY+" produce"+NORM+"d by\n"+
  HIY+"multipl"+NORM+"e reflection ca"+HIY+"n be obs"+NORM+"erved through a "+HIY+"peephole"+NORM+" at \n"+
  HIY+"one end"+NORM+" of the kaleido"+HIY+"scope it"+NORM+"self.  However, "+HIY+"this hap"+NORM+"pens \n"+
  HIY+"only wh"+NORM+"en objects (suc"+HIY+"h as pie"+NORM+"ces of coloured "+HIY+"glass) a"+NORM+"t the\n"+
  HIY+"other e"+NORM+"nd are suitably"+HIY+" illumin"+NORM+"ated.  When the "+HIY+"two mirr"+NORM+"ors are\n"+
  HIY+"rotated"+NORM+" or shifted one"+HIY+" against"+NORM+" the other, the "+HIY+"pattern "+NORM+"will\n"+
  HIY+"change,"+NORM+" thus producing"+HIY+" an almo"+NORM+"st endless combi"+HIY+"nation o"+NORM+"f shapes\n"+
  HIY+"and col"+NORM+"ors.\n",
  "   "+HIB+"The "+NORM+"kaleidoscope is"+HIR+" an opti"+NORM+"cal toy consist"+HIY+"ing of a "+NORM+"tube\n"+
  HIB+"contain"+NORM+"ing two plane m"+HIR+"irrors p"+NORM+"laced at an ang"+HIY+"le of 60 "+NORM+"degrees.\n"+
  HIB+"They ar"+NORM+"e mounted so th"+HIR+"at a sym"+NORM+"metrical patter"+HIY+"n produce"+NORM+"d by\n"+
  HIB+"multipl"+NORM+"e reflection ca"+HIR+"n be obs"+NORM+"erved through a"+HIY+" peephole"+NORM+" at \n"+
  HIW+"one end"+NORM+" of the kaleido"+HIW+"scope it"+NORM+"self.  However,"+HIW+" this hap"+NORM+"pens \n"+
  HIB+"only wh"+NORM+"en objects (suc"+HIR+"h as pie"+NORM+"ces of coloured"+HIY+" glass) a"+NORM+"t the\n"+
  HIB+"other e"+NORM+"nd are suitably"+HIR+" illumin"+NORM+"ated.  When the"+HIY+" two mirr"+NORM+"ors are\n"+
  HIB+"rotated"+NORM+" or shifted one"+HIR+" against"+NORM+" the other, the"+HIY+" pattern "+NORM+"will\n"+
  HIB+"change,"+NORM+" thus producing"+HIR+" an almo"+NORM+"st endless comb"+HIY+"ination o"+NORM+"f shapes\n"+
  HIB+"and col"+NORM+"ors.\n",
  "   "+HIW+"The "+NORM+"kaleidoscope is"+HIW+" an opti"+NORM+"cal toy consist"+HIW+"ing of a "+NORM+"tube\n"+
  HIW+"contain"+NORM+"ing two plane m"+HIW+"irrors p"+NORM+"laced at an ang"+HIW+"le of 60 "+NORM+"degrees.\n"+
  HIW+"They ar"+NORM+"e mounted so th"+HIW+"at a sym"+NORM+"metrical patter"+HIW+"n produce"+NORM+"d by\n"+
  HIW+"multipl"+NORM+"e reflection ca"+HIW+"n be obs"+NORM+"erved through a"+HIW+" peephole"+NORM+" at \n"+
  HIW+"one end"+NORM+" of the kaleido"+HIW+"scope it"+NORM+"self.  However,"+HIW+" this hap"+NORM+"pens \n"+
  HIR+"only wh"+NORM+"en objects (suc"+HIR+"h as pie"+NORM+"ces of coloured"+HIR+" glass) a"+NORM+"t the\n"+
  HIR+"other e"+NORM+"nd are suitably"+HIR+" illumin"+NORM+"ated.  When the"+HIR+" two mirr"+NORM+"ors are\n"+
  HIR+"rotated"+NORM+" or shifted one"+HIR+" against"+NORM+" the other, the"+HIR+" pattern "+NORM+"will\n"+
  HIR+"change,"+NORM+" thus producing"+HIR+" an almo"+NORM+"st endless comb"+HIR+"ination o"+NORM+"f shapes\n"+
  HIR+"and col"+NORM+"ors.\n",
  "   "+HIR+"The "+NORM+"kaleidoscope is"+HIW+" an opti"+NORM+"cal toy consist"+HIR+"ing of a "+NORM+"tube\n"+
  HIR+"contain"+NORM+"ing two plane m"+HIW+"irrors p"+NORM+"laced at an ang"+HIR+"le of 60 "+NORM+"degrees.\n"+
  HIR+"They ar"+NORM+"e mounted so th"+HIW+"at a sym"+NORM+"metrical patter"+HIR+"n produce"+NORM+"d by\n"+
  HIR+"multipl"+NORM+"e reflection ca"+HIW+"n be obs"+NORM+"erved through a"+HIR+" peephole"+NORM+" at \n"+
  HIR+"one end"+NORM+" of the kaleido"+HIW+"scope it"+NORM+"self.  However,"+HIR+" this hap"+NORM+"pens \n"+
  HIW+"only wh"+NORM+"en objects (suc"+HIR+"h as pie"+NORM+"ces of coloured"+HIW+" glass) a"+NORM+"t the\n"+
  HIW+"other e"+NORM+"nd are suitably"+HIR+" illumin"+NORM+"ated.  When the"+HIW+" two mirr"+NORM+"ors are\n"+
  HIW+"rotated"+NORM+" or shifted one"+HIR+" against"+NORM+" the other, the"+HIW+" pattern "+NORM+"will\n"+
  HIW+"change,"+NORM+" thus producing"+HIR+" an almo"+NORM+"st endless comb"+HIW+"ination o"+NORM+"f shapes\n"+
  HIW+"and col"+NORM+"ors.\n",
  "   "+HIC+"The k"+NORM+"aleidosco"+HIC+"pe is"+NORM+" an optic"+HIC+"al to"+NORM+"y consist"+HIC+"ing o"+NORM+"f a tube\n"+
  "conta"+HIC+"ining"+NORM+" two plan"+HIC+"e mir"+NORM+"rors plac"+HIC+"ed at"+NORM+" an angle"+HIC+" of 6"+NORM+"0 degrees.\n"+
  "They ar"+HIC+"e mou"+NORM+"nted so t"+HIC+"hat a"+NORM+" symmetri"+HIC+"cal p"+NORM+"attern pr"+HIC+"oduce"+NORM+"d by\n"+
  "multiple "+HIC+"refle"+NORM+"ction can"+HIC+" be o"+NORM+"bserved t"+HIC+"hroug"+NORM+"h a peeph"+HIC+"ole a"+NORM+"t \n"+
  HIC+"on"+NORM+"e end of "+HIC+"the k"+NORM+"aleidosco"+HIC+"pe it"+NORM+"self.  Ho"+HIC+"wever"+NORM+", this ha"+HIC+"ppens"+NORM+" \n"+
  HIC+"only"+NORM+" when obj"+HIC+"ects "+NORM+"(such as "+HIC+"piece"+NORM+"s of colo"+HIC+"ured "+NORM+"glass) at"+HIC+" the"+NORM+"\n"+
  "o"+HIC+"ther "+NORM+"end are s"+HIC+"uitab"+NORM+"ly illumi"+HIC+"nated"+NORM+".  When t"+HIC+"he tw"+NORM+"o mirrors"+HIC+" are"+NORM+"\n"+
  "rot"+HIC+"ated "+NORM+"or shifte"+HIC+"d one"+NORM+" against "+HIC+"the o"+NORM+"ther, the"+HIC+" patt"+NORM+"ern will\n"+
  "chang"+HIC+"e, th"+NORM+"us produc"+HIC+"ing a"+NORM+"n almost "+HIC+"endle"+NORM+"ss combin"+HIC+"ation"+NORM+" of shapes\n"+
  "and col"+HIC+"ors."+NORM+"\n",
  "   "+HIR+"The k"+NORM+"aleidosco"+HIR+"pe is"+NORM+" an optic"+HIR+"al to"+NORM+"y consist"+HIR+"ing o"+NORM+"f a tube\n"+
  "conta"+HIR+"ining"+NORM+" two plan"+HIR+"e mir"+NORM+"rors plac"+HIR+"ed at"+NORM+" an angle"+HIR+" of 6"+NORM+"0 degrees.\n"+
  "They ar"+HIR+"e mou"+NORM+"nted so t"+HIR+"hat a"+NORM+" symmetri"+HIR+"cal p"+NORM+"attern pr"+HIR+"oduce"+NORM+"d by\n"+
  "multiple "+HIR+"refle"+NORM+"ction can"+HIR+" be o"+NORM+"bserved t"+HIR+"hroug"+NORM+"h a peeph"+HIR+"ole a"+NORM+"t \n"+
  HIR+"on"+NORM+"e end of "+HIR+"the k"+NORM+"aleidosco"+HIR+"pe it"+NORM+"self.  Ho"+HIR+"wever"+NORM+", this ha"+HIR+"ppens"+NORM+" \n"+
  HIR+"only"+NORM+" when obj"+HIR+"ects "+NORM+"(such as "+HIR+"piece"+NORM+"s of colo"+HIR+"ured "+NORM+"glass) at"+HIR+" the"+NORM+"\n"+
  "o"+HIR+"ther "+NORM+"end are s"+HIR+"uitab"+NORM+"ly illumi"+HIR+"nated"+NORM+".  When t"+HIR+"he tw"+NORM+"o mirrors"+HIR+" are"+NORM+"\n"+
  "rot"+HIR+"ated "+NORM+"or shifte"+HIR+"d one"+NORM+" against "+HIR+"the o"+NORM+"ther, the"+HIR+" patt"+NORM+"ern will\n"+
  "chang"+HIR+"e, th"+NORM+"us produc"+HIR+"ing a"+NORM+"n almost "+HIR+"endle"+NORM+"ss combin"+HIR+"ation"+NORM+" of shapes\n"+
  "and col"+HIR+"ors."+NORM+"\n",
  "   "+HIB+"The k"+NORM+"aleidosco"+HIB+"pe is"+NORM+" an optic"+HIB+"al to"+NORM+"y consist"+HIB+"ing o"+NORM+"f a tube\n"+
  "conta"+HIB+"ining"+NORM+" two plan"+HIB+"e mir"+NORM+"rors plac"+HIB+"ed at"+NORM+" an angle"+HIB+" of 6"+NORM+"0 degrees.\n"+
  "They ar"+HIB+"e mou"+NORM+"nted so t"+HIB+"hat a"+NORM+" symmetri"+HIB+"cal p"+NORM+"attern pr"+HIB+"oduce"+NORM+"d by\n"+
  "multiple "+HIB+"refle"+NORM+"ction can"+HIB+" be o"+NORM+"bserved t"+HIB+"hroug"+NORM+"h a peeph"+HIB+"ole a"+NORM+"t \n"+
  HIB+"on"+NORM+"e end of "+HIB+"the k"+NORM+"aleidosco"+HIB+"pe it"+NORM+"self.  Ho"+HIB+"wever"+NORM+", this ha"+HIB+"ppens"+NORM+" \n"+
  HIB+"only"+NORM+" when obj"+HIB+"ects "+NORM+"(such as "+HIB+"piece"+NORM+"s of colo"+HIB+"ured "+NORM+"glass) at"+HIB+" the"+NORM+"\n"+
  "o"+HIB+"ther "+NORM+"end are s"+HIB+"uitab"+NORM+"ly illumi"+HIB+"nated"+NORM+".  When t"+HIB+"he tw"+NORM+"o mirrors"+HIB+" are"+NORM+"\n"+
  "rot"+HIB+"ated "+NORM+"or shifte"+HIB+"d one"+NORM+" against "+HIB+"the o"+NORM+"ther, the"+HIB+" patt"+NORM+"ern will\n"+
  "chang"+HIB+"e, th"+NORM+"us produc"+HIB+"ing a"+NORM+"n almost "+HIB+"endle"+NORM+"ss combin"+HIB+"ation"+NORM+" of shapes\n"+
  "and col"+HIB+"ors."+NORM+"\n",
  "   "+HIB+"The k"+NORM+"aleidosco"+HIR+"pe is"+NORM+" an optic"+HIB+"al to"+NORM+"y consist"+HIR+"ing o"+NORM+"f a tube\n"+
  "conta"+HIR+"ining"+NORM+" two plan"+HIB+"e mir"+NORM+"rors plac"+HIR+"ed at"+NORM+" an angle"+HIB+" of 6"+NORM+"0 degrees.\n"+
  "They ar"+HIB+"e mou"+NORM+"nted so t"+HIR+"hat a"+NORM+" symmetri"+HIB+"cal p"+NORM+"attern pr"+HIR+"oduce"+NORM+"d by\n"+
  "multiple "+HIR+"refle"+NORM+"ction can"+HIB+" be o"+NORM+"bserved t"+HIR+"hroug"+NORM+"h a peeph"+HIB+"ole a"+NORM+"t \n"+
  HIR+"on"+NORM+"e end of "+HIB+"the k"+NORM+"aleidosco"+HIR+"pe it"+NORM+"self.  Ho"+HIB+"wever"+NORM+", this ha"+HIR+"ppens"+NORM+" \n"+
  HIB+"only"+NORM+" when obj"+HIR+"ects "+NORM+"(such as "+HIB+"piece"+NORM+"s of colo"+HIR+"ured "+NORM+"glass) at"+HIB+" the"+NORM+"\n"+
  "o"+HIR+"ther "+NORM+"end are s"+HIB+"uitab"+NORM+"ly illumi"+HIR+"nated"+NORM+".  When t"+HIB+"he tw"+NORM+"o mirrors"+HIR+" are"+NORM+"\n"+
  "rot"+HIB+"ated "+NORM+"or shifte"+HIR+"d one"+NORM+" against "+HIB+"the o"+NORM+"ther, the"+HIR+" patt"+NORM+"ern will\n"+
  "chang"+HIR+"e, th"+NORM+"us produc"+HIB+"ing a"+NORM+"n almost "+HIR+"endle"+NORM+"ss combin"+HIB+"ation"+NORM+" of shapes\n"+
  "and col"+HIB+"ors."+NORM+"\n",
  "   "+HIM+"The k"+NORM+"aleidosco"+HIM+"pe is"+NORM+" an optic"+HIM+"al to"+NORM+"y consist"+HIM+"ing o"+NORM+"f a tube\n"+
  "conta"+HIM+"ining"+NORM+" two plan"+HIM+"e mir"+NORM+"rors plac"+HIM+"ed at"+NORM+" an angle"+HIM+" of 6"+NORM+"0 degrees.\n"+
  "They ar"+HIM+"e mou"+NORM+"nted so t"+HIM+"hat a"+NORM+" symmetri"+HIM+"cal p"+NORM+"attern pr"+HIM+"oduce"+NORM+"d by\n"+
  "multiple "+HIM+"refle"+NORM+"ction can"+HIM+" be o"+NORM+"bserved t"+HIM+"hroug"+NORM+"h a peeph"+HIM+"ole a"+NORM+"t \n"+
  HIM+"on"+NORM+"e end of "+HIM+"the k"+NORM+"aleidosco"+HIM+"pe it"+NORM+"self.  Ho"+HIM+"wever"+NORM+", this ha"+HIM+"ppens"+NORM+" \n"+
  HIM+"only"+NORM+" when obj"+HIM+"ects "+NORM+"(such as "+HIM+"piece"+NORM+"s of colo"+HIM+"ured "+NORM+"glass) at"+HIM+" the"+NORM+"\n"+
  "o"+HIM+"ther "+NORM+"end are s"+HIM+"uitab"+NORM+"ly illumi"+HIM+"nated"+NORM+".  When t"+HIM+"he tw"+NORM+"o mirrors"+HIM+" are"+NORM+"\n"+
  "rot"+HIM+"ated "+NORM+"or shifte"+HIM+"d one"+NORM+" against "+HIM+"the o"+NORM+"ther, the"+HIM+" patt"+NORM+"ern will\n"+
  "chang"+HIM+"e, th"+NORM+"us produc"+HIM+"ing a"+NORM+"n almost "+HIM+"endle"+NORM+"ss combin"+HIM+"ation"+NORM+" of shapes\n"+
  "and col"+HIM+"ors."+NORM+"\n",
  "   "+HIM+"The k"+NORM+"aleidosco"+HIY+"pe is"+NORM+" an optic"+HIM+"al to"+NORM+"y consist"+HIY+"ing o"+NORM+"f a tube\n"+
  "conta"+HIM+"ining"+NORM+" two plan"+HIY+"e mir"+NORM+"rors plac"+HIM+"ed at"+NORM+" an angle"+HIY+" of 6"+NORM+"0 degrees.\n"+
  "They ar"+HIM+"e mou"+NORM+"nted so t"+HIY+"hat a"+NORM+" symmetri"+HIM+"cal p"+NORM+"attern pr"+HIY+"oduce"+NORM+"d by\n"+
  "multiple "+HIM+"refle"+NORM+"ction can"+HIY+" be o"+NORM+"bserved t"+HIM+"hroug"+NORM+"h a peeph"+HIY+"ole a"+NORM+"t \n"+
  HIY+"on"+NORM+"e end of "+HIM+"the k"+NORM+"aleidosco"+HIY+"pe it"+NORM+"self.  Ho"+HIM+"wever"+NORM+", this ha"+HIY+"ppens"+NORM+" \n"+
  HIY+"only"+NORM+" when obj"+HIM+"ects "+NORM+"(such as "+HIY+"piece"+NORM+"s of colo"+HIM+"ured "+NORM+"glass) at"+HIY+" the"+NORM+"\n"+
  "o"+HIY+"ther "+NORM+"end are s"+HIM+"uitab"+NORM+"ly illumi"+HIY+"nated"+NORM+".  When t"+HIM+"he tw"+NORM+"o mirrors"+HIY+" are"+NORM+"\n"+
  "rot"+HIY+"ated "+NORM+"or shifte"+HIM+"d one"+NORM+" against "+HIY+"the o"+NORM+"ther, the"+HIM+" patt"+NORM+"ern will\n"+
  "chang"+HIY+"e, th"+NORM+"us produc"+HIM+"ing a"+NORM+"n almost "+HIY+"endle"+NORM+"ss combin"+HIM+"ation"+NORM+" of shapes\n"+
  "and col"+HIY+"ors."+NORM+"\n",
  HIR+"   The kaleidoscope is an optical toy consisting of a tube\n"+
  "containing two plane mirrors placed at an angle of 60 degrees.\n"+
  "They are mounted so that a symmetrical pattern produced by\n"+
  HIB+"multiple reflection can be observed through a peephole at \n"+
  "one end of the kaleidoscope itself.  However, this happens \n"+
  "only when objects (such as pieces of coloured glass) at the\n"+
  "other end are suitably illuminated.  When the two mirrors are\n"+
  HIR+"rotated or shifted one against the other, the pattern will\n"+
  "change, thus producing an almost endless combination of shapes\n"+
  "and colors."+NORM+"\n",
  "   "+HIM+"The kaleidosco"+HIY+"pe is an optic"+HIM+"al toy consist"+HIY+"ing of a tube\n"+
  "conta"+HIM+"ining two plan"+HIY+"e mirrors plac"+HIM+"ed at an angle"+HIY+" of 60 degrees.\n"+
  "They ar"+HIM+"e mounted so t"+HIY+"hat a symmetri"+HIM+"cal pattern pr"+HIY+"oduced by\n"+
  "multiple "+HIM+"reflection can"+HIY+" be observed t"+HIM+"hrough a peeph"+HIY+"ole at \n"+
  HIY+"one end of "+HIM+"the kaleidosco"+HIY+"pe itself.  Ho"+HIM+"wever, this ha"+HIY+"ppens \n"+
  HIY+"only when obj"+HIM+"ects (such as "+HIY+"pieces of colo"+HIM+"ured glass) at"+HIY+" the\n"+
  "o"+HIY+"ther end are s"+HIM+"uitably illumi"+HIY+"nated.  When t"+HIM+"he two mirrors"+HIY+" are\n"+
  HIM+"rot"+HIY+"ated or shifte"+HIM+"d one against "+HIY+"the other, the"+HIM+" pattern will\n"+
  "chang"+HIY+"e, thus produc"+HIM+"ing an almost "+HIY+"endless combin"+HIM+"ation of shapes\n"+
  "and col"+HIY+"ors."+NORM+"\n",
  "   The kaleidoscope is an "+HIR+"optical"+NORM+" toy consisting of a tube\n"+
  "containing two plane m"+HIR+"irrors "+NORM+"pla"+HIR+"ced at "+NORM+"an angle of 60 degrees.\n"+
  "They are mounted s"+HIR+"o that "+NORM+"a symmetric"+HIR+"al patt"+NORM+"ern produced by\n"+
  "multiple refle"+HIR+"ction c"+NORM+"an be observed thro"+HIR+"ugh a p"+NORM+"eephole at \n"+
  "one end of"+HIR+" the ka"+NORM+"leidoscope itself.  However"+HIR+", this "+NORM+"happens \n"+
  "only when obje"+HIR+"cts (su"+NORM+"ch as pieces of col"+HIR+"oured g"+NORM+"lass) at the\n"+
  "other end are suit"+HIR+"ably il"+NORM+"luminated. "+HIR+" When t"+NORM+"he two mirrors are\n"+
  "rotated or shifted one"+HIR+" agains"+NORM+"t t"+HIR+"he othe"+NORM+"r, the pattern will\n"+
  "change, thus producing an al"+HIR+"most en"+NORM+"dless combination of shapes\n"+
  "and colors.\n",
  "   The kaleidoscope is an "+HIB+"optical"+NORM+" toy consisting of a tube\n"+
  "containing two plane m"+HIB+"irrors "+NORM+"pla"+HIB+"ced at "+NORM+"an angle of 60 degrees.\n"+
  "They are mounted s"+HIB+"o that "+NORM+"a symmetric"+HIB+"al patt"+NORM+"ern produced by\n"+
  "multiple refle"+HIB+"ction c"+NORM+"an be observed thro"+HIB+"ugh a p"+NORM+"eephole at \n"+
  "one end of"+HIB+" the ka"+NORM+"leidoscope itself.  However"+HIB+", this "+NORM+"happens \n"+
  "only when obje"+HIB+"cts (su"+NORM+"ch as pieces of col"+HIB+"oured g"+NORM+"lass) at the\n"+
  "other end are suit"+HIB+"ably il"+NORM+"luminated. "+HIB+" When t"+NORM+"he two mirrors are\n"+
  "rotated or shifted one"+HIB+" agains"+NORM+"t t"+HIB+"he othe"+NORM+"r, the pattern will\n"+
  "change, thus producing an al"+HIB+"most en"+NORM+"dless combination of shapes\n"+
  "and colors.\n",
  "   The kaleidoscope is an "+HIC+"optical"+NORM+" toy consisting of a tube\n"+
  "containing two plane m"+HIC+"irrors "+NORM+"pla"+HIC+"ced at "+NORM+"an angle of 60 degrees.\n"+
  "They are mounted s"+HIC+"o that "+NORM+"a symmetric"+HIC+"al patt"+NORM+"ern produced by\n"+
  "multiple refle"+HIC+"ction c"+NORM+"an be observed thro"+HIC+"ugh a p"+NORM+"eephole at \n"+
  "one end of"+HIC+" the ka"+NORM+"leidoscope itself.  However"+HIC+", this "+NORM+"happens \n"+
  "only when obje"+HIC+"cts (su"+NORM+"ch as pieces of col"+HIC+"oured g"+NORM+"lass) at the\n"+
  "other end are suit"+HIC+"ably il"+NORM+"luminated. "+HIC+" When t"+NORM+"he two mirrors are\n"+
  "rotated or shifted one"+HIC+" agains"+NORM+"t t"+HIC+"he othe"+NORM+"r, the pattern will\n"+
  "change, thus producing an al"+HIC+"most en"+NORM+"dless combination of shapes\n"+
  "and colors.\n",
  "   The kaleidoscope is an "+HIC+"opt"+HIR+"ical"+NORM+" toy consisting of a tube\n"+
  "containing two plane m"+HIC+"irrors "+NORM+"pla"+HIR+"ced at "+NORM+"an angle of 60 degrees.\n"+
  "They are mounted s"+HIC+"o that "+NORM+"a symmetric"+HIR+"al patt"+NORM+"ern produced by\n"+
  "multiple refle"+HIC+"ction c"+NORM+"an be observed thro"+HIR+"ugh a p"+NORM+"eephole at \n"+
  "one end of"+HIC+" the ka"+NORM+"leidoscope itself.  However"+HIR+", this "+NORM+"happens \n"+
  "only when obje"+HIC+"cts (su"+NORM+"ch as pieces of col"+HIR+"oured g"+NORM+"lass) at the\n"+
  "other end are suit"+HIC+"ably il"+NORM+"luminated. "+HIR+" When t"+NORM+"he two mirrors are\n"+
  "rotated or shifted one"+HIC+" agains"+NORM+"t t"+HIR+"he othe"+NORM+"r, the pattern will\n"+
  "change, thus producing an al"+HIC+"mos"+HIR+"t en"+NORM+"dless combination of shapes\n"+
  "and colors.\n",
  "   The kaleidoscope is an "+HIB+"opt"+HIY+"ical"+NORM+" toy consisting of a tube\n"+
  "containing two plane m"+HIB+"irrors "+NORM+"pla"+HIY+"ced at "+NORM+"an angle of 60 degrees.\n"+
  "They are mounted s"+HIB+"o that "+NORM+"a symmetric"+HIY+"al patt"+NORM+"ern produced by\n"+
  "multiple refle"+HIB+"ction c"+NORM+"an be observed thro"+HIY+"ugh a p"+NORM+"eephole at \n"+
  "one end of"+HIB+" the ka"+NORM+"leidoscope itself.  However"+HIY+", this "+NORM+"happens \n"+
  "only when obje"+HIB+"cts (su"+NORM+"ch as pieces of col"+HIY+"oured g"+NORM+"lass) at the\n"+
  "other end are suit"+HIB+"ably il"+NORM+"luminated. "+HIY+" When t"+NORM+"he two mirrors are\n"+
  "rotated or shifted one"+HIB+" agains"+NORM+"t t"+HIY+"he othe"+NORM+"r, the pattern will\n"+
  "change, thus producing an al"+HIB+"mos"+HIY+"t en"+NORM+"dless combination of shapes\n"+
  "and colors.\n",
  "   "+HIB+"The kaleidosco"+HIR+"pe is an optic"+HIB+"al toy consist"+HIR+"ing of a tube\n"+
  "conta"+HIB+"ining two plan"+HIR+"e mirrors plac"+HIB+"ed at an angle"+HIR+" of 60 degrees.\n"+
  "They ar"+HIB+"e mounted so t"+HIR+"hat a symmetri"+HIB+"cal pattern pr"+HIR+"oduced by\n"+
  "multiple "+HIB+"reflection can"+HIR+" be observed t"+HIB+"hrough a peeph"+HIR+"ole at \n"+
  HIR+"one end of "+HIB+"the kaleidosco"+HIR+"pe itself.  Ho"+HIB+"wever, this ha"+HIR+"ppens \n"+
  HIR+"only when obj"+HIB+"ects (such as "+HIR+"pieces of colo"+HIB+"ured glass) at"+HIR+" the\n"+
  "o"+HIR+"ther end are s"+HIB+"uitably illumi"+HIR+"nated.  When t"+HIB+"he two mirrors"+HIR+" are\n"+
  HIB+"rot"+HIR+"ated or shifte"+HIB+"d one against "+HIR+"the other, the"+HIB+" pattern will\n"+
  "chang"+HIR+"e, thus produc"+HIB+"ing an almost "+HIR+"endless combin"+HIB+"ation of shapes\n"+
  "and col"+HIR+"ors."+NORM+"\n",
  "   The kaleidoscope is an "+HIB+"opt"+HIY+"ical"+NORM+" toy consisting of a tube\n"+
  "containing two plane m"+HIB+"irrors "+HIR+"pla"+HIY+"ced at "+NORM+"an angle of 60 degrees.\n"+
  "They are mounted s"+HIB+"o that "+HIR+"a symmetric"+HIY+"al patt"+NORM+"ern produced by\n"+
  "multiple refle"+HIB+"ction c"+HIR+"an be observed thro"+HIY+"ugh a p"+NORM+"eephole at \n"+
  "one end of"+HIB+" the ka"+HIR+"leidoscope itself.  However"+HIY+", this "+NORM+"happens \n"+
  "only when obje"+HIB+"cts (su"+HIR+"ch as pieces of col"+HIY+"oured g"+NORM+"lass) at the\n"+
  "other end are suit"+HIB+"ably il"+HIR+"luminated. "+HIY+" When t"+NORM+"he two mirrors are\n"+
  "rotated or shifted one"+HIB+" agains"+HIR+"t t"+HIY+"he othe"+NORM+"r, the pattern will\n"+
  "change, thus producing an al"+HIB+"mos"+HIY+"t en"+NORM+"dless combination of shapes\n"+
  "and colors.\n",
  "   The kaleidoscope is an "+HIY+"opt"+HIY+"ical"+NORM+" toy consisting of a tube\n"+
  "containing two plane m"+HIY+"irrors "+HIR+"pla"+HIY+"ced at "+NORM+"an angle of 60 degrees.\n"+
  "They are mounted s"+HIY+"o that "+HIR+"a symmetric"+HIY+"al patt"+NORM+"ern produced by\n"+
  "multiple refle"+HIY+"ction c"+HIR+"an be observed thro"+HIY+"ugh a p"+NORM+"eephole at \n"+
  "one end of"+HIY+" the ka"+HIR+"leidoscope itself.  However"+HIY+", this "+NORM+"happens \n"+
  "only when obje"+HIY+"cts (su"+HIR+"ch as pieces of col"+HIY+"oured g"+NORM+"lass) at the\n"+
  "other end are suit"+HIY+"ably il"+HIR+"luminated. "+HIY+" When t"+NORM+"he two mirrors are\n"+
  "rotated or shifted one"+HIY+" agains"+HIR+"t t"+HIY+"he othe"+NORM+"r, the pattern will\n"+
  "change, thus producing an al"+HIY+"mos"+HIY+"t en"+NORM+"dless combination of shapes\n"+
  "and colors.\n",
  "   The kaleidoscope is an "+HIY+"opt"+HIY+"ical"+NORM+" toy consisting of a tube\n"+
  "containing two plane m"+HIY+"irrors "+HIC+"pla"+HIY+"ced at "+NORM+"an angle of 60 degrees.\n"+
  "They are mounted s"+HIY+"o that "+HIC+"a symmetric"+HIY+"al patt"+NORM+"ern produced by\n"+
  "multiple refle"+HIY+"ction c"+HIC+"an be observed thro"+HIY+"ugh a p"+NORM+"eephole at \n"+
  "one end of"+HIY+" the ka"+HIC+"leidoscope itself.  However"+HIY+", this "+NORM+"happens \n"+
  "only when obje"+HIY+"cts (su"+HIC+"ch as pieces of col"+HIY+"oured g"+NORM+"lass) at the\n"+
  "other end are suit"+HIY+"ably il"+HIC+"luminated. "+HIY+" When t"+NORM+"he two mirrors are\n"+
  "rotated or shifted one"+HIY+" agains"+HIC+"t t"+HIY+"he othe"+NORM+"r, the pattern will\n"+
  "change, thus producing an al"+HIY+"mos"+HIY+"t en"+NORM+"dless combination of shapes\n"+
  "and colors.\n",
  "   The kaleidoscope is an "+HIM+"optical"+NORM+" toy consisting of a tube\n"+
  "containing two plane m"+HIM+"irrors "+NORM+"pla"+HIM+"ced at "+NORM+"an angle of 60 degrees.\n"+
  "They are mounted s"+HIM+"o that "+NORM+"a symmetric"+HIM+"al patt"+NORM+"ern produced by\n"+
  "multiple refle"+HIM+"ction c"+NORM+"an be observed thro"+HIM+"ugh a p"+NORM+"eephole at \n"+
  "one end of"+HIM+" the ka"+NORM+"leidoscope itself.  However"+HIM+", this "+NORM+"happens \n"+
  "only when obje"+HIM+"cts (su"+NORM+"ch as pieces of col"+HIM+"oured g"+NORM+"lass) at the\n"+
  "other end are suit"+HIM+"ably il"+NORM+"luminated. "+HIM+" When t"+NORM+"he two mirrors are\n"+
  "rotated or shifted one"+HIM+" agains"+NORM+"t t"+HIM+"he othe"+NORM+"r, the pattern will\n"+
  "change, thus producing an al"+HIM+"most en"+NORM+"dless combination of shapes\n"+
  "and colors.\n",
  "   "+HIR+"The kal"+NORM+"eidoscope is an optical toy consisting of a "+HIR+"a tube"+NORM+"\n"+
  "containin"+HIR+"g two p"+NORM+"lane mirrors placed at an angl"+HIR+"e of 60"+NORM+" degrees.\n"+
  "They are mounte"+HIR+"d so th"+NORM+"at a symmetrical pa"+HIR+"ttern "+NORM+"produced by\n"+
  "multiple reflection c"+HIR+"an be ob"+NORM+"serve"+HIR+"d throu"+NORM+"gh a peephole at \n"+
  "one end of the kaleidoscope "+HIR+"itself. "+NORM+" However, this happens \n"+
  "only when objects (su"+HIR+"ch as p"+NORM+"ieces "+HIR+"of colo"+NORM+"ured glass) at the\n"+
  "other end are s"+HIR+"uitably"+NORM+" illuminated.  When"+HIR+" the tw"+NORM+"o mirrors are\n"+
  "rotated o"+HIR+"r shift"+NORM+"ed one against the other, the p"+HIR+"attern "+NORM+"will\n"+
  "cha"+HIR+"nge, th"+NORM+"us producing an almost endless combination "+HIR+"of shap"+NORM+"es\n"+
  "and colors.\n",
  "   "+HIB+"The kal"+NORM+"eidoscope is an optical toy consisting of a "+HIB+"a tube"+NORM+"\n"+
  "containin"+HIB+"g two p"+NORM+"lane mirrors placed at an angl"+HIB+"e of 60"+NORM+" degrees.\n"+
  "They are mounte"+HIB+"d so th"+NORM+"at a symmetrical pa"+HIB+"ttern "+NORM+"produced by\n"+
  "multiple reflection c"+HIB+"an be ob"+NORM+"serve"+HIB+"d throu"+NORM+"gh a peephole at \n"+
  "one end of the kaleidoscope "+HIB+"itself. "+NORM+" However, this happens \n"+
  "only when objects (su"+HIB+"ch as p"+NORM+"ieces "+HIB+"of colo"+NORM+"ured glass) at the\n"+
  "other end are s"+HIB+"uitably"+NORM+" illuminated.  When"+HIB+" the tw"+NORM+"o mirrors are\n"+
  "rotated o"+HIB+"r shift"+NORM+"ed one against the other, the p"+HIB+"attern "+NORM+"will\n"+
  "cha"+HIB+"nge, th"+NORM+"us producing an almost endless combination "+HIB+"of shap"+NORM+"es\n"+
  "and colors.\n",
  "   "+HIB+"The kal"+NORM+"eidoscope is an optical toy consisting of a "+HIB+"a tube"+NORM+"\n"+
  "containin"+HIB+"g two p"+NORM+"lane mirrors placed at an angl"+HIB+"e of 60"+NORM+" degrees.\n"+
  "They are mounte"+HIB+"d so th"+NORM+"at a symmetrical pa"+HIB+"ttern "+NORM+"produced by\n"+
  "multiple reflection c"+HIB+"an be ob"+NORM+"serve"+HIB+"d throu"+NORM+"gh a peephole at \n"+
  "one end of the kaleidoscope "+HIW+"itself. "+NORM+" However, this happens \n"+
  "only when objects (su"+HIR+"ch as p"+NORM+"ieces "+HIR+"of colo"+NORM+"ured glass) at the\n"+
  "other end are s"+HIR+"uitably"+NORM+" illuminated.  When"+HIR+" the tw"+NORM+"o mirrors are\n"+
  "rotated o"+HIR+"r shift"+NORM+"ed one against the other, the p"+HIR+"attern "+NORM+"will\n"+
  "cha"+HIR+"nge, th"+NORM+"us producing an almost endless combination "+HIR+"of shap"+NORM+"es\n"+
  "and colors.\n",
  "   "+HIB+"The kaleidoscope is an optical toy consisting of a a tube"+NORM+"\n"+
  "containin"+HIB+"g two plane mirrors placed at an angle of 60"+NORM+" degrees.\n"+
  "They are mounte"+HIB+"d so that a symmetrical pattern "+NORM+"produced by\n"+
  "multiple reflection c"+HIB+"an be observed throu"+NORM+"gh a peephole at \n"+
  "one end of the kaleidoscope "+HIW+"itself. "+NORM+" However, this happens \n"+
  "only when objects (su"+HIR+"ch as pieces of colo"+NORM+"ured glass) at the\n"+
  "other end are s"+HIR+"uitably illuminated.  When the tw"+NORM+"o mirrors are\n"+
  "rotated o"+HIR+"r shifted one against the other, the pattern "+NORM+"will\n"+
  "cha"+HIR+"nge, thus producing an almost endless combination of shap"+NORM+"es\n"+
  "and colors.\n",
  "   "+HIB+"The kaleidoscope is an optical toy consisting of a a tube"+HIY+"\n"+
  "containin"+HIB+"g two plane mirrors placed at an angle of 60"+HIY+" degrees.\n"+
  "They are mounte"+HIB+"d so that a symmetrical pattern "+HIY+"produced by\n"+
  "multiple reflection c"+HIB+"an be observed throu"+HIY+"gh a peephole at \n"+
  "one end of the kaleidoscope "+HIW+"itself. "+HIY+" However, this happens \n"+
  "only when objects (su"+HIR+"ch as pieces of colo"+HIY+"ured glass) at the\n"+
  "other end are s"+HIR+"uitably illuminated.  When the tw"+HIY+"o mirrors are\n"+
  "rotated o"+HIR+"r shifted one against the other, the pattern "+HIY+"will\n"+
  "cha"+HIR+"nge, thus producing an almost endless combination of shap"+HIY+"es\n"+
  "a"+HIR+"nd colors."+NORM+"\n",
  "   The ka"+HIR+"leidoscope is an optical toy consisting o"+NORM+"f a tube\n"+
  "containin"+HIR+"g two plane mirrors placed at an angle of"+NORM+" 60 degrees.\n"+
  "They are "+HIR+"mounted"+NORM+" so that a symmetrical patt"+HIR+"ern pro"+NORM+"duced by\n"+
  "multiple "+HIR+"reflect"+NORM+"ion can be observed through"+HIR+" a peep"+NORM+"hole at \n"+
  "one end o"+HIR+"f the k"+NORM+"aleidoscope itself.  Howeve"+HIR+"r, this"+NORM+" happens \n"+
  "only when"+HIR+" object"+NORM+"s (such as pieces of colour"+HIR+"ed glas"+NORM+"s) at the\n"+
  "other end"+HIR+" are su"+NORM+"itably illuminated.  When t"+HIR+"he two "+NORM+"mirrors are\n"+
  "rotated o"+HIR+"r shifted one against the other, the patt"+NORM+"ern will\n"+
  "change, t"+HIR+"hus producing an almost endless combinati"+NORM+"on of shapes\n"+
  "and colors.\n",
  "   The ka"+HIB+"leidoscope is an optical toy consisting o"+NORM+"f a tube\n"+
  "containin"+HIB+"g two plane mirrors placed at an angle of"+NORM+" 60 degrees.\n"+
  "They are "+HIB+"mounted"+NORM+" so that a symmetrical patt"+HIB+"ern pro"+NORM+"duced by\n"+
  "multiple "+HIB+"reflect"+NORM+"ion can be observed through"+HIB+" a peep"+NORM+"hole at \n"+
  "one end o"+HIB+"f the k"+NORM+"aleidoscope itself.  Howeve"+HIB+"r, this"+NORM+" happens \n"+
  "only when"+HIB+" object"+NORM+"s (such as pieces of colour"+HIB+"ed glas"+NORM+"s) at the\n"+
  "other end"+HIB+" are su"+NORM+"itably illuminated.  When t"+HIB+"he two "+NORM+"mirrors are\n"+
  "rotated o"+HIB+"r shifted one against the other, the patt"+NORM+"ern will\n"+
  "change, t"+HIB+"hus producing an almost endless combinati"+NORM+"on of shapes\n"+
  "and colors.\n",
  "   The ka"+HIB+"leidoscope is an optical toy consisting o"+NORM+"f a tube\n"+
  "containin"+HIB+"g two plane mirrors placed at an angle of"+NORM+" 60 degrees.\n"+
  "They are "+HIB+"mounted"+HIR+" so that a symmetrical patt"+HIB+"ern pro"+NORM+"duced by\n"+
  "multiple "+HIB+"reflect"+HIR+"ion can be observed through"+HIB+" a peep"+NORM+"hole at \n"+
  "one end o"+HIB+"f the k"+HIR+"aleidoscope itself.  Howeve"+HIB+"r, this"+NORM+" happens \n"+
  "only when"+HIB+" object"+HIR+"s (such as pieces of colour"+HIB+"ed glas"+NORM+"s) at the\n"+
  "other end"+HIB+" are su"+HIR+"itably illuminated.  When t"+HIB+"he two "+NORM+"mirrors are\n"+
  "rotated o"+HIB+"r shifted one against the other, the patt"+NORM+"ern will\n"+
  "change, t"+HIB+"hus producing an almost endless combinati"+NORM+"on of shapes\n"+
  "and colors.\n",
  "   The ka"+HIW+"leidoscope is an optical toy consisting o"+NORM+"f a tube\n"+
  "containin"+HIW+"g two plane mirrors placed at an angle of"+NORM+" 60 degrees.\n"+
  "They are "+HIW+"mounted"+HIM+" so that a symmetrical patt"+HIW+"ern pro"+NORM+"duced by\n"+
  "multiple "+HIW+"reflect"+HIM+"ion can be observed through"+HIW+" a peep"+NORM+"hole at \n"+
  "one end o"+HIW+"f the k"+HIM+"aleidoscope itself.  Howeve"+HIW+"r, this"+NORM+" happens \n"+
  "only when"+HIW+" object"+HIM+"s (such as pieces of colour"+HIW+"ed glas"+NORM+"s) at the\n"+
  "other end"+HIW+" are su"+HIM+"itably illuminated.  When t"+HIW+"he two "+NORM+"mirrors are\n"+
  "rotated o"+HIW+"r shifted one against the other, the patt"+NORM+"ern will\n"+
  "change, t"+HIW+"hus producing an almost endless combinati"+NORM+"on of shapes\n"+
  "and colors.\n",
  "   The ka"+HIM+"leidoscope is an optical toy consisting o"+NORM+"f a tube\n"+
  "containin"+HIM+"g two plane mirrors placed at an angle of"+NORM+" 60 degrees.\n"+
  "They are "+HIM+"mounted"+NORM+" so that a symmetrical patt"+HIM+"ern pro"+NORM+"duced by\n"+
  "multiple "+HIM+"reflect"+NORM+"ion can be observed through"+HIM+" a peep"+NORM+"hole at \n"+
  "one end o"+HIM+"f the k"+NORM+"aleidoscope itself.  Howeve"+HIM+"r, this"+NORM+" happens \n"+
  "only when"+HIM+" object"+NORM+"s (such as pieces of colour"+HIM+"ed glas"+NORM+"s) at the\n"+
  "other end"+HIM+" are su"+NORM+"itably illuminated.  When t"+HIM+"he two "+NORM+"mirrors are\n"+
  "rotated o"+HIM+"r shifted one against the other, the patt"+NORM+"ern will\n"+
  "change, t"+HIM+"hus producing an almost endless combinati"+NORM+"on of shapes\n"+
  "and colors.\n",
  "   The kaleidoscope is an "+HIW+"optical"+NORM+" toy consisting of a tube\n"+
  "containing two plane m"+HIW+"irrors "+NORM+"pla"+HIW+"ced at "+NORM+"an angle of 60 degrees.\n"+
  "They are mounted s"+HIW+"o that "+NORM+"a symmetric"+HIW+"al patt"+NORM+"ern produced by\n"+
  "multiple refle"+HIW+"ction c"+NORM+"an be observed thro"+HIW+"ugh a p"+NORM+"eephole at \n"+
  "one end of"+HIW+" the ka"+NORM+"leidoscope itself.  However"+HIW+", this "+NORM+"happens \n"+
  "only when obje"+HIW+"cts (su"+NORM+"ch as pieces of col"+HIW+"oured g"+NORM+"lass) at the\n"+
  "other end are suit"+HIW+"ably il"+NORM+"luminated. "+HIW+" When t"+NORM+"he two mirrors are\n"+
  "rotated or shifted one"+HIW+" agains"+NORM+"t t"+HIW+"he othe"+NORM+"r, the pattern will\n"+
  "change, thus producing an al"+HIW+"most en"+NORM+"dless combination of shapes\n"+
  "and colors.\n",
  HIR+"   The k"+HIY+"aleidosc"+HIR+"ope is a"+HIY+"n optica"+HIR+"l toy co"+HIY+"nsisting"+HIR+" of a tu"+HIY+"be\n"+
  HIR+"conta"+HIY+"ining tw"+HIR+"o plane "+HIY+"mirrors "+HIR+"placed a"+HIY+"t an ang"+HIR+"le of 60"+HIY+" degrees.\n"+
  HIR+"Th"+HIY+"ey are m"+HIR+"ounted s"+HIY+"o that a"+HIR+" symmetr"+HIY+"ical pat"+HIR+"tern pro"+HIY+"duced by\n"+
  HIY+"multipl"+HIR+"e reflec"+HIY+"tion can"+HIR+" be obse"+HIY+"rved thr"+HIR+"ough a p"+HIY+"eephole "+HIR+"at \n"+
  HIY+"one "+HIR+"end of t"+HIY+"he kalei"+HIR+"doscope "+HIY+"itself. "+HIR+" However"+HIY+", this h"+HIR+"appens \n"+
  HIY+"o"+HIR+"nly when"+HIY+" objects"+HIR+" (such a"+HIY+"s pieces"+HIR+" of colo"+HIY+"ured gla"+HIR+"ss) at the\n"+
  HIR+"other"+HIY+" end are s"+HIR+"uitably "+HIY+" illumi"+HIR+"nated.  "+HIY+"When the"+HIR+" two mir"+HIY+"rors are\n"+
  HIR+"ro"+HIY+"tated or"+HIR+" shifted"+HIY+" one aga"+HIR+"inst the"+HIY+" other, "+HIR+"the patt"+HIY+"ern will\n"+
  HIY+"change,"+HIR+" thus pr"+HIY+"oducing "+HIR+"an almos"+HIY+"t endles"+HIR+"s combin"+HIY+"ation of"+HIR+" shapes\n"+
  HIY+"and "+HIR+"colors."+NORM+"\n",
  HIM+"   The k"+HIY+"aleidosc"+HIM+"ope is a"+HIY+"n optica"+HIM+"l toy co"+HIY+"nsisting"+HIM+" of a tu"+HIY+"be\n"+
  HIM+"conta"+HIY+"ining tw"+HIM+"o plane "+HIY+"mirrors "+HIM+"placed a"+HIY+"t an angl"+HIM+"e of 60 "+HIY+"degrees.\n"+
  HIM+"Th"+HIY+"ey are m"+HIM+"ounted s"+HIY+"o that a"+HIM+" symmetr"+HIY+"ical patt"+HIM+"ern prod"+HIY+"uced by\n"+
  HIY+"multiple"+HIM+" reflect"+HIY+"ion can "+HIM+"be obser"+HIY+"ved thro"+HIM+"ugh a pe"+HIY+"ephole a"+HIM+"t \n"+
  HIY+"one e"+HIM+"nd of th"+HIY+"e kaleid"+HIM+"oscope i"+HIY+"tself.  "+HIM+"However,"+HIY+" this ha"+HIM+"ppens \n"+
  HIY+"on"+HIM+"ly when "+HIY+"objects "+HIM+"(such as"+HIY+" pieces "+HIM+"of colour"+HIY+"ed glass"+HIM+") at the\n"+
  HIM+"other "+HIY+"end are "+HIM+"suitably"+HIY+" illumin"+HIM+"ated.  W"+HIY+"hen the "+HIM+"two mirr"+HIY+"ors are\n"+
  HIM+"rot"+HIY+"ated or "+HIM+"shifted "+HIY+"one agai"+HIM+"nst the "+HIY+"other, t"+HIM+"he patte"+HIY+"rn will\n"+
  HIY+"change, "+HIM+"thus pro"+HIY+"ducing a"+HIM+"n almost"+HIY+" endless"+HIM+" combina"+HIY+"tion of "+HIM+"shapes\n"+
  HIY+"and c"+HIR+"olors."+NORM+"\n",
  HIB+HIW+" "+HIB+"  T"+HIW+"h"+HIB+"e k"+HIW+"a"+HIB+"lei"+HIW+"d"+HIB+"osc"+HIW+"o"+HIB+"pe "+HIW+"i"+HIB+"s a"+HIR+"n optical toy consisting of a tube"+NORM+"\n"+
  HIB+"co"+HIW+"n"+HIB+"tai"+HIW+"n"+HIB+"ing"+HIW+" "+HIB+"two"+HIW+" "+HIB+"pla"+HIW+"n"+HIB+"e m"+HIW+"i"+HIB+"rr"+HIW+"ors placed at an angle of 60 degrees."+NORM+"\n"+
  HIB+HIW+"T"+HIB+"hey"+HIW+" "+HIB+"are"+HIW+" "+HIB+"mou"+HIW+"n"+HIB+"ted"+HIW+" "+HIB+"so "+HIW+"t"+HIB+"hat"+HIW+" "+HIR+"a symmetrical pattern produced by"+NORM+"\n"+
  HIB+"mu"+HIW+"l"+HIB+"tip"+HIW+"l"+HIB+"e r"+HIW+"e"+HIB+"fle"+HIW+"c"+HIB+"tio"+HIW+"n"+HIB+" ca"+HIW+"n"+HIB+" b"+HIW+"e observed through a peephole at"+NORM+" \n"+
  HIB+HIW+"o"+HIB+"ne "+HIW+"e"+HIB+"nd "+HIW+"o"+HIB+"f t"+HIW+"h"+HIB+"e k"+HIW+"a"+HIB+"lei"+HIW+"d"+HIB+"osc"+HIW+"o"+HIR+"pe itself.  However, this happens"+NORM+" \n"+
  HIW+"only when objects (such as pieces of coloured glass) at the"+NORM+"\n"+
  HIR+"other end are suitably illuminated.  When the two mirrors are"+NORM+"\n"+
  HIW+"rotated or shifted one against the other, the pattern will"+NORM+"\n"+
  HIR+"change, thus producing an almost endless combination of shapes"+NORM+"\n"+
  HIW+"and colors."+NORM+"\n",
  "   "+HIB+"The kaleidoscope is an optical toy consisting of a a tube"+HIY+"\n"+
  "containin"+HIB+"g two plane mirrors placed at an angle of 60"+HIY+" degrees.\n"+
  "They are mounte"+HIB+"d so that a symmetrical pattern "+HIY+"produced by\n"+
  "multiple reflection c"+HIB+"an be observed throu"+HIY+"gh a peephole at \n"+
  "one end of the kaleidoscope "+HIW+"itself. "+HIY+" However, this happens \n"+
  "only when objects (su"+HIR+"ch as pieces of colo"+HIY+"ured glass) at the\n"+
  "other end are s"+HIR+"uitably illuminated.  When the tw"+HIY+"o mirrors are\n"+
  "rotated o"+HIR+"r shifted one against the other, the pattern "+HIY+"will\n"+
  "cha"+HIR+"nge, thus producing an almost endless combination of shap"+HIY+"es\n"+
  "a"+HIR+"nd colors."+NORM+"\n"
  });
  
  return longdesc[random(42)];
}

/* This function sets the global variable Master equal to the master room (entrance.c) 
   This is set at the time of cloning by the master room. - Sparrow
*/
void
set_master(object ob) {
  Master = ob;
  return;
}

/* This function will remove the room from the master object if it is descructed 
   by the game. This is important to keep things running smoothly. - Sparrow
*/
void
remove_object(object caller) {
  Master->remove_room(this_object());
  return;
}