#include "/players/pavlik/guild/defs.h"
#undef HAND
#undef OFFHAND
#define HAND GOB->query_handed(0)
#define OFFHAND GOB->query_handed(1)
#define SAVE_INTERVAL 600

object donation_leader;
object *Meijin;
int *donation_leaders;

id(str) {
  return str == GUILDNAME+"_guild_master" || str == "pavlik_guild_master";
}

reset(arg) {
  if(arg) return;
  Meijin = ({ });
  donation_leaders = ({ 0, });
  move_object(this_object(), OBJ_ROOM);
  call_out("auto_save", SAVE_INTERVAL);
}

get() { return 0; }
drop() { return 1; }
short() { return "The Meijin Daemon"; }
long() { write("The Meijin Daemon\n"); return ; }
clean_up() { return 1; }
query_Meijin() { return Meijin; }

/****************************************************/
/* Add/Remove players guild object to the registry. */
/****************************************************/
add_Meijin(gob) {
  if(member_array(gob, Meijin) < 0) {
	Meijin += gob;
  }
}

remove_Meijin(gob) {
  if(member_array(gob, Meijin) == 0) {
	Meijin -= gob;
  }
}

/******************************************************/
/* Auto save players guild file                       */
/******************************************************/
auto_save() {
  int i;

  for(i=0; i<sizeof(Meijin); i++) {
	if(Meijin[i]) {
		if(!(Meijin[i]->id(ALLYID))) {
			Meijin[i]->save_me(1);
			tell_object(environment(Meijin[i]), HIY+"()"+NORM+" Autosave.\n");
			if(!random(4)) Meijin[i]->add_donations(5+random(16));
		}
	}
	else {
		/* clean out dead objects */
		Meijin -= Meijin[i];
	}
  }
  call_out("auto_save", SAVE_INTERVAL);
  return 1;
}

/******************************************************/
/* Get the guild exp cost for guild ranks             */
/******************************************************/
query_rank_cost(level) {
  int i, inc, amount;

  if(!level) return 0;
  amount = BASE_GUILD_COST;

  for(i=1; i<level; i++) {
	if(amount > 100000000) return 100000000;        /* avoid overruns */
	if(amount < 100000) inc = (amount * 4) / 9;
	else if(amount < 1000000) inc = (amount / 9);
	else if(amount < 2500000) inc = (amount / 15);
	else if(amount < 3500000) inc = (amount / 24);
	else inc = (amount / 48);
	amount += inc;
  }
  return amount;
}

/*******************************************************/
/* Determine how many practices we get                 */
/*******************************************************/
get_practices(rank) {
  if(rank < 10) return 1;
  else if(rank < 26) return 1 + random(4);
  else return 2 + random(4);
}

/*******************************************************/
/* Determine how much a stat or skill increases        */
/*******************************************************/
get_practice_increase(amt) {
  return 3 + random(9);
}
 
/*******************************************************/
/* Determine when we can learn a new skill             */
/*******************************************************/
get_skills(rank) {
  if(rank == 10 || rank == 12 || rank == 15 || rank == 18) return 1;
  if(rank == 21 || rank == 23 || rank == 26) return 1;
  if(rank == 32 || rank == 34 || rank == 36) return 1;
  if(rank == 40 || rank == 46) return 1;
  if(rank == 52 || rank == 55 || rank == 58) return 1;
  if(rank == 64 || rank == 69) return 1;
  if(rank == 75) return 1;
}

/*******************************************************/
/* Broadcast a message to all guild members            */
/*******************************************************/
guild_broadcast(str, flag) {
  int i;
  for(i=0; i<sizeof(Meijin); i++) {
	if(Meijin[i]) {
	if(!(Meijin[i]->query_guild_channel())) continue;
		if(flag && Meijin[i]->id(ALLYID)) continue;
		if(environment(Meijin[i])) tell_object(environment(Meijin[i]), str);
	}
  }
  return 1;
}

/******************************************************/
/* Broadcast login message to all guild members       */
/******************************************************/
broadcast_login(obj, enter_msg, silent) {
  string beg, end;

  if(silent) return;
  if(!obj) return;
  if(obj->query_invis()) return;

  if(!enter_msg || sscanf(enter_msg, "%s$$%s", beg, end) != 2)
	guild_broadcast(HIB+"<(> "+HIW+capitalize(obj->query_real_name())+
	" has entered the game. "+HIB+"<)>\n"+NORM);
  else
	guild_broadcast(HIB+"<(> "+HIW+beg+capitalize(obj->query_real_name())+
	end+" "+HIB+"<)>\n"+NORM);

  return;
}


/******************************************************/
/* Broadcast logout message to all guild members      */
/******************************************************/
broadcast_logout(obj, exit_msg, silent) {
  string beg, end;

  if(silent) return;
  if(obj->query_invis()) return;


  if(!exit_msg || sscanf(exit_msg, "%s$$%s", beg, end) != 2)
	guild_broadcast(HIB+"<(> "+HIW+capitalize(obj->query_real_name())+
	" has left the game. "+HIB+"<)>\n"+NORM);
  else
	guild_broadcast(HIB+"<(> "+HIW+beg+capitalize(obj->query_real_name())+
	end+" "+HIB+"<)>\n"+NORM);

  return;
}


/********************************************************/
/* Calculate the on-line donation point Leaders         */
/********************************************************/
calc_donation_leaders() {
  int i;

  donation_leaders = ({ });
  for(i=0; i<sizeof(Meijin); i++) {
	if(Meijin[i]) donation_leaders += Meijin[i]->query_donations();
  }
  donation_leaders = sort_array(donation_leaders, "greater_fun");
  return 1;
}

greater_fun(a, b) {
  if(a < b) return 1;
  else return 0;
}

/***********************************************************/
/* Query the donation point leaders                        */
/***********************************************************/
query_donation_leader(pos) {
  calc_donation_leaders();
  return donation_leaders[pos];
}

query_donation_leaders() {
  calc_donation_leaders();
  return donation_leaders;
}

/***********************************************************/
/* Query the donation point bonus to guild exp             */
/***********************************************************/
query_donation_bonus(donations, amt) {
  if(donations == donation_leaders[0]) return (amt / 10);	/* 10% */
  if(donations == donation_leaders[1]) return (amt / 20);	/*  5% */
  if(donations == donation_leaders[2]) return (amt / 40);	/*  2% */
  return 0;
}

/****************************/
/* Query valid weapon types */
/****************************/
query_weapon_types() {
  string *weapons;

  weapons = ({
	"sword",
	"dagger",	/* includes knife */
	"axe",
	"mace",		/* includes hammer and club */
	"spear",	/* includes trident */
	"bow",		/* includes crossbow */
	"flail",	/* inclues whip */
	"staff",	/* includes stick */
	"polearm",
	"gun",
  });
  return weapons;
}

/***********************************/
/* Randomize the color of a string */
/***********************************/
rancol(str){
  string msg;
  int x;
  x = random(7);
  if(x == 0) msg = HIR+str+NORM; else
  if(x == 1) msg = HIG+str+NORM; else
  if(x == 2) msg = HIY+str+NORM; else
  if(x == 3) msg = HIB+str+NORM; else
  if(x == 4) msg = HIM+str+NORM; else
  if(x == 5) msg = HIC+str+NORM; else
  msg = HIW+str+NORM;
  return msg;
}

pad2(str, space) {
  int i, size, nochar;
  string a, new;

  nochar = 0;
  for(i=0; i<strlen(str); i++) {
        a = extract(str, i, i);
        if(a == ESC) nochar = 1;
        if(a == "m" && nochar == 1) {
                nochar = 0;
                continue;
        }
        if(!nochar) size++;
  }
  new = str;
  for(i=size; i<space; i++) new += " ";
  /* if(size > space) new = extract(new, 0, space-1); */
  return new;
}

