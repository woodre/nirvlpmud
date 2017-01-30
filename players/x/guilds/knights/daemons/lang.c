static mapping translations;

string translate_word(string word){
  string *defs;
  int s;
  if(!(defs=translations[word]) || !(s = sizeof(defs))) {;
    return word;
  }
  else {
    string def, a, b, stuff;
    def = defs[random(s)];
    while(sscanf(def,"%s$%s$%s",a,stuff,b)==3){
      def = a+translate_word(stuff)+b;
    }
    return def;
  }
}

static string *simple_verbs;
static string *past_participles;
static string *irregular_verbs;

void reset(int x){
  string data, words, defs;
  string *nonsense, *words_arr;
  int a, b, s;
  if(x) return;
  
  translations =([]);
  
  data = read_file("/players/x/guilds/knights/daemons/data/translations.txt");
  nonsense = explode(data, "\n");
  b = sizeof(nonsense);
  for(a = 0; a < b; a ++){
    if(nonsense[a] != "" && nonsense[a] != "\n") {
      sscanf(nonsense[a],"%s:%s",words,defs);
      words_arr = explode(words, ",");
      s = sizeof(words_arr);
      while(s --){
        translations[words_arr[s]] = explode(defs, ",");
      }
    }
  }
  
  data = read_file("/players/x/guilds/knights/daemons/data/simpleVerbs.txt");
  simple_verbs = explode(data, "\n");
  
  data = read_file("/players/x/guilds/knights/daemons/data/pastParticiples.txt");
  past_participles = explode(data, "\n");

  data = read_file("/players/x/guilds/knights/daemons/data/irregularVerbs.txt");
  irregular_verbs = explode(data, "\n");
}

status is_simple_verb(string word){
  return (member_array(word, simple_verbs) > -1);
}

status is_past_participle(string word){
  return (member_array(word, past_participles) > -1);
}    

status is_irregular_verb(string word){
  return (member_array(word, irregular_verbs) > -1);
}

string translate_sentence(string sentence){
  status end;
  int comma, capped, dp, x, y, last_let, sl;
  string punc, da, db, *words, word;
  if(!sentence || (sl = strlen(sentence)) < 2){
    return sentence;
  }
  
  punc = sentence[sl-1..sl-1];
  
  if(punc == "." || punc == "!" || punc == "?") {
    words = explode(sentence[0..sl-2], " ");
  }
  else {
    words = explode(sentence," ");
  }
  y = sizeof(words);
  for(x = 0; x < y; x ++) {
    word = words[x];
    sl = strlen(word);
    
    if(word == "" || !word)
      continue;
    last_let = word[sl-1];
    
    if(capitalize(word) == word)
      capped = 1;
    
    word = lower_case(word);
    
    if(last_let == ',') {
      comma = 1;
      word = word[0..sl-2];
      last_let = word[sl-1];
      sl = strlen(word);
    }
    if(is_simple_verb(word) || is_irregular_verb(word)){
      if(word[sl-1] != 'e'){
        if(word[sl-1] == 't' &&
           word[sl-2] != 't') {
          word += "t";
        } 
        word += "e";
      }
      word += "th";
    }
    else if(is_past_participle(word)){
      if(word[sl-1] != 'e') {
        if(word[sl-1] == 't' &&
           word[sl-2] != 't') {
          word += "t";
        }
        word += "e";
      }
      word += "st";
    }
    else
    {
      word = translate_word(word);
    }
    
    sl = strlen(word);
    
    if(!random(2) && text_contains(word, "or") && sl > 1 &&
       word[sl-2..sl-1] == "or") {
      word = word[0..sl-2]+"h";
    }
    
    if(text_contains(word,"v")) {
      int ok;
      while(sscanf(word, "%sv%s",da,db)==2 && !ok) {
        if(strlen(da) && db != "" && db[0] != 'e' && 
          da[strlen(da)-1] != ''') {
          word = da+"'"+db;
        }
        else {
          ok = 1;
        }
      }
    }
    if(text_contains(word, "igh") && !text_contains(word, "oigh")){
      if(word[strlen(word)-3..strlen(word)-1] == "igh") end = 1;
      word = implode(explode(word,"igh"),"oigh");
      if(end) word += "oigh";
      sl = strlen(word);
    }
    if(text_contains(word,"em")) {
      if(word[strlen(word)-2..strlen(word)-1] == "em") end = 1;
      word = implode(explode(word,"em"),"ahm");
      if(end) word += "ahm";
      sl = strlen(word);
    }

    if(!random(2) && word[0] == 'h' && sl > 1) {
      word = "'"+word[1..sl-1];
    }
    if(word[strlen(word)-2..sl-1] == "ee" && sl > 1) {
     if(word != "thee")
      word = word[0..sl-2]+"y";
    }
    if(!random(2) && word[sl-1] == 'g') {
      word = word[0..sl-2]+"'";
    }
    if(!random(2) && text_contains(word,"er")){
      if(word[strlen(word)-2..strlen(word)-1] == "er") end = 1;
      word = implode(explode(word,"er"),"ah");
      if(end) word += "ah";
    }
    if((text_contains(word,"ar") || text_contains(word,"re")) &&
     sl > 2 && 
     (word[sl-2..sl-1]=="ar" || word[sl-2..sl-1]=="re")){
      word = word[0..sl-3]+"ah";
    }
    if(text_contains(word, "d") && !text_contains(word, "'")){
      while(sscanf(word,"%sd%s",da,db)==2 && !random(2) && !dp &&
      db != ""){
        dp = 1;
        word = da+"'"+db;
      }
    }
    if(!random(20) && (x && (y - x > 1)))
    {
      word += (random(2) ? " bloody" : " bloo'y");
    }
    if(comma || word == "i"){
      word += ",";
      comma = 0;
    }
    if(capped){
      word = capitalize(word);
      capped = 0;
    }
    words[x] = word;
  }
  sentence = implode(words, " ");
  
  if(punc != "." && punc != "?" && punc != "!"){
    sentence += ".";
  }
  else {
    sentence += punc;
    if(punc == "?") {
      if(random(3)){
        switch(random(2)){
          case 0: sentence = "Eh? "+sentence; break;
          case 1: sentence = sentence+" Eh?"; break;
        }
      }
    }
    else if(punc == "!") {
      string woo_word;
      if(random(3)) {
        switch(random(5))
        {
          case 0: woo_word = "Zounds";
            break;
          case 1: woo_word = "Gadzooks";
            break;
          case 2: woo_word = "Eureka";
            break;
          case 3: woo_word = "Egad";
            break;
          case 4: woo_word = "Bollocks";
            break;
        }
        sentence = woo_word+"! "+capitalize(sentence);
      }
    }
  }
  sentence = capitalize(sentence);
  return sentence;
}
