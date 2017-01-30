/*
 * encoding.c by Alfe for Tubmud 2003-May-22
 */

#pragma strong_types
#pragma no_clone

#include <ctype.h>

/**************************************************************************
 *                                                                        *
 * concrete conversions from one encoding to another:                     *
 *                                                                        *
 **************************************************************************/

varargs string latin12ascii(string s, int version) {
  // converts the given latin 1 string s to the corresponding ascii string.
  // data may get lost in this process.
  switch (version) {
  default:
  case 0:  // version 0, default: use character most alike ("a -> a)
    return to_string(map(to_array(s)[0..strlen(s)-1], (: isotoascii0($1) :)));
  case 1:  // version 1: remove accents, use ? for
    //                   non-translatable without loss:
    return to_string(map(to_array(s)[0..strlen(s)-1], (: isotoascii1($1) :)));
  case 2:  // version 2: convert umlauts etc to multiple-char-transcription:
    for (int i=strlen(s); i-->0; ) {
      int c;
      c = isotoascii1(s[i]);
      if (c == '?') {
        status in_capitals;
        in_capitals = (i < strlen(s)-1?
                       isupper(isotoascii0(s[i+1])) :
                       i > 0 && isupper(isotoascii0(s[i-1])));
        switch (s[i] & 0xff) {
        default:  s[i] = '?'; break;
        case 0xa9: s[i..i] = "(C)";   break;
        case 0xab: s[i..i] = "<<";    break;
        case 0xae: s[i..i] = "(R)";   break;
        case 0xb0: s[i..i] = "^0";    break;
        case 0xb1: s[i..i] = "+/-";   break;
        case 0xb2: s[i..i] = "^2";    break;
        case 0xb3: s[i..i] = "^3";    break;
        case 0xb4: s[i..i] = "'";     break;
        case 0xb5: s[i..i] = "my";    break;
        case 0xb7: s[i..i] = ".";     break;
        case 0xb8: s[i..i] = ",";     break;
        case 0xb9: s[i..i] = "^1";    break;
        case 0xbb: s[i..i] = ">>";    break;
        case 0xbc: s[i..i] = "1/4";   break;
        case 0xbd: s[i..i] = "1/2";   break;
        case 0xbe: s[i..i] = "3/4";   break;
        case 0xc4: s[i..i] = in_capitals? "AE" : "Ae";  break;
        case 0xc5: s[i..i] = in_capitals? "AA" : "Aa";  break;
        case 0xc6: s[i..i] = "AE";    break;
        case 0xd6: s[i..i] = in_capitals? "OE" : "Oe";  break;
        case 0xdc: s[i..i] = in_capitals? "UE" : "Ue";  break;
        case 0xdf: s[i..i] = "sz";    break;
        case 0xe4: s[i..i] = "ae";    break;
        case 0xe5: s[i..i] = "aa";    break;
        case 0xe6: s[i..i] = "ae";    break;
        case 0xf6: s[i..i] = "oe";    break;
        case 0xfc: s[i..i] = "ue";    break;
        }
      }
      else
        s[i] = c;
    }
    return s;
  }
  NO_WARN_MISSING_RETURN;  // Coogan, 24-Mar-2011
}

string latin12utf8(string s) {
  // converts the given latin 1 string s to the corresponding utf8 string.
  return regreplace(s, "[\x80-\xff]",
                    (: to_string(({ 0xC0 + (($1[0] & 0xFF) >> 6),
                                    0x80 +  ($1[0] & 0x3F)        })) :), 1);
}

string utf82latin1(string s) {
  // converts the given utf8 string s to the corresponding latin 1 string.
  return regreplace(s, "[0xc0-\xff][\x80-\xbf]",
                    (: to_string(({ (($1[0] & 0x03) << 6) +
                                     ($1[1] & 0x3F)         })) :), 1);
}

string ascii2latin1(string s) {
  // all ascii chars are ok in latin 1, so no conversion necessary:
  return s;  // this is correct!
}

/**************************************************************************
 *                                                                        *
 * abstract conversions from the mud internal to another and vice versa   *
 *                                                                        *
 **************************************************************************/

string mud2utf8(string s) {
  // converts the given mud string s to the corresponding utf8 string.
  return latin12utf8(s);  // using latin 1 internally (currently)
}

string utf82mud(string s) {
  // converts the given utf8 string into the encoding used internally
  // in the mud.
  return utf82latin1(s);  // using latin 1 internally (currently)
}

varargs string mud2ascii(string s, int version) {
  // converts the given mud string s to the corresponding ascii string.
  return latin12ascii(s, version);  // using latin 1 internally (currently)
}

string ascii2mud(string s) {
  // converts the given ascii string into the encoding used internally
  // in the mud.
  return ascii2latin1(s);  // using latin 1 internally (currently)
}

string mud2latin1(string s) { return s; }
string latin12mud(string s) { return s; }
