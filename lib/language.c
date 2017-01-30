/*
 * lib/language.c
 *
 * This file holds some standard natural language functions
 */

#pragma strong_types
#pragma no_clone
#pragma no_inherit

inherit "basic/create";

string article(string str) {
  if (!str)
    return 0;
  switch(str[0]) {
  case 'e':
  case 'E':
    if (str[1..2] == "ur")
      return "a";
  case 'a':
  case 'A':
  case 'i':
  case 'I':
    return "an";
  case 'o':
  case 'O':
    /* special treatment of 'one' and 'once' */
    if (str[1] == 'n')
      if (str[2] == 'e' || str[2..3] == "ce")
        return "a";
    return "an";
  case 'u':
  case 'U':
    break;
  case 'h':
  case 'H':
    if (strlen(str)==1 ||
        lower_case(str[1..3])=="our" ||
        lower_case(str[1..5])=="onest" ||
        lower_case(str[1..5])=="onour")
      return "an";
    // fall through
  default:
    return "a";
  }
  switch(str[1]) {
  case 0:
    break;
  case 'd':
  case 'g':
  case 'l':
  case 'm':
  case 'p':
  case 'x':
    return "an";
  case 'n':
    if (str[2] != 'i')
      return "an";
    switch(str[3]) {
    case 'd':
    case 'm':
    case 'n':
      return "an";
    }
    break;
  case 'r':
    switch(str[2]) {
    case 'a':
    case 'e':
    case 'i':
      return "a";
    }
    return "an";
  case 's':
    if (str[2] == 'h')
      return "an";
    break;
  case 't':
    switch(str[2]) {
    case 'm':
    case 't':
      return "an";
    }
  }
  return "a";
}

string add_article(string str) {
  return article(str) + " " + str;
}

/* This routine returns a number in text form */
private string *nums = ({ "one","two","three","four","five","six","seven",
                          "eight","nine","ten","eleven","twelve","thirteen",
                          "fourteen","fifteen","sixteen","seventeen",
                          "eighteen","nineteen" });
private string *numt = ({ "twenty","thirty","forty","fifty","sixty","seventy",
                          "eighty","ninety" });

string word_number(int num) {
  string ns;
  int nm;

  if (num < 0)
    return "no or even less";
  if (num < 1)
    return "no";
  if (num < 20)
    return nums[num -1];
  if (num > 99) {
    if (num > 999) {
      if (num > 999999)
        if (num > 999999999)
          return "extremely, rather incredibly many";
        else {
          ns = word_number(num / 1000000) + " million";
          nm = num % 1000000;
          if (nm)
            ns += " " + word_number(nm);
          return ns;
        }
      ns = word_number(num / 1000) + " thousand";
      nm = num % 1000;
      if (nm)
        ns += " " + word_number(num % 1000);
      return ns;
    }
    ns = word_number(num / 100) + " hunderd";
    nm = num % 100;
    if (nm)
      ns += " and " + word_number(num % 100);
    return ns;
  }
  nm = num % 10;
  if (!nm)
    return numt[num/10 -2];
  else
    return numt[num/10 -2] + "-" + nums[nm -1];
}

private static mapping irregular_plurals,irregular_singulars;

/* lpc singular to plural converter */

private varargs string append_s(string str, status third_person) {
  if (!strlen(str))
    return str;
  switch(str[<1]) {
  case 'z':
  case 's':
  case 'x':
  case 'o':
    return str + "es";
  case 'h':
    if (strlen(str) > 1 && ('g' == str[<2] || 'h' == str[<2]))
      return str + "s";
    return str + "es";
  case 'y':
    if (strlen(str) > 1 && member("aeiou", str[<2]) < 0)
      return str[0..<2] + "ies";
    return str + "s";
  case 'e':
    if (!third_person && str[<2] == 'f' && str[<3] != 'f')
      return str[0..<3] + "ves";
    break;
  case 'f':
    if (!third_person && str[<2] != 'f')
      return str[0..<2] + "ves";
    break;
  default:
    break;
  }
  return str + "s";
}

string plural_word(string str) {
  mixed h;

  if (!str)
    return 0;
  if (sizeof(regexp(({ str }), "^[1-9][0-9]*$")))
    return str;
  if (h=irregular_plurals[str])
    return h;
  if (str[<3..<1] == "man") {
    str[<2] = 'e';  // man --> men
    return str;
  }
  return append_s(str);
}

varargs string plural_sentence(string str, string colours) {
  mixed h, h2;
  int c;
  string *a, word, format;

  if (!str)
    return 0;
  a = explode(str, " ");
  if (!a || sizeof(a) < 1)
    return 0;
  for (c=1; c<sizeof(a); c++) {
    word = lower_case(a[c]);
    if (word == "of" ||
        word == "with" ||
        word == "in" ||
        word == "for" ||
        word == "to" ||
        word == "from" ||
        word == "about" ||
        word == "on" ||
        word[0] == '\[' ||
        word[0] == '\(') {
      h = plural_word(a[c-1]);
      if (colours) {
        if (strlen(h) > strlen(a[c-1])) { // grown by pluarlizing
          h2 = strlen(implode(a[..c-1]," ")) -1;
          format = "%'x'*s", format[2] = colours[h2];
          colours[h2+1..h2] = sprintf(format,strlen(h)-strlen(a[c-1]),"");
        }
        else if (strlen(h) < strlen(a[c-1])) { // shrunk by pluralizing
          h2 = strlen(implode(a[..c-1]," "));
          colours[h2-strlen(a[c-1]) + strlen(h)..h2-1] = "";
        }
      }
      a[c-1] = h;
      return implode(a," ");
    }
  }
  a[<1] = plural_word(a[<1]);
  h = implode(a," ");
  if (colours) {
    if (strlen(h) > strlen(colours)) { // grown by pluralizing
      format = "%'x'*s", format[2] = colours[<1];
      colours += sprintf(format,strlen(h)-strlen(colours),"");
    }
    else if(strlen(h) < strlen(colours)) // shrunk by pluralizing
      colours = colours[..strlen(h)];
  }
  return h;
}

// returns the singular or plural of the first argument depending on the
// second argument (which should be an array of objects or strings)
string describe_group_of(string single, mixed group) {
  if (pointerp(group)) {
    if (sizeof(group) == 1 && !(objectp(group[0]) && group[0]->query_plural()))
      return single;
    else
      return plural_sentence(single);
  }
  else if (intp(group)) {
    if (group == 1)
      return single;
    else
      return plural_sentence(single);
  }
}

varargs string possessive_s_ending(mixed m, status plural) {
  if (objectp(m)) {
    plural = m->query_plural();
    m = describe(m);
  }
  if (plural && 's' == m[<1])
    return "\'";
  else
    return "\'s";
}

varargs string possessive_s(mixed m, status plural) {
  return describe(m) + possessive_s_ending(m,plural);
}

string third_person_s(string infinitive) {
  if (infinitive[<3..] == "n't")
    return third_person_s(infinitive[0..<4]) + "n't";
  switch(infinitive) {
  case "were":
    return "was";
  case "have":
    return "has";
  case "be":
  case "are":
    return "is";
  case "can":
  case "may":
  case "cannot":
  case "could":
  case "will":
  case "wo":  // from "won't"
  case "would":
  case "shall":
  case "sha":  // from "shan't"
  case "should":
    return infinitive;
  }
  return append_s(infinitive,1);
}

string second_person(string infinitive) {
  if (infinitive == "be")
    return "are";
  else
    return infinitive;
}

// This function is not infallable, but it is a good hint in checking
// whether a string could be a plural description or not
status could_be_plural(string s) {
  return member(irregular_singulars,s) || (s!="" && s[<1]=='s');
}

// to_singular returns an array of possible singulars to a given plural
string *to_singular(string str) {
  mixed h;

  if (h=irregular_singulars[str])
    return ({ h,str });
  if (str[<3..] == "ves")
    return ({ str[0..<4]+"f",str[0..<4]+"fe",str[0..<2],str });
  if (str[<3..] == "ies")
    return ({ str[0..<4]+"y",str[0..<2],str});
  if (str[<2..] == "es")
    return ({ str[0..<3],str[0..<2],str });
  if (str[<1] == 's')
    return ({ str[0..<2],str});
  if (str[<3..] == "men")
    return ({ str[0..<4]+"man",str });
  return ({ str });
}

string *singular_sentences(mixed w) {
  int c, i;
  string *result, *sing, word;

  if (stringp(w))
    w = explode(w," ") - ({""});
  result = ({});
  for (c=1; c<sizeof(w); c++) {
    word = lower_case(w[c]);
    if (word == "of" ||
        word == "with" ||
        word == "in" ||
        word == "for") {
      sing = to_singular(w[c-1]);
      for (i=sizeof(sing); i--; ) {
        w[c-1] - sing[i];
        result = ({ implode(w," ") }) + result;
      }
      return result;
    }
  }
  sing = to_singular(w[<1]);
  for (i=sizeof(sing); i--; ) {
    w[<1] = sing[1];
    result = ({ implode(w," ") }) + result;
  }
  return result;
}

void create() {
  irregular_plurals = ([
                         "cactus": "cacti",
                         "child" : "children",
                         "dead"  : "dead",
                         "deer"  : "deer",
                         "die"   : "dice",
                         "dwarf" : "dwarves",
                         "elf"   : "elves",
                         "fish"  : "fish",
                         "foot"  : "feet",
                         "human" : "humans",
                         "index" : "indices",
                         "louse" : "lice",
                         "money" : "money",
                         "month" : "months",
                         "moth"  : "moths",
                         "mouse" : "mice",
                         "person": "people",
                         "sheep" : "sheep",
                         "sock"  : "sox",
                         "tooth" : "teeth",
                         "undead": "undead",
                         ]);
  irregular_singulars = mkmapping(m_values(irregular_plurals),
                                  m_indices(irregular_plurals));
}

