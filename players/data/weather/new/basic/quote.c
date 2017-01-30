/*
    basic/quote.c - quote strings
    Jan 1992 by marion@cs.tu-berlin.de

    Defines:

    string quote_string (string)
	Quote the first argument as it would be quoted if written in LPC.

    string unquote_string (string)
	Take first argument as quoted like LPC strings and interpret the
	quotes.
    
    string *query_quote()
	Return an array with the quoted representation for the character
	value. Thus, query_quote()[str[n]] is the quoted representation
	of the character a position n of string str.
    
    string query_chart()
	Return a string with the character value return[n] == n. This is
	usable to convert an int back to a string, since LPC does not
	provide for such operation.

*/

private static string *quote;
private static string chart = "^^^^^^^^\b\t\n^^\r^^^^^^^^^^^^^^^^^^ !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~^";

string * query_quote() {
  if (!quote) {
    if (clonep()) {
      quote = (string*)__FILE__->query_quote(); /* share the quote array */
      chart = (string) __FILE__->query_chart();
    }
    else {
      int i;
      quote = allocate(256);
      for (i = 0; i < 256; i++) {
        switch (i&127) {
        case   8:  quote[i] = "\\b";  break;
        case   9:  quote[i] = "\\t";  break;
        case  10:  quote[i] = "\\n";  break;
        case  13:  quote[i] = "\\r";  break;
        case '"':  quote[i] = "\\\""; break;
        case '\\': quote[i] = "\\\\"; break;
        default :  quote[i] = chart[i&127..i&127]; break;
        }
      }
    }
  }
  return quote;
}

string query_chart(int c) {
  query_quote();
  if (!c)
    return chart;
  return chart[c..c];
}

string quote_map(string arr, mixed *x) {
  return quote[x[1][x[0]++]];
}

string quote_string(string str) {
  query_quote();
  return implode(
           map(allocate(strlen(str)), "quote_map", this_object(), ({0,str})),
           "");
}

string unquote_map(string str, int *x) {
  int i;

  if (!x[0] && str) {
    if (!sizeof(str)) {   // str[0] to sizeof(str), Coogan, 28-Sep-2010
      x[0] = 1;
      return "\\";
    }
    if ((i = member(quote, "\\"+str[0..0])) >= 0) {
      return chart[i&127..i&127] + str[1..];
    }
  }
  x[0] = 0;
  return str;
}

string unquote_string(string str) {
  string *s;

  query_quote();
  s = map(explode("|\\\\"+str, "\\"), "unquote_map", this_object(), ({0}));
  return implode(s[2..sizeof(s)-1], "");
}

