/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
I want this to act like a daemon, so no cloning or inheritance. Might as well
have strong types and verbose errors.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
#pragma verbose_errors, no_clone, no_inherit, no_shadow, strong_types

/* Some default values. */
#define MAX_LINE_LENGTH 70

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Function declarations just in case I decide to use one before it's defined.
Also to help others understand what's in this utility object/daemon.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
string cpad(string str, int width, string padding);
string rpad(string str, int width, string padding);
string lpad(string str, int width, string padding);
int *get_random_ints(int min, int max, int num_results);
mixed *get_random_array_members(mixed *arr, int num_results);
mixed *get_random_array_member(mixed *arr);
string alternate(string str, string *interlace, int charcount);
string wrapline(string input);
string wrap(string input);
mixed *array_add(mixed arg, mixed *arr);
void write_array(mixed *arr);

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Returns an array of unique, random integers between max and min. The main use
case for this is to then use these ints as indexes by which to grab a random
selection of some other array, but perhaps it'll come in handy elsewhere.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
int *get_random_ints(int min, int max, int num_results) {
	int *results;
	int i, rnd;

	results = ({});
	i = 0;

	/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
	Failure conditions. These are nonsensical parameter values.
	TODO: Log an error? Return -1 or 0 instead of an empty array?
	=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=- */
	if (min > max || max == 0 || num_results > (max-min)) {
		return results;
	}

	for (i = 0; i < num_results; i++) {
		rnd = random(max-min)+min;
		/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
		In order to prevent adding the same number twice, we make
		sure the array doesn't already contain it.
		=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=- */
		if (member_array(rnd, results) == -1) {
			results += ({rnd});
		} else {
			/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
			This is stupid, but it essentially forces the loop to run
			extra times so we get the number of results we wanted.
			This is better done as a while() loop, but every single
			time I try that, the LPC interpreter complains about the
			execution time (even though that's no different than this).
			=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
			i--;
		}
	}
	return results;
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Returns an array of unique, randomly selected members of the provided array.
Right now this is used to randomly select strings to add together to form a
room description, but it may also be used to pick random colors, or spell
effects, etc.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
mixed *get_random_array_members(mixed *arr, int num_results) {
	int i;
	int *random_ints;
	mixed *results;

	/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
	Make sure we're not returning more items than arr contains.
	=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=- */
	if (num_results > sizeof(arr)) {
		num_results = sizeof(arr);
	}

	/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
	Get a list of integers to obtain array items with.
	=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=- */
	random_ints = get_random_ints(0, sizeof(arr), num_results);

	/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
	Initialize the array to an empty array so we can append.
	(C'mon LPC, you can do better than this! Silly language.)
	=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=- */
	results = ({});

	/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
	Populate the result list with the random selection from arr.
	=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=- */
	for (i = 0; i < sizeof(random_ints); i++) {
		results += ({arr[random_ints[i]]});
	}

	return results;
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Returns a single randomly selected member of an array. Yes, this is MUCH
simpler than the case above.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
mixed *get_random_array_member(mixed *arr) {
	return arr[random(sizeof(arr))];
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Takes in a string and adds another string (the 'padding') to it on the left
(leading) side until it is the desired width. In the case of odd numbers it
errs on the side of being under the target width instead of over it, so if
padding is particularly long, you might get unexpected results. If the str to
pad is already wider than width, it just returns str back to you.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
string lpad(string str, int width, string padding) {
	int pad_amt, str_length, i;

	str_length = strlen(remove_color(str));

	if (str_length > width) {
		return str;
	} else {
		pad_amt = width - str_length;
		for (i = 0; i < pad_amt/strlen(padding)-1; i++) {
			str = padding + str;
		}
	}
	return str;
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Takes in a string and adds another string (the 'padding') to it on the right
(trailing) side until it is the desired width. In the case of odd numbers it
errs on the side of being under the target width instead of over it, so if
padding is particularly long, you might get unexpected results. If the str to
pad is already wider than width, it just returns str back to you.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
string rpad(string str, int width, string padding) {
	int pad_amt, str_length, i;

	str_length = strlen(remove_color(str));

	if (str_length > width) {
		return str;
	} else {
		pad_amt = width - str_length;
		for (i = 0; i < pad_amt/strlen(padding)-1; i++) {
			str = str + padding;
		}
	}
	return str;
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Takes in a string and adds another string (the 'padding') to it on the left
and the right sides until it is the desired width (using rpad and lpad).
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
string cpad(string str, int width, string padding) {
	int pad_amt, str_length, i;
	string output, output2;

	str_length = strlen(remove_color(str));

	if (str_length > width) {
		return str;
	} else {
		pad_amt = width - str_length;
		/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
		I tried: rpad(lpad(str, width, padding), width, padding)
		but it kept only giving me the outermost call. WTF LPC?
		=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
		output = lpad(str, (pad_amt/2) + str_length, padding);
		output2 = rpad(output, width, padding);
	}
	return output2;
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Takes in a string to break apart (e.g. "TEST"), a string to interlace with it
(e.g. "-*-") and the character count to interlace into (e.g. 2). Our example
here would result in -*-TE-*-ST-*- because this does, at minimum, bracket
the string with the interlacing character. This behavior could be switched
on and off with a boolean/flag/status in the future.

Note that the interlacing string can be an array, so it will switch which
gets interwoven. So ("TEST",({"*","#"}),1) == *T#E*S#T*. This does awesome
things with arrays of color codes.

TODO: Make a color-specific version of this that adds NORM at the end.
TODO: Make a color-specific version of this that adds NORM between colors.
TODO: Make the bracketing behavior optional (e.g. *t*e*s*t* or t*e*s*t).
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
string alternate(string str, string *interlace, int charcount) {
	/* Input string, split up. */
	string *chunks;
	/* Our eventual output. */
	string result;
	/* Loop counters. */
	int i, j, k;

	chunks = ({""});
	result = "";

	/* Extract chunks from the string according to charcount. */
	i = 0;
	while (i < strlen(str)) {
		chunks += ({str[i..i + charcount-1]}); /* 0..1, 2..3 */
		i += charcount;
	}

	/* Remove the initial array element we initialized to allow += to work */
	chunks = chunks[1..sizeof(chunks)];

	/* Intersperse the special characters in order between the chunks. */
	j = 0;
	while (j < sizeof(chunks)) {
		k = 0;
		while (k < sizeof(interlace) && j < sizeof(chunks)) {
			result += interlace[k] + chunks[j];
			k++;
			j++;
		}
	}
	if (sizeof(interlace) == 1) {
		/* Add one last interlaced character to the end. */
		result += interlace[0];
	}

	return result;
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
It is annoying to constantly rearrange words in a multi-line string when you're
tweaking long descriptions (like rooms) for example:

set_long("blah blah blah blah blah blah"
	+ "blah blah blah blah "
	+ "blah blah blah blah ")

When I want to change a word somewhere I'd rather not have to move words at
the beginning and end of every other line just to make sure it looks correct.
So, this function wraps a multi-line input string to a specified line length,
breaking at spaces.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
string wrap(string arg) {
	/* An array of the lines in arg. */
	string *input_lines;
	/* An array of output text lines. */
	string *output_lines;
	/* Output from wrapping a single line. */
	string result;
	/* Counters. */
	int i;

	/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
	The input itself may already have newlines in it.
	Respect those by splitting arg into input lines, and
	then individually wrapping those, preserving the breaks.
	=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
	input_lines = explode(arg, "\n");
	output_lines = ({""});

	/* Loop through the input lines and wrap each one. */
	for (i = 0; i < sizeof(input_lines); i++) {
		if (i > 0) {
			output_lines += ({""});
		}
		output_lines[i] = wrapline(input_lines[i]);
	}
	return implode(output_lines, "\n");
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
This method wraps a single line, assuming there are no newlines in it to
complicate things. It does this by exploding the input on spaces, then
tacking the words back together while ensuring length is less than a maximum.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
string wrapline(string input) {
	string *lines;
	string *words;
	string *chars; /* Temporary? Maybe. */
	int i, num; /* counters */

	/* If we are already shorter than the limit, be lazy and return. */
	if (strlen(input) <= MAX_LINE_LENGTH) {
		return input;
	} else {
		words = explode(input, " ");
		num = 0;
		lines = ({""});

		for (i = 0; i < sizeof(words); i++) {
			/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
			If the word can be added to the current line without
			blowing the length limit, add, otherwise go to the next.
			=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
			if (strlen(remove_color(lines[num]) + " " + remove_color(words[i])) < MAX_LINE_LENGTH) {
				/* If this isn't the first word, add a space. */
				if (strlen(lines[num]) > 0) {
					lines[num] += " ";
				}
				/* Add the word. */
				lines[num] += words[i];
			} else {
				/* Start the next line with our word. */
				lines += ({""});
				num++;
				lines[num] += words[i];
			}
		}
	}
	return implode(lines, "\n");
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
A convenience function for adding an item to an array, since every damn time
you do it, LPC forces this sort of stupidity.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
mixed *array_add(mixed arg, mixed *arr) {
	if (sizeof(arr) == 0) {
		arr = ({arg});
	} else {
		arr += ({arg});
	}
	return arr;
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
A convenience function for writing out the members of an array. Hopefully
they're something writable like strings, but who knows.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
void write_array(mixed *arr) {
	int i;
	for (i = 0; i < sizeof(arr); i++) {
		write("Array item " + i + " has value: " + arr[i] + "\n");
	}
}