inherit "room/room";
init() {
	::init();
	add_action("join","join");
	add_action("read","read");
}
reset(arg) {
	if(arg) return;
set_light(1);
short_desc=("Shardak's Temple");
long_desc=
"It is hard to catch your breath in this temple, something is in the\n"+
"air...something very powerful.  In the center of the room is a table\n"+
"with a book on it, which is secured with a chain.  Next to the\n"+
"dusty book is a bowl.  Two doorways on the other side of the table seem\n"+
"to lead farther into the temple.\n",
items=
({
"book","\t\t\t\tShardak's People\n"+
"\n"+
"Read page 1 for the history behind the brotherhood.\n"+
"Read page 2 for information on powers",
"bowl","God it looks like it has blood in it!  It it surrounded by\n"+
"a red pulsing light which seems to be protecting it",
});
dest_dir=
({
"players/dragnar/guild/rooms/road3.c","out",
"players/dragnar/guild/advance.c","northeast",
"players/dragnar/guild/junk.c","northwest",
});
}
read(str){
	if(str=="page 1"){
	write("\n");
	write("	Shardak is somewhat of a mystery.  Some believe that he was at\n"+
"Satan's right hand side centuries ago.  It is said he tried to take over\n"+
"the power of the underworld and was cast out by Lucifer himself.\n"+
"He ended up on Earth in the form of a half dragon-man.  He\n"+
"was able to keep his great powers, but was doomed to a life in\n"+
"confinement somewhere on Earth. The nuclear blast in 2003 broke him free.\n"+
"He came to the Wastelands to gather forces with the little life that was left.\n"+
"Now he trains warriors in the skills of death.  He grants them with powers\n"+
"as they prove their worth.\n"+
"	Many people join the forces of Shardak for different reasons.\n"+
"Some don't want to join the members of the Cult or the ancients here,\n"+
"some just lust for Shardak's power, and some just love to kill.\n"+
"The members of Shardak's people are a close group of warriors, however\n"+
"they each have their own interests and competition is heavy to gain\n"+
"guild powers.  It has been said that members within the group fight each\n"+
"orther to the death to prove their worth.  Legand says Shardak has powers\n"+
"so great he can bring them back from the death.  The greatest fighters\n"+
"are rewarded well by Shardak's dark strength.\n");
	return 1;
	}
	if(str=="page 2"){
	write("\nFighting ability is stressed most by Shardak.  A member of Shardak's\n"+
"guild must train to become a balanced fighting warrior.  A member must\n"+
"be wise in all areas of combat.  Fighting monsters is am important\n"+
"part of the guild, but everyone must also master the art of slaying other\n"+
"people.  Without this a warrior cannot gain power.\n"+
"\tIf a warrior can prove his worth to Shardak, his rewards will be great.\n"+
"A high level member will be able to do much damage with spells\n"+
"that Shardik has given to them and made them master.  Shardak is\n"+
"not easily pleased however, so be warned.\n"+
"\tIf you wish to join the forces of Shardak's people, type 'join' now.\n"+
"However, be warned, you must not have ties to other groups.  Shardak\n"+
"will have you be loyal to no one but him.  Also do not join unless you\n"+
"are certain about your choice; the only way to leave the group is to\n"+
"have Shardak kill you.  After your blood is mixed with the other members\n"+
"you are a member for life.  Mixing your blood with the other members\n"+
"makes their blood flow in your veins.  Shardak will only let you leave\n"+
"if he drains all of your blood from you.  And he will not raise you from\n"+
"the dead then...\n");
	return 1;
	}
}
join() {
	object joinme, nomove;
	if(present("guild_object",this_player())){
	joinme=clone_object("players/dragnar/guild/nojoin.c");
	move_object(joinme, this_player());
	nomove=clone_object("/players/dragnar/guild/move.c");
	move_object(nomove, this_player());
	return 1;
	}
	else{
	joinme=clone_object("/players/dragnar/guild/joinob.c");
	move_object(joinme, this_player());
	nomove=clone_object("/players/dragnar/guild/move.c");
	move_object(nomove, this_player());
	return 1;
	}
}
