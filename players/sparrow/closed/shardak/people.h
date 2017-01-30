/*
* Guild members with special rights
* I guess some #define's will work as good as any daemon with save file
*/
#define GWIZ ({"vertebraker","laera","vital", "earwax"})
#define LAW ({ "worm", "amiro", "sunim" })
#define C_UNKNOWN -27
#define C_ALLY -1
#define C_GUEST 0
#define C_NOVICE 10
#define C_APPREN 20
#define C_JMAN 23
#define C_WARRIOR 26
#define C_ASSASSIN 27
#define C_BERSERKER 28
#define C_SENIOR 30
#define C_LAW 40
#define C_MBERSERKER 41
#define C_SPECIAL 42
#define C_MASTER 45
#define C_MAGUS 50

#define classtostr(x) (\
	x == C_NOVICE	? "Novice" :\
	x == C_APPREN	? "Apprentice" :\
	x == C_JMAN	? "Journeyman" :\
	x == C_WARRIOR	? "Warrior" :\
	x == C_ASSASSIN ? "Assassin" :\
	x == C_BERSERKER ? "Berzerker" :\
	x == C_SENIOR	? "Senior" :\
	x == C_LAW	? "Law" :\
	x == C_MBERSERKER  ? "Warlord" :\
	x == C_SPECIAL ? "Magistrate" :\
	x == C_MASTER	? "Master" :\
	x == C_MAGUS	? "Magus" :\
	x == C_GUEST	? "Guest" :\
	x == C_ALLY	? "Ally" :\
"Unknown")

#define strtoclass(x) (\
	x == "Novice"	? C_NOVICE :\
	x == "Apprentice" ? C_APPREN :\
	x == "Journeyman" ? C_JMAN :\
	x == "Warrior" ? C_WARRIOR :\
	x == "Assassin" ? C_ASSASSIN :\
	x == "Berzerker" ? C_BERSERKER :\
	x == "Senior" ? C_SENIOR :\
	x == "Law"	 ? C_LAW :\
	x == "Warlord" ? C_MBERSERKER :\
	x == "Master" ? C_MASTER :\
	x == "Magus" ? C_MAGUS :\
	x == "Guest" ? C_GUEST :\
	x == "Magistrate" ? C_SPECIAL :\
	x == "Ally" ? C_ALLY :\
C_UNKNOWN)

#define gwiz_tell(x, o)
/*
{
	object a;
	int i;
	for(i = 0; i < sizeof(GWIZ); i ++)
	if(a = find_player(GWIZ[i]))
	{
		if(o && pointerp(o)) if(member_array(a, o) == -1) tell_object(a, x);
		else if(o && objectp(o)) if(a != o) tell_object(a, x);
	}
}
*/
