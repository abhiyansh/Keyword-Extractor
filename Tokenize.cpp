bool is_number(const string& s)
{
    string::const_iterator it = s.begin();
    while (it != s.end() && (isdigit(*it) || (*it == '.'))) ++it;
    return !s.empty() && it == s.end();
}

inline bool is_stopword(set<string> stop_words, string word){
	return stop_words.find(word) != stop_words.end();
}

vector<string> Tokenize(string input){
	//stop words
	set<string> stop_words;
	string word;
	ifstream file("stopwords.txt");
	if(file.is_open()){
		//read file one word at a time (delimiter used = '\n'); adds each word in set of strings
		while(getline(file, word, '\n')) stop_words.insert(word);
	}

	char ch;
	string st = "";
	vector<string> v;

	fstream fin(input, fstream::in);
	while (fin >> noskipws >> ch) {
		
		if(isalpha(ch) || isdigit(ch) || ch == '-'){
			if(isalpha(ch)) ch = tolower(ch);
			st.push_back(ch);
		}

	    else if(ch == ' ' || ispunct(ch)){
	    	if(!st.empty()){
	    		if(!is_number(st) && !is_stopword(stop_words, st)) v.push_back(st);
	    		st = "";
	   		}
		}
	}

	if(!st.empty()){
	    	if(!is_number(st)) v.push_back(st);
	   	}

	return v;
}