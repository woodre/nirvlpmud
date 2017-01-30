string	Caught;
string	MatchFunc;
object	Talker;
int	busy_catch_tell;
mixed	talk_ob;
string	*talk_match, *talk_func, *talk_type;

void set_talk_ob(mixed ob) { talk_ob = ob;}

varargs void add_match(string match, string func, string type) {
    talk_match += ({ match });
    talk_func  += ({ func });
    talk_type  += ({ type });
}

void remove_match(string str) {
    int i;
    i = member_array(str, talk_match);
    if (i >= 0) {
	talk_match = exclude_array(talk_match, i, i);
	talk_func  = exclude_array(talk_func, i, i);
	talk_type  = exclude_array(talk_type, i, i);
    }
}

status test_match(string str) {
    string who, str1, type, match, func;
    int i, maxi;
    
    maxi = sizeof(talk_match);
    for (i = 0; i < maxi; i++) {
	if (talk_type[i]) type = talk_type[i];
	if (talk_func[i]) func = talk_func[i];
	match = (talk_match[i] || "");
	
	if (sscanf(str, "%s " + type + match + " %s\n", who, str1) == 2 ||
	    sscanf(str, "%s " + type + match + "\n", who) ||
	    sscanf(str, "%s " + type + match + "%s\n", who, str1) == 2 ||
	    sscanf(str, "%s " + type + " " + match + "\n", who) ||
	    sscanf(str, "%s " + type + " " + match + " %s\n", who, str1) == 2) {
	    call_other(talk_ob, func, str);
	    return 1;
	} 
    }
}

void dotalk() {
    if (stringp(Caught)) {
	test_match(Caught);
	Caught = 0;
    }
}

void catch_tell(string str) {
    string who;

    if (busy_catch_tell++) return;
    dotalk();
    Caught = str;
    busy_catch_tell = 0;
}
