int quest_point;        /* amt of quest pts you have earned */
string quests;

add_quest_point(num) {
   quest_point += num;
}

query_quest_point() { return quest_point; }

recalc_quest() {
   string rest, tmp, rest_tmp;
   int i;
   quest_point = 0;
   rest = quests;
   while (rest) {
     i = sscanf(rest, "%s#%s", tmp, rest_tmp);
     if (i < 2) {
       tmp = rest;
       rest_tmp = 0;
     }
     quest_point += quest_pt_physical(tmp) + quest_pt_mental(tmp);
     rest = rest_tmp;
   }
   return quest_point;
}

quest_pt_physical(str) {
  int value;
  switch(str) {
    case "sinja_quest"	: value = 7; break;
    case "jungle_village"      : value = 2; break;
    case "despoina"    : value = 8; break;
    case "toy_store"   : value = 3; break;
    case "t_rexs"      : value = 5; break;
    case "keep_dragons" : value = 8; break;
    case "key_quest"   : value = 5; break;
    case "hooks_hand"  : value = 5; break;
    case "lost_rood"   : value = 7; break;
    case "phantasm_puzzle" : value = 6; break;
    case "protoculture" : value = 5; break;
    case "fallen_lands" : value = 7; break;
    case "chisel" : value = 5; break;
    case "springfield" : value = 4; break;
    case "angmar" : value = 6; break;
    case "padrone" : value = 3; break;
    case "super" : value = 4; break;
    case "disk_quest" : value = 4; break;
    case "keivjam" : value = 4; break;
    case "Ursa" : value = 7; break;
    case "cyclops_mace": value = 3; break;
    case "staff"       : value = 9; break;
    case "medallion"   : value = 5; break;
    case "brain_quest" : value = 0; break;
    case "ring"        : value = 1; break;
    case "orc_slayer"  : value = 2; break;
    case "melko"       : value = 7; break;
    case "temple_quest" : value = 6; break;
    case "trekkie"     : value = 7; break;
    case "rod_quest"   : value = 5; break;
    case "waste_lands"  : value = 9; break;
    case "M*A*S*H"     : value = 4;  break;
    case "lost_cities"        : value = 5; break;
    case "archwizard"         : value = 10; break;
    case "inculta_creperum"   : value = 6;  break;
    case "mastermind"   : value = 4;  break;
    case "graduation"   : value = 4;  break;
    case "ninja_turtles": value = 9; break;

/*  OLD QUESTS LEFT IN FOR QUEST POINTS ONLY  */
		case "unterrealm"	: value = 9; break;
		case "hades_quest"	: value = 8; break;
		case "vale"		: value = 7; break;
		case "loth_quest"	: value = 8; break;
		case "sage"		: value = 9; break;
		case "hermit"		: value = 9; break; /* staff */
		case "orb_of_evil"	: value = 6; break;
		case "ys"		: value =10; break;
		case "soul_search"	: value = 9; break;
		case "fear_fuckos"	: value =10; break;
		case "grail"		: value = 3; break;
                case "blind_boy"   : value = 5; break;
		case "bishops_ring"	: value = 9; break;
                case "*sabbath*"        : value = 7; break;
   }
   return(value);
}

quest_pt_mental(str) {
  int value;
  switch(str) {
      case "sinja_quest"	: value = 4; break;
      case "jungle_village"    : value = 6; break;
      case "despoina"    : value = 5; break;
      case "toy_store"   : value = 5; break;
      case "t_rexs"      : value = 5; break;
      case "keep_dragons" : value = 6; break;
      case "key_quest"   : value = 8; break;
      case "hooks_hand"  : value = 6; break;
      case "lost_rood"   : value = 9; break;
      case "phantasm_puzzle" : value = 9; break;
      case "protoculture" : value = 7; break;
      case "fallen_lands" : value = 5; break;
      case "chisel" : value = 7; break;
      case "super" : value = 7; break;
      case "springfield" : value = 6; break;
      case "angmar" : value = 3; break;
      case "padrone" : value = 3; break;
      case "disk_quest" : value = 6; break;
      case "cyclops_mace": value = 3; break;
      case "staff"       : value = 9; break;
      case "medallion"   : value = 7; break;
      case "brain_quest" : value = 9; break;
      case "ring"        : value = 3; break;
      case "orc_slayer"  : value = 2; break;
      case "melko"       : value = 8; break;
      case "temple_quest" : value = 4;break;
      case "keivjam" : value =5; break;
      case "Ursa" : value = 6; break;
      case "trekkie"     : value = 6; break;
      case "rod_quest"   : value = 4; break;
      case "waste_lands"  : value = 7; break;
      case "M*A*S*H"    : value = 5; break;
      case "lost_cities" : value = 10; break;
      case "archwizard"  : value = 8; break;
      case "inculta_creperum" : value = 4; break;
      case "mastermind":        value = 7; break;
      case "graduation":      value = 5; break;
      case "ninja_turtles": value = 2; break;

/* Coding tests */
      case "code1": value=1; break;
      case "code2": value=2; break;
      case "code3": value=3; break;
      case "code4": value=4; break;
      case "code5": value=5; break;
      case "code6": value=6; break;
      case "code7": value=7; break;
      case "code8": value=8; break;
      case "code9": value=9; break;
      case "code10": value=10; break;
      case "code11": value=11; break;
      case "code12": value=12; break;
      case "code13": value=13; break;
      case "code14": value=14; break;
      case "code15": value=15; break;
      case "code16": value=16; break;
      case "code17": value=17; break;
      case "code18": value=18; break;
      case "code19": value=19; break;
      case "code20": value=20; break;
      case "code21": value=21; break;
      case "code22": value=22; break;
      case "code23": value=23; break;
      case "code24": value=24; break;
      case "code25": value=25; break;
      case "code26": value=26; break;
      case "code27": value=27; break;
      case "code28": value=28; break;
      case "code29": value=29; break;
      case "code30": value=30; break;
      case "code31": value=31; break;

/*  OLD QUESTS LEFT IN FOR QUEST POINTS ONLY  */
		case "unterrealm"	: value = 7; break;
		case "hades_quest"	: value = 5; break;
		case "vale"		: value = 7; break;
		case "loth_quest"	: value = 8; break;
		case "sage"		: value = 7; break;
		case "hermit"		: value = 9; break;
		case "orb_of_evil"	: value = 7; break;
		case "ys"		: value = 9; break;
		case "soul_search"	: value = 5; break;
		case "fear_fuckos"	: value = 4; break;
		case "grail"		: value = 3; break;
                case "blind_boy"   : value = 5; break;
		case "bishops_ring"	: value = 9; break;
                case "*sabbath*"        : value = 9; break;
   }
   return(value);
}

set_quest(q) {
    if (!q)
	return;
    if (query_quests(q))
	return 0;
    add_quest_point(quest_pt_mental(q) + quest_pt_physical(q));
/* If this is first time quest is done, add quest pts ^ */
    if (previous_object()) {
	log_file("QUESTS", name + ": " + q + " from " +
		 object_name(previous_object()) + ctime(time()) + "\n");
       log_file("QUESTS", name + ":"+quests+"\n");
	if (this_player() && this_player() != this_object() &&
	  query_ip_number(this_player()))
	    log_file("QUESTS", "Done by " +
		     this_player()->query_real_name() + ctime(time()) + "\n");
    }
    if (quests == 0)
	quests = q;
    else
	quests = quests + "#" + q;
    return 1;
}

clear_quest() { 
if(this_player()->query_level() < 999) return 0;
quests=0;
quest_point = 0;
return 1;
}