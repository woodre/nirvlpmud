#include <defs>

//:DAEMON HTTPD
// HTTP daemon

private nosave string* buffer;
private nosave string username;
private nosave string ip;
private nosave mapping headers,params;

public void initialize_object() {
    set_next_reset(-1);
}

private void write( string text) {
    efun::tell_object(this_object(), text);
}

public void setup() {
    ip=query_ip_name();
    set_max_commands(-1);
    efun::set_prompt("", this_object());
    buffer=({});
    input_to("parse_line",128);
}

public void remove() {
    catch( remove_interactive( this_object()); nolog);
    destruct( this_object());
}

private void log( mixed stat, string request, int length) {
#ifdef LOG_HTTP
    log_file(LOG_HTTP, query_ip_number()+ " - "+
	     (headers["username"]||"-")+" "+
	     "["+ctime()[4..]+"] \""+request+"\" "+
	     stat+" "+length+"\n");
#endif
}

private varargs int write_answer( string stat, string content,
				  mapping headers) {
    write("HTTP/1.0 "+stat+"\n");
    if( strlen(content)>0) {
	if( !headers || !headers["Content-Type"])
	    write("Content-Type: text/html\n");
    }
    write("Server: TheLand/1.1\n");
    write("Content-Length: "+strlen(content)+"\n");
    if( headers) {
	foreach( string key: m_indices(headers)) {
	    write(key+": "+headers[key]+"\n");
	}
    }
    write("Connection: close\n");
    write("\n");
    binary_message(content);
    return strlen(content);
}

private string* bad_request() {
    return ({"400 Bad Request",
	     "Your browser sent a request that this server could not understand"});
}

private void send_bad_request() {
    mixed tmp= bad_request();
    write_answer(tmp[0],tmp[1]);
}

private string* file_not_found() {
    return ({"404 File not found",
	     read_file(HTTP_DOCS "/error/notfound.html")});
}


private void send_file_not_found() {
    mixed tmp= file_not_found();
    write_answer(tmp[0],tmp[1]);
}

private void send_auth_required() {
    write_answer("401 Authorization required",
		 "401 Authorization required",
		 (["WWW-Authenticate":"Basic realm=\"The Land\""]));

}

private int conv_base64_char( int ch) {
    if( ch< 0o53 || ch> 0o173) return 0o177;
    switch( ch) {
    case 0o53: return 0o76;
    case 0o57: return 0o77;
    case 0o75: return 0o100;
    case 0o131: return 0o30;
    case 0o132: return 0o31;
    }
    if( ch>=48 && ch<=58) return ch+4;
    if( ch>=65 && ch<=88) return ch-65;
    if( ch>=97 && ch<=122) return ch-71;
    return 0o177;
}

private string decode_base64( string text) {
    string result="";
    int num;

    while( strlen(text) % 4) text+="=";
    num= strlen(text)/4;
    for( int i=0; i<num; i++) {
	int c1, c2, c3;
	if( text[(i*4)]=='=') break;
	c1= conv_base64_char(text[(i*4)]);
	if( text[(i*4)+1]=='=') break;
	c2= conv_base64_char(text[(i*4)+1]);
	if( text[(i*4)+2]=='=') break;
	c3= conv_base64_char(text[(i*4)+2]);
	result+= sprintf("%c", c1<<2 | c2>>4);
	result+= sprintf("%c", c2<<4 | c3>>2);
	if( text[(i*4)+3]=='=') break;
	result+= sprintf("%c", c3<<6 | conv_base64_char(text[(i*4)+3]));
    }
    return result;
}

private status check_authorization( string auth) {
    if( starts_with( auth, "Basic ")) {
	string decoded= decode_base64( auth[6..]);
	string *tmp= explode(decoded,":");
	if( sizeof(tmp)!=2) return false;
	if( USERD->is_registered_user(tmp[0]) &&
	    USERD->test_password(tmp[0],tmp[1])) {
	    headers["username"]= tmp[0];
	    return true;
	}
    }
    return false;
}

private string check_uri( string file) {
    mixed tmp;
	
    while( file[0]=='/') file= file[1..];

    if( starts_with( file, "auth/")) {
	if( !headers["authorization"] ||
	    !check_authorization(headers["authorization"])) {
	    send_auth_required();
	    return null;
	}
	file= file[5..];
    }

    if( file[0]=='~') {
	string home;

	file= file[1..];
	tmp= explode( file, "/");
	if( USERD->is_registered_user( tmp[0]) &&
	    file_exists( home= USERD->get_home_dir(tmp[0])+"/public_html")) {
	    file= LIB_FILES->calc_path( implode(tmp[1..],"/"), home);
	    if( !starts_with( file, home))
		return send_bad_request(),null;
	}
	else return send_file_not_found(),null;
    } else {
	file= LIB_FILES->calc_path( file, HTTP_DOCS);
	if( !starts_with( file, HTTP_DOCS))
	    return send_bad_request(),null;
    }

    if( file== HTTP_DOCS) file+="/index";
    if( is_directory(file)) file+="/";
    if( file[<1]=='/') {
	if( file_exists(file+"index.html") ||
	    file_exists(file+"index.c"))
	    file+="index";
    }
    return file;
}

private string* get_file_contents( string file, string query) {
    mixed tmp;

    if( file_exists(file+".html")) {
	return ({"200 OK",read_file(file+".html")});
    }
    if( file_exists(file+".c")) {
	tmp= file->request(query,file, this_object());
	if( stringp(tmp)) {
	    return ({"200 OK", tmp });
	} else {
	    return tmp;
	}
    }
    if( file_exists(file) &&
	!ends_with(file, ".c")) {
	return ({ "200 OK",read_file(file)});
    }
    return file_not_found();
}

private void handle_get( string file, string query) {
    mixed tmp2;
    int length;

    if( catch(tmp2= get_file_contents( file, query))) {
	tmp2= ({ "500 INTERNAL ERRROR", "Internal server error.\n" });
    }
    if( !tmp2) {
	DEBUG(file);
	DEBUG(query);
	tmp2= ({ "500 INTERNAL ERROR", "Internal server error.\n" });
    }
    if( strlen(tmp2[1])>1 && tmp2[1][<1]!='\n') tmp2[1]+="\n";
    length=write_answer( tmp2[0], tmp2[1]);
    log( tmp2[0][0..2], "GET "+file, length);
}

//:FUNCTION string url_decode( string tmp)
// Receives an URL-encoded string and decodes it.

public string url_decode( string tmp) {
    return regreplace(tmp, "%[0-9a-fA-F][0-9a-fA-F]",
		      (: sprintf("%c",hex_to_dec($1[1..])) :), 1);
}

private void handle_request() {

    if( !buffer || !sizeof(buffer)) return;

    string *tmp;
    string *first= explode(buffer[0]," ");
    string request= first[0];
    string uri, query;
    
    headers= ([]);
    params= ([]);
    foreach( string header: buffer[1..]) {
	string *tmp2= explode( header, ":");
	headers[lower_case(trim(tmp2[0]))]= trim(implode(tmp2[1..],":"));
    }
    headers=m_delete(headers,"username");
    tmp= explode( first[1], "?");
    uri= check_uri( tmp[0]);
    query= implode( tmp[1..], "?");
    tmp= explode( query, "&");
    foreach( string el : tmp) {
	string *tmp2= explode( el, "=");
	if( sizeof(tmp2)>=2) {
	    string tmp3= url_decode(implode(tmp2[1..],"="));
	    if( member(params,tmp2[0])) {
		if( !pointerp(params[tmp2[0]])) {
		    params[tmp2[0]]= ({ params[tmp2[0]] });
		}
		params[tmp2[0]]+= ({ tmp3 });
	    } else {
		params[tmp2[0]]= tmp3;
	    }
	}
    }
    
    if( uri) {
	switch( request) {
	case "GET":
	case "POST":
	    handle_get( uri, query);
	    return;
	case "HEAD":
	    return;
	case "OPTIONS":
	    write_answer( "200 OK", "",
			  ([ "Allow":"GET, HEAD, OPTIONS" ]));
	    return;
	default:
	    tmp= bad_request();
	    write_answer( tmp[0], tmp[1]);
	}
    }
}


static void parse_line( string line) {
    if( line=="") {
	handle_request();
        call_out("remove",4);
    } else {
	buffer+=({line});
	input_to( "parse_line", 128);
    }
}

//:FUNCTION string get_authenticated_user()
// Returns the username of the user if he is logged in
// using WWW authentication or null.
public string get_authenticated_user() {
    return headers["username"];
}

//:FUNCTION mapping get_params()
// Returns all key/value pairs supplied to the query
public mapping get_params() {
    return params;
}

//:FUNCTION mixed get_param( string key)
// Returns the value of the specified key. Result will
// either be a string or an array of strings
public mixed get_param( string s) {
    return params[s];
}

//:FUNCTION status is_wizard()
// Returns true if this daemon is an http session for a wizard
public status is_wizard() {
    if( headers["username"] &&
	USERD->is_wizard(headers["username"])) return true;
    return false;
}

public void close_connection() {
    remove();
}

// Fake functions for the help daemon
public string get_pronoun() { return "he"; }
public string get_cap_name() { return "Player"; }
public string get_possessive() { return "his"; }

public status is_service_connection() { return true; }
