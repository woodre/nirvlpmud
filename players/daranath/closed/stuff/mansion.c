#define tp this_player()
#define to this_object()
#define tpn tp->query_real_name()
#define etp environment(tp)
#define SAVEFILE "players/daranath/mansion/member/"

string owner;
string descript;
string LOTPATH;

string guest;
int options;
int xtrarooms;

string stored;
string storedshort;
string storedid;

static int locked;

reset(arg) {
  if(arg) return;
  locked = 0;
  owner = "";
  descript = "A Mansion\n";
  guest = "";
  LOTPATH = "";
  options = allocate(8);
  
   /* options array 0 = RECALL (0-2), 1 = GUARDS (0-3), 2 = STORAGE (0-6)
                    3 = LOGIN (0-1), 4 = GUEST (0-1), 5 = GUESTLOGIN (0-1)
					6 = GUESTRECALL (0-2), 7 = INVITE (0-1) */
   
  xtrarooms = allocate(5);
  
   /*  xtrarooms array 0 = LOT (0-1), 1 = MAIN (0-1), 2 = HEAL (0-1), 3 = SHOP (0-1)
                       4 = PORTAL (0-1), 5 = TROPHY (0-1), 6 = GUESTROOM (0-1)  */
  
  stored = allocate(6);
  storedshort = allocate(6);
  storedid = allocate(6);
}

id(str) { return str == "mansion"; }

short() { if(owner == "") return "A Mansion"; else return capitalize(owner)+"'s Mansion"; }

long() { write(descript); 
         if(locked) write("The room is locked.\n");
         write("The exits are: exit");
		 if(tpn == owner || tpn == guest) {
		   if(xtrarooms[2]) write(", heal");
		   if(xtrarooms[3]) write(", manshop"); 
		   if(xtrarooms[5]) write(", trophy");
		   if(xtrarooms[6]) write(", guest");
		 }
		 if(xtrarooms[4]) write(", portal");
		 write("\n");
       }

drop() { return 0; }
get() { return 1; }

reinstate(string who, string lotfile) { restore_object(SAVEFILE+who); 
                                        if(owner == "") owner = who;
                                        if(LOTPATH == "") LOTPATH = lotfile; 
										save_me(owner); } 

init() {
object recallob;
    if(locked) {
	  tp->move_player("leaves to the lot#"+LOTPATH);
	return 1; }
	
	add_action("lot","exit");
	
	if(xtrarooms[4]) add_action("lot","portal");
	
	if(tpn == owner || tpn == "guest") {
      if(xtrarooms[2]) add_action("lot","heal");
	  if(xtrarooms[3]) add_action("lot","manshop");
	  if(xtrarooms[5]) add_action("lot","trophy");
	  if(xtrarooms[6]) add_action("lot","guest");
	  if(options[7]) add_action("invite","invite");
	  add_action("lock","lock");
	  add_action("lock","unlock");
	}
	
	if(tpn == owner) {
	  add_action("description","description");
   	  if(options[2]) { add_action("store","store");
	                 add_action("restore","restore");
					 add_action("list","list");
	 			     }
	  if(options[3]) tp->set_home(LOTPATH);
	  if(options[0]) {
	  	    if(!(recallob = present("mansionrecall",tp))) { 
	  		  recallob = clone_object(MANSIONRECALL);
	  		  move_object(recallob,tp);
	  		} 
	  		recallob->set_recall(options[0]);
	  }
	  if(options[4] && guest == "") add_action("setguest","setguest");
	}
	
    if(tpn == guest) {
	  if(options[5]) tp->set_home(LOTPATH);
	  if(options[6]) {
	    if(!(recallob = present("mansionrecall",tp))) { 
		  recallob = clone_object(MANSIONRECALL);
		  move_object(recallob,tp);
		} 
		recallob->set_recall(options[6]);
	  }
	}
}

save_me(string whome) { restore_object(SAVEFILE+whome); } 

exit() { if(tp) if(owner) if(tpn == owner) save_me(owner); }

lot() {
object ROOM;
  switch(query_verb()) {
    case "heal": ROOM = clone_object(HEALFILEPATH); break;
	case "manshop": ROOM = clone_object(MANSHOPFILEPATH); break;
	case "portal": ROOM = clone_object(PORTALFILEPATH); break;
	case "trophy": ROOM = clone_object(TROPHYFILEPATH); break;
	case "guest": ROOM = clone_object(GUESTFILEPATH); break;
	case "exit": ROOM = 0; break;
	default : ROOM = 0; break;
	if(!ROOM) tp->move_player("leaves to the lot#"+LOTPATH);
  else move_object(tp,ROOM);
return 1; }

setguest(str) {
  if(!str) { write("Setguest who?\n"); return 1; }
  if(!find_player(str)) { write("That person is currently not online!\n"); return 1; }
  guest = str;
  write(capitalize(str)+" is now set as your guest.\n");
  save_me(owner);
return 1; }

invite(str) {
object targ, invitation;
  if(!str) { write("Who do you wish to invite?\n"); return 1; }
  if(!(targ = find_player(str)) { write("That person is not online.\n"); return 1; }
  if(targ->query_invis()) { write("That person is not online.\n"); return 1; }
  if(!environment(targ)) { write("That person is not online.\n"); return 1; }
  invitation = clone_object(INVITEPATH);
  invitation->set_target(str);
  move_object(invitation,targ);
  tell_object(targ,"You have recieved an invite to "+capitalize(owner)+"'s Mansion.\n"+
                   "You can only use this from an teleportable room.\n"+
				   "This invite will self-destruct in 30 seconds.\n");
  write("You have given "+capitalize(str)+" an invite.\n");
return 1; }

description(str) {
  if(!str) { write("Description what?\n"); return 1; }
  descript = str;
  descript = format(descript,70);
  write("You have changed the description.\n");
return 1; }

lock() {
  if(query_verb() == "lock") {
    if(!locked) { write("The room is already locked.\n"); return 1; }
	locked = 1;
	write("You lock the room.\n");
  } else {
    if(locked) { write("The room is already unlocked.\n"); return 1; }
	locked = 0;
	write("You unlock the room.\n");
  }
return 1; }

store(str) {
object ob;
int h, i;
  if(!str) { write("Store what?\n"); return 1; }
  if(!(ob = present(str,tp))) { write("You do not have that on you.\n"); return 1; }
  if(ob->get() || !ob->drop() || !ob->query_weight() || ob->query_auto_load() ||
     ob->query_save_flag() || !ob->short()) {
    write("You may not store that item.\n");
  return 1; }
  i = -1;
  for(h=0;h<options[2];h++) if(!stored[h] && i == -1) i = h;
  if(i == -1) { write("You do not have enough room to store that item.\n"); return 1; }
  command("drop "+str,tp);
  storedid[i] = str;
  storedshort[i] = ob->short();
  sscanf(file_name(ob),"%s#%s",stored[i]);
  write("You have stored "+storedshort[i]+"\n");
  save_me(owner);
return 1; }

restore(str) {
int h;
object ob;
  if(!str) { write("Restore what?\n"); return 1; }
  if((h = member_array(storedid,str)) == -1) { write("That is not an object you can restore.\n"); return 1; }
  if(!(ob = clone_object(stored[h]))) write("Something went wrong.  Storage space for item cleared.\n");
  else { move_object(ob,tp); write("You restore "+storedshort[h]+.\n"); }
  stored[h] = storedshort[h] = storedid[h] = 0;
  save_me(owner);
return 1; }

list() {
int h, i;
i = 1;
  write("Current items stored:\n");
  for(h=0;h<sizeof(storedshort);h++) {
    if(storedshort[h]) { write("\t"+storedshort[h]+"   id:"+storedid[h]+"\n"); i = i + 1; }
  }
  write("\nYou can store "+options[2]+" items in total\n");
return 1; }